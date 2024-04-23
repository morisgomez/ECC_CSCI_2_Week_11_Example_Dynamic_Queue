/*
 Program Name: Dynamic_Queue.cpp
 Programmer: Moris Gomez
 Date: Tuesday 04/21/2024
 Version Control: 1.0
 About: Week 11, CSCI 2, Example 1.
 Description:
 Intro to Dynamic Queue using a Linked List.
 Following along professor's example.
*/

#include <iostream>
#include <string>

using namespace std;

class DynamicQueue
{
private:
    struct Node
    {
        int value;
        Node *next;
    }; //end struct Node
    
    Node *rear;
    Node *front;
    int numItems;
    
public:
//constructor:
    DynamicQueue()
    {
        front = NULL;
        rear = NULL;
        numItems = 0;
    }
//destructor:
    ~DynamicQueue()
    {
        clear();
    }
//function 1: enqueue()
    void enqueue(int num)
    {
        Node *n = new Node;
        n->value = num;
        n->next = NULL;
        if(isEmpty()) //special case: queue is empty.
        {
            front = n;
            rear = n;
        }
        else //non-special case: not empty.
        {
            rear->next = n;
            rear = n;
        }
        numItems++;
    } //end enqueue() function.
//function 2: dequeue()
    void dequeue(int &num)
    {
        Node *temp;
        if(isEmpty()) //if queue is empty.
        {
            cout << "Queue is empty!" << endl;
        }
        else //else not empty.
        {
            if(numItems == 1) //special case: 1 element in queue.
            {
                num = front->value;
                delete front;
                rear = NULL;
                numItems--;
            }
            else //else more than 1 element in queue.
            {
                num = front->value;
                temp = front;
                front = front->next;
                delete temp;
                numItems--;
            } //close inner else.
        } //close outer else.
    } //end dequeue() function.
//function 3: display()
    void display()
    {
        Node *current = front;
        if(isEmpty())
        {
            cout << "Queue is empty!" << endl;
        }
        else
        {
            while(current != NULL)
            {
                cout << "element with value of: " << current->value << endl;
                current = current->next;
            } //close while loop.
        } //close else.
    } //end display() function.
//function 4: isEmpty()
    bool isEmpty()
    {
        if(numItems > 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    } //end isEmpty() function.
//function 5: clear()
    void clear()
    {
        int value;
        while(!isEmpty())
        {
            dequeue(value);
        } //close while loop.
    } //end clear() function.
}; //end class Dynamic Queue.


int main()
{
    //1. create an object of DynamicQueue class:
    DynamicQueue qOne;
    
    //2. enqueue some Nodes to qOne:
    qOne.enqueue(5);
    qOne.enqueue(10);
    qOne.enqueue(15);
    qOne.enqueue(20);
    
    //3. display Nodes in qOne:
    qOne.display(); //5, 10, 15, 20
    
    //4. dequeue a Node from qOne:
    int x;
    qOne.dequeue(x);
    
    //5. display Nodes in qOne:
    cout << "----" << endl;
    qOne.display(); //10, 15, 20
    
    //6. call clear function on qOne:
    qOne.clear(); //still exists but with no elements.
    
    //7. display Nodes in qOne:
    cout << "----" << endl;
    qOne.display(); //Queue is empty!
}
