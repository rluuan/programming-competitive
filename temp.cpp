#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

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

void init(int dec) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(dec);
}
int main() {
	init(0);

	return 0;
}
