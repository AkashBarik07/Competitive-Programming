#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define nl '\n'
const int mod = 1000000007;

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
