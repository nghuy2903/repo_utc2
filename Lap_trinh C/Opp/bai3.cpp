#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
char *saochep(const char *s)
{
    return strcpy(new char[strlen(s) + 1], s);
}
class Chuoi
{
    char *p;

public:
    Chuoi(const Chuoi &s) : p(saochep(s.p)) {}
    Chuoi(const char *s = "") : p(saochep(s)) {}
    ~Chuoi()
    {
        delete[] p;
    }

    void nhap()
    {
        std::cin.getline(p, 35);
    }

    void xuat()
    {
        std::cout << p << " ";
    }

    bool sosanh(const Chuoi &s) const
    {
        return strcmp(p, s.p) == 0;
    }

    const char *get() const
    {
        return p;
    }
};

class NgaySinh
{
    int ngay, thang, nam;

public:
    void nhap()
    {
        std::cout << "Nhap ngay sinh (ngay thang nam): ";
        std::cin >> ngay >> thang >> nam;
    }

    void xuat() const
    {
        std::cout << ngay << "/" << thang << "/" << nam;
    }
};
class MonHoc
{
    Chuoi tenMonHoc;
    int soTiet;

public:
    void nhap()
    {
        cin.ignore();
        std::cout << "Nhap ten mon hoc: ";
        tenMonHoc.nhap();
        std::cout << "Nhap so tiet: ";
        std::cin >> soTiet;
    }

    void xuat()
    {
        tenMonHoc.xuat();
        std::cout << " - So tiet: " << soTiet << std::endl;
    }
};

class Nguoi
{
protected:
    Chuoi cccd;
    Chuoi hoTen;
    Chuoi gioiTinh;
    Chuoi ngaySinh;
    Chuoi diaChi;
    Chuoi sdt;

public:
    virtual void nhap()
    {
        std::cin.ignore();
        std::cout << "Nhap ho ten: ";
        hoTen.nhap();
        std::cout << "Nhap gioi tinh: ";
        gioiTinh.nhap();
        std::cout << "Nhap ngay sinh: ";
        ngaySinh.nhap();
        std::cout << "Nhap dia chi: ";
        diaChi.nhap();
        std::cout << "Nhap so dien thoai: ";
        sdt.nhap();
        std::cout << "Nhap so CCCD: ";
        cccd.nhap();
    }

    virtual void xuat()
    {
        std::cout << "Ho ten: ";
        hoTen.xuat();
        std::cout << "\nGioi tinh: ";
        gioiTinh.xuat();
        std::cout << "\nNgay sinh: ";
        ngaySinh.xuat();
        std::cout << "\nDia chi: ";
        diaChi.xuat();
        std::cout << "\nSo dien thoai: ";
        sdt.xuat();
        std::cout << "\nCCCD: ";
        cccd.xuat();
    }
};

class GiaoVien : public Nguoi
{
    Chuoi boMonCongTac;
    int soMonHoc;
    std::vector<MonHoc> danhSachMonHoc;

public:
    void nhap() override
    {
        Nguoi::nhap();
        std::cout << "Nhap bo mon cong tac: ";
        boMonCongTac.nhap();
        std::cout << "Nhap so mon hoc co the giang day: ";
        std::cin >> soMonHoc;
        danhSachMonHoc.resize(soMonHoc);
        for (int i = 0; i < soMonHoc; ++i)
        {
            std::cout << "Nhap thong tin mon hoc " << i + 1 << std::endl;
            danhSachMonHoc[i].nhap();
        }
    }

    void xuat() override
    {
        Nguoi::xuat();
        std::cout << "\nBo mon cong tac: ";
        boMonCongTac.xuat();
        std::cout << "\nSo mon hoc co the giang day: " << soMonHoc << std::endl;
        std::cout << "Danh sach mon hoc co the giang day:" << std::endl;
        for (int i = 0; i < soMonHoc; ++i)
        {
            danhSachMonHoc[i].xuat();
        }
    }
};

class BoMon
{
private:
    Chuoi tenBoMon;
    int soGiaoVien;
    std::vector<GiaoVien> danhSachGiaoVien;

public:
    void nhap()
    {
        std::cout << "Nhap ten bo mon: ";
        tenBoMon.nhap();
        std::cout << "Nhap so luong giao vien: ";
        std::cin >> soGiaoVien;
        danhSachGiaoVien.resize(soGiaoVien);
        for (int i = 0; i < soGiaoVien; ++i)
        {
            std::cout << "Nhap thong tin giao vien " << i + 1 << std::endl;
            danhSachGiaoVien[i].nhap();
        }
    }
    void xuat()
    {
        std::cout << "Ten bo mon: ";
        tenBoMon.xuat();
        std::cout << "\nSo luong giao vien: " << soGiaoVien << std::endl;
        std::cout << "Danh sach giao vien:" << std::endl;
        for (int i = 0; i < soGiaoVien; ++i)
        {
            danhSachGiaoVien[i].xuat();
            std::cout << std::endl;
        }
    }
};

int main()
{
    BoMon *boMon = new BoMon;
    boMon->nhap();
    boMon->xuat();
    return 0;
}