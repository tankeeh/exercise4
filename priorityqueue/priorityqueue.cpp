
#include "priorityqueue.hpp"


template <typename Data>
PriorityQueue<Data>::PriorityQueue(const LinearContainer<Data>& container):Heap<Data>(container){}

template <typename Data>
PriorityQueue<Data>::PriorityQueue(const PriorityQueue<Data>& priorityqueue):Heap<Data>(priorityqueue){}

template <typename Data>
PriorityQueue<Data>::PriorityQueue(PriorityQueue<Data>&& priorityqueue):Heap<Data>(std::move(priorityqueue)){}

template <typename Data>
PriorityQueue<Data>& PriorityQueue<Data>::operator=(const PriorityQueue<Data>& priorityqueue) noexcept{
    Heap<Data>::operator=(priorityqueue);
    return *this;
}

template <typename Data>
PriorityQueue<Data>& PriorityQueue<Data>::operator=(PriorityQueue<Data>&& priorityqueue) noexcept{
    Heap<Data>::operator=(std::move(priorityqueue));
    return *this;
}

template <typename Data>
bool PriorityQueue<Data>::operator==(const PriorityQueue<Data>& priorityqueue)const noexcept{
    return BinaryTree<Data>::operator==(priorityqueue);
}

template <typename Data>
bool PriorityQueue<Data>::operator!=(const PriorityQueue<Data>& priorityqueue)const noexcept{
    return BinaryTree<Data>::operator!=(priorityqueue);

}

template<typename Data>
Data PriorityQueue<Data>::Tip() const {
    if(!(this->Empty()))  return this->Root();
    else throw std::length_error("non ci sono elementi nello Heap.");
}

template<typename Data>
void PriorityQueue<Data>::RemoveTip() {
    if(!(this->Empty())){
        std::swap(this->tree[0]->Element(),this->tree[this->size-1]->Element());
        delete this->tree[this->size-1];
    }
    else throw std::length_error("non ci sono elementi nello Heap.");
}

template<typename Data>
const Data& PriorityQueue<Data>::TipNRemove() {
    if(!(this->Empty())){
        Tip();
        RemoveTip();
    }
    else throw std::length_error("non ci sono elementi nello Heap.");
}

template<typename Data>
void PriorityQueue<Data>::Insert(const Data& item) noexcept {

}

template<typename Data>
void PriorityQueue<Data>::Insert(Data && item) noexcept {

}

template<typename Data>
void PriorityQueue<Data>::ChangePriority(const Data &) noexcept {

}

template<typename Data>
void PriorityQueue<Data>::ChangePriority(Data &&) noexcept {

}
