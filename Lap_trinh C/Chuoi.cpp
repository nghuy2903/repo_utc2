#include <iostream>
#include <cstring>

using namespace std;

class Chuoi {
private:
    char* chuoi; // Con trỏ đến mảng ký tự

public:
    // Hàm khởi tạo mặc định
    Chuoi() {
        chuoi = nullptr;
    }

    // Hàm khởi tạo với chuỗi ký tự đầu vào
    Chuoi(const char* str) {
        chuoi = new char[strlen(str) + 1];
        strcpy(chuoi, str);
    }

    // Hàm hủy
    ~Chuoi() {
        if (chuoi != nullptr) {
            cout << "Hủy đối tượng tại địa chỉ: " << static_cast<void*>(chuoi) << endl;
            delete[] chuoi;
        }
    }

    // Hàm trả về chiều dài của chuỗi
    int ChieuDai() const {
        if (chuoi != nullptr) {
            return strlen(chuoi);
        }
        return 0;
    }

    // Hàm so sánh 2 chuỗi
    bool SoSanh(const Chuoi& other) const {
        if (chuoi != nullptr && other.chuoi != nullptr) {
            return strcmp(chuoi, other.chuoi) == 0;
        }
        return false;
    }

    // Hàm nhập chuỗi từ bàn phím
    friend istream& operator >>(istream& in, Chuoi& chuoi) {
        char buffer[256];
        in >> buffer;
        chuoi = Chuoi(buffer);
        return in;
    }

    // Hàm xuất chuỗi ra màn hình
    friend ostream& operator<<(ostream& out, const Chuoi& chuoi) {
        if (chuoi.chuoi != nullptr) {
            out << chuoi.chuoi;
        }
        return out;
    }

    // Hàm gán chuỗi
    Chuoi& operator=(const Chuoi& other) {
        if (this != &other) {
            delete[] chuoi;
            chuoi = new char[strlen(other.chuoi) + 1];
            strcpy(chuoi, other.chuoi);
        }
        return *this;
    }

    // Hàm nối chuỗi
    Chuoi operator+(const Chuoi& other) const {
        Chuoi ketQua;
        if (chuoi != nullptr && other.chuoi != nullptr) {
            int chieuDaiMoi = ChieuDai() + other.ChieuDai();
            ketQua.chuoi = new char[chieuDaiMoi + 1];
            strcpy(ketQua.chuoi, chuoi);
            strcat(ketQua.chuoi, other.chuoi);
        }
        return ketQua;
    }

    // Hàm đảo chuỗi
    Chuoi Dao() const {
        Chuoi ketQua;
        if (chuoi != nullptr) {
            int chieuDai = ChieuDai();
            ketQua.chuoi = new char[chieuDai + 1];
            for (int i = 0; i < chieuDai; i++) {
                ketQua.chuoi[i] = chuoi[chieuDai - i - 1];
            }
            ketQua.chuoi[chieuDai] = '\0';
        }
        return ketQua;
    }
};

int main(){
    Chuoi chuoi1, chuoi2;
    
    cout << "Nhập chuỗi 1: ";
    cin >> chuoi1;
    
    cout << "Nhập chuỗi 2: ";
    cin >> chuoi2;

    cout << "Chuỗi 1: " << chuoi1 << endl;
    cout << "Chuỗi 2: " << chuoi2 << endl;

    cout << "Chiều dài chuỗi 1: " << chuoi1.ChieuDai() << endl;
    cout << "Chiều dài chuỗi 2: " << chuoi2.ChieuDai() << endl;

    if (chuoi1.SoSanh(chuoi2)) {
        cout << "Chuỗi 1 và chuỗi 2 giống nhau." << endl;
    } else {
        cout << "Chuỗi 1 và chuỗi 2 khác nhau." << endl;
    }

    Chuoi chuoi3 = chuoi1 + chuoi2;
    cout << "Chuỗi 1 + Chuỗi 2: " << chuoi3 << endl;

    Chuoi chuoiDao = chuoi1.Dao();
    cout << "Đảo Chuỗi 1: " << chuoiDao << endl;

    return 0;



    return 0;
}