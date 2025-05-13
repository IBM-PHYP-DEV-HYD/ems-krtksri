#ifndef  __E_DEQUE__
#define  __E_DEQUE__

#include "Deque.H"

using namespace standardTemplates;

template <class T>
class EDLL : public Deque<T> {
public:
    EDLL();
    ~EDLL();
    void AddElementAt(unsigned long int posParm, T& dataParm);
    void RemoveElementAt(unsigned long int posParm);
};

template <class T>
EDLL<T>::EDLL():Deque<T>::Deque(){

}

template <class T>
EDLL<T>::~EDLL(){
    
}

template <class T>
void EDLL<T>::AddElementAt(unsigned long int posParm, T& dataParm) {
    Node<T>* sCurrentNode =  this->mHead;
    uint64_t idx = 0;
    if (nullptr != this->mHead) {
        Node<T> *tNode = new Node(dataParm);
        this->mHead = tNode;
    }
    else if (this->mSize > 0) {
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
void EDLL<T>::RemoveElementAt(unsigned long int posParm) {
    Node<T>* sCurrentNode = this->mHead;
    uint64_t idx = 0;
    if (this->mSize > 0) {
        while((nullptr != sCurrentNode) && (idx < posParm)) {
            sCurrentNode = sCurrentNode->next;
            idx++;
        }
        
        if (nullptr != sCurrentNode->prev) {
            Node<T>* prevNode = sCurrentNode->prev;
            if (nullptr != sCurrentNode->next) { //in case current node is last node in the list
                prevNode->next = sCurrentNode->next;
                sCurrentNode->next->prev = prevNode;
            }
        }
        else {
            this->mHead = sCurrentNode->next;
            if (nullptr != this->mHead) {
                this->mHead->prev = nullptr;
            }
        }
        delete sCurrentNode;
        this->mSize--;
    }
    else {
        std::cout << "The Deque is empty" << std::endl;
    }
}

#endif