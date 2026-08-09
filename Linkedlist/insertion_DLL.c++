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
Node *array_to_DLL(vector<int> arr)
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
// insert after head
Node *add_after_head(Node *head, int num)
{
    // Node *temp = head;
    if (head->next == nullptr)
    {
        Node *curr = new Node(num);
        head->next = curr;
        curr->back = head;
        return head;
    }
    else
    {
        Node *curr = new Node(num);
        curr->back = head;
        curr->next = head->next;
        head->next = curr;
        return head;
    }
}
// Node* insert_at_tail(Node*)

Node *insert_at_tail(Node *head, int num)
{
    Node *temp = head;
    if (head == nullptr)
    {
        Node *curr = new Node(num);
        curr->next = nullptr;
        curr->back = nullptr;
        return curr;
    }
    else
    {
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        Node *curr = new Node(num);
        temp->next = curr;
        curr->back = temp;
        curr->next = nullptr;
        return head;
    }
}
// insertion at kth node after head
Node *insert_at_kth_node(Node *head, int num, int k)
{

    if (head == nullptr)
    {
        Node *curr = new Node(num);
        curr->next = nullptr;
        curr->back = nullptr;
        return curr;
    }
    int count = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    int cnt = 0;
    Node *temp1 = head;
    while (temp1->next != nullptr)
    {
        cnt++;
        if (cnt == k && cnt == 1)
        {
            return add_after_head(head, num);
        }
        else if (count == k && count == cnt)
        {
            return insert_at_tail(head, num);
        }
        else
        {
            if (cnt == k)
            {
                Node *front = temp1->next;
                Node *curr = new Node(num);
                curr->next = front;
                curr->back = temp1;
                temp1->next = curr;
                front->back = curr;
                return head;
            }
        }
        temp1 = temp1->next;
    }
}

// insert at given node
Node *given_node(Node *head, int num)
{
    Node *temp = head;
    Node *front = temp->next;
    Node *prev = temp->back;
    
    //head is tail
    if(front == nullptr)
    {
        Node *curr = new Node(num);
        temp->next = curr;
        curr->back = temp;
        curr->next = nullptr;
        return head;   
    }
        //middle
        Node *curr = new Node(num);
        temp->next = curr;
        curr->back = temp;
        curr->next = front;
        front->back = curr;
        if(prev == nullptr)
        {
            return head;
        }
        else
        {
            return prev->back; 
        }
        
    
}

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
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = array_to_DLL(arr);
    cout << "Array to LinkesList" << endl;
    print(head);
    int num = 90;
    Node *h1 = given_node(head->next->next, num);
    cout<<"Insertion at given node"<<endl;
    print(h1);
    Node *head1 = add_after_head(head, num);
    cout << "Insertion after head" << endl;
    print(head1);
    Node *head2 = insert_at_tail(head1, num);
    cout << "Insertion after tail" << endl;
    print(head2);
    Node *head3 = insert_at_kth_node(head2, num, 3);
    cout << "Insertion at kth node" << endl;
    print(head3);
    return 0;
}