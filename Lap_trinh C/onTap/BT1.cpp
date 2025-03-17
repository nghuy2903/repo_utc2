#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    int dinh1, dinh2, trongso;
    Node* next;
    
    Node(int x = 0, int y = 0, int z = 0){
        dinh1 = x;
        dinh2 = y;
        trongso = z;
        next = nullptr;
    }
};

class DOTHI{
    Node* head;
    public:
        DOTHI(){head = nullptr;}
        void Nhap();
        void Xuat();
        void them(int u, int v, int x);



};

void DOTHI::Nhap(){
    int n; cin>>n;
    for(int i=0; i<n; i++){
        int u, v, x;
        cin >> u >> v >> x;
        them(u,v,x);
    }
}

void DOTHI::them(int u, int v, int x){
    Node* moi = new Node(u,v,x);
    if(head == nullptr) head = moi;
    else {
        Node* tam = head;
        while(tam->next!= nullptr){
            tam = tam->next;
        }
        
        tam->next = moi;
    }
}

void DOTHI::Xuat(){
    Node* tam = head;
    while(tam!=nullptr){
        cout << tam->dinh1 << "->" << tam->dinh2 << " : " << tam->trongso << endl;
        tam = tam->next;
    }
}

int main(){

    DOTHI ds;
    ds.Nhap();
    ds.Xuat();

    return 0;
}