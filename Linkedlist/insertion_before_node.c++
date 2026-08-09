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

Node *array_to_dll(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *curr = new Node(arr[i]);
        temp->next = curr;
        curr->back = temp;
        temp = curr;
    }
    return head;
}

// insert before head
Node *insert_before_head(Node *head, int num)
{
    if(head == nullptr)
    {
        Node *curr = new Node(num);
        head = curr;
        return head;
    }
    else
    {
        Node *temp = head;
        Node *curr = new Node(num);
        temp->back = curr;
        curr->next = temp;
        curr->back = nullptr;
        head = curr;
        return head;
    }
    Node *temp = head;
    Node *curr = new Node(num);
    temp->back = curr;
    curr->next = temp;
    curr->back = nullptr;
    head = curr;
    return head;
}
// insert before tail
// insert before kth node
//  insert before given node
void print(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node *head = array_to_dll(arr);
    cout << "DLL" << endl;
    print(head);
    int num = 90;
    Node *head1 = insert_before_head(head, num);
    cout << "insertion before head" << endl;
    print(head1);
    return 0;
}