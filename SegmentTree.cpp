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
		//here i, and val means the value(i) whicch we want to update with a value(val).
		//so i = curr_value, val = updated value which we want to update
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
