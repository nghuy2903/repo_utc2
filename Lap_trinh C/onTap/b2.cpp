#include <bits/stdc++.h>

using namespace std;


int main(){
    int n, m;cin >> n >> m;

    int* a ,* b;

    a = new int[n*m];

    b = new int[n*m];
    
    for(int i=0; i<n*m; i++){
           cin >> a[i]; 
        
    }
    for(int i=0; i<n*m; i++){
           cin >> b[i]; 
        
    }

    for(int i=0; i<n*m; i++){
        cout << (a[i] + b[i]) << " "; 
        if(i%2!=0 ) cout << endl;
    }


    delete[] a;
    delete[] b;
    return 0;
}