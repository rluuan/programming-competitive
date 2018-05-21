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
int toca[maxn][maxn], handleAsMark[maxn][maxn];

int ans = 0;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void build (int x, int y, int endx, int endy) {
	if (x > endx or x < 0 or y < 0 or y > endy) return; // verify borders
	
	if (toca[x][y] == 2) { // achou mizeravi
		ans++;
		return;
	}

	int mx, my, exitsTwo = 0;
	f0 (i, 4) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (toca[nx][ny] == 2) exitsTwo = 1; // after all n4, is number two coming out?
		if (toca[nx][ny] != 1) continue;

		if (toca[nx][ny] == 1 and ! handleAsMark[nx][ny]) { // I save the way I can go , I already did not go through that position
			mx = nx, my = ny;
		}
	}
	if (! exitsTwo) { // did not come the number two then call the function with the new parameters
		ans++;
		handleAsMark[mx][my] = 1;
		return build (mx, my, endx, endy);

	} else {
		ans++; // achou mizeravi
		return;
	}
}

int main() {
	init(false);
	
	int n, m, xi, ji;
	cin >> n >> m;

	f0 (i, n) {
		f0 (j, m) {
			handleAsMark[i][j] = 0;
			cin >> toca[i][j];
			if (toca[i][j] == 3) xi = i, ji = j;
		}
	}
	
	build (xi, ji, n, m);

	cout << ans + 1 << '\n';

	return 0;	
}
