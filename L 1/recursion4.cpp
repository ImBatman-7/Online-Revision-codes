// check if an array is sorted

#include <iostream>
using namespace std;
bool isSorted(int *a, int i, int n) {
	//base case
	if (i == n - 1) {
		return true;
	}
	if (a[i] < a[i + 1] && isSorted(a, i + 1, n)) {
		return true;
	}
	return false;

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << isSorted(a, 0, n);

	return 0;
}