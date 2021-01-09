/**
*
* Solution to homework assignment 1
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
//#include<vector>
//#include <algorithm>

using namespace std;
int main(){

    int secondMax=-1, maxNum=-1, currentNum=0;
    cin>>currentNum;
    while(currentNum>0){
        if(currentNum>maxNum)
        {
            secondMax=maxNum;
            maxNum=currentNum;
        }
        else{
            if(currentNum>secondMax){
                secondMax=currentNum;
            }
       }
       // cout<<"secondMax= "<<secondMax<<"\n max= "<<maxNum<<endl;
        currentNum=0;
        cin>>currentNum;
    }

    cout<<secondMax;
//    vector<int> nums;
//    int a=0;
//
//    cin>>a;
//
//    while(a>0){
//        nums.push_back(a);
//        a=0;
//        cin>>a;
//    }
//
//    sort(nums.begin(),nums.end());
//
//    cout<<nums[nums.size()-2];

    return 0;
}
