#ifndef  __E_DEQUE__
#define  __E_DEQUE__

#include "Deque.H"

using namespace standardTemplates;

template <class T>
class EDeque : public Deque<T> {
public:
    EDeque();
    ~EDeque();
    void AddElementAt(unsigned long int posParm, T& dataParm);
    void RemoveElementAt(unsigned long int posParm);
};

template <class T>
EDeque<T>::EDeque():Deque<T>::Deque(){

}

template <class T>
EDeque<T>::~EDeque(){
    
}

template <class T>
void EDeque<T>::AddElementAt(unsigned long int posParm, T& dataParm) {
    //Deque<T>::operator[](posParm) = dataParm;
    Node<T>* sCurrentNode =  this->mHead;
    uint64_t idx = 0;
    if (this->mSize > 0) {
        while((nullptr != sCurrentNode) && (idx < posParm)) {
            sCurrentNode = sCurrentNode->next;
            idx++;
        }
        Node<T> *tNode = new Node(dataParm);
        Node<T>* prevNode = sCurrentNode->prev;
        if (nullptr != prevNode) {
            prevNode->next = tNode;
        }
        tNode->next = sCurrentNode;
        sCurrentNode->prev = tNode;
        if (0 == idx) {
            this->mHead = tNode;
        }
        this->mSize++;
    }
    else {
        std::cout << "The Deque is empty" << std::endl;
    }
}

template <class T>
void EDeque<T>::RemoveElementAt(unsigned long int posParm) {
    Node<T>* sCurrentNode = this->mHead;
    uint64_t idx = 0;
    if (this->mSize > 0) {
        while((nullptr != sCurrentNode) && (idx < posParm)) {
            sCurrentNode = sCurrentNode->next;
            idx++;
        }
        Node<T>* prevNode = sCurrentNode->prev;
        if (nullptr != prevNode) {
            if (nullptr != sCurrentNode->next) { //in case current node is last node in the list
                prevNode->next = sCurrentNode->next;
                sCurrentNode->next->prev = prevNode;
            }
        }
        else {
            this->mHead = sCurrentNode->next;
            sCurrentNode->next->prev = nullptr;
        }
        delete sCurrentNode;
        this->mSize--;
    }
    else {
        std::cout << "The Deque is empty" << std::endl;
    }
}

#endif