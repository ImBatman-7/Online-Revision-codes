#include <iostream>
using namespace std;
int fact(int n) {
	//base case
	if (n == 1) {
		return 1; //it is int not bool.
	}
	int ans = n * fact(n - 1);
	// return ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	cout << fact(n);

	return 0;
}