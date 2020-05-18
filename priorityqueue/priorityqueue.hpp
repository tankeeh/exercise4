
#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

/* ************************************************************************** */

#include "../heap/heap.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class PriorityQueue: virtual public Heap<Data> {

private:

  // ...

protected:

  using Heap<Data>::Heapify;

  void UpSwap(typename BinaryTreeVec<Data>::NodeVec& node);

    // ...

public:
    using BinaryTreeVec<Data>::Root;

    // Default constructor
  PriorityQueue() = default;

  // Specific constructor
  PriorityQueue(const LinearContainer<Data>& container); // Construct a priority queue from a LinearContainer

  // Copy constructor
  PriorityQueue(const PriorityQueue<Data>&);

  // Move constructor
  PriorityQueue(PriorityQueue<Data>&&);

  /* ************************************************************************ */

  // Destructor
  ~PriorityQueue() = default;

  /* ************************************************************************ */

  // Copy assignment
  PriorityQueue& operator=(const PriorityQueue&) noexcept ;

  // Move assignment
  PriorityQueue& operator=(PriorityQueue&&) noexcept ;


    /* ************************************************************************ */

  // Comparison operators
  bool operator==(const PriorityQueue&) const noexcept ;
  bool operator!=(const PriorityQueue&) const noexcept ;


    /* ************************************************************************ */

  // Specific member functions

  using Heap<Data>::Sort;

  // using Heap<Data>::Root;

  Data& Tip() const; // (might throw std::length_error)
  void RemoveTip() ; // (might throw std::length_error)
  const Data TipNRemove(); // (might throw std::length_error)
  void Insert(const Data&) noexcept ; // Copy of the value
  void Insert(Data&&) noexcept ; // Move of the value

  void ChangePriority(typename BinaryTreeVec<Data>::NodeVec& node,const Data&) noexcept; // Change priority of a Node (Copy of the value)
  void ChangePriority(typename BinaryTreeVec<Data>::NodeVec& node,Data&&) noexcept; // Change priority of a Node (Move of the value)



};

/* ************************************************************************** */

#include "priorityqueue.cpp"

}

#endif
