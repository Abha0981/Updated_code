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
    if (head == nullptr)
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
}

// insert before tail
Node *insert_before_tail(Node *head, int num)
{
    if (head == nullptr)
    {
        Node *curr = new Node(num);
        head = curr;
        return head;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    Node *prev = temp->back;
    Node *curr = new Node(num);

    temp->back = curr;
    curr->next = temp;
    curr->back = prev;
    if (prev != nullptr)
    {
        prev->next = curr;
    }
    else
    {
        head = curr;
    }
    return head;
}
// insert before kth node

Node *insert_before_kth_node(Node *head, int num, int k)
{
    Node *temp1 = head;
    int count1 = 0;
    while (temp1 != nullptr)
    {
        count1++;
        temp1 = temp1->next;
    }
    if (head == nullptr)
    {
        return nullptr;
    }
    if (k <= 0 || k > count1)
    return head;

    Node *temp = head;
    int count = 0;
    while (temp != nullptr)
    {
        count++;
      
        if (count == 1 && k == count)
        {
            return insert_before_head(head, num);
        }
        else if (count == k && count1 == count)
        {
            return insert_before_tail(head, num);
        }
        else if (count == k)
        {
            Node *prev = temp->back;
            Node *curr = new Node(num);
            temp->back = curr;
            curr->next = temp;
            curr->back = prev;
            prev->next = curr;
        }
        temp = temp->next;
    }
    return head;
}
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
    Node *head2 = insert_before_tail(head1, num);
    cout << "insertion before tail" << endl;
    print(head2);
    Node *head3 = insert_before_kth_node(head2, num, 4);
    cout << "Insertion before Kth node" << endl;
    print(head3);
    return 0;
}