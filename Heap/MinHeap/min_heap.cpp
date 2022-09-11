/*
For designing min-heap we need to have size of arr, capacity of arr

eg:

         10
       /    \
      80     15
     /  \    /
    100  85  18

arr = [10, 80, 15, 100, 85, 18, _ , _ , _ , _]
size of arr = 6
cap = 10


*/

#include <bits/stdc++.h>
using namespace std;

class MinHeap{
    int *arr;
    int size;
    int cap;
    MinHeap(int c){
        arr = new int[c];
        size = 0;
        cap = c;
    }

    int getLeftIdx(int idx){
        return (2 * idx + 1);
    }
    int getRightIdx(int idx){
        return (2 * idx + 2);
    }
    int getParentIdx(int idx){
        return ((idx-1)/2);
    }

    void insert(int key)
    {
        if(size == cap)
            return;
        
        size += 1;
        arr[size - 1] = key;
        for (int curr = size - 1; curr != 0;)
        {
            int pr = getParentIdx(curr);
            if(pr <= arr[curr])
                break;
            swap(arr[curr], arr[pr]);
            curr = pr;
        }
    }

    // fix heap having one violation
    void min_heapify(int idx)
    {
        int l = getLeftIdx(idx);
        int r = getRightIdx(idx);
        int smallest = idx;

        if(l < size and arr[l] < arr[idx])
            smallest = l;
        if(r < size and arr[r] < arr[idx])
            smallest = r;
        
        if(smallest != idx){
            swap(arr[idx], arr[smallest]);
            min_heapify(smallest);
        }
    }

    // remove root/minimum value from heap 
    // returns the removed value 
    int extractMin(){
        if(size == 0)
            return -1e9;

        // we don't want min_heapify for only one node
        if(size == 1){
            size -= 1;
            return arr[0];
        }

        swap(arr[0], arr[size - 1]);
        size--;
        min_heapify(0);
        return arr[size];
    }

    // update
    void decreaseKey(int idx, int x)
    {
        arr[idx] = x;
        int curr = idx;
        while(curr != 0)
        {
            int pr = getParentIdx(curr);
            if (pr <= arr[curr])
                break;
            swap(arr[curr], arr[pr]);
            curr = pr;
        }
    }

    void deleteKey(int idx)
    {
        decreaseKey(idx, -1e9);
        int deletedKey = extractMin();
        cout << deletedKey << " has been deleted";
    }
};