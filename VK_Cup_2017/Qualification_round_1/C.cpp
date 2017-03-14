//Problem: VKcup2017 Qualification round 1. Problem C.
//Authors of the solution:
//Volodin Sergey <sergei.volodin@phystech.edu>
//Solomatin Ivan <ivan.solomatin@phystech.edu>.

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;

bool a[1010][1010];
int d[1010][1010];
bool used[1010][1010];
queue <pair<int, int> > Q;

const char dest[4] = { 'D', 'L', 'R', 'U' };

char revert(char c)
{
	if (c == 'D')
		return 'U';
	if (c == 'U')
		return 'D';
	if (c == 'L')
		return 'R';
	if (c == 'R')
		return 'L';
	exit(1);
}

pair <int, int> move(const pair <int, int> &pos, char dest)
{
	if (dest == 'D')
		return make_pair(pos.first + 1, pos.second);
	if (dest == 'U')
		return make_pair(pos.first - 1, pos.second);
	if (dest == 'L')
		return make_pair(pos.first, pos.second - 1);
	if (dest == 'R')
		return make_pair(pos.first, pos.second + 1);
	exit(1);
}

int main()
{
	int N, M, K;
	cin >> N >> M >> K;
	memset(a, sizeof(a), 0);
	memset(used, sizeof(used), 0);
	int start_i = -1;
	int start_j = -1;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			char c = 0;
			cin >> c;
			if (c != '*')
				a[i + 1][j + 1] = true;
			if (c == 'X')
			{
				start_i = i + 1;
				start_j = j + 1;
			}
		}

	pair <int, int> v = make_pair(start_i, start_j);
	bool ok = false;
	for (int c = 0; c < 4; c++)
	{
		pair <int, int> pos = move(v, dest[c]);
		ok |= a[pos.first][pos.second];
	}

	if (!ok || (K % 2 != 0))
	{
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}

	d[v.first][v.second] = 0;
	used[v.first][v.second] = true;
	Q.push(v);
	while (!Q.empty())
	{
		v = Q.front();
//		cout << "BFS: " << v.first << ' ' << v.second << " d = " << d[v.first][v.second] << endl;
		Q.pop();
		int i = v.first;
		int j = v.second;
		for (int c = 0; c < 4; c++)
		{
				pair <int, int> pos = move(v, dest[c]);
			if ((a[pos.first][pos.second]) && (!used[pos.first][pos.second]))
			{
				//p[pos.first][pos.second] = revert(dest[c]);
				d[pos.first][pos.second] = d[v.first][v.second] + 1;
				used[pos.first][pos.second] = true;
				Q.push(pos);
			}
		}
	}
	int i = start_i;
	int j = start_j;
	v = make_pair(start_i, start_j);
	for (int k = 0; k < K; k++)
	{
		if (d[v.first][v.second] == K - k)
			break;
		for (int c = 0; c < 4; c++)
		{
			pair <int, int> pos = move(v, dest[c]);
			if (a[pos.first][pos.second])
			{
				cout << dest[c];
				v = pos;
				break;
			}
		}
	}
	while ((v.first != start_i) || (v.second != start_j))
	{
		for (int c = 0; c < 4; c++)
		{
			pair <int, int> pos = move(v, dest[c]);
			if ((a[pos.first][pos.second]) && (d[pos.first][pos.second] == d[v.first][v.second] - 1))
			{
				cout << dest[c];
				v = pos;
				break;
			}
		}
	}
	cout << endl;
	return 0;
}
