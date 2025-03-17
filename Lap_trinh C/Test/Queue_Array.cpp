#include <bits/stdc++.h>

using namespace std;

class Queue{
    private:
      static const int MAX_SIZE = 100;
      int n;
      int a[MAX_SIZE];
    public:
      Queue();
      int size();
      bool isEmpty();
      void enqueue(int value);
      void dequeue();
      void show();
      int front();//Trả về phần tử ở đầu mà không xóa 
      int back();//Trả về phần tử ở cuối mà không xóa
};

Queue::Queue(){
    n = 0;
}

bool Queue::isEmpty(){
    return n < MAX_SIZE ? true : false;
}

void Queue::enqueue(int value){
    if(n<MAX_SIZE) a[n++] = value;
    else cout << "Queue full!\n";
}

void Queue::dequeue(){
    for(int i=0; i<n-1; i++){
        a[i] = a[i+1];
    }
    n--;
}

int Queue::size(){
    return n;
}

int Queue::front(){
    return a[0];
}

int Queue::back(){
    return a[n-1];
}

void Queue::show(){
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){ 
    Queue myQueue;

    myQueue.enqueue(5);
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.dequeue();
   
    myQueue.show();


    return 0;
}