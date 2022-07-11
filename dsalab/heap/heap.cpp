#include <bits/stdc++.h>
using namespace std;
template <class T>
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
    int getItem(T item);
    void remove(T item);
    void clear();
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

// Your code here
template<class T>
int Heap<T>::getItem(T item) {
    // TODO: return the index of item in heap
    for(int i = 0; i < count; i++){
        if(item == elements[i]) return i;
    }
    return -1;
}
template<class T>
void heapify(T* a , int i, int limit){
        int left = (2*i)+1;
        int right = (2*i) + 2;
        int next = i;

        if(left <= limit && a[left] > a[i])
            next = left;
        if(right <= limit && a[right] > a[next] )
            next = right;

        if(next!=i)
        {
            swap(a, next, i);
            heapify(a, next, limit);
        }
}
template<class T>
void swap(T* a , int i, int k){
    T temp = a[k];
    a[k] = a[i];
    a[i] = temp;
}
template<class T>
void Heap<T>::remove(T item) {
    // TODO: remove the element with value equal to item
    
    int s = getItem(item);
    if(s == -1) return;
    swap(elements, s, count - 1);
    //T data = elements[0];
    heapify(elements, s, count - 2);
    count = count - 1;
   
    
    
    
}

template<class T>
void Heap<T>::clear() {
    // TODO: delete all elements in heap
    delete [] elements;
    count = 0;
    capacity = 0;
}
int main(){
    Heap<int> maxHeap;
int arr[] = {78, 67, 32, 56, 8, 23, 19, 45};
for (int i = 0; i < 8; i++)
    maxHeap.push(arr[i]);
maxHeap.remove(78);
maxHeap.printHeap();
}