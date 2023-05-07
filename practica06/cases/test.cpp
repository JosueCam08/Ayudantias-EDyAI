#include <iostream>
#include <string>

using namespace std;

void f(string s){
    s[0] = 'b';
    return;
}

void g(char *c){
    s[0] = 'b';
    return;
}

int main(){

    string s = "aba";
    f(s);
    cout << s << '\n';
    g(s[0]);
    cout << s << '\n';
    return 0;
}