#include <bits/stdc++.h>
using namespace std;

// f(n) = [n(n-1)/2] = (n²-n)/2
// f(n) e O(n²)

int main() {
	int n = 100;
	// cin >> n;
	vector<int> v;

	for(int aux, i = 0; i < n; i++) {
			cin >> aux;
			v.push_back(aux);
	} // for

	int aux = 0;
	for(auto i = v.begin(); i != v.end(); i++) { // n
		for(auto j = i+1; j != v.end(); j++) { // somatoria de 1 a n-1 = [(n-1)n]/2
			
			// aux++;
			if(*i > *j) {
				// not sure about this part
				random_device rd;
				default_random_engine rng(rd());
				// end shady part

				random_shuffle(i, v.end());
				j = i+1; // reset
			} // if
		} // for
	} // for

	// cout << aux << "\n"; // numero de vez de execucao dentro do for

	for(auto a : v) cout << a << " ";
	cout << endl;

	return 0;
}