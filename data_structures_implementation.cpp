#include <iostream>

using namespace std;

/*
============================= 
		Linked List
=============================
*/

class LinkedList {

  // struct to create basic node structure to hold data and reference to next node
  struct node {
    int data;
    node * next;

    node(int input) {
      data = input;
      next = nullptr;
    }
  };

  node * head;

  public:

  // Class Method Definitions
  LinkedList();

  // Create
  void insertNode(int);

  // Search
  bool searchList(int);

  // Delete
  void deleteList();

  // Display
  void displayList();
};

// Constructor
LinkedList::LinkedList() {
  head = NULL;
}

// Inserts Node at start
void LinkedList::insertNode(int input) {
  node * temp = new node(input);
  temp -> next = head;
  head = temp;
  cout << " Inserted Element In Linked List.\n\n";
}

// Searches for a specific element in the linked list
bool LinkedList::searchList(int value) {
  if (head == NULL) {
    cout << " List is empty.\n";
    return false;
  }
  node * curr = head;
  while (curr != NULL) {
    if (curr -> data == value) {
      cout << "Found " << value << " in linked list.\n";
      cout << endl;
      return true;
    }
    curr = curr -> next;
  }

  cout << "Element " << value << " was not found in linked list.\n";
  return false;
}

// Deletes the list in sequential order
void LinkedList::deleteList() {

  // Check for empty list
  if (head == nullptr) {
    cout << " List is Empty.\n\n";
    return;
  }

  // While there are elements in the list keep looping and deleting
  while (head != NULL) {
    node * curr;
    curr = head;
    head = head -> next;
    delete curr;
  }
  cout << "Deleted List\n\n";
}

// Show the entire list in order of traversal
void LinkedList::displayList() {
   // Check for empty list
  if (head == NULL) {
    cout << " List is Empty.\n\n";
    return;
  }
  
  node * curr = head;
  cout << "Linked List Elements:";
  
  // Loop through list until there are no elements
  while (curr != NULL) {
	  // Print current node and move to next
    cout << " " << curr -> data;
    curr = curr -> next;
  }
  cout << endl;
}



/* 
=============================
			Queue
=============================
*/
class Queue {
  // Dynamically allocated array for queue
  int * queue;
  // Length of queue
  int length;
  
  // Front of queue
  int head;
  
  // Back of queue
  int tail;
  
  // # of elements currently in the queue
  int numOfElements;
  
  public:
  
  // Constructor
  Queue(int);
	
  // Destructor
  ~Queue();
  
  // Add to queue
  void enqueue(int);
  
  // Show all elements currently enqueued
  void displayQueue();

  // Remove from queue
  void dequeue();
  
  // Check if queue is empty
  bool isEmpty();
  
  // Check if queue is full
  bool isFull();
};

// Constructor
Queue::Queue(int queueLength) {
	
  // Dynamically allocate queue array
  queue = new int[queueLength];
  
  // Set queue length
  length = queueLength;
  
  // Since we have no elements at start initialize head and tail to -1 which means our head and tail indexes point to nothing
  head = -1;
  tail = -1;
  
  // No elements in queue right now so set it to 0
  numOfElements = 0;
}

// Destructor
Queue::~Queue() {
  // Deallocate the queue array
  delete[] queue;
}

// Insert element in the queue
void Queue::enqueue(int element) {
	
   // Use the "isFull" function to check if the element can be added to the queue
  if (isFull()) {
    cout << " Sorry but the queue is at full capacity cannot add another element.\n\n";
    return;
  }
  
  // Queue is not full get tail index for insertion of new element
  tail = (tail + 1) % length;
  
  // Insert element in queue
  queue[tail] = element;
  
  // Increment number of elements currently in queue
  numOfElements++;
  
  cout << "Queue insertion successful \n\n";
}

// Display Queue
void Queue::displayQueue() {
	// Check for empty queue
  if (isEmpty()) {
    cout << " Empty Queue nothing to display.\n\n";
    return;
  }
  cout << "Queue Elements: ";
  
  // While queue is not empty keep traversing and printing nodes
  while (!isEmpty()) {
    int temp;
    head = (head + 1) % length;
    temp = queue[head];
    numOfElements--;
    cout << " " << temp;
  }
  cout << endl;
}

// Delete Queue
void Queue::dequeue() {
  // As long as queue is not empty keep looping and deleting all elements
  while (!isEmpty()) {
    int temp;
	
	// Get index of element in the next node and update head index
    head = (head + 1) % length;
	
	// Update reference
    temp = queue[head];
	
	// Decrement no of elements after node deletion
    numOfElements--;
  }
  cout << "Queue deleted successfully \n\n";
}

// Check for empty queue
bool Queue::isEmpty() {
  // If noOfElements contains any value greater than 0 false will be returned
  if (numOfElements) {
    return false;
  }
  return true;
}

// Check for full queue capacity
bool Queue::isFull() {
   // If current no of elements in the queue are less than max capacity (length) then queue is not full
  if (numOfElements < length) {
    return false;
  }
  return true;
}


/* 
=============================
			Stack
=============================
*/
class Stack {
	
  // Dynamically allocated array for Stack
  int * stack;
  
  // Stack length
  int length;
  
  // Index of element on top of stack
  int top;
  
  public:
  
  // Constructor
  Stack(int);
  
  // Destructor
  ~Stack();
  
  // Push element on top of stack
  void push(int);
  
  // Pop element from top of stack
  void pop(int & );
  
  // Check if stack is empty
  bool isEmpty();
  
  // Check if stack is full
  bool isFull();
  
  // Display stack
  void displayStack();
};

// Constructor
Stack::Stack(int stackLength) {
  // Dynamically allocate queue array
  stack = new int[stackLength];
  
  // Set stack length
  length = stackLength;
  
  // No element in stack set top to -1
  top = -1;
}

// Destructor
Stack::~Stack() {
	// Deallocate stack array
  delete[] stack;
}

// Function to check if stack is empty
bool Stack::isEmpty() {
	// If no element on top of stack it is empty
  if (top == -1) {
    return true;
  }
  return false;
}

// Function to check if stack is full
bool Stack::isFull() {
	// is stack index the same as maximum allowed length of stack? if yes then it is full and no new elements can be added
  if (top == length - 1) {
    return true;
  }
  return false;
}

// Push Element on top of stack
void Stack::push(int element) {
	// Check if stack is full before adding any element
  if (isFull()) {
    cout << " Full stack.\n\n";
    return;
  }
  
  // Stack is not full update top index
  top++;
  
  // Add element on top of stack
  stack[top] = element;
  cout << "Stack push operation successful.\n\n";
}

// Pop element from top of stack
void Stack::pop(int & num) {
  if (isEmpty()) {
    cout << " The Stack is Empty.\n";
    return;
  }
  num = stack[top];
  top--;
  return;
}

// Display all elements in stack
void Stack::displayStack() {
	// Check if stack is empty
  if (isEmpty()) {
    cout << " The Stack is Empty.\n";
    return;
  }
  
  // Print stack elements
  cout << " The Elements in the Stack were: ";
  for (int i = 0; i <= top; i++) {
    cout << stack[i] << " ";
  }
  cout << endl;

}

void handleLinkedList() {
	LinkedList myLinkedList;
	
    while (true) {
		cout << "[Linked List] Please Choose One of The Following Options\n===================================================\n";
		cout << "1.Insert \n2.Delete List\n3.Search \n4.Display List \n5.Return To Main Menu\n";
        int option;
        cout << "Enter your option: ";
        cin >> option;
		
        switch (option) {
            case 1: {
                int element;
                cout << "Enter Data To Add: ";
                cin >> element;
                myLinkedList.insertNode(element);
                break;
            }
            case 2: {
                myLinkedList.deleteList();
                break;
            }
            case 3: {
                int element;
                cout << "Enter Data To Search: ";
                cin >> element;
                myLinkedList.searchList(element);
                break;
            }
            case 4: {
                myLinkedList.displayList();
                break;
            }
			
			case 5:
			return;
			break;
        }
    }
}

void handleQueue() {
    int queueSize;
    cout << "Enter Size of Queue: ";
    cin >> queueSize;
    Queue myQueue(queueSize);

    while (true) {
	    cout << "[Queue] Please Choose One of The Following Options\n===================================================\n";
		cout << "1.Insert \n2.Delete Queue\n3.Check Empty \n4.Display Queue \n5.Return To Main Menu\n";
        int option;
        cout << "Enter your option: ";
        cin >> option;
		
        switch (option) {
            case 1: {
                int element;
                cout << "Enter Data To Add: ";
                cin >> element;
                myQueue.enqueue(element);
                break;
            }
            case 2: {
                myQueue.dequeue();
                break;
            }
            case 3: {
                cout << (myQueue.isEmpty() ? "Empty Queue.\n" : "Queue is not Empty.\n");
                break;
            }
            case 4: {
                myQueue.displayQueue();
                break;
            }
			
			case 5:
			return;
			break;
        }
    }
}

void handleStack() {
    int stackSize;
    cout << "Enter Size of Stack: ";
    cin >> stackSize;
    Stack myStack(stackSize);

    while (true) {
        cout << "[Stack] Please Choose One of The Following Options\n===================================================\n";
        cout << "1.Push \n2.Pop \n3.Check Empty \n4.Display Stack\n5.Return To Main Menu\n";
        
        int option;
        cout << "Enter your option: ";
        cin >> option;

        switch (option) {
            case 1: {
                int element;
                cout << "Enter Data To Add: ";
                cin >> element;
                myStack.push(element);
                break;
            }
            case 2: {
                int element;
                while (!myStack.isEmpty()) {
                    myStack.pop(element);
                }
                cout << "Popped Elements from list";
                break;
            }
            case 3: {
                cout << (myStack.isEmpty() ? "Stack is Empty.\n" : "Stack is not empty.\n");
                break;
            }
            case 4: {
                myStack.displayStack();
                break;
            }
            case 5:
                return;
				break;
        }
    }
}


int main() {
    while (true) {
        cout << "Welcome! Please Choose One of The Following Options\n===================================================\n";
		cout << "1.Linked List \n2.Queue \n3.Stack \n4.Exit Program\n";
		
        int option;
        cout << "Select Option: ";
        cin >> option;

        switch (option) {
            case 1:
                handleLinkedList();
                break;
            case 2:
                handleQueue();
                break;
            case 3:
                handleStack();
                break;
			case 4:
			    break;
        }
    }
    return 0;
}
