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
        int iNumber;// thêm số lượng phần tử của mảng, số đối tượng(giá trị) thực đang chứa trong mảng

    public:


//###INSERT CODE HERE -

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
        void InputArray(int n);
        void InputArray();
        int GetSize(){
            return iNumber; 
        }
        void PushBack(T x);
        int GetPosEmpty();

        template<class U> friend istream& operator >> (istream& input, MyArray<U>& arr);
        template<class U> friend ostream& operator << (ostream& output, MyArray<U>& arr);
};


template<class T> MyArray<T>::~MyArray(){
    delete[] pElement;
}

template<class T> MyArray<T>::MyArray(string s){
    pElement = nullptr;
    iLength = 0;
    name = s;
    iNumber = 0;
}

template<class T> MyArray<T>::MyArray(int x, string s){
    if(x < 0){
        cout << "\nLoi: chieu dai mang la so am";
        iLength = 0;
        pElement = nullptr;
        iNumber = 0;
        name = s;
        return;
    }
    else{
        pElement = new T[x];
        iLength = x ;
        iNumber = 0;
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
    iNumber = other.iNumber;
}

template<class T> MyArray<T>::MyArray(int x, T y, string s){
    if (x < 0) {
        cout << "\nLoi: chieu dai mang la so am";
        iLength = 0;
        pElement = nullptr;
        name = s;
        // iNumber
    } else {
        iLength = x;
        pElement = new T[x];
        name = s;
        for (int i = 0; i < iLength; i++)
            pElement[i] = y;
    }
    iNumber = 0;

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
    if(iLength == 0 || iNumber == 0) {
        cout << "\nXuat mang " << name << ": ";
        cout << "\nMang rong";
        return; 
    }
    else {
        if(name != "") cout<<"\nXuat mang "<<name<<": ";
        else cout<<"\nXuat mang: "; 
        int x =  iLength <= iNumber ? iLength : iNumber; 
        for (int i = 0; i < x; i++)
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

template<class T> void MyArray<T>::InputArray(int x){
    cout<<"\nBan muon nhap "<<x<<" gia tri nhung kich thuoc mang la chua biet. Ban co muon thiet lap kich thuoc mang la "<<x<<" khong?(c/k)";
    char c; cin>>c;
   

    if(c == 'c'){
        if(x <= 0){
            cout<<"\nSo luong phan tu khong hop le, ket thuc viec nhap";
            iNumber = 0;
            return;
        }
        else{
            iNumber = x;
            iLength = x;
            pElement = new T[x];
            if(iNumber > iLength){
                cout << "\nSo luong phan tu (" << x << ") nhieu hon suc chua cua mang (" << iLength << ") nen chi nhap duoc " << iLength << " gia tri";
                iNumber = iLength;
            }
            
            
            int temp = iLength <= iNumber ? iLength : iNumber;
            if(name != "") cout<< "\nNhap mang " << name << " voi " << temp << " gia tri: "; 
            else cout << "\nNhap mang voi " << temp << " gia tri: ";
            
            for(int i = 0; i <temp; i++){
                cin >> pElement[i];
            }
            
        }
    }
    else if(c == 'k'){

        if(name != "") cout<<"\nNhap kich thuoc cua mang "<<name<<": ";
        else cout<<"\nNhap kich thuoc cua mang: ";

        label: int n;cin>>n;
        if(n<3){
            cout<<"\nKich thuoc mang ("<< n << ") khong du de chua 3 gia tri. Moi ban nhap lai:";
            goto label;
        }
        iLength = n;
        pElement = new T[n];
        iNumber = x;

        if(name != "") cout<< "\nNhap mang " << name << " voi " << iNumber << " gia tri: "; 
        else cout << "\nNhap mang voi " << iNumber << " gia tri: ";
        for(int i = 0; i< iLength; i++){
            cin >> pElement[i];
        }
    }
}

template<class T> void MyArray<T>::InputArray(){
    if(iLength == 0){
        if(name != "") cout<<"\nNhap kich thuoc cua mang "<<name<<": ";
        else cout<<"\nNhap kich thuoc cua mang: ";

        label: int n;cin>>n;
        if(n <= 0){
            cout<<"\nKich thuoc mang khong hop le. Moi ban nhap lai: "; 
            goto label;
        }
        iLength = n;
        pElement = new T[n];
        iNumber = n;
        
    }
    if(name != "") cout<< "\nNhap mang " << name << " voi " << iLength << " gia tri: "; 
    else cout << "\nNhap mang voi " << iLength << " gia tri: ";
    for(int i = 0; i< iLength; i++){
        cin >> pElement[i];
    }
    iNumber = iLength;
}

template<class T> istream& operator >>(istream& input, MyArray<T>& arr){
    arr.InputArray();
    return input;
}

template<class T> ostream& operator <<(ostream& output, MyArray<T>& arr){
    arr.PrintArray();
    return output;
}

template<class T> void MyArray<T>::PushBack(T x){
    if (iNumber == iLength) {
        iLength++;
        T *newArray = new T[iLength];

        for (int i = 0; i < iNumber; i++) {
            newArray[i] = pElement[i];
        }

        newArray[iNumber] = x;
        iNumber++;

        delete[] pElement;
        pElement = newArray;
    } else {
        pElement[iNumber] = x;
        iNumber++;
    }
}



int main()
{
    string test;cin>>test;
    MyArray<int> a(3,"a"); //mảng a rỗng, push liên tục vào
    cout << "\nSo luong phan tu cua mang a: " << a.GetSize();
    for (int i=0; i<5; i++)
        a.PushBack(i);
    cout<<a;
    cout << "\nSo luong phan tu cua mang a: " << a.GetSize();
    cout << "\nKich thuoc cua mang a: " << a.GetLength();

    MyArray<int> b(3,"b"); //mảng b chứa đủ 3 giá trị, push thêm 5 số nữa
    cin>>b;
    cout<<b;
    cout << "\nSo luong phan tu cua mang b: " << b.GetSize();
    cout << "\nKich thuoc cua mang b: " << b.GetLength();
    for (int i=0; i<5; i++)
        b.PushBack(i);
    cout<<b;
    cout << "\nSo luong phan tu cua mang b: " << b.GetSize();
    cout << "\nKich thuoc cua mang b: " << b.GetLength();
    return 0;
}
