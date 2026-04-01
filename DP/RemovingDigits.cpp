#include <bits/stdc++.h>
#include <string>
 
using namespace std;
#define int long long
#define ld long double
#define all(n) (n).begin(), (n).end()
#define alll(n) (n).rbegin(), (n).rend()
#define pb push_back
#define pii pair<int, int>
#define loop(i, a, n) for (register int i = (a); i < (int)(n); i++)
#define co cout <<
#define en << endl;
#define print(x) cout << x << endl;
#define no cout << "NO" << endl;
#define yes cout << "YES" << endl;
#define co cout <<
#define ed << endl;
#define bf bool flag = 0;
#define ff first
#define ss second
 
long long lcm(int a, int b) { return (a / __gcd(a, b)) * b; }
 
int gcd(int a, int b, int &x, int &y) // used to solve linear equation in 2 var ax + by = c and gcd(a,b)%c == 0;
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
 
int MODD = 1e9 + 7;
 
int Binary_Expo(int base, int power)
{
    int ans = 1;
    while (power)
    {
        if (power % 2)
        {
            ans = (ans * base) % MODD;
            power = power - 1;
        }
        else
        {
            base = (base * base) % MODD;
            power = power / 2;
        }
    }
    return ans;
}
 
vector<int> factorial(1000004);
vector<int> modinv(1000004);
 
void precompute_factorial()
{
    modinv[0] = 1;
    factorial[0] = 1;
 
    for (int i = 1; i <= 1000000; i++)
    {
        factorial[i] = (factorial[i - 1] * i) % MODD;
        modinv[i] = Binary_Expo(factorial[i], MODD - 2);
    }
}
 
int ncr(int n, int r)
{
    if (n < 0 || r < 0 || r > n)
        return 0;
    return (((factorial[n] * modinv[r]) % MODD) * modinv[n - r]) % MODD;
}
 
long long compute_hash(string const &s)
{
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s)
    {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}
 
int ceil(int a, int b)
{
    return (a + b - 1) / b;
}
 
bool isBit_set(int n, int k)
{
    if (n & (1 << k))
        return 1;
    else
        return 0;
}
 
string decToBinary(int x)
{
    string s = "";
    for (int i = 0; i < 32; i++)
    {
        s += (x & 1) ? '1' : '0';
        x >>= 1;
    }
    return s;
}
 
int binaryToDecimal(string n)
{
    string num = n;
    int dec_value = 0;
    int base = 1;
    int len = num.length();
    for (int i = len - 1; i >= 0; i--)
    {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
    return dec_value;
}
 
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
 
vector<int> prefixisum(const vector<int> &a)
{
    int res = 0;
    vector<int> prefixisum(a.size());
    for (int i = 0; i < (a.size()); ++i)
    {
        prefixisum[i] = res + a[i];
        res = prefixisum[i];
    }
    return prefixisum;
}
 
const int N = 1e6;
vector<int> primes;
void sieve()
{
    vector<bool> prime(N + 1, true);
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= N; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= N; p++)
    {
        if (prime[p])
        {
            primes.push_back(p);
        }
    }
}
 
vector<int> spf(N);
void smallest_prime_factor()
{
    for (int i = 2; i <= N; i++)
        spf[i] = i;
 
    for (int p = 2; p * p <= N; p++)
    {
        if (spf[p] != p)
            continue;
 
        for (int i = p * p; i <= N; i += p)
        {
 
            if (spf[i] == i)
            {
                spf[i] = p;
            }
        }
    }
}
 
 
 
signed main()
{
int n;
cin>>n;
vector<int> dp(n+1,1e10);
auto func =[&] (int m) ->vector<int>
{
    vector<int> c;
   while(m)
   {
     c.pb(m%10);
    m/=10;
       }
return c;
};
 
for(int i=1;i<=min(n,9LL);i++) dp[i] = 1;
 
for(int i=10;i<=n;i++)
{
   vector<int> arr = func(i);
     for(int j=0;j<arr.size();j++)
     {
    dp[i] =min(dp[i] , dp[i-arr[j]] +1 );
     }
}
co dp[n] ed 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
}