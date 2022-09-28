//
//  list_eda.h
//
//  Implementaci�n del TAD lista heredando de colas dobles
//  y con iteradores (constantes y no constantes)
//
//  Estructuras de Datos
//  Facultad de Inform�tica
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2020 Alberto Verdejo
//

#ifndef list_h
#define list_h

#include <stdexcept>
#include <cassert>

#include "deque_eda.h"

template <class T>
class list : public deque<T> {
public:
    void une(list<T>& h) {
        Nodo* he = h.fantasma->sig;
        Nodo* aux = this->fantasma->sig;
        if (aux->elem > he->elem) {
            Nodo* m = he;
            he = he->sig;
            ++this->nelems;
            aux->ant = he;
            m->sig = aux;
            m->ant = this->fantasma;
            this->fantasma->sig = m;
           
          //  aux = aux->sig;
           
        }
    
        while (aux!=this->fantasma&&he!=h.fantasma) {
            if (aux->elem > he->elem) {
                Nodo* l = he;
                Nodo* ant = aux->ant;  
                he = he->sig;
                ++this->nelems;
                aux->ant->sig = l;
                aux->ant = l;   
                l->sig = aux;               
                l->ant = ant;
            }
            else {
                aux = aux->sig;
            }      
        }
        if (aux == this->fantasma) {
            while (he != h.fantasma) {
                Nodo* m = aux->ant;
                Nodo* l = he;
                he = he->sig;
                ++this->nelems;
                aux->ant->sig = l;
                l->ant = m;
                l->sig = this->fantasma;
                this->fantasma->ant = l;
              
            }
        }
        h.nelems = 0;
        h.fantasma->ant = h.fantasma;
        h.fantasma->sig = h.fantasma;
            /* Nodo* aux=this->prim;
         if (aux->elem > * it) {
             Nodo* hey = this->prim->sig;
             int elemento = prim->elem;

         }
         for (list<int>::iterator it = h.begin(); it != h.end(); ++it) {
             if (aux->elem > * it) {

             }
         }*/
    }
protected:
    using Nodo = typename deque<T>::Nodo;

    template <class Apuntado>
    class Iterador {
        // puntero al nodo actual del recorrido
        Nodo* act;
        // puntero al nodo fantasma (para saber cu�ndo estamos fuera)
        Nodo* fan;
    public:
        void une(list<int>& h) {
            Nodo* he = this->prim;
            /* Nodo* aux=this->prim;
             if (aux->elem > * it) {
                 Nodo* hey = this->prim->sig;
                 int elemento = prim->elem;

             }
             for (list<int>::iterator it = h.begin(); it != h.end(); ++it) {
                 if (aux->elem > * it) {

                 }
             }*/
        }
        Iterador() : act(nullptr), fan(nullptr) {}

        // para acceder al elemento apuntado
        Apuntado& operator*() const {
            if (act == fan) throw std::out_of_range("fuera de la lista");
            return act->elem;
        }

        // para acceder a un m�todo del elemento apuntado
        // it->metodo() en vez de (*it).metodo()
        Apuntado* operator->() const {
            return &(operator*());
        }

        Iterador& operator++() { // ++ prefijo (recomendado)
            if (act == fan) throw std::out_of_range("fuera de la lista");
            act = act->sig;
            return *this;
        }

        Iterador operator++(int) { // ++ postfijo
            Iterador ret(*this);
            operator++();
            return ret;
        }

        bool operator==(Iterador const& that) const {
            return act == that.act && fan == that.fan;
        }

        bool operator!=(Iterador const& that) const {
            return !(*this == that);
        }

    private:
        // para que list pueda construir objetos del tipo iterador
        friend class list;

        // constructora privada
        Iterador(Nodo* ac, Nodo* fa) : act(ac), fan(fa) {}
    };

public:
    /*
     Iteradores que permiten recorrer la lista pero no cambiar sus elementos.
     */
    using const_iterator = Iterador<T const>;

    // devuelven un iterador constante al principio de la lista
    const_iterator cbegin() const {
        return const_iterator(this->fantasma->sig, this->fantasma);
    }
    const_iterator begin() const {
        return cbegin();
    }

    // devuelven un iterador constante al final del recorrido y fuera de este
    const_iterator cend() const {
        return const_iterator(this->fantasma, this->fantasma);
    }
    const_iterator end() const {
        return cend();
    }

    /*
     Iteradores que permiten recorrer la lista y cambiar sus elementos.
     */
    using iterator = Iterador<T>;

    // devuelve un iterador al principio de la lista
    iterator begin() {
        return iterator(this->fantasma->sig, this->fantasma);
    }

    // devuelve un iterador al final del recorrido y fuera de este
    iterator end() {
        return iterator(this->fantasma, this->fantasma);
    }

    // inserta un elemento delante del apuntado por el iterador it
    // (it puede estar apuntado detr�s del �ltimo)
    // devuelve un iterador al nuevo elemento
    iterator insert(iterator const& it, T const& elem) {
        assert(this->fantasma == it.fan); // comprueba que el iterador es de esta lista
        Nodo* nuevo = this->inserta_elem(elem, it.act->ant, it.act);
        return iterator(nuevo, this->fantasma);
    }

    // elimina el elemento apuntado por el iterador (debe haber uno)
    // devuelve un iterador al siguiente elemento al borrado
    iterator erase(iterator const& it) {
        assert(this->fantasma == it.fan); // comprueba que el iterador es de esta lista
        if (it.act == this->fantasma)
            throw std::out_of_range("fuera de la lista");
        iterator next(it.act->sig, this->fantasma);
        this->borra_elem(it.act);
        return next;
    }
};

#endif // list_eda_h