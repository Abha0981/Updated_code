#include <iostream>
#include <climits>  // this method is also give the largest and smallest element 
//but it is not working here 
//this method is two pass method 
// TC = O(n)
// SC = O(1)
using namespace std;

int s = INT_MAX;
int s2 = -1;

int largest(int arr[], int n)
{
    int largest = INT_MIN;
	    int seclargest = -1;
	    
	    for(int i = 0; i<n; i++)
	    {
	        if(arr[i] > largest)
	        {
	            largest = arr[i];
	        }
	    }
	    
	    for(int j = 0; j<n; j++)
	    {
	        if(arr[j] > seclargest && arr[j] < largest)
	        {
	            seclargest = arr[j];
	        }
	    }
	    
	    return seclargest;
}
int smallest(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < s)
        {
            s = arr[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < s2 && arr[i] > s)
        {
            s2 = arr[i];
        }
    }
    return s2;
}

int main()
{
    int n = 7;
    int arr[7] = {2, 3, 4, 7, 6, 8, 10};
    cout << largest << endl;
    // cout<<smallest<<endl;

    return 0;
}