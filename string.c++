#include<iostream>
#include<string>
#include<map>
#include<iterator>
using namespace std;


void count_string(string str)
{   
    map<char, int>count;
   
    for(auto ch :str)
    {
        count[ch]++; 
    }
    for(auto it : count)
    {
        if(it.second > 1)
        {
            cout<<it.first<<" "<<it.second<<endl;
        }
    }
    cout<<endl;

}

int main() 
{
    string str;
    cout<<"Enter string "<<endl;
    getline(cin, str);
    cout<<"Duplicates values"<<endl;
    count_string(str);
    return 0;
}