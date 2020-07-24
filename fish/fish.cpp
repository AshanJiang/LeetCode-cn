#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <time.h>
using namespace std;

constexpr auto MAX_N = 30000+5; // 鱼的最大数量

int n, v;

struct Fish
{
    int w; // 重量
    int v; // 价值
    inline bool operator < (const Fish& x) const
    {
        // 排序，按照重量从1到2，同重量价值从高到低排列
        if (w != x.w) return w < x.w;
        return v > x.v;
    }
};

Fish a[MAX_N];

int main()
{
    clock_t tStart = clock();
    int ans = 0;
    freopen("C:\\工作\\eat_fish\\d9.in", "r", stdin);
    scanf("%d%d", &n, &v);
    int division = 0; // 重量为1的鱼的数量
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &a[i].w, &a[i].v);
        if (a[i].w == 1) ++division;
    }
    sort(a + 1, a + n + 1); // division为重量为1的鱼和重量为2的鱼的分界点
    int i = 0, j = division;
    while (i < division && i < v)
    {
        // 先从大到小吃重量1的鱼，直到胃口吃满或者鱼吃完
        ans += a[++i].v;
    }
    while (j < n && (i + (j - division + 1) * 2) <= v)
    {
        // 胃口没用完，再从大到小吃重量2的鱼
        ans += a[++j].v;
    }
    // 如果还未使用的重量2的鱼的价值大于等于已使用的两条价值最低的重量1的鱼，则用重量2的鱼换走2条重量1的鱼
    while (i >= 2 && j < n && a[i].v + a[i - 1].v <= a[j + 1].v)
    {
        ans += a[++j].v;
        ans -= a[i--].v;
        ans -= a[i--].v;
    }
    // 交换后，若胃口未满，则
    // 1.若还有重量1的鱼没吃，再选一条最贵的1号鱼吃掉
    // 2.若还有重量2的鱼没吃，用重量2的鱼换最便宜的重量1的鱼出去
    if ((i + (j - division) * 2) < v)
    {
        int biggerV = 0;
        if (i < division)
            biggerV = a[i + 1].v;
        if (j < n)
            biggerV = max(biggerV, a[j + 1].v - a[i].v);
        ans += biggerV;
    }
    printf("%d\n", ans);
	fclose(stdin);
    printf("Time taken: %.5fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
	return 0;
}