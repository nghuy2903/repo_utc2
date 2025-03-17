#include <iostream>
using namespace std;

template <class T> class MyArray
{
private:
    T *pElement;
    int iLength;
    string name;
    int iNumber;
    const T NULLDATA = -100;

public:
    MyArray(string s = "");
    MyArray(int n, string s = "");
    int GetLength() const;
    T &ElementAt(const int &iIndex);
    T &operator[](const int &iIndex);
    MyArray(int n, T value, string name = "");
    void PrintArray() const;
    T ElementAt(const int &iIndex) const;
    T operator[](const int &iIndex) const;
    ~MyArray();
    MyArray(const MyArray &b, string s = "");
    MyArray &operator=(const MyArray &b);
    void InputArray(int n);
    void InputArray();
    int GetSize()
    {
        return iNumber;
    }
    void PushBack(T x);
    int GetPosEmpty();
    void PopBack();
    bool IsEmpty();
    T GetBack();

    MyArray &operator<<(const T &value)
    {
        PushBack(value);
        return *this;
    }

    MyArray &operator>>(T &value)
    {
        value = GetBack();
        PopBack();
        return *this;
    }

    friend class PhanSo;

    template <class U> friend istream &operator>>(istream &input, MyArray<U> &arr);
    template <class U> friend ostream &operator<<(ostream &output, MyArray<U> &arr);
    MyArray<T> &operator++();       
    MyArray<T> operator++(int);    
    MyArray<T> &operator--();     
    MyArray<T> operator--(int);    

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

template <class T> MyArray<T>::MyArray(const MyArray<T> &b, string s) : NULLDATA(b.NULLDATA)
{
    iLength = b.iLength;
    iNumber = b.iNumber;
    name = s;

    pElement = new T[iLength];
    for (int i = 0; i < iLength; i++)
    {
        pElement[i] = b.pElement[i];
    }
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

template <class T> T &MyArray<T>::operator[](const int &x)
{
    return ElementAt(x);
}

template <class T> T &MyArray<T>::ElementAt(const int &x)
{
    if (x < 0 || x >= iLength)
    {
        cout << "\nLoi: truy xuat phan tu ngoai pham vi mang";
    }
    return pElement[x];
}

template <class T> T MyArray<T>::operator[](const int &x) const
{
    return ElementAt(x);
}

template <class T> T MyArray<T>::ElementAt(const int &x) const
{
    if (x < 0 || x >= iLength)
    {
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
        cout << "\nMang rong";
        return;
    }
    else
    {
        if (!name.empty())
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

template <class T> MyArray<T> &MyArray<T>::operator++()
{
    for (int i = 0; i < iNumber; i++)
    {
        pElement[i] = pElement[i] +1;
    }
    return *this;
}

template <class T> MyArray<T> MyArray<T>::operator++(int)
{
    MyArray<T> temp(*this);
    operator++();
    return temp;
}

template <class T> MyArray<T> &MyArray<T>::operator--()
{
    for (int i = 0; i < iNumber; i++)
    {
        pElement[i] = pElement[i] - 1;
    }
    return *this;
}

template <class T> MyArray<T> MyArray<T>::operator--(int)
{
    MyArray<T> temp(*this);
    operator--();
    return temp;
}

template <class T>
MyArray<T>& MyArray<T>::operator=(const MyArray<T> &b)
{
    if (this != &b)
    {
        delete[] pElement;

        iLength = b.iLength;
        iNumber = b.iNumber;
        name = b.name;

        pElement = new T[iLength];
        for (int i = 0; i < iLength; i++)
        {
            pElement[i] = b.pElement[i];
        }
    }
    return *this;
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

    friend istream &operator>>(istream &in, PhanSo &ps)
    {
        in >> ps.tu;
        in >> ps.mau;
        return in;
    }


    PhanSo& operator++();
    PhanSo operator++(int);
    PhanSo& operator--();
    PhanSo operator--(int);

    PhanSo operator +(long a) const;
	PhanSo operator -(long a) const;
    PhanSo operator *(long a) const;
	PhanSo operator /(long a) const;

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
    if (mau == 0)
        return;
    if (temp.tu * temp.mau < 0)
        cout << "-";
    temp.tu = abs(temp.tu);
    temp.mau = abs(temp.mau);
    cout << temp.tu;
    if (temp.mau != 1)
        cout << "/" << temp.mau;
}

PhanSo& PhanSo::operator++()
{
    tu += mau;
    RutGon();
    return *this;
}

PhanSo PhanSo::operator++(int)
{
    PhanSo temp(*this);
    tu += mau;
    RutGon();
    return temp;
}

PhanSo& PhanSo::operator--()
{
    tu -= mau;
    RutGon();
    return *this;
}

PhanSo PhanSo::operator--(int)
{
    PhanSo temp(*this);
    tu -= mau;
    RutGon();
    return temp;
}

PhanSo PhanSo::operator +(long a) const{
	return PhanSo( tu + a*mau, mau);
}

PhanSo PhanSo::operator -(long a) const{
	return PhanSo( tu - a*mau, mau);
}

PhanSo PhanSo::operator *(long a) const{
	return PhanSo( tu * a, mau);
}

PhanSo PhanSo::operator /(long a) const{
	return PhanSo( tu , mau*a);
}

int main()
{
    string test;cin>>test;
    cout<<"\nTest toan tu tang giam cua Mang\n";

    int n;cin>>n;//Nhập số lượng phần tử của mảng
    MyArray<PhanSo>a_arr(n, "a"),b_arr("b"),c_arr("c"),d_arr("d"),e_arr("e");
    cin>>a_arr; //Nhập n phần tử của mảng
    cout<<a_arr;
    cout<<"\nb=a++";
    b_arr=a_arr++;
    cout<<a_arr<<b_arr;
    cout<<"\nc=++a";
    c_arr=++a_arr;
    cout<<a_arr<<c_arr;
    cout<<"\nd=(--b)";
    d_arr=(--b_arr);
    cout<<d_arr<<b_arr;
    cout<<"\ne=(c--)";
    e_arr=(c_arr--);
    cout<<e_arr<<c_arr;

    return 0;
}
