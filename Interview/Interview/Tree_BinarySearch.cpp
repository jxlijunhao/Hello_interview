/************************************************************************/
/* ���������                                                            */
/************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef int Type;

typedef struct BSTreeNode
{
	Type key;                 //�ؼ���
	struct BSTreeNode *left;
	struct BSTreeNode *right;
	struct BSTreeNode *parent;
}Node,*BSTree;

//�����ڵ�
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

//���룬�ǵݹ�,���ظ����,����������Ĳ�����������ĳһ·����һֱ��Ҷ�ӽ����в���
static Node* Insert_noInter(BSTree root,Type key)
{
	Node* temp=NULL;
	Node* p=root;
	//�ȴ���һ���ڵ�
	Node* z=createBSTree(key,NULL,NULL,NULL);

	//�ҵ�Ҫ�����λ��
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

//���룬�ݹ�,���ظ����,����������Ĳ�����������ĳһ·����һֱ��Ҷ�ӽ����в���
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





//ǰ�����
void preOrder(BSTree root)
{
	if (root!=NULL)
	{
		printf("%d ",root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}

//�������
void inOrder(BSTree root)
{
	if (root!=NULL)
	{
		inOrder(root->left);
		printf("%d ",root->key);		
		inOrder(root->right);
	}
}

//�������
void posOrder(BSTree root)
{
	if (root!=NULL)
	{
		posOrder(root->left);			
		posOrder(root->right);
		printf("%d ",root->key);	
	}
}

//���ң��ݹ�

Node* Search(BSTree root,Type key)
{
	if (root==NULL || root->key==key)
		return root;
	if (key<root->key)
		return Search(root->left,key);
	else
		return Search(root->right,key);
}

//���ң��ǵݹ�
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

//���ֵ
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

//��Сֵ
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



//ɾ�����
static Node* Delete(BSTree root,Type key)
{
	Node* temp=NULL;
	if (root==NULL)
		printf("Not Find\n");
	else if (key<root->key)
		root->left=Delete(root->left,key);//�������ݹ�ɾ��
	else if (key>root->key)
		root->right=Delete(root->right,key);//�������ݹ�ɾ��
	else //��ʾ�ҵ���Ҫɾ����Ԫ��
	{
		//�������������
		//1,��ɾ���Ľ�������������ӽ��,һ�ֲ���������������С��㣬��һ������
		//�����������
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

//���ٶ�����

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
//	//�����������ϲ���
//	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
//	{
//		printf("%d ",arr[i]);
//		root=Insert_noInter(root,arr[i]);
//	}
//
//	printf("\nǰ�����: ");
//	preOrder(root);
//
//	printf("\n�������: ");
//	inOrder(root);
//
//	printf("\n�������: ");
//	posOrder(root);
//	printf("\n");
//
//	printf("���ֵ:%d\n",FindMax(root)->key);
//
//    printf("��Сֵ:%d\n",FindMin(root)->key);
//
//	root=Delete(root,arr[2]);
//	return 0;
//}

