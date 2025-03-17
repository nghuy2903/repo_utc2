#include <bits/stdc++.h>
//Nguyễn Nguyên Huy - 6351071030
using namespace std;

/*Cho n món hàng (n ≤ 50). Món hàng thứ i có
khối lượng A[i] (số nguyên). Cần chọn những
món hàng nào để bỏ vào một balô sao tổng khối
lượng của các món hàng đã chọn là lớn nhất
nhưng không vượt quá khối lượng W cho trước
(W ≤ 100) Mỗi món chỉ chọn 1 hoặc không chọn*/

void SIPB(vector<int> item, int W){
    vector<vector<int>> K(item.size() + 1, vector<int>(W + 1, 0));

    for (int i = 0; i <= item.size(); i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (item[i - 1] <= w)
                K[i][w] = max(item[i - 1] + K[i - 1][w - item[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    vector<int> selectedItems;
    int w = W, maxWeight = K[item.size()][W];

    for (int i = item.size(); i > 0 && maxWeight > 0; i--) {
        if (maxWeight != K[i - 1][w]) {
            selectedItems.push_back(i - 1);
            maxWeight -= item[i - 1];
            w -= item[i - 1];
        }
    }

    reverse(selectedItems.begin(), selectedItems.end());

    cout << K[item.size()][W] << endl;
    for(auto i:selectedItems) cout << i+1 << " ";
}

int main(){
    int n, W;
    cout << "Nhap so luong mon hang: ";cin>>n;
    vector<int> item(n);
    cout << "Khoi luong tung mon hang: ";
    for(int i=0; i<n; i++) cin >> item[i];
    cout << "W: ";cin>>W;

    SIPB(item, W);
    
    return 0;
}