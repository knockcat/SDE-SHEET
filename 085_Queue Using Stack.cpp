// Time Complexity -> O(n) push O(1) pop, peek
// Space Complexity -> O(2N) ~ O(N)

// costly enQueue

class Queue {
    // Define the data members(if any) here.
    
    stack<int> st1, st2;

    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.

        while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }

        st1.push(val);

        while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }

    }

    int deQueue() {
        // Implement the dequeue() function.

        if(!st1.empty())
        {
            int ans = st1.top();
            st1.pop();
            return ans;
        }

        return -1;
    }

    int peek() {
        // Implement the peek() function here.
        if(!st1.empty())
        {
            return st1.top();
        }
        return -1;
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.

        return st1.empty();
    }
};

// Time Complexity -> O(1) push , worst O(n) or O(1) amortised pop, peek
// Space Complexity -> O(2N) ~ O(N)

// costly deQueue & peek O(n) but not in all instances and that's why we say it is O(1) amortised complexity

class Queue {
    // Define the data members(if any) here.

    stack<int> input, output;

    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        input.push(val);
    }

    int deQueue() {
        // Implement the dequeue() function.

        if(!output.empty())
        {
            int ans = output.top();
            output.pop();
            return ans;
        }
        else{
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
            
            if(output.empty())
                return -1;
            else
                return deQueue();
        }
        
    }

    int peek() {
        // Implement the peek() function here.

        if(!output.empty())
        {
            return output.top();
        }
        else{
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
            
            if(output.empty())
                return -1;
            return peek();
        }
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.

        return input.empty() && output.empty();
    }
};
