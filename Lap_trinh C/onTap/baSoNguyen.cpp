#include <iostream>

using namespace std;

int main(){
    int a[9];
   for (int i = 0; i < 9; i++)
   {
    cin >> a[i];
   }

   for(int i=0; i<9; i++ ){
     if(a[i] > 9 || a[i] < 0) {
        cout << "INVALID";
        return 0;
     }
     else {
        for(int j=i+1; j<9; j++){
            if(a[j] == a[i]){
                cout << "INVALID";
                return 0;
            }
        }
    }
   }

   cout << "VALID";

   return 0;
}