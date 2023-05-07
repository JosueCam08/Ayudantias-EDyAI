#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

string randomWord(){
    int len = (rand() % 10) + 1;
    string s = "";

    int c = 0;
    for(int i = 0; i < len; i++){
        c = (rand() % 26) + 97;
        s += c; 
    }
    //cout << "s = " << s << '\n';
    return s;
}

int main(){
    srand(time(0));

    int n;
    cin >> n;

    vector<string> arr(n);

    cout << n << '\n';
    for(int i = 0; i < n; i++){
        arr[i] = randomWord();
        cout << arr[i] << '\n';
    }

    return 0;
}