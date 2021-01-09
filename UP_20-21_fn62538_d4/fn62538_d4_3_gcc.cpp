/**
*
* Solution to homework assignment 4
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

struct Fraction
{
    int numerator;
    int denominator;
    Fraction()
    {
        numerator=0;
        denominator=1;
    }
    Fraction(int n,int d)
    {
        numerator=n;
        denominator=d;
    }
};

bool verifyDen(int d)
{
    if(d!=0)
    {
        return true;
    }
    return false;
}
bool verifyOp(char op)
{
    if(op=='+'||op=='-'||op=='*'||op=='/')
    {
        return true;
    }
    return false;
}

Fraction operator*(Fraction a, Fraction b)
{
    int resultN=0, resultD=1;
    resultN=a.numerator*b.numerator;
    resultD=a.denominator*b.denominator;
    return Fraction(resultN,resultD);
}

Fraction operator/(Fraction a, Fraction b)
{
    int resultN=0, resultD=1;
    resultN=a.numerator*b.denominator;
    resultD=a.denominator*b.numerator;
    return Fraction(resultN,resultD);
}

Fraction operator+(Fraction a, Fraction b)
{
    int resultN=0, resultD=1;
    if(a.denominator!=b.denominator)
    {
        resultD=a.denominator*b.denominator;
        resultN=a.numerator*b.denominator+b.numerator*a.denominator;
    }
    else
    {
        resultD=a.denominator;
        resultN=a.numerator+b.numerator;
    }
    return Fraction(resultN,resultD);
}
Fraction operator-(Fraction a, Fraction b)
{
    int resultN=0, resultD=1;
    if(a.denominator!=b.denominator)
    {
        resultD=a.denominator*b.denominator;
        resultN=a.numerator*b.denominator-b.numerator*a.denominator;
    }
    else
    {
        resultD=a.denominator;
        resultN=a.numerator-b.numerator;
    }
    return Fraction(resultN,resultD);
}

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

Fraction simplified(Fraction a)
{
    int d=1;
    int resultN=a.numerator, resultD=a.denominator;
    d=gcd(resultN,resultD);
    resultN=a.numerator/d;
    resultD=a.denominator/d;
    if(resultD<0)
    {
        resultD*=(-1);
        resultN*=(-1);
    }
    return Fraction(resultN,resultD);
}

int* fractionCalculator(int aN,int aD,int bN, int bD, char op)
{
    //int r[2];
    Fraction a= Fraction(aN,aD);
    Fraction b= Fraction(bN,bD);
    Fraction result=Fraction();
    switch(op)
    {
    case '*':
        result=a*b;
        break;
    case '+':
        result=a+b;
        break;
    case '-':
        result=a-b;
        break;
    case '/':
        result=a/b;
        break;
    }
    result=simplified(result);
    static int r[2]={result.numerator,result.denominator};
    return r;
}

int main()
{
    int aN=0,aD=1,bN=0,bD=1;
    char op=0;
    int *result=new int[2];
    cin>>aN>>aD;
    if(!verifyDen(aD))
    {
        cout<<-1;
        return 0;
    }
    cin>>op;
    if(!verifyOp(op))
    {
        cout<<-1;
        return 0;
    }
    cin>>bN>>bD;
    if(!verifyDen(bD))
    {
        cout<<-1;
        return 0;
    }
    result=fractionCalculator(aN,aD,bN,bD,op);
    cout<<result[0]<<" "<<result[1];
    return 0;
}
