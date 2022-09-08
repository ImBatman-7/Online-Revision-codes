#include <bits/stdc++.h>
using namespace std;
string check(string s) {
	int n = s.length();
	if (n == 0 || n == 1) {
		return s;
	}

	if (s[0] == 'p' && s[1] == 'i') {
		return "3.14" + check(s.substr(2));
	} else {
		return s[0] + check(s.substr(1));
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	cout << check(s);

	return 0;
}
