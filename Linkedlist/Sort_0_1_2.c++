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

// sort 0, 1 2 in linkedlist
void sort_0_1_2(Node *head)
{
    Node *list0 = new Node(-1);
    Node *list1 = new Node(-1);
    Node *list2 = new Node(-1);

    Node *tail0 = list0;
    Node *tail1 = list1;
    Node *tail2 = list2;

    Node *temp = head;

    if (head == nullptr || head->next == nullptr)
    {
        head;
    }

    while (temp != nullptr)
    {
        if (temp->data == 0)
        {
            tail0->next = temp;
            tail0 = tail0->next;
        }
        else if (temp->data == 1)
        {
            tail1->next = temp;
            tail1 = tail1->next;
        }
        else
        {
            tail2->next = temp;
            tail2 = tail2->next;
        }
        temp = temp->next;
    }
    tail0->next = list1->next ? list1->next : list2->next;
    tail1->next = list2->next;
    tail2->next = nullptr;
    head = list0->next;

    delete list0;
    delete list1;
    delete list2;
}
Node *print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
    return head;
}

int main()
{
    // vector<int> arr = {0, 0, 1, 2,1};
    vector<int> arr = {0, 0, 1, 2, 2, 2, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    Node *head = array_to_linkedlist(arr);
    print(head);
    cout << "Sorted 0, 1, 2 LL" << endl;
    sort_0_1_2(head);
    print(head);
    return 0;
}