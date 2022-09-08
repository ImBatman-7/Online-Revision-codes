#include <iostream>
using namespace std;
void word(string &s, int n, char a, char b) {
	if (n == 0) {
		return;
	}
	// char ch = s[n - 1];
	if (s[n - 1] == a) {
		s[n - 1] = b;
	}
	word(s , n - 1, a , b);
	// cout << ch;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	char a, b;
	cin >> s >> a >> b;
	int n = s.length();

	word(s, n, a, b);

	cout << endl << s;


	return 0;
}