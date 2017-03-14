//Problem: VKcup2017 Qualification round 1. Problem A.
//Authors of the solution:
//Volodin Sergey <sergei.volodin@phystech.edu>
//Solomatin Ivan <ivan.solomatin@phystech.edu>.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[100];

int main()
{
	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> a[i];
	sort(a, a + N);
	cout << a[N / 2] << endl;
	return 0;
}