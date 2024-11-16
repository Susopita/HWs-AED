#ifndef HW3_IMPL_H
#define HW3_IMPL_H

#include <algorithm>
#include <cstdlib>
#include <vector>
#include <stdexcept>

#include "hw3.h"

template <typename T>
BST<T>::BST()
{
	// COMPLETE HERE
	head = nullptr;
}

template <typename T>
BST<T>::~BST()
{
	// COMPLETE HERE
	clear();
}

template <typename T>
void BST<T>::insert(T const &value)
{
	// COMPLETE HERE
	head = insertNode(head, value);
}

template <typename T>
bool BST<T>::search(T const &value) const
{
	// COMPLETE HERE
	return searchNode(head, value);
}

template <typename T>
void BST<T>::remove(T const &value)
{
	// COMPLETE HERE
	head = removeNode(head, value);
}

template <typename T>
size_t BST<T>::size() const
{
	// COMPLETE HERE
	return countNodes(head);
}

template <typename T>
T BST<T>::findMin() const
{
	// COMPLETE HERE
	if (isEmpty())
		throw std::runtime_error("BST is empty");
	Node<T> *minNode = findMinNode(head);
	return minNode->data;
}

template <typename T>
T BST<T>::findMax() const
{
	// COMPLETE HERE
	if (isEmpty())
		throw std::runtime_error("BST is empty");
	Node<T> *maxNode = findMaxNode(head);
	return maxNode->data;
}

template <typename T>
bool BST<T>::isEmpty() const
{
	// COMPLETE HERE
	return head == nullptr;
}

template <typename T>
void BST<T>::clear()
{
	// COMPLETE HERE
	clearNodes(head);
	head = nullptr;
}

// Métodos privados

template <typename T>
Node<T> *BST<T>::insertNode(Node<T> *node, T const &value)
{
	if (!node)
		return new Node<T>(value);

	if (value < node->data)
		node->left = insertNode(node->left, value);
	else if (value > node->data)
		node->right = insertNode(node->right, value);

	return node;
}

template <typename T>
bool BST<T>::searchNode(Node<T> *node, T const &value) const
{
	if (!node)
		return false;

	if (value == node->data)
		return true;
	else if (value < node->data)
		return searchNode(node->left, value);
	else
		return searchNode(node->right, value);
}

template <typename T>
Node<T> *BST<T>::removeNode(Node<T> *node, T const &value)
{
	if (!node)
		return nullptr;

	if (value < node->data)
		node->left = removeNode(node->left, value);
	else if (value > node->data)
		node->right = removeNode(node->right, value);
	else
	{
		if (!node->left)
		{
			Node<T> *rightChild = node->right;
			delete node;
			return rightChild;
		}
		else if (!node->right)
		{
			Node<T> *leftChild = node->left;
			delete node;
			return leftChild;
		}
		else
		{
			Node<T> *minNode = findMinNode(node->right);
			node->data = minNode->data;
			node->right = removeNode(node->right, minNode->data);
		}
	}

	return node;
}

template <typename T>
Node<T> *BST<T>::findMinNode(Node<T> *node) const
{
	while (node->left)
		node = node->left;
	return node;
}

template <typename T>
Node<T> *BST<T>::findMaxNode(Node<T> *node) const
{
	while (node->right)
		node = node->right;
	return node;
}

template <typename T>
size_t BST<T>::countNodes(Node<T> *node) const
{
	if (!node)
		return 0;

	return 1 + countNodes(node->left) + countNodes(node->right);
}

template <typename T>
void BST<T>::clearNodes(Node<T> *node)
{
	if (!node)
		return;

	clearNodes(node->left);
	clearNodes(node->right);
	delete node;
}

#endif
