#include <bits/stdc++.h>
using namespace std;

#define f0(i, n) for (int i = 0; i < (n); ++i)
#define all(n) n.begin(), n.end()
#define dbg(n) cout << #n << " = " << n << endl
#define dbg2(n1, n2) cout << #n1 << " = " << n1 << ", " << #n2 << " = " << n2 << endl


void init(int dec) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(dec);
}
int vetx[] = {0, 1, 0, -1};
int vety[] = {1, 0, -1, 0};

int ans = 0, n = 0;

int lsb (int n) {
    return n & -n;
}
void build (int n) {
    while (n) {
        ans++;
        n -= lsb(n);
    }
}
int f () {
    int tmp = 0;
    for (int i = 0; i < 32; ++i) {
        if ((n & (1 << i) == 0)) return 0;
        tmp += (int) (1 << i);
        if (tmp > n) return 0;
        if (tmp == n) return 1;
    }
    if (tmp == n) return 1;
    return 0;
}
int main() {
	init(0);
    cin >> n;

    cout << (f() ? 'S' : 'N') << endl;
    return 0;
}
