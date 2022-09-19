#include <iostream>

struct Node
{
    int value;
    Node* next;
    
    Node(int val): value(val), next(nullptr) {  }
    Node(int val, Node* nxt): value(val), next(nxt) {  }
};

class LinkedList
{
public:
    Node* head;

    LinkedList() : head(NULL) {}
    LinkedList(Node* node) : head(node) {}

    void PrintNodes()
    {
        Node* temp = head;
        std::cout << "List is:";
        while (temp != NULL)
        {
            std::cout << " " << temp->value;
            temp = temp->next;
        }
        std::cout <<std::endl;
        delete temp;
    }

    void InsertAtBeginning(int x)
    {
        Node* temp = new Node(x, head);
        head = temp;
        PrintNodes();
    }

    void Insert(int x, int pos)
    {

    }
};

int main()
{
    LinkedList lst = LinkedList();
    lst.InsertAtBeginning(2);
    lst.InsertAtBeginning(1);
    lst.InsertAtBeginning(5);
}