
#include "priorityqueue.hpp"


template <typename Data>
PriorityQueue<Data>::PriorityQueue(const LinearContainer<Data>& container):Heap<Data>(container){}

template <typename Data>
PriorityQueue<Data>::PriorityQueue(const PriorityQueue<Data>& priorityqueue):Heap<Data>(),BinaryTreeVec<Data>(priorityqueue){}

template <typename Data>
PriorityQueue<Data>::PriorityQueue(PriorityQueue<Data>&& priorityqueue):Heap<Data>(),BinaryTreeVec<Data>(std::move(priorityqueue)){}

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
Data& PriorityQueue<Data>::Tip() const {
    if(!(this->Empty()))  return this->tree[0]->Element();
    else throw std::length_error("non ci sono elementi nello Heap.");
}

template<typename Data>
void PriorityQueue<Data>::RemoveTip() {
    if(!(this->Empty())){
        std::swap(this->tree[0]->Element(),this->tree[this->size-1]->Element());
        delete this->tree[this->size-1];
        this->tree[this->size-1] = nullptr;
        this->size--;
        Heapify(*this,0,this->size);
        if(this->Size() < this->tree.Size()/2 && this->tree.Size()/2 >= 3) this->tree.Resize(this->tree.Size()/2);
    }
    else throw std::length_error("non ci sono elementi nello Heap.");
}

template<typename Data>
const Data PriorityQueue<Data>::TipNRemove() {
    if(!(this->Empty())){
        Data ret = Tip();
        RemoveTip();
        return ret;
    }
    else throw std::length_error("non ci sono elementi nello Heap.");
}

template <typename Data>
void PriorityQueue<Data>::UpSwap(typename BinaryTreeVec<Data>::NodeVec& node){
    if(node.HasParent()){
        if(node.Element() < node.Parent().Element()){
            std::swap(node.Element(),node.Parent().Element());
            UpSwap(node.Parent());
        }
    }
}

template<typename Data>
void PriorityQueue<Data>::Insert(const Data& item) noexcept {
    if(this->size >= this->tree.Size()) this->Expand();
    this->tree[this->size] = new typename BinaryTreeVec<Data>::NodeVec(item,&this->tree);
    this->tree[this->size]->setIndex(this->size);
    this->size++;
    UpSwap(*this->tree[this->size - 1]);
}


template<typename Data>
void PriorityQueue<Data>::Insert(Data && item) noexcept {
    if(this->size >= this->tree.Size()) this->Expand();
    this->tree[this->size] = new typename BinaryTreeVec<Data>::NodeVec(std::move(item),&this->tree);
    this->tree[this->size]->setIndex(this->size);
    this->size++;
    UpSwap(*this->tree[this->size -1]);
}

template<typename Data>
void PriorityQueue<Data>::ChangePriority(typename BinaryTreeVec<Data>::NodeVec& node,const Data& item) noexcept {
    if(item < node.Element()){
        node.Element() = item;
        this->BuildHeap();
        //UpSwap(node);
    }
    else if(item > node.Element()){
        node.Element() = item;
        this->BuildHeap();
        //Heapify(*this,node.getIndex(),this->size);
    }
}

template<typename Data>
void PriorityQueue<Data>::ChangePriority(typename BinaryTreeVec<Data>::NodeVec& node,Data&& item) noexcept {
    if(item < node.Element()){
        node.Element() = std::move(item);
        this->BuildHeap();
        //UpSwap(node);
    }
    else if(item > node.Element()){
        node.Element() = std::move(item);
        this->BuildHeap();
        //Heapify(*this,node.getIndex(),this->size);
    }
}
