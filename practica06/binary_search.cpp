#include <iostream>
#include <string>
#include <vector>

using namespace std;

int binarySearch(string *arr, int ini, int fin, string busca){
    if(ini == fin)
        return ini;
    int mid = (ini + fin) / 2;
    if(arr[mid] < busca)
        return binarySearch(arr, mid + 1, fin, busca);
    return binarySearch(arr, ini, mid, busca);
}

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

    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        string s;
        cin >> s;
        int index = binarySearch(arr, 0, n - 1, s);

        if(arr[index] == s)
            cout << index << '\n';
        else
            cout << "NOT FOUND :(\n";
    }

    return 0;
}