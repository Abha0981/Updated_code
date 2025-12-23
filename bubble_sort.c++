#include<iostream>
using namespace std;

void input_array(int size, int arr[])
{
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }  
}

void print_array(int size, int arr[])
{
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

void bubble_sort(int size, int arr[])
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int  j = 0; j < size - 1 - i; j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap(arr[j], arr[j+1]);
            }  
        }  
    }
}

int main()
{
    int size;
    int arr[100];
    cout<<"Enter the size of the array :";
    cin>>size;
    cout<<"Enter the inputs of array"<<endl;
    input_array(size, arr);
    bubble_sort(size, arr);
    cout<<"Sorted array"<<endl;
    print_array(size, arr);
}