//print nth fibonacci number

#include <iostream>
using namespace std;
int fib(int n) {
	//base case
	if (n == 0 || n == 1) {
		return n;
	}
	int a = fib(n - 1);
	int b = fib(n - 2);

	return a + b;


}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	cout  << fib(n);

	return 0;
}