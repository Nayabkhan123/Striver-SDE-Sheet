/*
    Write a program to implement a Stack using Array. Your task is to use the class as shown in the comments 
    in the code editor and complete the functions push() and pop() to implement a stack. The push() method 
    takes one argument, an integer 'x' to be pushed into the stack and pop() which returns an integer 
    present at the top and popped out from the stack. If the stack is empty then return -1 from the pop() method.

    Note: The input is given in form of queries. Since there are two operations push() and pop(), there is 
    two types of queries as described below:
    (i) 1 x   (a query of this type means  pushing 'x' into the stack)
    (ii) 2     (a query of this type means to pop an element from the stack and print the popped element)
    Input contains separated by space and as described above. 

    Examples :

    Input: 1 2 1 3 2 1 4 2 
    Output: 3, 4
    Explanation: 
    push(2)    the stack will be {2}
    push(3)    the stack will be {2 3}
    pop()      poped element will be 3,
            the stack will be {2}
    push(4)    the stack will be {2 4}
    pop()      poped element will be 4
*/


/*
class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};
*/

void MyStack ::push(int x) {
    arr[++top]=x;
}

// Function to remove an item from top of the stack.
int MyStack ::pop() {
    if(top==-1){
        return -1;
    }
    else{
        return arr[top--];
    }
}