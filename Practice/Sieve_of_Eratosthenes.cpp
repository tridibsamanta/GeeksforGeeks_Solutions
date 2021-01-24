/**
 * Title   : Sieve of Eratosthenes
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/sieve-of-eratosthenes5242/1
 **/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function Template for C++
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N) {

        vector<int> primes;
        vector<bool> isPrime(N + 1, true);

        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= N; ++i) {

            if (isPrime[i]) {

                for (int j = i * i; j <= N; j += i)
                    isPrime[j] = false;
            }
        }

        for (int i = 2; i <= N; ++i) {
            if (isPrime[i])
                primes.emplace_back(i);
        }

        return primes;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
