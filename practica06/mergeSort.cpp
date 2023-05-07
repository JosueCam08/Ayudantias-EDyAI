#include <iostream>
#include <string>
#include <vector>

using namespace std;

void merge(string *arr, int left, int mid, int right){
    // Definimos tamanio de los vectores auxiliares
    int tamA = mid - left + 1;
    int tamB = right - mid;

    // Definimos vectores auxiliares
    vector<string> A(tamA), B(tamB);

    // Llenamos los vectores auxiliares
    for(int i = 0; i < tamA; i++)
        A[i] = arr[left + i];
    for(int j = 0; j < tamB; j++)
        B[j] = arr[mid + j + 1];

    int itA = 0, itB = 0, it = left;

    // Ordenamos el arreglo original
    while(itA < tamA && itB < tamB){
        if(A[itA] <= B[itB])
            arr[it] = A[itA++];
        else
            arr[it] = B[itB++];
        it++;
    }

    while(itA < tamA){
        arr[it] = A[itA++];
        it++;
    }

    while(itB < tamB){
        arr[it] = B[itB++];
        it++;
    }
}

void mergeSort(string *arr, int ini, int fin){
    if(ini >= fin)
        return;

    int mid = ini + (fin - ini) / 2;
    mergeSort(arr, ini, mid);
    mergeSort(arr, mid + 1, fin);
    merge(arr, ini, mid, fin);
}

int main(){

    int n;
    cin >> n;

    string arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    mergeSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++)
        cout << arr[i] << '\n';

    return 0;
}