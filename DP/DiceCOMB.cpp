#include <bits/stdc++.h>
#include <string>
//                 ---------- predefined functions----------
using namespace std;
#define int long long
#define all(n) (n).begin(), (n).end()
#define alll(n) (n).rbegin(), (n).rend()
#define pb push_back
#define pii pair<int, int>
#define loop(i, a, n) for (register int i = (a); i < (int)(n); ++i)
#define co cout <<
#define en << endl;
#define print(x) cout << x << endl;
#define no cout << "NO" << endl;
#define yes cout << "YES" << endl;
#define co cout <<
#define ed << endl;
// --------------------------
long long lcm(int a, int b) { return (a / __gcd(a, b)) * b; }
// ------substring check---------
bool find(string s, string p)
{
    return (s.find(p) != string::npos);
}
//------------ceil val------
int ceil(int a, int b)
{
    return a / b + (a % b != 0);
}
// ------PRefix sum--------------
vector<int> prefix_sum(const vector<int> &a)
{
    int res = 0;
    vector<int> prefix_sum(a.size());
    for (int i = 0; i < (a.size()); ++i)
    {
        prefix_sum[i] = res + a[i];
        res = prefix_sum[i];
    }
    return prefix_sum;
}
 
const int MOD = 1e9 + 7;
signed main()
{
//     int tt;
//     cin >> tt;
 
//     while (tt--)
//     {
 
    int n;
    cin>>n;
 
 vector<int> dp( n+1 );
 dp[0] = 1;
for(int i = 1 ; i <= n ; i++ )
{
    for(int j = 1 ;j <= 6 ; j++)
    {
        if( i - j >= 0) dp[i] = (dp[ i ] + dp[ i-j ]) % MOD ;
    }
}
   
    
co dp[n] ed
 
    }