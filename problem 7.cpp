
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
#define check_bit(mask, bit) (mask & (1LL << bit)) // checks it
#define ss second
#define ff first
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
    for (int i = 0; i < (int)(a.size()); ++i)
    {
        prefix_sum[i] = res + a[i];
        res = prefix_sum[i];
    }
    return prefix_sum;
}

signed main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin); //file input.txt is opened in reading mode i.e "r"
    //     freopen("output.txt","w",stdout);  //file output.txt is opened in writing mode i.e "w"
    // #endif
    int k;
    cin >> k;
    int ans=0;
    for (int x = 1; x <= k; x++)
    {
      int p=  4 * ( x-1 ) * (x-2);
      int q = ( x * x ) * ( x * x - 1) / 2;
      ans  = q-p;
            
        co ans ed
    }
    // co ans ed
}
