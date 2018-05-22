#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f0(i, n) for (int i = 0; i < (n); ++i)
#define all(n) n.begin(), n.end()
#define dbg(n) cout << #n << " = " << n << endl
#define dbg2(n1, n2) cout << #n1 << " = " << n1 << ", " << #n2 << " = " << n2 << endl


void init(bool dec) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(dec);
}
 
const int maxn = (int) 10e5;

vector <int> ligado[maxn];

bool dfs (int x, int y) {
	for (int w: ligado[x]) {
		if (w == y) return 1;
	}
	return 0;
}

void add_edge (int a, int b) {
	ligado[a].push_back (b);
	ligado[b].push_back (a);
}

int main() {
	init(false);
	int n, m;

	cin >> n >> m;

	int op, a, b;
	f0 (i, m) {
		cin >> op >> a >> b;

		if (op == 0) {
			cout << dfs (a, b) << '\n';
		} else {
			add_edge (a, b);
		}
	}
	
	return 0;
}