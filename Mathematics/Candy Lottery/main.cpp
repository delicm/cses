#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

vector <double> maxp;

int main()
{
    int n, k; cin >> n >> k;
    maxp.resize(k+1);

    for(double i = 1.00000000; i <= k; i++){
        maxp[i] = 1-pow((i-1)/k, n);
    }

    double sol = 0;

    for(int i = 1; i <= k; i++){
        sol += maxp[i];
    }
    cout << fixed << setprecision(6) << sol;

    return 0;
}
