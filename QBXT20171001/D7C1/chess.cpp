#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int board[10][10], isKing[10][10];
int dir[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
int best_deep;
vector<int> w;
vector<int> ways;

void dfs(int step, int x, int y, int isKing)
{
    w.push_back(x * 10 + y);
    if (step > best_deep)
    {
        best_deep = step;
        ways.clear();
        ways.push_back(w[0]);
    }
    else if (step > 1 && step == best_deep)
    {
        ways.push_back(w[0]);
    }

    int dis_limit = isKing ? 9 : 2;

    for (int d = 0; d < 4; d++)
    {
        bool pass = false;
        int passx = 0, passy = 0;
        for (int dis = 1; dis <= dis_limit; dis++)
        {
            int nxtX = x + dis * dir[d][0];
            int nxtY = y + dis * dir[d][1];
            if (!(0 <= nxtX && nxtX < 10 && 0 <= nxtY && nxtY < 10))
                break;
            if (board[nxtX][nxtY] == 1 || board[nxtX][nxtY] == 3)
                break;
            if (pass && board[nxtX][nxtY] == 2)
                break;
            if (board[nxtX][nxtY] == 2)
            {
                pass = true;
                passx = nxtX;
                passy = nxtY;
            }
            else
            {
                if (!pass)
                    continue;
                board[passx][passy] = 3;
                dfs(step + 1, nxtX, nxtY, isKing);
                board[passx][passy] = 2;
            }
        }
    }
    w.pop_back();
}

bool getAvailable()
{
    ways.clear();
    w.clear();
    best_deep = 1;
    for (int curX = 0; curX < 10; curX++)
        for (int curY = 0; curY < 10; curY++)
            if (board[curX][curY] == 1)
                dfs(1, curX, curY, isKing[curX][curY]);
    if (best_deep == 1)
    {
        for (int curX = 0; curX < 10; curX++)
            for (int curY = 0; curY < 10; curY++)
                if (board[curX][curY] == 1)
                {
                    if (isKing[curX][curY])
                    {
                        for (int x = curX + 1, y = curY + 1; 0 <= x && x < 10 && 0 <= y && y < 10; x++, y++)
                            if (!board[x][y])
                                ways.push_back(curX * 10 + curY);
                            else
                                break;
                        for (int x = curX + 1, y = curY - 1; 0 <= x && x < 10 && 0 <= y && y < 10; x++, y--)
                            if (!board[x][y])
                                ways.push_back(curX * 10 + curY);
                            else
                                break;
                        for (int x = curX - 1, y = curY + 1; 0 <= x && x < 10 && 0 <= y && y < 10; x--, y++)
                            if (!board[x][y])
                                ways.push_back(curX * 10 + curY);
                            else
                                break;
                        for (int x = curX - 1, y = curY - 1; 0 <= x && x < 10 && 0 <= y && y < 10; x--, y--)
                            if (!board[x][y])
                                ways.push_back(curX * 10 + curY);
                            else
                                break;
                    }
                    else
                    {
                        if (curX - 1 >= 0 && curY - 1 >= 0 && !board[curX - 1][curY - 1])
                            ways.push_back(curX * 10 + curY);
                        if (curX - 1 >= 0 && curY + 1 < 10 && !board[curX - 1][curY + 1])
                            ways.push_back(curX * 10 + curY);
                    }
                }
    }
    if (!ways.size())
        return false;
    return true;
}

int main()
{
    freopen("chess.in", "r", stdin);
    freopen("chess.out", "w", stdout);
    memset(board, 0, sizeof(board));
    memset(isKing, 0, sizeof(isKing));
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
        {
            char c;
            scanf(" %c", &c);
            board[i][j] = c - '0';
        }
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
        {
            char c;
            scanf(" %c", &c);
            isKing[i][j] = c - '0';
        }
    getAvailable();
	if (!ways.size())
		printf("0\n");
	else {
		sort(ways.begin(), ways.end());
		printf("%d\n", (int)ways.size());
		for (int i = 0; i < (int)ways.size(); i++)
			printf("(%d,%d)\n", ways[i] / 10 + 1, ways[i] % 10 + 1);
	}	
}
