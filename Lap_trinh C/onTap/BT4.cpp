#include <iostream>
#include <vector>

using namespace std;

void findSubsetsWithSum(vector<int>& A, int S, vector<int>& currentSubset, int currentIndex, int currentSum) {
    // Kết thúc nếu đã xem xét tất cả phần tử trong mảng
    if (currentIndex == A.size()) {
        // Kiểm tra nếu tổng của tập con hiện tại bằng S
        if (currentSum == S) {
            // In ra tập con hiện tại
            cout << "Subset: ";
            for (int num : currentSubset) {
                cout << num << " ";
            }
            cout << endl;
        }
        return;
    }

    // Xem xét việc thêm phần tử hiện tại vào tập con
    currentSubset.push_back(A[currentIndex]);
    currentSum += A[currentIndex];

    // Gọi đệ quy cho các trường hợp có và không thêm phần tử hiện tại vào tập con
    findSubsetsWithSum(A, S, currentSubset, currentIndex + 1, currentSum);

    // Sau khi xem xét, loại bỏ phần tử hiện tại để thử các trường hợp khác
    currentSubset.pop_back();
    currentSum -= A[currentIndex];

    findSubsetsWithSum(A, S, currentSubset, currentIndex + 1, currentSum);
}

int main() {
    int n, S;
    cout << "Nhập số phần tử của mảng: ";
    cin >> n;

    vector<int> A(n);

    cout << "Nhập các phần tử của mảng: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout << "Nhập tổng S: ";
    cin >> S;

    vector<int> currentSubset;
    findSubsetsWithSum(A, S, currentSubset, 0, 0);

    return 0;
}
