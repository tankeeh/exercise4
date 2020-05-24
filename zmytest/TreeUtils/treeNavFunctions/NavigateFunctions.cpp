//
// Created by Antonio on 10/05/2020.
//


/**NAVIGAZIONE SULLE PRIORITY QUEUES**/

template <typename Data>
void intRecursivePQueueNavigate(lasd::PriorityQueue<Data>* Pqueue,typename lasd::BinaryTreeVec<Data>::NodeVec* node){

    char scelta = '0';

    while(scelta != 'e'){


        std::cout<<"\n1. per spostarsi sul nodo sinistro \n";
        std::cout<<"2. per spostarsi sul nodo destro \n";
        std::cout<<"r. per spostarsi sul nodo padre \n";
        std::cout<<"3. per aggiungere un nodo \n";
        std::cout<<"v. per vedere il valore del nodo attuale\n";
        std::cout<<"4. per vedere il dato nella radice \n";
        std::cout<<"5. per vedere e rimuovere il dato nella radice\n";
        std::cout<<"6. per rimuovere nella radice  \n";
        std::cout<<"7. per cambiare la priorita' di un nodo \n";
        std::cout<<"e. per uscire \n";

        std::cout<<"\n\ncosa intendi fare ? \n";
        std::cin>>scelta;

        switch(scelta){
            case '1':
                if(node->HasLeftChild()) {
                    std::cout<<"Mi sposto sul nodo sinistro...";
                    intRecursivePQueueNavigate(Pqueue,&node->LeftChild());
                }else std::clog<<"Tale nodo non ha un figlio sinistro. \n\n";

                break;
            case '2':
                if(node->HasRightChild()){
                    std::cout<<"Mi sposto sul nodo destro...";
                    intRecursivePQueueNavigate(Pqueue,&node->RightChild());
                }
                else std::clog<<"Tale nodo non ha un figlio destro. \n\n";
                break;
            case 'r':
                if(node->HasParent()) {
                    std::cout << "Mi sposto sul nodo padre...";
                    return;
                }else std::clog<<"Tale nodo non ha un nodo padre. \n\n";
                break;
            case '3':
                int item;
                std::cout<<"Che valore deve avere il nuovo nodo ? \n";
                std::cin>>item;
                Pqueue->Insert(item);
                break;
            case 'v':
                if(node->getIndex() <= Pqueue->Size()) std::cout<<"\nIl valore del nodo che si sta visitando e' : "<<node->Element()<<" \n\n";
                else {
                    std::clog<<"\n Nodo non presente. E' possibile si stia visitando una locazione non piu' rilevante. mi sposto sulla Radice...";
                    intRecursivePQueueNavigate(Pqueue,&Pqueue->Root());
                }
                break;
            case '4':
                try {
                    std::cout << "Il dato nella radice e' : " << Pqueue->Tip() << "\n\n";
                }
                catch (std::length_error err){
                    std::clog<<err.what()<<"\n";
                }
                break;
            case '5':
                try{
                std::cout<<"Il dato nella radice e' : "<<Pqueue->TipNRemove()<<"\n\n";
                std::cout<<"\n\nRadice rimossa.\n\n";
                }
                catch (std::length_error err){
                    std::clog<<err.what()<<"\n";
                }
                break;
            case '6':
                std::cout<<"Rimozione della radice...\n";
                try{
                Pqueue->RemoveTip();
                }
                catch (std::length_error err){
                    std::clog<<err.what()<<"\n";
                }
                break;
            case '7':
                if(!(Pqueue->Empty())) {
                    int val;
                    std::cout << "** CHANGE PRIORITY **";
                    std::cout << "Quale valore vuoi che sovrascriva il nodo che attualmente stai visitando ? \n";
                    std::cin >> val;
                    Pqueue->ChangePriority(*node, val);
                    std::cout << "Ricostruzione della Priority Queue come MinHeap...";
                }else std::clog<<"\n Nodo non presente. E' possibile che la priority queue sia vuota.\n\n";
                break;
            case 'e': {
                std::cout << " Esco dalla navigazione nodi... (potrebbe esserci la necessita' di richiamare piu' volte questo comando) \n";
                return;
                }
            default:
                std::cout<<"carattere non valido.";
    }
    }


}


template <typename Data>
void intTreePQueueNavigation(lasd::PriorityQueue<Data>* Pqueue){
    std::cout<<"\n Attualmente sei sulla Root dell' albero \n";
    intRecursivePQueueNavigate(Pqueue,&Pqueue->Root());
}




template <typename Data>
void floatRecursivePQueueNavigate(lasd::PriorityQueue<Data>* Pqueue,typename lasd::BinaryTreeVec<Data>::NodeVec* node){

    char scelta = '0';

    while(scelta != 'e'){


        std::cout<<"\n1. per spostarsi sul nodo sinistro \n";
        std::cout<<"2. per spostarsi sul nodo destro \n";
        std::cout<<"r. per spostarsi sul nodo padre \n";
        std::cout<<"3. per aggiungere un nodo \n";
        std::cout<<"v. per vedere il valore del nodo attuale\n";
        std::cout<<"4. per vedere il dato nella radice \n";
        std::cout<<"5. per vedere e rimuovere il dato nella radice\n";
        std::cout<<"6. per rimuovere nella radice  \n";
        std::cout<<"7. per cambiare la priorita' di un nodo \n";
        std::cout<<"e. per uscire \n";

        std::cout<<"\n\ncosa intendi fare ? \n";
        std::cin>>scelta;

        switch(scelta) {
            case '1':
                if (node->HasLeftChild()) {
                    std::cout << "Mi sposto sul nodo sinistro...";
                    floatRecursivePQueueNavigate(Pqueue, &node->LeftChild());
                } else std::clog << "Tale nodo non ha un figlio sinistro. \n\n";
            case '2':
                if (node->HasRightChild()) {
                    std::cout << "Mi sposto sul nodo destro...";
                    floatRecursivePQueueNavigate(Pqueue, &node->RightChild());
                } else std::clog << "Tale nodo non ha un figlio destro. \n\n";
            case 'r':
                if (node->HasParent()) {
                    std::cout << "Mi sposto sul nodo padre...";
                    return;
                } else std::clog << "Tale nodo non ha un nodo padre. \n\n";
                break;
            case '3':
                float item;
                std::cout << "Che valore deve avere il nuovo nodo ? \n";
                std::cin >> item;
                Pqueue->Insert(item);
                break;
            case 'v':
                if(node->getIndex() <= Pqueue->Size()) std::cout<<"\nIl valore del nodo che si sta visitando e' : "<<node->Element()<<" \n\n";
                else {
                    std::clog<<"\n Nodo non presente. E' possibile si stia visitando una locazione non piu' rilevante. mi sposto sulla Radice...";
                    floatRecursivePQueueNavigate(Pqueue,&Pqueue->Root());
                }
                break;
            case '4':
                try {
                    std::cout << "Il dato nella radice e' : " << Pqueue->Tip() << "\n\n";
                }
                catch (std::length_error err) {
                    std::clog << err.what() << "\n";
                }
                break;
            case '5':
                try {
                    std::cout << "Il dato nella radice e' : " << Pqueue->TipNRemove() << "\n\n";
                    std::cout << "\n\nRadice rimossa.\n\n";
                }
                catch (std::length_error err) {
                    std::clog << err.what() << "\n";
                }
                break;
            case '6':
                try {
                    std::cout << "Rimozione della radice...\n";
                    Pqueue->RemoveTip();
                }
                catch (std::length_error err) {
                    std::clog << err.what() << "\n";
                }
                break;
            case '7':
                if(!(Pqueue->Empty())){
                float val;
                std::cout << "** CHANGE PRIORITY **";
                std::cout << "Quale valore vuoi che sovrascriva il nodo che attualmente stai visitando ? \n";
                std::cin >> val;
                Pqueue->ChangePriority(*node, val);
                std::cout << "Ricostruzione del MinHeap...";
                }else std::clog<<"\n Nodo non presente. E' possibile che la priority queue sia vuota.\n\n";
                break;
            case 'e':
                std::cout << " Esco dalla navigazione nodi... (potrebbe esserci la necessita' di richiamare piu' volte questo comando) \n";
                return;
            default:
                std::cout<<"carattere non valido.";
        }
    }


}


template <typename Data>
void floatTreePQueueNavigation(lasd::PriorityQueue<Data>* Pqueue){
    std::cout<<"\n Attualmente sei sulla Root dell' albero \n";
    floatRecursivePQueueNavigate(Pqueue,&Pqueue->Root());
}



template <typename Data>
void stringRecursivePQueueNavigate(lasd::PriorityQueue<Data>* Pqueue,typename lasd::BinaryTreeVec<Data>::NodeVec* node){

    char scelta = '0';

    while(scelta != 'e'){


        std::cout<<"\n1. per spostarsi sul nodo sinistro \n";
        std::cout<<"2. per spostarsi sul nodo destro \n";
        std::cout<<"r. per spostarsi sul nodo padre \n";
        std::cout<<"3. per aggiungere un nodo \n";
        std::cout<<"v. per vedere il valore del nodo attuale\n";
        std::cout<<"4. per vedere il dato nella radice \n";
        std::cout<<"5. per vedere e rimuovere il dato nella radice\n";
        std::cout<<"6. per rimuovere nella radice  \n";
        std::cout<<"7. per cambiare la priorita' di un nodo \n";
        std::cout<<"e. per uscire \n";

        std::cout<<"\n\ncosa intendi fare ? \n";
        std::cin>>scelta;

        switch(scelta) {
            case '1':
                if(node->HasLeftChild()){
                    std::cout<<"Mi sposto sul nodo sinistro...";
                    stringRecursivePQueueNavigate(Pqueue,&node->LeftChild());
                }
                else std::clog<<"Tale nodo non ha un figlio sinistro. \n\n";
            case '2':
                if(node->HasRightChild()){
                    std::cout<<"Mi sposto sul nodo destro...";
                    stringRecursivePQueueNavigate(Pqueue,&node->RightChild());
                }
                else std::clog<<"Tale nodo non ha un figlio destro. \n\n";
            case 'r':
                if (node->HasParent()) {
                    std::cout << "Mi sposto sul nodo padre...";
                    return;
                } else std::clog << "Tale nodo non ha un nodo padre. \n\n";
                break;
            case '3': {
                std::string item;
                std::cout << "Che valore deve avere il nuovo nodo ? \n";
                std::cin >> item;
                Pqueue->Insert(item);
                break;
            }
            case 'v':
                if(node->getIndex() <= Pqueue->Size()) std::cout<<"\nIl valore del nodo che si sta visitando e' : "<<node->Element()<<" \n\n";
                else {
                    std::clog<<"\n Nodo non presente. E' possibile si stia visitando una locazione non piu' rilevante. mi sposto sulla Radice...";
                    stringRecursivePQueueNavigate(Pqueue,&Pqueue->Root());
                }
                break;
            case '4':
                try{
                std::cout << "Il dato nella radice e' : " << Pqueue->Tip() << "\n\n";
                }
                catch (std::length_error err){
                    std::clog<<err.what()<<"\n";
                }
                break;
            case '5':
                try{
                std::cout << "Il dato nella radice e' : " << Pqueue->TipNRemove() << "\n\n";
                std::cout << "\n\nRadice rimossa.\n\n";
                }
                catch (std::length_error err){
                    std::clog<<err.what()<<"\n";
                }
                break;
            case '6':
                try{
                std::cout << "Rimozione della radice...\n";
                Pqueue->RemoveTip();
                }
                catch (std::length_error err){
                    std::clog<<err.what()<<"\n";
                }
                break;
            case '7': {
                if(!(Pqueue->Empty())){
                std::string val;
                std::cout << "** CHANGE PRIORITY **";
                std::cout << "Quale valore vuoi che sovrascriva il nodo che attualmente stai visitando ? \n";
                std::cin >> val;
                Pqueue->ChangePriority(*node, val);
                std::cout << "Ricostruzione del MinHeap...";
            }else std::clog<<"\n Nodo non presente. E' possibile che la priority queue sia vuota.\n\n";
                break;
            }
            case 'e':
                std::cout << " Esco dalla navigazione nodi... (potrebbe esserci la necessita' di richiamare piu' volte questo comando) \n";
                return;
            default:
                std::cout<<"carattere non valido.";
        }
    }


}


template <typename Data>
void stringTreePQueueNavigation(lasd::PriorityQueue<Data>* Pqueue){
    std::cout<<"\n Attualmente sei sulla Root dell' albero \n";
    stringRecursivePQueueNavigate(Pqueue,&Pqueue->Root());
}

