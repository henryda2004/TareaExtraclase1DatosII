#include <iostream>

class Node{
public:
    int valor;
    Node *next;
    Node (int valor){
        this->valor = valor;
        this->next = NULL;
    }
    void asignar_valor(int nuevo_valor){
        valor = nuevo_valor;
        std::cout<<"Valor modificado correctamente" << std::endl;
    }
    void obtener_valor(){
        std::cout<<"EL valor almacenado es: " << valor <<std::endl;
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
    void asignar_valor_cabeza(int nuevo_valor){
        inicio->valor = nuevo_valor;
        std::cout<<"Valor de cabeza modificado correctamente" << std::endl;
    }
    void obtener_valor_cabeza(){
        std::cout<<"EL valor almacenado al inicio es: " << inicio->valor <<std::endl;
    }

};

int main() {

    List *list  = new List();
    list->insertar_nuevo(8);
    list->insertar_nuevo(9);
    list->obtener_valor_cabeza();
    list->asignar_valor_cabeza(10);
    list->obtener_valor_cabeza();


    return 0;
}
