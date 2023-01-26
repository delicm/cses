#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, k;
vector <int> moves;
string s;

void process(int pos)
{
    for(auto m : moves){
        if(pos < m) continue;
        else if(s[pos-m] == 'L'){
            s[pos] = 'W'; return;
        }
    }
}

int main()
{
    cin >> n >> k; s.resize(n+1, 'L'); moves.resize(k);
    for(int i = 0; i < k; i++) cin >> moves[i];
    for(int i = 1; i <= n; i++) process(i);

    for(int i = 1; i <= n; i++) cout << s[i];

    return 0;
}
