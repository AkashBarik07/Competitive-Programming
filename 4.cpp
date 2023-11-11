#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define nl '\n'
const int mod = 1000000007;

class SGTree{
	vector<int> seg;
public:
	SGTree(int n){
		seg.resize(4 * n + 1);
	}

	void build(int ind, int low, int high, int arr[]){
		if(low == high){
			seg[ind] = arr[low];
			return;
		}

		int mid = (low + high)/2;
		build(2 * ind + 1, low , mid , arr);
		build(2 * ind + 2, mid + 1, high, arr);
		// seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
		// seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
		seg[ind] = (seg[2 * ind + 1] ^ seg[2 * ind + 2]);
		// seg[ind] = (seg[2 * ind + 1] & seg[2 * ind + 2]);
	}

	int query(int ind, int low, int high, int l, int r){
		//no overlap 
		//l r, low high or low high l r
		if(r < low || high < l) return INT_MAX;

		//complete overlap
		//[l  low high  r]

		if(low >= l && high <= r) return seg[ind];
		int mid = (low + high) / 2;
		int left = query(2 * ind + 1, low , mid , l, r);

		int right = query(2 * ind + 2, mid + 1, high, l, r);
		// return min(left, right);
		// return max(left, right);
		return (left ^ right);
		// return (left & right);
	}
	void update(int ind, int low, int high, int i, int val){
		if(low == high){
			seg[ind] = val;
			return;
		}

		int mid = (low + high)/2;
		if(i <= mid) update(2 * ind + 1, low, mid, i, val);
		else update(2 * ind + 2, mid + 1, high, i, val);

		// seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
		// seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
		seg[ind] = (seg[2 * ind + 1] ^ seg[2 * ind + 2]);
		// seg[ind] = (seg[2 * ind + 1] & seg[2 * ind + 2]);
	}
};

class DisjointSet{
	vector<int> rank, parent, size;
public:
		DisjointSet(ll n) {
		rank.resize(n + 1, 0);
		parent.resize(n + 1);
		size.resize(n + 1, 1);
		for(ll i = 1; i <= n; i++) parent[i] = i;
	}

	void unionByRank(ll x, ll y) {

		ll par_x = findPar(x);
		ll par_y = findPar(y);

		if(par_x == par_y) return;

		if(rank[par_x] < rank[par_y]) {
			parent[par_x] = par_y;
		} else if(rank[par_y] < rank[par_x]) {
			parent[par_y] = par_x;
		} else {
			parent[par_x] = par_y;
			rank[par_y]++;
		}
	}

	void unionBySize(ll x, ll y) {

		ll par_x = findPar(x);
		ll par_y = findPar(y);

		if(par_x == par_y) return;

		if(size[par_x] < size[par_y]) {
			parent[par_x] = par_y;
			size[par_y] += size[par_x];
		} else {
			parent[par_y] = par_x;
			size[par_x] += size[par_y];
		}
	}

	ll findPar(ll x) {

		if(parent[x] == x) return x;

		return parent[x] = findPar(parent[x]);

	}

};


ll binpow(ll a,ll b) {
    ll ans = 1;
    while(b > 0) {
        if((b & 1) == 1) ans *= a;
        a *= a;
        b = b >> 1;
    }
    return ans;
}

ll binpowmod(ll a,ll b) {
    ll ans = 1;
    while(b > 0) {
        if((b & 1) == 1) {
        	ans *= a;
        	ans %= mod;
        }
        a *= a;
        a %= mod;
        b = b >> 1;
    }
    return ans;
}


ll gcd(ll a,ll b) {
	if(b == 0) return a;
	return gcd(b, a % b);
}

ll lcm(ll a,ll b) {
	return (a / gcd(a,b)) * b;
}

const ll MAX = 2e5 + 7;
vector<ll> fact(MAX);
 
ll add(ll a, ll b) {
	return (a + b) % mod;
}
 
ll sub(ll a, ll b) {
	return ((a - b) % mod + mod) % mod;
}
ll mult(ll a, ll b) {
	return ((a * b) % mod);
}

ll inv(ll a) {
	return binpowmod(a, mod - 2);
}
 
ll divide(ll a, ll b) {
	return mult(a, inv(b));
}
 
ll nCr(ll n, ll r) {
	if(n < r) return 0;
	return divide(fact[n], mult(fact[r], fact[n - r]));
}
 
void preFactorial() {
	fact[0] = 1;
	for(ll i = 1; i < MAX; i++) fact[i] = mult(i, fact[i - 1]);
}

bool isVowel(char c) {
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
	if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
	return false;
}

bool isSame(ll n, ll arr[]) {
	for(ll i = 0; i < n; i++) {
		if(arr[i] != arr[0]) return false;
	}
	return true;
}

bool isSame(ll n, vector<ll> &arr) {
	for(ll i = 0; i < n; i++) {
		if(arr[i] != arr[0]) return false;
	}
	return true;
}

bool isSorted(ll n, ll arr[]) {
	for(ll i = 1; i < n; i++) {
		if(arr[i] < arr[i - 1]) return false;
	}
	return true;
}
bool isSorted(ll n, vector<ll> &arr) {
	for(ll i = 1; i < n; i++) {
		if(arr[i] < arr[i - 1]) return false;
	}
	return true;
}

void inputArr(ll n, ll arr[]) {
	for(ll i = 0; i < n; i++) cin >> arr[i];
}

void inputArr(ll n, vector<ll> &arr) {
	ll x;
	for(ll i = 0; i < n; i++) {
		cin >> x;
		arr.push_back(x);
	}
}

void printArr(ll n, ll arr[]) {
	for(ll i = 0; i < n; i++) cout << arr[i] << " ";
	cout << nl;
}

void printArr(ll n, vector<ll> &arr) {
	for(ll i = 0; i < n; i++) cout << arr[i] << " ";
	cout << nl;
}
void leftRotate(vector<int>& v, int n, int k) {
    k %= n;
    reverse(v.begin(), v.begin() + k);
    reverse(v.begin() + k, v.begin() + n);
    reverse(v.begin(), v.begin() + n);
}
// rightRotate
void rightRotate(vector<int>& v, int n, int k) {
    k %= n;
    reverse(v.begin(), v.begin() + n);
    reverse(v.begin(), v.begin() + k);
    reverse(v.begin() + k, v.begin() + n);
}

ll sumOfArr(ll n, ll arr[]) {
	ll ans = 0;
	for(ll i = 0; i < n; i++) ans += arr[i];
	return ans;
}

ll sumOfArr(ll n, vector<ll> &arr) {
	ll ans = 0;
	for(ll i = 0; i < n; i++) ans += arr[i];
	return ans;
}

bool isPrime(ll n) {
	if(n == 1) return false;
	for(ll i = 2; i <= sqrt(n); i++) {
		if(n % i == 0) return false;
	}
	return true;
}
ll countSetBits(ll n) {
	ll ans = 0;
	while(n) {
		ans++;
		n = n & (n - 1);
	}
	return ans;
}

vector<ll> primeFactorization(ll n) {
	vector<ll> factors;
	for(ll i = 2; i * i <= n; i++) {
		ll cnt = 0; 
		while(n % i == 0) {
			cnt++;
			n /= i;
			factors.push_back(i);
		}
	}
	if(n > 1) factors.push_back(n);
	return factors;
}

/*vector<bool>isPrime(N, 1);
vector<int> primes;

void sieveOfEra() {
    isPrime[0] = false;
    isPrime[1] = false;

    for(ll i = 2; i <= N; i++){
    	if(isPrime[i] == true){
    		for(ll j = i * i; j <= N; j += i){
    			isPrime[j] = false;
    		}
    	}
    }

    primes.push_back(2);
    for (ll i = 3; i <= N; i += 2) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
}*/

bool isPalindrome(string s) {
	ll i = 0;
	ll j = s.size() - 1;
	while(i <= j) {
		if(s[i] != s[j]) return false;
		i++;
		j--;
	}
	return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    DisjointSet ds(n);

    int cnt = 0;
    vector<int> component_sizes(n, 0);

    while (m--) {
        int u, v;
        cin >> u >> v;

        u--, v--;

        // Check if u and v are in the same component
        if (ds.findPar(u) == ds.findPar(v)) {
            // If they are in the same component, it means the current edge forms a cycle.
            // You can increment the count of cyclic components.
            cnt++;
        } else {
            // If they are not in the same component, merge them and update the component sizes.
            ds.unionBySize(u, v);
        }
    }

    // Now, count the number of connected components.
    for (int i = 0; i < n; i++) {
        component_sizes[ds.findPar(i)]++;
    }

    // The number of cyclic components is the number of components with size greater than 1.
    int cyclic_components = 0;
    for (int i = 0; i < n; i++) {
        if (component_sizes[i] > 1) {
            cyclic_components++;
        }
    }

    cout << cyclic_components << endl;
}

void solve(){
	int n, q;
	cin>>n>>q;

	vector<int> v(n);
	for(int i = 0; i < n; i++) cin>>v[i];

	while(q--){
		int type;
		cin>>type;

		if(type == 1){
			int l, r;
			cin>>l>>r;

			SGTree sg(n);
			sg.build(0, l, r, v);
		}
		else{
			int x;
			cin>>x;
		}
	}
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
    	solve();
    }
    // solve();
    return 0;
}
