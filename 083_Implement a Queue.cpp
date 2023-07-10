// From Scratch

#include <bits/stdc++.h> 
class Queue {

private:
   int *arr;
   int qfront;
   int rear;
   int size;

public:
    Queue() {
        // Implement the Constructor
        size = 5001;

        arr = new int[size];

        qfront = rear = 0;

    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function

        return (rear == qfront ? 1 : 0);
    }

    void enqueue(int data) {
        // Implement the enqueue() function

        if (rear != size) {
          arr[rear] = data;
          ++rear;
        }
    }

    int dequeue() {
        // Implement the dequeue() function

       if(rear == qfront)
       {
           return -1;
       }
       else
       {
           int ans = arr[qfront];

           ++qfront;

           if(qfront == rear){
               qfront = rear = 0;
           }
           return ans;
       }
        

    }

    int front() {
        // Implement the qfront() function

        if(qfront == rear)
            return -1;
        return arr[qfront];
    }
};

// Using Vector

#include <bits/stdc++.h> 
class Queue {

private:
   vector<int> v;

public:
    Queue() {
        // Implement the Constructor

    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function

        return v.empty();
    }

    void enqueue(int data) {
        // Implement the enqueue() function

        v.push_back(data);

    }

    int dequeue() {
        // Implement the dequeue() function

        int ans = -1;

        if(!v.empty())
        {
            ans = v[0];
            v.erase(v.begin());
        }


        return ans;

    }

    int front() {
        // Implement the front() function

        if(!v.empty())
            return v[0];
        return -1;
    }
};
