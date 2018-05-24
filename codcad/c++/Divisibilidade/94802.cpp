#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string n;

struct event {
    char res[3];

    ll nsize = (ll) n.size(), s = 0;
    ll sizeT() {
        for (int i = 0; i < nsize; ++i) {
            ll nu = n[i] - '0';
            s += nu;
        }
        return s;
    }
    int sizeF() {
        return (n[nsize - 1] - '0' == 5) || (n[nsize - 1] - '0' == 0);
    }
};

void ans() {
    event e;

    ll size = (ll) n.size();

    ((n[size - 1] - '0') % 2 == 0) ? e.res[0] = 'S' : e.res[0] = 'N';
    (e.sizeT() % 3 == 0) ? e.res[1] = 'S' : e.res[1] = 'N';
    (e.sizeF()) ? e.res[2] = 'S' : e.res[2] = 'N';

    for (char w: e.res) {
        cout << w << endl;
    }
}

int main() {


    cin >> n;

    ans();


    return 0;
}
