#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int hashFunction(string s, int M){
    int h = 0, a = 127;
    for(int i = 0; i < s.length(); i++){
        h = (a * h + s[i]) % M;
    }
    return h;
}

int main(){

    int n;
    cin >> n;

    int M = 97;
    vector<int> rep(M);
    vector< vector<string> > colisiones(M);

    while(n--){
        string s;
        cin >> s;
        int h = hashFunction(s, M);
        rep[h]++;
        colisiones[h].push_back(s);
    }

    for(int i = 0; i < M; i++){
        if(rep[i] > 0){
            cout << "Repeticiones de key = " << i << ": " << rep[i] << '\n';
            sort(colisiones[i].begin(), colisiones[i].end());
            cout << "Palabras con la asignacion key: " << colisiones[i][0] << " ";
            for(int j = 1; j < colisiones[i].size(); i++){
                if(colisiones[i][j - 1] == colisiones[i][j])
                    continue;
                cout << colisiones[i][j] << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}