#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 100000;
const int maxnt = 4 * maxn;
bool tree[maxnt];

void push(int x) {
	tree[x] = tree[x + x] + tree[x + x + 1];
}

void build(int x, int l, int r) {
	if (l == r) {
		tree[x] = 0;
		return;
	}
	int y = (l + r) >> 1;
	build(x + x, l, y);
	build(x + x + 1, y + 1, r);
	push(x);
}
void update(int x, int l, int r, int ll, int rr) {
	if (l == ll && r == rr) { 
		tree[x] = !tree[x];
		return;
	}
	if (ll > r || rr < l) {
		return;
	}
	int y = (l + r) >> 1;
	update(x + x, l, y, ll, y);
	update(x + x + 1, y + 1, r, y + 1, rr);
	push(x);
}
int query(int x, int l, int r, int ll, int rr) {
	if (ll <= l && r <= rr) {
		return tree[x];
	}
	if (ll > r || rr < l) {
		return 0;
	}
	int y = (l + r) >> 1;
	return query(x + x, l, y, ll, y) + query(x + x + 1, y + 1, r, y + 1, rr);
}
	
	
int main() {
	fast_io
	int n, m, k, s, e;
	cin >> n >> m;
	build(1, 1, n);

	for (int i = 1; i <= m; ++i) {
		cin >> k >> s >> e;
		if (k == 0) {
			update(1, 1, n, s, e);		
			for (int i = 4; i <= 7; ++i) {
				cout << tree[i] << " ";
			}
			cout << endl;
		} else {
			cout << query(1, 1, n, s, e) << endl;
		}
	}
	return 0;
}
