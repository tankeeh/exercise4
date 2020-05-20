
#include "heap.hpp"

template <typename Data>
void Heap<Data>::BuildTree(Heap<Data>& heap,const LinearContainer<Data>& container){
    heap.size = container.Size();
    heap.tree.Resize(heap.size);
    int i = 0;
    while(i < heap.size){
        heap.tree[i] = new typename BinaryTreeVec<Data>::NodeVec(container[i],&heap.tree);
        heap.tree[i]->setIndex(i);
        i++;
    }
}


template <typename Data>
Heap<Data>:: Heap(const LinearContainer<Data>& container){
    BuildTree(*this,container);
    this->BuildHeap();
}


template <typename Data>
Heap<Data>& Heap<Data>:: operator=(const Heap& heap2) noexcept{
BinaryTreeVec<Data>::operator=(heap2);
return *this;
}

template <typename Data>
Heap<Data>& Heap<Data>:: operator=(Heap&& heap2) noexcept{
    BinaryTreeVec<Data>::operator=(std::move(heap2));
    return *this;
}

template <typename Data>
bool Heap<Data>::operator==(const Heap& heap2) const noexcept{
    return BinaryTree<Data>::operator==(heap2);
}

template <typename Data>
bool Heap<Data>::operator!=(const Heap& heap2) const noexcept{
    return BinaryTree<Data>::operator!=(heap2);
}


template<typename Data>
Heap<Data>::Heap(const Heap& heap2):BinaryTreeVec<Data>(heap2){}

template<typename Data>
Heap<Data>::Heap(Heap&& heap2):BinaryTreeVec<Data>(std::move(heap2)){}


template <typename Data>
void Heap<Data>::BuildHeap(){
    for(int i=(this->size-1)/2;i >= 0;i--) Heapify(*this,i,this->size);
}

template <typename Data>
void Heap<Data>::Heapify(Heap& heap,int i,int heapsize){
    int minimo = i;
    int temp;
    int sx = 2*i + 1;
    int dx = 2*i + 2;
    if(sx < heapsize && heap.tree[sx]->Element() <= heap.tree[minimo]->Element()) minimo=sx;
    if(dx < heapsize && heap.tree[dx]->Element() <= heap.tree[minimo]->Element()) minimo=dx;

    if(minimo != i){
        std::swap(heap.tree[i]->Element(),heap.tree[minimo]->Element());
        //std::swap(heap.tree[i],heap.tree[minimo]);

          //temp = heap.tree[i]->getIndex();
          //heap.tree[i]->setIndex(heap.tree[minimo]->getIndex());
          //heap.tree[minimo]->setIndex(temp);

        Heapify(heap,minimo,heapsize);
    }
}


template <typename Data>
void Heap<Data>::Sort(){
    int temp;
    this->BuildHeap();
    for(int j = this->size-1;j>0;j--){

        std::swap(this->tree[0]->Element(),this->tree[j]->Element());

        //temp = this->tree[j]->getIndex();
        //this->tree[j]->setIndex(this->tree[0]->getIndex());
        //this->tree[0]->setIndex(temp);

        Heapify(*this,0,j);
    }

    for(int k=0;k<(this->size)/2;k++){
    std::swap(this->tree[k]->Element(),this->tree[this->size-k-1]->Element());

    //temp = this->tree[k]->getIndex();
    //this->tree[k]->setIndex(this->tree[this->size-k-1]->getIndex());
    //this->tree[this->size-k-1]->setIndex(temp);
    }
}

template<typename Data>
void Heap<Data>::MapPreOrder(MapFunctor fun, void *par) {
this->MapBreadth(fun,par);
this->BuildHeap();
}

template<typename Data>
void Heap<Data>::MapPostOrder(MapFunctor fun, void *par) {
    for(int i=this->size-1;i>=0;i--) fun(this->tree[i]->Element(),par);
    this->BuildHeap();
}

template<typename Data>
void Heap<Data>::FoldPreOrder(FoldFunctor fun, const void *par, void *acc) const {
    this->FoldBreadth(fun,par,acc);
}

template<typename Data>
void Heap<Data>::FoldPostOrder(FoldFunctor fun, const void *par, void *acc) const {
    for(int i=this->size-1;i>=0;i--) fun(this->tree[i]->Element(),par,acc);
}















