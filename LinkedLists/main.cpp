#include <iostream>

using namespace std;

// template <typename T> struct Node{
// public:
//     T element;
//     Node* next;
// };

template <typename T> class IList{
public:
    virtual void add(T e) = 0;
    virtual void add(int index, T e) = 0;
    virtual T removeAt (int index ) = 0;
    virtual bool removeItem (T item ) = 0;
    virtual bool empty () = 0;
    virtual int size () = 0;
    virtual void clear () = 0;
    virtual T get (int index ) = 0;
    virtual void set ( int index , T e) = 0;
    virtual int indexOf (T item ) = 0;
    virtual bool contains ( T item ) = 0;
    virtual string toString () = 0;
};

template <typename T> class IntSLinkedList : public IList <T> {
public:
    class Node;

protected:
    Node* head;
    Node* tail;
    int count; //size of list

public:
    IntSLinkedList():
        head(NULL) , tail(NULL), count(0) {};

public:
    class Node{
        T data;
        Node* next;
        
        public:
            Node(T data = 0){
                T data = 0;
                this->next = NULL;
            }
    };
};