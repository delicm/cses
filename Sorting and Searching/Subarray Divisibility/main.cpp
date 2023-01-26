#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int x[n];

    for(int i = 0; i < n; i++)
        cin >> x[i];

    long long score = 0, sum = 0;
    map <long long, long long> m;

    for(int i = 0; i < n; i++)
    {
        sum += x[i];
        sum = (sum%n+n)%n;
        if(sum == 0) score++;
        score += m[(((sum-n)%n)+n)%n];
        m[sum]++;
    }

    cout << score;

    return 0;
}
