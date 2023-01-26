#include <iostream>

using namespace std;

bool digit[10];

void checkn(int n)
{
    for(int i = 0; i <= 9; i++) digit[i]=0;
    while(n > 0)
    {
        digit[n%10] = true;
        n/=10;
    }
}

int main()
{
    int n; cin >> n;

    long long s[max(10, n+1)]; long long temp = 1000001;

    s[0] = 0;
    s[1] = 1;
    s[2] = 1;
    s[3] = 1;
    s[4] = 1;
    s[5] = 1;
    s[6] = 1;
    s[7] = 1;
    s[8] = 1;
    s[9] = 1;

    for(int i = 10; i <= n; i++)
    {
        checkn(i);

        for(int j = 1; j <= 9; j++)
        {
            if(digit[j]) temp = min(temp, s[i-j]);
        }
        s[i] = temp+1;
        temp = 1000001;
    }

    cout << s[n];

    return 0;
}
