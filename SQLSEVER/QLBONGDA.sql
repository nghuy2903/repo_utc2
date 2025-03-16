-- Bảng San
CREATE TABLE San (
    MaSan CHAR(3) PRIMARY KEY,
    TenSan VARCHAR(100),
    DiaChi VARCHAR(100)
);

-- Bảng Doi
CREATE TABLE Doi (
    MaDoi CHAR(3) PRIMARY KEY,
    TenDoi VARCHAR(100),
    MaSan CHAR(3),
    FOREIGN KEY (MaSan) REFERENCES San(MaSan)
);

-- Bảng TranDau
CREATE TABLE TranDau (
    MaTD CHAR(3) PRIMARY KEY,
    MaSan CHAR(3),
    Ngay DATE,
    Gio TIME,
    FOREIGN KEY (MaSan) REFERENCES San(MaSan)
);

-- Bảng CT_TranDau
CREATE TABLE CT_TranDau (
    MaTD CHAR(3),
    MaDoi CHAR(3),
    SoBanThang INT CHECK (SoBanThang >= 0),
    PRIMARY KEY (MaTD, MaDoi),
    FOREIGN KEY (MaTD) REFERENCES TranDau(MaTD),
    FOREIGN KEY (MaDoi) REFERENCES Doi(MaDoi)
);
-- Dữ liệu bảng San
INSERT INTO San (MaSan, TenSan, DiaChi) VALUES
('MDI', 'Mỹ Đình', 'Hà Nội – Việt Nam'),
('NAS', 'Sân vận động quốc gia', 'Viêng Chăn – Lào'),
('IMO', 'Sân I-Mobile', 'Buriram – Thái Lan'),
('MOD', 'Khu thể thao Morodok Decho', 'Russey Keo – Campichia');

-- Dữ liệu bảng Doi
INSERT INTO Doi (MaDoi, TenDoi, MaSan) VALUES
('VN', 'Việt Nam', NULL),
('LA', 'Lào', NULL),
('TL', 'Thái Lan', NULL),
('CPC', 'Campuchia', NULL);

-- Dữ liệu bảng TranDau
INSERT INTO TranDau (MaTD, MaSan, Ngay, Gio) VALUES
('01', 'MOD', '2017-08-14', '15:00'),
('02', 'NAS', '2017-08-16', '17:00'),
('03', 'MOD', '2017-08-16', '15:00'),
('04', 'IMO', '2017-08-18', '19:00');

-- Dữ liệu bảng CT_TranDau
INSERT INTO CT_TranDau (MaTD, MaDoi, SoBanThang) VALUES
('01', 'VN', 3),
('01', 'TL', 1),
('02', 'VN', 5),
('02', 'LA', 0),
('03', 'TL', 3),
('03', 'CPC', 3),
('04', 'TL', 2),
('04', 'LA', 0);


--câu 1
SELECT a.MaDoi, a.TenDoi, COUNT(b.MaDoi) AS SoTran
FROM Doi a
JOIN CT_TranDau b
ON a.MaDoi = b.MaDoi
GROUP BY a.MaDoi, a.TenDoi;

--câu 2
SELECT A.MaTD AS MaTran,
	CONCAT(A.MaDoi, '-' , B.MaDoi) AS DoiTranDau,
	CONCAT(A.SoBanThang, '-', B.SoBanThang) AS TySo
FROM CT_TranDau A
JOIN CT_TranDau B
ON A.MaTD = B.MaTD AND A.MaDoi < B.MaDoi;

--câu 3
SELECT A.MaTD AS MaTran,
	A.MaDoi AS DoiTranDau,
	CONCAT(A.SoBanThang, '-', B.SoBanThang) AS TySo
FROM CT_TranDau A
JOIN CT_TranDau B
ON A.MaTD = B.MaTD AND A.MaDoi < B.MaDoi;

--câu 4 In mã đội, tên đội, tổng số điểm:
SELECT A.MaDoi,
	 B.TenDoi,
	 SUM(CASE
		WHEN A.SoBanThang > C.SoBanThang THEN 3
		WHEN A.SoBanThang = C.SoBanThang THEN 1
		ELSE 0
	 END) AS DIEM
FROM CT_TranDau A
JOIN Doi B
ON A.MaDoi = B.MaDoi
JOIN  CT_TranDau C
ON A.MaTD = C.MaTD AND A.MaDoi != C.MaDoi
GROUP BY A.MaDoi, B.TenDoi;

--câu 5 Sắp xếp danh sách các đội để biết thứ hạng:

SELECT A.MaDoi,
	 B.TenDoi,
	 SUM(CASE
		WHEN A.SoBanThang > C.SoBanThang THEN 3
		WHEN A.SoBanThang = C.SoBanThang THEN 1
		ELSE 0
	 END) AS DIEM,
	 SUM(A.SoBanThang - C.SoBanThang) AS HieuSoBanThang
FROM CT_TranDau A
JOIN Doi B
ON A.MaDoi = B.MaDoi
JOIN  CT_TranDau C
ON A.MaTD = C.MaTD AND A.MaDoi != C.MaDoi
GROUP BY A.MaDoi, B.TenDoi
ORDER BY HieuSoBanThang DESC;

--câu 6 Hiển thị các trận chưa đá:
--C1
/*
WITH LK AS( 
	SELECT A.MaDoi AS DOI1, 
			C.MaDoi AS DOI2
	FROM CT_TranDau A
	
	JOIN CT_TranDau C
	ON C.MaTD = A.MaTD AND C.MaDoi != A.MaDoi
	GROUP BY A.MaDoi, C.MaDoi
), TÌM RA CÁC CẶP ĐÃ ĐẤU VÀ NHÓM CHÚNG LẠI
AllPossiblePairs AS (
    SELECT 
        A.MaDoi AS DOI3, 
        B.MaDoi AS DOI4
    FROM 
        Doi A
    CROSS JOIN 
        Doi B
    WHERE 
        A.MaDoi < B.MaDoi  -- To avoid duplicate pairs (e.g., LA-VN and VN-LA)
) -- TÌM RA TẤT CẢ CÁC CẶP VÀ LOẠI CÁC CẶP TRÙNG
SELECT 
    CONCAT(APP.DOI3, '-', APP.DOI4) AS DoiChuaDa
FROM 
    AllPossiblePairs APP
WHERE 
    NOT EXISTS (
        SELECT 1
        FROM LK L
        WHERE L.DOI1 = APP.DOI3 AND L.DOI2 = APP.DOI4
);
*/

--C2
SELECT CONCAT(A.MaDoi, '-',B.MaDoi) AS CapChuaDa 
FROM Doi A
CROSS JOIN Doi B
WHERE A.MaDoi < B.MaDoi
--Tìm ra tất cả các cặp trận đấu
EXCEPT
--Trừ các cặp đã đấu
SELECT CONCAT(A.MaDoi, '-' ,B.MaDoi) AS CapChuaDa
FROM CT_TranDau A
JOIN CT_TranDau B
ON A.MaTD = B.MaTD AND A.MaDoi < B.MaDoi;