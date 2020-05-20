//
// Created by Antonio on 10/05/2020.
//


/**NAVIGAZIONE SULLE PRIORITY QUEUES**/

template <typename Data>
void intRecursivePQueueNavigate(lasd::PriorityQueue<Data>* Pqueue,typename lasd::BinaryTreeVec<Data>::NodeVec* node){

    char scelta = '0';

    if(!(node->HasParent())) std::cout<<"\n Attualmente sei sulla Root dell' albero \n";
    while(scelta != 'e'){

        std::cout<<"\n1. per spostarsi sul nodo sinistro \n";
        std::cout<<"2. per spostarsi sul nodo destro \n";
        std::cout<<"r. per spostarsi sul nodo padre \n";
        std::cout<<"3. per aggiungere un nodo \n";
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
                    intRecursivePQueueNavigate(Pqueue,&node->LeftChild());
                    std::cout<<"Mi sposto sul nodo sinistro...";
                }else std::cout<<"Tale nodo non ha un figlio sinistro.";

                break;
            case '2':
                if(node->HasRightChild()){
                    intRecursivePQueueNavigate(Pqueue,&node->RightChild());
                    std::cout<<"Mi sposto sul nodo destro...";
                }
                else std::cout<<"Tale nodo non ha un figlio destro.";
                break;
            case 'r':
                if(node->HasParent()) {
                    std::cout << "Mi sposto sul nodo padre...";
                    return;
                }else std::cout<<"Tale nodo non ha un nodo padre.";
                break;
            case '3':
                int item;
                std::cout<<"Che valore deve avere il nuovo nodo ? \n";
                std::cin>>item;
                Pqueue->Insert(item);
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
                int val;
                std::cout<<"** CHANGE PRIORITY **";
                std::cout<<"Quale valore vuoi che sovrascriva il nodo che attualmente stai visitando ? \n";
                std::cin>>val;
                Pqueue->ChangePriority(*node,val);
                std::cout<<"Ricostruzione del MinHeap...";
                break;
            case 'e':
                std::cout << " Esco dalla navigazione nodi... \n";
                return;
            default:
                std::cout<<"carattere non valido.";
    }
    }


}


template <typename Data>
void intTreePQueueNavigation(lasd::PriorityQueue<Data>* Pqueue){
    intRecursivePQueueNavigate(Pqueue,&Pqueue->Root());
}




template <typename Data>
void floatRecursivePQueueNavigate(lasd::PriorityQueue<Data>* Pqueue,typename lasd::BinaryTreeVec<Data>::NodeVec* node){

    char scelta = '0';

    if(!(node->HasParent())) std::cout<<"\n Attualmente sei sulla Root dell' albero \n";
    while(scelta != 'e'){

        std::cout<<"\n1. per spostarsi sul nodo sinistro \n";
        std::cout<<"2. per spostarsi sul nodo destro \n";
        std::cout<<"r. per spostarsi sul nodo padre \n";
        std::cout<<"3. per aggiungere un nodo \n";
        std::cout<<"4. per vedere il dato nella radice \n";
        std::cout<<"5. per vedere e rimuovere il dato nella radice\n";
        std::cout<<"6. per rimuovere nella radice  \n";
        std::cout<<"7. per cambiare la priorita' di un nodo \n";
        std::cout<<"e. per uscire \n";

        std::cout<<"\n\ncosa intendi fare ? \n";
        std::cin>>scelta;

        switch(scelta){
            case '1':
                if(node->HasLeftChild()){
                    floatRecursivePQueueNavigate(Pqueue,&node->LeftChild());
                    std::cout<<"Mi sposto sul nodo sinistro...";
                }
                else std::cout<<"Tale nodo non ha un figlio sinistro.";
            case '2':
                if(node->HasRightChild()){
                    floatRecursivePQueueNavigate(Pqueue,&node->RightChild());
                    std::cout<<"Mi sposto sul nodo destro...";
                }
                else std::cout<<"Tale nodo non ha un figlio destro.";
            case 'r':
                if(node->HasParent()) {
                    std::cout << "Mi sposto sul nodo padre...";
                    return;
                }else std::cout<<"Tale nodo non ha un nodo padre.";
                break;
            case '3':
                float item;
                std::cout<<"Che valore deve avere il nuovo nodo ? \n";
                std::cin>>item;
                Pqueue->Insert(item);
                break;
            case '4':
                try{
                std::cout<<"Il dato nella radice e' : "<<Pqueue->Tip()<<"\n\n";
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
                try{
                std::cout<<"Rimozione della radice...\n";
                Pqueue->RemoveTip();
                }
                catch (std::length_error err){
                    std::clog<<err.what()<<"\n";
                }
                break;
            case '7':
                float val;
                std::cout<<"** CHANGE PRIORITY **";
                std::cout<<"Quale valore vuoi che sovrascriva il nodo che attualmente stai visitando ? \n";
                std::cin>>val;
                Pqueue->ChangePriority(*node,val);
                std::cout<<"Ricostruzione del MinHeap...";
                break;
            case 'e':
                std::cout << " Esco dalla navigazione nodi... \n";
                return;
            default:
                std::cout<<"carattere non valido.";
        }
    }


}


template <typename Data>
void floatTreePQueueNavigation(lasd::PriorityQueue<Data>* Pqueue){
    floatRecursivePQueueNavigate(Pqueue,&Pqueue->Root());
}



template <typename Data>
void stringRecursivePQueueNavigate(lasd::PriorityQueue<Data>* Pqueue,typename lasd::BinaryTreeVec<Data>::NodeVec* node){

    char scelta = '0';

    if(!(node->HasParent())) std::cout<<"\n Attualmente sei sulla Root dell' albero \n";

    while(scelta != 'e'){

        std::cout<<"\n1. per spostarsi sul nodo sinistro \n";
        std::cout<<"2. per spostarsi sul nodo destro \n";
        std::cout<<"r. per spostarsi sul nodo padre \n";
        std::cout<<"3. per aggiungere un nodo \n";
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
                    stringRecursivePQueueNavigate(Pqueue,&node->LeftChild());
                    std::cout<<"Mi sposto sul nodo sinistro...";
                }
                else std::cout<<"Tale nodo non ha un figlio sinistro.";
            case '2':
                if(node->HasRightChild()){
                    stringRecursivePQueueNavigate(Pqueue,&node->RightChild());
                    std::cout<<"Mi sposto sul nodo destro...";
                }
                else std::cout<<"Tale nodo non ha un figlio destro.";
            case 'r':
                if (node->HasParent()) {
                    std::cout << "Mi sposto sul nodo padre...";
                    return;
                } else std::cout << "Tale nodo non ha un nodo padre.";
                break;
            case '3': {
                std::string item;
                std::cout << "Che valore deve avere il nuovo nodo ? \n";
                std::cin >> item;
                Pqueue->Insert(item);
                break;
            }
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
            case '7':{
                std::string val;
                std::cout << "** CHANGE PRIORITY **";
                std::cout << "Quale valore vuoi che sovrascriva il nodo che attualmente stai visitando ? \n";
                std::cin >> val;
                Pqueue->ChangePriority(*node, val);
                std::cout << "Ricostruzione del MinHeap...";
                break;
            }
            case 'e':
                std::cout << " Esco dalla navigazione nodi... \n";
                return;
            default:
                std::cout<<"carattere non valido.";
        }
    }


}


template <typename Data>
void stringTreePQueueNavigation(lasd::PriorityQueue<Data>* Pqueue){
    stringRecursivePQueueNavigate(Pqueue,&Pqueue->Root());
}

