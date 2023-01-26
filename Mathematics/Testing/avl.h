#ifndef AVL_H
#define AVL_H

#include <stdio.h>

class AVL
{
    public:
        AVL(int Value = 0, AVL* Parent = NULL, AVL* Left = NULL, AVL* Right = NULL);
        void insert(int Value, AVL* Parent = NULL);
        bool find(int Value);
        void dumb();
    private:
        int value;
        AVL* parent;
        AVL* left;
        AVL* right;
};

#endif
