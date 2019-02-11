#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll; 

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
const int maxn = 5;

int lsb (int x) {
	return x & -x;
}
void update_bit (int *bit, int ix, int v, int n) {
	ix++;
	while (ix <= n) {
		bit[ix] += v;
		ix += lsb(ix);
	}
}
int querySum_bit (int *bit, int x) {
	x++;
	int ans = 0;
	while (x > 0) {
		ans += bit[x];
		x -= lsb(x);
	}
	return ans;
}
int main() {
	fast_io
	
	int *fenw = new int [2 * maxn], v[maxn];
	
	for (int i = 0; i < maxn; ++i) v[i] = i, fenw[i + 1] = 0;
	for (int i = 0; i < maxn; ++i) update_bit (fenw, i, v[i], maxn);
	cout << ( querySum_bit(fenw, 3) - querySum_bit(fenw, 1) )<< endl;
	return 0;
}

