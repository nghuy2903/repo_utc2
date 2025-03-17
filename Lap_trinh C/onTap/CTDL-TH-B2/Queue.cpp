#include <bits/stdc++.h>

using namespace std;

/*
Bài 4. Sử dụng hàng đợi
Viết chương trình quản lý việc phục vụ khách hàng tại phòng giao dịch của một ngân hàng. 
Biết rằng khi một khách hàng đến phòng giao dịch sẽ lấy một số thứ tự. 
Thông tin của mỗi khách hàng gồm: số thứ tự (chương trình tự sinh), họ tên, dịch vụ cần thực hiện. Chương trình có các chức năng sau:
1. Thêm 1 khách hàng vào hàng đợi chờ phục vụ, cho biết số thứ tự của người đó.
2. Cho biết thông tin khách hàng tiếp theo sẽ được phục vụ là ai và xuất khách hàng đó ra khỏi hàng đợi.
3. Cho biết có bao nhiêu khách hàng chưa được phục vụ?
4. Cho biết có bao nhiêu khách hàng đã được phục vụ?
5. Viết hàm main kiểm tra kết quả thực hiện của các hàm trên
*/

string inHoaChuCaiDau(const string& input) {
    string result = input;

    // Thiết lập biến flag để kiểm tra chữ cái đầu tiên
    bool newWord = true;

    for (size_t i = 0; i < result.length(); ++i) {
        // Kiểm tra xem ký tự có phải là chữ cái không
        if (isalpha(result[i])) {
            // Chuyển đổi chữ cái đầu tiên của từ thành in hoa
            if (newWord) {
                result[i] = toupper(result[i]);
                newWord = false;
            }
            else {
                result[i] = tolower(result[i]);  
            } 
        }
        else {
            // Nếu ký tự không phải là chữ cái, đặt flag để bắt đầu từ mới
            newWord = true;
        }    
    }
    return result;
}

class kH{
    private:
        static int count;
        int STT;
        string hoTen, dichVu;
    public:
        kH(string s = "", string a = "") {
            STT = ++count;
            hoTen = s;
            dichVu = a;
        }

        int getNumber(){return STT;}
        string getName(){
            hoTen = inHoaChuCaiDau(hoTen);
            return hoTen;}
        string getServe(){
            dichVu = inHoaChuCaiDau(dichVu);
            return dichVu;}
        void inPut();
        void outPut();
};

int kH::count = 0;

void kH::inPut(){
    cin.ignore();
    cout << "Nhap ten: ";
    getline(cin, hoTen);
   
    cout << "Nhap dich vu: ";
    getline(cin,dichVu);
}

void kH::outPut(){  
    cout << STT << "\t" << inHoaChuCaiDau(hoTen) << "\t" << inHoaChuCaiDau(dichVu) << endl;
}

class quanLi{
    private:
        queue<kH> s;
        int soLuong;
        int soLuongDaPV;
    public:
        quanLi() {
            soLuong = 0;
            soLuongDaPV = 0;
        };
        void themKH();
        void thongTinKHTT();
        int soLuongKHChuaPV();
        int soLuongKHDaPV(); 
};

void quanLi::themKH(){
    kH a;
    a.inPut();
    ++soLuong;
    s.push(a);

    cout << "Da them thanh cong!\n";
    cout << "So thu tu cua khach hang la: " << a.getNumber() << endl;
}

void quanLi::thongTinKHTT(){
    kH temp = s.front();
    ++soLuongDaPV;
    cout << "Khach hang tiep theo se nhan duoc dich vu la: " << temp.getName()<< endl;
    temp.outPut();
    s.pop();
}

int quanLi::soLuongKHDaPV(){
    return soLuongDaPV;
}

int quanLi::soLuongKHChuaPV(){
    return soLuong-soLuongDaPV;
}

int main(){
    quanLi ds;
    int n;

    do{
        system("cls");
        cout << "\n	        \t\tMENU           ";
        cout << "\n	+-------------------------------------------------------+";
        cout << "\n	| [1]. Them khach hang va in STT                        |";
        cout << "\n	| [2]. Xuat thong tin khach hang tiep theo duoc phuc vu |";
        cout << "\n	| [3]. So khach hang da phuc vu                         |";
        cout << "\n	| [4]. So khach hang chua da phuc vu                    |";
        cout << "\n	| [0]. Thoat                                            |";
        cout << "\n	+-------------------------------------------------------+\n";

        cout << "Chon: ";
        cin >> n;

        switch (n)
        {
        case 1:
            ds.themKH();
            system("pause");
            break;
        case 2:
            ds.thongTinKHTT();
            system("pause");
            break;
        case 3: 
            cout << "So khach hang da duoc phuc vu: " << ds.soLuongKHDaPV() << endl;
            system("pause");
            break;
        case 4:
            cout << "So khach hang chua duoc phuc vu: " << ds.soLuongKHChuaPV() << endl;
            system("pause");
            break;
        case 0:
        default:
            break;
        }

    } while (n!=0);



    return 0;
}