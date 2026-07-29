#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* back;
    

    Node(int data1,Node* next1, Node*back1){
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
Node* array_to_DLL(vector<int>arr){
    Node* head = new Node(arr[0]);
     Node* temp = head;
    for(int i = 1; i<arr.size(); i++)
    {
        Node* curr = new Node(arr[i]);
        temp->next = curr;
        curr->back = temp;
        temp = curr;

    }
    return head;

}
void print(Node* head)
{
    Node* temp = head;
    while(temp != nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

//Node* insert_at_tail(Node*)
int main()
{
    vector<int>arr = {1,2,3,4,5};
    Node* head = array_to_DLL(arr);
    print(head);
    return 0;
}