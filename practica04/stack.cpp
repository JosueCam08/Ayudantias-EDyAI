#include <iostream>

using namespace std;

// Estructura nodo que presenta elementos de lista simplemente enlazada
struct Node {
    int val;
    Node* sig = nullptr;

    Node(int val) {
        this->val = val;
    }
};

class stack {
    public:
    Node* parent = nullptr;
    Node* last_node = nullptr;
    int tam = 0;
    
    // Constructor sin parametros
    stack(){}

    // Constructor con parametros
    stack(int val){
        parent = new Node(val);
        last_node = parent;
        tam++;
    }

    // Destructor
    ~stack(){
        while(parent != nullptr){
            Node* aux = parent;
            parent = parent->sig;
            delete aux;
        }
    }

    // Agrega un elemento al stack
    void push(int val){
        Node *new_Node = new Node(val);
        new_Node->sig = parent;
        parent = new_Node;
        if(++tam == 1)
            last_node = parent;
    }

    // Retorna el top del stack
    int top(){
        if(!empty()){
            cout << parent->val << '\n';
            return parent->val;
        }
        return INT_MIN;
    }

    // Elimina el elemento en el top del stack
    void pop(){
        if(!empty()){
            Node *aux = parent;
            parent = parent->sig;
            if(--tam == 0)
                last_node = nullptr;
            delete aux;
        }
    }

    // Retorna el tamanio del stack
    int size(){
        cout << tam << '\n';
        return tam;
    }

    // Retorna el valor booleano a la pregunta si el stack esta vacio
    bool empty(){
        return !(tam);
    }

    // Retorna el ultimo elemento de la pila
    int last(){
        if(!empty())
            return last_node->val;
        return INT_MIN;
    }  
    
};

int main(){

    stack pila;

    pila.size();
    cout << pila.empty() << '\n';
    return 0;
}