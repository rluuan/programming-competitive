#include <bits/stdc++.h>

using namespace std;

#define f0(i, n) for (int i = 0; i < (n); ++i)
#define all(n) n.begin(), n.end()
#define dbg(n) cout << #n << " = " << n << endl
#define dbg2(n1, n2) cout << #n1 << " = " << n1 << ", " << #n2 << " = " << n2 << endl
#define ms(x, n) memset(x, n, sizeof(x))
//
#define MAXN 100010

void init(int dec) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(dec);
}

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int n, q, v[MAXN], tree[4*MAXN];

void build (int node, int l, int r) {
    if (l == r) {
        tree[node] = v[l];
        return;
    }
    int mid = (l + r) / 2;
    int nodel = node * 2;
    int noder = node * 2 + 1;

    build (nodel, l, mid);
    build (noder, mid + 1, r);
    // operation tree
    tree[node] = tree[nodel] * tree[noder];

}
void update (int node, int l, int r, int idx, int val) {
    if (l == r) {
        tree[node] = val;
        return;
    }
    int mid = (l + r) >> 1;
    int nodeleft = node * 2;
    int noderight = node * 2 + 1;
    if (idx <= mid) {
        update (nodeleft, l, mid, idx, val);

    } else if (idx > mid) {
        update (noderight, mid + 1, r, idx, val);

    }
    tree[node] = tree[nodeleft] * tree[noderight];
}
int query (int node, int l, int r, int s, int e) {
    if (l == s and e == r) {
        return tree[node];
    }
    int mid = (l + r) >> 1;
    int nodeleft = node * 2;
    int noderight = node * 2 + 1;
    if (e <= mid) {
        return query (nodeleft, l, mid, s, e);
    }
    else if (s > mid) {
        return query (noderight, mid + 1, r, s, e);
    } else {
        return (query (nodeleft, l, mid, s, mid) * query (noderight, mid + 1, r, mid + 1, e));
    }
}
int sig (int x) {
    if (x < 0) return -1;
    else if (x > 0) return 1;
    else return 0;
}
int main() {
	init(1);
    while (cin >> n >> q) {
        memset (tree, 0, sizeof tree);
        for (int i = 1; i <= n; ++i) {
            cin >> v[i];
            v[i] = sig(v[i]);
        }
        build (1, 1, n);
        for (int i = 0; i < q; ++i) {
            char op;
            int x1, x2;
            cin >> op >> x1 >> x2;
            if (op == 'C') {
                x2 = sig (x2);
                update (1, 1, n, x1, x2);
            } else {
                int c = query (1, 1, n, x1, x2);
                if (c == 1) {
                    cout << "+";
                } else if (c == -1) {
                    cout << "-";
                } else {
                    cout << "0";
                }
            }
        }
        cout << endl;
    }
    return 0;
}
