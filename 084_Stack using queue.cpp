// Using 2 Queues 

// Time Complexity -> O(n) push, O(1) pop
// Space Complexity -> O(2N) ~ O(N)


class Stack {
	// Define the data members.

   queue<int> q1, q2;

   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.

        return q1.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.

        return q1.empty();

    }

    void push(int element) {
        // Implement the push() function.

        q2.push(element);

        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }

    int pop() {
        // Implement the pop() function.

        if (!q1.empty()) {

          int top = q1.front();

          q1.pop();

          return top;
        }
        return -1;

    }

    int top() {
        // Implement the top() function.

        if(!q1.empty())
            return q1.front();

        return -1;
    }
};


// Using Single Queue

// Time Complexity -> O(n) push, O(1) pop
// Space Complexity -> O(N)

class Stack {
	// Define the data members.

    queue<int> q;

   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.

        return q.size();
        
    }

    bool isEmpty() {
        // Implement the isEmpty() function.

        return q.empty();
        
    }

    void push(int element) {
        // Implement the push() function.

        q.push(element);

        for(int i = 0; i < q.size()-1; ++i)
        {
            q.push(q.front());
            q.pop();
        }
        
    }

    int pop() {
        // Implement the pop() function.
        if(!isEmpty())
        {
            int ans = q.front();
            q.pop();
            return ans;
        }

        return -1;
    }

    int top() {
        // Implement the top() function.
        if(!isEmpty())
        {
            return q.front();
        }
        return -1;
    }
};
