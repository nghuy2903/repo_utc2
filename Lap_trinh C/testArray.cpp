#include <bits/stdc++.h>
//Nguyễn Nguyên Huy - 6351071030

using namespace std;

int knapsackProblem(int W, vector<int> weight, vector<int> val, int n){

    int dp[n+1][W+1];
    memset(dp, 0, sizeof(dp));

    for(int i=1; i<=n; i++){
        for(int j =1; j<=W; j++){
            if(weight[i-1] <= j){
                dp[i][j] = max(val[i-1] + dp[i-1][j-weight[i-1]], dp[i-1][j]);
            }
            else 
                dp[i][j] = dp[i-1][j];
        }
    }


    return dp[n][W];
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    vector<pair<float,pair<int,int>>> tmp(points.size());
    for(int i=0;i<points.size();i++){
        tmp[i].first = sqrt( pow(points[i][1], 2) + pow(points[i][0], 2));
        tmp[i].second.first = points[i][0];
        tmp[i].second.second = points[i][1];
    }
    
    sort(tmp.begin(), tmp.end());
    vector<vector<int>> res(k);
    int i = 0;
    for(auto x:tmp){
        if(i>=k) break;
        res[i].reserve(2);
        res[i][0] = x.second.first;
        res[i][1] = x.second.second;
        i++;
    }

    for(int i=0; i<res.size();i++){
        cout << res[i][0] << res[i][1] << endl;
    }    
    return res;
}


int main(){

    vector<vector<int>> points = {{1,3},{-2,2}};

    kClosest(points, 1);

    return 0;
}