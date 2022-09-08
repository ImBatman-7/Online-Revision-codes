#include <iostream>
using namespace std;
int find(int *a, int n, int key) {
	if (n == 0) {
		return -1;
	}
	int x = a[n - 1];
	if (x == key) {
		return n - 1;
	}
	find(a , n - 1, key);
}

#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n ; i++) {
		cin >> a[i];
	}
	int key;
	cin >> key;
	cout << find(a, n, key);

	return 0;
}