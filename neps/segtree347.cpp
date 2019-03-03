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
int tree[100000], add[100000];

void push(int x) {
	tree[x] = tree[x + x] + tree[x + x + 1];

}
void build(int x, int l, int r) {
	if (l == r) {
		tree[x] = add[l];
		return;
	}
	int m = (l + r) >> 1;

	build(x + x, l, m);
	build(x + x + 1, m + 1, r);

	push(x);
}
void modify(int x, int l, int r, int ll, int rr, int v) {
	if (ll > r || rr < l || l > r) {
		return;
	}
	if (l == r) {
		tree[x] = v;
		return;
	}
	int m = (l + r) >> 1;

	modify(x + x, l, m, ll, m, v);
	modify(x + x + 1, m + 1, r, m + 1, rr, v);

	push(x);
}
int query(int x, int l, int r, int ll, int rr) {
	if (ll <= l && r <= rr) {
		return tree[x];
	}
	if (ll > r || rr < l) {
		return 0;
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

	int o, a, b, k;

	for (int i = 1; i <= n; ++i) {
		cin >> add[i];
	}
	build(1, 1, n);
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

