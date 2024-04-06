#include"BTNode.h"
#include"Queue.h"

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (*pi >= n || a[*pi] == '*')
	{
		return;
	}
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->_data = a[(*pi)++];
	root->_left = BinaryTreeCreate(a, n, pi);
	root->_right = BinaryTreeCreate(a, n, pi);
	return root;
}
// 二叉树销毁
void BinaryTreeDestory(BTNode** root)
{
	if ((*root) == NULL)
	{
		return;
	}
	BinaryTreeDestory(&(*root)->_left);
	BinaryTreeDestory(&(*root)->_right);
	free(*root);
	*root = NULL;
}
// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int leftlength = BinaryTreeLeafSize(root->_left);
	int rightlength = BinaryTreeLeafSize(root->_right);
	return rightlength > leftlength ? rightlength + 1 : leftlength + 1;
}
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1) ;
}
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->_data == x)
	{
		return root;
	}
	BTNode* ret = BinaryTreeFind(root->_left, x);
	if (ret != NULL)
	{
		return ret;
	}
	return BinaryTreeFind(root->_right, x);
}
// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeInOrder(root->_left);
	printf("%d ", root->_data);
	BinaryTreeInOrder(root->_right);
}
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%d ", root->_data);
}
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue Q;
	QueueInit(&Q);
	if (root != NULL)
	{
		QueuePush(&Q, root);
	}
	while (!QueueEmpty(&Q))
	{
		BTNode* front = QueueFront(&Q);
		QueuePop(&Q);
		printf("%d ", front->_data);
		if (front->_left != NULL)

		{
			QueuePush(&Q, front->_left);
		}
		if (front->_right != NULL)
		{
			QueuePush(&Q, front->_right);
		}
	}
	QueueDestory(&Q);
}
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root)
{
	Queue Q;
	QueueInit(&Q);
	bool Juge = false;//标记第一个遇到的空
	if (root != NULL)
	{
		QueuePush(&Q, root);

	}
	while (!QueueEmpty(&Q))
	{
		BTNode* front = QueueFront(&Q);
		QueuePop(&Q);

		if (front == NULL)
		{
			Juge = true;
			continue;//如果每次进来都是空节点，则会跳过本次循环
		}

		if (Juge)//若没有跳过本次循环，说明遇到了非空节点则返回false
		{
			return false;

		}
		QueuePush(&Q, front->_left);

		QueuePush(&Q, front->_right);

	}
	return true;
	QueueDestory(&Q);
}