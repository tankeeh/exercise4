

#include <iostream>
//#include "../stack/vec/stackvec.hpp"
//#include "../queue/vec/queuevec.hpp"
//#include "../stack/lst/stacklst.hpp"
//#include "../queue/lst/queuelst.hpp"
#include "../heap/heap.hpp"
#include "../priorityqueue/priorityqueue.hpp"
#include "RandomGens/RandomValues.hpp"
#include "./TreeUtils/TreeUtilsFunctions.hpp"
#include "./TreeUtils/treeNavFunctions/NavigateFunctions.hpp"
#include "../list/list.hpp"



template <typename Data>
void lasd::Heap<Data>::PrintArray(){
    for (int i =0; i<this->size; i++)
        std::cout<<this->tree[i]->Element()<<" "<< this->tree[i]->getIndex()<<std::endl;
}



/** MY TESTS **/



void testHeap(){

     /*
    lasd::List<int> lista;
    for (int i=0; i<30; i++){
        lista.InsertAtBack(12 - i);
    }*/



    lasd::Vector<int> vettore(7);
    for(int i=0;i<7;i++){
        vettore[i] = 12 -i;
    }


    lasd::Heap<int> linearHeap(vettore);
    std::cout<<"STAMPA"<<std::endl;

    linearHeap.PrintArray();

    std::cout<<"\n\n";
    linearHeap.Sort();
    linearHeap.PrintArray();

    std::cout<<"Heap ex "<<linearHeap.Exists(11);


}

void testPriorityQueue(){

    lasd::Vector<int> vettore(7);
    for(int i=0;i<7;i++){
        vettore[i] = 12 -i;
    }


    lasd::PriorityQueue<int> linearPQ(vettore);
    std::cout<<"STAMPA"<<std::endl;

    linearPQ.PrintArray();
    std::cout<<"\n\n";

    //std::cout<<"POST CHANGE PRIORITY < : \n\n";
    //linearPQ.ChangePriority(linearPQ.Root().RightChild(),2);
    //linearPQ.PrintArray();

    std::cout<<"POST CHANGE PRIORITY > : \n\n";
    linearPQ.ChangePriority(linearPQ.Root().RightChild(),1500);
    linearPQ.PrintArray();


    //linearPQ.Insert(3);
    //linearPQ.Sort();
    std::cout<<"\n\nLa testa dell' albero e' : "<<linearPQ.TipNRemove()<<"\n";
    linearPQ.PrintArray();

    std::cout<<"\n\n";


    //std::cout<<"POST CHANGE PRIORITY > : \n\n";
    //linearPQ.ChangePriority(linearPQ.Root().RightChild(),2);


    //linearPQ.Insert(0);
    //linearPQ.Insert(1);
    //linearPQ.Insert(2);

    //linearPQ.PrintArray();

    std::cout<<"SORT : \n\n";
    linearPQ.Sort();
    linearPQ.PrintArray();

    std::cout<<"\n\n";
    FunIntEx4ForBinaryTreeHeap(linearPQ);
    linearPQ.PrintArray();

    std::cout<<"Heap ex "<<linearPQ.Exists(1500);







}





/**BinaryTreeHeap**/


void BinaryTreeHeapInt(){
    char scelta = '0';
    int n;

        std::cout << "Quanti elementi deve contenere il vettore di generazione ? : \n";
        std::cin>>n;
        lasd::Vector<int> vettore(n);
        for(int i = 0;i<n;i++) vettore[i] = IntValueGenerator();

        std::cout << "\n\n ** Generazione albero Heap tramite un vettore... ** \n\n";

        lasd::Heap<int> heap(vettore);

        while (scelta != 'b') {
            std::cout << "\n\nCosa vuoi fare con il seguente MinHeap di interi? : \n";
            std::cout << "1. MapPreOrder Print. \n";
            std::cout << "2. MapPostOrder Print. \n";
            std::cout << "3. Exists. \n";
            std::cout << "4. Fold MoltiplicateIntSmallerThan. \n";
            std::cout << "5. Map n*(-1)^n. \n";
            std::cout << "6. Sort \n";


            std::cout << "b. tornare indietro. \n\n\n";

            std::cin >> scelta;

            switch (scelta) {

                case '1':
                    std::cout << " ** PREORDER PRINT ** \n\n";
                    PrintElementHeapPreOrder(heap);
                    break;
                case '2':
                    std::cout << " ** POSTORDER PRINT ** \n\n";
                    PrintElementHeapPostOrder(heap);
                    break;
                case '3':
                    std::cout << " ** EXISTS ** \n\n";
                    std::cout << "Inserire il valore di cui si vuole verificare l'esistenza : ";
                    int item;
                    std::cin >> item;
                    if(heap.Exists(item))std::cout<<"L'elemento e' presente nell' albero";
                    else std::cout<<"L'elemento e' assente nell' albero";
                    break;
                case '4':
                    std::cout << " ** FOLD MoltiplicateIntSmallerThan ** \n\n";
                    std::cout << "Inserire il valore con cui chiamare la Fold : ";
                    int elem;
                    std::cin >> elem;
                    std::cout<<"La moltiplicazione degli elementi minori di "<<elem<<" e' :"<<FoldTreeHeapIntMoltiplicateSmallerThan(elem, heap);
                    break;
                case '5':
                    std::cout << " ** MAP n*(-1)^n ** \n\n";
                    FunIntEx4ForBinaryTreeHeap(heap);
                    break;
                case '6':
                    std::cout << "\n\n ** SORT ** \n\n";
                    heap.Sort();
                    std::cout << "L'albero e' adesso ordinato totalmente. \n\n";
                    break;
                case 'b':
                    return;
                    break;
                default:
                    std::cout << " Hai inserito un codice non valido! riprovare : ";

            }

            }
    }

void BinaryTreeHeapFloat(){
    char scelta = '0';
    int n;

    std::cout << "Quanti elementi deve contenere il vettore di generazione ? : \n";
    std::cin>>n;
    lasd::Vector<float> vettore(n);
    for(int i = 0;i<n;i++) vettore[i] = FloatValueGenerator();

    std::cout << "\n\n ** Generazione albero Heap tramite un vettore... ** \n\n";

    lasd::Heap<float> heap(vettore);

    while (scelta != 'b') {
        std::cout << "\n\nCosa vuoi fare con il seguente MinHeap di float? : \n";
        std::cout << "1. MapPreOrder Print. \n";
        std::cout << "2. MapPostOrder Print. \n";
        std::cout << "3. Exists. \n";
        std::cout << "4. Fold SumFloatBiggerThan. \n";
        std::cout << "5. Map Opposite Float. \n";
        std::cout << "6. Sort \n";


        std::cout << "b. tornare indietro. \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** PREORDER PRINT ** \n\n";
                PrintElementHeapPreOrder(heap);
                break;
            case '2':
                std::cout << " ** POSTORDER PRINT ** \n\n";
                PrintElementHeapPostOrder(heap);
                break;
            case '3':
                std::cout << " ** EXISTS ** \n\n";
                std::cout << "Inserire il valore di cui si vuole verificare l'esistenza : ";
                float item;
                std::cin >> item;
                if(heap.Exists(item))std::cout<<"L'elemento e' presente nell' albero";
                else std::cout<<"L'elemento e' assente nell' albero";
                break;
            case '4':
                std::cout << " ** FOLD SumFloatBiggerThan ** \n\n";
                std::cout << "Inserire il valore con cui chiamare la Fold : ";
                float elem;
                std::cin >> elem;
                std::cout<<"La somma dei float maggiori di "<<elem<<" e' :"<<FoldTreeHeapFloatSumBiggerThan(elem, heap);
                break;
            case '5':
                std::cout << " ** MAP Opposite Float ** \n\n";
                NegatifyDataForBinaryTreeHeap(heap);
                break;
            case '6':
                std::cout << "\n\n ** SORT ** \n\n";
                heap.Sort();
                std::cout << "L'albero e' adesso ordinato totalmente. \n\n";
                break;
            case 'b':
                return;
            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }

    }
}

void BinaryTreeHeapString(){
    char scelta = '0';
    int n;

    std::cout << "Quanti elementi deve contenere il vettore di generazione ? : \n";
    std::cin>>n;
    lasd::Vector<std::string> vettore(n);
    for(int i = 0;i<n;i++) vettore[i] = CharValueGenerator();

    std::cout << "\n\n ** Generazione albero Heap tramite un vettore... ** \n\n";

    lasd::Heap<std::string> heap(vettore);

    while (scelta != 'b') {
        std::cout << "\n\nCosa vuoi fare con il seguente MinHeap di stringhe? : \n";
        std::cout << "1. MapPreOrder Print. \n";
        std::cout << "2. MapPostOrder Print. \n";
        std::cout << "3. Exists. \n";
        std::cout << "4. Fold StringConcatLowerEqualsThan. \n";
        std::cout << "5. Map InitialConcatString \n";
        std::cout << "6. Sort \n";


        std::cout << "b. tornare indietro. \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** PREORDER PRINT ** \n\n";
                PrintElementHeapPreOrder(heap);
                break;
            case '2':
                std::cout << " ** POSTORDER PRINT ** \n\n";
                PrintElementHeapPostOrder(heap);
                break;
            case '3': {
                std::cout << " ** EXISTS ** \n\n";
                std::cout << "Inserire il valore di cui si vuole verificare l'esistenza : ";
                std::string item;
                std::cin >> item;
                if (heap.Exists(item))std::cout << "L'elemento e' presente nell' albero";
                else std::cout << "L'elemento e' assente nell' albero";
                break;
            }
            case '4':
                std::cout << " ** FOLD StringConcatLowerEqualsThan ** \n\n";
                std::cout << "Inserire il valore con cui chiamare la Fold : ";
                int length;
                std::cin >> length;
                std::cout << "La concatenazione di stringhe con lunghezza minore o uguale a " << length << " e' :"
                          << FoldTreeHeapStringConcatLowerEqualsThan(length, heap);
                break;
            case '5':{
                std::cout << " ** MAP InitialConcatString ** \n\n";
                std::string par;
                std::cout << "Che sequenza vuoi concatenare all'inizio di ogni stringa dello heap ? \n";
                std::cin >> par;
                InitialConcatStringForBinaryTreeHeap(heap,&par);
                break;
             }
            case '6':
                std::cout << "\n\n ** SORT ** \n\n";
                heap.Sort();
                std::cout << "L'albero e' adesso ordinato totalmente. \n\n";
                break;
            case 'b':
                return;
            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }

    }
}

void BinaryTreeHeap(){
    char scelta = '0';

    while (scelta != 'e') {
        std::cout << "Vuoi testare : \n";
        std::cout << "1.Heap di interi. \n";
        std::cout << "2.Heap di float. \n";
        std::cout << "3.Heap di string. \n";

        std::cout<<"\nb. tornare indietro.\n";
        std::cout << "e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** HEAP DI INTERI ** \n\n";
                BinaryTreeHeapInt();
                break;
            case '2':
                std::cout << " ** HEAP DI FLOAT ** \n\n";
                BinaryTreeHeapFloat();
                break;
            case '3':
                std::cout << " ** HEAP DI STRINGHE ** \n\n";
                BinaryTreeHeapString();
                break;
            case 'b':
                return;
            case 'e':
                std::cout << " Il programma sta per chiudersi... \n";
                exit(0);

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }

    }
}





/**BinaryTreePriorityQueue**/






/*
void BinaryTreePQueueInt(){
    char scelta = '0';
    lasd::BinaryTreeVec<int> albero;

    while(scelta!= 'b' && scelta != '%') {
        std::cout << "Che tipo di albero vuoi generare? : \n";
        std::cout << "c. Completo. \n";
        std::cout << "s. degenere a sinistra. \n";
        std::cout << "d. degenere a destra. \n";
        std::cout << "b. tornare indietro. \n";



        std::cin >> scelta;

        switch (scelta) {

            case 'c': {
                std::cout << " ** Generazione albero completo... ** \n\n";
                albero.NewRoot(IntValueGenerator());
                albero.AddLeftChild(albero.Root(), IntValueGenerator());
                albero.AddRightChild(albero.Root(), IntValueGenerator());
                albero.AddLeftChild(albero.Root().LeftChild(), IntValueGenerator());
                albero.AddRightChild(albero.Root().LeftChild(), IntValueGenerator());
                albero.AddLeftChild(albero.Root().RightChild(), IntValueGenerator());
                albero.AddRightChild(albero.Root().RightChild(), IntValueGenerator());
                scelta = '%';

                break;
            }
            case 'd': {
                std::cout << " ** Generazione albero degenere destro... ** \n\n";
                albero.NewRoot(IntValueGenerator());
                typename lasd::BinaryTreeVec<int>::NodeVec *node = &albero.Root();
                std::cout << "quanti nodi vuoi inserire oltre la root? : ";
                int n;
                int i = 0;
                std::cin >> n;
                while (i < n) {
                    albero.AddRightChild(*node, IntValueGenerator());
                    node = &node->RightChild();
                    i++;
                }
                scelta = '%';
                break;
            }
            case 's': {
                std::cout << " ** Generazione albero degenere sinistro... ** \n\n";
                albero.NewRoot(IntValueGenerator());
                typename lasd::BinaryTreeVec<int>::NodeVec *node = &albero.Root();
                std::cout << "quanti nodi vuoi inserire oltre la root? : ";
                int n;
                int i = 0;
                std::cin >> n;
                while (i < n) {
                    albero.AddLeftChild(*node, IntValueGenerator());
                    node = &node->LeftChild();
                    i++;
                }
                scelta = '%';
                break;

            }
            case 'b':
                return;
            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";
        }
    }


    while (scelta != 'b') {
        std::cout << "\n\nCosa vuoi fare con il seguente BinaryTreeVec di interi? : \n";
        std::cout << "1. MapBreadth Print. \n";
        std::cout << "2. MapPreOrder Print. \n";
        std::cout << "3. MapInOrder Print. \n";
        std::cout << "4. MapPostOrder Print. \n";
        std::cout << "5. Exists. \n";
        std::cout << "6. Fold MoltiplicateIntSmallerThan. \n";
        std::cout << "7. Map TriplicateInt. \n";
        std::cout << "8. SottoTest: Navigazione sui nodi dell' albero. \n";


        std::cout << "b. tornare indietro. \n\n\n";


        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** BREADTH PRINT ** \n\n";
                PrintElementTreeBreadth(albero);
                break;
            case '2':
                std::cout << " ** PREORDER PRINT ** \n\n";
                PrintElementTreePreOrder(albero);
                break;
            case '3':
                std::cout << " ** INORDER PRINT ** \n\n";
                PrintElementTreeInOrder(albero);
                break;
            case '4':
                std::cout << " ** POSTORDER PRINT ** \n\n";
                PrintElementTreePostOrder(albero);
                break;
            case '5':
                std::cout << " ** EXISTS ** \n\n";
                std::cout << "Inserire il valore di cui si vuole verificare l'esistenza : ";
                int item;
                std::cin >> item;
                if(albero.Exists(item))std::cout<<"L'elemento e' presente nell' albero";
                else std::cout<<"L'elemento e' assente nell' albero";
                break;
            case '6':
                std::cout << " ** FOLD MoltiplicateIntSmallerThan ** \n\n";
                std::cout << "Inserire il valore con cui chiamare la Fold : ";
                int elem;
                std::cin >> elem;
                std::cout<<"La moltiplicazione degli elementi minori di "<<elem<<" e' :"<<FoldTreeIntMoltiplicateSmallerThan(elem, albero);
                break;
            case '7':
                std::cout << " ** MAP TriplicateInt ** \n\n";
                TriplicateIntForBinaryTree(albero);
                break;
            case '8':
                std::cout << " ** SOTTOTEST NODI ** \n\n";
                intTreeVecNavigation(&albero);
                break;
            case 'b':
                return;
            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }

    }
}

void BinaryTreeVecFloat(){

    char scelta = '0';
    lasd::BinaryTreeVec<float> albero;

    while(scelta!= 'b' && scelta != '%') {
        std::cout << "Che tipo di albero vuoi generare? : \n";
        std::cout << "c. Completo. \n";
        std::cout << "s. degenere a sinistra. \n";
        std::cout << "d. degenere a destra. \n";
        std::cout << "b. tornare indietro. \n";



        std::cin >> scelta;

        switch (scelta) {

            case 'c': {
                std::cout << " ** Generazione albero completo... ** \n\n";
                albero.NewRoot(FloatValueGenerator());
                albero.AddLeftChild(albero.Root(), FloatValueGenerator());
                albero.AddRightChild(albero.Root(), FloatValueGenerator());
                albero.AddLeftChild(albero.Root().LeftChild(), FloatValueGenerator());
                albero.AddRightChild(albero.Root().LeftChild(), FloatValueGenerator());
                albero.AddLeftChild(albero.Root().RightChild(), FloatValueGenerator());
                albero.AddRightChild(albero.Root().RightChild(), FloatValueGenerator());
                scelta = '%';

                break;
            }
            case 'd': {
                std::cout << " ** Generazione albero degenere destro... ** \n\n";
                albero.NewRoot(FloatValueGenerator());
                typename lasd::BinaryTreeVec<float>::NodeVec *node = &albero.Root();
                std::cout << "quanti nodi vuoi inserire oltre la root? : ";
                int n;
                int i = 0;
                std::cin >> n;
                while (i < n) {
                    albero.AddRightChild(*node, FloatValueGenerator());
                    node = &node->RightChild();
                    i++;
                }
                scelta = '%';
                break;
            }
            case 's': {
                std::cout << " ** Generazione albero degenere sinistro... ** \n\n";
                albero.NewRoot(FloatValueGenerator());
                typename lasd::BinaryTreeVec<float>::NodeVec *node = &albero.Root();
                std::cout << "quanti nodi vuoi inserire oltre la root? : ";
                int n;
                int i = 0;
                std::cin >> n;
                while (i < n) {
                    albero.AddLeftChild(*node, FloatValueGenerator());
                    node = &node->LeftChild();
                    i++;
                }
                scelta = '%';
                break;

            }
            case 'b':
                return;
            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";
        }
    }


    while (scelta != 'b') {
        std::cout << "\n\nCosa vuoi fare con il seguente BinaryTreeVec di float? : \n";
        std::cout << "1. MapBreadth Print. \n";
        std::cout << "2. MapPreOrder Print. \n";
        std::cout << "3. MapInOrder Print. \n";
        std::cout << "4. MapPostOrder Print. \n";
        std::cout << "5. Exists. \n";
        std::cout << "6. Fold FloatSumBiggerThan. \n";
        std::cout << "7. Map CubedFloat. \n";
        std::cout << "8. SottoTest: Navigazione sui nodi dell' albero. \n";


        std::cout << "b. tornare indietro. \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** BREADTH PRINT ** \n\n";
                PrintElementTreeBreadth(albero);
                break;
            case '2':
                std::cout << " ** PREORDER PRINT ** \n\n";
                PrintElementTreePreOrder(albero);
                break;
            case '3':
                std::cout << " ** INORDER PRINT ** \n\n";
                PrintElementTreeInOrder(albero);
                break;
            case '4':
                std::cout << " ** POSTORDER PRINT ** \n\n";
                PrintElementTreePostOrder(albero);
                break;
            case '5':
                std::cout << " ** EXISTS ** \n\n";
                std::cout << "Inserire il valore di cui si vuole verificare l'esistenza : ";
                float item;
                std::cin >> item;
                if(albero.Exists(item))std::cout<<"L'elemento e' presente nell' albero";
                else std::cout<<"L'elemento e' assente nell' albero";
                break;
            case '6':
                std::cout << " ** FOLD FloatSumBiggerThan ** \n\n";
                std::cout << "Inserire il valore con cui chiamare la Fold : ";
                float elem;
                std::cin >> elem;
                std::cout<<"La somma degli elementi maggiori di "<<elem<<" e' :"<<FoldTreeFloatSumBiggerThan(elem, albero);
                break;
            case '7':
                std::cout << " ** MAP CubedFloat ** \n\n";
                CubedFloatForBinaryTree(albero);
                break;
            case '8':
                std::cout << " ** SOTTOTEST NODI ** \n\n";
                floatTreeVecNavigation(&albero);
                break;
            case 'b':
                return;

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }

    }
}

void BinaryTreeVecString(){

    char scelta = '0';
    lasd::BinaryTreeVec<std::string> albero;

    while(scelta!= 'b' && scelta != '%') {
        std::cout << "Che tipo di albero vuoi generare? : \n";
        std::cout << "c. Completo. \n";
        std::cout << "s. degenere a sinistra. \n";
        std::cout << "d. degenere a destra. \n";
        std::cout << "b. tornare indietro. \n";

        std::cin >> scelta;

        switch (scelta) {

            case 'c': {
                std::cout << " ** Generazione albero completo... ** \n\n";
                albero.NewRoot(CharValueGenerator());
                albero.AddLeftChild(albero.Root(), CharValueGenerator());
                albero.AddRightChild(albero.Root(), CharValueGenerator());
                albero.AddLeftChild(albero.Root().LeftChild(), CharValueGenerator());
                albero.AddRightChild(albero.Root().LeftChild(), CharValueGenerator());
                albero.AddLeftChild(albero.Root().RightChild(), CharValueGenerator());
                albero.AddRightChild(albero.Root().RightChild(), CharValueGenerator());
                scelta = '%';

                break;
            }
            case 'd': {
                std::cout << " ** Generazione albero degenere destro... ** \n\n";
                albero.NewRoot(CharValueGenerator());
                typename lasd::BinaryTreeVec<std::string>::NodeVec *node = &albero.Root();
                std::cout << "quanti nodi vuoi inserire oltre la root? : ";
                int n;
                int i = 0;
                std::cin >> n;
                while (i < n) {
                    albero.AddRightChild(*node, CharValueGenerator());
                    node = &node->RightChild();
                    i++;
                }
                scelta = '%';
                break;
            }
            case 's': {
                std::cout << " ** Generazione albero degenere sinistro... ** \n\n";
                albero.NewRoot(CharValueGenerator());
                typename lasd::BinaryTreeVec<std::string>::NodeVec *node = &albero.Root();
                std::cout << "quanti nodi vuoi inserire oltre la root? : ";
                int n;
                int i = 0;
                std::cin >> n;
                while (i < n) {
                    albero.AddLeftChild(*node, CharValueGenerator());
                    node = &node->LeftChild();
                    i++;
                }
                scelta = '%';
                break;

            }
            case 'b':
                std::cout << " Program is gonna stop... \n";
                break;
            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";
        }
    }


    while (scelta != 'b') {
        std::cout << "\n\nCosa vuoi fare con il seguente BinaryTreeVec di stringhe? : \n";
        std::cout << "1. MapBreadth Print. \n";
        std::cout << "2. MapPreOrder Print. \n";
        std::cout << "3. MapInOrder Print. \n";
        std::cout << "4. MapPostOrder Print. \n";
        std::cout << "5. Exists. \n";
        std::cout << "6. Fold StringConcatLowerEqualsThan. \n";
        std::cout << "7. Map InitialConcatString. \n";
        std::cout << "8. SottoTest: Navigazione sui nodi dell' albero. \n";


        std::cout << "\n e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** BREADTH PRINT ** \n\n";
                PrintElementTreeBreadth(albero);
                break;
            case '2':
                std::cout << " ** PREORDER PRINT ** \n\n";
                PrintElementTreePreOrder(albero);
                break;
            case '3':
                std::cout << " ** INORDER PRINT ** \n\n";
                PrintElementTreeInOrder(albero);
                break;
            case '4':
                std::cout << " ** POSTORDER PRINT ** \n\n";
                PrintElementTreePostOrder(albero);
                break;
            case '5': {
                std::cout << " ** EXISTS ** \n\n";
                std::cout << "Inserire il valore di cui si vuole verificare l'esistenza : ";
                std::string item;
                std::cin >> item;
                if (albero.Exists(item))std::cout << "L'elemento e' presente nell' albero";
                else std::cout << "L'elemento e' assente nell' albero";
                break;
            }
            case '6': {
                std::cout << " ** FOLD StringConcatLowerEqualsThan ** \n\n";
                std::cout << "Inserire il valore con cui chiamare la Fold : ";
                int elem;
                std::cin>>elem;
                std::cout << "\"La concatenazione delle stringhe con lunghezza minore o uguale di \" " << elem<< " e' :" << FoldTreeStringConcatLowerEqualsThan(elem,albero);
                break;
            }
            case '7': {
                std::cout << " ** MAP InitialConcatString ** \n\n";
                std::string par;
                std::cout << "Che stringa vuoi concatenare all' inizio di ogni stringa? : ";
                std::cin >> par;
                InitialConcatStringForBinaryTree(albero, &par);
                break;
            }
            case '8':
                std::cout << " ** SOTTOTEST NODI ** \n\n";
                stringTreeVecNavigation(&albero);
                break;
            case 'b':
                return;
            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }

    }
}

void BinaryTreeVec(){
    char scelta = '0';

    while (scelta != 'e') {
        std::cout << "Vuoi testare : \n";
        std::cout << "1. BinaryTreeVec di interi. \n";
        std::cout << "2. BinaryTreeVec di float. \n";
        std::cout << "3. BinaryTreeVec di stringhe. \n";

        std::cout<<"\nb. tornare indietro.\n";
        std::cout << "\n e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** BINARYTREEVEC DI INTERI ** \n\n";
                BinaryTreeVecInt();
                break;
            case '2':
                std::cout << " ** BINARYTREEVEC DI FLOAT ** \n\n";
                BinaryTreeVecFloat();
                break;
            case '3':
                std::cout << " ** BINARYTREEVEC DI STRINGHE ** \n\n";
                BinaryTreeVecString();
                break;
            case 'b':
                return;
            case 'e':
                std::cout << " Il programma sta per chiudersi... \n";
                exit(0);

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";
                break;
        }

    }

}



*/


void BinaryTreePQueueInt(){
    char scelta = '0';
    int n;

    std::cout << "Quanti elementi deve contenere la lista di generazione ? : \n";
    std::cin>>n;
    lasd::List<int> lista;
    int i = 0;
    while(i<n){
        lista.InsertAtBack(IntValueGenerator());
        i++;
    }

    std::cout << "\n\n ** Generazione Priority Queue tramite una lista... ** \n\n";

    lasd::PriorityQueue<int> Pqueue(lista);

    while (scelta != 'b') {
        std::cout << "\n\nCosa vuoi fare con la seguente Priority Queue di interi? : \n";
        std::cout << "1. MapPreOrder Print. \n";
        std::cout << "2. MapPostOrder Print. \n";
        std::cout << "3. Exists. \n";
        std::cout << "4. Fold MoltiplicateIntSmallerThan. \n";
        std::cout << "5. Map n*(-1)^n. \n";
        std::cout << "6. Sort \n";
        std::cout << "7. Menu' navigazione nodi. \n";



        std::cout << "b. tornare indietro. \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** PREORDER PRINT ** \n\n";
                PrintElementHeapPreOrder(Pqueue);
                break;
            case '2':
                std::cout << " ** POSTORDER PRINT ** \n\n";
                PrintElementHeapPostOrder(Pqueue);
                break;
            case '3':
                std::cout << " ** EXISTS ** \n\n";
                std::cout << "Inserire il valore di cui si vuole verificare l'esistenza : ";
                int item;
                std::cin >> item;
                if(Pqueue.Exists(item))std::cout<<"L'elemento e' presente nell' albero";
                else std::cout<<"L'elemento e' assente nell' albero";
                break;
            case '4':
                std::cout << " ** FOLD MoltiplicateIntSmallerThan ** \n\n";
                std::cout << "Inserire il valore con cui chiamare la Fold : ";
                int elem;
                std::cin >> elem;
                std::cout<<"La moltiplicazione degli elementi minori di "<<elem<<" e' :"<<FoldTreeHeapIntMoltiplicateSmallerThan(elem, Pqueue);
                break;
            case '5':
                std::cout << " ** MAP n*(-1)^n ** \n\n";
                FunIntEx4ForBinaryTreeHeap(Pqueue);
                break;
            case '6':
                std::cout << "\n\n ** SORT ** \n\n";
                Pqueue.Sort();
                std::cout << "L'albero e' adesso ordinato totalmente. \n\n";
                break;
            case '7':
                std::cout << "\n\n ** NAVIGAZIONE TRA I NODI ** \n";
                std::cout<<"NOTA: per ritornare al menu' struttura occorre essere sulla Root dell' albero. \n\n";
                intTreePQueueNavigation(&Pqueue);
                break;
            case 'b':
                return;
            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }

    }
}

void BinaryTreePQueueFloat(){
    char scelta = '0';
    int n;

    std::cout << "Quanti elementi deve contenere la lista di generazione ? : \n";
    std::cin>>n;
    lasd::List<float> lista;
    int i = 0;
    while(i<n){
        lista.InsertAtFront(FloatValueGenerator());
        i++;
    }

    std::cout << "\n\n ** Generazione Priority Queue tramite una lista... ** \n\n";

    lasd::PriorityQueue<float> Pqueue(lista);

    while (scelta != 'b') {
        std::cout << "\n\nCosa vuoi fare con la seguente Priority Queue di float? : \n";
        std::cout << "1. MapPreOrder Print. \n";
        std::cout << "2. MapPostOrder Print. \n";
        std::cout << "3. Exists. \n";
        std::cout << "4. Fold SumFloatBiggerThan. \n";
        std::cout << "5. Map Opposite Float. \n";
        std::cout << "6. Sort. \n";
        std::cout << "7. Menu' navigazione nodi. \n";


        std::cout << "b. tornare indietro. \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** PREORDER PRINT ** \n\n";
                PrintElementHeapPreOrder(Pqueue);
                break;
            case '2':
                std::cout << " ** POSTORDER PRINT ** \n\n";
                PrintElementHeapPostOrder(Pqueue);
                break;
            case '3':
                std::cout << " ** EXISTS ** \n\n";
                std::cout << "Inserire il valore di cui si vuole verificare l'esistenza : ";
                float item;
                std::cin >> item;
                if(Pqueue.Exists(item))std::cout<<"L'elemento e' presente nell' albero";
                else std::cout<<"L'elemento e' assente nell' albero";
                break;
            case '4':
                std::cout << " ** FOLD SumFloatBiggerThan ** \n\n";
                std::cout << "Inserire il valore con cui chiamare la Fold : ";
                float elem;
                std::cin >> elem;
                std::cout<<"La somma dei float maggiori di "<<elem<<" e' :"<<FoldTreeHeapFloatSumBiggerThan(elem, Pqueue);
                break;
            case '5':
                std::cout << " ** MAP Opposite Float ** \n\n";
                NegatifyDataForBinaryTreeHeap(Pqueue);
                break;
            case '6':
                std::cout << "\n\n ** SORT ** \n\n";
                Pqueue.Sort();
                std::cout << "L'albero e' adesso ordinato totalmente. \n\n";
                break;
            case '7':
                std::cout << "\n\n ** NAVIGAZIONE TRA I NODI ** \n\n";
                std::cout<<"NOTA: per ritornare al menu' struttura occorre essere sulla Root dell' albero. \n\n";
                floatTreePQueueNavigation(&Pqueue);
                break;
            case 'b':
                return;
            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }

    }
}

void BinaryTreePQueueString(){
    char scelta = '0';
    int n;

    std::cout << "Quanti elementi deve contenere la lista di generazione ? : \n";
    std::cin>>n;
    lasd::List<std::string> lista;
    int i = 0;
    while(i<n){
        lista.InsertAtFront(CharValueGenerator());
        i++;
    }

    std::cout << "\n\n ** Generazione Priority Queue tramite una lista... ** \n\n";

    lasd::PriorityQueue<std::string> Pqueue(lista);

    while (scelta != 'b') {
        std::cout << "\n\nCosa vuoi fare con la seguente Priority Queue di float? : \n";
        std::cout << "1. MapPreOrder Print. \n";
        std::cout << "2. MapPostOrder Print. \n";
        std::cout << "3. Exists. \n";
        std::cout << "4. Fold StringConcatLowerEqualsThan. \n";
        std::cout << "5. Map InitialConcatString. \n";
        std::cout << "6. Sort. \n";
        std::cout << "7. Menu' navigazione nodi. \n";


        std::cout << "b. tornare indietro. \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** PREORDER PRINT ** \n\n";
                PrintElementHeapPreOrder(Pqueue);
                break;
            case '2':
                std::cout << " ** POSTORDER PRINT ** \n\n";
                PrintElementHeapPostOrder(Pqueue);
                break;
            case '3':{
                std::cout << " ** EXISTS ** \n\n";
                std::cout << "Inserire il valore di cui si vuole verificare l'esistenza : ";
                std::string item;
                std::cin >> item;
                if (Pqueue.Exists(item))std::cout << "L'elemento e' presente nell' albero";
                else std::cout << "L'elemento e' assente nell' albero";
                break;
            }
            case '4':
                std::cout << " ** FOLD StringConcatLowerEqualsThan ** \n\n";
                std::cout << "Inserire il valore con cui chiamare la Fold : ";
                int length;
                std::cin >> length;
                std::cout<<"La concatenazione di stringhe con lunghezza minore o uguale a "<<length<<" e' :"<<FoldTreeHeapStringConcatLowerEqualsThan(length, Pqueue);
                break;
            case '5':{
                std::cout << " ** MAP InitialConcatString ** \n\n";
                std::string par;
                std::cout << "Che sequenza vuoi concatenare all'inizio di ogni stringa della Priority Queue? \n";
                std::cin >> par;
                InitialConcatStringForBinaryTreeHeap(Pqueue,&par);
                break;
            }
            case '6':
                std::cout << "\n\n ** SORT ** \n\n";
                Pqueue.Sort();
                std::cout << "L'albero e' adesso ordinato totalmente. \n\n";
                break;
            case '7':
                std::cout << "\n\n ** NAVIGAZIONE TRA I NODI ** \n\n";
                std::cout<<"NOTA: per ritornare al menu' struttura occorre essere sulla Root dell' albero. \n\n";
                stringTreePQueueNavigation(&Pqueue);
                break;
            case 'b':
                return;
            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }

    }
}


void BinaryTreePriorityQueue(){
    char scelta = '0';

    while (scelta != 'e') {
        std::cout << "Vuoi testare : \n";
        std::cout << "1.Priority Queue di interi. \n";
        std::cout << "2.Priority Queue di float. \n";
        std::cout << "3.Priority Queue di string. \n";

        std::cout<<"\nb. tornare indietro.\n";
        std::cout << "e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** PRIORITY QUEUE DI INTERI ** \n\n";
                BinaryTreePQueueInt();
                break;
            case '2':
                std::cout << " ** PRIORITY QUEUE DI FLOAT ** \n\n";
                BinaryTreePQueueFloat();
                break;
            case '3':
                std::cout << " ** PRIORITY QUEUE DI STRINGHE ** \n\n";
                BinaryTreePQueueString();
                break;
            case 'b':
                return;
            case 'e':
                std::cout << " Il programma sta per chiudersi... \n";
                exit(0);

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }

    }
}





void mytest() {

    char scelta = '0';

    while (scelta != 'e') {
        std::cout << "Prego, inserire : \n";
        std::cout << "1. per testare un Albero Heap. \n";
        std::cout << "2. per testare una Priority Queue. \n";

        std::cout<<"\nb. tornare indietro.\n";
        std::cout << "e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** TEST Heap ** \n\n";
                BinaryTreeHeap();
                break;
            case '2':
                std::cout << " ** TEST Priority Queue ** \n\n";
                BinaryTreePriorityQueue();
                break;
            case 'b':
                return;
            case 'e':
                std::cout << "Il programma sta per chiudersi... \n";
                exit(0);

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }

    }
}








