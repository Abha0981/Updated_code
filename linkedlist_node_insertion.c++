#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
    Node(int data1, Node* next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data2)
    {
        data = data2;
        next = nullptr;
    }
};
Node* array_to_linkedlist(vector<int>&arr)
{
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
Node* print(Node* head)
{
    while (head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
    return head;    
}
Node* insert_head(Node* head, int val) //insertion new node at head
{
    if(head == NULL)
    {
        return new Node(val, head);
    }
    return new Node(val, head);       
}
Node * insert_tail(Node* head, int val)
{
    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node* newnnode = new Node(val); 
    temp->next = newnnode;
    return head;
}
int main()
{
    vector<int>arr = {3,34,4,5,6,62};
    Node * head = array_to_linkedlist(arr);
    print(head);
    head = insert_head(head,100); //insertion of new node at head
    print(head);
    head = insert_tail(head, 100); //insertion of new node at tail
    print(head);
    return 0;
}