#include <bits/stdc++.h>

using namespace std;

bool check(char x){
   if(x == '+' or x == '-' or x == '*' or x == '/') return true;
    return false;
}

int phepToan(char x){
      if(x == '+') return 1;
       else if(x == '-') return 2;
        else if(x == '*') return 3;
         else return 4;
   
}

int main(){
    stack<int> res;
    string s;
    cin >> s;

    string temp = "";

    for (int j = s.length() - 1; j >= 0; j--) {
        temp += s[j];
    }
    // Đảo chuỗi
    
    for(char i:temp){
       if(check(i) == true){ // Nếu là toán tử thì thực hiện phép tính
          int pri = phepToan(i);
          if(pri == 1){
            int temp1 = res.top();
            res.pop();
            int temp2 = res.top();
            res.pop();
            int result1 = temp1 + temp2;
            res.push(result1);
         }
        else if(pri == 2){
            int temp3 = res.top();
            res.pop();
            int temp4 = res.top();
            res.pop();
            int result2 = temp3 - temp4;
            res.push(result2);
         }
        else if(pri == 3){
            int temp5 = res.top();
            res.pop();
            int temp6 = res.top();
            res.pop();
            int result3 = temp5 * temp6;
            res.push(result3);
         }
        else{
            int temp7 = res.top();
            res.pop();
            int temp8 = res.top();
            res.pop();
            int result4 = temp7 / temp8;
            res.push(result4);
         }

        }
       else{ // Nếu là toán hạng thì đẩy vào stack
        int x = stoi(string(1,i));
        res.push(x);
       }

    }

    cout << res.top();
    
    return 0;
}