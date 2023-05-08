#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"
template<class T>
class Heap {
protected:
    T* elements;
    int capacity;
    int count;
public:
    Heap()
    {
        this->capacity = 10;
        this->count = 0;
        this->elements = new T[capacity];
    }
    ~Heap()
    {
        delete[]elements;
    }
    void push(T item);
    bool isEmpty();
    bool contains(T item);
    T peek();
    bool pop();
    int size();
    
    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]\n";
    }
private:
    void ensureCapacity(int minCapacity);
    void reheapUp(int position);
    void reheapDown(int position);
};
//Your code goes here

/****************************************/
/*          Public function            */
/**************************************/
template<class T>
int Heap<T>::size()
{
    return count;
}

template<class T>
bool Heap<T>::isEmpty()
{
    return this->count = 0;
}

template<class T>
bool Heap<T>::contains(T item){
    bool found = false;

    for(int i = 0; i < count - 1; i++)
    {
        if(elements[i] == item)
        {
            found = true;
        }
    }

    return found;
}

template<class T>
T Heap<T>::peek()
{
    return elements[0];
}

template<class T>
bool Heap<T>::pop()
{
    if(count == 0) return -1;

    T item = elements[0];
    elements[0] = elements[count - 1];
    count -= 1;
    reheapDown(0);
    return item;
}

template<class T>
void swap(T* a, T* b)
{
    T* item = a;
    a = b;
    b = item;
}

/****************************************/
/*          Private function           */
/**************************************/