/**
*
* Solution to homework assignment 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Teodora Petkova
* @idnumber 62538
* @task 1
* @compiler GCC
*
*/
#include<iostream>
using namespace std;


bool increasingWithMistakes(int *arr, int n, int k)
{

    for (int i = 0; i < n-1; i++)
    {
        if (arr[i] > arr[i+1])
        {
            //cout<<arr[i]<<">"<<arr[i+1]<<endl;
            k--;
        }
    }

    if(k<0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    int k=0, n=0, *arr;
    cin>>k;
    if(k<0){
        cout<<-1;
        return 0;
    }
    cin>>n;
    if(n<0){
        cout<<-1;
        return 0;
    }
    for(int i=0; i<n; i++)
    {
        cin>>*(arr+i);
    }

    cout<<increasingWithMistakes(arr,n,k);

    return 0;
}
