#include <iostream>

int main() {

    int size = 10;
    int arr[size] = {20, 77, 1, 4, 5, 9, 4, 6, 545, 666};

    int temp = 0;
    bool exit = false;

    while(!exit){
        exit = true;
        for (int i = 0; i < size; i++){
            if (arr[i] > arr[i+1]){
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                exit = false;
            }
        }
    }

    for (int i = 0; i < size; i++){
       std::cout << arr[i] << "  ";
    }

    return 0;
}