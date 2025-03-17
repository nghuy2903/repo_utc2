#include <bits/stdc++.h>

using namespace std;
class Graph {
private:
    int V; // Số đỉnh
    vector<vector<char>> adj; // Danh sách kề
    
    void DFSUtil(char v, vector<bool>& visited) {
        stack<char> node;
        node.push(v);
        while (!node.empty())
        {
            /* code */
            char top = node.top();
            if (!visited[top]) {
                cout << top << " ";
                visited[top] = true;
            }
            for(char it : adj[top]){
                if(!visited[it]){
                   node.push(it); 
                }
            }
            
            node.pop();

        }
        
    }

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(char v, char w) {
        adj[v].push_back(w); // Thêm cạnh từ v đến w
    }

    void DFS(char start) {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
    }
};

int main() {
    

    return 0;
}