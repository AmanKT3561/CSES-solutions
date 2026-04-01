#include <bits/stdc++.h>
#include <string>
 
using namespace std;
#define int long long
#define ld long double
#define aint(n) (n).begin(), (n).end()
#define aintl(n) (n).rbegin(), (n).rend()
#define pb push_back
#define pii pair<int, int>
#define loop(i, a, n) for (register int i = (a); i < (int)(n); i++)
#define co cout <<
#define en << endl;
#define print(x) cout << x << endl;
#define no cout << "No" << endl;
#define yes cout << "Yes" << endl;
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
public:
    static const int MAXN = 1000000;
    static const int MOD = 1e9 + 7;
 
    vector<int> factorial;
    vector<int> modinv;
 
    Combinatorics()
    {
        factorial.resize(MAXN + 1);
        modinv.resize(MAXN + 1);
        precompute_factorial();
    }
 
    int Binary_Expo(int base, int power)
    {
        int ans = 1;
        while (power)
        {
            if (power & 1)
            {
                ans = (1LL * ans * base) % MOD;
                power--;
            }
            else
            {
                base = (1LL * base * base) % MOD;
                power >>= 1;
            }
        }
        return ans;
    }
 
    void precompute_factorial()
    {
        factorial[0] = 1;
        modinv[0] = 1;
 
        for (int i = 1; i <= MAXN; i++)
        {
            factorial[i] = (1LL * factorial[i - 1] * i) % MOD;
            modinv[i] = Binary_Expo(factorial[i], MOD - 2);
        }
    }
 
    int ncr(int n, int r)
    {
        if (n < 0 || r < 0 || r > n)
            return 0;
        return (1LL * factorial[n] * modinv[r] % MOD * modinv[n - r]) % MOD;
    }
};
int MOD = 1e9 + 7;
int Binary_Expo0(int base, int power)
{
    int ans = 1;
    while (power)
    {
        if (power & 1)
        {
            ans = (1LL * ans * base) % MOD;
            power--;
        }
        else
        {
            base = (1LL * base * base) % MOD;
            power >>= 1;
        }
    }
    return ans;
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
    TrieNode() : v(26, NULL), isEnd(false) {}
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
void smaintest_prime_factor()
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
 
vector<int> tree, h;
 
void build(int idx, int l, int r)
{
    if (l == r)
    {
        tree[idx] = h[l];
        return;
    }
    int mid = (l + r) / 2;
    build(idx * 2 + 1, l, mid);
    build(idx * 2 + 2, mid + 1, r);
    tree[idx] = max(tree[idx * 2 + 1], tree[idx * 2 + 2]);
}
 
int query(int idx, int l, int r, int x)
{
    if (tree[idx] < x)
        return -1;
    if (l == r)
        return l;
 
    int mid = (l + r) / 2;
 
    if (tree[idx * 2 + 1] >= x)
        return query(idx * 2 + 1, l, mid, x);
    else
        return query(idx * 2 + 2, mid + 1, r, x);
}
 
void update(int idx, int l, int r, int pos, int x)
{
    if (l == r)
    {
        tree[idx] -= x;
        return;
    }
 
    int mid = (l + r) / 2;
 
    if (pos <= mid)
        update(idx * 2 + 1, l, mid, pos, x);
    else
        update(idx * 2 + 2, mid + 1, r, pos, x);
 
    tree[idx] = max(tree[idx * 2 + 1], tree[idx * 2 + 2]);
}
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
int in[200005];
int dp[200005];
int subtree[200005];
 int n;
void dfs(int node, int par, vector<int> adj[]) {
    in[node] = 0;
    subtree[node] = 1;
    for (auto it : adj[node]) {
        if (it == par) continue;
        dfs(it, node, adj);
        subtree[node] += subtree[it]; 
        in[node] += in[it] + subtree[it];
    }
}
 
void dfs2(int node, int par, vector<int> adj[]) {
   
    for (auto it : adj[node]) {
        if(it == par) continue;
        dp[it] = n - (long long)2*subtree[it] + dp[node];
        dfs2(it , node ,adj);
    }
}
 
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Combinatorics comb;
 
    
 
 
 
 cin>>n;
 vector<int> adj[n+1];
 
for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
} 
dfs( 1, 0 , adj);
dp[1] = in[1];
dfs2( 1, 0, adj);
 
 
for (int i = 1; i <= n; i++) {
    cout << dp[i] << " ";
}
 
    }
