#include <bits/stdc++.h>

using namespace std;

bool check(char x) {
  if (x == '+' or x == '-' or x == '*' or x == '/' or x == '(' or x == ')' or x == '^') return true;
  return false;
}

int prior(char x) { // Hàm kiểm tra mức độ ưu tiên toan tử
  if (x == '+' or x == '-') return 1;
  else if (x == '*' or x == '/') return 2; 
  else if (x == '^') return 3;
  else return 4;
}

void save_Delete(char i, stack<char>& s, vector<char>& z) { // Hàm thêm dấu ngoặc ( và lấy các phần tử trong stack nếu gặp dấu ngoặc )
  if (i == '(') s.push(i);
  else {
    while (s.top() != '(') {
      z.push_back(s.top());
      s.pop();
    }
    s.pop(); // Sau khi lấy hết các phần tử thì xóa dấu ) 
  }
}

int main() {
  string s;
  stack<char> repo;
  vector<char> res;
  cin >> s;

  for (char i : s) {
    if (check(i)) { // Nếu là toán tử
      if (repo.empty()) repo.push(i); // Nếu stack trống thì thêm vào luôn
      else if (i == '(' or i == ')') save_Delete(i, repo, res);  //Trường hợp gặp dấu '('  ')'   
      else {
        while (!repo.empty() and prior(repo.top()) >= prior(i) and repo.top() != '(') {
          res.push_back(repo.top());
          repo.pop();
        }
        repo.push(i);
      }
    }
    else res.push_back(i); 
  }

  while (repo.size() != 0) { // lấy các phần tử còn lại nếu stack vẫn còn phần tử
    res.push_back(repo.top());
    repo.pop();
  }

  for (int i = 0; i < res.size(); i++) {
    cout << res[i];
  }
  cout << endl;

  return 0;
}
