#include <bits/stdc++.h>
//Nguyễn Nguyên Huy - 6351071030
using namespace std;

/*1.1. 
Tính S =1 + (1+2)/2! + (1+2+3)/3! +...+ (1+2+...+n)/n!*/

double bT1(int n){
    if(n <= 0) return -1;
    double result = 1, S = 1, P = 1;//P để tính tổng dãy số, S để tính dây thừa

    for(int i=2; i<=n; i++){
        P += i;
        S *= i;
        result += P/S;
    }

    return result;
}

/*1.2.
Tính giá trị biểu thức:
S = 1 + 2/3 + 2*4/3*5 + 2*4*2*(n+1)/3*5*(2n+3)
*/

double bT2(int n){
    if(n <= 0) return -1;
    double result = 1, S = 1;
    for(int i=0; i<n; i++){
        S *= double(2*(i+1))/(2*i+3);
        result += S;
    }

    return result;
}

/*1.3.Tính
S = 1 + 3/2! + 5/3! +....+ (2n-1)/n!
*/

double bT3(int n){
    if(n <= 0) return -1;
    double result = 1, S = 1;

    for(int i=2; i<=n; i++){
        S *= i;
        result += double(2*i-1)/S;
    }

    return result;
}

/*1.4. 
Cho dãy n số nguyên a[I], I=1..n. Hãy tìm cách dưa k số đầu cuối về cuối dãy. Hãy chạy
chương trình khi n=60.000
*/

void bT4(){
    int n;
    cout << "Nhap so luong phan tu cua mang: "; cin>>n;
    if(n<=0){
        cout << "Loi!";
        return;
    }
    int  a[n];
    for(int i=0; i<n; i++){
        a[i] = i+1;
    }

    cout << "Mang truoc khi di chuyen: ";
    for(auto j:a) cout << j << " ";

    int k;
    cout << "\nNhap so luong phan tu mang muon di chuyen: "; cin>>k;
    if(k >= n){
        cout << "Loi!";
        return;
    }
    
    for(int i=0; i<n; i++){
        if(i >= n-k) a[i] -= (n-k);//Đối với k vị trí cuối: giá trị = giá trị - (n-k)
        else a[i] += k;//Đối với n-k phần tử đầu: giá trị = giá trị + k
    }

    for(auto i:a) cout << i << " ";
}

/*1.5. Thực hiện phép cộng, trừ, nhân hai số nguyên lớn.*/
string add(string num1, string num2) {
    string result = "";
    int carry = 0, sum;
    int n1 = num1.size(), n2 = num2.size();
    
    // Làm cho độ dài của hai số bằng nhau bằng cách thêm số 0 vào đầu chuỗi ngắn hơn
    string num1_copy = string(max(n2 - n1, 0), '0') + num1;
    string num2_copy = string(max(n1 - n2, 0), '0') + num2;

    // Cộng từng chữ số từ cuối đến đầu
    for (int i = num1_copy.size() - 1; i >= 0; i--) {
        sum = (num1_copy[i] - '0') + (num2_copy[i] - '0') + carry;
        carry = sum / 10;
        result.push_back(sum % 10 + '0');
    }

    if (carry) result.push_back(carry + '0');
    reverse(result.begin(), result.end());
    return result;
}

string sub(const string &num1, const string &num2) {
    string result = "";
    int borrow = 0, diff;
    int n1 = num1.size(), n2 = num2.size();
    
    // Làm cho độ dài của hai số bằng nhau bằng cách thêm số 0 vào đầu chuỗi ngắn hơn
    string num1_copy = num1;
    string num2_copy = string(n1 - n2, '0') + num2;

    // Trừ từng chữ số từ cuối đến đầu
    for (int i = n1 - 1; i >= 0; i--) {
        diff = (num1_copy[i] - '0') - (num2_copy[i] - '0') - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.push_back(diff + '0');
    }

    // Loại bỏ các số 0 ở đầu kết quả
    while (result.size() > 1 && result.back() == '0')
        result.pop_back();
        reverse(result.begin(), result.end());
    return result;
}

string multi(string num1, string num2) {
    int n1 = num1.size(), n2 = num2.size();
    string result(n1 + n2, '0');

    for (int i = n1 - 1; i >= 0; i--) {
        int carry = 0;
        for (int j = n2 - 1; j >= 0; j--) {
            int sum = (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0') + carry;
            carry = sum / 10;
            result[i + j + 1] = sum % 10 + '0';
        }
        result[i] += carry;
    }

    // Loại bỏ các số 0 ở đầu kết quả
    size_t startpos = result.find_first_not_of('0');
    if (string::npos != startpos) {
        return result.substr(startpos);
    }
    return "0";
}

/*1.6. Đếm xem từ 1 đến 10.000.000 có bao nhiêu số chính phương ?*/

void bT6(){
    int result = 0;
    for(int i=1; i<=10000000; i++){
        if(sqrt(i) == int(sqrt(i))) result++;
    }

    cout << "So chinh phuong trong [1;10000000]: " << result;
}

/*1.7. Cho dãy n số nguyên a0,a1,...,an-1. Hãy rút gọn dãy số.
Ví dụ INPUT: 3 4 2 3 1 3 8 thì OUTPUT: 3 4 2 1 8*/

void bT7(){
    int n;
    cout << "Nhap so luong phan tu cua mang: "; cin>>n;
    if(n<=0){
        cout << "Loi!";
        return;
    }
    int a[n];
    map<int,int> tmp;
    for(int i=0; i<n; i++){
        cin>>a[i];
        tmp[a[i]]++;
    } 
    for(auto i:tmp)
        cout << i.first << " ";
}

int main(){


    return 0;
}