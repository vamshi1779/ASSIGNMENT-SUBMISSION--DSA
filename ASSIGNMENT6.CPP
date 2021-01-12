// Question 1
// Write a program implementing insert, delete and display operation of Circular Queue.

// Solution:
#include <stdio.h>

#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;

// Check if the queue is full
int isFull() {
  if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) return 1;
  return 0;
}

// Check if the queue is empty
int isEmpty() {
  if (front == -1) return 1;
  return 0;
}

// Adding an element
void enQueue(int element) {
  if (isFull())
    printf("\n Queue is full!! \n");
  else {
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    items[rear] = element;
    printf("\n Inserted -> %d", element);
  }
}

// Removing an element
int deQueue() {
  int element;
  if (isEmpty()) {
    printf("\n Queue is empty !! \n");
    return (-1);
  } else {
    element = items[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    } 
    // Q has only one element, so we reset the 
    // queue after dequeing it. ?
    else {
      front = (front + 1) % SIZE;
    }
    printf("\n Deleted element -> %d \n", element);
    return (element);
  }
}

// Display the queue
void display() {
  int i;
  if (isEmpty())
    printf(" \n Empty Queue\n");
  else {
    printf("\n Front -> %d ", front);
    printf("\n Items -> ");
    for (i = front; i != rear; i = (i + 1) % SIZE) {
      printf("%d ", items[i]);
    }
    printf("%d ", items[i]);
    printf("\n Rear -> %d \n", rear);
  }
}

int main() {
  // Fails because front = -1
  deQueue();

  enQueue(1);
  enQueue(2);
  enQueue(3);
  enQueue(4);
  enQueue(5);

  // Fails to enqueue because front == 0 && rear == SIZE - 1
  enQueue(6);

  display();
  deQueue();

  display();

  enQueue(7);
  display();

  // Fails to enqueue because front == rear + 1
  enQueue(8);

  return 0;
}

// Question 2
// A Barua number is a number which consists of only zeroes and ones and has only one 1. Barua number will start with 1. Given numbers, find out the multiplication of the numbers. Note: The input may contain one decimal number and all other Barua numbers. (Assume that each number is very large and total number of values give is also very large)
// Input 1: 100 10 12 1000
// Output 1: 12000000
// Input 2: 100 121 1000000000000000
// Output 2: 12100000000000000000
// Input 3: 10 100 1000
// Output 3: 1000000
// Solution:


// Question 3
// Implement push, pop and find the minimum element in a stack in O(1) time complexity.
// Solution:

// C++ program to implement a stack that supports 
// getMinimum() in O(1) time and O(1) extra space. 
#include <bits/stdc++.h> 
using namespace std; 
  
// A user defined stack that supports getMin() in 
// addition to push() and pop() 
struct MyStack 
{ 
    stack<int> s; 
    int minEle; 
  
    // Prints minimum element of MyStack 
    void getMin() 
    { 
        if (s.empty()) 
            cout << "Stack is empty\n"; 
  
        // variable minEle stores the minimum element 
        // in the stack. 
        else
            cout <<"Minimum Element in the stack is: "
                 << minEle << "\n"; 
    } 
  
    // Prints top element of MyStack 
    void peek() 
    { 
        if (s.empty()) 
        { 
            cout << "Stack is empty "; 
            return; 
        } 
  
        int t = s.top(); // Top element. 
  
        cout << "Top Most Element is: "; 
  
        // If t < minEle means minEle stores 
        // value of t. 
        (t < minEle)? cout << minEle: cout << t; 
    } 
  
    // Remove the top element from MyStack 
    void pop() 
    { 
        if (s.empty()) 
        { 
            cout << "Stack is empty\n"; 
            return; 
        } 
  
        cout << "Top Most Element Removed: "; 
        int t = s.top(); 
        s.pop(); 
  
        // Minimum will change as the minimum element 
        // of the stack is being removed. 
        if (t < minEle) 
        { 
            cout << minEle << "\n"; 
            minEle = 2*minEle - t; 
        } 
  
        else
            cout << t << "\n"; 
    } 
  
    // Removes top element from MyStack 
    void push(int x) 
    { 
        // Insert new number into the stack 
        if (s.empty()) 
        { 
            minEle = x; 
            s.push(x); 
            cout <<  "Number Inserted: " << x << "\n"; 
            return; 
        } 
  
        // If new number is less than minEle 
        if (x < minEle) 
        { 
            s.push(2*x - minEle); 
            minEle = x; 
        } 
  
        else
           s.push(x); 
  
        cout <<  "Number Inserted: " << x << "\n"; 
    } 
}; 
  
// Driver Code 
int main() 
{ 
    MyStack s; 
    s.push(3); 
    s.push(5); 
    s.getMin(); 
    s.push(2); 
    s.push(1); 
    s.getMin(); 
    s.pop(); 
    s.getMin(); 
    s.pop(); 
    s.peek(); 
  
    return 0; 
} 

