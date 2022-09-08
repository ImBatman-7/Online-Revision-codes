/*given n stairs , you have only 3 type of steps to reach to the top, 1 jump, 2 jump or 3 jump
calculate the total possible jumps.*/

/*logic -> agar aap stair k top m khade ho, to jaahir si baat h ki, ya to 1 step last m liya hoga,
2 step last m liya hoga ya fir 3 step last m liya hoga.

agr 1 step leke aaya to, baaki n-1 ka kaam recursion se karao, agar 2 step jump krke aaya to baaki n-2 ka kaam
recursion se karao, similarily, n-3.*/

#include <iostream>
using namespace std;
int check(int n) {
	if ( n == 0) {
		return 1;// top se kudte kudte aa rha h to, perfectly lower step m aagya(1 way aagya)
	}
	if (n < 0) {
		return 0; // top se kudte kudte aarha h, fir lower m naa aake aur aage nikal gaya(we won't consider this way)
	}

	return check(n - 1) + check(n - 2) + check(n - 3);
}

// generic functin, if user want us to take upto k jumps;

int check1(int n, int k) {
	if ( n == 0) {
		return 1;// top se kudte kudte aa rha h to, perfectly lower step m aagya(1 way aagya)
	}
	if (n < 0) {
		return 0; // top se kudte kudte aarha h, fir lower m naa aake aur aage nikal gaya(we won't consider this way)
	}

	int ans = 0;
	for (int i = 1 ; i <= k ; i++) {
		ans += check1(n - i, k);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;

	cin >> n;
	cout << check(n);


	// k steps
	// cin >> k;
	// cout << check1(n, k);

	return 0;
}