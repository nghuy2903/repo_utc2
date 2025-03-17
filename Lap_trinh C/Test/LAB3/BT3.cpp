#include <bits/stdc++.h>
//Nguyễn Nguyên Huy - 6351071030
using namespace std;

/*Trung tâm tính toán hiệu năng cao nhận
được đơn đặt hàng của n khách hàng. Khách
hàng i muốn sử dụng máy trong khoảng thời gian
từ ai đến bi và trả tiền thuê là ci. Hãy bố trí lịch
thuê máy để tổng số tiền thu được là lớn nhất
mà thời gian sử dụng máy của 2 khách hàng bất
kì được phục vụ đều không giao nhau (cả trung
tâm chỉ có một máy cho thuê).*/

bool Compair(vector<int> a, vector<int> b){
    return a[0] < b[0];
}

void OAS(vector<vector<int>> &schedule){
    sort(schedule.begin(), schedule.end(), Compair);
    vector<int> prev(schedule.size(), -1), val(schedule.size());
    int Lmax = 0, posEnd = 0;
    val[0] = schedule[0][2];

    for(int i=1; i<schedule.size();i++){
       val[i] = schedule[i][2];
        for(int j=0; j<i; j++){
            if(schedule[j][1] <= schedule[i][0] && val[j] + schedule[i][2] > val[i]){
                prev[i] = j;
                val[i] = val[j] + schedule[i][2];
            }
        }

        if(val[i] > Lmax){
            Lmax = val[i];
            posEnd = i;
        }
    }



    cout << "Tong tien thu duoc: " <<  Lmax << endl;
    cout << "Cuoc hop duoc chon:\n";
    vector<vector<int>> lis;
    for(int i=posEnd;i>=0;i=prev[i]){
        lis.push_back(schedule[i]);
    }
    reverse(lis.begin(), lis.end());
    for(auto i:lis){
        for(auto j:i) cout << j << " ";
        cout << endl;
    }
}

int main(){
    vector<vector<int>> schedule = {{1, 3, 20}, {2, 5, 10}, {4, 6, 30}, {6, 7, 10}, {5, 8, 15}};
    OAS(schedule);
    return 0;
}


