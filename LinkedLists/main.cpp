#include <iostream>

using namespace std;

template <typename T> class IntSLinkedList {
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
            Node(): next(NULL) {}
            Node(T data = 0){
                T data = 0;
                //this->next = NULL;
                next(NULL);
            }
    };

public:
    void insert(const T& it){
        Node* pNew = new Node(it);
        
        /*
        2 cases:
        case 1: empty list
        case 2: non-empty list
        */ 

        // case 1
        if(head == NULL){
            head = tail = pNew;
        }
        else{ // case2
            tail->next = pNew;
            tail = pNew;
        }

        count++;
    }

    void add(T index, T element){
        Node* pNew = new Node(element);

        if(count == 0)
        {
            head = tail = pNew;
            count++;
        }

        if(index == count)
        {
            insert(element);
        }
        else if(index == 0){
            pNew->next = head;
            head = pNew;
        }
        else{
            Node* pCurrent = head;

            for(int i = 0; i < index - 1; i++){
                pCurrent = pCurrent->next;
            }

            pNew->next = pCurrent->next;
            pCurrent->next = pNew;
        }

        count++;
    }

    int removeAt(T index) {

        Node* pTemp = new Node();

        if(index == 0){
            pTemp = head;
            head = head->next;
            free(pTemp);
        }
        else if(index == count){
            Node* pPre = head;
            
            for(int i = 0; i < count - 1; i++)
            {
                pPre = pPre->next;
            }
            pPre->next = NULL;
            tail = pPre;
            free(pPre);
        }
        else{
            Node* pTemp = head;
            Node* pPre = head;

            for(int i = 0; i < index - 1; i++)
            {
                pPre = pPre->next;
            }
            pTemp = pPre->next;
            pPre->next = pTemp->next;
            free(pTemp);
        }

        count--;
    }

    bool removeItem(int item) {

        return false;
    }

    bool empty() {

        return false;
    }

    int size() {

        return count;
    }
    
    int get(int index) {
        return -1;
    }

    void set(int index, int element) {

    }

    int indexOf(int item) {
        return -1;
    }

    bool contains(int item) {
        return false;
    }
    
    void clear() {

    }
    
    string toString();
};