//print numbers in reverse order

#include <iostream>
using namespace std;
void rev(int n) {
	//base case
	if (n < 1) {
		return;
	}
	cout << n << " ";
	rev(n - 1);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	rev(n);

	return 0;
}