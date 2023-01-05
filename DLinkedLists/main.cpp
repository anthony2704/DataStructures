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
        return -1;
    }

    bool removeItem(int element)
    {
        return false;
    }

    int get(int index)
    {
        return -1;
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

int main()
{ 	
    IntDLinkedList list;
    int size = 10;
    for (int index = 0; index < size; index++) {
        list.add(list.size(), index);
    }

    list.print();
}