/*
  circularQueue.cpp
  Jasmine Rodriguez
  COP 3415
  Last date modified: 10/4/23
  Assignment 3:
  Create circular queue
  with enQueue(int value), deQueue(),
  displayQueue()
  */
#include <iostream>
using namespace std;

class Queue
{
private:

    int front, rear, capacity, size;
    int* array;

public:

    //create queue
    Queue(int capacity)
    {
        //set capacity/max amount of elements
        this->capacity = capacity;
        size = 0;
        //front is set to rear due to there being no elements. rear is set to -1 for the same reason
        front = rear = -1;
        //set array
        array = new int[capacity];
    }

    //insert element at end of array
    void enQueue(int value)
    {
        //cannot add more to queue if full
        if (size == capacity)
        {
            cout << "Error: queue is full\n";
            return;
        }
        else if (size == 0)
        {
            /* now that a value has been added
            to the queue, rear can be set
            to 0
              */
            front = rear = 0;
        }
        else
            rear = (rear + 1) % capacity;
        array[rear] = value;
        size++;
        cout << value << " has been enqueued\n";
    }

    //remove element at front of array
    int deQueue()
    {
        //cannot remove anything from the queue if it is empty
        if (size == 0)
        {
            cout << "Error: Queue is empty\n";
            return 0;
        }
        //a value to return
        int value = array[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % capacity;
        size--;
        cout << value << " has been dequeued \n";
        return value;
    }

    //display array
    void displayQueue()
    {
        if (size == 0)
        {
            cout << "Error: queue is empty\n";
            return;
        }
        /* in order to properly iterate through
        the array, int i must be set to front as
        a temp so that front can still point
        to the start of the queue
          */
        cout << "Cir Queue: ";
        int i = front;
        do
        {
            cout << array[i] << " ";
            i = (i + 1) % capacity;
        } while (i != (rear + 1) % capacity);
        cout << "\n";
    }
};

int main()
{
    Queue q(5);

    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    q.enQueue(60);

    q.displayQueue();

    q.deQueue();

    q.displayQueue();

    q.enQueue(60);

    q.displayQueue();

    return 0;
}