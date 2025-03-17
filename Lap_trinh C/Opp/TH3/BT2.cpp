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
        T *pElement; //con trỏ quản lý mảng động
        int iLength; //kích thước của mảng, số lượng phần tử tối đa mà mảng có thể chứa được

    public:

//###INSERT CODE HERE -
    MyArray();
    MyArray(int x);
    MyArray(int x, int y);

    T& operator [](int x)const;
    int GetLength();
     T& ElementAt(int x)const;
     void PrintArray()const;
};

template<class T> MyArray<T>::MyArray(){
    pElement = nullptr;
    iLength = 0;
}

template<class T> MyArray<T>::MyArray(int x){
    if(x < 0){
        cout << "\nLoi: chieu dai mang la so am";
        iLength = 0;
        pElement = nullptr;
        return;
    }
    else{
        pElement = new T[x];
        iLength = x ;
    }   
}

template<class T> MyArray<T>:: MyArray(int x, int y){
    if(x < 0){
        cout << "\nLoi: chieu dai mang la so am";
        iLength = 0;
        pElement = nullptr;
    }
    else {
        iLength = x;
        pElement = new T[x];
        for (int i = 0; i < iLength; i++)
            pElement[i] = y;
    }
}

template<class T> T& MyArray<T>::operator [](int x)const {
    return ElementAt(x);
}

template<class T> T& MyArray<T>::ElementAt(int x)const{
    if(x < 0 || x >= iLength) {
            cout << "\nLoi: truy xuat phan tu ngoai pham vi mang";
        }
        return pElement[x];
}

template<class T> int MyArray<T>::GetLength(){
    return iLength;
}

template<class T> void MyArray<T>::PrintArray()const{
    if(iLength == 0) {
       cout << "Mang rong";
       return; 
    }
    else {
        for (int i = 0; i < iLength; i++)
            cout << pElement[i] <<" ";
    }
}

int main()
{
    string test;cin>>test;
    MyArray<int> a(3),b;

    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    a[-1] = -1;
    a[3] = 3;
    a.ElementAt(1) = 10;
    a.ElementAt(2) = 20;
    a.ElementAt(3) = 30;
    cout<<"\nMang a: ";
    for (int i = 0; i < a.GetLength(); i++)
        cout << a[i] <<" ";

    cout<<"\nSo luong phan tu cua mang b: ";
    cout<<b.GetLength();
    cout<<"\nMang b: ";
    b.PrintArray();

    MyArray<float>c1(5,0);
    cout<<"\nMang c1: ";
    c1.PrintArray();
    MyArray<float> c2(-5, 1);
    cout<<"\nMang c2: ";
    c2.PrintArray();

    const MyArray<double>d(4,-1);
    cout<<"\nMang d: ";
    d.PrintArray();
    cout<<"\nd[0]: "<<d[0];
    cout<<"\nd[-1]: ";d[-1];
    cout<<"\nd[4]: ";d[4];
    cout<<"\nElementAt[4]: ";d.ElementAt(4);
    cout<<"\nElementAt[2]: "<<d.ElementAt(2);

    return 0;
}
