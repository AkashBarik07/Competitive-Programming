#include<bits/stdc++.h>
using namespace std;
//this is the most optimal approach (sieve algorithm) to find prime factorisation
const int N = 1e7+10;
vector<bool>isPrime(N,1);//initially we taking all N number is true(1,means prime)
int main(){
    // q = 10 ^ 7 and N = 10 ^ 7
    isPrime[0] = isPrime[1] = false;
    for(int i=2;i<N;i++){
        if(isPrime[i] == true){    //without if condition time complexity of this approach is O(logN)
            for(int j = 2*i;j<N;j+=i){
                isPrime[j] = false;
            }
        }
    }
 //  time complexity of this approach is O(N*(log(logN)))    

    int q;
    cin>>q;
    while(q--){
        int num;
        cin>>num;
        if(isPrime[num]){
            cout<<"prime"<<endl;
        }
        else{
            cout<<"not prime"<<endl;
        }
    }
}
// ----------------------------------------------------------------------------------------------------------------------------
//To find heighest prime and lowest prime number using sieve algoritham
/*
#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
vector<bool> isPrime(N, 1);
vector<int> lp(N, 0);
vector<int> hp(N, 0);
int main()
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < N; i++)
    {
        if (isPrime[i] == true)
        {
            lp[i] = hp[i] = i;
            for (int j = 2 * i; j < N; j += i)
            {
                isPrime[j] = false;
                hp[j] = i;
                if (lp[j] == 0)
                {
                    lp[j] = i;
                }
            }
        }
    }

    for (int i = 1; i < 100; i++)
    {
        cout << lp[i] << " " << hp[i] << endl;
    }
    return 0;
}
------------------------------------------------------------------------------------------------------------
*/
//Find prime factors of a number using sieve algorithm
/*
// ex- factorisation of 24 is 3 2 2 2.
#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
vector<bool> isPrime(N, 1);
vector<int> lp(N, 0);
vector<int> hp(N, 0);
int main()
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < N; i++)
    {
        if (isPrime[i] == true)
        {
            lp[i] = hp[i] = i;
            for (int j = 2 * i; j < N; j += i)
            {
                isPrime[j] = false;
                hp[j] = i;
                if (lp[j] == 0)
                {
                    lp[j] = i;
                }
            }
        }
    }

    int num;
    cin >> num;
    vector<int> prime_factors;
    while (num > 1)
    {
        int prime_factor = hp[num];
        while (num % prime_factor == 0)
        {
            num /= prime_factor; //------->here time complexity is O(logN)
            prime_factors.push_back(prime_factor);
        }
    }
    for (int factor : prime_factors)
    {
        cout << factor << " ";
    }
    cout << endl;
    return 0;
}
------------------------------------------------------------------------------------------------------------
// the same thing in count way how many power number have(using map) to find factorisation of a number
ex-here factorisation of 24 is
2 3
3 1


#include<bits/stdc++.h>
using namespace std;
const int N = 1e7+10;
vector<bool> isPrime(N,1);
vector<int> lp(N,0);
vector<int> hp(N,0);
int main() {
    isPrime[0] = isPrime[1] = false;
    for(int i=2;i<N;i++){
       if(isPrime[i] == true){
         lp[i] = hp[i] = i;
         for(int j = 2*i;j<N;j+=i){
            isPrime[j] = false;
            hp[j] = i;
            if(lp[j] == 0){
                lp[j] = i;
            }
         }
       }
    }

    int num;
    cin>>num;
    map<int,int>prime_factors; //------------>if i use here unordered_map then tc will be converted log(N) to O(1)
    while(num > 1){    //------->here time complexity is O(logN)
        int prime_factor = hp[num];
        while(num % prime_factor == 0){
            num /= prime_factor;
            prime_factors[prime_factor]++;
        }
    }
    for(auto factor: prime_factors){
        cout<<factor.first<<" "<<factor.second<<endl;
    }
    return 0;
}
------------------------------------------------------------------------------------------------------
//NOTE:: find all the devisors of a number
//it's very inportant

#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
vector<int> divisors[N];
int main() {
    for(int i=2;i<N;i++){
        for(int j = i;j<N;j+=i){
            divisors[j].push_back(i);
        }
    }
    //time complexity -> n/2+n/3+n/4+...n/n
    //n(1/2+1/3+1/4+....1/n) so tc is Nlog(N) that's why it will run till 1e6+10 but not run up to 1e7+10
    for(int i=1;i<100;i++){
        for(int div: divisors[i]){
            cout<<div<<" ";
        }
        cout<<endl;
    }
    return 0;
}
*/
