#include <iostream>
#include <vector>
#include <complex>

using namespace std;

#define cplx complex<long long>
cplx infty(1000000009, 1000887658);

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

string verdict(vector<cplx> v, cplx p)
{
    int n = v.size()-1;
    for(int i = 0; i < n; i++) if(v[i] == p) return "BOUNDARY";
    for(int i = 0; i < n; i++) if(between(v[i], v[i+1], p)) return "BOUNDARY";
    int cnt = 0;
    for(int i = 0; i < n; i++) cnt += intersect(v[i], v[i+1], p, infty);
    if(cnt%2 == 0) return "OUTSIDE";
    return "INSIDE";
}

int main()
{
    int n, m; cin >> n >> m;
    vector<cplx> v(n+1);
    int x, y;
    for(int i = 0; i < n; i++){cin >> x >> y; cplx temp(x, y); v[i] = temp;}
    v[n] = v[0];

    for(int i = 0; i < m; i++){
        cin >> x >> y; cplx temp(x, y);
        cout << verdict(v, temp) << endl;
    }

    return 0;
}
