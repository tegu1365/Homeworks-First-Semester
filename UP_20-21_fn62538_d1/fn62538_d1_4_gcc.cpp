/**
*
* Solution to homework assignment 1
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
void output(int a,int b,int c)
{
    int min_=0,max_=0,mid=0;
    if(a<b && a<c)
    {
        min_=a;
        if(b>c)
        {
            max_=b;
            mid=c;
        }
        else
        {
            max_=c;
            mid=b;
        }
    }
    else
    {
        if(b<a && b<c)
        {
            min_=b;
            if(a>c)
            {
                max_=a;
                mid=c;
            }
            else
            {
                max_=c;
                mid=a;
            }
        }
        else
        {
            min_=c;
            if(a>b)
            {
                max_=a;
                mid=b;
            }
            else
            {
                max_=b;
                mid=a;
            }
        }
    }
    cout<<min_<<" "<<mid<<" "<<max_;
}
int main()
{
    int num=0,minSum=0;
    cin>>num;
    if(num<1 || num>1000000000)
    {
        cout<<(-1);
    }
    else
    {
        int m=num,p=1,q=1;
        minSum=m+p+q;
        for(int i=num-1; i>0; i--)
        {
            int currentSum=0,currentM=1,currentP=1,currentQ=1;

            if(num%i==0)
            {
                currentM=i;
                if(num==1)
                {
                    currentP=1;
                }
                else
                {
                    for(int j=2; j<=num; j++)
                    {
                        if(num%i==0)
                        {
                            currentP=j;
                            currentQ=num/(currentM*currentP);
                            currentSum=currentM+currentP+currentQ;
                            // cout<<"%%%"<<currentSum<<"="<<currentM<<"+"<<currentP<<"+"<<currentQ<<endl<<endl;
                            if(currentSum<minSum && currentM*currentP*currentQ==num)
                            {
                                minSum=currentSum;
                                m=currentM;
                                p=currentP;
                                q=currentQ;
                                //cout<<minSum<<"= "<<m<<"+"<<p<<"+"<<q<<endl<<endl;
                            }
                        }
                    }
                }
            }
        }

        output(m,p,q);
    }
    return 0;
}
