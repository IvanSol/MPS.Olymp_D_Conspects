//Problem: VKcup2017 Qualification round 1. Problem D.
//Authors of the solution:
//Volodin Sergey <sergei.volodin@phystech.edu>
//Solomatin Ivan <ivan.solomatin@phystech.edu>.

#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

#define AMAX 10050
unsigned long long cnt[AMAX];

int N, K;

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
	memset(cnt, 0, sizeof(cnt));

	cin >> N >> K;

	int a_max = -1;
	int a;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		cnt[a]++;
		if (a_max < a)
			a_max = a;
	}

	unsigned long long res = 0;

	if (K == 0)
	{
		for (int ai = 0; ai <= a_max; ai++)
			if (cnt[ai] > 0)
				res += (cnt[ai] * (cnt[ai] - 1));
	}
	else
	{
		unsigned long long bmax = a_max * 2;
		for (unsigned b = 0; b <= bmax; b++)
			if (count_bit(b) == K)
				for (int ai = 0; ai <= a_max; ai++)
					if (cnt[ai] > 0)
					{
						int aj = ai ^ b;
						if (aj != ai && aj <= a_max && cnt[aj] > 0)
							res += cnt[ai] * cnt[aj];
					}
	}

	cout << res / 2 << endl;
	return 0;
}