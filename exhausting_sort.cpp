/**
 * @exhausting_sort.cpp
 * @brief the fastest slow sort.
 * @author Mateus Ferreira Silva
 * @date 16/09/2020
 **/

#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<auto> &v) {
	for(auto a : v) cout << a << endl;
} // print_vector

int disorder_degree(vector<auto> &v, int n) {
	if(n == 1) return 0;
	int d = 0;
	for(int i = 0, j = 1; i < n-1; i++, j++) // n comparisons
		if(v[i] > v[j]) d++;
	return d;
} // disorder_degree

void exhausting_sort_int(string file) {
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

	vector<vector<int>> m; // matrix
	m.reserve(n);
	// O(n³): n[(n²-n) + n²]
	for(int i = 0; i < n; i++) { // n

		// total = n(n-1) = n²-n
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
				m[j].push_back(left[k]);

			for(int k = 0; k < mid.size(); k++)
				m[j].push_back(mid[k]);

			for(int k = 0; k < right.size(); k++) 
				m[j].push_back(right[k]);
		} // for

		vector<int> d;
		d.reserve(n);
		// total = n²
		for(int j = 0; j < n; j++) { // n
			d[j] = disorder_degree(m[j], n); // catch the disorder degree of each line on the matrix
			if(d[j] == 0) { // we find a sorted array
				print_vector(m[j]);
				return;
			} // if
		} // for 

		int min;
		list<int> index; // store the index of the lesser disorder degree in a pseudo sorted order
		for(int j = 0; j < n; j++) {
			if(j == 0 || d[j] <= min) {
				min = d[j];
				index.push_front(j);
			} else
				index.push_back(j);
		} // for

		int vd = disorder_degree(v, n); // catch the disorder degree of the vector of input

		int idx_cp;
		for(int idx : index) { // n
			if(d[idx] == vd) {
				// we have to check if this array is different of the original one 
				bool flag = false;
				for(int j = 0; j < n; j++) { // n comparisons
					if(m[idx][j] != v[j]) {
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
			v[j] = m[idx_cp][j];
		for(int j = 0; j < n; j++)
			m[j].clear();

	} // for
} // exhausting_sort_int

void exhausting_sort_str(string file) {
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

	vector<vector<string>> m;
	m.reserve(n);
	for(int i = 0; i < n; i++) {

		for(int j = 0; j < n; j++) {

			string pivot = v[j];
			vector<string> left, right, mid;

			for(int k = 0; k < n; k++) {
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
				m[j].push_back(left[k]);

			for(int k = 0; k < mid.size(); k++)
				m[j].push_back(mid[k]);

			for(int k = 0; k < right.size(); k++) 
				m[j].push_back(right[k]);
		} // for

		vector<int> d;
		d.reserve(n);
		for(int j = 0; j < n; j++) {
			d[j] = disorder_degree(m[j], n); // catch the disorder degree of each line on the matrix
			if(d[j] == 0) { // we find a sorted array
				print_vector(m[j]);
				return;
			} // if
		} // for

		int min;
		list<int> index; // store the index of the lesser disorder degree in a pseudo sorted order
		for(int j = 0; j < n; j++) {
			if(j == 0 || d[j] <= min) {
				min = d[j];
				index.push_front(j);
			} else
				index.push_back(j);
		} // for

		int vd = disorder_degree(v, n); // catch the disorder degree of the vector of input

		int idx_cp;
		for(int idx : index) {
			if(d[idx] == vd) { // we have to check if this array is different of the original one 
				bool flag = false;
				for(int j = 0; j < n; j++) {
					if(m[idx][j] != v[j]) {
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
			v[j] = m[idx_cp][j];
		for(int j = 0; j < n; j++)
			m[j].clear();

	} // for
} // str_sort

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

	// check the type of input
	int digit_cont = 0;
	for(int i = 0; i < in.size(); i++) {
		if(isdigit((char) in[i]))
			digit_cont++;
		else break;
	} // for

	if(digit_cont == in.size())
		exhausting_sort_int(file);
	else 
		exhausting_sort_str(file);

	return 0;
} // main