#include<iostream>
using namespace std;

void print_array(int size, int arr[])
{
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
}

void insertion_sort(int size, int arr[])
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (key < arr[j] && j>=0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    } 
}

int main()
{
    int arr[8] ={576,45,34,3,45,67,4,54};
    int size = 8;
    cout<<endl;
    insertion_sort(size, arr);
    print_array(size, arr);
    return 0;
}