#include <iostream>
using namespace std;

class IntDLinkedList
{
private:
    class Node;

private:
    Node *head;
    Node *tail;
    int count;

public:
    IntDLinkedList() : head(NULL), tail(NULL), count(0) {}

public:
    void add(int element) // at end
    {
        Node* pNew = new Node(element);

        if(head == NULL)
        {
            head = tail = pNew;
        }
        // else
        // {
        //     pNew->next = head;
        //     head->prev = pNew;
        //     head= pNew;
        // }
        else
        {
            pNew->prev = tail;
            tail->next = pNew;
            tail = pNew;
        }

        count++;
    }

    void add(int index, int element)
    {
        Node* pNew = new Node(element);

        if(head == NULL)
        {
            head = tail = pNew;
            count++;
        }
        else if(index == 0)
        {
            pNew->next = head;
            head->prev = pNew;
            head = pNew;
            count++;
        }
        else if(index == count)
        {
            add(element);
        }
        else
        {
            Node* pNext = head;
            Node* pPre = head;

            for(int i = 0; i < index - 1; i++)
            {
                pPre = pPre->next;
                pNext = pNext->next->next;
            }

            pNew->prev = pPre;
            pPre->next = pNew;
            pNew->next = pNext;
            pNext->prev = pNew;

            count++;
        }
    }

    int removeAt(int index)
    {
        Node* pCurr = new Node();

        if(index == 0)
        {
            pCurr = head;
            head = head->next;

            return pCurr->value;
            free(pCurr);
        }
        else if(index == count - 1)
        {
            Node* pPre = head;
            Node* pCurr = head;

            for(int i = 0; i < index - 1; i++)
            {
                pPre = pPre->next;
            }
            pCurr = pPre->next;
            pPre->next = NULL;
            tail = pPre;
            return(pCurr->value);
            free(pPre);
        }
        else
        {
            Node* pPre = head;
            Node* pCurr = head;

            for(int i = 0; i < index - 1; i++)
            {
                pPre = pPre->next;
            }
            pCurr = pPre->next;
            pPre->next = pCurr->next;
            pCurr->next->prev = pPre;
            return(pCurr->value);
            free(pCurr);
        }
        
        count--;
    }

    bool removeItem(int element)
    {
        return false;
    }

    int get(int index)
    {
        Node* pTemp = new Node();

        if(index <= count / 2)
        {
            pTemp = head;

            for(int i = 0; i < index; i++)
            {
                pTemp = pTemp->next;
            }
        }
        else
        {
            pTemp = tail;

            for(int i = 0; i < count - 1 - index; i++)
            {
                pTemp = pTemp->prev;
            }
        }

        return pTemp->value;
    }

    void set(int index, int element)
    {
        
    }

    int indexOf(int element)
    {
        return -1;
    }

    bool contains(int element)
    {
        return false;
    }

    int size()
    {
        return count;
    }

    bool empty()
    {
        return false;
    }

    void clear()
    {
        
    }
    
    void print()
    {
        Node* pCurr = head;
        while(pCurr != NULL)
        {
            cout << pCurr->value;
            pCurr = pCurr->next;
        }
    }

    ~IntDLinkedList()
    {
        this->clear();
    }

    private:
    class Node
    {
        public:
            int value;
            Node *prev;
            Node *next;
            Node(int value = 0, Node *prev = NULL, Node *next = NULL) 
            : value(value), prev(prev), next(next) {}
    };
};

class IntStack
{
private:
    IntDLinkedList *list;
public:
    IntStack()
    {
        this->list = new IntDLinkedList();
    }
    ~IntStack()
    {
        delete this->list;
    }

public:
    void push(int element)
    {
        this->list->add(0,element);
    }

    int pop()
    {
        int size = this->list->size();
        return this->list->removeAt(size - 1);
    }

    int top()
    {
        return -1;
    }

    int size()
    {
        return this->list->size();
    }

    bool empty()
    {
        return false;
    }

    int search(int element)
    {
        return -1;
    }
};