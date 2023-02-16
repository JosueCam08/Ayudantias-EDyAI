#include <iostream>

using namespace std;

int N, M;

void printVector(int *id){
    for(int i = 0; i < N; i++)
        std::cout << id[i] << " ";
    std::cout << '\n' << '\n';
}

int main(){

    // Input numero de nodos y numero de parejas
    cin >> N >> M;
    
    // Declaracion de variables
    int p, q, id[N], cont = 0;

    // Inicializacion de vector de representantes
    for(int i = 0; i < N; i++)
        id[i] = i;

    printVector(id);

    for(int i = 0; i < M; i++){

        cin >> p >> q;

        // Quick find
        int t = id[p];

        // Comprueba si es una nueva coneccion
        if(t == id[q]){
            std::cout << "No new connection with (" << p << "," << q << ")\n\n";
            continue;
        }

        // Slow union
        for(int j = 0; j < N; j++)
            if(id[j] == t)
                id[j] = id[q];

        std::cout << "Pair (" << p << "," << q << ") gives a new connection\n";
        printVector(id);
    }

    return 0;
}