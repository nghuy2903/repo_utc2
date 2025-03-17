#include <bits/stdc++.h>
//Nguyễn Nguyên Huy - 6351071030
using namespace std;

/* Có n cuộc họp, cuộc họp thứ i bắt đầu vào
 thời điểm ai và kết thúc ở thời điểm bi. Do chỉ có
 một phòng hội thảo nên 2 cuộc họp bất kì sẽ
 được cùng bố trí phục vụ nếu khoảng thời gian
 làm việc của chúng chỉ giao nhau tại đầu mút.
 Hãy bố trí phòng họp để phục vụ được nhiều
 cuộc họp nhất*/

void FMM(vector<pair<int,int>>& meeting){
    if(meeting.empty()) return;
    sort(meeting.begin(), meeting.end());

    cout << "Cuoc hop duoc chon:\n";

    vector<int> L(meeting.size(),1), prev(meeting.size(), -1);
    int lMax = 1, posEnd = 0;

    for(int i=1; i<meeting.size();i++){
        for(int j=0; j<i; j++){
            if(meeting[j].second <= meeting[i].first && L[j] + 1 > L[i]){
                L[i] = L[j] + 1;
                prev[i] = j;
            }
        }
        if(L[i] > lMax){
            lMax = i;
            posEnd = i;
        }
    }

    vector<pair<int,int>> lis;
    for(int i=posEnd; i>=0; i=prev[i]){
        lis.push_back(meeting[i]);
    }

    reverse(lis.begin(), lis.end());

    for(auto i:lis )
        cout  <<i.first << "->" <<i.second << endl;

}

int main(){
    vector<pair<int,int>> meeting = {{2,5}, {1,2}, {6,7}, {4,6}};
    FMM(meeting);
    
    return 0;
}