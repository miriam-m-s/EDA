//
//  queue_eda.h
//
//  Implementación del TAD cola con nodos enlazados
//  y punteros al primero y al último nodo
//
//  Estructuras de Datos
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2020 Alberto Verdejo
//

#ifndef queue_h
#define queue_h

#include <stdexcept>  // std::domain_error

template <class T>
class queue {
protected:

    /*
     Nodo que almacena internamente el elemento (de tipo T),
     y un puntero al nodo siguiente, que puede ser nullptr si
     el nodo es el último de la lista enlazada.
     */
    struct Nodo {
        Nodo() : sig(nullptr) {}
        Nodo(T const& el, Nodo* si = nullptr) : elem(el), sig(si) {}
        T elem;
        Nodo* sig;
    };

    // punteros al primer y último elemento
    Nodo* prim;
    Nodo* ult;

    // número de elementos en la cola
    int nelems;

public:

    // constructor: cola vacía
    queue() : prim(nullptr), ult(nullptr), nelems(0) {}

    // destructor
    ~queue() {
        libera();
    }

    // constructor por copia
    queue(queue<T> const& other) {
        copia(other);
    }

    // operador de asignación
    queue<T>& operator=(queue<T> const& other) {
        if (this != &other) {
            libera();
            copia(other);
        }
        return *this;
    }

    // añadir un elemento al final de la cola
    void push(T const& elem) {
        Nodo* nuevo = new Nodo(elem);

        if (ult != nullptr)
            ult->sig = nuevo;
        ult = nuevo;
        if (prim == nullptr) // la cola estaba vacía
            prim = nuevo;
        ++nelems;
    }

    // consultar el primero de la cola
    T const& front() const {
        if (empty())
            throw std::domain_error("la cola vacia no tiene primero");
        return prim->elem;
    }
    void invertircola() {
        int mita = nelems / 2;
        Nodo* mitad = this->prim;
        Nodo* ant = this->prim;
        int i = 0;
        while (i != mita) {
         
            if (i >= 1) {
                ant = ant->sig;
            }
            mitad = mitad->sig;
            i++;
        }
        Nodo* der = mitad;
        Nodo* izq = this->prim;
        Nodo* finder = this->ult;
        Nodo* antder =ant;
        int j = 0;
        while (j != mita) {
            while (der != finder) {            
                antder = antder->sig;               
                der = der->sig;
            }
            finder = antder;
            int iz = izq->elem;


            izq->elem = der->elem;
            der->elem = iz;
           
            antder = ant;
            der = mitad;
            izq = izq->sig;
            j++;
           
        }

        
    }
    void invierte() {
        if (this->size() != 0&&this->size()!=1&& this->size() != 2) {
            Nodo* aux1 = this->prim;
            Nodo* aux2 = this->prim->sig;
            Nodo* aux3 = nullptr;
            if (this->prim->sig->sig)
                aux3 = this->prim->sig->sig;

            this->ult = this->prim;
            bool hey = true;
            while (hey) {
                if (aux3->sig == nullptr) {
                    this->prim = aux3;
                    aux3->sig = aux2;
                    aux2->sig = aux1;
                    hey = false;
                }
                else {
                    aux2->sig = aux1;
                    aux1 = aux2;
                    aux2 = aux3;
                    aux3 = aux3->sig;

                }
            }
            this->ult->sig = nullptr;
        }
        else if(this->size() == 2) {
            int iz = this->prim->elem;


            this->prim->elem = this->ult->elem;
            this->ult->elem = iz;


        }
        
    }
    // eliminar el primero de la cola
    void pop() {
        if (empty())
            throw std::domain_error("eliminando de una cola vacia");
        Nodo* a_borrar = prim;
        prim = prim->sig;
        if (prim == nullptr) // la cola se ha quedado vacía
            ult = nullptr;
        delete a_borrar;
        --nelems;
    }

    // consultar si la cola está vacía
    bool empty() const {
        return nelems == 0;
    }

    // consultar el tamaño de la cola
    int size() const {
        return nelems;
    }

protected:

    void libera() {
        while (prim != nullptr) {
            Nodo* a_borrar = prim;
            prim = prim->sig;
            delete a_borrar;
        }
        ult = nullptr;
    }

    // this está sin inicializar
    void copia(queue const& other) {
        if (other.empty()) {
            prim = ult = nullptr;
            nelems = 0;
        }
        else {
            Nodo* act = other.prim; // recorre la cola original
            Nodo* ant = new Nodo(act->elem); // último nodo copiado
            prim = ant;
            while (act->sig != nullptr) {
                act = act->sig;
                ant->sig = new Nodo(act->elem);
                ant = ant->sig;
            }
            ult = ant;
            nelems = other.nelems;
        }
    }
};

#endif // queue_eda_h
