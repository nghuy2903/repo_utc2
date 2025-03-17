#include <bits/stdc++.h>

using namespace std;

void out(int arr[], int n){
    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
           out(arr, n);
           cout << endl;
        }
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int current = arr[i];
        int j = i - 1;

        // Di chuyển các phần tử lớn hơn current về phía sau
        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Đặt current vào vị trí thích hợp trong phần đã sắp xếp
        arr[j + 1] = current;
        out(arr, n);
        cout << endl;
    }
}
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        // Tìm phần tử nhỏ nhất trong phần chưa sắp xếp
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Hoán đổi phần tử nhỏ nhất với phần tử đầu tiên chưa sắp xếp
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
        out(arr, n);
        cout << endl;
    }
}




int main(){
    int n = 10;
    int a[] = {6, 3 , 5 , 1 , 0, 7, 1, 0, 3, 0};
    // bubbleSort(a, n);
    // insertionSort(a, n);
    selectionSort(a, n);
    
    return 0;
}