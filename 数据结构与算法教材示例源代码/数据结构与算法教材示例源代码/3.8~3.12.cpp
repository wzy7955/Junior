#include<iostream>
using namespace std;
//����3.8�������������Ľ���ࡣ

template <class T>
class ThreadBinaryTreeNode
{
public:
	int leftTag, rightTag;                  	//���ұ�־λ
	ThreadBinaryTreeNode<T> * leftChild;   	//ǰ����������
	ThreadBinaryTreeNode<T> * rightChild;  	//��̻�������
	T element;                                  	//���������

	ThreadBinaryTreeNode() {}
	ThreadBinaryTreeNode(const T& ele)
	{
		element = ele;
	}//���캯��
	ThreadBinaryTreeNode(const T& ele, ThreadBinaryTreeNode<T> * l, ThreadBinaryTreeNode<T> * r)
	{
		element = ele;
		leftChild = l;
		rightChild = r;
	}
	ThreadBinaryTreeNode(const T& ele, ThreadBinaryTreeNode<T> * l, ThreadBinaryTreeNode<T> * r, int lt, int rt)
	{
		element = ele;
		leftChild = l;
		rightChild = r;
		leftTag = lt;
		rightTag = rt;
	}
	void getLeftChild() const
	{
		if (leftChild)
		{
			cout << leftChild->element << endl;
		}
		else
		{
			cout << "NULL" << endl;
		}
	}
	void getRightChild() const
	{
		if (rightChild)
		{
			cout << rightChild->element << endl;
		}
		else
		{
			cout << "NULL" << endl;
		}
	}
	void setLeftChild(ThreadBinaryTreeNode<T> * l)
	{
		leftChild = l;
	}
	void setRightChild(ThreadBinaryTreeNode<T> * r)
	{
		rightChild = r;
	}
	void getValue() const
	{
		cout << element << endl;
	}//���ظý�������ֵ
	void setValue(const T& val)
	{
		element = val;
	}//���øý����������ֵ
};


//����3.9�������������ࡣ

template <class T>
class ThreadBinaryTree
{
public:
	ThreadBinaryTreeNode<T> * root;     		//�����ָ��

	ThreadBinaryTree()
	{

	}                        	//���캯��
	ThreadBinaryTree(ThreadBinaryTreeNode<T> * r)
	{
		root = r;
	}
	~ThreadBinaryTree()
	{

	}//��������
	void InsertNode(ThreadBinaryTreeNode<T>* pointer, ThreadBinaryTreeNode<T>* newPointer);//���������������Ĳ������
	ThreadBinaryTreeNode<T> * getRoot();   		//���ظ����ָ��
	void InThread(ThreadBinaryTreeNode<T> * root, ThreadBinaryTreeNode<T> * &pre);//����������������
	void InOrder(ThreadBinaryTreeNode<T> * root);	//�������
};

//����3.10��������������������

template <class T>
void ThreadBinaryTree<T>::InThread(ThreadBinaryTreeNode<T>* root, ThreadBinaryTreeNode<T>* &pre)//pre��ʼֵΪNULL
{
	ThreadBinaryTreeNode<T>* current;//preΪ��ǰ���ʽ���ǰһ�����
	current = root;                          	//currentΪ��ǰ���ʽ��
	if (current != NULL)
	{
		InThread(current->leftChild, pre);	//����������������
		if (current->leftChild == NULL)
		{
			current->leftChild = pre;
			current->leftTag = 1;     		//����ǰ������
		}
		if ((pre) && (pre->rightChild == NULL))
		{
			pre->rightChild = current;
			pre->rightTag = 1;              	//�����������
		}
		pre = current;
		InThread(current->rightChild, pre);	//����������������
	}
}


//����3.11���������������������

template<class T>
void ThreadBinaryTree<T>::InOrder(ThreadBinaryTreeNode<T>* root)
{
	ThreadBinaryTreeNode<T>* current;
	current = root;

	while (current->leftTag == 0)
		current = current->leftChild;    	//Ѱ����������ĵ�һ�����
	while (current)
	{
		current->getValue();                  		//���ʵ�ǰ���
		if (current->rightTag == 1)
		{
			current = current->rightChild;	//������Ѱ�Һ��
		}
		else
		{
			current = current->rightChild;
			while (current && current->leftTag == 0)
				current = current->leftChild; 	//Ѱ�������ն˽��
		}
	}
}


//����3.12�����������������Ĳ��������

template<class T>
void ThreadBinaryTree<T>::InsertNode(ThreadBinaryTreeNode<T>* pointer, ThreadBinaryTreeNode<T>* newPointer)
{
	if (pointer->rightTag == 1) //pointer���Һ���
	{
		newPointer->rightChild = pointer->rightChild;
		//pointer�ĺ�̱�ΪnewPointer�ĺ��
		newPointer->rightTag = 1;
		pointer->rightChild = newPointer;	//newPointer��Ϊpointer���Һ���
		pointer->rightTag = 0;
		newPointer->leftChild = pointer;	//pointer��ΪnewPointer��ǰ��
		newPointer->leftTag = 1;
	}
	else //pointer���Һ���
	{
		ThreadBinaryTreeNode<T>* s = pointer->rightChild;
		while (s->leftTag == 0)
			s = s->leftChild;	//����p������������"�����¶�"���
		newPointer->rightChild = pointer->rightChild;
		//pointer���Һ��ӱ�ΪnewPointer���Һ���
		newPointer->rightTag = 0;
		newPointer->leftChild = pointer;	//pointer��ΪnewPointer��ǰ��
		newPointer->leftTag = 1;
		pointer->rightChild = newPointer;	//newPointer��Ϊpointer���Һ���
		s->leftChild = newPointer;
		//newPointer��Ϊpointerԭ����������"�����¶�"����ǰ��
	}
}



int main()
{//���������������ϵ�����
	ThreadBinaryTreeNode<char> A('A', NULL, NULL, 0, 0);
	ThreadBinaryTreeNode<char> B('B', NULL, NULL, 0, 0);
	ThreadBinaryTreeNode<char> C('C', NULL, NULL, 0, 0);
	ThreadBinaryTreeNode<char> D('D', NULL, NULL, 0, 0);
	ThreadBinaryTreeNode<char> E('E', NULL, NULL, 0, 0);
	ThreadBinaryTreeNode<char> F('F', NULL, NULL, 0, 0);
	ThreadBinaryTreeNode<char> G('G', NULL, NULL, 0, 0);
	ThreadBinaryTreeNode<char> H('H', NULL, NULL, 0, 0);
	A.setLeftChild(&B);
	A.setRightChild(&C);
	B.setLeftChild(NULL);
	B.setRightChild(&D);
	C.setLeftChild(NULL);
	C.setRightChild(&E);
	D.setLeftChild(&F);
	D.setRightChild(&G);
	E.setLeftChild(NULL);
	E.setRightChild(&H);
	F.setLeftChild(NULL);
	F.setRightChild(NULL);
	G.setLeftChild(NULL);
	G.setRightChild(NULL);
	H.setLeftChild(NULL);
	H.setRightChild(NULL);
	ThreadBinaryTree<char> R(&A);
	ThreadBinaryTreeNode<char> *prev = NULL;
	R.InThread(&A, prev);//����������
	R.InOrder(&A);//�������
	ThreadBinaryTreeNode<char> I('I', NULL, NULL, 0, 0);//�������㣬������Ϊ������newPointer�����뵽pointer�����Ҳࡣ
	R.InsertNode(&B,&I);//��I���뵽B���Ҳ�
	R.InOrder(&A);//�������
	system("pause");
	return 0;
}