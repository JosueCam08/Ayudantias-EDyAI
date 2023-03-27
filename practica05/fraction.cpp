#include <iostream>

using namespace std;

template <typename T>
class Fraction{
    private:
        T num;
        T den;
    public:
        Fraction(T a, T b){
            num = a;
            den = b;
        }

        Fraction(){
            num = 0;
            den = 1;
        }

        Fraction operator+(Fraction const &B){
            T a, b;
            a = num * B.den + den * B.num;
            b = den * B.den;
            return Fraction(a, b);
        }

        operator float() const{
            return float(num) / float(den);
        }

        void print(){
            cout << num << "/" << den << "\n";
        }
};

int main(){

    Fraction<int> a(1.0, 2.1), b(1.0, 2.0);
    Fraction<int> c(0.0, 1.0);
    c = a + b;
    c.print();

    float v = c;
    cout << c << '\n';
    return 0;
}