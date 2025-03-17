#include <bits/stdc++.h>

using namespace std;

#define mnMax = 2e5;
typedef long long ll;//using ll = long long

class Graph {
private:
    int V; // Số đỉnh
    vector<vector<int>> adj; // Danh sách kề

    void DFSUtil(int v, vector<bool>& visited, int g) {
        stack<int> node;
        node.push(v);
        list<int> result;
        bool flag = false;
        while (!node.empty())
        {
            /* code */
            int top = node.top();
            node.pop();
            if (!visited[top]) {
                result.push_back(top);
                visited[top] = true;
            }
            if(top == g){
                for(auto it:result) cout << it << " ";
                cout << "\nGoal";
                flag = false;
                return;
            }
            for(int it : adj[top]){
                if(!visited[it]){
                   node.push(it); 
                }
            }
        }
        if(!flag){
            cout << "No path from " << v << " to " << g;
            return;
        }
        
    }

    void BFSUtil(int v, vector<bool>& visited, int g){
        queue<int> node;
        node.push(v);
        list<int> result;
        bool flag = false;
        while (!node.empty())
        {
            /* code */
            int top = node.front();
            node.pop();
            if(!visited[top]){
                visited[top] = true;
                result.push_back(top);
            }
            if(top == g){
                for(auto it:result) cout << it << " ";
                flag = true;
                cout << "\nGoal";
                return;
            }
            for(auto it:adj[top]){
                if(!visited[it]){
                    node.push(it);
                }
            }
        }
        if(!flag){
            cout << "No path from " << v << " to " << g;
            return;
        }
        
    }
public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w); // Thêm cạnh từ v đến w
    }

    void DFS(int start, int g) {
        
        vector<bool> visited(V, false);
        DFSUtil(start, visited, g);
    }

    void BFS(int start, int goal) {
        
        vector<bool> visited(V, false);
        BFSUtil(start, visited, goal);
    }
};

int main() {
    Graph g(10);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2,7);
    g.addEdge(2, 9);
    g.addEdge(3, 6);
    g.addEdge(3, 5);
    g.addEdge(4, 3);
    g.addEdge(4, 6);
    g.addEdge(5, 7);
    g.addEdge(5, 8);
    g.addEdge(6, 8);
    g.addEdge(9, 7);
    cout << "DFS from 0:\n";
    g.DFS(4, 10);

    return 0;
}