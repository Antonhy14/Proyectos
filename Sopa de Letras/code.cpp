#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define nl cout<<"\n"
#define sp(x,n) fixed<<setprecision(x) << n
#define all(x) x.begin(),x.end()
#define fore(i,l,r) for(auto i=l;i<r;i++)
#define pb push_back
#define pf push_front
/*
    Valores ASCII
    'A' = 65 'Z' = 90
    'a' = 97 'z' = 122
    '0' = 48 '9' = 57
*/

vector<vector<char>> generator(vector<string>& words, int size) {
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<int> distribution(0, 2);

	vector<vector<char>> res(size, vector<char>(size, ' '));

	fore(i, 0, words.size()) {
		string word = words[i];
		distribution.param(uniform_int_distribution<int>::param_type(0, 2));
		int direction = distribution(gen);
		// 0: horizontal
		// 1: vertical
		// 2: diagonal

		if(direction == 0) {
			distribution.param(uniform_int_distribution<int>::param_type(0, size - 1));
			int row = distribution(gen);

			distribution.param(uniform_int_distribution<int>::param_type(0, size - word.length()));
			int column = distribution(gen);

			int ok = 0;
			fore(j, 0, word.length()) {
				if(res[row][column+j]!=32 && res[row][column+j]!=word[j]) {
					ok = 1;
					i--;
					break;
				}
			}
			if(!ok) fore(j,0,word.length()) res[row][column+j] = word[j];
		}
		else if(direction == 1) {
			distribution.param(uniform_int_distribution<int>::param_type(0, size - 1));
			int column = distribution(gen);

			distribution.param(uniform_int_distribution<int>::param_type(0, size - word.length()));
			int row = distribution(gen);

			int ok = 0;
			fore(j,0,word.length()) {
				if(res[row+j][column]!=32 && res[row+j][column]!=word[j]) {
					ok = 1;
					i--;
					break;
				}
			}
			if(!ok) fore(j,0,word.length()) res[row+j][column] = word[j];
		}
		else if(direction == 2) {
			distribution.param(uniform_int_distribution<int>::param_type(0, size - word.length()));

			int row = distribution(gen);
			int column = distribution(gen);

			int ok = 0;
			fore(j,0,word.length()) {
				if(res[row+j][column+j]!=32 && res[row+j][column+j]!=word[j]) {
					ok = 1;
					i--;
					break;
				}
			}
			if(!ok) fore(j,0,word.length()) res[row+j][column+j] = word[j];
		}
	}

	distribution.param(uniform_int_distribution<int>::param_type(65, 90));
	fore(i,0,size) {
		fore(j,0,size) {
			cout << res[i][j];
		}
		nl;
	}

	fore(i,0,size) {
		fore(j,0,size) {
			if(res[i][j]==32) {
				res[i][j] = distribution(gen);
			} 
		}
	}

	nl;nl;nl;
	return res;
}

void toUpper(string& word) {
	fore(i,0,word.length()) if(word[i]>=97&&word[i]<=122) word[i]-=32;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int nWords, size;
	cin >> nWords >> size;
	vector<string> words;

	fore(i,0,nWords) {
		string aux;
		cin >> aux;
		toUpper(aux);
		words.pb(aux);
	}

	vector<vector<char>> res = generator(words, size);

	fore(i,0,size) {
		fore(j,0,size) {
			cout << res[i][j];
		}
		nl;
	}

	return 0;
}
