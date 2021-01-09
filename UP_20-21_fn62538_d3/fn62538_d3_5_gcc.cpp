/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Teodora Petkova
* @idnumber 62538
* @task 5
* @compiler GCC
*
*/


#include<iostream>
#include<fstream>
#include<algorithm>
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
void clean(char *str)
{
    for(int i=0; str[i] != '\0'; i++)
    {
        str[i] = '\0';
    }
}
char deshif(char str[])
{
    int n=getSize(str);
    sort(str,str+n);
    char a=str[1];
    for(int i=1; i<n; i++)
    {
        if(a==str[i])
        {
            if(a=='Z')
            {
                a='a';
            }else{
                a++;
            }
            if(a=='z'){
                a='.';
            }
        }
        else
        {
            break;
        }
    }
    return a;
}
bool inputVerify(char ch)
{
    if((ch<'a'||ch>'z')&&(ch<'A'||ch>'Z')&&ch!='\n'&&ch!='\n')
    {
        return false;
    }
    return true;
}

int main()
{
    fstream read("message.txt",ios::in);
    char line[150],message[150];
    int br=0,i=0;
    char ch;
    if(!read.is_open())
    {
        cout<<-2;
        return 0;
    }

    while (!read.eof())
    {
        read.get(ch);
      //  cout<<ch;
        if(!inputVerify(ch))
        {
           cout<<-1;
           break;
        }
        line[br]=ch;
        br++;
        if(br==150||ch=='\n')
        {
            message[i]=deshif(line);
            i++;
            br=0;
            clean(line);
        }
    }
    cout<<message;
    read.close();
    return 0;
}
