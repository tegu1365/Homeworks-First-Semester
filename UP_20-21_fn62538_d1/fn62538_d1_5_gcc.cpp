 /**
*
* Solution to homework assignment 1
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
using namespace std;

bool numCheck(int num){
    while(num%2==0){
        num/=2;
    }
    while(num%5==0){
        num/=5;
    }
    if(num==1){
        return true;
    }else{
        return false;
    }
}

int main(){
   double a=1.0;
   int num=1;
   int i=0;

   cin>>num;

   if(numCheck(num)){
       a/=num;

       while(a!=(int)a){
            a=a*10;
            //cout<<a<<endl;
            i++;
       }
       cout<<i;
   }else{
       cout<<"NO";
   }
   return 0;
}
