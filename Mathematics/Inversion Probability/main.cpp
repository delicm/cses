#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector <int> v;

double swapProb(int r, int s)
{
    double sol = 0;
    for(double i = 1; i <= r; i++){
        if(i > s) sol += 1;
        else sol += (i-1)/s;
    }
    return sol/r;
}

int main()
{
    int n; cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    double sol = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            sol += swapProb(v[i], v[j]);
        }
    }

    cout << fixed << setprecision(6) << sol;

    return 0;
}
