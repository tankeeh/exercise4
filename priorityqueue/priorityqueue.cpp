

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