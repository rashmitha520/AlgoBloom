/*
Design a stack which supports the following operations.

Implement the CustomStack class:

CustomStack(int maxSize) Initializes the object with maxSize which is the maximum number of elements in the stack or do nothing if the stack reached the maxSize.
void push(int x) Adds x to the top of the stack if the stack hasn't reached the maxSize.
int pop() Pops and returns the top of stack or -1 if the stack is empty.
void inc(int k, int val) Increments the bottom k elements of the stack by val. If there are less than k elements in the stack, just increment all the elements in the stack.
*/


#include<vector>
class CustomStack {
public:
    vector<int> stack,inc;
    int n;
    CustomStack(int maxSize) {
       n=maxSize;
           
    }
    
    void push(int x) {
      if(stack.size()<n)
           stack.push_back(x);
    }
    
    int pop() {
        if(stack.size()==0) return -1;
        int k=stack[stack.size()-1];
        stack.pop_back();
        return k;
    }
    
    void increment(int k, int val) {
        if(stack.size()>=k)
        for(int i=0;i<k;i++)
            stack[i]+=val;
        else
          for(int i=0;i<stack.size();i++)
            stack[i]+=val;  
    }
};

