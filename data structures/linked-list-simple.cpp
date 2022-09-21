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
        // Insert at Beginning
        if (pos == 1)
        {
            InsertAtBeginning(x);
            return;
        }

        Node* temp1 = new Node(x);
        Node* temp2 = head;
        for (int i = 0; i < pos - 2; i++)
        {
            if (temp2->next == NULL) // When pos exceeds list size
            {
                temp2->next = temp1;
                PrintNodes();

                delete temp1, temp2;
                return;
            }
            temp2 = temp2->next;
        }
        temp1->next = temp2->next;
        temp2->next = temp1;
        PrintNodes();

        delete temp1, temp2;
    }
};

int main()
{
    LinkedList lst = LinkedList();
    lst.InsertAtBeginning(2);
    lst.InsertAtBeginning(1);
    lst.InsertAtBeginning(5);
    lst.Insert(9, 3);
    lst.Insert(9, 3);
}