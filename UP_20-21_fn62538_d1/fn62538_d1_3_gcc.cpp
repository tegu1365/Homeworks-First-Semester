/**
*
* Solution to homework assignment 1
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
int main()
{
    short a=0,b=0,c=0;
    short min_=0,max_=0,mid=0;

    cin>>a>>b>>c;

    if((a>9 || b>9 || c>9)|| (a<0 || b<0 || c<0))
    {
        //   cout<<"Incorrect data. The numbers must be between 1 and 9. Try again: \n";
        cout<<"-1";
    }
    else
    {
        if(a==0 && b==0 && c==0)
        {
            cout<<0;
        }
        else
        {
            if(a==0 && b==0)
            {
                cout<<c<<a<<b<<c;

            }
            else
            {
                if(c==0 && b==0)
                {
                    cout<<a<<c<<b<<a;

                }
                else
                {
                    if(a==0 && c==0)
                    {
                        cout<<b<<a<<c<<b;

                    }

                    else
                    {
                        if(a==b && a==c)
                        {
                            cout<<a<<b<<c;
                        }
                        else
                        {
                            if(a==b)
                            {
                                cout<<a<<c<<b;
                            }
                            else
                            {
                                if(a==c)
                                {
                                    cout<<a<<b<<c;
                                }
                                else
                                {
                                    if(b==c)
                                    {
                                        cout<<b<<a<<c;
                                    }
                                    else
                                    {

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

                                        if(min_==0)
                                        {
                                            cout<<mid<<min_<<max_<<min_<<mid;
                                        }
                                        else
                                        {
                                            cout<<min_<<mid<<max_<<mid<<min_;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }


return 0;
}
