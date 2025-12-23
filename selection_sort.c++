#include<iostream>
using namespace std;

void display(int size, int arr[])
{
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
}

void selection_sort(int size, int arr[])
{
    for (int i = 0; i < size-1; i++)
    {
        int min = i;
        for (int j = i; j < size; j++)
        {
            if (arr[j]<arr[min])
            {
                min = j;
            }
        }
        swap(arr[min],arr[i]);
    }
    
}

int main()
{
    int arr[8] = {56,45,34,35,65,3,454,4};
    int size = 8;
    cout<<endl;
    selection_sort(size, arr);
    display(size, arr);
    return 0;
}