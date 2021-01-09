/**
*
* Solution to homework assignment 3
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

int getSize(char str[])
{
    int i=0;
    while(str[i]!='\0')
    {
        i++;
    }
    return i;
}
bool inputVerify(char str[])
{
    bool cap=false;
    int i=0;
    if(getSize(str)>150){
        return true;
    }
    while(str[i]!='\0')
    {
        if(str[i]<'a'||str[i]>'z')
        {
            cap=true;
        }
        i++;
    }
    return cap;
}

int numOfFind(char str[], char a, bool left,int s)
{
    int br=0;
    int i=0;
    if(left)
    {
        for(int i=0; i<s; i++)
        {
            if(str[i]==a)
            {
                br++;
            }
        }
    }
    else
    {
        for(int i=getSize(str)-1; i>=getSize(str)-s; i--)
        {
            if(str[i]==a)
            {
                br++;
            }
        }
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


bool leftJoin(char a[],char join[])
{
    int num=0;
    char counted[151];
    int n=getSize(a),c=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(!itsNotCounted(counted,a[i]))
            {
                if(a[i]==join[j])
                {
                    num+=numOfFind(join,a[i],true,n);
                    counted[c]=a[i];c++;
                }
            }
        }
    }
    if(num==n)
    {
        return true;
    }
    return false;
}

bool rightJoin(char a[],char join[])
{
    int num=0;
    char counted[151];
    int n=getSize(a),c=0;

    for(int i=0; i<n; i++)
    {
        for(int j=getSize(join)-1; j>=getSize(join)-n;j--)
        {
            //cout<<join[i]<<"=="<<a[i]<<endl;
            if(!itsNotCounted(counted,a[i]))
            {
                if(a[i]==join[j])
                {
                    num+=numOfFind(join,a[i],false,n);
                    counted[c]=a[i];c++;
                }
            }
        }
    }
    if(num==n)
    {
        return true;
    }
    return false;
}

bool joined(char a[],char b[],char join[])
{
    if(getSize(a)+getSize(b)!=getSize(join))
    {
        return false;
    }
    else
    {
        if(leftJoin(b,join)&&rightJoin(a,join))
        {
            return true;
        }
        else
        {
            if(leftJoin(a,join)&&rightJoin(b,join))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

int main()
{
    char str1[151],str2[151],str3[151];
    cin>>str1>>str2>>str3;
    if(inputVerify(str1)||inputVerify(str2)||inputVerify(str3))
    {
        cout<<-1;
    }
    else
    {
        cout<<joined(str1,str2,str3);
    }
    return 0;
}
