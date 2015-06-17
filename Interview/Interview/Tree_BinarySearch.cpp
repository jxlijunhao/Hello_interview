/************************************************************************/
/* 二叉查找树                                                            */
/************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef int Type;

typedef struct BSTreeNode
{
	Type key;                 //关键字
	struct BSTreeNode *left;
	struct BSTreeNode *right;
	struct BSTreeNode *parent;
}Node,*BSTree;

//创建节点
static Node* createBSTree(Type key,Node* parent,Node* left,Node* right)
{
	Node* p;
	if ((p=(Node*)malloc(sizeof(Node)))==NULL)
		return NULL;

	p->key=key;
	p->left=left;
	p->right=right;
	p->parent=parent;
	return p;
}

//插入，非递归,返回根结点,二叉查找树的插入总是沿着某一路径，一直到叶子结点进行插入
static Node* Insert_noInter(BSTree root,Type key)
{
	Node* temp=NULL;
	Node* p=root;
	//先创建一个节点
	Node* z=createBSTree(key,NULL,NULL,NULL);

	//找到要插入的位置
	while (p!=NULL)
	{
		temp=p;
		if (z->key<p->key)
			p=p->left;
		else
			p=p->right;
	}
	z->parent=temp;
	if (temp==NULL)
		root=z;
	else if (z->key<temp->key)
		temp->left=z;
	else
		temp->right=z;
	return root;
}

//插入，递归,返回根结点,二叉查找树的插入总是沿着某一路径，一直到叶子结点进行插入
static Node* Insert_Inter(BSTree root,Type key)
{
	Node* z=createBSTree(key,NULL,NULL,NULL);
	if (root==NULL)
	{
		root=z;		
	}
	else if (key<root->key)
		root->left=Insert_Inter(root->left,key);
	else
		root->right=Insert_Inter(root->right,key);
	return root;	 
}





//前序遍历
void preOrder(BSTree root)
{
	if (root!=NULL)
	{
		printf("%d ",root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}

//中序遍历
void inOrder(BSTree root)
{
	if (root!=NULL)
	{
		inOrder(root->left);
		printf("%d ",root->key);		
		inOrder(root->right);
	}
}

//后序遍历
void posOrder(BSTree root)
{
	if (root!=NULL)
	{
		posOrder(root->left);			
		posOrder(root->right);
		printf("%d ",root->key);	
	}
}

//查找，递归

Node* Search(BSTree root,Type key)
{
	if (root==NULL || root->key==key)
		return root;
	if (key<root->key)
		return Search(root->left,key);
	else
		return Search(root->right,key);
}

//查找，非递归
Node* Search_nonIter(BSTree root,Type key)
{
	if (root==NULL || root->key==key)
		return root;

	BSTree p=root;
	while ((p!=NULL) && (p->key!=key))
	{
		if (key<p->key)
			p=p->left;
		else
			p=p->right;	
	}
	return p;
}

//最大值
Node* FindMax(BSTree root)
{
	if (root==NULL)
		return root;
	while (root->right!=NULL)
	{
		root=root->right;
	}
	return root;
}

//最小值
Node* FindMin(BSTree root)
{
	if (root==NULL)
		return root;
	while (root->left!=NULL)
	{
		root=root->left;
	}
	return root;
}



//删除结点
static Node* Delete(BSTree root,Type key)
{
	Node* temp=NULL;
	if (root==NULL)
		printf("Not Find\n");
	else if (key<root->key)
		root->left=Delete(root->left,key);//左子树递归删除
	else if (key>root->key)
		root->right=Delete(root->right,key);//右子树递归删除
	else //表示找到了要删除的元素
	{
		//分三种情况考虑
		//1,被删除的结点有左右两个子结点,一种策略是找右子树最小结点，另一种是找
		//左子树最大结点
		if (root->left!=NULL && root->right!=NULL)
		{
			temp=FindMin(root->right);
			root->key=temp->key;
			root->right=Delete(root->right,temp->key);
		}else 
		{
			temp=root;
			if (root->left!=NULL)
				root=root->right;
			else if (root->right!=NULL)
				root=root->left;
			free(temp);
		}
	}
	return root;
}

//销毁二叉树

void Destroy(BSTree root)
{
	if ( root == NULL)
		return ;
	if ( root->left != NULL )
		Destroy( root->left );
	if ( root->right!= NULL )
		Destroy( root->right);
	free(root);
}

//int main()
//{
//	int arr[]={3,1,5,2,4,6};
//	BSTree root=NULL;
//
//	//构建树，不断插入
//	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
//	{
//		printf("%d ",arr[i]);
//		root=Insert_noInter(root,arr[i]);
//	}
//
//	printf("\n前序遍历: ");
//	preOrder(root);
//
//	printf("\n中序遍历: ");
//	inOrder(root);
//
//	printf("\n后序遍历: ");
//	posOrder(root);
//	printf("\n");
//
//	printf("最大值:%d\n",FindMax(root)->key);
//
//    printf("最小值:%d\n",FindMin(root)->key);
//
//	root=Delete(root,arr[2]);
//	return 0;
//}

