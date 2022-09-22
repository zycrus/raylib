#include <stdio.h>
#include <iostream>

struct Node
{
    int val;
    Node* next;
};

Node* head;

void Print()
{
    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    std::cout << temp->val << std::endl;
}

int main()
{
    head = NULL;
    Node* temp = new Node();
    temp->val = 2;
    temp->next = NULL;
    head = temp;
    Print();
}