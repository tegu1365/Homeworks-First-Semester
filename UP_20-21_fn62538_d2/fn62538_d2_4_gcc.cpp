/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Teodora Petkova
* @idnumber 62538
* @task 4
* @compiler GCC
*
*/
#include<iostream>
using namespace std;
int input(int arr[],int n)
{
    int a;
    cin>>a;
    for(int i=0; i<n; i++)
    {
        if(arr[i]==a)
        {
            a=input(arr,n);
        }
    }
    return a;
}
int main()
{
    int n=0, arr[100];
    int numOfZeros=0;
    cin>>n;
    if(n>=3 && n<=100)
    {
        cin>>arr[0];
        for(int i=1; i<n; i++)
        {
            arr[i]=input(arr,i);
        }
//        for(int i=0; i<n; i++)
//        {
//            cout<<arr[i]<<" ";
//        }
//cout<<endl;
        int sum=0;
        for(int i=0; i<n-2; i++)
        {

            for(int j=i+1; j<n-1; j++)
            {
                for(int k=j+1; k<n; k++)
                {
                    sum+=arr[i]+arr[j]+arr[k];
                  //  cout<<arr[i]<<"+"<<arr[j]<<"+"<<arr[k]<<"="<<sum<<endl;
                    if(sum==0)
                    {
                        numOfZeros++;
                    }
                    sum=0;
                }
            }
        }
        cout<<numOfZeros;
    }
    else
    {
        cout<<-1;
    }
    return 0;
}
