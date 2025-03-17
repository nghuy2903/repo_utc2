#include <bits/stdc++.h>

using namespace std;

class Stack{
    private:
      static const int MAX_SIZE = 100;
      int n;
      int a[MAX_SIZE];
    public:
      Stack();
      int size();
      void show();
      void push(int value);
      void pop();
      void top();
      bool isEmpty();
};

Stack::Stack(){
    n = 0;
}

void Stack::push(int value){
    if(n < MAX_SIZE ){
      a[n++] = value;
    }
    else {
        cout << "Stack full!\n";
    }
}

int Stack::size(){
    return n;
}

void Stack::pop(){
    n--;
}

void Stack::top(){
    if(isEmpty()) {
        cout << "Stack is emty!\n";\
        return;
    }
    cout << a[n-1] << endl;
}

bool Stack::isEmpty(){
    return n < 100 ? true : false;
}

void Stack::show(){
    for(int i=n-1; i>=0; i--){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){ 
    Stack myStack;

    if(myStack.isEmpty()) cout << "Stack is empty!\n";
     else cout << "Stack is not empty!\n";

    myStack.push(5);
    myStack.push(10);
    myStack.push(20);
    myStack.pop();

    myStack.show();
    myStack.top();

    return 0;
}