#include <iostream>
#include <string>

using namespace std;

int n = 0;
int t = 0;
string s = "ka.";
bool ind[9][9];

void traverse(int step, int x, int y)
{
    if(x < 0 || x >= t || y < 0 || y >= t) return;
    if(ind[x][y]) return;
    if(step == t*t-1)
    {
        if(x == t-1 && y == 0)
        {
            n++;
            return;
        }
        return;
    }

    if(x == t-1 && y == 0) return;

    if((x == 0 || x == t-1) && y != 0 && y != t-1)
    {
        if(ind[x][y+1] == false && ind[x][y-1] == false) return;
    }
    if((y == 0 || y == t-1) && x != 0 && x != t-1)
    {
        if(ind[x+1][y] == false && ind[x-1][y] == false) return;
    }
    if(y != 0 && y != t-1 && x != 0 && x != t-1)
    {
        //if(ind[x+1][y] == 0 && ind[x-1][y] == 0 && ind[x][y+1] == 1 && ind[x][y-1] == 1) return;
        //if(ind[x+1][y] == 1 && ind[x-1][y] == 1 && ind[x][y+1] == 0 && ind[x][y-1] == 0) return;
        if(ind[x+1][y] == ind[x-1][y] && ind[x][y+1] == ind[x][y-1]) return;
    }

    ind[x][y] = true;
    step++;

    if(s[step-1] == '?')
    {
        traverse(step, x+1, y);
        traverse(step, x-1, y);
        traverse(step, x, y+1);
        traverse(step, x, y-1);
    }
    else if(s[step-1] == 'R')
    {
        traverse(step, x, y+1);
    }
    else if(s[step-1] == 'L')
    {
        traverse(step, x, y-1);
    }
    else if(s[step-1] == 'U')
    {
        traverse(step, x-1, y);
    }
    else if(s[step-1] == 'D')
    {
        traverse(step, x+1, y);
    }

    ind[x][y] = false;
    return;
}

int main()
{
    cin >> s;
    //cin >> t;
    t = 7;
    //bool ind [9][9];
    for(int i = 0; i < t; i++)
    {
        for(int j = 0; j < t; j++)
        {
            ind[i][j]=0;
        }
    }

    /*ind[1][2] = 1;

    for(int i = 0; i < t; i++)
    {
        for(int j = 0; j < t; j++)
        {
            cout << ind[i][j];
        }
        cout << endl;
    }*/

    //ind[t-1][t-1] = 1;

    traverse(0, 0, 0);
    cout << n;

    return 0;
}
