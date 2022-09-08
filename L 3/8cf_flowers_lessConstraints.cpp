#include <bits/stdc++.h>
using namespace std;

int Flowers(int n, int k) {
	if (n == 0) { //agar last mai phoch gye ho, to 1 return kro , mtlb 1 way mil gya hai
		return 1;
	}

	int option1 = Flowers(n - 1, k); //red ko liya hai
	int option2 = 0;
	if (n >= k) {//jab flowers k se bade honge to hi white ko check krna
		option2 = Flowers(n - k, k); //white ko liya
	}

	return option2 + option1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	cout << Flowers(n, k);

	return 0;
}