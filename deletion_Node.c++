#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data1, Node *next1)
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
Node *array_to_linkedlist(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void print(Node *head)
{
    while (head != 0)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
Node *del_node_position(Node *head, int k)
{
    int count = 0;
    if (head == NULL) // if linkedlist is NULL
    {
        return head;
    }
    if (k == 1) // if linkedlist contains only one Node that's first Node
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL) // linkedlist contains 2 or more than 2 Nodes
    {
        count++;
        if (count == k)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
Node *del_node_element(Node *head, int element) //deletion of element by its value
{
    if (head == NULL)
    {
        return head;
    }
    if (head->data == element)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        if (temp->data == element)
        {
            prev->next = prev->next->next;
            delete temp;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
int main()
{
    vector<int> arr = {3, 42, 5, 3, 23, 3, 12, 4, 45};
    Node *head = array_to_linkedlist(arr);
    print(head);
    head = del_node_position(head, 6); // deletion of node by its position
    print(head);
    head = del_node_element(head, 3); // deleteion of node by its value
    print(head);
    return 0;
}