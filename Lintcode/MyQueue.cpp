class MyQueue {
public:
    stack<int> stack1;
    stack<int> stack2;

    MyQueue() {
        // do intialization if necessary
    }

    void push(int element) {
        // write your code here
        stack1.push(element);
        return;
    }

    int pop() {
        // write your code here
        int tmp, result;
        while (!stack1.empty()) {
          tmp = stack1.top();
          stack1.pop();
          stack2.push(tmp);
        }
        result = stack2.top();
        stack2.pop();

        while (!stack2.empty()) {
          tmp = stack2.top();
          stack2.pop();
          stack1.push(tmp);
        }

        return result;
    }

    int top() {
        // write your code here
        int tmp, result;
        while (!stack1.empty()) {
          tmp = stack1.top();
          stack1.pop();
          stack2.push(tmp);
        }
        result = stack2.top();

        while (!stack2.empty()) {
          tmp = stack2.top();
          stack2.pop();
          stack1.push(tmp);
        }

        return result;
    }
};
