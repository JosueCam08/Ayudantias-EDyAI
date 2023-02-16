#include <iostream>

using namespace std;

int N, M;

void printVector(int *id){
    for(int i = 0; i < N; i++)
        cout << id[i] << " ";
    cout << '\n' << '\n';
}

int main(){

    // Input numero de nodos y parejas
    cin >> N >> M;

    // Declaracion de variables
    int p, q, id[N];

    for(int i = 0; i < N; i++)
        id[i] = i;

    printVector(id);

    for(int k = 0; k < M; k++){
        
        cin >> p >> q;
        // Slow find
        int i, j;
        for(i = p; i != id[i]; i = id[i]);
        for(j = q; j != id[j]; j = id[j]);

        if(i == j){
            cout << "No new connection with (" << p << "," << q << ")\n\n";
            continue;
        }

        // Quick union
        id[i] = j;

        cout << "Pair (" << p << "," << q << ") gives a new connection\n";
        printVector(id);

    }
    return 0;
}