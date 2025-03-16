INSERT INTO NHACUNGCAP (MANHACUNGCAP, TENNHACUNGCAP, DIACHI, SODIENTHOAI, EMAIL)
VALUES
(1, 'Công Ty A', 'Hà Nội', '0123456789', 'info@companya.com'),
(2, 'Công Ty B', 'TP.HCM', '0987654321', 'info@companyb.com'),
(3, 'Công Ty C', 'Đà Nẵng', '0123456780', 'info@companyc.com'),
(4, 'Công Ty D', 'Hải Phòng', '0987654322', 'info@companyd.com'),
(5, 'Công Ty E', 'Cần Thơ', '0123456781', 'info@companye.com'),
(6, 'Công Ty F', 'Quảng Ninh', '0987654323', 'info@companyf.com'),
(7, 'Công Ty G', 'Bình Dương', '0123456782', 'info@companyg.com'),
(8, 'Công Ty H', 'Đồng Nai', '0987654324', 'info@companyh.com'),
(9, 'Công Ty I', 'Bắc Ninh', '0123456783', 'info@companyi.com'),
(10, 'Công Ty J', 'Hưng Yên', '0987654325', 'info@companyj.com');

INSERT INTO LOAIHANG (MALOAIHANG, TENLOAIHANG)
VALUES
(1, 'Điện tử'),
(2, 'Thời trang'),
(3, 'Đồ gia dụng'),
(4, 'Sách và văn phòng phẩm'),
(5, 'Mỹ phẩm'),
(6, 'Thực phẩm chức năng'),
(7, 'Đồ chơi trẻ em'),
(8, 'Dụng cụ thể thao'),
(9, 'Nội thất'),
(10, 'Xe máy và phụ tùng');

INSERT INTO MATHANG (MAMATHANG, TENMATHANG, MALOAIHANG, MANHACUNGCAP, GIA, SOLUONGTONKHO)
VALUES
(1, 'Điện thoại X', 1, 1, 1000.0, 50),
(2, 'Quần jeans Y', 2, 2, 500.0, 100),
(3, 'Tivi Z', 1, 3, 2000.0, 20),
(4, 'Áo phông A', 2, 4, 300.0, 150),
(5, 'Bàn ủi B', 3, 5, 400.0, 30),
(6, 'Sách giáo khoa C', 4, 6, 200.0, 200),
(7, 'Kem dưỡng da D', 5, 7, 150.0, 100),
(8, 'Đồ chơi E', 7, 8, 50.0, 500),
(9, 'Bóng rổ F', 8, 9, 300.0, 20),
(10, 'Ghế sofa G', 9, 10, 5000.0, 10);

INSERT INTO NHANVIENQL (MANHANVIEN, TENNHANVIEN, NGAYSINH, DIACHI, SODIENTHOAI, EMAIL)
VALUES
(1, 'Nguyễn Văn A', '1990-01-01', 'Hà Nội', '0123456789', 'nva@example.com'),
(2, 'Trần Thị B', '1995-06-15', 'TP.HCM', '0987654321', 'ttb@example.com'),
(3, 'Lê Văn C', '1985-03-20', 'Đà Nẵng', '0123456780', 'lvc@example.com'),
(4, 'Nguyễn Thị D', '1992-09-10', 'Hải Phòng', '0987654322', 'ntd@example.com'),
(5, 'Phạm Văn E', '1988-05-05', 'Cần Thơ', '0123456781', 'pve@example.com'),
(6, 'Đỗ Thị F', '1991-07-07', 'Quảng Ninh', '0987654323', 'dtf@example.com'),
(7, 'Hồ Văn G', '1986-04-04', 'Bình Dương', '0123456782', 'hvg@example.com'),
(8, 'Trần Văn H', '1993-08-08', 'Đồng Nai', '0987654324', 'tvh@example.com'),
(9, 'Lê Thị I', '1987-02-02', 'Bắc Ninh', '0123456783', 'lti@example.com'),
(10, 'Nguyễn Văn J', '1994-01-01', 'Hưng Yên', '0987654325', 'nvj@example.com');

INSERT INTO KHACHHANG (MAKHACHHANG, TENKHACHHANG, NGAYSINH, DIACHI, SODIENTHOAI, EMAIL)
VALUES
(1, 'Nguyễn Văn K', '1980-03-20', 'Hà Nội', '0123456789', 'nvk@example.com'),
(2, 'Trần Thị L', '1985-09-10', 'TP.HCM', '0987654321', 'ttl@example.com'),
(3, 'Lê Văn M', '1982-05-05', 'Đà Nẵng', '0123456780', 'lvm@example.com'),
(4, 'Nguyễn Thị N', '1983-07-07', 'Hải Phòng', '0987654322', 'ntn@example.com'),
(5, 'Phạm Văn O', '1981-04-04', 'Cần Thơ', '0123456781', 'pvo@example.com'),
(6, 'Đỗ Thị P', '1984-02-02', 'Quảng Ninh', '0987654323', 'dtp@example.com'),
(7, 'Hồ Văn Q', '1986-08-08', 'Bình Dương', '0123456782', 'hvq@example.com'),
(8, 'Trần Văn R', '1987-06-06', 'Đồng Nai', '0987654324', 'tvr@example.com'),
(9, 'Lê Thị S', '1988-01-01', 'Bắc Ninh', '0123456783', 'lts@example.com'),
(10, 'Nguyễn Văn T', '1989-03-03', 'Hưng Yên', '0987654325', 'nvt@example.com');

INSERT INTO DONDATHANG (MADONDATHANG, NGAYDATHANG, MAKHACHHANG, MANHANVIEN)
VALUES
(1, GETDATE(), 1, 1),
(2, GETDATE(), 2, 2),
(3, GETDATE(), 3, 3),
(4, GETDATE(), 4, 4),
(5, GETDATE(), 5, 5),
(6, GETDATE(), 6, 6),
(7, GETDATE(), 7, 7),
(8, GETDATE(), 8, 8),
(9, GETDATE(), 9, 9),
(10, GETDATE(), 10, 10);

INSERT INTO CHITIETDATHANG (MADONDATHANG, MAMATHANG, SOLUONG, GIABAN)
VALUES
(1, 1, 2, 1000.0),
(1, 2, 3, 500.0),
(2, 3, 1, 2000.0),
(2, 4, 2, 300.0),
(3, 5, 1, 400.0),
(3, 6, 3, 200.0),
(4, 7, 2, 150.0),
(4, 8, 1, 50.0),
(5, 9, 1, 300.0),
(5, 10, 1, 5000.0);

/*Câu 1*/
SELECT TENNHACUNGCAP
FROM NHACUNGCAP
WHERE TENNHACUNGCAP IN (SELECT TENKHACHHANG
						FROM KHACHHANG);

/*Câu 2*/





