#include <iostream>

void InsertNodeAt(int, int);
void PrintNodes();

struct Node
{
    int value;
    Node* next;

    Node(int data) : value(data), next(NULL) {}
};

Node* head;

// Insert Node at nth position
// Assumes that position given is valid
void InsertNodeAt(int data, int n)
{
        Node* temp1 = new Node(data);
        
        // Insert at Beginning
        if (n == 1)
        {
            temp1->next = head;
            head = temp1;
            PrintNodes();
            delete temp1;
            return;
        }

        Node* temp2 = head;
        for (int i = 0; i < n - 2; i++)
        {
            temp2 = temp2->next;
        }
        temp1->next = temp2->next;
        temp2->next = temp1;
        PrintNodes();

        delete temp1;
        delete temp2;
}

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

int main()
{
    head = NULL;
    InsertNodeAt(2, 1); // 2
    InsertNodeAt(5, 2); // 2, 5
    InsertNodeAt(6, 3); // 2, 5, 6
    InsertNodeAt(8, 4); // 2, 5, 6, 8
    InsertNodeAt(4, 2); // 2, 4, 5, 6, 8

    delete head;
}