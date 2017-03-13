//Problem: VKcup2017 Qualification round 1. Problem D.
//Authors of the solution:
//Volodin Sergey 
//Solomatin Ivan <ivan.solomatin@phystech.edu>.

//The computational complexity is O(N^2). Does not fit the TL.
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

int N, K;
vector <int> a;

int count_bit(int x)
{
	int ans = 0;
	while (x > 0)
	{
		x &= x - 1;
		ans++;
	}
	return ans;
}

int main()
{
	cin >> N >> K;
	a.resize(N);

	for (int i = 0; i < N; i++)
		cin >> a[i];

	unsigned long long res = 0;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < i; j++)
			if (count_bit(a[i] ^ a[j]) == K)
				res++;
	
	cout << res;
	return 0;
}