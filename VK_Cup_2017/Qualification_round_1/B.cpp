//Problem: VKcup2017 Qualification round 1. Problem B.
//Authors of the solution:
//Volodin Sergey <sergei.volodin@phystech.edu>
//Solomatin Ivan <ivan.solomatin@phystech.edu>.

#include <iostream>
#include <stdlib.h>
using std::cout;
using std::cin;
using std::endl;

#define MAXN 150
int N;
int arr[MAXN];
int idx[MAXN];

static int comp_arr(const void* p1, const void* p2)
{
    int i1 = *(int*) p1;
    int i2 = *(int*) p2;
    if(i1 == 0)
        return(-1);
    else if(i2 == 0)
        return(1);
    else
        return(arr[i1] < arr[i2] ? 1 : -1);
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
        idx[i] = i;
    }

    int sum = 0;
    for(int i = 0; i < N; i++)
        sum += arr[i];

    if(sum < N - 1 || arr[0] == 0)
    {
        cout << "-1" << endl;
        return(0);
    }

    qsort(idx, N, sizeof(int), comp_arr);

    int target = 1;
    cout << N - 1 << endl;
    for(int i = 0; i < N; i++)
    {
        int current = idx[i];
        while(target < N && arr[current] > 0)
        {
            arr[current]--;
            cout << (current + 1) << " " << (idx[target] + 1) << endl;
            target++;
        }
    }

    return(0);
}