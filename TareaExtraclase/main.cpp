#include <iostream>

class Node{
public:
    Node() {

    }

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
        cabeza->next = aux;

    }
    void eliminar_nodo_referencia(Node *&cabeza, int valor){
        if(cabeza != NULL){
            Node *aux_eliminar;
            Node *anterior = NULL;

            aux_eliminar = cabeza;

            std::cout<<aux_eliminar->next->valor<<"es el valor de x en este momento ";

            while ((aux_eliminar != NULL) && (aux_eliminar->valor != valor)){
                anterior = aux_eliminar;
                aux_eliminar = aux_eliminar->next;
            }

            if(aux_eliminar = NULL){
                std::cout<<"Valor a eliminar no encontrado"<< std::endl;
            }
            else if(anterior == NULL){
                cabeza = cabeza->next;
                delete aux_eliminar;
                std::cout<<"Valor a eliminar encontrado" << std::endl;

            }
            else{
                std::cout<<"Valor a eliminar encontrado" << std::endl;
                anterior->next = aux_eliminar->next;
                delete aux_eliminar;
            }
        }
    }
    void mostrar_lista_private(Node *cabeza){
        Node *actual = new Node();
        actual = cabeza;

        while(actual != NULL){
            std::cout<<actual->valor<<"->";
            actual = actual->next;
        }
    }
public:
    Node *inicio = NULL;
    void insertar_nuevo(int valor){

        insertar_inicio(inicio, valor);
    }
    void asignar_valor_cabeza(int nuevo_valor){
        inicio->valor = nuevo_valor;
        std::cout<<"Valor de cabeza modificado correctamente" << std::endl;
    }
    void obtener_valor_cabeza(){
        std::cout<<"EL valor almacenado al inicio es: " << inicio->valor <<std::endl;
    }

    void eliminar_nodo(int valor){
        eliminar_nodo_referencia(inicio,valor);
    }
    void mostrar_lista(){
        mostrar_lista_private(inicio);
    }

};

class Collector{
private:
public:
};

int main() {

    List *list  = new List();
    list->insertar_nuevo(8);
    list->insertar_nuevo(9);
    list->insertar_nuevo(7);
    list->insertar_nuevo(10);
    list->mostrar_lista();
    list->asignar_valor_cabeza(11);
    list->mostrar_lista();
    list->eliminar_nodo(7);
    list->mostrar_lista();


    return 0;
}
