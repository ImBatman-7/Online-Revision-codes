
// q. print numbers in english

#include <iostream>
using namespace std;
string meaning[10] = {"zero ", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine "};
void word(int x) {
	if (x == 0) {
		return;
	}
	int digit = x % 10;
	word(x / 10);
	cout << meaning[digit];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int x;
	cin >> x;

	if (x == 0) {
		cout << meaning[0];
		return 0;
	}

	word(x);

	return 0;
}