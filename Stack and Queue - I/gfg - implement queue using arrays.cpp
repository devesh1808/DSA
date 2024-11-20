class MyQueue
{
private:
    int arr[100005];
    int front;
    int rear;

public:
    MyQueue()
    {
        front = -1;
        rear = -1;
    }
    void push(int);
    int pop();
};

// Function to push an element x in a queue.
void MyQueue ::push(int x)
{
    // Your Code
    rear++;
    arr[rear] = x;
}

// Function to pop an element from queue and return that element.
int MyQueue ::pop()
{
    // Your Code
    if (front == rear)
        return -1;
    front++;
    return arr[front];
}