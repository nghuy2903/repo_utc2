#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Định nghĩa cấu trúc cho mỗi đỉnh trong danh sách liên kết
struct Vertex {
    int vertexNumber;
    int weight;
    Vertex* next;

    Vertex(int v, int w) : vertexNumber(v), weight(w), next(nullptr) {}
};

class Graph {
    int numVertices;
    vector<Vertex*> adjacencyList;

public:
    Graph(int n) : numVertices(n), adjacencyList(n, nullptr) {}

    // Thêm một cạnh từ u đến v với trọng số w vào danh sách liên kết
    void addEdge(int u, int v, int w) {
        Vertex* newEdge = new Vertex(v, w);
        newEdge->next = adjacencyList[u];
        adjacencyList[u] = newEdge;
    }

    // Thuật toán Dijkstra để tìm độ dài đường đi ngắn nhất từ đỉnh nguồn tới tất cả các đỉnh
    void dijkstra(int source) {
        // Tạo mảng để lưu trữ độ dài ngắn nhất từ đỉnh nguồn tới các đỉnh khác
        vector<int> distance(numVertices, numeric_limits<int>::max());

        // Đặt độ dài của đỉnh nguồn là 0
        distance[source] = 0;

        // Duyệt qua tất cả các đỉnh
        for (int i = 0; i < numVertices - 1; ++i) {
            // Duyệt qua các đỉnh kề của đỉnh hiện tại
            for (int u = 0; u < numVertices; ++u) {
                for (Vertex* edge = adjacencyList[u]; edge != nullptr; edge = edge->next) {
                    int v = edge->vertexNumber;
                    int weightUV = edge->weight;

                    // Cập nhật độ dài ngắn nhất nếu tìm thấy đường đi ngắn hơn
                    if (distance[u] != numeric_limits<int>::max() && distance[u] + weightUV < distance[v]) {
                        distance[v] = distance[u] + weightUV;
                    }
                }
            }
        }

        // In độ dài ngắn nhất từ đỉnh nguồn tới các đỉnh khác
        cout << "Độ dài đường đi ngắn nhất từ đỉnh 0:" << endl;
        for (int i = 0; i < numVertices; ++i) {
            cout << "Đỉnh " << i << ": " << distance[i] << endl;
        }
    }
};

int main() {
    // Số đỉnh của đồ thị
    int numVertices = 5;
    
    // Khởi tạo đồ thị
    Graph G(numVertices);

    // Thêm cạnh vào đồ thị
    G.addEdge(0, 1, 1);
    G.addEdge(0, 3, 3);
    G.addEdge(0, 4, 10);
    G.addEdge(1, 2, 5);
    G.addEdge(2, 4, 1);
    G.addEdge(3, 2, 2);
    G.addEdge(3, 4, 6);

    // Áp dụng thuật toán Dijkstra từ đỉnh 0
    G.dijkstra(0);

    return 0;
}
