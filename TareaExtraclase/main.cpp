#include <iostream>
/**
 * @brief Esta clase crea un nodo del colector y lo pone en la primera posicion de la lista.
 */
class NodeC{
public:
    /**
   * @brief se crean un nodo del colector, estos nodos son punteros. Tambien es posible obtener los valores a los que apuntan estos punteros.
   *
   * @param valor es un entero, el cual se quiere guardar en el colector(lista) mediante los punteros(nodos).
   * @return se puede obtener el valor del numero ingresado mediante los punteros, y se almacenan los estos punteros en la lista de punteros.
   */

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
/**
 * @brief Esta clase crea la lista de punteros/ direcciones que han sido liberadas, que le llamaremos el colector de punteros.
 */
class Collector{

private:
    /**
  * @brief estas funciones son privadas ya que no se debe interactuar directamente con ellas.
  *
  */

    void insertar_collector_private(NodeC *&cabeza, void* valor){
        /**
  * @brief se hace un puntero auxiliar para poder insertar en la cabeza de la lista el puntero que recien se ha creado.
  *
  * @param cabeza es el primer nodo de la lista cabeza, finalmente se le asigna el valor ingresado.
  * @param valor es el entero que se ingresa, para que sea guarado en el puntero, y este puntero en la lista de punteros.
  * @return muestra en pantalla que el nodo ingresado esta en efecto en la cabeza de la lista.
  */

        NodeC *nuevo_nodo = new NodeC(valor);

        NodeC *aux = cabeza;

        cabeza = nuevo_nodo;
        cabeza->next = aux;
        std::cout<<"Nuevo puntero ingresado a collector con el valor de: " << valor <<std::endl;
    }
    void eliminar_nodo_collector(NodeC *&cabeza){
        /**
* @brief se hace un puntero auxiliar para poder borrar de la cabeza de la lista..
*
* @param cabeza es el primer nodo de la lista cabeza, este es el nodo a eliminar.
* @return muestra en pantalla que el nodo ingresado esta eliminado de la lista.
*/

        if(cabeza != NULL){
            NodeC *aux_eliminar;

            aux_eliminar = cabeza;


            cabeza = cabeza->next;
            delete(aux_eliminar);
            std::cout<<"Primer nodo de Collector eliminado correctamente" << std::endl;

        }
    }
    void mostrar_collector_private(NodeC *cabeza){
        /**
* @brief se muestra en la consola la lista de punteros almacenada en el colector.
*
* @param cabeza es el primer nodo de la lista y con este, se puede recorrer la lista y mostrar las direcciones de todos los punteros en esta. .
* @return muestra en consola las direcciones de los punteors en el colector.
*/

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

    /**
* @brief estas funciones son publicas ya que se interactua directamente con ellas.
* @param inicio funciona como un puntero inicializado en null, para ppoder hacer con este las operaciones deseadas.
*/

    void insertar_collector(void *valor){
        /**
* @brief se inserta la direccion de un nodo en la lista del colector.
*
* @param *valor el entero, del que se debe almacenar la direccion en el colector, este se inserta en la lista en la primer posicion.
* @return muestra en consola la direccion que se va a guardar en el colector.
*/

        std::cout<<"El puntero que se va a insertar a collector es " << valor <<std::endl;
        insertar_collector_private(inicio, valor);
    }
    bool validar_existencia(){
        /**
* @brief determina si hay nodos dentro del colector.
*
* @param inicio este es el primer nodo en la lista del colector, si este no tiene una direccion nula significa que hay almenos un nodo en la lista del colector.
* @return muestra en consola si el collector esta o no vacio.
*/
        if (inicio != NULL){
            std::cout<<"Collector con nodo(s) restantes" << std::endl;
            return true;
        } else{
            std::cout<<"Collector vacio" << std::endl;
            return false;
        }
    }
    void* obtener_valor (){
        /**
* @brief obtiene el valor que se elimina de la lista del colector, es decir, la dirrecion que ha sido liberada.
*
* @param inicio este es el primer nodo en la lista del colector, que en este caso en representa el espacio liberado.
* @return muestra en consola el valor que acaba de ingresar al colector.
*/
        void* x = inicio->obtener_valor();
        eliminar_nodo_collector(inicio);
        std::cout<<"El valor obtenido de collector es: " << x <<std::endl;

        return x;
    }
    void mostrar_collector(){
        /**
* @brief muestra en consola la lista de direcciones/punteros que estan en el colector.

*/
        mostrar_collector_private(inicio);
    }
};
Collector *collector = new Collector;
/**
 * @brief Esta clase crea los nodos que estan en la lista de direcciones de oupadas y realiza operaciones con ellos.
 */
class Node{

public:
    /**
* @brief estas funciones son publicas ya que se interactua directamente con ellas.
*/
    Node() {
/**
* @brief crea los nodos de la lista: numeros enteros y su direccion.
*
* @param valor este es el numeor entero.
* @param *next es un puntero al siguente dato, necesario para ejecutar las siguientes operaciones. .
*/

    }
    int valor;
    Node *next;
    Node (int valor){
        /**
* @brief asigna el valor ingresado y el puntero lo senala al siguente, como no se ha ingresado un nodo sigueinte, se declara como nulo.
*
* @param valor este es el numero entero.
* @param *next es un puntero al siguente dato.
*/

        this->valor = valor;
        this->next = NULL;
    }
    void asignar_valor(int nuevo_valor){
        /**
* @brief modifica el valor ingresado originalmente.
*
* @param valor este es el numero entero ingresado orignalmente.
* @param nuevo_valor este es el numero por le cual se desa cambiar al dato ingresado.
*
* @return muestra en consola que el numero ha sido modificado.
*/

        valor = nuevo_valor;
        std::cout<<"Valor modificado correctamente" << std::endl;
    }
    int obtener_valor(){

        /**
* @brief permite consultar el valor almacenado en el nodo.
*
* @param valor es el numero entero ingresado.
*
* @return muestra en consola el numero que esta en el nodo.
*/

        std::cout<<"EL valor almacenado es: " << valor <<std::endl;
        return valor;
    }

    void * operator new(size_t size)
    /**
* @brief es un metodo sobrecargado, que toma los espacios que de memoria almacenados en el colecto para volverlos a usar, analizando dos casos
*
* @param size especifica el numero de bytes que se necesitan para almacenar el dato.
*/

    {
        if (collector->validar_existencia() == false) {

            /**
        * @brief Analiza el caso donde el colector esta vacio, es decir no hay espacios en memoria que puedan ser reutilizados, entonces crea uno nuevo.
        *
        * @return muestra en consola que el colector estabab vacio y la dirrecion en memoria creada. .
        */
            void * p = ::operator new(size);
            std::cout<<"Nuevo espacio de memoria utilizado porque colector estaba vacio" << std::endl;
            std::cout<<"El puntero nuevo creado es: " << p <<std::endl;
            return p;
        }
        else {
            /**
        * @brief Analiza el otro caso, donde en el colector hay espacios en memoria que puedan ser reutilizados, y usa el que se encuentre en la cabeza pero lo asigna como el puntero de un nodo de lista.
        *
        * @return muestra en consola la dirrecion en memoria que ahora esta en uso.
        */
            void * p = reinterpret_cast<void *>(collector->obtener_valor());
            std::cout<<"El nodo creado con el puntero obtenido de collector tiene la direccion " << p <<std::endl;
            return p;
        }
    }
    void operator delete(void * p)
    /**
* @brief es un metodo sobrecargado, que toma un espacio de memoria almacenados en la lista de nodos y lo envia al colector, es decir lo libera que esto puedan ser usados nuevamente.
*
* @param *p es el puntero que se desea enviar al colector.
*/
    {
        std::cout<<"El puntero que se va a eliminar es" << p <<std::endl;
        collector->insertar_collector(p);
        free(p);
    }
};
/**
 * @brief Esta clase crea la lista de espacios en memoria que estan siendo usados por los nodos.
 */
class List{

private:
    /**
 * @brief Estos metoods son privados ya que no se debe interacuar directamente con ellos.
 */
    void insertar_inicio(Node *&cabeza, int valor){
        /**
     * @brief inserta con ayuda de un puntero auxiliar al primer elemento de la lista un nodo, que consiste de una direccion en memoria y de un numero entero.
     * @param cabeza es la direccion del primer elemento de la lista, puede venir de un espacio liberado que se encontraba en el colector o de uno que se haya creado en este momento..
     * @param valor es el numero entero ingresado.
     */

        Node *nuevo_nodo = new Node(valor);

        Node *aux = cabeza;

        cabeza = nuevo_nodo;
        cabeza->next = aux;

    }
    void eliminar_nodo_referencia(Node *&cabeza){
        /**
     * @brief elimina con ayuda de un puntero auxiliar al primer elemento de la lista.
     *
     * @param cabeza es la direccion del primer elemento de la lista
     *
     * @return muestra en la consola que se ha eliminado el nodo.
     */
        if(cabeza != NULL){
            Node *aux_eliminar;


            aux_eliminar = cabeza;

            cabeza = cabeza->next;
            std::cout<<"Valor eliminado" << std::endl;
            delete(aux_eliminar);


        }
    }
    void mostrar_lista_private(Node *cabeza){
        /**
* @brief muestra la lista de numeros, los cuales tienen una dirreccion en memoria asignada.
*
* @param cabeza es la direccion del primer elemento de la lista
*
* @return muestra en la consola la lista actual de nodos.
*/

        Node *actual;
        actual = cabeza;
        std::cout<<"List actual es: " << std::endl;
        while(actual != NULL){
            std::cout<<actual->valor<<"->";
            actual = actual->next;
        }
    }
public:
    /**
 * @brief Estos metodos son spublicos por que ocn estos se debe de interactuar facilmente.Se inicializa con un punteor que apunta a null para ejecutar las funciones correctamente.
 */
    Node *inicio = NULL;
    void insertar_nuevo(int valor){
        /**
* @brief usando la funcion privada, inserta al inicio el nuevo nodo, usando el punteor inicial y el valor entero deseado.
*
* @param valor es el numero entero ingresado.
* @param *inicio es el puntero inicializado en null. .

*/

        insertar_inicio(inicio, valor);
    }
    void asignar_valor_cabeza(int nuevo_valor){
        /**
* @brief usando la funcion privada, modifica el valor del primer elemento de la lista, usando el punteor inicial, el valor original y el valor entero a cambiar.
*
* @param valor es el numero entero ingresado originalmente.
* @param nuevo_valor es el numero entero por el cual se desa cambiar al original.
* @param *inicio es el puntero, que contiene la direccion del valor.
*
* @return muestra en la consola que el valor se ha modificado.
*/
        inicio->valor = nuevo_valor;
        std::cout<<"Valor de cabeza modificado correctamente" << std::endl;
    }
    void obtener_valor_cabeza(){
        /**
* @brief usando la funcion privada, muestra el primer numero en la lista.
*
* @param valor es el numero entero ingresado.
* @param *inicio es el puntero, que tiene la direccion del valor.
*
* @return muestra en la consola que el valor se ha modificado.
*/
        std::cout<<"EL valor almacenado al inicio es: " << inicio->valor <<std::endl;
    }

    void eliminar_nodo(){
        /**
* @brief usando la funcion privada, elimina el primer elemento de la lista, usando el puntero inicio.
*
* @param inicio es el puntero que tiene la dirreccion del primer valor.

*/
        eliminar_nodo_referencia(inicio);
    }
    void mostrar_lista(){
        /**
* @brief usando la funcion privada, muestra en la consola la lista de valores que estan usando activamente espacios en memoria.
*
* @param inicio es el puntero que tiene la dirreccion del primer valor.

*/
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
    l->insertar_nuevo(9);
    l->mostrar_lista();
    collector->mostrar_collector();
    l->eliminar_nodo();
    l->mostrar_lista();
    collector->mostrar_collector();

    return 0;
}
