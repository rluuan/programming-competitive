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
int vetx[] = {0, 1, 0, -1};
int vety[] = {1, 0, -1, 0};

long long ans = 0, n = 0;

long long lsb (long long n) {
    return n & -n;
}
void build (long long n) {
    while (n) {
        ans++;
        n -= lsb(n);
    }
}
int f () {
    long long tmp = 0;
    for (int i = 0; i < ans; ++i) {
        tmp += (1 << i);
    }
    if (tmp == n) return 1;
    return 0;
}
int main() {
	init(false);
    cin >> n;

    build (n);
    cout << (f() ? 'S' : 'N') << endl;
    return 0;
}
