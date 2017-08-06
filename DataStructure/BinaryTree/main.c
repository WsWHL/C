#include <stdio.h>
#include <stdlib.h>

// 二叉树的二叉链表结点结构定义
typedef char TElemType;
typedef struct BiTNode  /* 结点结构 */
{
    TElemType data;     /* 结点数据 */
    struct BiTNode *lchild, *rchild;    /* 左右孩子指针 */
} BiTNode, *BiTree;
void CreateBiTree(BiTree *T);
void PreOrderTraverse(BiTree T);

int main()
{
    BiTree T;
    CreateBiTree(&T);

    return 0;
}

//  按前序输入二叉树中结点的值（一个字符）
//  #表示空树，构造二叉链表表示二叉树T
void CreateBiTree(BiTree *T)
{
    TElemType ch;
    scanf("%c", &ch);
    if(ch == '#')
        *T = NULL;
    else
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if(!*T)
            exit(0);
        ( *T) ->data = ch; /* 生成根结点 */
        CreateBiTree(&(*T)->lchild);    /* 构造左子树 */
        CreateBiTree(&(*T)->rchild);    /* 构造右子树 */
    }
}

//  二叉树的前序遍历
void PreOrderTraverse(BiTree T)
{
    if(T==NULL)
        return;
    printf("%c", T->data);  /* 显示结点数据 */
    PreOrderTraverse(T->lchild);    /* 再先序遍历左子树 */
    PreOrderTraverse(T->rchild);    /* 然后先序遍历右子树 */
}
