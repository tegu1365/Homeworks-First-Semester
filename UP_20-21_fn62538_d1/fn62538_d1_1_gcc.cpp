/**
*
* Solution to homework assignment 1
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
int main()
{
    int moneyForCom=0,moneyFromToy=0,numOfBDays=0;//x,m,n
    int finalMoney=0;

    cin>>numOfBDays>>moneyForCom>>moneyFromToy;

    if((moneyForCom<=0 || moneyFromToy<=0 || numOfBDays<=0))
    {
        //   cout<<"Incorrect data. The numbers must be positive. Try again: \n";
        cout<<"-1";
    }
    else
    {


        if(numOfBDays%2==0)
        {
            int n=numOfBDays/2;
            finalMoney=n*moneyFromToy+((50+(n-1)*30)*n)/2;
        }
        else
        {
            int evenBDays=numOfBDays/2;
            int oddBDays=evenBDays+1;
            finalMoney=oddBDays*moneyFromToy+((50+(evenBDays-1)*30)*evenBDays)/2;
        }

        if(finalMoney>=moneyForCom)
        {
            cout<<"yes"<<endl<<finalMoney-moneyForCom;
        }
        else
        {
            cout<<"no"<<endl<<moneyForCom-finalMoney;
        }
    }
    return 0;
}
