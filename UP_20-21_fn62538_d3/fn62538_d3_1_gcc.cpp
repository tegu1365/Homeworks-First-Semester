/**
*
* Solution to homework assignment 3
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

int numOfFind(char str[], char a)
{
    int br=0;
    int i=0;
    while(str[i]!= '\0')
    {
        if(str[i]==a)
        {
            br++;
        }
        i++;
    }
    return br;
}

bool itsNotCounted(char str[],char a)
{
    bool counted=false;
    int i=0;
    while(str[i]!= '\0')
    {
        if(str[i]==a)
        {
            counted=true;
            break;
        }
        i++;
    }
    return counted;
}

bool correctStr(char str[])
{
    bool itIsCor=true;
    bool removeOne=false;
    int finds[150],a=0,n=0;
    char findsCh[150];
    while(str[a]!= '\0')
    {
        if(!itsNotCounted(findsCh,str[a]))
        {
            findsCh[n]=str[a];
            finds[n]=numOfFind(str,str[a]);
            n++;
        }
        a++;
    }

//     for(int i=0; i<n; i++)
//    {
//        cout<<findsCh[i]<<"->"<<finds[i]<<endl;
//    }
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(finds[i]!=finds[j])
            {
                if(!removeOne)
                {
                    if((finds[i]-1==finds[j]|| finds[i]-1==0) && finds[i]<finds[j])
                    {
                        removeOne=true;
                        finds[i]-=1;
                    }
                    else
                    {
                        if(finds[j]-1==finds[i]|| finds[j]-1==0)
                        {
                            removeOne=true;
                            finds[j]-=1;
                        }
                        else
                        {
                            itIsCor=false;
                            break;
                        }
                    }
                }
                else
                {
                    if(finds[i]!=0&&finds[j]!=0)
                    {
                        itIsCor=false;
                        break;
                    }
                }
            }
        }
    }
    return itIsCor;
}

int getSize(char str[])
{
    int i=0;
    while(str[i]!='\0')
    {
        i++;
    }
    return i;
}

int main()
{
    char str[151];
    cin>>str;
    if(getSize(str)>150)
    {
        cout<<-1;
    }
    else
    {
        cout<<correctStr(str);
    }
    return 0;
}
