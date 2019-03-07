#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll; 
int mx[4 * 100000], add[100000 + 7];

void build(const int x, const int l, const int r) {
	if (l == r) {
		mx[x] = add[l];
		return;
	}
	int m = (l + r) >> 1;
	build(x + x, l, m);
	build(x + x + 1, m + 1, r);
	mx[x] = min(mx[x + x], mx[x + x + 1]);
}
void modify(int x, int l, int r, int ix, int v) {
	if (l == r) {
		mx[x] = v;
		return;
	}
	int m = (l + r) >> 1;
	if (ix <= m) {
		modify(x + x, l, m, ix, v);
	} else if (ix > m) {
		modify(x + x + 1, m + 1, r, ix, v);
	}
	mx[x] = min(mx[x + x], mx[x + x + 1]);
}
int query(int x, int l, int r, int ll, int rr) {

	if (ll <= l && r <= rr) {
		return mx[x];
	}
	int y = (l + r) >> 1;
	if (rr <= y) {
		return query(x + x, l, y, ll, rr);
	} else if (ll > y) {
		return query(x + x + 1, y + 1, r, ll, rr);
	} else {
		return min(query(x + x, l, y, ll, y), query(x + x + 1, y + 1, r, y + 1, rr));
	}
}
int main() {
	fast_io
	
	int n, k, x, y;
	char o;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> add[i];
	}
	build(1, 1, n);
	for (int i = 0; i < k; ++i) {
		cin >> o >> x >> y;
		if (o == 'q') {
			cout << query(1, 1, n, x, y) << endl;
		} else {
			modify(1, 1, n, x, y);
		}
	}

	return 0;
}

