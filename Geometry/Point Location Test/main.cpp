#include <iostream>
#include <complex>

#define X real()
#define Y imag()

using namespace std;

long long cross(complex<long long> a, complex<long long> b)
{
    return (conj(a)*b).Y;
}

int main()
{
    int n; cin >> n;
    while(n--){
        long long x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        complex<long long> p1(x1, y1), p2(x2, y2), p3(x3, y3);

        long long cs = cross(p3-p1, p3-p2);
        if(cs == 0) cout << "TOUCH" << endl;
        if(cs < 0) cout << "RIGHT" << endl;
        if(cs > 0) cout << "LEFT" << endl;
    }

    return 0;
}
