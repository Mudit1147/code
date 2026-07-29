#include<iostream>
using namespace std;

int main(){
    int n,x,y,maxE;
    cin>>n>>x>>y;
    
    if(y>x*2) cout<<((n/2)*y)+((n%2)*x)<<endl;
    else if (y<=x*2) cout<<n*x<<endl;
    else cout<<n*x<<endl;
    return 0;
}