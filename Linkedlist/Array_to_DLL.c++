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

Node *reverse(Node *head)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        Node *temp = curr->next;
        curr->next = curr->back;
        curr->back = temp;

        head = curr;
        curr = temp;
    }
    return head;
}

Node *deleteHeadDLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}

Node *deltailDLL(Node *head)
{

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *prev = temp->back;
    temp->back = NULL;
    prev->next = nullptr;
    delete temp;
    return head;
}

Node *delKthNode(Node *head, int k)
{
    int count = 0;
    Node *temp = head;
    if (head == nullptr)
    {
        return nullptr;
    }
    while (temp != nullptr)
    {
        count++;
        if (count == k)
        {
            break;
        }
        temp = temp->next;
    }
    Node *prev = temp->back;
    Node *front = temp->next;
    if (prev == nullptr && front != nullptr)
    {
        head = deleteHeadDLL(temp);
        return head;
    }
    else if (front == nullptr && prev != nullptr)
    {
        deltailDLL(temp);
        return head;
    }
    else if (prev == nullptr && front == nullptr)
    {
        return nullptr;
    }

    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}
Node* delNode(Node* temp)
{
    Node* prev = temp->back;
    Node* front = temp->next;

    // tail node
    if(front == nullptr)
    {
        prev->next = nullptr;
        temp->back = nullptr;
        delete temp;
        return nullptr;
    }

    // middle node
    prev->next = front;
    front->back = prev;

    temp->next = nullptr;
    temp->back = nullptr;

    delete temp;
    return nullptr;
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
    vector<int> arr = {1, 3, 4, 5, 3, 3, 6};
    Node *head = array_to_DLL(arr);
    print(head);
    Node *rev = reverse(head);
    print(rev);
    Node *delhead = deleteHeadDLL(rev);
    print(delhead);
    Node *deltail = deltailDLL(delhead);
    print(deltail);
    Node *delkth = delKthNode(deltail, 3);
    print(delkth);
    Node  *delnode = delNode(delkth->next);
    print(delnode);
    return 0;
}