/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
struct
###End banned keyword*/
#include <iostream>
using namespace std;




//###INSERT CODE HERE -

template<class T> class MyArray
{
    private:
        T *pElement;
        int iLength;
        string name;
        int iNumber;
        const T NULLDATA=-100; //thêm: đánh dấu phần tử bị xóa, hoặc giá trị return khi lỗi

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
        void PopBack();
        bool IsEmpty();
        T GetBack();

        MyArray& operator<<(const T& value) {
            PushBack(value);
            return *this;
        }

        MyArray& operator>>( T& value) {
            value = GetBack();
            PopBack();
            return *this;
        }

        friend class PhanSo;

        template<class U> friend istream& operator >> (istream& input, MyArray<U>& arr);
        template<class U> friend ostream& operator << (ostream& output, MyArray<U>& arr);
        
};



template <class T> MyArray<T>::~MyArray()
{
    delete[] pElement;
}

template <class T> MyArray<T>::MyArray(string s) : NULLDATA(-100)
{
    pElement = nullptr;
    iLength = 0;
    name = s;
    iNumber = 0;
}

template <class T> MyArray<T>::MyArray(int x, string s) : NULLDATA(-100)
{
    if (x < 0)
    {
        cout << "\nLoi: chieu dai mang la so am";
        iLength = 0;
        pElement = nullptr;
        name = s;
    }
    else
    {
        pElement = new T[x];
        for (int i = 0; i < x; i++)
        {
            pElement[i] = T();
        }
        iLength = x;
        iNumber = 0;
        name = s;
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

template <class T> int MyArray<T>::GetLength() const
{
    return iLength;
}

template <class T> void MyArray<T>::PrintArray() const
{
    if (iLength == 0 || iNumber == 0)
    {
        cout << "\nXuat mang: ";
        // cout << "\nMang rong";
        cout << NULLDATA;
        return;
    }
    else
    {
        if (name != "")
            cout << "\nXuat mang " << name << ": ";
        else
            cout << "\nXuat mang: ";
        int x = iLength <= iNumber ? iLength : iNumber;
        for (int i = 0; i < x; i++)
        {
            cout << pElement[i] << " ";
        }
    }
}
template <class T> void MyArray<T>::InputArray()
{
    for (int i = 0; i < iLength; i++)
    {
        T value;
        cin >> value;
        pElement[i] = value;
    }


}

template <class T> istream &operator>>(istream &input, MyArray<T> &arr)
{
    arr.InputArray();
    return input;
}

template <class T> ostream &operator<<(ostream &output, MyArray<T> &arr)
{
    arr.PrintArray();
    return output;
}

template <class T> void MyArray<T>::PushBack(T x)
{
    if (iNumber == iLength)
    {
        iLength++;
        pElement[iNumber] = x;
        iNumber++;
    }
    else
    {
        pElement[iNumber] = x;
        iNumber++;
    }
}

template <class T> bool MyArray<T>::IsEmpty()
{
    for (int i = 0; i < iLength; i++)
    {
        if (pElement[i] != NULLDATA)
            return false;
    }
    return true;
}

template <class T> void MyArray<T>::PopBack()
{
    if (IsEmpty())
    {
        return;
    }
    else
    {
        iNumber--;
        pElement[iNumber] = NULLDATA;
    }
}

class PhanSo
{
    long tu, mau;
    void RutGon();

public:
    void Set(long t, long m);
    PhanSo() { Set(0, 1); };
    PhanSo(long t, long m) { Set(t, m); }
    PhanSo(int x) : tu(x), mau(1) {} 

    long GetTu() const { return tu; }
    long GetMau() const { return mau; }

    PhanSo(const PhanSo &other)
    {
        tu = other.tu;
        mau = other.mau;
    }

    // Phép gán
    PhanSo &operator=(const PhanSo &other)
    {
        if (this != &other)
        {
            tu = other.tu;
            mau = other.mau;
        }
        return *this;
    }


    void Xuat() const;
    friend ostream &operator<<(ostream &out, const PhanSo &ps)
    {
        ps.Xuat();
        return out;
    }

    friend istream &operator>>(istream &in, PhanSo &ps) // Removed 'const' from the parameter
    {
        in >> ps.tu;
        in >> ps.mau;
        return in;
    }
    
};

void PhanSo::Set(long t, long m)
{
    tu = t;
    mau = m;
}

long gcd(long a, long b)
{
    a = abs(a);
    b = abs(b);
    if (a * b == 0)
        return a + b;
    if (a > b)
        return gcd(a - b, b);
    else
        return gcd(a, b - a);
}

void PhanSo::RutGon()
{
    long x = gcd(tu, mau);
    if (mau != 0)
    {
        tu /= x;
        mau /= x;
    }
    else
        cout << "Khong thoa yeu cau bai toan";
}

void PhanSo::Xuat() const
{
    
    PhanSo temp(*this);
    temp.RutGon();
    if(mau == 0) return;
    if (temp.tu * temp.mau < 0)
        cout << "-";
    temp.tu = abs(temp.tu);
    temp.mau = abs(temp.mau);
    cout << temp.tu;
    if (temp.mau != 1)
        cout << "/" << temp.mau;
}

int main()
{
   int n;cin>>n;
   MyArray<PhanSo>a(n); //Tạo 1 mảng phân số có n phần tử
   cin>>a; //Nhập n phần tử của mảng
   for(int i=n-1;i>=0;i--)
     cout<<a[i]<<endl; //Xuất các phần tử của mảng phân số


    return 0;
}
