#include "avl.h"
#include <iostream>

AVL::AVL(int Value, AVL* Parent, AVL* Left, AVL* Right)
:value(Value), parent(Parent), left(Left), right(Right)
{

}

void AVL::insert(int Value, AVL* Parent)
{
    if(this == NULL){
        *this = AVL(Value, Parent);
        if(Parent == NULL) return;
        if(Parent->value > Value) Parent->left = this;
        else Parent->right = this;
    }
    else{
        if(value > Value) left->insert(Value);
        else right->insert(Value);
    }
}

bool AVL::find(int Value)
{
    if(this == NULL) return false;
    if(value == Value) return true;

    if(value > Value) return left->find(Value);
    else return right->find(Value);
}

void AVL::dumb(){
    std::cout << "I'm dumb" << std::endl;
}
