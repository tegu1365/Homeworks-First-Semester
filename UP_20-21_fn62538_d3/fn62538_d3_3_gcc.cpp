/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Teodora Petkova
* @idnumber 62538
* @task 3
* @compiler GCC
*
*/


#include<iostream>
using namespace std;

double rowSum(double arr[][100], int size_, int numOfRow)
{
    double sum=0;
    for(int i=0; i<size_; i++)
    {
        sum+=arr[numOfRow][i];
    }
    return sum;
}

double colSum(double arr[][100], int size_, int numOfCol)
{
    double sum=0;
    for(int i=0; i<size_; i++)
    {
        sum+=arr[i][numOfCol];
    }
    return sum;
}

double diaSum(double arr[][100], int size_)
{
    double sum=0;
    for(int i=0; i<size_; i++)
    {
        sum+=arr[i][i];
    }
    return sum;
}

double dia2Sum(double arr[][100], int size_)
{
    double sum=0;
    for(int i=0; i<size_; i++)
    {
        sum+=arr[i][size_-i-1];
        // cout<<arr[i][size_-i-1]<<"+";
    }
    //cout<<endl;
    return sum;
}

bool magicSquer(double arr[][100],int n)
{
    double magicalNum=diaSum(arr,n);

    if(magicalNum!=dia2Sum(arr,n))
    {
        return false;
    }
    for(int i=0; i<n; i++)
    {
        if(magicalNum!=rowSum(arr,n,i))
        {
            return false;
        }
        if(magicalNum!=colSum(arr,n,i))
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int n=0;
    cin>>n;
    if(n<0||n>100)
    {
        cout<<-1;
        return 0;
    }
    double arr[100][100];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]<0 || arr[i][j]>100.0)
            {
                cout<<-1;
                return 0;
            }
        }
    }
    if(magicSquer(arr,n))
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }
    return 0;
}
