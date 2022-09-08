//find power of a number

#include <iostream>
using namespace std;
int power(int x, int n) {
	if (n == 0) {
		return 1;
	}
	int ans = x * power(x, n - 1);
	return ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int x, n;
	cin >> x >> n;

	cout << power(x, n);

	return 0;
}