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

struct points {
	int x;
	int y;

	points() : x(0), y(0) {}
	points (int x, int y) : x(x), y(y) {};
	void read() { scanf ("%d %d", &x, &y); }
	void print() { cout << x << " " << y << endl; }
};


int main() {
	fast_io
	


	return 0;
}

