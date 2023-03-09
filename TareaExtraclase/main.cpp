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
    int obtener_valor(){
        std::cout<<"EL valor almacenado es: " << valor <<std::endl;
        return valor;
    }
    void * operator new(size_t size)
    {
        std::cout<< "Overloading new operator with size: " << size << std::endl;
        void * p = ::operator new(size);
        //void * p = malloc(size); will also work fine

        return p;
    }
    void operator delete(void * p)
    {
        std::cout<< "Overloading delete operator " << std::endl;
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
                delete(aux_eliminar);
                std::cout<<"Valor a eliminar encontrado" << std::endl;

            }
            else{
                std::cout<<"Valor a eliminar encontrado" << std::endl;
                anterior->next = aux_eliminar->next;
                delete(aux_eliminar);
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
    void insertar_collector_private(Node *&cabeza, int valor){
        Node *nuevo_nodo = new Node(valor);

        Node *aux = cabeza;

        cabeza = nuevo_nodo;
        cabeza->next = aux;
    }
    void eliminar_nodo_collector(Node *&cabeza){
        if(cabeza != NULL){
            Node *aux_eliminar;

            aux_eliminar = cabeza;


            cabeza = cabeza->next;
            delete(aux_eliminar);
            std::cout<<"Primer nodo de Collector eliminado correctamente" << std::endl;

        }
    }
public:
    Node *inicio = NULL;
    void insertar_collector(int valor){

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
    int obtener_valor (){
        int x = inicio->obtener_valor();
        eliminar_nodo_collector(inicio);
        std::cout<<"El valor obtenido de collector es: " << x <<std::endl;

        return x;
    }
};

int main() {

    Node *ptr = new Node(4);
    Collector *collector = new Collector();
    collector->insertar_collector(3);
    collector->insertar_collector(32);
    collector->validar_existencia();
    collector->obtener_valor();
    collector->validar_existencia();
    ptr->obtener_valor();
    delete ptr;


    return 0;
}
