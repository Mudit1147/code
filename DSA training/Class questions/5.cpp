#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int count, n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    count=0;
    for(int i=0; i<n; i++){
        if(arr[i]<x){
            count=std::max(count, i+1);
        }
        }
    cout << count << endl;
    return 0;
}
