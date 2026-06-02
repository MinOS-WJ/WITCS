#include <iostream>
using namespace std;

int board[9][9];
int pos[81][2];      // 记录空格位置
int tryNum[81];      // 当前尝试数字
int totalEmpty = 0;

// 判断 num 能否放在 (r,c)
bool valid(int r, int c, int num)
{
    for(int i = 0; i < 9; i++)
    {
        if(board[r][i] == num) return false;
        if(board[i][c] == num) return false;
    }

    int sr = (r / 3) * 3;
    int sc = (c / 3) * 3;

    for(int i = sr; i < sr + 3; i++)
        for(int j = sc; j < sc + 3; j++)
            if(board[i][j] == num)
                return false;

    return true;
}

// 输出结果
void printBoard()
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
            cout << board[i][j];
        cout << endl;
    }
}

int main()
{
    char ch;

    // 输入
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cin >> ch;
            board[i][j] = ch - '0';

            if(board[i][j] == 0)
            {
                pos[totalEmpty][0] = i;
                pos[totalEmpty][1] = j;
                tryNum[totalEmpty] = 1;
                totalEmpty++;
            }
        }
    }

    int k = 0;
    bool found = false;

    while(k >= 0)
    {
        if(k == totalEmpty)
        {
            if(found) cout << endl;
            printBoard();
            found = true;

            k--;
            if(k >= 0)
            {
                int r = pos[k][0];
                int c = pos[k][1];
                board[r][c] = 0;
                tryNum[k]++;
            }
            continue;
        }

        int r = pos[k][0];
        int c = pos[k][1];

        bool placed = false;

        while(tryNum[k] <= 9)
        {
            if(valid(r, c, tryNum[k]))
            {
                board[r][c] = tryNum[k];
                placed = true;
                break;
            }
            tryNum[k]++;
        }

        if(placed)
        {
            k++;
            if(k < totalEmpty)
                tryNum[k] = 1;
        }
        else
        {
            tryNum[k] = 1;
            board[r][c] = 0;
            k--;

            if(k >= 0)
            {
                int pr = pos[k][0];
                int pc = pos[k][1];
                board[pr][pc] = 0;
                tryNum[k]++;
            }
        }
    }

    if(!found)
        cout << "None" << endl;

    return 0;
}

/*
时间复杂度：
最坏情况下每个空格尝试 9 种可能，共 E 个空格：
O(9^E)

每次合法性检查扫描：
行 9 次 + 列 9 次 + 宫 9 次 = O(27) = O(1)

故总体：
O(9^E)

空间复杂度：
棋盘 O(81)
空位记录 O(81)
尝试数组 O(81)

总空间复杂度：
O(81) = O(1)
*/