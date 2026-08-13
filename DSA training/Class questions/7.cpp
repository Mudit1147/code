#include<iostream>
using namespace std;

int main(){
    int start,end;
    cin>> start>>end;
    int count=0;
    for(int i=start;i<=end;i++){
        if(i%3==0){
            //sum of digits
            int sum=0;
            int temp=i; 
            while(temp>0){
                sum+=temp%10;
                temp/=10;
            }
            if(sum%2==0){
                count++;
            }
        }
    }
    cout<<count;
}