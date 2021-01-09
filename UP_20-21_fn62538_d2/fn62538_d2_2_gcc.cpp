/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Teodora Petkova
* @idnumber 62538
* @task 2
* @compiler GCC
*
*/
#include<iostream>
using namespace std;
double input()
{
    double a;
    cin>>a;
    if(a<0.1 || a>100)
    {
        a=input();
    }
    else return a;
}
double buy(double money,double a)
{
   // cout<<money<<"-"<<a<<"="<<money-a<<endl;
    return money-a;
}
double sell(double money,double a)
{
    //cout<<money<<"+"<<a<<"="<<money+a<<endl;
    return money+a;
}
int main()
{
    double shares[365];
    int n;
    double currentMoney=0, finalMoney=0;
    bool hasShares=false;
    cin>>n;
    if(n>=3 && n<=365)
    {
        for(int i=0; i<n; i++)
        {
            shares[i]=input();
        }

        for(int i=0; i<n; i++)
        {
                if(hasShares){
                        if(i!=n-1){
                    int j=i+1;
                    while(currentMoney+shares[j+1]>currentMoney+shares[j]&& j<n){
                        j++;
                    }
                    i=j;
                        }
                    currentMoney=sell(currentMoney,shares[i]);
                    //cout<<"sell\n";
                    hasShares=false;
                }else{
                    if(shares[i]<shares[i+1]){
                        currentMoney=buy(currentMoney,shares[i]);
                       // cout<<"buy\n";
                        hasShares=true;
                    }
                }
        }
        finalMoney=currentMoney;
        if(currentMoney<=0){
            cout<<0;
        }else{
            cout<<finalMoney;
        }
    }
    else
    {
        cout<<0;
    }
    return 0;
}
