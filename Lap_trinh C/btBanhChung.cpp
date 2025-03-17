#include <iostream>


using namespace std;

int main(){
int n;
cin >> n;
int a[n], sum =  0;

for(int i=0; i<n; i++){
    cin >> a[i];
    if(a[i] <= 4) sum += a[i];
}

float banh;
int soSanh;
banh = float(sum)/4;

soSanh = int(sum)/4;

if(banh ==soSanh ) cout << banh;
 else cout << ++soSanh; 

}


