#include <iostream>

using namespace std;
typedef long long ll;

ll Numgordo(ll n){
    ll suma=0;
    ll aux=n;
    while(aux>0){
        suma+=(aux%10);
        aux/=10;
    }
    return n-suma;
}


ll busqueda (ll a,ll c){
    ll fin=a;
    ll ini=10;
    ll med=(ini+fin)/2;
    while(ini!=fin){
        if(Numgordo(med)<c){
            ini=med+1;
        }else{
            fin=med;
        }
        med=(ini+fin)/2;
    }
    return ini-1;
}

int main()
{
    ll a,c;
    cin >> a >> c;
    if(a<=9){
        cout<<0;
    }
    else{
    cout<<(a-busqueda(a+1,c));
    }
    return 0;
}