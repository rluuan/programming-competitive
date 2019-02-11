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
int t = 0;
vector <int> dp(1000000, -1);
void build(int x) {
	t++;
	if (dp[x] != -1) {
		t += dp[x];
		return;
	}
	if (x == 1) {
		dp[x] = t - 1;
		return;
	}
	if (x & (1 << 0)) {
		build(3 * x + 1);
	} else {
		build(x / 2);
	}
}

	

int main() {
	fast_io
	
	int x1, x2, ans;
	
	while (cin >> x1 >> x2) {
		ans = 0;
		for (int i = x1; i <= x2; ++i) {
			if (dp[i] != -1) {
				ans = dp[i];
				break;
			}
			build(i);
			ans = max(ans, t);
			t = 0;
		}
		cout << x1 << " " << x2 << " " << ans << endl;
	}
	return 0;
}

