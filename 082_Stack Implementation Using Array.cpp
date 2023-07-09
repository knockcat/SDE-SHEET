// From Scratch

#include <bits/stdc++.h> 
// Stack class.
class Stack {

private:
    int *arr;
    int size;
    int rear;    
    
public:
    
    Stack(int capacity) {
        // Write your code here.

        arr = new int[capacity];
        rear = 0;
        size = capacity;
    }

    void push(int num) {
        // Write your code here.
        if(rear != size)
        {
            arr[rear] = num;
            ++rear;
        }
    }

    int pop() {
        // Write your code here.
        if(rear != 0)
        {
            --rear;
            return arr[rear]   ;
        }

        return -1;
    }
    
    int top() {
        // Write your code here.

        if(rear != 0)
        {
            return arr[rear-1];
        }
        return -1;
    }
    
    int isEmpty() {
        // Write your code here.
        if(rear == 0)
            return true;
        return false;
    }
    
    int isFull() {
        // Write your code here.

        if(rear == size)
            return true;
        return false;
    }
    
};

// Using Vector

#include <bits/stdc++.h> 
// Stack class.
class Stack {

private:
    vector<int> v;
    int size;
    
public:
    
    Stack(int capacity) {
        // Write your code here.
        size = capacity;
    }

    void push(int num) {
        // Write your code here.
        if(v.size() != size)
            v.push_back(num);
    }

    int pop() {
        // Write your code here.

        int ans = -1;

        if(!v.empty())
        {
            ans = v.back();
            v.pop_back();
        }

        return ans;
    }
    
    int top() {
        // Write your code here.
        if(!v.empty())
            return v.back();
        return -1;
    }
    
    int isEmpty() {
        // Write your code here.
        return v.empty();
    }
    
    int isFull() {
        // Write your code here.
        return v.size() == size;
    }
    
};
