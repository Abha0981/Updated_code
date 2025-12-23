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

void insertion(int size, int arr[])
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i-1;

        while (key<arr[j] && j>=0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }  
}

int main()
{
    int size;
    int arr[100];
    cout<<"Enter the size of the array"<<endl;
    cin>> size;
    
    input_array(size, arr);
    insertion(size, arr);
    print_array(size, arr);
    return 0;
}