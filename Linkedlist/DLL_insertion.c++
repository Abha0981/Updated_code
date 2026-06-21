#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data ;
    Node* next;
    Node* back;

    Node(int data1, Node*next1, Node* back1)
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
Node* arrayToDll(vector<int> &arr)
{
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i = 1; i<arr.size(); i++)
    {
        Node* curr = new Node(arr[i]);
        temp->next =  curr;
        curr->back = temp;
        temp = curr;
    }
    return head;
}

Node* reverse(Node* head)
{
    Node* temp = head;
    while(temp != nullptr)
    {
        // front is taken need to move to next node after swapping
        Node* front = temp->next;
        temp->next = temp->back;
        temp->back = front;

        head = temp;
        temp = front;      
    }
    return head;    
}

Node* print(Node* head)
{
    Node* temp = head;
    while(temp != nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    return head;
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8};
    Node* head = arrayToDll(arr);
    print(head);
    Node* rev = reverse(head);
    print(rev);
    return 0;
}