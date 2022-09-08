/*
Given weights and values of n items, put these items in a knapsack of capacity W
to get the maximum total value in the knapsack. In other words, given two integer arrays val[0..n-1]
and wt[0..n-1] which represent values and weights associated with n items respectively.
Also given an integer W which represents knapsack capacity, find out the maximum value
subset of val[] such that sum of the weights of this subset is smaller than or equal to W.
---You cannot break an item---, either pick the complete item or don’t pick it (0-1 property).*/

// if you could have break the item, use greedy method(ratio of weighs and profit)


// working

/*
value[] = {60, 100, 120};
weight[] = {10, 20, 30};
W = 50;


Weight = 10; Value = 60;
Weight = 20; Value = 100;
Weight = 30; Value = 120;


Weight = (20+10); Value = (100+60);
Weight = (30+10); Value = (120+60);
Weight = (30+20); Value = (120+100);
Weight = (30+20+10) > 50

Solution: 220
*/

// time comp-- 2^n-jaise 4 total element h ,,saaare cases dkhne k liye 2 ki power 4 tak jana padega


#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n) {
	if (n == 0 || W == 0) { //agar last item mai pahoch gaye...ya fir w==0 mtlb weight full hogya
		return 0;
	}


	// agar item ka weight capacity se zyada ho to n-1 item k liye check karo
	if (wt[n - 1] > W) {
		return knapSack(W, wt, val, n - 1);
	}

	// agar item ki value capacity se kam h to, do following...

	/*add value of last item, then check further,as the value has been added in the bag, the total weight will
	decrease by the added weight and also for going to next item do n-1.*/
	int option1 = val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1); // agar weight include krna h
	int option2 = knapSack(W, wt, val, n - 1); // agar weight include ni krna

	return max(option1, option2);
}



int main()
{
	int val[] = { 60, 100, 120 };
	int wt[] = { 10, 20, 30 };
	int W = 50;
	int n = sizeof(val) / sizeof(val[0]);
	cout << knapSack(W, wt, val, n);
	return 0;
}