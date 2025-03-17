/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
struct
###End banned keyword*/
#include <iostream>
using namespace std;

template<class T> class MyArray
{
    private:
        T *pElement;
        int iLength;
        string name;
    public:
        MyArray(string s="");//thêm đối mặc định cho 3.2
        MyArray(int n, string s="");//thêm đối mặc định cho 3.2
        int GetLength()const;
        T & ElementAt(const int &iIndex); //nếu bỏ & thì hàm chỉ return giống như trả về 1 giá trị để đọc, chứ không truy cập vào vùng nhớ của phần thử để gán
        T & operator [](const int &iIndex); //Kết quả trả về là tham chiếu để phần tử trả về, có thể đứng ở bên trái của phép toán gán.
        //bổ sung cho bài 2
        MyArray(int n, T value, string name="");//thêm đối mặc định cho 3.2
        void PrintArray()const;
        T ElementAt(const int &iIndex) const; //phiên bản dành riêng cho đối tượng hằng
        T  operator [](const int &iIndex) const; //phiên bản dành riêng cho đối tượng hằng
        //bổ sung cho bài 3
        ~MyArray();
        MyArray(const MyArray &b,string s="");//thêm đối mặc định cho 3.2
        MyArray & operator=(const MyArray &b); //toán tử gán
        //bổ sung cho bài 4
        void InputArray();
};

//###INSERT CODE HERE -

template<class T> MyArray<T>::~MyArray(){
    delete[] pElement;
}

template<class T> MyArray<T>::MyArray(string s){
    pElement = nullptr;
    iLength = 0;
    name = s;
}

template<class T> MyArray<T>::MyArray(int x, string s){
    if(x < 0){
        cout << "\nLoi: chieu dai mang la so am";
        iLength = 0;
        pElement = nullptr;
        name = s;
        return;
    }
    else{
        pElement = new T[x];
        iLength = x ;
        name = s;
    }   
}

template<class T> MyArray<T>::MyArray(const MyArray& other, string s){
    if(other.iLength== 0){
        iLength = 0;
        pElement = nullptr;
        name = s;
    }
    else{
        iLength = other.iLength;
        pElement = new T[iLength];
        name = s;
        for(int i=0; i<iLength; i++){
            pElement[i] = other.pElement[i];
        }
    }
}

template<class T> MyArray<T>::MyArray(int x, T y, string s){
    if (x < 0) {
        cout << "\nLoi: chieu dai mang la so am";
        iLength = 0;
        pElement = nullptr;
        name = s;
    } else {
        iLength = x;
        pElement = new T[x];
        name = s;
        for (int i = 0; i < iLength; i++)
            pElement[i] = y;
    }

}

template<class T> T& MyArray<T>::operator [](const int &x){
    return ElementAt(x);
}

template<class T> T& MyArray<T>::ElementAt(const int& x){
    if(x < 0 || x >= iLength) {
            cout << "\nLoi: truy xuat phan tu ngoai pham vi mang";
        }
        return pElement[x];
}

template<class T> T MyArray<T>::operator [](const int &x) const{
    return ElementAt(x);
}

template<class T> T MyArray<T>::ElementAt(const int& x) const{
    if(x < 0 || x >= iLength) {
            cout << "\nLoi: truy xuat phan tu ngoai pham vi mang";
        }
        return pElement[x];
}

template<class T> int MyArray<T>::GetLength() const{
    return iLength;
}

template<class T> void MyArray<T>::PrintArray()const{
    if(iLength == 0) {
       cout << "Mang rong";
       return; 
    }
    else {
        if(name != "") cout<<"\nXuat mang "<<name<<": ";
        else cout<<"\nXuat mang: ";  
        for (int i = 0; i < iLength; i++)
            cout << pElement[i] <<" ";
    }
}

template<class T> MyArray<T>& MyArray<T>::operator =(const MyArray& other) {
    if(iLength == 0){
        cout<<"\nCap phat bo nho truoc khi gan";
        pElement = new T[other.iLength];
        iLength = other.iLength;
    } 
    if(iLength != other.iLength) cout<<"\nPhep gan khong tuong thich, khong gan duoc";
    
    for (int i = 0; i < iLength; i++) {
        pElement[i] = other.pElement[i];
    }
    
    
    return *this;
}

template<class T> void MyArray<T>::InputArray(){
    if(iLength == 0){
        if(name != "") cout<<"\nNhap so luong phan tu cua mang "<<name<<": ";
        else cout<<"\nNhap so luong phan tu cua mang: ";
        int n;cin>>n;
        iLength = n;
        pElement = new T[n];
        
    }
    if(name != "") cout<< "\nNhap mang " << name << " voi " << iLength << " gia tri: "; 
    else cout << "\nNhap mang voi " << iLength << " gia tri: ";
    for(int i = 0; i< iLength; i++){
        cin >> pElement[i];
    }
}

int main()
{
    string test;cin>>test;

    MyArray<int> a(3), b, c(5, "c"),d("d");
    a.InputArray();
    a.PrintArray();
    b.InputArray();
    b.PrintArray();
    c.InputArray();
    c.PrintArray();
    d.InputArray();
    d.PrintArray();

    return 0;
}
