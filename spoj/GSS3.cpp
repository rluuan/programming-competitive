#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll; 

int add[100000 + 7], mx[4 * 100000];

void build(int x, int l, int r) {
	if (l == r) {
		mx[x] = add[l];
		return;
	}
	int y = (l + r) >> 1;
	build(x + x, l, y);
	build(x + x + 1, y + 1, r);
	mx[x] = mx[x + x] + mx[x + x + 1];
}
void modify(int x, int l, int r, int ix, int v) {
	if (l == r) {
		mx[x] = v;
		return;
	}
	int y = (l + r) >> 1;
	if (ix <= y) {
		modify(x + x, l, y, ix, v);
	} else if (ix > y) {
		modify(x + x + 1, y + 1, r, ix, v);
	}
	mx[x] = mx[x + x] + mx[x + x + 1];
}
int query(int x, int l, int r, int ll, int rr) {
	if (ll <= l and r <= rr) {
		return mx[x];
	}
	int y = (l + r) >> 1;
	if (rr <= y) {
		return query(x + x, l, y, ll, rr);
	} else if (ll > y) {
		return query(x + x + 1, y + 1, r, ll, rr);
	} else {
		return max(query(x + x, l, y, ll, y), query(x + x + 1, y + 1, r, y + 1, rr));
	}
}
int main() {
	fast_io
	
	int n, k, x, y;
	char o;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> add[i];
	}
	cin >> k;
	build(1, 1, n);
	for (int i = 0; i < k; ++i) {
		cin >> o >> x >> y;
		if (o == '0') {
			modify(1, 1, n, x, y);
		} else {
			cout << query(1, 1, n, x, y) << endl;
		}
	}

	return 0;
}

