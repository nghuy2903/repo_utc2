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
        string name;//thêm tên của mảng
    public:

//###INSERT CODE HERE -

    MyArray(int x, string s = "");
    MyArray(const MyArray& other, string s = "");
    MyArray(int x, T y, string s = "");
    MyArray(string s = "");
    ~MyArray(){
        // cout << "\nGoi ham huy";
        delete[] pElement;
    }

    T& operator [](int x)const;
    MyArray& operator =(const MyArray& other);
    int GetLength();
     T& ElementAt(int x)const;
     void PrintArray()const;
};

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

int main()
{
    string test;cin>>test;
    MyArray<int> a1(3), a2(5,-1, "a2");
    a1[0] = 1;
    a1[1] = 2;
    a1[2] = 3;
    a1.PrintArray(); a2.PrintArray();

    MyArray<int> b1(a1),b2(a2,"b2"), b3=a1;
    b1.PrintArray(); b2.PrintArray(); b3.PrintArray();

    MyArray<int> c1(3,"c1"),c2(3,"c2"), d1("d1"),d2;
    c2=c1=a1;
    c1.PrintArray(); c2.PrintArray();
    d1=d2=a2;
    d1.PrintArray();d2.PrintArray();

    return 0;
}
