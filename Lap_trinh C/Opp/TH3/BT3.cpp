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
    MyArray(const MyArray& other);
    ~MyArray(){
        cout << "\nGoi ham huy";
        delete[] pElement;
    }

    T& operator [](int x)const;
    MyArray& operator =(const MyArray& other);
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

template<class T> MyArray<T>::MyArray(const MyArray& other){
    if(other.iLength== 0){
        iLength = 0;
        pElement = nullptr;
    }
    else{
        iLength = other.iLength;
        pElement = new T[iLength];
        for(int i=0; i<iLength; i++){
            pElement[i] = other.pElement[i];
        }
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

template<class T> MyArray<T>& MyArray<T>::operator =(const MyArray& other){
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

int main()
{
    string test;cin>>test;
    MyArray<int> a(3);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;

    cout<<"\nMang a: ";
    a.PrintArray();
    MyArray<int> b1(a), b2=a;
    cout<<"\nMang b1: ";
    b1.PrintArray();
    cout<<"\nMang b2: ";
    b2.PrintArray();


    MyArray<int> c1(3),c2;
    c2=c1=a;
    cout<<"\nMang c1: ";
    c1.PrintArray();
    cout<<"\nMang c2: ";
    c2.PrintArray();

    return 0;
}
