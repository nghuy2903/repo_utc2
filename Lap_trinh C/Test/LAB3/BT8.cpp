#include <bits/stdc++.h>
//Nguyễn Nguyên Huy - 6351071030
using namespace std;
/*Ở đất nước nọ người ta chỉ tiêu tiền xu. Có
N loại tiền xu, loại thứ i có mệnh giá là Ai đồng.
Một hôm có một vị khách du lịch đến thăm, ông
ta muốn đổi số tiền mình đang có mà M đồng
sang loại xu của đất nước này để tiện tiêu dùng.
Bên cạnh đó ông ta cũng muốn số đồng tiền đổi
được là ít nhất . Bạn hãy giúp ông ta tìm cách đổi
tiền yêu cầu trên.*/

bool Compair(int a, int b){
    return a>b;
}

void FWCM(vector<int> money, int M){
    sort(money.begin(), money.end(), Compair);
    int i=0;

    while(M>0 && i<money.size()){
        int temp = M/money[i];
        cout << temp << " xu " << money[i] << " dong\n";
        M = M - temp*money[i];
        i++;
    }

    // for(auto i:money) cout << i << " ";

}


int main(){
    int n, M;
    cout << "Nhap so luong menh gia: ";cin>>n;
    vector<int> money(n);
    for(int i=0; i<n; i++){
        cin >> money[i];
    }
    cout << "Nhap so tien dang co: "; cin>>M;

    FWCM(money, M);

    return 0;
}