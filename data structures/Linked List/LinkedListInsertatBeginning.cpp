#include <stdio.h>
#include <iostream>

struct Node
{
    int val;
    Node* next;
};

// Functions
void Print(Node*);
void InsertAtBeginning(Node**, int);

//Node* head;

int main()
{
    //head = NULL;    // Emplty List
    Node* head = NULL;

    int n, x;
    printf("How many numbers? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the number: ");
        scanf("%d", &x);
        InsertAtBeginning(&head, x);
    }

    Print(head);
}

void Print(Node* head)
{
    Node* temp = head;
    while (temp->next != NULL)
    {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << temp->val << std::endl;
}

void InsertAtBeginning(Node** head, int n)
{
    Node* temp = new Node();
    temp->val = n;
    temp->next = *head;
    *head = temp;
}