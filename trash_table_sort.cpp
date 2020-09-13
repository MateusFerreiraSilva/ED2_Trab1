#include <bits/stdc++.h>
using namespace std;

int disorder_degree(vector<int> &v, int n) {
	if(n == 1) return 0;
	int d = 0;
	for(int i = 0, j = 1; i < n-1; i++, j++)
		if(v[i] > v[j]) d++;
	return d;
} // disorder_degree

int main() {
	int n = 10;
	// cin >> n;
	int cont = 0;
	vector<int> v;
	v.reserve(n);

	for(int i = 0; i < n; i++)
			cin >> v[i];

	vector<vector<int>> s;
	s.reserve(n);
	// O(n³)
	for(int i = 0; i < n; i++) { // n

		// O(n²) = n(n-1)
		for(int j = 0; j < n; j++) { // n

			int pivot = v[j];
			vector<int> left, right, mid;

			for(int k = 0; k < n; k++) { // n-1 
					if(v[k] > pivot){
						cont++;
						right.push_back(v[k]);
					}
					else if(v[k] < pivot){
						left.push_back(v[k]);
						cont++;
					}
					else
						mid.push_back(v[k]);
			} // for

			s.reserve(n);
			for(int k = 0; k < left.size(); k++) 
				s[j].push_back(left[k]);

			for(int k = 0; k < mid.size(); k++)
				s[j].push_back(mid[k]);

			for(int k = 0; k < right.size(); k++) 
				s[j].push_back(right[k]);

			//print
			for(int k = 0; k < n; k++) {
					cout << s[j][k];
					if(k == n-1) cout << endl;
					else cout << " ";
			} // for
		} // for

		int vd = disorder_degree(v, n); // catch the disorer degree of the vector of input

		vector<int> d;
		d.reserve(n);
		for(int j = 0; j < n; j++)
			d[j] = disorder_degree(s[j], n); // catch the disorder degree of each line on the matrix
			// !!!!!!!!!!!try break if d[j] == 0 

		int min;
		vector<int> index; // store the index of lesser disorder degree in a pseudo sorted order
		for(int j = 0; j < n; j++) {
			if(j == 0 || d[j] <= min) {
				min = d[j];
				index.insert(index.begin(), j);
			} else
				index.push_back(j);
		} // for

		int idx_cp;
		for(int idx : index) {
			if(d[idx] == 0) { // we find a sorted array
				cout << cont << " OWARI DA!\n";
				for(auto a : s[idx]) cout << a << " ";
				cout << endl << endl;
				return 0;

			} else if(d[idx] == vd) { // we have to check if this array is different of the original one 
				bool flag = false;
				for(int j = 0; j < n; j++) {
					if(s[idx][j] != v[j]) {
						flag = true;
						break;
						//!!!!!!!!!!! create a table with the already used vectors
					} // if
				} // for
				if(flag) {
					idx_cp = idx;
					break;
				} // if

			} else {
				idx_cp = idx;
				break;
			} // else
		} // for

		// reset
		v.clear();
		v.reserve(n);
		swap(v, s[idx_cp]);

		for(int j = 0; j < n; j++)
				s[j].clear();

	} // for


	return 0;
}