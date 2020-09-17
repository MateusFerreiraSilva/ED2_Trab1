#include <bits/stdc++.h>
using namespace std;

void inteiros(string file) {
	vector<int> v;
	int aux;
	ifstream input(file);

	while(input >> aux) {
		v.push_back(aux);
	}

	for(auto a : v) cout << a << endl;
} // dna

void frases(string file) {
	vector<string> v;
	string aux;
	ifstream input(file);

	while(getline(input, aux)) {
		v.push_back(aux);
	}

	for(auto a : v) cout << a << endl;
} // dna


void dna(string file) {
	vector<string> v;
	string aux;
	ifstream input(file);

	while(getline(input, aux)) {
		v.push_back(aux);
	}



	for(auto a : v) cout << a << endl;

} // dna

void le(string file) {
	vector<string> v;
	ifstream input(file);
	string in;

	if(input.is_open()) {
		while(getline(input, in)) {
			if(input.good()) 
				v.push_back(in);
		} // while
	} // if

	for(auto a : v) cout << a << endl;
}

int main() {
	string file = "data.txt";
	ifstream input(file);
	string in;
	
	if(input.is_open())
		getline(input, in);

	// cout << in << endl;

	le(file);

}

