#include <bits/stdc++.h>
//Nguyễn Nguyên Huy - 6351071030

using namespace std;

/*Ví dụ 1: Viết chương trình tính tổng
S =1 + x/1!+ x^2/2! + x^3/3! + .... + x^n/n!
 với x và n cho trước.*/

double sumS(int x, int n){
    if(n<=0) return -1;
    double result = 1, s = 1;

    for(int i=1;i<=n;i++){
        s = s*x/i;
        cout << s;
        result += s;
    }

    return result;
}

/*Ví dụ 2: 
Tìm các cặp số khác nhau M,N sao cho tổng các ước số của M bằng N và ngược laị 
với M,N <30000*/
int sumDivisor(int n){
    if(n<=0) return -1;
    int result = 1;
    for(int i=2; i<=n/2;i++){
        if(n%i == 0) result += i;
    }

    return result;
}

void findMN(){
    for(int i=1; i<30000; i++){
        int j = sumDivisor(i);
        /*
            i != j && j > i la dieu kien de loc cap so trung
            Ngoai ra j > i de in ra cac cap so tang dan
        */
        if(i != j && j > i && i == sumDivisor(j))
            cout << i << " " << j << endl;
    }

}

/*Ví dụ 3: 
Cho hai dãy số nguyên A,B lần lượt có số phần tử là n,m. 
Xét xem A,B có bằng nhau hay không ?
*/
bool check(int A[], int n, int B[], int m){
    if(n != m) return false; //Neu so luong phan tu khac nhau thi tra ve sai

    for(int i=0; i<n; i++){
        if(A[i] != B[i]) return false;
    }

    return true;
}

/*Ví dụ 4: 
Xét bài toán cổ sau:
Vừa gà vừa chó, bó lại cho tròn, ba mươi sáu con ,một trăm chân chẳn.
Hỏi có bao nhiêu gà bao nhiêu chó ?
*/

void findCD(){
    for(int i=1; i<36; i++){
        int j = 36-i;
        if(i*2 + j*4 == 100) cout << i << " " << j;
    }
}

/*Ví dụ 5:
Tính giá trị biểu thức:
1/1! + 3/2! + 5/3! + ... + (2n-1)/n!
*/

double count(int n){
    if(n <= 0) return -1;
    double result = 0, S = 1;
    for(int i=1; i<=n; i++){
        S = S * i;
        result += double(2*i-1)/S;
    }

    return result;
}

/*Ví dụ 6:
Tính giá trị biểu thức:
1 + 2/3 + 2*4/3*5 + 2*4*2*(n+1)/3*5*(2n+3)
*/
double countB(int n){
    double result = 1, S = 1;
    for(int i=0; i<n; i++){
        S *= double(2*(i+1))/(2*i+3);
        result += S;
    }

    return result;
}

/*Ví dụ 7. 
Cho dãy n số nguyên {a}. Dãy con liên tiếp là dãy mà thành phần của nó là các thành
phần liên tiếp nhau trong {a}. Ta gọi tổng của dãy con là tổng tất cả các thành phần của nó. Tìm
tổng lớn nhất trong tất cả các tổng của các dãy con của {a}
*/

int findMax(vector<int> A){
    int maxTmp = 0, Max = 0;

    for(int i=0; i<A.size(); i++){
        maxTmp = max(maxTmp + A[i], A[i]);
        Max = max(Max, maxTmp);
    }

    return Max;
}

int main(){
    vector<int> A = {4,-5,6,-4,2,3,-7};

    cout << findMax(A);
    
    return 0;
}