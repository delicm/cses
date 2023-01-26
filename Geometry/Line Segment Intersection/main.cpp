#include <iostream>
#include <complex>

using namespace std;

#define cplx complex<long long>

long long cross(cplx a, cplx b) {return (conj(a)*b).imag();}

int side(cplx a, cplx b, cplx p)
{
    long long c = cross(p-a, p-b);
    if(c == 0) return 0;
    if(c > 0) return 1;
    return -1;
}

bool between(cplx a, cplx b, cplx p)
{
    if(side(a, b, p) != 0) return false;
    a -= p; b -= p;
    return (abs(a+b) < abs(a)+abs(b));
}

bool intersect(cplx a, cplx b, cplx c, cplx d)
{
     if(a == c || b == c || a == d || b == d) return true;
     if(between(a, b, c) || between(a, b, d) || between(c, d, a) || between(c, d, b)) return true;
     if(!side(a, b, c) || !side(a, b, d) || !side(c, d, a) || !side(c, d, b)) return false;
     if(side(a, b, c) == side(a, b, d)) return false;
     if(side(c, d, a) == side(c, d, b)) return false;
     return true;
}

int main()
{
    int t; cin >> t;
    while(t--){
        long long x1, x2, x3, x4, y1, y2, y3, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        cplx a(x1, y1), b(x2, y2), c(x3, y3), d(x4, y4);

        if(intersect(a, b, c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
