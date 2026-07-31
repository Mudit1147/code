#include<iostream>
using namespace std;

int main(){
    int a,b;
    cin>> a>>b;
    int la= ((a-1)/2)+1;
    int lb= ((b-2)/2)+1;
    if(la>lb){
        cout<<"limak";
    }
    else if(la==lb){
        cout<<"limak";
    }
    else{
        cout<<"bob";
    }
    return 0;
}