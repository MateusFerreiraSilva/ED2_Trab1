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



int main(int argc, char **argv) {
	// if(argc != 3)
	// 	cout << "Entrada inválida\n";
	// else {

	// 	string str1 = argv[1];
	// 	string str2 = argv[2];

	// 	if(str1 == "inteiros") inteiros(str2);
	// 	else if(str1 == "frases") frases(str2);
	// 	else if(str1 == "dna") dna(str2);
	// } // else

	vector<string> v = {"aaa", "bbb", "ccc"};
	// for(int i = 0; i < v.size(); i++) {
	// 		v[i] = "ddd";
	// } // for

	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	} // for
}

