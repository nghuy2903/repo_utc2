#include <iostream>


using namespace std;

int main(){
    int n;
    cin >> n;
    if(n>999 or n<100) cout << "NULL";
     else if(n == 100) cout << "mot tram";
     else if(n == 200) cout << "hai tram";
     else if(n == 300) cout << "ba tram";
     else if(n == 400) cout << "bon tram";
     else if(n == 500) cout << "nam tram";
     else if(n == 600) cout << "sau tram";
     else if(n == 700) cout << "bay tram";
     else if(n == 800) cout << "tam tram";
     else if(n == 900) cout << "chin tram";
      else {
        int a = n%100;
        int b = n/100;
        switch (b){
            case 1: cout << "mot tram" << " ";
               break;
            case 2: cout << "hai tram" << " ";
               break;
            case 3: cout << "ba tram" << " ";
               break;
            case 4: cout << "bon tram" << " ";
               break;
            case 5: cout << "nam tram" << " ";
               break;
            case 6: cout << "sau tram" << " ";
               break;
            case 7: cout << "bay tram" << " ";
               break;
            case 8: cout << "tam tram" << " ";
               break;
            case 9: cout << "chin tram" << " ";
               break;
        }
        b = a/10;
        a = a%10;
        
         switch (b){
            case 0: cout << "le";
               break;
            case 1: cout << "muoi" ;
               break;
            case 2: cout << "hai muoi" ;
               break;
            case 3: cout << "ba muoi" ;
               break;
            case 4: cout << "bon muoi" ;
               break;
            case 5: cout << "nam muoi" ;
               break;
            case 6: cout << "sau muoi" ;
               break;
            case 7: cout << "bay muoi" ;
               break;
            case 8: cout << "tam muoi" ;
               break;
            case 9: cout << "chin muoi" ;
               break;
            }
        switch (a){
            case 0: 
               break;
            case 1: cout << " muoi" ;
               break;
            case 2: cout << " hai" ;
               break;
            case 3: cout << " ba";
               break;
            case 4: cout << " bon" ;
               break;
            case 5: cout << " nam";
               break;
            case 6: cout << " sau";
               break;
            case 7: cout << " bay";
               break;
            case 8: cout << " tam";
               break;
            case 9: cout << " chin";
               break;
        }

        
    }

    
return 0;
}