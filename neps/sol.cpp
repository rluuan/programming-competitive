#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll; 

inline string IntToString(ll a){
    char x[100];
    sprintf(x,"%lld",a); string s = x;
    return s;
}

inline ll StringToInt(string a){
    char x[100]; ll res;
    strcpy(x,a.c_str()); sscanf(x,"%lld",&res);
    return res;
}

inline string GetString(void){
    char x[1000005];
    scanf("%s",x); string s = x;
    return s;
}
int tree[4 * 100000 + 7], add[100000 + 7], lz[4 * 100000 + 7];

void pusht(const int x) {
	tree[x] = tree[x << 1] + tree[x << 1 | 1];
}
void pushlz(const int x, const int l, const int r) {
	if (lz[x]) {
		tree[x] = lz[x] * (r - l + 1);
		if(l != r) {
			lz[x << 1] += lz[x];
			lz[x << 1 | 1] += lz[x];
		}
		lz[x] = 0;
	}
}
void build(const int x, const int l, const int r) {
	if (l == r) {
		tree[x] = add[l];
		lz[x] = 0;
		return;
	}
	const int m = (l + r) >> 1;

	build(x << 1, l, m);
	build(x << 1 | 1, m + 1, r);
	pusht(x);
}
void modify(const int x, const int l, const int r, const int ll, const int rr, const int v) {
	pushlz(x, l, r);

	if (ll > r || rr < l || l > r) {
		return;
	}
	if (ll <= l && r <= rr) {

		tree[x] = v * (r - l + 1);
		if (l != r) {
			lz[x << 1] += v;
			lz[x << 1 | 1] += v;
		}
	} else {

		const int m = (l + r) >> 1;
		
		modify(x << 1, l, m, ll, rr, v);
		modify(x << 1 | 1, m + 1, r, ll, rr, v);

		pusht(x);
	}
}
int query(const int x, const int l, const int r, const int ll, const int rr) {
	pushlz(x, l, r);

	if (ll > r || rr < l || l > r) {
		return 0;
	}
	if (ll <= l && r <= rr) {
		return tree[x];
	} else {

		const int m = (l + r) >> 1;
		if (rr <= m) {
			return query(x << 1, l, m, ll, rr);
		} else if (l > m) {
			return query(x << 1 | 1, m + 1, r, ll, rr);
		} else {
			return query(x << 1, l, m, ll, rr) + query(x << 1 | 1, m + 1, r, ll, rr);
		}
	}
}

int main() {
	fast_io
	
	int n, m;
	cin >> n >> m;

	int o, a, b, k;

	for (int i = 1; i <= n; ++i) {
		cin >> add[i];
	}
	build(1, 1, n);

/*	for (int i = 0; i < n; ++i) {
		cin >> tree[i + n];
	}
	for (int i = n - 1; i > 0; --i) {
		tree[i] = tree[i << 1] + tree[i << 1 | 1];
	}
	*/
	for (int i = 0; i < m; ++i) {
		cin >> o;
		if (o == 2) {
			cin >> a >> b;
			cout << query(1, 1, n, a, b) << endl;

		} else {
			cin >> a >> b >> k;
			modify(1, 1, n, a, b, k);

		}
	}
	return 0;
}


