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
    if (iLength == 0)
    {
        if (name != "")
            cout << "\nNhap kich thuoc cua mang " << name << ": ";
        else
            cout << "\nNhap kich thuoc cua mang: ";

    label:
        int n;
        cin >> n;
        if (n <= 0)
        {
            cout << "\nKich thuoc mang khong hop le. Moi ban nhap lai: ";
            goto label;
        }
        iLength = n;
        pElement = new T[n];
        iNumber = n;
    }
    if (name != "")
        cout << "\nNhap mang " << name << " voi " << iLength << " gia tri: ";
    else
        cout << "\nNhap mang voi " << iLength << " gia tri: ";
    for (int i = 0; i < iLength; i++)
    {
        cin >> pElement[i];
    }
    iNumber = iLength;
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

    void Xuat() const;
    friend ostream &operator<<(ostream &out, const PhanSo &ps)
    {
        ps.Xuat();
        return out;
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
        cout << "loi\n";
}

void PhanSo::Xuat() const
{
    PhanSo temp(*this);
    temp.RutGon();
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
    string test;
    cin >> test;

    MyArray<int> a(5, "so nguyen a");
    a << 0 << 1 << 2;
    cout << a;
    cout << "\nSo luong phan tu cua mang a: " << a.GetSize();
    cout << "\nKich thuoc cua mang a: " << a.GetLength();

    MyArray<PhanSo> b(10, "phan so b");
    b << PhanSo(1, 2) << PhanSo(-3, -4) << PhanSo(2, -1) << PhanSo(6, -8) << PhanSo(-3, 1) << PhanSo(0, -5) << PhanSo(4, 2);
    cout << b;
    cout << "\nSo luong phan tu cua mang b: " << b.GetSize();
    cout << "\nKich thuoc cua mang b: " << b.GetLength();

    return 0;
}