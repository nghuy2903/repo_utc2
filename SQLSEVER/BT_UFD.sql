CREATE DATABASE QLHOADON;

CREATE TABLE KHACHHANG (
    MaKH INT PRIMARY KEY,
    TenKH NVARCHAR(100) NOT NULL,
    DiaChi NVARCHAR(200),
    DienThoai VARCHAR(15),
    Email VARCHAR(100)
);

CREATE TABLE VATTU (
    MaVT INT PRIMARY KEY,
    TenVT NVARCHAR(100) NOT NULL,
    DVT NVARCHAR(50),
    GiaMua DECIMAL(18, 2),
    SoLuongTon INT
);

CREATE TABLE HOADON (
    MaHD INT PRIMARY KEY,
    NgayHD DATE NOT NULL,
    MaKH INT,
    TongTG DECIMAL(18, 2),
    FOREIGN KEY (MaKH) REFERENCES KHACHHANG(MaKH)
);

CREATE TABLE CTHD (
    MaHD INT,
    MaVT INT,
    SoLuong INT,
    GiaBan DECIMAL(18, 2),
    KhuyenMai DECIMAL(5, 2),
    PRIMARY KEY (MaHD, MaVT),
    FOREIGN KEY (MaHD) REFERENCES HOADON(MaHD),
    FOREIGN KEY (MaVT) REFERENCES VATTU(MaVT)
);

--1.Tính tổng doanh thu của một tháng trong năm
CREATE FUNCTION dbo.sum_doanthu(@MONTH INT, @YEAR INT)
RETURNS TABLE
AS
RETURN(
	SELECT MONTH(B.NgayHD) AS month_, YEAR(B.NgayHD) AS year_ , sum(A.SoLuong*A.GiaBan) AS doanh_thu
	FROM CTHD A
	JOIN HOADON B
	ON A.MaHD = B.MaHD
	WHERE MONTH(B.NgayHD) = @MONTH AND YEAR(B.NgayHD) = @YEAR
	GROUP BY MONTH(B.NgayHD), YEAR(B.NgayHD)
);

--2.Lấy ra một mã hóa đơn có giá trị lớn nhất

CREATE FUNCTION dbo.HighestValueInvoice()
RETURNS TABLE
AS
RETURN (
    SELECT TOP 1 MaHD, TongTG
    FROM HOADON
    ORDER BY TongTG DESC
);

--3.Viết hàm trả về một bảng các hóa đơn có cùng ngày mua với ngày mua của khách hàng có mã khách hàng là tham số truyền vào.

CREATE FUNCTION dbo.InvoicesByCustomerPurchaseDate(@MaKH INT)
RETURNS TABLE
AS
RETURN (
    SELECT B.MaHD, B.NgayHD, B.TongTG
    FROM HOADON B
    WHERE B.NgayHD IN (
        SELECT NgayHD
        FROM HOADON
        WHERE MaKH = @MaKH
    )
);

--4.Viết hàm cho biết họ tên và địa chỉ các khách hàng đã mua mặt hàng có mã vật tư là tham số truyền vào.

CREATE FUNCTION dbo.CustomersByProduct(@MaVT INT)
RETURNS TABLE
AS
RETURN (
    SELECT DISTINCT A.TenKH, A.DiaChi
    FROM KHACHHANG A
    JOIN HOADON B ON A.MaKH = B.MaKH
    JOIN CTHD C ON B.MaHD = C.MaHD
    WHERE C.MaVT = @MaVT
);

