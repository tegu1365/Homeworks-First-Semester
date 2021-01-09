/**
*
* Solution to homework assignment 2
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
#include<math.h>
using namespace std;
int input()
{
    int a;
    cin>>a;
    if(a<1)
    {
        a=input();
    }
    else return a;
}
int main()
{
    int n, arr[100];
    bool isItTriangular=true;
    cin>>n;
    if(n>=3 && n<=100)
    {
        for(int i=0; i<n; i++)
        {
            arr[i]=input();
        }
        for(int i=0; i<(n-1); i++)
        {
            if(abs(arr[i]-arr[i+1])!= abs(arr[(n-1)-i]-arr[(n-1)-(i+1)]))
            {
                // cout<<i<<"- "<<i+1<<"="<<abs(arr[i]-arr[i+1])<<endl;
                //cout<<n-i<<"- "<<n-(i+1)<<"="<<abs(arr[(n-1)-i]-arr[(n-1)-(i+1)])<<endl;
                isItTriangular=false;
                break;
            }
        }
        cout<<isItTriangular;
    }
    else
    {
        cout<<-1;
    }
    return 0;
}
