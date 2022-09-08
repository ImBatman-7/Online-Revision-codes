// find power of a number more faster

#include <iostream>
using namespace std;
#define ll long long
ll power(int x, int n) {
	if (n == 0) {
		return 1;
	}
	ll small_ans = power(x, n / 2);
	small_ans *= small_ans;
	if (n & 1) { //if last bit is 1 it is odd
		small_ans *= x;
	}
	return small_ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll x , n;
	cin >> x >> n;

	cout << power(x, n);

	return 0;
}