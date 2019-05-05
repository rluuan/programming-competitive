#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	
		
	vector <int> setA = {1, 2, 3, 4, 5};
	
	int bitmask_length = (int) setA.size();
	int subset 		   = (1 << bitmask_length) - 1; 

	// remove mid bit
	int bitmask = subset & ~(1 << (bitmask_length >> 1)); 


	for (int i = 0; i < bitmask_length; ++i) {
		if ((bitmask & (1 << i))) {
			cout << setA[i] << " ";
		}
	}
	cout << endl;

    return 0;
}

