#include <bits/stdc++.h>

using namespace std;

bool check(char x){
   if(x == '+' or x == '-' or x == '*' or x == '/') return true;
    return false;
}

int phepToan(char x){
   if(check(x)){
      if(x == '+') return 1;
       else if(x == '-') return 2;
        else if(x == '*') return 3;
         else return 4;
   }
}

int main(){
   string s;
   vector<int> res;
   cin >> s;

   for (char i : s)
   {
     if(check(i) == false) {
      int j = stoi(string(1,i));
      res.insert(res.begin(), j);
      }
      else {
         int x = phepToan(i);
         if(x == 1) {
           int y = res[1] + res[0];
           res.erase(res.begin());
           res.erase(res.begin());
           res.insert(res.begin(), y);
         }
         else if(x == 2){
            int z = res[1] - res[0];
           res.erase(res.begin());
           res.erase(res.begin());
           res.insert(res.begin(), z);
         }
         else if(x == 3){
            int t = res[1] * res[0];
           res.erase(res.begin());
           res.erase(res.begin());
           res.insert(res.begin(), t);
         }
         else{
            int q = res[1] / res[0];
           res.erase(res.begin());
           res.erase(res.begin());
           res.insert(res.begin(), q);
         }

      }

   }
   cout << res[0];
   
   return 0;

}