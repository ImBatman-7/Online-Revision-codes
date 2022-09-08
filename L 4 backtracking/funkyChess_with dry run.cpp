#include <iostream>
#include <algorithm>
using namespace std;
int n;
int grid[10][10] = {0};
int saare_one = 0, ans = 0, N = 10; // N == max limit of chess board
int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};

void input_grid() {
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < n ; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 1) {
				saare_one++;
			}
		}
	}
}

void knight(int x, int y, int counter) {
	// cout << "------" << endl;
	// cout << "f" << counter << endl ;
	ans = max(counter, ans);
	for (int i = 0; i < 8 ; i++) {//i<8->total directions // i++ will happen when if condition fails
		int xco = x + dx[i];
		int yco = y + dy[i];

		// cout << xco << " - " << yco << "  " << endl;
		// kya coordinates grid m lie krte aur, wo main chess("grid[xco][yco] == 1") m bhi lie krte
		if (xco >= 0 && yco >= 0 && xco < N && yco < N && grid[xco][yco] == 1) {
			// cout << "i-" << i << " "  << xco << " - " << yco << "  " << endl << endl;
			// for (int i = 0; i < n ; i++) {
			// 	for (int j = 0; j < n ; j++) {
			// 		cout << grid[i][j] << " ";
			// 	}
			// 	cout << endl;
			// }
			// cout << endl;


			grid[xco][yco] = 0; //you cant go to a box  once visited

			// cout << "grid after flip" << endl ;
			// for (int i = 0; i < n ; i++) {
			// 	for (int j = 0; j < n ; j++) {
			// 		cout << grid[i][j] << " ";
			// 	}
			// 	cout << endl;
			// }
			// cout << endl;
			knight(xco, yco, counter + 1); //counter + 1 --> ek box pe jaa skte h, jisme wo khada h
			// cout << "f after backtracking " << counter << endl ;

			/*pehle apn 0,0 se gaye the, ab apn koi dusri jagah se bhi pohoch skte h
			lekin apn sbko 0(so that you can't visit there) bana chuke h, to usko backtracking
			ki help se wapas 1(to be able to travese) bnana pdega*/
			grid[xco][yco] = 1; //backtracking
			//agar backtracking ni kroge to, bas ek hi baar check krega, multiple\
			conditions check ni ho payegi

			// DO NOTE-> i jo phle tha wahi rhega , wapas i = 0 ni hoga
			// cout << "yes" << endl;
		}

	}

	// cout << endl << "fReturning.." << counter << endl ;
	// for (int i = 0; i < n ; i++) {
	// 	for (int j = 0; j < n ; j++) {
	// 		cout << grid[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << "returned" << endl << endl;
	return;
}



/*
	1  i--0  2
	2  i--1  0
	0  i--6  1
	2  i--2  2
	1  i--5  0
	0  i--4  2
	2  i--3  1
	2  i--2  1
	0  i--6  2
	1  i--1  0
	2  i--0  2
	0  i--7  1
	2  i--3  0
	1  i--4  2
*/
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	input_grid(); // 2d array cin le liya
	grid[0][0] = 0; //yaha khade the already
	knight(0, 0, 1);
	cout << saare_one - ans << endl;
	// for (int i = 0; i < n ; i++) {
	// 	for (int j = 0; j < n ; j++) {
	// 		cout << grid[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	// minimise the number of boxes where we cannot travel for that we will maximise the number
	// of boxes we can travel.
	return 0;
}

/////////////DRY RUN//////////////

/*
------
f1
1 - 2
i-0 1 - 2

0 1 1
1 1 1
1 1 1

grid after flip
0 1 1
1 1 0
1 1 1

------
f2
2 - 4
2 - 0
i-1 2 - 0

0 1 1
1 1 0
1 1 1

grid after flip
0 1 1
1 1 0
0 1 1

------
f3
3 - 2
3 - -2
4 - 1
4 - -1
1 - 2
1 - -2
0 - 1
i-6 0 - 1

0 1 1
1 1 0
0 1 1

grid after flip
0 0 1
1 1 0
0 1 1

------
f4
1 - 3
1 - -1
2 - 2
i-2 2 - 2

0 0 1
1 1 0
0 1 1

grid after flip
0 0 1
1 1 0
0 1 0

------
f5
3 - 4
3 - 0
4 - 3
4 - 1
1 - 4
1 - 0
i-5 1 - 0

0 0 1
1 1 0
0 1 0

grid after flip
0 0 1
0 1 0
0 1 0

------
f6
2 - 2
2 - -2
3 - 1
3 - -1
0 - 2
i-4 0 - 2

0 0 1
0 1 0
0 1 0

grid after flip
0 0 0
0 1 0
0 1 0

------
f7
1 - 4
1 - 0
2 - 3
2 - 1
i-3 2 - 1

0 0 0
0 1 0
0 1 0

grid after flip
0 0 0
0 1 0
0 0 0

------
f8
3 - 3
3 - -1
4 - 2
4 - 0
1 - 3
1 - -1
0 - 2
0 - 0

fReturning..8
0 0 0
0 1 0
0 0 0
returned

f after backtracking 7
-1 - 4
-1 - 0
-2 - 3
-2 - 1

fReturning..7
0 0 0
0 1 0
0 1 0
returned

f after backtracking 6
0 - -2
-1 - 1
-1 - -1

fReturning..6
0 0 1
0 1 0
0 1 0
returned

f after backtracking 5
0 - 3
0 - 1

fReturning..5
0 0 1
1 1 0
0 1 0
returned

f after backtracking 4
2 - 0
-1 - 3
-1 - -1
-2 - 2
-2 - 0

fReturning..4
0 0 1
1 1 0
0 1 1
returned

f after backtracking 3
0 - -1

fReturning..3
0 1 1
1 1 0
0 1 1
returned

f after backtracking 2
3 - 3
3 - 1
0 - 4
0 - 0
-1 - 3
-1 - 1

fReturning..2
0 1 1
1 1 0
1 1 1
returned

f after backtracking 1
1 - -2
2 - 1
i-2 2 - 1

0 1 1
1 1 1
1 1 1

grid after flip
0 1 1
1 1 1
1 0 1

------
f2
3 - 3
3 - -1
4 - 2
4 - 0
1 - 3
1 - -1
0 - 2
i-6 0 - 2

0 1 1
1 1 1
1 0 1

grid after flip
0 1 0
1 1 1
1 0 1

------
f3
1 - 4
1 - 0
i-1 1 - 0

0 1 0
1 1 1
1 0 1

grid after flip
0 1 0
0 1 1
1 0 1

------
f4
2 - 2
i-0 2 - 2

0 1 0
0 1 1
1 0 1

grid after flip
0 1 0
0 1 1
1 0 0

------
f5
3 - 4
3 - 0
4 - 3
4 - 1
1 - 4
1 - 0
0 - 3
0 - 1
i-7 0 - 1

0 1 0
0 1 1
1 0 0

grid after flip
0 0 0
0 1 1
1 0 0

------
f6
1 - 3
1 - -1
2 - 2
2 - 0
i-3 2 - 0

0 0 0
0 1 1
1 0 0

grid after flip
0 0 0
0 1 1
0 0 0

------
f7
3 - 2
3 - -2
4 - 1
4 - -1
1 - 2
i-4 1 - 2

0 0 0
0 1 1
0 0 0

grid after flip
0 0 0
0 1 0
0 0 0

------
f8
2 - 4
2 - 0
3 - 3
3 - 1
0 - 4
0 - 0
-1 - 3
-1 - 1

fReturning..8
0 0 0
0 1 0
0 0 0
returned

f after backtracking 7
1 - -2
0 - 1
0 - -1

fReturning..7
0 0 0
0 1 1
0 0 0
returned

f after backtracking 6
-1 - 3
-1 - -1
-2 - 2
-2 - 0

fReturning..6
0 0 0
0 1 1
1 0 0
returned

f after backtracking 5

fReturning..5
0 1 0
0 1 1
1 0 0
returned

f after backtracking 4
2 - -2
3 - 1
3 - -1
0 - 2
0 - -2
-1 - 1
-1 - -1

fReturning..4
0 1 0
0 1 1
1 0 1
returned

f after backtracking 3
2 - 3
2 - 1
-1 - 4
-1 - 0
-2 - 3
-2 - 1

fReturning..3
0 1 0
1 1 1
1 0 1
returned

f after backtracking 2
0 - 0

fReturning..2
0 1 1
1 1 1
1 0 1
returned

f after backtracking 1
2 - -1
-1 - 2
-1 - -2
-2 - 1
-2 - -1

fReturning..1
0 1 1
1 1 1
1 1 1
returned

1
*/