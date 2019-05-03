#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);


vector <char> store = {'a', 'b', 'c'};

void print_bitmask(int bitmask) {


	for (int i = 0; i < (1 << bitmask); ++i) {
		cout << "{ ";
		
		for (int j = 0; j < bitmask; ++j) {
			if ((i & (1 << j)) > 0) {
				cout << store[j] << " ";
			}
		}
		cout << "}" << endl;
	}
}


int main() {
	print_bitmask(store.size());

	return 0;
}
