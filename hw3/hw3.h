#ifndef HW3_H
#define HW3_H

/*******************************************************************************

MODIFIQUE ESTE ARCHIVO Y LA CORRESPONDIENTE IMPLEMENTACIÓN A SU GUSTO.


Los tests que se usarán para calificar esta tarea serán los provistos en el
archivo de tests y muchos otros. El archivo de tests se incluye solo a modo
de referencia, pero no es una version completa de los tests que serán
utilizados.

Todas las funciones listadas en este archivo serán testeadas por el corrector
automático, con el mismo prototipo mostrado en este archivo.

*******************************************************************************/

template <typename T>
struct Node
{
    T data;
    Node *left;
    Node *right;
    Node(T value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
struct BST
{
private:
    Node<T> *head;

    Node<T> *insertNode(Node<T> *node, T const &value);

    bool searchNode(Node<T> *node, T const &value) const;

    Node<T> *removeNode(Node<T> *node, T const &value);

    Node<T> *findMinNode(Node<T> *node) const;

    Node<T> *findMaxNode(Node<T> *node) const;

    size_t countNodes(Node<T> *node) const;

    void clearNodes(Node<T> *node);

public:
    BST();

    ~BST();

    void insert(T const &value);

    bool search(T const &value) const;

    void remove(T const &value);

    size_t size() const;

    T findMin() const;

    T findMax() const;

    bool isEmpty() const;

    void clear();
};

#include "hw3_impl.h"

#endif
