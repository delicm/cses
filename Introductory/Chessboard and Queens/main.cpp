#include <iostream>

using namespace std;

long long counter = 0;
char b[8][8];
bool c[8], d1[15], d2[15];

void rec(int row)
{
    if(row == 8)
    {
        counter++;
        return;
    }
    for(int i = 0; i < 8; i++)
    {
        if(b[row][i] == '.' && c[i] == 0 && d1[row+i] == 0 && d2[7+row-i]==0)
        {
            c[i]=1; d1[row+i] =1; d2[row-i+7]=1;
            rec(row+1);
            c[i]=0; d1[row+i] =0; d2[row-i+7]=0;
        }
    }
    return;

}

int main()
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            cin >> b[i][j];
        }
    }

    for(int i = 0; i<8; i++)
    {
        c[i]=0;
        d1[i]=0;
        d2[i]=0;
    }
    for(int i = 8; i<15; i++)
    {
        d1[i]=0;
        d2[i]=0;
    }

    rec(0);
    cout << counter;

    return 0;
}
