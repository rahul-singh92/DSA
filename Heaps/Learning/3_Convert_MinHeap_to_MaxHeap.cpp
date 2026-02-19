#include <iostream>
#include <algorithm>
using namespace std;

class BinaryHeap
{
public:
    int capacity; // Max elements that can be stored in heap
    int size;     // Current size of the heap
    int *arr;     // Array for storing the keys

    BinaryHeap(int cap)
    {
        capacity = cap; // Assign the capacity

        size = 0; // currently 0 size

        arr = new int[capacity]; // creating new array
    }

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int left(int i)
    {
        return 2 * i + 1;
    }

    int right(int i)
    {
        return 2 * i + 2;
    }

    void Insert(int x)
    {
        if (size == capacity)
        {
            cout << "Binary Heap Overflow" << endl;
            return;
        }

        // Insert new element at end
        arr[size] = x;

        // Store index to check heap property
        int k = size;

        // Increase the size
        size++;

        // Fix the min Heap Property
        while (k != 0 && arr[parent(k)] > arr[k])
        {
            swap(&arr[parent(k)], &arr[k]);
            k = parent(k);
        }
    }

    void Heapify(int ind)
    {
        // Right child
        int ri = right(ind);

        // Left Child
        int li = left(ind);

        // Assume violated value is minimum
        int smallest = ind;

        if (li < size && arr[li] < arr[smallest])
        {
            smallest = li;
        }

        if (ri < size && arr[ri] < arr[smallest])
        {
            smallest = ri;
        }

        // If the minimum among the three nodes is not the parent itsel
        // then swap and call heapify rescursively

        if (smallest != ind)
        {
            swap(&arr[ind], &arr[smallest]);
            Heapify(smallest);
        }
    }

    void MaxHeapify(int i)
    {
        int li = left(i);
        int ri = right(i);
        int largest = i;

        if (li < size && arr[li] > arr[largest])
        {
            largest = li;
        }
        if (ri < size && arr[ri] > arr[largest])
            largest = ri;

        if (largest != i)
        {
            swap(&arr[i], &arr[largest]);
            MaxHeapify(largest);
        }
    }
    void convertToMaxHeap()
    {
        for (int i = (size - 2) / 2; i >= 0; --i)
        {
            MaxHeapify(i);
        }
    }

    int getMin()
    {
        return arr[0];
    }

    int ExtractMin()
    {
        if (size <= 0)
            return INT_MAX;

        if (size == 1)
        {
            size--;
            return arr[0];
        }

        int mini = arr[0];

        // Copy the last node value to the root node
        arr[0] = arr[size - 1];

        size--;

        // Call Heapify at the root node
        Heapify(0);

        return mini;
    }

    void Decreasekey(int i, int val)
    {
        // update the neew value
        arr[i] = val;

        // Fix the min heap
        while (i != 0 && arr[parent(i)] > arr[i])
        {
            swap(&arr[parent(i)], &arr[i]);
            i = parent(i);
        }
    }

    void Delete(int i)
    {
        Decreasekey(i, INT_MIN);
        ExtractMin();
    }

    void swap(int *x, int *y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    BinaryHeap h(20);

    h.Insert(4);
    h.Insert(1);
    h.Insert(2);
    h.Insert(6);
    h.Insert(7);
    h.Insert(3);
    h.Insert(8);
    h.Insert(5);

    // cout << "Min value is " << h.getMin() << endl;

    // h.Insert(-1);
    // cout << "Min value is " << h.getMin() << endl;

    // h.Decreasekey(3, -2);
    // cout << "Min value is " << h.getMin() << endl;

    // h.ExtractMin();
    // cout << "Min value is " << h.getMin() << endl;

    // h.Delete(0);
    // cout << "Min value is " << h.getMin() << endl;
    h.print();
    h.convertToMaxHeap();
    h.print();
}