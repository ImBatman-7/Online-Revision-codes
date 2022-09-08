/*#include <bits/stdc++.h>
using namespace std;
set<string>s;
void permute(char *in, int i) {
	if (in[i] == '\0') {
		s.insert(in);
		// cout << in <<  "<-original" << endl;
		return;
	}

	for (int j = i; in[j] != '\0'; j++) {
		swap(in[i], in[j]);
		permute(in, i + 1);
		swap(in[i], in[j]);//Backtracking
		// cout << i << "-" << j << " " << in << endl;
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	char in[100];
	cin >> in;

	permute(in, 0);

	for (auto it = s.begin(); it != s.end(); it++) {
		cout << *it << endl;
	}

	return 0;
}

*/

#include<bits/stdc++.h>
using namespace std;
void Permute(char* in, int i) {
	if (in[i] == '\0') {
		cout << in << endl;
		return;
	}


	for (int j = i; in[j] != '\0'; j++) {
		swap(in[i], in[j]);
		Permute(in, i + 1);
		swap(in[i], in[j]);// backteacking
	}
}


int main() {
	char in[1000];
	cin >> in;
	Permute(in, 0);
	1 2 3 12
}