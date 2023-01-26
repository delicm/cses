#include <iostream>
#include "avl.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    cout << "Hello world" << endl;
    AVL tree;

    int q; cin >> q;
    while(q--){
        int t, x; cin >> t >> x;
        if(t == 1) tree.insert(x);
        else cout << tree.find(x) << endl;
    }
    return 0;
}
