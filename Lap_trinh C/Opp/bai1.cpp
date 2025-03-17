#include<iostream>
#include<math.h>
#include"string.h"
using namespace std;
char* saochep(char *s){
    return strcpy(new char[strlen(s) + 1], s );
}
class chuoi{
    char *p;
public:
    chuoi(char *s=""){p=saochep(s);}
    ~chuoi(){
        delete []p;
    }
    chuoi( const chuoi &s){p = saochep(s.p);}
    void nhap();
    void xuat();
   chuoi chuyenThuongthanhHoa() const ;
   chuoi chuyenHoathanhThuong() const;
    bool sosanh(chuoi s) const;
    chuoi chuanhoa() const;
    chuoi& operator=(const chuoi &s) ;
    chuoi& operator+(const chuoi &s);
    chuoi& operator-(const chuoi &);
    friend std::istream& operator>>(std::istream &in, chuoi &s);
    friend std::ostream& operator<<(std::ostream &out, const chuoi &s) ;
    chuoi xoaKhoangTrangDuThua() const;
};
chuoi chuoi::xoaKhoangTrangDuThua() const {
    chuoi ketQua;
    int len = strlen(this->p);
    char *newStr = new char[len + 1];
    int j = 0;
    bool lastCharWasSpace = false;

    for (int i = 0; i < len; i++) {
        if (p[i] != ' ' || !lastCharWasSpace) {
            newStr[j] = p[i];
            lastCharWasSpace = (p[i] == ' ');
            j++;
        }
    }
    newStr[j] = '\0';
    ketQua.p = newStr;
    return ketQua;
}
std::istream& operator>>(std::istream &in, chuoi &s){
    char buffer[1000];
    in >> buffer;
    delete[] s.p;
    s.p = new char[strlen(buffer) + 1];
    strcpy(s.p, buffer);
    return in;
}
//ử dụng >> để đọc một chuỗi từ đối tượng in (thường là cin) vào một mảng kí tự buffer.
//Xóa bộ nhớ động hiện tại của đối tượng s.p để tránh rò rỉ bộ nhớ.
//Cấp phát lại bộ nhớ động cho s.p với kích thước phù hợp để chứa chuỗi nhập.
//Sao chép chuỗi từ buffer vào s.p bằng hàm strcpy.
//Trả về đối tượng in để hỗ trợ việc liên kết nhập.
std::ostream& operator<<(std::ostream &out, const chuoi &s){
    out << s.p;
    return out;
}
//ử dụng << để xuất nội dung của s.p (một chuỗi) vào đối tượng out (thường là cout).
//Trả về đối tượng out để hỗ trợ việc liên kết xuất.
chuoi chuoi::chuanhoa() const {
    if (p) {
        bool newWord = true;
        for (size_t i = 0; i < strlen(p); i++) {
            if (isalpha(p[i])) {
                if (newWord) {
                    p[i] = toupper(p[i]);
                    newWord = false;
                } else {
                    p[i] = tolower(p[i]);
                }
            } else {
                newWord = true;
            }
        }
    }
}
chuoi& chuoi::operator-(const chuoi &s) {
    chuoi a;
    strcpy(a.p, this->p);
  strcpy(this->p, s.p);
    strcat(this->p, a.p);
    return *this;
}
//chuoi a;: Khởi tạo một đối tượng chuoi mới tên a.
//strcpy(a.p, this->p);: Sao chép nội dung của chuỗi hiện tại (this->p) vào a.p. Điều này giữ lại nội dung của chuỗi gọi toán tử.
//strcpy(this->p, s.p);: Sao chép nội dung của chuỗi s vào chuỗi gọi toán tử (this->p). Điều này thay đổi nội dung của chuỗi gọi toán tử thành nội dung của chuỗi s.
//strcat(this->p, a.p);: Nối nội dung của chuỗi a (chứa nội dung cũ của chuỗi gọi toán tử) vào cuối chuỗi gọi toán tử.
//Kết quả là chuỗi gọi toán tử (this->p) sẽ chứa nội dung của chuỗi s được nối với nội dung ban đầu của chuỗi gọi toán tử. Điều này giống như việc ghép nối hai chuỗi.
chuoi& chuoi::operator=(const chuoi &s) {
if (this == &s) {
return *this; // Tránh gán cho chính đối tượng hiện tại
}
strcpy(this->p, s.p);
return *this;
}
//Mục đích: Nạp chồng toán tử gán (=) để gán giá trị từ một đối tượng chuoi khác.
//
//Thực hiện:
//
//this != &s: Kiểm tra xem đối tượng gọi toán tử có khác với đối tượng được gán hay không.
//delete[] p: Giải phóng bộ nhớ của đối tượng gọi toán tử.
//p = saochep(s.p): Sao chép nội dung từ đối tượng s và gán vào đối tượng gọi toán tử.
chuoi& chuoi::operator+(const chuoi &s) {
    strcat(this->p, s.p);
    return *this;
}
//Mục đích: Nạp chồng toán tử cộng (+) để nối chuỗi.
//
//Thực hiện:
//
//char *newStr = new char[strlen(p) + strlen(s.p) + 1]: Cấp phát bộ nhớ mới đủ để chứa cả hai chuỗi và kí tự kết thúc chuỗi.
//strcpy(newStr, p): Sao chép nội dung của chuỗi gọi toán tử vào newStr.
//strcat(newStr, s.p): Nối nội dung của chuỗi s vào newStr.
//delete[] p: Giải phóng bộ nhớ của chuỗi gọi toán tử.
//p = newStr: Gán con trỏ p vào vùng nhớ mới sau khi nối chuỗi.
void chuoi::nhap() {
    cout<<"nhap: ";
    cin.getline(p,35);
}
void chuoi::xuat() {
    cout<<p;
}
chuoi chuoi::chuyenThuongthanhHoa()  const{
    return  strupr(this->p);
}
chuoi chuoi::chuyenHoathanhThuong() const {
    return strlwr( this->p);
}
bool chuoi::sosanh(chuoi s) const {

    if( strcmp( this->p, s.p) == 0){
        return 1;
    }
    return 0;
}
int main(){
    chuoi z;
    chuoi m("vinh");
    chuoi l("nguyen");
    cin>>z;
    z + l;
    z.xuat();
}

