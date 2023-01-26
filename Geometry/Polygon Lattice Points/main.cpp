#include <iostream>
#include <vector>
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

long long gcd(long long a, long long b)
{
    if(a < b) swap(a, b);
    if(b == 0) return a;
    return gcd(b, a%b);
}

long long area2(vector<cplx> v)
{
    int n = v.size()-1;
    long long area = 0;
    for(int i = 0; i < n; i++) area += cross(v[i], v[i+1]);
    return abs(area);
}

long long edgecount(vector<cplx> v)
{
    long long cnt = 0; int n = v.size()-1;
    for(int i = 0; i < n; i++) cnt += gcd(abs(v[i].real()-v[i+1].real()), abs(v[i].imag()-v[i+1].imag()));
    return cnt;
}

long long point_count(vector<cplx> v)
{
    return (area2(v)-edgecount(v)+2)/2;
}

int main()
{
    int n; cin >> n;
    vector<cplx> v(n+1);

    for(int i = 0; i < n; i++){int x, y; cin >> x >> y; cplx temp(x,y); v[i] = temp;}
    v[n] = v[0];

    cout << point_count(v) << " " << edgecount(v);

    return 0;
}
