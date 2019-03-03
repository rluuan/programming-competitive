#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);


int tree[4 * 100000 + 1];

void push(int x) {
	tree[x] = tree[x + x] + tree[x + x + 1];
}

void build(int x, int l, int r) {
	if (l == r) {
		tree[x] = 0;
		return;
	}
	int m = (l + r) >> 1;
	build(x + x, l, m);
	build(x + x + 1, m + 1, r);
	push(x);
}
void modify(int x, int l, int r, int ll, int rr) {
	if (l == r) {
		tree[x] = !tree[x];
		return;
	}
	if (ll > r || rr < l) {
		return;
	}
	int m = (l + r) >> 1;

	if (rr <= m) {
		modify(x + x, l, m, ll, m);
		
	} else if (ll > m) {
		modify(x + x + 1, m + 1, r, m + 1, rr);

	} else {
		modify(x + x, l, m, ll, m);
		modify(x + x + 1, m + 1, r, m + 1, rr);

	}
	push(x);
}
int query(int x, int l, int r, int ll, int rr) {
	if (ll <= l && r <= rr) {
		return tree[x];
	}
	int m = (l + r) >> 1;
	if (rr <= m) {
		return query(x + x, l, m, ll, m);

	} else if (ll > m) {
		return query(x + x + 1, m + 1, r, m + 1, rr);

	} else {
		return query(x + x, l, m, ll, m) + query(x + x + 1, m + 1, r, m + 1, rr);

	}
}



int main() {
	fast_io


	int n, m;
	cin >> n >> m;
	int k, s, e;
	build(1, 1, n);
	for (int i = 1; i <= m; ++i) {
		cin >> k >> s >> e;
		if (k == 0) {
			modify(1, 1, n, s, e);
		} else {
			cout << query(1, 1, n, s, e) << endl;
		}
	}
	return 0;
}
