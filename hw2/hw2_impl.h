#ifndef HW2_IMPL_H
#define HW2_IMPL_H

#include <algorithm>
#include <cstdlib>
#include <vector>

#include "hw2.h"

// Heap

template <typename T>
Heap<T>::Heap(bool isMinHeap) : minHeap(isMinHeap)
{
  // COMPLETE HERE
  elements = std::vector<T>();
}

template <typename T>
void Heap<T>::insert(T const &element)
{
  // COMPLETE HERE
  elements.push_back(element);
  heapifyUp(elements.size() - 1);
}

template <typename T>
T Heap<T>::extractTop()
{
  // COMPLETE HERE
  if (isEmpty())
    throw std::out_of_range("Heap is empty");

  T top = elements[0];
  elements[0] = elements.back();
  elements.pop_back();

  if (!isEmpty())
  {
    heapifyDown(0);
  }
  return top;
}

template <typename T>
T Heap<T>::peek() const
{
  // COMPLETE HERE
  if (isEmpty())
    throw std::out_of_range("Heap is empty");
  return elements[0];
}

template <typename T>
size_t Heap<T>::size() const
{
  // COMPLETE HERE
  return elements.size();
}

template <typename T>
bool Heap<T>::isEmpty() const
{
  // COMPLETE HERE
  return elements.empty();
}

template <typename T>
void Heap<T>::clear()
{
  // COMPLETE HERE
  elements.clear();
}

// Función auxiliar para mantener la propiedad de heap después de una inserción.
template <typename T>
void Heap<T>::heapifyUp(size_t index)
{
  while (index > 0)
  {
    size_t parent = (index - 1) / 2;
    if ((minHeap && elements[index] < elements[parent]) || (!minHeap && elements[index] > elements[parent]))
    {
      std::swap(elements[index], elements[parent]);
      index = parent;
    }
    else
    {
      break;
    }
  }
}

// Función auxiliar para mantener la propiedad de heap después de una extracción.
template <typename T>
void Heap<T>::heapifyDown(size_t index)
{
  size_t size = elements.size();
  while (true)
  {
    size_t left = 2 * index + 1;
    size_t right = 2 * index + 2;
    size_t smallest = index;

    if (left < size && ((minHeap && elements[left] < elements[smallest]) || (!minHeap && elements[left] > elements[smallest])))
    {
      smallest = left;
    }
    if (right < size && ((minHeap && elements[right] < elements[smallest]) || (!minHeap && elements[right] > elements[smallest])))
    {
      smallest = right;
    }
    if (smallest != index)
    {
      std::swap(elements[index], elements[smallest]);
      index = smallest;
    }
    else
    {
      break;
    }
  }
}

#endif
