#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Hàm kiểm tra xem một ký tự có phải là toán tử hay không
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Hàm ưu tiên của các toán tử
int getPriority(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

// Hàm chuyển biểu thức trung tố sang hậu tố
string infixToPostfix(string infix) {
    stack<char> operatorStack;
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) {
            // Nếu là toán hạng, thêm vào biểu thức hậu tố
            postfix += c;
        } else if (c == '(') {
            // Nếu là dấu mở ngoặc, đẩy vào ngăn xếp
            operatorStack.push(c);
        } else if (c == ')') {
            // Nếu là dấu đóng ngoặc, lấy toàn bộ toán tử từ ngăn xếp và thêm vào biểu thức hậu tố
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            // Loại bỏ dấu '(' khỏi ngăn xếp
            if (!operatorStack.empty()) {
                operatorStack.pop();
            }
        } else if (isOperator(c)) {
            // Nếu là toán tử, kiểm tra ưu tiên và thêm vào biểu thức hậu tố
            while (!operatorStack.empty() && operatorStack.top() != '(' && getPriority(operatorStack.top()) >= getPriority(c)) {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }

    // Lấy toàn bộ toán tử còn lại trong ngăn xếp và thêm vào biểu thức hậu tố
    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

int main() {
    string infixExpression;
    cin >> infixExpression;

    string postfixExpression = infixToPostfix(infixExpression);
    cout << postfixExpression << endl;

    return 0;
}
