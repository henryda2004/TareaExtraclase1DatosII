#include <iostream>

class NodeC{
public:

    NodeC(void);
    void* valor;
    NodeC *next;
    NodeC (void* valor){
        this->valor = valor;
        this->next = NULL;
    }
    void* obtener_valor(){
        std::cout<<"EL valor almacenado es: " << valor <<std::endl;
        return valor;
    }
};

class Collector{

private:
    void insertar_collector_private(NodeC *&cabeza, void* valor){
        NodeC *nuevo_nodo = new NodeC(valor);

        NodeC *aux = cabeza;

        cabeza = nuevo_nodo;
        cabeza->next = aux;
        std::cout<<"Nuevo puntero ingresado a collector con el valor de: " << valor <<std::endl;
    }
    void eliminar_nodo_collector(NodeC *&cabeza){
        if(cabeza != NULL){
            NodeC *aux_eliminar;

            aux_eliminar = cabeza;


            cabeza = cabeza->next;
            delete(aux_eliminar);
            std::cout<<"Primer nodo de Collector eliminado correctamente" << std::endl;

        }
    }
    void mostrar_collector_private(NodeC *cabeza){
        NodeC *actual;
        actual = cabeza;
        std::cout<<"Collector actual es: " << std::endl;
        while(actual != NULL){
            std::cout<<actual->valor<<"->";
            actual = actual->next;
        }
    }
public:
    NodeC *inicio = NULL;
    void insertar_collector(void *valor){
        std::cout<<"El puntero que se va a insertar a collector es " << valor <<std::endl;
        insertar_collector_private(inicio, valor);
    }
    bool validar_existencia(){
        if (inicio != NULL){
            std::cout<<"Collector con nodo(s) restantes" << std::endl;
            return true;
        } else{
            std::cout<<"Collector vacio" << std::endl;
            return false;
        }
    }
    void* obtener_valor (){
        void* x = inicio->obtener_valor();
        eliminar_nodo_collector(inicio);
        std::cout<<"El valor obtenido de collector es: " << x <<std::endl;

        return x;
    }
    void mostrar_collector(){
        mostrar_collector_private(inicio);
    }
};

Collector *collector = new Collector;
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
    int obtener_valor(){
        std::cout<<"EL valor almacenado es: " << valor <<std::endl;
        return valor;
    }

    void * operator new(size_t size)
    {
        if (collector->validar_existencia() == false) {
            void * p = ::operator new(size);
            std::cout<<"Nuevo espacio de memoria utilizado porque colector estaba vacio" << std::endl;
            std::cout<<"El puntero nuevo creado es: " << p <<std::endl;
            return p;
        }
        else {
            void * p = reinterpret_cast<void *>(collector->obtener_valor());
            std::cout<<"El puntero obtenido de collector es " << p <<std::endl;
            return p;
        }
    }
    void operator delete(void * p)
    {
        std::cout<< "Overloading delete operator " << std::endl;
        std::cout<<"El puntero que se va a eliminar es" << p <<std::endl;
        collector->insertar_collector(p);
        free(p);
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
    void eliminar_nodo_referencia(Node *&cabeza){
        if(cabeza != NULL){
            Node *aux_eliminar;


            aux_eliminar = cabeza;

            cabeza = cabeza->next;
            std::cout<<"Valor a eliminar encontrado" << std::endl;
            delete(aux_eliminar);


        }
    }
    void mostrar_lista_private(Node *cabeza){
        Node *actual = new Node();
        actual = cabeza;
        std::cout<<"List actual es: " << std::endl;
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

    void eliminar_nodo(){
        eliminar_nodo_referencia(inicio);
    }
    void mostrar_lista(){
        mostrar_lista_private(inicio);
    }

};


int main() {
    List *l = new List;
    l->insertar_nuevo(4);
    l->insertar_nuevo(5);
    l->insertar_nuevo(6);
    l->mostrar_lista();
    l->asignar_valor_cabeza(7);
    l->obtener_valor_cabeza();
    l->mostrar_lista();
    l->eliminar_nodo();
    l->eliminar_nodo();
    collector->mostrar_collector();
    l->insertar_nuevo(8);
    collector->mostrar_collector();

    return 0;
}
