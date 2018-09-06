#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct Node
{
    int key;
    Node *next;
};
void push(Node **headRef, int k) // insert at the front
{
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode -> key = k;
    newNode -> next = (*headRef);
    (*headRef) = newNode;
}
void printAfter(Node *prevNode, int k) // insert after a specified node
{
    if(prevNode == NULL)
    {
        cout <<"WTF AREU DOING?????????"<<endl;
        return;
    }
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode -> key = k;
    newNode -> next = prevNode -> next;
    prevNode -> next = newNode;
}
void append(Node **headRef, int k) // insert at the end
{
    Node *newNode = (Node *) malloc(sizeof(Node));
    Node *last = *headRef;
    newNode -> key = k;
    newNode -> next = NULL;
    if(*headRef == NULL)
    {
        *headRef = newNode;
        return;
    }
    while(last -> next != NULL)
        last = last -> next;
    last -> next = newNode;
}
void deleteNode(Node **headRef, int k)
{
    Node *temp = *headRef, *prev;
    if(temp != NULL && temp -> key == k)
    {
        *headRef = temp -> next;
        free(temp);
        return;
    }
    while(temp != NULL && temp -> key != k)
    {
        prev = temp;
        temp = temp -> next;
    }
    if(temp == NULL) return;
    prev -> next = temp -> next;
    free(temp);
    return;
}
void deleteInPos(Node **headRef, int position)
{
    if(*headRef == NULL) return;
    Node *temp = *headRef;
    if(position == 0)
    {
        *headRef = temp -> next;
        free(temp);
        return;
    }
    for(int i = 0; i < position - 1; i ++)
        temp = temp -> next;
    if(temp == NULL || temp -> next == NULL)
        return;
    Node *next = temp -> next -> next;
    free(temp -> next);
    temp -> next = next;
}
void print(Node *node)
{
    while(node != NULL)
    {
        cout << node -> key << endl;
        node = node -> next;
    }
}
int main()
{
    Node *newNode = NULL;
    for(int i = 0; i < 4; i ++) push(&newNode, i);
    deleteInPos(&newNode, 3);
    print(newNode);
    return 0;
}
