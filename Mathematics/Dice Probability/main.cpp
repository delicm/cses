#include <bits/stdc++.h>

using namespace std;

double p[601];
double q[601];

void copyp()
{
    for(int i = 0; i <= 600; i++) q[i] = p[i];
}

void updatep()
{
    for(int i = 0; i <= 5; i++){
        p[i] = 0;
        for(int j = 0; j < i; j++){
            p[i] += q[j]/6;
        }
    }

    for(int i = 6; i <= 600; i++){
        p[i] = 0;
        for(int j = 1; j <= 6; j++){
            p[i] += q[i-j]/6;
        }
    }
    copyp();
}

void init()
{
    p[0] = 1;
    for(int i = 1; i <= 600; i++) p[i] = 0;
    copyp();
}

int main()
{
    init();
    int n, a, b; cin >> n >> a >> b;
    double sol = 0;
    while(n--) updatep();
    for(int i = a; i <= b; i++) sol += 1000000*p[i];

    int ans = round(sol);

    cout << "0.";

    for(int i = 5; i >= 0; i--)
        if(ans < pow(10, i)) cout << 0;

    cout << ans;

    return 0;
}
