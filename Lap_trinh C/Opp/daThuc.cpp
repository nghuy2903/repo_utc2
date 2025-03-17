/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
struct
###End banned keyword*/

//###INSERT CODE HERE -
#include <bits/stdc++.h>

using namespace std;
class DATHUC{
private:
    int n;
    float* a;
    float* b;
public:
    DATHUC();
    DATHUC(int m);
   void Nhap();
   void Xuat();
   double TinhDaThuc(double x);
   bool Check();
   bool sosanh(DATHUC* b);
   DATHUC* congHaiDaThuc(DATHUC* b);
   ~DATHUC(){
    delete []a;
    delete []b;
   }
};

DATHUC::DATHUC() {
    n = 0;
    a = nullptr;
    b = nullptr;
}
DATHUC::DATHUC(int m){
    n = m;
    a = new float[m+1];
    b = new float[m+1];
}

void DATHUC::Nhap(){
for(int i = n; i > 0; i--){
    cin >> a[i];
    cin >> b[i];
}
}

bool DATHUC::Check(){
   for(int i=n; i>0; i--){
    if(a[i] != 0) return false;
   }
   return true;
}

void DATHUC::Xuat(){
    if(n==0 || Check()){
        cout<< 0;
        return;
    }
    bool check = false;
    for(int i = n; i > 0;i--){
        if (a[i] != 0){
          if (a[i] > 0){
            if(check) cout << "+";
           }
            else if(a[i]< 0){
            cout << "-";
            }

            if (abs(a[i]) != 1 || b[i] == 0) {
             cout << abs(a[i]);
            }

            if (b[i] > 1) {
             cout << "x^" << b[i];
            } 
            else if (b[i] == 1) {
             cout << "x";
            }
        check = true;
        }
    }

}

double DATHUC::TinhDaThuc(double x){
    double res = 0;
    for(int i=n; i>0; i--){
        res += a[i]*pow(x, b[i]);
    }
    return res;
}

void bubbleSort(float arr[], float b[],  int size) {
    for (int i = 1; i <= size - 1; i++) {
        for (int j = 1; j <= size - i - 1; j++) {
            if (b[j] > b[j + 1]) {
                // Hoán đổi hai phần tử nếu thứ tự sai
                int temp1 = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp1;
                int temp2 = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp2;
            }
        }
    }
}



DATHUC* DATHUC::congHaiDaThuc(DATHUC* c) {
    DATHUC* res = new DATHUC(this->n + c->n );
    for (int i = 1; i <= this->n; i++) {
      res->a[i] = a[i];
      res->b[i] = b[i];
    }
    int j = this->n + 1;
    for (int i = 1; i <= c->n; i++) {
      res->a[j] = c->a[i];
      res->b[j] = c->b[i];
      j++;
    }
    int temp = j;
    for (int i = 1; i <= j; i++) {
        for (int l = i + 1; l < j; l++) {
            if (res->b[i] == res->b[l]){
                res->a[i] = res->a[i] + res->a[l];
                res->a[l] = 0;
                res->b[l] = 0;
                continue;
            }
        }
    }

    bubbleSort(res->a, res->b, temp);

    return res;
}


int main() {
    int n;cin>>n;
    DATHUC *A=new DATHUC(n);
    A->Nhap();
    

    int m;cin>>m;
    DATHUC *B=new DATHUC(m);
    B->Nhap();
    cout << "Da thuc A: "; A->Xuat();
    cout<<endl;
    cout << "Da thuc B: "; B->Xuat();
    cout<<endl;

    DATHUC* C;
    C = A->congHaiDaThuc(B);
    cout << "A+B = "; C->Xuat();

    delete A;
    delete B;
    delete C;
    return 0;
}
