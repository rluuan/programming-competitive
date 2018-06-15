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
struct e {
    int n1;
    int n2;
   
    inline bool operator < (const e &other) const {
        if (other.n1 < n2) return 1;
        return 0;
    }
};
int main() {
	init(false);
    vector <e> event(6);

    for (int i = 0; i < 3; ++i) cin >> event[i].n1;
    for (int i = 0; i < 3; ++i) cin >> event[i].n2;

    sort(event.begin(), event.end());
    for (int i = 0; i < 3; ++i) {
        if (event[i].n1 > event[i].n2) {
            cout << "A";
            break;

        } else if (event[i].n1 < event[i].n2) {
            cout << "B";
            break;

        }
    }
    cout << endl;
    return 0;
}
