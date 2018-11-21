#include <bits/stdc++.h>

using namespace std;

#define f0(i, n) for (int i = 0; i < (n); ++i)
#define all(n) n.begin(), n.end()
#define dbg(n) cout << #n << " = " << n << endl
#define dbg2(n1, n2) cout << #n1 << " = " << n1 << ", " << #n2 << " = " << n2 << endl
#define ms(x, n) memset(x, n, sizeof(x))
//

void init(int dec) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(dec);
}

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int build (int n) {
    if (n <= 1) return 1;
    cout << "fuck off 1" << endl;
    int value = n * 100;
    build (n - 1);
    cout << n << endl;
    cout << value << endl;
}

int main() {
	init(1);

    int w = build (10);
    cout << w << endl;
	return 0;
}
