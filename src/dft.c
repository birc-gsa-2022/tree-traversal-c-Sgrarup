#include "gsa.h"
#include <assert.h>
#include <stdio.h>

void dfs_rec(tree t, dynarr a) {
    if(t->left != NULL ) dfs_rec(t->left, a);
    append(&a, t->val);
    if(t->right != NULL) dfs_rec(t->right, a);
}

void dfs(tree t, dynarr a) {
    tree cur = t;
    while (cur->left != NULL && cur->left) {
        append(&a, cur->val);
        if(cur->left->val < cur->right->val) cur = cur->left;
        else cur = cur->right;
    }
}

dynarr in_order(tree t)
{
    dynarr a = new_dynarr();
    if (t == NULL) return a;
    dfs_rec(t, a);
    return a;
}