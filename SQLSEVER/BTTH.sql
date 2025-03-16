CREATE TABLE Loai (
    MaLoai CHAR(5) PRIMARY KEY,
    TenLoai NVARCHAR(100) NOT NULL
);

CREATE TABLE SanPham (
    MaSP CHAR(5) PRIMARY KEY,
    TenSP NVARCHAR(100) UNIQUE NOT NULL,
    MaLoai CHAR(5) NOT NULL,
    CONSTRAINT FK_SanPham_Loai FOREIGN KEY (MaLoai) REFERENCES Loai(MaLoai)
);

CREATE TABLE NhanVien (
    MaNV CHAR(5) PRIMARY KEY,
    HoTen NVARCHAR(100) NOT NULL,
    NgaySinh DATE NOT NULL CHECK (DATEDIFF(YEAR, NgaySinh, GETDATE()) BETWEEN 18 AND 55),
    Phai INT DEFAULT 0 CHECK (Phai IN (0, 1))
);

CREATE TABLE PhieuXuat (
    MaPX INT IDENTITY(1,1) PRIMARY KEY,
    NgayLap DATE NOT NULL DEFAULT GETDATE(),
    MaNV CHAR(5) NOT NULL,
    CONSTRAINT FK_PhieuXuat_NhanVien FOREIGN KEY (MaNV) REFERENCES NhanVien(MaNV)
);

CREATE TABLE CTPX (
    MaPX INT NOT NULL,
    MaSP CHAR(5) NOT NULL,
    SoLuong INT NOT NULL CHECK (SoLuong > 0),
    CONSTRAINT PK_CTPX PRIMARY KEY (MaPX, MaSP),
    CONSTRAINT FK_CTPX_PhieuXuat FOREIGN KEY (MaPX) REFERENCES PhieuXuat(MaPX),
    CONSTRAINT FK_CTPX_SanPham FOREIGN KEY (MaSP) REFERENCES SanPham(MaSP)
);

--View 1: Tổng số lượng xuất của từng sản phẩm trong năm 2010
CREATE VIEW View_SoLuongXuat_2010 AS
SELECT sp.MaSP, sp.TenSP, SUM(ctpx.SoLuong) AS TongSoLuong
FROM SanPham sp
JOIN CTPX ctpx ON sp.MaSP = ctpx.MaSP
JOIN PhieuXuat px ON ctpx.MaPX = px.MaPX
WHERE YEAR(px.NgayLap) = 2010
GROUP BY sp.MaSP, sp.TenSP
ORDER BY sp.TenSP ASC;

--View 2: Sản phẩm đã được bán từ ngày 1/1/2010 đến 30/6/2010
CREATE VIEW View_SanPhamBan_2010 AS
SELECT DISTINCT sp.MaSP, sp.TenSP, l.TenLoai
FROM SanPham sp
JOIN Loai l ON sp.MaLoai = l.MaLoai
JOIN CTPX ctpx ON sp.MaSP = ctpx.MaSP
JOIN PhieuXuat px ON ctpx.MaPX = px.MaPX
WHERE px.NgayLap BETWEEN '2010-01-01' AND '2010-06-30';

--Procedure P1: Tổng số lượng xuất kho của tên sản phẩm trong năm 2010
CREATE PROCEDURE P1 @TenSP NVARCHAR(100), @TongSoLuong INT OUTPUT AS
BEGIN
    SELECT @TongSoLuong = COALESCE(SUM(ctpx.SoLuong), 0)
    FROM SanPham sp
    JOIN CTPX ctpx ON sp.MaSP = ctpx.MaSP
    JOIN PhieuXuat px ON ctpx.MaPX = px.MaPX
    WHERE YEAR(px.NgayLap) = 2010 AND sp.TenSP = @TenSP;
END;

--Procedure P2: Tổng số lượng xuất kho của tên sản phẩm từ đầu tháng 4 đến hết tháng 6 năm 2010
CREATE PROCEDURE P2 @TenSP NVARCHAR(100), @TongSoLuong INT OUTPUT AS
BEGIN
    SELECT @TongSoLuong = COALESCE(SUM(ctpx.SoLuong), 0)
    FROM SanPham sp
    JOIN CTPX ctpx ON sp.MaSP = ctpx.MaSP
    JOIN PhieuXuat px ON ctpx.MaPX = px.MaPX
    WHERE MONTH(px.NgayLap) BETWEEN 4 AND 6 AND YEAR(px.NgayLap) = 2010 AND sp.TenSP = @TenSP;
END;

--Function F1: Số lượng xuất kho của tên sản phẩm trong một năm

CREATE FUNCTION F1 (@TenSP NVARCHAR(100), @Nam INT) RETURNS INT AS
BEGIN
    DECLARE @TongSoLuong INT;
    
    SELECT @TongSoLuong = COALESCE(SUM(ctpx.SoLuong), 0)
    FROM SanPham sp
    JOIN CTPX ctpx ON sp.MaSP = ctpx.MaSP
    JOIN PhieuXuat px ON ctpx.MaPX = px.MaPX
    WHERE YEAR(px.NgayLap) = @Nam AND sp.TenSP = @TenSP;

    RETURN @TongSoLuong;
END;

--Function F2: Số lượng phiếu xuất của nhân viên

CREATE FUNCTION F2 (@MaNV CHAR(5)) RETURNS INT AS
BEGIN
    DECLARE @SoLuongPhieuXuat INT;

    SELECT @SoLuongPhieuXuat = COALESCE(COUNT(MaPX), 0)
    FROM PhieuXuat
    WHERE MaNV = @MaNV;

    RETURN @SoLuongPhieuXuat;
END;

--Trigger chỉ cho phép một nhân viên lập tối đa 10 phiếu xuất trong một ngày

CREATE TRIGGER TR_PhieuXuat_NhanVien ON PhieuXuat FOR INSERT AS
BEGIN
    IF EXISTS (
        SELECT 1 
        FROM inserted i 
        GROUP BY i.MaNV, CONVERT(DATE, i.NgayLap) 
        HAVING COUNT(i.MaPX) > 10
    )
    BEGIN
        RAISERROR ('Một nhân viên chỉ được lập tối đa 10 phiếu xuất trong một ngày.', 16, 1);
        ROLLBACK TRANSACTION;
    END;
END;

