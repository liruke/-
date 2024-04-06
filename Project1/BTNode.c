#include"BTNode.h"
#include"Queue.h"

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
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
// ����������
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
// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}
// ������Ҷ�ӽڵ����
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
// ��������k��ڵ����
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
// ����������ֵΪx�Ľڵ�
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
// ������ǰ����� 
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
// �������������
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
// �������������
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
// �������
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
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root)
{
	Queue Q;
	QueueInit(&Q);
	bool Juge = false;//��ǵ�һ�������Ŀ�
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
			continue;//���ÿ�ν������ǿսڵ㣬�����������ѭ��
		}

		if (Juge)//��û����������ѭ����˵�������˷ǿսڵ��򷵻�false
		{
			return false;

		}
		QueuePush(&Q, front->_left);

		QueuePush(&Q, front->_right);

	}
	return true;
	QueueDestory(&Q);
}