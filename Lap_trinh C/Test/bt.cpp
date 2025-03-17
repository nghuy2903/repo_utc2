/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
struct
###End banned keyword*/

//###INSERT CODE HERE -

#include <iostream>

void removeDuplicates(int arr[], int& size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < size - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                size--;
                j--;
            }
        }
    }
}

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;
    int* arr = new int[size];

    std::cout << "Enter elements of the array: ";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    // Remove duplicates
    removeDuplicates(arr, size);

    // Display the modified array
    std::cout << "Array after removing duplicates: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Deallocate memory
    delete[] arr;

    return 0;
}
