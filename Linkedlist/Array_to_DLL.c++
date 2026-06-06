#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node *back;

    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }
    Node(int data2)
    {
        data = data2;
        next = nullptr;
        back = nullptr;
    }

};

Node *array_to_DLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for(int i = 1; i<arr.size(); i++)
    {
        Node *curr = new Node(arr[i]);
        temp->next = curr;
        curr->back = temp;
        temp = curr;
    }
    return head;
}

int print(Node * head)
{
    Node * temp = head;
    while(temp!= NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    return 0;
}


int main()
{
    vector<int>arr = {1,3,4,5,3,3,6};
    Node * head = array_to_DLL(arr);
    print(head);
    return 0;

}