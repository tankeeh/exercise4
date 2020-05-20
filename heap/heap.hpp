
#ifndef HEAP_HPP
#define HEAP_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../binarytree/vec/binarytreevec.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Heap :  virtual public SearchableContainer<Data>,virtual protected BinaryTreeVec<Data>{

private:

  // ...

protected:

  // using SearchableContainer<Data>::???;

  using BinaryTreeVec<Data>::NodeVec;


  void BuildTree(Heap& heap,const LinearContainer<Data>& container) ;

  void BuildHeap();

  void Heapify(Heap& heap,int i,int heapsize);

  // ...

public:
    void PrintArray();

    using BinaryTreeVec<Data>::Root;

    // Default constructor
  Heap() = default;

  // Specific constructor
  Heap(const LinearContainer<Data>& container); // Construct a heap from a LinearContainer

  // Copy constructor
  Heap(const Heap& heap2);

  // Move constructor
  Heap(Heap&& heap2) ;

  /* ************************************************************************ */

  // Destructor
  ~Heap() = default;

  /* ************************************************************************ */

  // Copy assignment
  Heap& operator=(const Heap& heap2) noexcept ;

  // Move assignment
  Heap& operator=(Heap&& heap2) noexcept ;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const Heap& heap2) const noexcept ;
  bool operator!=(const Heap& heap2) const noexcept ;


    /* ************************************************************************ */

  // Specific member functions

  void Sort();

  /* ************************************************************************ */

  // Specific member functions (inherited from SearchableContainer)

  using typename SearchableContainer<Data>::MapFunctor;
  void MapPreOrder(MapFunctor, void* par) override ; // Override SearchableContainer member
  void MapPostOrder(MapFunctor, void* par) override ; // Override SearchableContainer member

  using typename SearchableContainer<Data>::FoldFunctor;
  void FoldPreOrder(FoldFunctor functor, const void *par, void *acc) const override ; // Override SearchableContainer member
  void FoldPostOrder(FoldFunctor functor, const void *par, void *acc) const override ; // Override SearchableContainer member

  using SearchableContainer<Data>::Exists;

};

/* ************************************************************************** */

#include "heap.cpp"

}

#endif
