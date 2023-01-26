#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
    int n;
    long long tempx, tempy;
    queue <string> q;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        scanf("%ld %ld", &tempx, &tempy);
        if((tempx+tempy)%3 == 0 && tempx<=2*tempy && tempy<=2*tempx) q.push("YES");
        else q.push("NO");
    }

    for(int i = 0; i < n; i++)
    {
        cout << q.front() << "\n";
        q.pop();
    }

    return 0;
}
