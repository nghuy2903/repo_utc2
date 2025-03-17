#include <bits/stdc++.h>

using namespace std;

class Item{
    private: 
        int n; // Số items
        vector<float> weight;
        vector<float> value;
    public:
        void testcase(){
            cout << "N items: ";cin>>n;
            weight.resize(n);
            value.resize(n);
            for(int i=0; i<n; i++){
                cin >> weight[i];
                cin >> value[i];
            }
        }

        int solutionKnapsack(float W){
            sort(weight.begin(), weight.end());
            float sum = weight[0];
            int result = 0, i = 1;
            while(sum<W && i<n){
                sum+=weight[i++];
                ++result;
            }
            return result;
            // for(auto i:weight) cout << i << " ";
        }
};

int main(){
    Item it;
    it.testcase();
    float W; cin>>W;
    cout << it.solutionKnapsack(W);

    return 0;
}