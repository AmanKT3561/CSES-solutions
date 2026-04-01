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
 
class Combinatorics
{
private:
    const int MODD = 998244353;
    vector<int> factorial;
    vector<int> modinv;
 
    int Binary_Expo(long long base, long long power)
    {
        long long ans = 1;
        while (power)
        {
            if (power & 1)
                ans = (ans * base) % MODD;
            base = (base * base) % MODD;
            power >>= 1;
        }
        return ans;
    }
 
public:
    Combinatorics(int limit = 1000000)
    {
        factorial.resize(limit + 1);
        modinv.resize(limit + 1);
        precompute_factorial(limit);
    }
 
    void precompute_factorial(int limit)
    {
        factorial[0] = 1;
        modinv[0] = 1;
        for (int i = 1; i <= limit; i++)
        {
            factorial[i] = (1LL * factorial[i - 1] * i) % MODD;
            modinv[i] = Binary_Expo(factorial[i], MODD - 2);
        }
    }
 
    int ncr(int n, int r) const
    {
        if (n < 0 || r < 0 || r > n)
            return 0;
        return (1LL * factorial[n] * modinv[r] % MODD * modinv[n - r]) % MODD;
    }
 
    int fact(int n)
    {
        if (n < 0 || n >= (int)factorial.size())
            throw out_of_range("Factorial not precomputed for this n");
        return factorial[n];
    }
};
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
 
// Function to compute the LPS (Longest Prefix Suffix) array
vector<int> computeLPS(string pattern)
{
    int m = pattern.size();
    vector<int> lps(m, 0);
    int len = 0;
    int i = 1;
 
    while (i < m)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
 
    return lps;
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
 
class TrieNode
{
public:
    vector<TrieNode *> v;
    bool isEnd;
    TrieNode() : v(26, nullptr), isEnd(false) {}
};
// TRIE
// Trie
struct Node
{
    Node *links[26];
    bool flag = false;
 
    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }
 
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
 
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
 
    bool isEnd()
    {
        return flag;
    }
 
    void setEnd()
    {
        flag = true;
    }
};
class Trie
{
private:
    Node *root;
 
public:
    Trie()
    {
        root = new Node();
    }
 
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
                node->put(word[i], new Node());
 
            node = node->get(word[i]);
        }
        node->setEnd();
    }
 
    bool checkIfPrefixExist(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            node = node->get(word[i]);
            if (node->flag == false)
                return false;
        }
        return true;
    }
};
 
class ModMath
{
private:
    const int MOD = 1e9 + 7;
 
public:
    inline int add(long long a, long long b) const { return ((a % MOD + b % MOD) % MOD + MOD) % MOD; }
    inline int sub(long long a, long long b) const { return ((a % MOD - b % MOD) % MOD + MOD) % MOD; }
    inline int mul(long long a, long long b) const { return ((a % MOD) * (b % MOD)) % MOD; }
 
    inline int power(long long a, long long b) const
    {
        long long res = 1;
        a %= MOD;
        while (b > 0)
        {
            if (b & 1)
                res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }
 
    inline int modinv(long long a) const { return power(a, MOD - 2); }
    inline int mod() const { return MOD; }
};
 
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
 
// DISJOINT SET UNION FIND
 
class DisjointSet
{
    vector<int> rank, parent, size;
 
public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
 
    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
 
    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
 
    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
vector<vector<int>> pre(40, vector<int>(2e5 + 1));
 
class SEIVE
{
public:
    vector<int> spf;
    SEIVE(int size)
    {
        spf.assign(size + 1, 0);
        if (size >= 0)
            spf[0] = 0;
        if (size >= 1)
            spf[1] = 1;
        for (long long i = 2; i <= size; i++)
        {
            if (spf[i] == 0)
            {
                spf[i] = i;
                for (long long j = i * i; j <= size; j += i)
                {
                    if (spf[j] == 0)
                        spf[j] = i;
                }
            }
        }
    }
    set<int> factorise(int n)
    {
        set<int> res;
        if (n <= 0)
            return res;
        while (n != 1)
        {
            int p = spf[n];
            if (p == 0)
            {
                res.insert(n);
                break;
            }
            res.insert(p);
            n = n / p;
        }
        return res;
    }
};
 
class SparseTable
{
    vector<vector<int>> sparsetablematrix;
    vector<int> sparselogarray;
    int n;
 
public:
    SparseTable(vector<int> &arr)
    {
        n = arr.size();
        sparselogarray.resize(n + 1);
        sparselogarray[1] = 0;
        for (int i = 2; i <= n; i++)
            sparselogarray[i] = sparselogarray[i / 2] + 1;
 
        int K = sparselogarray[n] + 1;
        sparsetablematrix.assign(n, vector<int>(K));
 
        for (int i = 0; i < n; i++)
            sparsetablematrix[i][0] = arr[i];
 
        for (int j = 1; j < K; j++)
        {
            for (int i = 0; i + (1 << j) <= n; i++)
            {
                sparsetablematrix[i][j] = min(sparsetablematrix[i][j - 1], sparsetablematrix[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
 
    int query(int L, int R)
    {
        int j = sparselogarray[R - L + 1];
        return min(sparsetablematrix[L][j], sparsetablematrix[R - (1 << j) + 1][j]);
    }
};
 
class SegmentTree
{
    vector<int> seg;
    int n;
 
    void build(vector<int> &arr, int idx, int low, int high)
    {
        if (low == high)
        {
            seg[idx] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(arr, 2 * idx + 1, low, mid);
        build(arr, 2 * idx + 2, mid + 1, high);
        seg[idx] = (seg[2 * idx + 1] + seg[2 * idx + 2]);
    }
 
    int queryUtil(int idx, int low, int high, int l, int r)
    {
        if (r < low || high < l)
            return 0; // no overlap
        if (l <= low && high <= r)
            return seg[idx]; // total overlap
        int mid = (low + high) / 2;
        int left = queryUtil(2 * idx + 1, low, mid, l, r);
        int right = queryUtil(2 * idx + 2, mid + 1, high, l, r);
        return (left + right);
    }
 
    void updateUtil(int idx, int low, int high, int pos, int val)
    {
        if (low == high)
        {
            seg[idx] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (pos <= mid)
            updateUtil(2 * idx + 1, low, mid, pos, val);
        else
            updateUtil(2 * idx + 2, mid + 1, high, pos, val);
        seg[idx] = (seg[2 * idx + 1] + seg[2 * idx + 2]);
    }
 
public:
    SegmentTree(vector<int> &arr)
    {
        n = arr.size();
        seg.assign(4 * n, 0);
        build(arr, 0, 0, n - 1);
    }
 
    int query(int l, int r)
    {
        return queryUtil(0, 0, n - 1, l, r);
    }
 
    void update(int pos, int val)
    {
        updateUtil(0, 0, n - 1, pos, val);
    }
};
 
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, q;
    cin >> n >> q;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    vector<int> adj[n + 3];
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        int y;
        cin >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vector<int> flat;
    int cnt = 0;
    map<int, pair<int, int>> mp;
 
    function<void(int, int)> dfs = [&](int node, int par)
    {
        flat.pb(node);
        mp[node].ff = cnt;
        cnt++;
        for (auto i : adj[node])
        {
            if (i == par)
                continue;
            dfs(i, node);
        }
        flat.pb(node);
        mp[node].ss = cnt;
        cnt++;
    };
    dfs(1, 0);
    // for (auto i : flat)
    //     co i << " ";
    vector<int> visited(n + 1);
    vector<int> segtr;
 
    for (auto i : flat)
    {
        if (!visited[i])
        {
            visited[i]++;
            segtr.pb(arr[i]);
        }
        else
        {
            segtr.pb(0);
        }
    }
    // for(auto i:segtr) co i<<" ";
    // cout<<endl;
    // for(auto i:mp)
    // {
    //     co i.ff <<"->"<<i.ss.ff<<" "<<i.ss.ss ed
    // }
    SegmentTree st(segtr);
    while (q--)
    {
        int a;
        cin>>a;
        if(a == 2)
        {
            int node;
            cin>>node;
            int ans = st.query(mp[node].ff , mp[node].ss);
            co ans ed
        }
        else{
            int node , val;
            cin>>node>>val;
            st.update(mp[node].ff , val);
        }
    }
}