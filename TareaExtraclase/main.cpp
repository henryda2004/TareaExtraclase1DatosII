#include <iostream>

class Node{
public:
    int valor;
    Node *next;
    Node (int valor){
        this->valor = valor;
        this->next = NULL;
    }

};

class List{
private:
    void insertar_inicio(Node *&cabeza, int valor){
        Node *nuevo_nodo = new Node(valor);

        Node *aux = cabeza;

        cabeza = nuevo_nodo;
        nuevo_nodo->next = aux;
    }
public:
    Node *inicio;

    void insertar_nuevo(int valor){
        if (this->inicio = NULL){
            this->inicio = new Node(valor);
        } else{
            this->insertar_inicio(inicio, valor);
        }
    }

};

int main() {

    List *list  = new List();
    list->insertar_nuevo(8);
    list->insertar_nuevo(9);

    return 0;
}
