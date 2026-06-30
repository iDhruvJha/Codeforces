#include <bits/stdc++.h>
using namespace std;

#define float double;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vvi = vector<vi>;
using vs = vector<string>;

#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define set_bits __builtin_popcountll
#define vb vector<bool>
// template <class K, class V>
// using m = map<K, V>;
template <class K, class V>
using umap = unordered_map<K, V>;

#define fsort(arr) sort(arr.begin(), arr.end())
#define sum(arr) accumulate(arr.begin(), arr.end(), 0LL)
#define maxel(arr) *ranges::max_element(arr)
#define minel(arr) *ranges::min_element(arr)
#define rsort(arr) sort(arr.rbegin(), arr.rend())
#define f(i, a, b) for (int i = a; i < b; i++)
#define rf(i, a, b) for (int i = a; i >= b; i--)
#define py cout << "YES\n";
#define pm cout << "-1\n";
#define pn cout << "NO\n";
#define endl "\n"
// #define int long long
#define MOD 1000000007

void yes(bool cond = true) { cout << (cond ? "YES" : "NO") << '\n'; }
void no(bool cond = true) { cout << (cond ? "NO" : "YES") << '\n'; }

template <class T>
istream &operator>>(istream &is, vector<T> &v) {
    assert(v.size() != 0);
    for (auto &x : v) is >> x;
    return is;
}

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    // check divisors up to sqrt(n)
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}


void solve(){
    int n ;
    cin >> n ;
    vi a(n) ;
    vi b(n) ;
    f(i,0,n){
        cin >> a[i] ;
    }
    f(i,0,n){
        cin >> b[i] ;
    }

    vi copy = a ;
    fsort(copy) ;
    f(i,0,n){
        if( b[i] < copy[i]){
            cout << -1 << endl ;
            return ;
        }
    }
    unordered_map<int,bool> mp ;
    set<int> ui ;
    ll need = 0 ;
    for(int i = 0 ; i < n ; i++ ){
        if( copy[i] != b[i]){
            ui.insert(b[i]) ;
            need += b[i] - copy[i] ;
        }
    }

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t ;
    cin >> t ;

    while (t--)
    {
        solve();
    }

    return 0;
}