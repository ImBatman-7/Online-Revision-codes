// multiply two numbers

#include <iostream>
using namespace std;
int multi(int x, int y) { //5 4
	//base case
	if (y == 0) {
		return 0;
	}
	int ans =  x + multi(x , (y - 1));
	return ans;


}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	cout << multi(n, m);

	return 0;
}