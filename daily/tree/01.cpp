#include <stdio.h>
#include <stdlib.h>

typedef int dataType;
typedef struct node{
    dataType data;
    struct node *left,*right;
}BitTree;


typedef BitTree BitTreeNode;
typedef int BOOL;
#define TRUE 1
#define FALSE 0

typedef struct linkNode {
    BitTreeNode *_NodeAddrCopy;
    struct linkNode *pNext;
}LintStack;

LintStack *InitStack(void){
    LintStack *p = NULL;
    p = (LintStack *)malloc(sizeof(LintStack));
    if (p != NULL){
        p->pNext = NULL;
    }
    return p;
}
BOOL isEmptyLKMazeStack(LintStack *top){
    return (top->pNext == NULL);
}
LintStack *pushLKStack(LintStack *top,BitTreeNode *elem){
    LintStack *p = NULL;
    if(elem != NULL){
        p = (LintStack *)malloc(sizeof(LintStack));
        p->_NodeAddrCopy = elem;
        p->pNext = top;
        top = p;
    }
    return top;
}
LintStack *popLKStack(LintStack *top,BitTreeNode *pData){
    LintStack *p;
    if(top != NULL){
        pData = top->_NodeAddrCopy;
        p = top;
        top = p->pNext;
        free(p);
    }
    return top;
}

BitTree *Q[16];

BitTree *createBinTree(int arr[]){
    int i = 1;
    int front = 1,rear = 0;
    BitTree *root = NULL;
    BitTree *s;
    while(arr[i] != -999){
        s = NULL;
        if(arr[i] != 0){
            s = (BitTree *)malloc(sizeof(BitTree));
            s->data = arr[i];
            s->left = NULL;
            s->right = NULL;
        }
        Q[++rear] = s;
        if(rear == 1){
            root = s;
        }else{
            if(s != NULL && Q[front]){
                if(rear % 2 == 0){
                    Q[front]->left = s;
                }else{
                    Q[front]->right = s;
                }
            }
            if(rear % 2 == 1){
                front++;
            }
        }
        i++;
    }
    return root;
}

void NonRecrvPreOrder(BitTree *root){
    LintStack *pTop = NULL;
    BitTreeNode *pNode;
    pTop = InitStack();
    pNode = root;
    pTop = pushLKStack(pTop,pNode);
    while(!isEmptyLKMazeStack(pTop)){
        pNode = pTop->_NodeAddrCopy;
        pTop = popLKStack(pTop,pNode);
        if(pNode != NULL){
            pTop = pushLKStack(pTop,pNode->right);
            pTop = pushLKStack(pTop,pNode->left);
        }
    }
}
void NonRecvInorder(BitTree *root){
    LintStack *pTop = NULL;
    BitTreeNode TempNode;
    pTop = InitStack();
    BitTree *p = root;
    while(p != NULL || !isEmptyLKMazeStack(pTop)){
        while(p != NULL){
            pTop = pushLKStack(pTop,p);
            p = p->left;
        }
        if(!isEmptyLKMazeStack(pTop)){
            p = pTop->_NodeAddrCopy;
            pTop = popLKStack(pTop,&TempNode);
            p = p->right;
        }
    }
}

void NonRecvPostorder(BitTree *root){
    BitTree *cur;
    BitTree *pre = NULL;
    LintStack *pTop = NULL;
    BitTree TempNode;
    pTop = InitStack();
    pTop = pushLKStack(pTop,root);
    while(!isEmptyLKMazeStack(pTop)){
        cur = pTop->_NodeAddrCopy;
        if((cur->left == NULL && cur->right == NULL)||(pre != NULL && (pre = cur->left||pre == cur->right))){
            pTop = popLKStack(pTop,&TempNode);
            pre = cur;
        }else{
            if(cur->right != NULL){
                pTop = pushLKStack(pTop,cur->right);
            }
            if(cur->left != NULL){
                pTop = pushLKStack(pTop,cur->left);
            }
        }
    }
}


int leafCount = 0;
void LeafCount_DLR(BitTree *t){
    if(t){
        if(t->left == NULL && t->right == NULL){
            leafCount++;
        }
        LeafCount_DLR(t->left);
        LeafCount_DLR(t->right);
    }
}
int hight = 0;
int TreeDepth_DLR(BitTree *pNode, int level) {
	if (pNode) {
		level++;
		if (level > hight)
			hight = level;
		hight = TreeDepth_DLR(pNode->left, level);
		hight = TreeDepth_DLR(pNode->right, level);
	}
	return hight;
}
//这个比较难
BitTree* reConstructBinTree(int pre[], int startPre, int endPre,
	int in[], int startIn, int endIn) {
	if (startPre > endPre || startIn > endIn) {
		return NULL;
	}
	BitTree* pNode = (BitTree*)malloc(sizeof(BitTree));
	pNode->left = NULL;
	pNode->right = NULL;
	pNode->data = pre[startPre];
	for (int i = startIn;i <= endIn;i++) {
		if (in[i] == pre[startPre]) {
			pNode->left = reConstructBinTree(pre, startPre + 1, startPre + i - startIn, in, startIn, i - 1);
			pNode->right = reConstructBinTree(pre, i - startIn + startPre + 1, endPre, in, i + 1, endIn);
		}
	}
	return pNode;
}

BitTree* Paths[10] = { 0 };
void OutPutPath(){
	int i = 0;
	while (Paths[i] != NULL) {
		printf("%d ", Paths[i]->data);
		i++;
	}
	printf("\n");
}
void LeavesPath(BitTree *tree ,int level){
    if(tree == NULL){
        return;
    }
    Paths[level] = tree;
    if((tree->left == NULL)&&(tree->right == NULL)){
        Paths[level + 1] = NULL;
        OutPutPath();
        return;
    }
    LeavesPath(tree->left,level+1);
    LeavesPath(tree->right,level+1);
}
BOOL isEqualTree(BitTree *t1,BitTree *t2){
    if(t1 == NULL && t2 == NULL){
        return TRUE;
    }
    if(!t1||!t2){
        return FALSE;
    }
    if(t1->data == t2->data){
        return isEqualTree(t1->left,t2->left) && isEqualTree(t1->right, t2->right);
    }else{
        return FALSE;
    }
}