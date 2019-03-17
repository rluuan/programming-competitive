#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

int v[5 * 100000 + 7], tree[5 * 4 * 100000 + 7], n;


void build(int x, int l, int r) {
	if (l == r) {
		tree[x] = v[l];
		return;
	}
	int m = (l + r) >> 1;
	build(x + x, l, m);
	build(x + x + 1, m + 1, r);
	tree[x] = -1;
}
void modify(int x, int l, int r, int ix) {
	if (l == r) {
		if (tree[x] == 0) {
			tree[x] = 1;
		}
		return;
	}
	int m = (l + r) >> 1;
	if (ix <= m) {
		modify(x + x, l, m, ix);
	} else if (ix > m) {
		modify(x + x + 1, m + 1, r, ix);
	}
	if (tree[x + x] >= tree[x + x + 1]) {
		tree[x] = x + x - n + 1;
	} else {
		tree[x] = x + x + 1 - n + 1;
	}
}
int query(int x, int l, int r, int ll, int rr) {
	if (ll > r || rr < l) {
		return -1;
	}
	if (ll <= l && r <= rr) {
		if (tree[x] == 0) return -1;
		return tree[x];
	}
	int m = (l + r) >> 1;
	if (rr <= m) {
		return query(x + x, l, m, ll, rr);
	} else if (ll > m) {
		return query(x + x + 1, m + 1, r, ll, rr);
	}
}

int main() {
	fast_io
	
	int m, k, idx;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	memset(tree, 0, sizeof 0);
	build(1, 1, n);
	for (int i = 0; i < m; ++i) {
		cin >> k >> idx;
		if (k == 0) {
			cout << query(1, 1, n, 1, n >> 1) << " ";
			cout << query(1, 1, n, (n >> 1) + 1, (n >> 1) + 1 + idx) << endl;
		} else {
			modify(1, 1, n, idx);
		}
	}
	return 0;
}
