/*
 ============================================================================
 Name        : 47_平衡二元樹的基本操作.c
 Author      : Binson
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int val;
	struct node *lchild,*rchild;
	int height
}node_t,*p_node_t;

p_node_t insert(p_node_t root,int val);
int search(p_node_t root,int val);
p_node_t rotation(p_node_t root);
void print(p_node_t root);
int getHeight(p_node_t root);

int main(void) {
	int i,j;
	int n,k;
	int val;
	p_node_t root = NULL;

	scanf("%d%d",&n,&k);

	for(i=0;i<n;i++)
	{
		scanf("%d",&val);
		root = insert(root,val);
		root = rotation(root);
	}
    /*printf("Tree : ");
    print(root);
    printf("\n");
    printf("Height : %d\n",getHeight(root));
*/
	for(i=0;i<k;i++)
	{
		if(i > 0)
			printf(" ");
		scanf("%d",&val);
		int iffind;
		iffind= search(root,val);
		printf("%d",iffind);
	}
	printf("\n");
	return EXIT_SUCCESS;
}

p_node_t insert(p_node_t root,int val){
	p_node_t newcode;
	newcode = (p_node_t)malloc(sizeof(node_t));
	newcode->val = val;
	newcode->lchild = NULL;
	newcode->rchild = NULL;
	if(root == NULL){
        return newcode;
	}
	p_node_t temp;
	temp = root;
	while(temp != NULL){
        if(val > temp->val && temp->rchild == NULL){
            temp->rchild = newcode;
            break;
        }
        else if(val <= temp->val && temp->lchild == NULL){
            temp->lchild = newcode;
            break;
        }
        else if(val > temp->val){
            temp = temp->rchild;
        }
        else if(val <= temp->val){
            temp = temp->lchild;
        }
	}
	return root;
}
int search(p_node_t root,int val){
    if(root == NULL)
        return 0;
    if(root->val == val)
        return 1;
	return search(root->lchild,val)+search(root->rchild,val);
}
p_node_t rotation(p_node_t root){
    if(root == NULL)
        return root;
    if(root->lchild)
        root->lchild = rotation(root->lchild);
    if(root->rchild)
        root->rchild = rotation(root->rchild);
    int lh,rh;
    lh = getHeight(root->lchild);
    rh = getHeight(root->rchild);
    p_node_t temp = root;
    if(lh-rh > 1){
        if(root->lchild->rchild && root->lchild->lchild){
            temp = root->lchild;
            root->lchild = temp->rchild;
            temp->rchild = root;
        }
        else if(root->lchild->lchild){
            // temp = 2,
            //    3
            //   2
            //  1
            temp = root->lchild;
            temp->rchild = root;
            root->lchild = NULL;
        }
        else if(root->lchild->rchild){
            // temp = 2,
            //    3
            //   1
            //    2
            temp = root->lchild->rchild;
            temp->lchild = root->lchild;
            temp->rchild = root;
            root->lchild = NULL;
            temp->lchild->rchild = NULL;
        }
    }
    else if(lh-rh < -1){
        if(root->rchild->rchild && root->rchild->lchild){
            temp = root->rchild;
            root->rchild = temp->lchild;
            temp->lchild = root;
        }
        else if(root->rchild->rchild){
            // temp = 2,
            //     1
            //      2
            //       3
            temp = root->rchild;
            temp->lchild = root;
            root->rchild = NULL;
        }
        else if(root->rchild->lchild){
            // temp = 2
            //     1
            //      3
            //     2
            temp = root->rchild->lchild;
            temp->rchild = root->rchild;
            temp->lchild = root;
            root->rchild = NULL;
            temp->rchild->lchild = NULL;
        }
    }
    return temp;
}
void print(p_node_t root){
    if(root!=NULL){
        print(root->lchild);
        printf("%d ",root->val);
        print(root->rchild);
    }
}

int getHeight(p_node_t root){
    if(root == NULL)
        return 0;
    int l=0,r=0;
    if(root->lchild)
        l = getHeight(root->lchild);
    if(root->rchild)
        r = getHeight(root->rchild);
    if(l>r)
        return l+1;
    else
        return r+1;
}







