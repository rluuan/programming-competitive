#include <bits/stdc++.h>

using namespace std;

class segt {
	private:
		int x;
		int *tree;
		int *arr;
	public:
		segt() {
			x = 0;
			tree = new int[10];
			arr  = new int[10];
		}
		segt(int maxn) {
			x = maxn;
			tree = new int[x];
			arr  = new int[x];
		}
		void build(int node, int l, int r) {
			if (l == r) {
				tree[node] = arr[l];
				return;
			}
			int mid  = (l + r) >> 1;
			int left = no << 1;
			int right= no << 1 | 1;
			build(left, l, mid);
			build(right, mid + 1, r);
			tree[node] = tree[left] + tree[right];
		}
		void update(int node, int l, int r, int ix, int v) {
			if (l == r) {
				tree[node] = v;
				return ;
			}
			int mid  = (l + r) >> 1;
			int left = no << 1;
			int right= no << 1 | 1;
			if (ix <= mid) {
				update(left, l, mid, ix, v);
			} else if (ix > mid) {
				update(right, mid + 1, r, ix, v);
			}
			tree[node] = tree[left] + tree[right];
		}
		int query (int node, int l, int r, int ll, int rr) {
			if (l == ll && r == rr) {
				return tree[node];
			}
			int mid  = (l + r) >> 1;
			int left = no << 1;
			int right= no << 1 | 1;
			if (rr <= mid) {
				return query (left, l, mid, ll, rr);
			} else if (ll > mid) {
				return query(right, mid + 1, r, ll, rr);
			} else {
				return query(left, l, mid, ll, mid) + query(right, mid + 1, r, mid + 1, rr);
			}
		}
}
				
