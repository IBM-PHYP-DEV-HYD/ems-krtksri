#ifndef _DEQUE_H
#define _DEQUE_H

#include <iostream>

namespace standardTemplates
{
    enum DequeDirection {
        Reverse = -1,
        Forward = 1
    };

    enum ReturnTypes {
        Success = 0,
        Failure = 1
    };

    enum Numbers {
        MinusOne = -1,
        Zero = 0,
        One
    };

    template <typename T>
    struct Node
    {
        public:
            T data;
            Node* next;
            Node* prev;
            Node();
            Node(const T& data);
    };

    /* Creating doubly linked list to traverse back n forth */
    template <typename T>
    Node<T>::Node(const T& x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
    
    template <typename T>
    Node<T>::Node() {

    }

    template<class T>
    class Deque 
    {
        protected:
            Node<T> *mHead;
            Node<T> *mTail;
            size_t mSize;
        public:
            Deque();
            Deque(uint64_t length, T& data);
            Deque(const Deque<T>& dParm);
            ~Deque();
            void pushBack(const T &data);
            void pushBack(T &&data);
            void popBack();
            void pushFront(const T &data);
            void popFront();
            T& front();
            T& back();
            bool empty();
            size_t size();
            void resize(size_t sizeParm, T& defaultValParm, int DequeDirectionParm);
            void clear();
            T& operator[](int pos);
            T& operator=(const T& valueParm);
    };

    template <class T>
    Deque<T>::Deque(){
        mHead = nullptr;
        mTail = nullptr;
        mSize = 0;
    }

    template <class T>
    Deque<T>::Deque(const Deque<T>& dParm) {
        mHead = dParm.mHead;
        mTail = dParm.mTail;
        mSize = dParm.mSize;
    }

    template <class T>
    Deque<T>::~Deque() {
        Node<T> *sNodeTmp = mHead;
        Node<T> *sNextNode = nullptr;
        for (uint64_t idx = 0; idx < mSize; idx++) {
            sNextNode = sNodeTmp->next;
            delete sNodeTmp;
            sNodeTmp = sNextNode;
        }
        mHead = nullptr;
        mTail = nullptr;
        mSize = 0;
    }

    template <class T>
    Deque<T>::Deque(uint64_t length, T& x){
        Node<T>* pNode = nullptr;
        for (uint64_t idx = 0; idx < length; idx++) {
            Node<T>* tNode = new Node(x);
            tNode->prev = pNode;
            if (nullptr == pNode) {
                // Create the Node and assign to front as this is the first element
                pNode = tNode;
                mHead = mTail = pNode;
            }
            else {
                pNode->next = tNode;
                pNode = tNode;
                mTail = tNode;
            }
        }
        mSize = length;
    }

    template <class T>
    void Deque<T>::pushBack(const T& data) {
        Node<T> *tNode = new Node(data);
        Node<T> *pNode = mTail;
        if ((nullptr == mTail) && (nullptr == mHead)) {
            mTail = tNode;
            mHead = mTail;
            mSize++;
        }
        else {
            if (nullptr != tNode) {
                pNode->next = tNode;
                tNode->prev = pNode;
                mTail = tNode;
                mSize++;
            }
        }
    }

    //#if 1
    template <class T>
    void Deque<T>::pushBack(T &&data) {
        Node<T> *tNode = new Node(data);
        Node<T> *pNode = mTail;
        if ((nullptr == mTail) && (nullptr == mHead)) {
            mTail = tNode;
            mHead = mTail;
            mSize++;
        }
        else {
            if (nullptr != tNode) {
                pNode->next = tNode;
                tNode->prev = pNode;
                mTail = tNode;
                mSize++;
            }
        }
    }
    //#endif

    template <class T>
    void Deque<T>::popBack(){
        Node<T> *tNode = mTail;
        if (this->mSize > 0) {
            if (nullptr != tNode) {
                Node<T> *prevNode = tNode->prev;
                tNode->prev = nullptr;
                prevNode->next = nullptr;
                mTail = prevNode;
                delete tNode;
                mSize--;
            }
        }
        else {
            std::cout << "The Deque is empty" << std::endl;
        }
    }

    template <class T>
    void Deque<T>::pushFront(const T &data){
        Node<T> *tNode = new Node(data);
        if ((nullptr == mTail) && (nullptr == mHead)) {
            mTail = mHead = tNode;
            mSize++;
        }
        else {
            if (nullptr != tNode) {
                Node<T> *pNode = mHead;
                tNode->next = pNode;
                pNode->prev = tNode;
                mHead = tNode;
                mSize++;
            }
        }
    }

    #if 0
    template <class T>
    void Deque<T>::pushFront(T &&data){
        Node<T> *tNode = new Node(data);
        if (nullptr != tNode) {
            Node<T> *pNode = mHead;
            tNode->next = pNode;
            pNode->prev = tNode;
            mHead = tNode;
            mSize++;
        }
    }
    #endif

    template <class T>
    void Deque<T>::popFront(){
        Node<T> *tNode = mHead;
        if (this->mSize > 0) {
            if (nullptr != tNode) {
                Node<T> *nextNode = tNode->next;
                tNode->prev = nullptr;
                mHead = nextNode;
                delete tNode;
                mSize--;
            }
        }
        else {
            std::cout << "The Deque is empty" << std::endl;
        }
    }
    template <class T>
    T& Deque<T>::front(){
        return mHead->data;
    }
    
    template <class T>
    T& Deque<T>::back(){
        return mTail->data;
    }

    template <class T>
    bool Deque<T>::empty(){
        return (nullptr == mHead) ? true : false;
    }

    template <class T>
    size_t Deque<T>::size(){
        return mSize;
    }

    template <class T>
    void Deque<T>::resize(size_t sizeParm, T& defaultValParm, int DequeDirectionParm){
        size_t sResultingSize = Numbers::Zero;
        /* Increasing the size */
        if (mSize < sizeParm) {
            sResultingSize = sizeParm - mSize;
            if (DequeDirection::Forward == (DequeDirection)DequeDirectionParm) {
                for (int sIdx = 0; sIdx < sResultingSize; sIdx++) {
                    pushBack(defaultValParm);
                }
            }
            else if (DequeDirection::Reverse == (DequeDirection)DequeDirectionParm) {
                for (int sIdx = 0; sIdx < sResultingSize; sIdx++) {
                    pushFront(defaultValParm);
                }
            }
            else {
                std::cout << "Invalid DequeDirection" << std::endl;
            }
        }
        else { /* Dicreasing the size */
            sResultingSize = mSize - sizeParm;
            if (DequeDirection::Forward == (DequeDirection)DequeDirectionParm) {
                for (int sIdx = 0; sIdx < sResultingSize; sIdx++) {
                    popBack();
                }
            }
            else if (DequeDirection::Reverse == (DequeDirection)DequeDirectionParm) {
                for (int sIdx = 0; sIdx < sResultingSize; sIdx++) {
                    popFront();
                }
            }
            else {
                std::cout << "Invalid DequeDirection" << std::endl;
            }
        }
    }

    template <class T>
    void Deque<T>::clear(){
        Node<T>* sTempNode = mHead;
        Node<T>* sBckupNode = nullptr;
        if (this->mSize > 0) {
            while(nullptr != sTempNode) {
                sBckupNode = sTempNode->next;
                if (nullptr != sBckupNode) {
                    sBckupNode->prev = nullptr;
                }
                delete sTempNode;
                mSize--;
                sTempNode = sBckupNode;
            }
            mHead = nullptr;
            mTail = nullptr;
        }
        else {
            std::cout << "The Deque is empty" << std::endl;
        }
    }

    template <class T>
    T& Deque<T>::operator[](int pos){
        Node<T>* sTempNode = mHead;
        uint64_t idx = 0;
        if (this->mSize > 0) {
            while((nullptr != sTempNode) && (idx < pos)) {
                sTempNode = sTempNode->next;
                idx++;
            }
        }
        else {
            std::cout << "The Deque is empty" << std::endl;
        }
        return sTempNode->data;
    }

    template <class T>
    T& Deque<T>::operator=(const T& valueParm){
        T sVal;
        sVal = valueParm;
        return sVal;
    }
}
#endif