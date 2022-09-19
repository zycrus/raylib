#include <iostream>

// Node
/*
    - value is a data
    - next is a Node pointer    
*/
struct Node
{
    int value;
    Node* next;

    // Node(int val): value(val), next(nullptr) {  }
    // Node(int val, Node* nxt): value(val), next(nxt) {  }
};

void InsertNode(Node** node, int val, Node* next)
{
    (*node)->value = val;
    (*node)->next = next;
}

Node* GetLastNode(Node* node)
{
    if (node->next != nullptr)
    {
        return node->next;
    }
    else
        return node;
}

void Insert(Node**, int, int);
void InsertAtBeginning(Node**, int);
void Print(Node*);
int main()
{
    // Inserting node at the beginning
    Node* head;
    head = NULL;
    std::cout << "How many numbers? ";
    int n, x;
    std::cin >> n;  
    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter the number: ";
        std::cin >> x;
        InsertAtBeginning(&head, x);
        Print(head);
    }

    delete head;
    // Inserting node at a certain place

    std::cout << "" << std::endl;
}

void InsertAtBeginning(Node** headPtr, int x)
{
    // Node* temp = (Node*)malloc(sizeof(Node));  // C Method
    Node* temp = new Node(); // C++ Method
    temp->value = x;
    temp->next = NULL;

    if (*headPtr != NULL) temp->next = *headPtr;
    *headPtr = temp;
    std::cout << "Data Inserted" << std::endl;
    delete temp;
}
void Print(Node* head)
{
    std::cout << "List is:";
    while (head != NULL)
    {
        std::cout << " " << head->value;
        head = head->next;
    }
    std::cout << std::endl;
    delete head;
}

void LinkedListTutorial1()
{
    Node* a = NULL;
        // Node* temp = (Node*)malloc(sizeof(Node));
        // temp->value = 2;
        // temp->next = Null;
        Node* temp = new Node();
        temp->value = 2;
        temp->next = NULL;
        a = temp;

        temp = new Node();
        temp->value = 4;
        temp->next = NULL;


        // Inserting node at the end
        Node* temp1 = a;
        // Traverse the List
        while (temp1->next != NULL)
        {
            temp1 = temp1->next;
        } 
        temp1->next = temp;
        delete a;
        delete temp;
        delete temp1;
}