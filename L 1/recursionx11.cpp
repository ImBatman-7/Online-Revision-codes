#include <iostream>
using namespace std;
void word(string &s, int n) {//use &(by reference) to make it fast
	if (n == 0) {
		return;
	}
	char ch = s[n - 1];

	word(s , n - 1);
	cout << ch << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	int n = s.length();

	word(s, n);

	return 0;
}