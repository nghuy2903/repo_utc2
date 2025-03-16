CREATE TABLE KHACHHANG (
    MaKH INT PRIMARY KEY,
    TenKH VARCHAR(100) NOT NULL,
    DiaChi VARCHAR(200) NOT NULL,
    DienThoai VARCHAR(20) NOT NULL,
    Email VARCHAR(100) UNIQUE NOT NULL
);

CREATE TABLE VATTU (
    MaVT INT PRIMARY KEY,
    TenVT VARCHAR(100) NOT NULL,
    DVT VARCHAR(50) NOT NULL,
    GiaMua DECIMAL(10, 2) NOT NULL,
    SoLuongTon INT NOT NULL
);

CREATE TABLE HOADON (
    MaHD INT PRIMARY KEY,
    NgayHD DATE NOT NULL,
    MaKH INT NOT NULL,
    TongTG DECIMAL(10, 2) NOT NULL,
    FOREIGN KEY (MaKH) REFERENCES KHACHHANG(MaKH)
);

CREATE TABLE CTHD (
    MaHD INT NOT NULL,
    MaVT INT NOT NULL,
    SoLuong INT NOT NULL,
    GiaBan DECIMAL(10, 2) NOT NULL,
    KhuyenMai DECIMAL(5, 2),
    PRIMARY KEY (MaHD, MaVT),
    FOREIGN KEY (MaHD) REFERENCES HOADON(MaHD),
    FOREIGN KEY (MaVT) REFERENCES VATTU(MaVT)
);

INSERT INTO KHACHHANG (MaKH, TenKH, DiaChi, DienThoai, Email)
VALUES
(1, N'Nguyễn Văn A', N'123 Phố Cổ', '0901234567', 'nguyenvana@example.com'),
(2, N'Trần Thị B', N'456 Phố Mới', '0907654321', 'tranthib@example.com'),
(3, N'Lê Văn C', N'789 Phố Cũ', '0909876543', 'levanc@example.com');

INSERT INTO VATTU (MaVT, TenVT, DVT, GiaMua, SoLuongTon)
VALUES
(1, N'Sản phẩm A', N'Cái', 10000.00, 50),
(2, N'Sản phẩm B', N'Chai', 20000.00, 30),
(3, N'Sản phẩm C', N'Túi', 5000.00, 100),
(4, N'Sản phẩm D', N'Giày', 12000.00, 30),
(5, N'Sản phẩm E', N'Ví', 70000.00, 40);

INSERT INTO HOADON (MaHD, NgayHD, MaKH, TongTG)
VALUES
(1, '2023-10-01', 1, 30000.00),
(2, '2023-10-05', 2, 40000.00),
(3, '2023-10-10', 3, 20000.00);

INSERT INTO CTHD (MaHD, MaVT, SoLuong, GiaBan, KhuyenMai)
VALUES
(1, 1, 2, 15000.00, NULL),
(1, 2, 1, 25000.00, NULL),
(2, 3, 4, 6000.00, NULL),
(3, 1, 3, 15000.00, NULL);



-- 1.Tạo trigger để khi insert một record vào trong table CHITIETHOADON, thì cập nhật lại SLTON của vật tư đó trong table VATTU

CREATE TRIGGER trg_UpdateSoLuongTon
ON CTHD
AFTER INSERT
AS
BEGIN
    UPDATE v
    SET SoLuongTon = v.SoLuongTon - i.SoLuong
    FROM VATTU v
    INNER JOIN inserted i ON v.MaVT = i.MaVT;
END;

INSERT INTO CTHD (MaHD, MaVT, SoLuong, GiaBan, KhuyenMai)
VALUES (1, 3, 2, 15000.00, NULL);

--2.Tạo trigger để không cho phép một hoá đơn có nhiều hơn 4 chi tiết hoá đơn
CREATE TRIGGER trg_HanCheChiTietHoaDon
ON CTHD
FOR INSERT 
AS 
BEGIN
	IF EXISTS(
		SELECT 1
		FROM inserted i
		WHERE (SELECT COUNT(*) FROM CTHD WHERE i.MaHD = MaHD) > 4
	)
	BEGIN
		RAISERROR ('Một hóa đơn không thể có nhiều hơn 4 chi tiết hóa đơn.', 16, 1);
        ROLLBACK TRANSACTION;
	END;
END;

INSERT INTO CTHD (MaHD, MaVT, SoLuong, GiaBan, KhuyenMai)
VALUES (1, 5, 2, 15000.00, NULL);	

--3.Tạo trigger không cho phép hai vật tư trùng tên

CREATE TRIGGER trg_HanCheVatTu
ON VATTU
AFTER INSERT 
AS 
BEGIN
	IF EXISTS(
		SELECT 1
		FROM inserted i
		WHERE TenVt = i.TenVt
	) 
	BEGIN 
		RAISERROR ('Không thể trùng tên vật tư', 16, 1);
		ROLLBACK TRANSACTION;
	END;
END;

INSERT INTO VATTU
VALUES (6, 'Sản phẩm A', 'Giày', 50000, 10);	

--4.Tạo trigger để không cho phép xoá cùng lúc nhiều hơn một khách hàng

CREATE TRIGGER trg_LimitXoaKhachHang
ON KHACHHANG
INSTEAD OF DELETE
AS 
BEGIN
	IF(SELECT COUNT(*) FROM deleted) > 1
	BEGIN
		RAISERROR('Không cho phép xóa nhiều người cùng lúc', 16, 1);
		ROLLBACK TRANSACTION;
	END
	ELSE
	BEGIN
		DELETE 
		FROM KHACHHANG
		WHERE MaKH IN (SELECT MaKH FROM deleted);
	END;
END;

DELETE FROM KHACHHANG
WHERE MaKH IN (1, 2);
