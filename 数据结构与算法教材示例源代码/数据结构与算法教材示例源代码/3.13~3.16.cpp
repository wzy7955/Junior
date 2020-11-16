#include<iostream>
using namespace std;

template <class T>
class BinarySearchTreeNode
{
public:
	T element;                          //����������
	BinarySearchTreeNode<T> * leftChild;   	//�������ӽ��
	BinarySearchTreeNode<T> * rightChild;   	//�����Һ��ӽ��

	BinarySearchTreeNode()              	//Ĭ�Ϲ��캯��
	{

	}
	BinarySearchTreeNode(const T& ele)	//�����������ֵ�Ĺ��캯��
	{
		element = ele;
	}
	BinarySearchTreeNode(const T& ele, BinarySearchTreeNode<T> * l, BinarySearchTreeNode<T> * r)	//��������ֵ�����Һ��ӽ��Ĺ��캯��
	{
		element = ele;
		leftChild = l;
		rightChild = r;
	}
	//BinarySearchTreeNode<T> * getLeftChild() const;//���ظý������ӽ��

	//BinarySearchTreeNode<T> * getRightChild() const;//���ظý����Һ��ӽ��

	void setLeftChild(BinarySearchTreeNode<T> * l)//���øý������ӽ��
	{
		leftChild = l;
	}
	void setRightChild(BinarySearchTreeNode<T> * r)//���øý����Һ��ӽ��
	{
		rightChild = r;
	}
	T getValue() const                           //���ظý�������ֵ
	{
		return element;
	}
	void setValue(const T& val)                //���øý����������ֵ
	{
		element = val;
	}
	//bool isLeaf() const;  //�жϸý���Ƿ���Ҷ�ӽ�㣬���ǣ��򷵻�true

};


template <class T>
class BinarySearchTree
{
public:
	BinarySearchTreeNode<T> * root;				//�����������

	BinarySearchTree(BinarySearchTreeNode<T> * r)              				//Ĭ�Ϲ��캯��
	{
		root = r;
	}
	~BinarySearchTree()                  			//��������
	{

	}
	/*bool isEmpty() const;           			//�ж϶������Ƿ�Ϊ����
	BinarySearchTreeNode<T> * getRoot() const;	//���ض������ĸ����
	BinarySearchTreeNode<T> * getParent(BinarySearchTreeNode<T> * current) const;
	//����current���ĸ����
	BinarySearchTreeNode<T> * getLeftSibling(BinarySearchTreeNode<T> * current) const;
	//����current�������ֵ�
	BinarySearchTreeNode<T> * getRightSibling(BinarySearchTreeNode<T> * current) const;
	//����current�������ֵ�
	void breadthFirstOrder(BinarySearchTreeNode<T> * root);
	//������ȱ�����rootΪ����������
	void preOrder(BinarySearchTreeNode<T> * root);
	//���������rootΪ����������
	void inOrder(BinarySearchTreeNode<T> * root);
	//���������rootΪ����������
	void postOrder(BinarySearchTreeNode<T> * root);
	//���������rootΪ����������
	void levelOrder(BinarySearchTreeNode<T> * root);
	//����α�����rootΪ����������
	void deleteBinaryTree(BinarySearchTreeNode<T> * root);
	//ɾ����rootΪ����������*/
	BinarySearchTreeNode<T>* search(BinarySearchTreeNode<T>* root, T key);
	//�����������Ĳ���
	void insertNode(const T& value);
	//������������в�����
	void deleteByMerging(BinarySearchTreeNode<T>* node);
	//�ϲ�ɾ��
	void deleteByCopying(BinarySearchTreeNode<T>* node);
	//����ɾ��
};







//����3.13�������������Ĳ��ҡ�

template<class T>
BinarySearchTreeNode<T>* BinarySearchTree<T>::search(BinarySearchTreeNode<T>* root, T key)
{
	BinarySearchTreeNode<T>* current = root;
	while ((NULL != root) && (key != current->element))
		//��ǰ����keyֵ���ڲ�ѯ��ֵʱ���˳�ѭ��
	{
		current = (key < current->element ? search(current->leftChild, key) : search(current->rightChild, key));
		//���ݵ�ǰ����ֵ�Ĵ�С�����ƶ�����
	}
	return current;
}

//����3.14��������������в����㡣

template<class T>
void BinarySearchTree<T>::insertNode(const T& value) 
{
	BinarySearchTreeNode<T> *p = root, *prev = NULL;
	while (p != 0)
	{                                  		//�½�����λ��
		prev = p;                      	//��¼�����
		if (p->getValue() < value)
			p = p->rightChild;
		else
			p = p->leftChild;
	}
	if (root == NULL)               		//����ǿ��������½����Ϊ�����
		root = new BinarySearchTreeNode<T>(value);
	else if (prev->getValue() < value)
		//���ݹؼ����������Ϊ���ӽ�㻹�����ӽ��
		prev->rightChild = new BinarySearchTreeNode<T>(value);
	else
		prev->leftChild = new BinarySearchTreeNode<T>(value);
}


//����3.15���ϲ�ɾ�����㷨ʵ�֡�

template<class T>

void BinarySearchTree<T>::deleteByMerging(BinarySearchTreeNode<T>* node)
{
	BinarySearchTreeNode<T> *tmp = node;
	if (node != NULL)
	{
		//�����ɾ�����û���������������������ĸ���������汻ɾ�����
		if (!node->rightChild)
			node = node->leftChild;
		//�����ɾ�����û���������������������ĸ���������汻ɾ�����
		else if (node->leftChild == NULL)
			node = node->rightChild;
		else {                      	//�����ɾ�������������������
			tmp = node->leftChild;
			while (tmp->rightChild != NULL)
				//�����������а�������������һ�����
				tmp = tmp->rightChild;
			//�����ҵ��Ľ�����ָ�븳ֵΪ��ɾ�������������ĸ�
			tmp->rightChild = node->rightChild;
			tmp = node;
			node = node->leftChild; //���������ĸ������汻ɾ�����
		}
		//delete tmp;
	}
}

//����3.16������ɾ���㷨ʵ�֡�

template<class T>
void BinarySearchTree<T>::deleteByCopying(BinarySearchTreeNode<T>* node)
{
	BinarySearchTreeNode<T>* previous, *tmp = node;
	//�����ɾ�����û���������������������ĸ���������汻ɾ�����
	if (node->rightChild == NULL)
		node = node->leftChild;
	//�����ɾ�����û���������������������ĸ���������汻ɾ�����
	else if (node->leftChild == NULL)
		node = node->rightChild;
	else    								//�����ɾ�������������������
	{
		tmp = node->leftChild;
		previous = node;
		while (tmp->rightChild != NULL)	//�����������йؼ������Ľ��
		{
			previous = tmp;
			tmp = tmp->rightChild;
		}
		node->element = tmp->element;	//�����ҵ��Ľ���ֵ��ֵ����ɾ�����
		if (previous == node)
			previous->leftChild = tmp->leftChild;
		else
			previous->rightChild = tmp->leftChild;
	}
	//delete tmp;
}


int main()
{
	//����������������ͼ3-22������
	BinarySearchTreeNode<int> N1(400, NULL, NULL);
	BinarySearchTreeNode<int> N2(122, NULL, NULL);
	BinarySearchTreeNode<int> N3(450, NULL, NULL);
	BinarySearchTreeNode<int> N4(99, NULL, NULL);
	BinarySearchTreeNode<int> N5(250, NULL, NULL);
	BinarySearchTreeNode<int> N6(500, NULL, NULL);
	BinarySearchTreeNode<int> N7(110, NULL, NULL);
	BinarySearchTreeNode<int> N8(200, NULL, NULL);
	BinarySearchTreeNode<int> N9(300, NULL, NULL);
	BinarySearchTreeNode<int> N10(105, NULL, NULL);
	BinarySearchTreeNode<int> N11(330, NULL, NULL);
	N1.setLeftChild(&N2);
	N1.setRightChild(&N3);
	N2.setLeftChild(&N4);
	N2.setRightChild(&N5);
	N3.setLeftChild(NULL);
	N3.setRightChild(&N6);
	N4.setLeftChild(NULL);
	N4.setRightChild(&N7);
	N5.setLeftChild(&N8);
	N5.setRightChild(&N9);
	N6.setLeftChild(NULL);
	N6.setRightChild(NULL);
	N7.setLeftChild(&N10);
	N7.setRightChild(NULL);
	N8.setLeftChild(NULL);
	N8.setRightChild(NULL);
	N9.setLeftChild(NULL);
	N9.setRightChild(&N11);
	N10.setLeftChild(NULL);
	N10.setRightChild(NULL);
	N11.setLeftChild(NULL);
	N11.setRightChild(NULL);
	BinarySearchTree<int> R(&N1);
	//����elementΪ200�Ľ��
	//BinarySearchTreeNode<int>* P=R.search(&N1, 200);
	//cout << P->element << endl;
	//��KeyֵΪ120�Ľ����뵽����
	//R.insertNode(120);
	//cout << N7.rightChild->element << endl;
	//�ϲ�ɾ��N2
	//R.deleteByMerging(&N2);
	//����ɾ��N2
	R.deleteByCopying(&N2);
	system("pause");
	return 0;
}