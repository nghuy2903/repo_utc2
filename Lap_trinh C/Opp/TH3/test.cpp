#include <bits/stdc++.h>

using namespace std;

class CN{
    string ten, dc;
    int nam;
    public:
        void Nhap();
        void In();
        int getNam(){return nam;}
};

class SV : public CN{
    float DBT;
    public:
        void Nhap();
};

void CN::Nhap(){
    cin.ignore();
    getline(cin, ten);
    getline(cin, dc);
    cin >> nam;
    
}

void SV::Nhap(){
    CN::Nhap();
    cin >> DBT;
}

int main(){
    int n;cin>>n;

    SV* dssv = new SV[n];
    for(int i=0; i<n; i++){
        dssv[i].Nhap();
    }

    return 0;
}