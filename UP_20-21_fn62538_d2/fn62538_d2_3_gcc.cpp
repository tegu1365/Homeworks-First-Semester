/**
*
* Solution to homework assignment 2
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
bool isItPolyndrom(int start, int end_, int a[])
{
//    for(int i=start; i<=end_; i++)
//    {
//        cout<<a[i]<<" ";
//    }
//    cout<<endl;
    for(int i=0; i<(start-end_)/(-2); i++)
    {
        if(a[start+i]-a[end_-i]!=0)
        {
            //     cout<<start+i<<"-"<<end_-i<<"!=0"<<endl;
           // cout<<"NP"<<endl;
            return false;
        }
    }
//    cout<<"P"<<endl;
    return true;
}
int input(){
    int a;
    cin>>a;
    if(a<0||a>9){
        a=input();
    }
    else{
        return a;
    }
}
int main()
{
    int arr[1000], numOfPolyndroms=0;
    int n=0;
    cin>>n;
    if(n>=3 && n<=1000)
    {
        for(int i=0; i<n; i++)
        {
           arr[i]=input();
        }
        for(int i=1; i<n-1; i++)
        {
            //Odd
            int j=1;
            if(i<=n/2)
            {
                j=i;
            }
            else
            {
                j=n-i-1;
            }
            // cout<<j<<endl;
            for(; j>0; j--)
            {
                if(isItPolyndrom(i-j,i+j,arr))
                {
                    numOfPolyndroms++;
                    // cout<<"P";
                }
            }

            //even
            //cout<<arr[i]<<"== "<<arr[i+1]<<endl;
            if(arr[i]==arr[i+1])
            {
                if(i<=n/2)
                {
                    j=i;
                }
                else
                {
                    j=n-i-1;
                }
                //cout<<j+1<<endl;
                for(; j>0; j--)
                {
                    if(i+j+1<n)
                    {
                        if(isItPolyndrom(i-j,i+j+1,arr))
                        {
                            numOfPolyndroms++;
                            // cout<<"P";
                        }
                    }
                }
            }

        }
        if(numOfPolyndroms==0){
            cout<<-1;
        }else{
        cout<<numOfPolyndroms;
        }
    }
    else
    {
        cout<<-1;
    }
    return 0;
}
