#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 500100;

int father[MAXN] = {0};
int dfsTime[MAXN] = {0}, linkTime[MAXN] = {0}, cct[MAXN] = {0}, st[MAXN] = {0};
bool statue[MAXN] = {0};
int nowTime = 0, cnt = 0, top = 0;
int point[MAXN] = {0}, nxt[MAXN] = {0}, v[MAXN] = {0}, cur[MAXN] = {0}, tot = 0;
int money[MAXN] = {0};
bool cctbar[MAXN] = {0}, bar[MAXN] = {0};
int cctmoney[MAXN] = {0}, f[MAXN] = {0};
int x[MAXN], y[MAXN], n, m, start, p;
int rudu[MAXN] = {0}, able[MAXN] = {0};

inline void memorycheck()
{
    int memory = sizeof(dfsTime) + sizeof(linkTime) + sizeof(cct) + sizeof(st) + sizeof(point)
               + sizeof(nxt) + sizeof(v) + sizeof(money) + sizeof(cctbar) + sizeof(bar)
               + sizeof(cctmoney) + sizeof(f) + sizeof(x) + sizeof(y);
    printf("%d\n", memory / 1024 / 1024);
}

inline void clear()
{
    tot = 0;
    memset(point, 0, sizeof(point));
    memset(nxt, 0, sizeof(nxt));
}

inline void addedge(int x, int y)
{
    tot++;
    nxt[tot] = point[x];
    point[x] = tot;
    v[tot] = y;
}

inline void dfs(int now)
{
    while (now)
    {
        if (!dfsTime[now])
        {
            dfsTime[now] = linkTime[now] = ++nowTime;
            st[++top] = now;
            cur[now] = point[now];
        }
        else
        {
            if (statue[now])
            {
                linkTime[now] = min(linkTime[now], linkTime[v[cur[now]]]);
                statue[now] =false;
            }
            cur[now] = nxt[cur[now]];
        }
        
        if (!cur[now])
        {
            if (dfsTime[now] == linkTime[now])
            {
                cnt++;
                while (1)
                {
                    cct[st[top--]] = cnt;
                    if (st[top + 1] == now) break;
                }
            }
            now = father[now];
            continue;
        }
        
        if (!dfsTime[v[cur[now]]])
        {
            statue[now] = true;
            father[v[cur[now]]] = now;
            now = v[cur[now]];
            continue;
        }
        else
            if (!cct[v[cur[now]]])
                linkTime[now] = min(linkTime[now], dfsTime[v[cur[now]]]);
    }
}

int main()
{
	freopen("save.in", "r", stdin);
	freopen("save.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &x[i], &y[i]);
        addedge(x[i], y[i]);
    }
    for (int i = 1; i <= n; i++) scanf("%d", &money[i]);
    scanf("%d%d", &start, &p);
    for (int i = 1; i <= p; i++)
    {
        int x;
        scanf("%d", &x);
        bar[x] = true;
    }
    for (int i = 1; i <= n; i++)
        if (!dfsTime[i])
            dfs(i);
    clear();
    for (int i = 1; i <= n; i++)
    {
        cctbar[cct[i]] |= bar[i];
        cctmoney[cct[i]] += money[i];
    }
    for (int i = 1; i <= m; i++)
        if (cct[x[i]] != cct[y[i]])
        {    
            addedge(cct[x[i]], cct[y[i]]);
            rudu[cct[y[i]]]++;
        }
    queue<int> q;
    while (!q.empty()) q.pop();
    for (int i = 1; i <= cnt; i++)
        if (!rudu[i])
            q.push(i);
    able[cct[start]] = 1;
    int ans = 0;
    while (!q.empty())
    {
        int now = q.front(); q.pop();
        f[now] += cctmoney[now] * able[now];
        if (cctbar[now])
            ans = max(ans, f[now]);
        for (int temp = point[now]; temp; temp = nxt[temp])
        {
            rudu[v[temp]]--;
            if (!rudu[v[temp]]) q.push(v[temp]);
            f[v[temp]] = max(f[v[temp]], f[now]);
            able[v[temp]] |= able[now];
        }
    }
    printf("%d\n", ans);
}
