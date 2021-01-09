/**
*
* Solution to homework assignment 3
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

char arr[10000][100];
int _size=0, sizeSTR=0;

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
    if(getSize(str)>100)
    {
        return false;
    }
    for(int i=0; i<getSize(str); i++)
    {
        if((str[i]<'a'||str[i]>'z')&&(str[i]<'A'||str[i]>'Z'))
        {
            return false;
        }
    }
    return true;
}

int compare(char a[],char b[],int n)
{
    for(int i=0; i<n; i++)
    {
        if(a[i]!=b[i])
            return 0;
    }
    return 1;
}

bool counted(char a[],int n)
{
    for(int i=0; i<n; i++)
    {
        char an[sizeSTR];
        for(int j=0; j<sizeSTR; j++)
        {
            an[j]=arr[i][j];
        }
        if(compare(an,a,sizeSTR))
        {
            return true;
        }
    }
    return false;
}


char* subStr(char str[],int start, int end_){
    int n=end_-start;
    char* result = new char[n];
    for (int i = 0; i < n; i++){
        result[i] = *(str + start + i);
    }
    result[n] = '\0';
    return result;
}

void inArr(char a[]){
    int n=getSize(a);
    for(int j=0;j<sizeSTR;j++){
        if(j<n) {arr[_size][j]=a[j];}
        else{arr[_size][j]=0;}
    }
    _size++;
}
void printArr(){
    for(int i=0; i<_size; i++)
    {
        for(int j=0; j<sizeSTR; j++)
        {
           cout<<arr[i][j];
        }
        cout<<endl;
    }

}

char* eraseCh(char str[],int p){
    for (int i = p; i < getSize(str) - 1; i++){
            str[i] = str[i + 1];
    }
    str[getSize(str)-1]='\0';
    return str;
}
void subsequence(char str[])
{
    for (int i = 0; i < getSize(str); i++)
    {

        for (int j = getSize(str); j>i; j--)
        {
            int a=j-i;
            char* sub=new char[a];
            sub=subStr(str,i,j);
            inArr(sub);
            for (int k = 1; k < a-1; k++)
            {
                char* str1 =new char[a];
                str1=eraseCh(sub,k);
                //cout<<"sub: "<<sub<<"\n"<<k<<"->"<<str1<<endl;
                subsequence(str1);
            }
        }
    }
}


int numOfUniStr(char str[])
{
    int br=0;
    subsequence(str);
   //printArr();
    //cout<<"____________________________"<<endl;
    for(int i=0; i<_size; i++)
    {
        char an[sizeSTR];
        for(int j=0; j<sizeSTR; j++)
        {
            an[j]=arr[i][j];
        }
        //cout<<an<<endl;
        if(!counted(an,i))
        {
            br++;
          // cout<<i<<"->"<<br<<endl;
        }
       //cout<<endl;
    }
    //  cout<<br;
          // cout<<endl;

    return br;
}

int main()
{
    char str[100];
    cin>>str;
    sizeSTR=getSize(str);
    cout<<numOfUniStr(str);
    //printArr();
    return 0;
}
