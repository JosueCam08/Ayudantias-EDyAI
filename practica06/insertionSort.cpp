#include <iostream>
#include <string>

using namespace std;

// Algoritmo de ordenamiento insertion sort
void insertionSort(string *arr, int n){
    for(int i = 1; i < n; i++){
        int j = i - 1;
        string key = arr[i];

        // Mientras key es menor al indice j-esimo
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main(){

    int n;
    cin >> n;

    string arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    insertionSort(arr, n);

    for(int i = 0; i < n; i++)
        cout << arr[i] << '\n';
    
    return 0;
}