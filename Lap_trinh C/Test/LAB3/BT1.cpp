#include <bits/stdc++.h>
//Nguyễn Nguyên Huy - 6351071030

using namespace std;

// Cho dãy a1,a2,..an. Hãy tìm một dãy con tăng có nhiều phần tử nhất của dãy


void FLIS(const vector<int>& A) {
    if (A.empty()) return ;

    vector<int> L(A.size(), 1), previous(A.size(), -1);
    int lengthMax = 1, end = 0;
    /*L: lưu số lượng dãy con lớn nhất tính từ L[0] đến L[i]
      previous: lưu dãy con mà tại previous[i] tìm được
      end: lưu vị trí mà dãy con kết thúc
    */
    for(int i=1; i<A.size(); i++){
        for(int j=0; j<i; j++){
            if(A[j] < A[i] && L[j] + 1 > L[i]){
                L[i] = L[j] + 1;
                previous[i] = j;
            }
        }
        if(L[i] > lengthMax){
            lengthMax  = L[i];
            end = i;
        }
    }

    vector<int> lis;
    for(int i=end; i>=0; i=previous[i]){
        lis.push_back(A[i]);
    }

    reverse(lis.begin(), lis.end());
    
    for(auto i:lis) cout << i << " ";
}

int main(){
    vector<int> a = {10, 22, 34, 33, 51, 50, 41, 60, 80};
    FLIS(a);
    

    return 0;
}