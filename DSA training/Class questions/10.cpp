#include<iostream>
#include<vector>
using namespace std;

vector<int> sieveOfEratosthenes(int n) {
    vector<int> primes;
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i*i <= n; ++i) {
        if (isPrime[i]) {
           
            for (int j = i*i ; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

int main(){
    int n;
    cin>>n;

    vector<int> primes = sieveOfEratosthenes(1000);
    int c=0,i=0;
    while(c<=n){
        cout<<primes[i]<<" ";
        c++;
        if(c==n){
            break;
        }

        cout<<primes[i+1]<<" ";
        c++;
        if(c==n){
            break;
        }

        cout<<primes[i]*primes[i+1]<<" ";
        c++;
        i+=2;
    }
    return 0;
}

