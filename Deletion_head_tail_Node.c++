#include <iostream>
#include <bits/stdc++.h>  //all types of linkedlist code
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
    for (int i = 1; i < arr.size(); i++) // coversion from array to Linkedlist
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
int lengthlinkedlist(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " "; // printing the value of Linkedlist
        temp = temp->next;
        cnt++;
    }
    cout << endl;
    return cnt; // reutrning the size of the Linkedlist
}
int print(Node *head)
{
    // Node *temp = head;
    while (head!= NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
Node *RemoveHead(Node *head) // delete the head node
{
    if (head == NULL)
    {
        return head;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}
Node *RemoveTail(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

int main()
{
    vector<int> arr = {3, 45, 5, 32, 4, 324};
    Node *head = array_to_linkedlist(arr); // passing the array in head
    cout << lengthlinkedlist(head); //calling of function by passing the head
    cout<<endl<<"HEAD NODE DELETION"<<endl;
    head = RemoveHead(head); //removal of head node
    cout << lengthlinkedlist(head); //calling printing of linkedlist
    cout<<endl<<"TAIL NODE DELETION"<<endl;
    head = RemoveTail(head); // removal of tail node
    print(head); // print the linkedlist

    return 0;
}