#include <bits/stdc++.h>
using namespace std;

#define f0(i, n) for (int i = 0; i < (n); ++i)
#define all(n) n.begin(), n.end()
#define dbg(n) cout << #n << " = " << n << endl
#define dbg2(n1, n2) cout << #n1 << " = " << n1 << ", " << #n2 << " = " << n2 << endl
#define ms(x, n) memset(x, n, sizeof(x))

void init(bool dec) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(dec);
}
const int maxn = 1000;
char costa[maxn][maxn];
int ans = 0;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

vector < pair <int, int> > event;

inline void build (int x, int y) {
	for (auto w: event) {
		int solve = 0;
		for (int i = 0; i < 4; ++i) {
			int nx = w.first  + dx[i];
			int ny = w.second + dy[i];
			
			if (w.first == x - 1 || w.second == y - 1 || ! w.first|| ! w.second || costa[nx][ny] == '.') {
				ans++;
				break;
			} 
		}
	}
}

int main() {
	init(false);
	
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> costa[i][j];
			if (costa[i][j] == '#') event.push_back(make_pair(i, j));
		}
	}
	build (n, m);

	cout << ans << '\n';

	return 0;	
}
