#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 100000;
const int maxnt = 4 * maxn;
bool tree[maxnt];

void update(int node, int l, int r, int ll, int rr) {
	if (l > rr || ll > r) {
		return;
	}
	if (l == ll and r == rr) {
		tree[node] = !tree[node];
		return;
	}
	int mid   = (l + r) >> 1;
	int left  = node << 1;
	int right = node << 1 | 1;
	update(left, l, mid, ll, mid);
	update(right, mid + 1, r, mid + 1, rr);
	tree[node] = tree[left] + tree[right];
}
int query(int node, int l, int r, int ll, int rr) {
	
	if (ll <= l and r <= rr) {
		return tree[node];
	}
	if (l > rr || ll > r) {
		return 0;
	}
	int mid   = (l + r) >> 1;
	int left  = node << 1;
	int right = node <<1 | 1;
	return query(left, l, mid, ll, mid) + query(right, mid + 1, r, mid + 1, rr);

}
int main() {
	fast_io
	int n, m, k, s, e;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		tree[i] = 0;
	}
	n++;
	for (int i = 1; i <= m; ++i) {
		cin >> k >> s >> e;
		if (k == 0) {
			update(1, 1, n, s, e);		
		} else {
			cout << query(1, 1, n, s, e) << endl;
		}
	}
	return 0;
}
