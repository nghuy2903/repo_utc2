#include <bits/stdc++.h>
using namespace std;

#define  V 4// Số đỉnh của đồ thị

// Hàm kiểm tra xem một đỉnh có thể được thêm vào chu trình Hamilton hay không
bool isSafe(int v, vector<vector<int>>& graph, vector<int>& path, int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; ++i)
        if (path[i] == v)
            return false;

    return true;
}

// Hàm tìm đường đi ngắn nhất sử dụng chu trình Hamilton
int shortestHamiltonianPathUtil(vector<vector<int>>& graph, vector<int>& path, int pos, int cost) {
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] != 0) // Kiểm tra xem có cạnh nối giữa đỉnh cuối cùng và đỉnh đầu tiên không
            return cost + graph[path[pos - 1]][path[0]];
        else
            return INT_MAX; // Trả về một giá trị lớn nếu không tạo thành chu trình
    }

    int minCost = INT_MAX;

    for (int v = 1; v < V; ++v) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            // Tìm đường đi ngắn nhất từ đỉnh tiếp theo
            int currentCost = shortestHamiltonianPathUtil(graph, path, pos + 1, cost + graph[path[pos - 1]][v]);

            // Cập nhật giá trị nhỏ nhất
            minCost = min(minCost, currentCost);
            path[pos] = -1;
        }
    }

    return minCost;
}

// Hàm tìm đường đi ngắn nhất sử dụng chu trình Hamilton
int shortestHamiltonianPath(vector<vector<int>>& graph) {
    vector<int> path(V, -1);
    path[0] = 0; // Chọn đỉnh 0 làm đỉnh xuất phát

    return shortestHamiltonianPathUtil(graph, path, 1, 0);
}

int main() {
    vector<vector<int>> graph = {
        {0, 2, 8, 5},
        {2, 0, 3, 4},
        {8, 3, 0, 7},
        {5, 4, 7, 0}
    };

    int minCost = shortestHamiltonianPath(graph);

    if (minCost != INT_MAX)
        cout << "Do dai duong di ngan nhat su dung chu trinh Hamilton: " << minCost << endl;
    else
        cout << "Khong tim thay chu trinh Hamilton" << endl;

    return 0;
}
