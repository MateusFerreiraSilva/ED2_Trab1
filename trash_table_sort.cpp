#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<auto> &v) {
	for(auto a : v) cout << a << endl;
} // print_vector

int disorder_degree(vector<auto> &v, int n) {
	if(n == 1) return 0;
	int d = 0;
	for(int i = 0, j = 1; i < n-1; i++, j++)
		if(v[i] > v[j]) d++;
	return d;
} // disorder_degree

void int_sort(string file) {
	vector<int> v;
	int in, n;
	ifstream input(file);

	if(input.is_open()) {
		while(input >> in) {
			if(input.good()) 
				v.push_back(in);
		} // while
	} // if

	n = v.size();

	vector<vector<int>> s;
	s.reserve(n);
	// O(n³) -> n()
	for(int i = 0; i < n; i++) { // n

		// O(n²) -> n(n-1) = n²-n
		for(int j = 0; j < n; j++) { // n

			int pivot = v[j];
			vector<int> left, right, mid;

			for(int k = 0; k < n; k++) { // n-1 comparisons
				if(v[k] > pivot){
					right.push_back(v[k]);
				}
				else if(v[k] < pivot){
					left.push_back(v[k]);
				}
				else
					mid.push_back(v[k]);
			} // for

			for(int k = 0; k < left.size(); k++) 
				s[j].push_back(left[k]);

			for(int k = 0; k < mid.size(); k++)
				s[j].push_back(mid[k]);

			for(int k = 0; k < right.size(); k++) 
				s[j].push_back(right[k]);
		} // for

		int vd = disorder_degree(v, n); // catch the disorer degree of the vector of input

		vector<int> d;
		d.reserve(n);
		for(int j = 0; j < n; j++) {
			d[j] = disorder_degree(s[j], n); // catch the disorder degree of each line on the matrix
			if(d[j] == 0) { // we find a sorted array
				print_vector(s[j]);
				return;
			} // if
		} // for 

		int min;
		list<int> index; // store the index of lesser disorder degree in a pseudo sorted order
		for(int j = 0; j < n; j++) {
			if(j == 0 || d[j] <= min) {
				min = d[j];
				index.push_front(j);
			} else
				index.push_back(j);
		} // for

		int idx_cp;
		for(int idx : index) {
			if(d[idx] == 0) { // we find a sorted array
				print_vector(s[idx]);
				return;
			} else if(d[idx] == vd) { // we have to check if this array is different of the original one 
				bool flag = false;
				for(int j = 0; j < n; j++) {
					if(s[idx][j] != v[j]) {
						flag = true;
						break;
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
		for(int j = 0; j < n; j++)
			v[j] = s[idx_cp][j];
		for(int j = 0; j < n; j++)
				s[j].clear();

	} // for
} // inteiros

void str_sort(string file) {
	vector<string> v;
	int n;
	string in;
	ifstream input(file);

	if(input.is_open()) {
		while(getline(input, in)) {
			if(input.good()) 
				v.push_back(in);
		} // while
	} // if

	n = v.size();

	vector<vector<string>> s;
	s.reserve(n);
	// O(n³)
	for(int i = 0; i < n; i++) { // n

		// O(n²) = n(n-1)
		for(int j = 0; j < n; j++) { // n

			string pivot = v[j];
			vector<string> left, right, mid;

			for(int k = 0; k < n; k++) { // n-1 
				if(v[k] > pivot){
					right.push_back(v[k]);
				}
				else if(v[k] < pivot){
					left.push_back(v[k]);
				}
				else
					mid.push_back(v[k]);
			} // for

			for(int k = 0; k < left.size(); k++) 
				s[j].push_back(left[k]);

			for(int k = 0; k < mid.size(); k++)
				s[j].push_back(mid[k]);

			for(int k = 0; k < right.size(); k++) 
				s[j].push_back(right[k]);

			//print
		} // for

		int vd = disorder_degree(v, n); // catch the disorer degree of the vector of input

		vector<int> d;
		d.reserve(n);
		for(int j = 0; j < n; j++) {
			d[j] = disorder_degree(s[j], n); // catch the disorder degree of each line on the matrix
			if(d[j] == 0) { // we find a sorted array
				print_vector(s[j]);
				return;
			} // if
		} // for

		int min;
		list<int> index; // store the index of lesser disorder degree in a pseudo sorted order
		for(int j = 0; j < n; j++) {
			if(j == 0 || d[j] <= min) {
				min = d[j];
				index.push_front(j);
			} else
				index.push_back(j);
		} // for

		int idx_cp;
		for(int idx : index) {
			if(d[idx] == 0) { // we find a sorted array
				print_vector(s[idx]);
				return;
			} else if(d[idx] == vd) { // we have to check if this array is different of the original one 
				bool flag = false;
				for(int j = 0; j < n; j++) {
					if(s[idx][j] != v[j]) {
						flag = true;
						break;
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
		for(int j = 0; j < n; j++)
			v[j] = s[idx_cp][j];
		for(int j = 0; j < n; j++)
				s[j].clear();

	} // for
} // dna

int main() {
	string file = "data.txt";
	ifstream input(file);
	string in;
	
	if(input.is_open())
		getline(input, in);

	else {
		cout << "Arquivo não encontrado\n";
		return 0;
	} // else

	// check type of input
	int digit_cont = 0;
	for(int i = 0; i < in.size(); i++) {
		if(isdigit((char) in[i]))
			digit_cont++;
		else break;
	} // for

	if(digit_cont == in.size())
		int_sort(file);
	else 
		str_sort(file);

	return 0;
} // main