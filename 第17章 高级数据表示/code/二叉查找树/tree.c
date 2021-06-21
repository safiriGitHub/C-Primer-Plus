/* 树的支持函数 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

/* 树中的查找项 */
typedef struct pair {
    Trnode *parent;
    Trnode *child;
} Pair;

static Trnode* MakeNode(const Item* pi);
static bool ToLeft(const Item *i1, const Item *i2);
static bool ToRight(const Item *i1, const Item *i2);
static bool AddNode(Trnode *new_node, Trnode*root);
static void InOrder(const Trnode *root, void(*pfun)(Item item));
static Pair SeekItem(const Item* pi, const Tree *ptree);
static void DeleteAllNodes(Trnode *root);
static void DeleteNode(Trnode **ptr);

void InitializeTree(Tree * ptree)
{
    ptree->size = 0;
    ptree->root = NULL; 
}

bool TreeIsEmpty(const Tree * ptree)
{
    return ptree->root == NULL;
}

bool TreeIsFull(const Tree * ptree)
{
    return ptree->size == MAXITEMS;
}

int TreeItemCount(const Tree * ptree)
{
    return ptree->size;
}

bool AddItem(const Item * pi, Tree * ptree)
{
    Trnode *new_node;
    if (TreeIsFull(ptree))
    {
        fprintf(stderr, "Tree is full\n");
        return false;
    }
    if (SeekItem(pi, ptree).child != NULL)
    {
        fprintf(stderr, "Attempted to add duplicate item\n");
        return false;
    }
    
    new_node = MakeNode(pi);
    if (new_node == NULL)
    {
        fprintf(stderr, "Couldn't create node\n");
        return false;
    }

    /* 成功创建了一个新节点 */
    ptree->size++;
    if (ptree->root == NULL)
        ptree->root = new_node;
    else
        AddNode(new_node, ptree->root);
    
    return true;
}

bool InTree(const Item * pi, const Tree * ptree)
{
    return (SeekItem(pi, ptree).child == NULL) ? false : true;
}


bool DeleteItem(const Item * pi, Tree * ptree)
{
    Pair look;
    look = SeekItem(pi, ptree);
    if (look.child == NULL)
        return false;
    if (look.parent == NULL) /* 删除根节点 */
        DeleteNode(&ptree->root);
    else if (look.parent->left == look.child)
        DeleteNode(&look.parent->left);
    else
        DeleteNode(&look.parent->right);
    
    ptree->size--;
    return true;
}


void Traverse(const Tree * ptree, void(*pfun)(Item item))
{
    if (ptree != NULL)
        InOrder(ptree->root, pfun);
}

void DeleteAll(Tree * ptree)
{
    if (ptree != NULL)
        DeleteAllNodes(ptree->root);
    ptree->root = NULL;
    ptree->size = 0;
}


/* ************* */


static void InOrder(const Trnode *root, void(*pfun)(Item item))
{
    if (root != NULL)
    {
        InOrder(root->left, pfun);
        (*pfun)(root->item);
        InOrder(root->right, pfun);
    }
    /* 注意， InOrder()函数处理左子树，然后处理项，最后处理右子树。这种遍历树的顺 序是按字母排序进行。
    如果你有时间，可以试试用不同的顺序，比如，项- 左子树-右子树或者左子树-右子树-项，看看会发生什么。 */
}

static Trnode* MakeNode(const Item* pi)
{
    Trnode *new_node;
    new_node = (Trnode *)malloc(sizeof(Trnode));
    if (new_node != NULL)
    {
        new_node->item = *pi;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}

static bool AddNode(Trnode *new_node, Trnode*root)
{
    if (ToLeft(&new_node->item, &root->item))
    {
        if (root->left == NULL)
            root->left = new_node;
        else
            AddNode(new_node, root->left);
    }
    else if (ToRight(&new_node->item, &root->item))
    {
        if (root->right == NULL)
            root->right = new_node;
        else
            AddNode(new_node, root->right);
    }
    else /* 不允许有重复项 */
    {
        fprintf(stderr, "location error on AddNode()\n");
        exit(1);
    }
    
}

static bool ToLeft(const Item *i1, const Item *i2)
{
    int comp1 = strcmp(i1->petname, i2->petname);
    if (comp1 < 0)
    {
        return true;
    }
    else if (comp1 > 0)
    {
        return false;
    }
    else if (comp1 == 0)
    {
        return strcmp(i1->petkind, i2->petkind) < 0;
    }
}

static bool ToRight(const Item *i1, const Item *i2)
{
    int comp1 = strcmp(i1->petname, i2->petname);
    if (comp1 > 0)
    {
        return true;
    }
    else if (comp1 < 0)
    {
        return false;
    }
    else if (comp1 == 0)
    {
        return strcmp(i1->petkind, i2->petkind) > 0;
    }
}

static Pair SeekItem(const Item* pi, const Tree *ptree)
{
    Pair look;
    look.parent = NULL;
    look.child = ptree->root;

    if (look.child == NULL)
        return look; /* 提前退出 */
    while (look.child != NULL)
    {
        if (ToLeft(pi, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->left;
        }
        else if (ToRight(pi, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->right;
        }
        else        /* 如果前两种情况都不满足，则必定是相等的情况 */
            break;  /* look.child 目标项的节点 */
    }
    return look;
}

static void DeleteNode(Trnode **ptr)
{
    Trnode *temp;
    if ((*ptr)->left == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    }
    if ((*ptr)->right == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
    else /* 被删除的节点有两个子节点 */
    {
        /* 找到重新连接右子树的位置 */
        for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right)
            continue;
        temp->right = (*ptr)->right; /* 被删除节点的右子树赋值给左子树的最右节点的右指针 */
        
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
}


static void DeleteAllNodes(Trnode *root)
{
    Trnode *pright;
    if (root != NULL)
    {
        pright = root->right;
        DeleteAllNodes(root->left);
        free(root);
        DeleteAllNodes(pright);
    }
}