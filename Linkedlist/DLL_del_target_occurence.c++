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
    for (int i = 1; i < arr.size(); i++)
    {
        Node *curr = new Node(arr[i]);
        temp->next = curr;
        curr->back = temp;
        temp = curr;
    }
    return head;
}

Node *deltargetNode(Node *head, int target)
{

    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        if (head->data == target)
        {
            delete head;
            return NULL;
        }
        else
        {
            return head;
        }
    }

    Node *temp = head;

    while (temp != nullptr)
    {
        Node *prev = temp->back;
        Node *front = temp->next;

        if (temp->data == target && prev == nullptr)
        {
            head = temp->next;
            head->back = nullptr;
            delete temp;
            temp = head;
            continue;
        }

        if (temp->data == target && prev != nullptr && front != nullptr)
        {
            prev->next = front;
            front->back = prev;
            temp->next = nullptr;
            temp->back = nullptr;
            delete temp;
            temp = front;
        }

        if (temp->data == target && front == nullptr)
        {
            temp->back = nullptr;
            prev->next = nullptr;
            delete temp;
            temp = front;
            return head;
        }
        temp = front;
    }

    return head;
}
int print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}

int main()
{
    vector<int> arr = {2, 5, 2, 4, 8, 10, 2, 2};
    Node *head = array_to_DLL(arr);
    print(head);
    Node *deltarget = deltargetNode(head, 2);
    cout << "Target deletion" << endl;
    print(deltarget);
    return 0;
}