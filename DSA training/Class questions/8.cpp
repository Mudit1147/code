#include<iostream>
using namespace std;

int SOD(int n){
    int sum=0;
    while(n){
        sum+=n%10;
        n/=10;
    }
    return sum;
}

// function for checking if a number is prime
int isPrime(int n) {
    if (n <= 1) return 0;
    for (int j = 2; j * j <= n; j++) {
        if (n % j == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int start, end;
    cin >> start >> end;
    int count = 0;
    for(int i=start; i<=end; i++){
        if(isPrime(i)){
            int sum = SOD(i);
            if(sum%2==0){
                count++;
            }
        }
    }
    cout << count;
}