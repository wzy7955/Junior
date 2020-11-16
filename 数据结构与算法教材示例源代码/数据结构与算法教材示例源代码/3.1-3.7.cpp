#include<iostream>
#include<stack>
#include<queue>
#include<string>
using namespace std;
template <class T>
class BinaryTreeNode{
	//friend class BinaryTree<T>;
private:
	T element;                      	//����������
	BinaryTreeNode<T> * leftChild;   	//�������ӽ��
	BinaryTreeNode<T> * rightChild;   	//�����Һ��ӽ��
public:
	BinaryTreeNode();              	//Ĭ�Ϲ��캯��
	BinaryTreeNode(const T& ele);	//�����������ֵ�Ĺ��캯��
	BinaryTreeNode(const T& ele, BinaryTreeNode<T> * l, BinaryTreeNode<T> * r);			//��������ֵ�����Һ��ӽ��Ĺ��캯��
	BinaryTreeNode<T> * getLeftChild() const;//���ظý������ӽ��
	BinaryTreeNode<T> * getRightChild() const;//���ظý����Һ��ӽ��
	void setLeftChild(BinaryTreeNode<T> * l);//���øý������ӽ��
	void setRightChild(BinaryTreeNode<T> * r);//���øý����Һ��ӽ��
	void createLeftChild();//�����ý������ӽ��
	void createRightChild();//�����ý����Һ��ӽ��
	T getValue() const;                           //���ظý�������ֵ
	void setValue(const T& val);                //���øý����������ֵ
	bool isLeaf() const;  //�жϸý���Ƿ���Ҷ�ӽ�㣬���ǣ��򷵻�true
};
template<class T>
BinaryTreeNode<T>::BinaryTreeNode()
{
    element = 0;
    leftChild = rightChild = NULL;
}
template<class T>
BinaryTreeNode<T>::BinaryTreeNode(const T& ele)
{
    element = ele;
    leftChild = rightChild = NULL;
}
template<class T>
BinaryTreeNode<T>::BinaryTreeNode(const T& ele, BinaryTreeNode<T> * l, BinaryTreeNode<T> * r)
{
    element = ele;
    leftChild = l;
    rightChild = r;
}
template<class T>
BinaryTreeNode<T> * BinaryTreeNode<T>::getLeftChild() const
{
    return leftChild;
}
template<class T>
BinaryTreeNode<T> * BinaryTreeNode<T>::getRightChild() const
{
    return rightChild;
}
template<class T>
void BinaryTreeNode<T>::setLeftChild(BinaryTreeNode<T> * l)
{
    leftChild = l;
}
template<class T>
void BinaryTreeNode<T>::setRightChild(BinaryTreeNode<T> * r)
{
    rightChild = r;
}
template<class T>
void BinaryTreeNode<T>::createLeftChild()
{
    leftChild = new BinaryTreeNode<T>;
}
template<class T>
void BinaryTreeNode<T>::createRightChild()
{
    rightChild = new BinaryTreeNode<T>;
}
template<class T>
T BinaryTreeNode<T>::getValue() const
{
    return element;
}
template<class T>
void BinaryTreeNode<T>::setValue(const T& val)
{
    element = val;
}
template<class T>
bool BinaryTreeNode<T>::isLeaf() const
{
    if(leftChild == NULL && rightChild == NULL)
        return true;
    else
        return false;
}
template <class T>
class BinaryTree{
private:
	BinaryTreeNode<T> * root;				//�����������
public:
	BinaryTree();              				//Ĭ�Ϲ��캯��
	~BinaryTree();                  		//��������
	bool isEmpty() const;           		//�ж϶������Ƿ�Ϊ����
	BinaryTreeNode<T> * getRoot() const;	//���ض������ĸ����
	BinaryTreeNode<T> * getParent(BinaryTreeNode<T> * current) const;
                                              		//����current���ĸ����
	BinaryTreeNode<T> * getLeftSibling(BinaryTreeNode<T> * current) const;
	                                          	//����current�������ֵ�
	BinaryTreeNode<T> * getRightSibling(BinaryTreeNode<T> * current) const;
	                                          	//����current�������ֵ�
	void levelOrder(BinaryTreeNode<T> * root);
	                               		//������ȱ�����rootΪ����������
	void preOrder(BinaryTreeNode<T> * root);
									//���������rootΪ����������
    void PreOrderWithoutRecusion(BinaryTreeNode<T> * root);
                                    //�ǵݹ����������rootΪ����������
	void inOrder(BinaryTreeNode<T> * root);
									//���������rootΪ����������
    void InOrderWithoutRecusion(BinaryTreeNode<T> * root);
                                    //�ǵݹ����������rootΪ����������
	void postOrder(BinaryTreeNode<T> * root);
									//���������rootΪ����������
    void PostOrderWithoutRecusion(BinaryTreeNode<T> * root);
                                    //�ǵݹ���������rootΪ����������
	void deleteBinaryTree(BinaryTreeNode<T> * root);
	                    				//ɾ����rootΪ����������
    void visit(BinaryTreeNode<T> *t);   //���ʵ�ǰ�ڵ�
    void create1(string m,string n);    //��������������������
    void preincreatetree(BinaryTreeNode<T> *t,string pre,string in);
                                        //��������򴴽�������
    void create2(string m,string n);    //����������ĺ��������
    void inpostcreatetree(BinaryTreeNode<T> *t,string in,string post);
                                        //��������򴴽�������
};
template <class T>
BinaryTree<T>::BinaryTree()
{
    root = NULL;
}
template <class T>
BinaryTree<T>::~BinaryTree()
{
    deleteBinaryTree(root);
}
template <class T>
bool BinaryTree<T>::isEmpty() const
{
    if(root == NULL)
        return true;
    else
        return false;
}
template <class T>
BinaryTreeNode<T> * BinaryTree<T>::getRoot() const
{
    return root;
}
template <class T>
void BinaryTree<T>::levelOrder(BinaryTreeNode<T> * root)
{
    queue<BinaryTreeNode<T> *> nodeQueue;//�ö�������Ž�Ҫ���ʵĽ��
	BinaryTreeNode<T> * pointer = root;

	if(pointer)                          //��������ǿգ���������������
		nodeQueue.push(pointer);
	while(!nodeQueue.empty())
	{
		pointer = nodeQueue.front(); 	//��ȡ���׽��
		visit(pointer);	                 	//���ʵ�ǰ���
		nodeQueue.pop();               	//�����ʹ��Ľ���Ƴ�����
		if(pointer->getLeftChild())
			nodeQueue.push(pointer->getLeftChild());
		if(pointer->getRightChild())
			nodeQueue.push(pointer->getRightChild());
		                       	//�����ʹ��Ľ������Һ��ӽ�����μ��뵽��β
	}
}
template <class T>
void BinaryTree<T>::preOrder(BinaryTreeNode<T> * root)
{
    if(root != NULL)
	{
		visit(root);			         	//���ʵ�ǰ���
		preOrder(root->getLeftChild());			//����������
		preOrder(root->getRightChild());	   		//����������
	}
}
template <class T>
void BinaryTree<T>::PreOrderWithoutRecusion(BinaryTreeNode<T> * root)
{
    stack<BinaryTreeNode<T> * > nodeStack;   	//��Ŵ����ʵĽ���ջ
  	BinaryTreeNode<T> * pointer = root;      	//��������

	while(!nodeStack.empty() || pointer)	 	//ջΪ��ʱ��������
	{
		if(pointer)
        {
		  	  visit(pointer);		          	//���ʵ�ǰ���
			  if(pointer->getRightChild() != NULL)
					nodeStack.push(pointer->getRightChild());
			                           	//��ǰ���ʽ����������ĸ������ջ
			  pointer = pointer->getLeftChild();		//ת�������������
		}
		else
		{	        			 	//������������ϣ�ת�����������
			  pointer = nodeStack.top();		//��ȡջ�������ʵĽ��
			  nodeStack.pop();                  	//ɾ��ջ�����
		}
	}
}
template <class T>
void BinaryTree<T>::inOrder(BinaryTreeNode<T> * root)
{
    if(root != NULL)
	{
		inOrder(root->getLeftChild());			//����������
		visit(root);			         	//���ʵ�ǰ���
		inOrder(root->getRightChild());	    	//����������
	}
}
template <class T>
void BinaryTree<T>::InOrderWithoutRecusion(BinaryTreeNode<T> * root)
{
    stack<BinaryTreeNode<T> * > nodeStack; 		//�洢�����ʽ��
  	BinaryTreeNode<T> * pointer = root;		  	//��������

	while(!nodeStack.empty() || pointer)     	//ջΪ��ʱ��������
	{
		if(pointer)
        {
			  nodeStack.push(pointer);			//��ǰ�����ջ
			  pointer = pointer->getLeftChild();   	//ת�����������
		}
		else
        {        					//������������ϣ�ת�����������
			  pointer = nodeStack.top();		//��ȡջ�������ʵĽ��
		  	  visit(pointer);		       		//���ʵ�ǰ���
			  pointer = pointer->getRightChild();  	//ת�����Һ���
			  nodeStack.pop();				  	//ɾ��ջ�����
		}
	}
}
template <class T>
void BinaryTree<T>::postOrder(BinaryTreeNode<T> * root)
{
    if(root != NULL)
	{
		postOrder(root->getLeftChild());	    	//����������
		postOrder(root->getRightChild());		//����������
		visit(root);	                    //���ʵ�ǰ���
	}
}
template <class T>
void BinaryTree<T>::PostOrderWithoutRecusion(BinaryTreeNode<T> * root)
{
    stack<BinaryTreeNode<T> * > nodeStack;	//�洢�����ʽ��
  	BinaryTreeNode<T> * pointer = root;		//��������
	BinaryTreeNode<T> * pre = root;         //����ǰһ�������ʵĽ��

	while(pointer)
    {
		for( ; pointer->getLeftChild() != NULL; pointer = pointer->getLeftChild())
			nodeStack.push(pointer);     	//��������

		while(pointer != NULL && (pointer->getRightChild() == NULL || pointer->getRightChild() == pre))
        {
			        //��ǰ���û���Һ��ӻ����Һ��Ӹձ����ʹ�,����ʸý��
			visit(pointer);
			pre = pointer;            		//��¼�ձ����ʹ��Ľ��
			if(nodeStack.empty())
				return;
			pointer = nodeStack.top();   	//ȡջ�����
			nodeStack.pop();
		}
		nodeStack.push(pointer);
		pointer = pointer->getRightChild();  	//ת��ǰ����������
	}
}
template <class T>
void BinaryTree<T>::deleteBinaryTree(BinaryTreeNode<T> * root)
{
    if(root!=NULL)
    {
        deleteBinaryTree(root->getLeftChild());
        deleteBinaryTree(root->getRightChild());
        delete root;
    }
}
template <class T>
void BinaryTree<T>::visit(BinaryTreeNode<T> *t)
{
    cout<<t->getValue();
}
template <class T>
void BinaryTree<T>::create1(string m,string n)
{
    root = new BinaryTreeNode<T>;
    preincreatetree(root,m,n);
}
template <class T>
void BinaryTree<T>::preincreatetree(BinaryTreeNode<T> *t,string pre,string in)
{
    if(pre.length() == 0)
    {
        t = NULL;
        return;
    }
    char tvalue = pre[0];
    int index = in.find(tvalue);                              //�����������е�λ��
    string leftchild_in = in.substr(0,index);                 //���ӵ���������
    string rightchild_in = in.substr(index+1);                //�Һ��ӵ���������
    int leftchild_length = leftchild_in.length();             //���ӵĳ���
    int rightchild_length = rightchild_in.length();           //�Һ��ӵĳ���
    string leftchild_pre = pre.substr(1,leftchild_length);    //���ӵ�ǰ������
    string rightchild_pre = pre.substr(leftchild_length+1);   //�Һ��ӵ�ǰ������
    if(leftchild_length == 0 && rightchild_length == 0)
    {
        t->setValue(tvalue);
    }
    else if(leftchild_length > 0 && rightchild_length == 0)
    {
        t->setValue(tvalue);
        t->createLeftChild();
        preincreatetree(t->getLeftChild(),leftchild_pre,leftchild_in);        //�ݹ鴴������
    }
    else if(leftchild_length == 0 && rightchild_length > 0)
    {
        t->setValue(tvalue);
        t->createRightChild();
        preincreatetree(t->getRightChild(),rightchild_pre,rightchild_in);     //�ݹ鴴���Һ���
    }
    else if(leftchild_length > 0 && rightchild_length > 0)
    {
        t->setValue(tvalue);
        t->createLeftChild();
        t->createRightChild();
        preincreatetree(t->getLeftChild(),leftchild_pre,leftchild_in);        //�ݹ鴴������
        preincreatetree(t->getRightChild(),rightchild_pre,rightchild_in);     //�ݹ鴴���Һ���
    }
}
template <class T>
void BinaryTree<T>::create2(string m,string n)
{
    root = new BinaryTreeNode<T>;
    inpostcreatetree(root,m,n);
}
template <class T>
void BinaryTree<T>::inpostcreatetree(BinaryTreeNode<T> *t,string in,string post)
{
    if(post.length() == 0)
    {
        t = NULL;
        return;
    }
    char tvalue=post[post.length()-1];
    int index=in.find(tvalue);                                                //�����������е�λ��
    string leftchild_in=in.substr(0,index);                                   //���ӵ���������
    string rightchild_in=in.substr(index+1);                                  //�Һ��ӵ���������
    int leftchild_length=leftchild_in.length();                               //���ӵĳ���
    int rightchild_length=rightchild_in.length();                             //�Һ��ӵĳ���
    string leftchild_post=post.substr(0,leftchild_length);                    //���ӵĺ�������
    string rightchild_post=post.substr(leftchild_length,rightchild_length);   //�Һ��ӵĺ�������
    if(leftchild_length == 0 && rightchild_length == 0)
    {
        t->setValue(tvalue);
    }
    else if(leftchild_length > 0 && rightchild_length == 0)
    {
        t->setValue(tvalue);
        t->createLeftChild();
        inpostcreatetree(t->getLeftChild(),leftchild_in,leftchild_post);           //�ݹ鴴������
    }
    else if(leftchild_length == 0 && rightchild_length > 0)
    {
        t->setValue(tvalue);
        t->createRightChild();
        inpostcreatetree(t->getRightChild(),rightchild_in,rightchild_post);        //�ݹ鴴���Һ���
    }
    else if(leftchild_length > 0 && rightchild_length > 0)
    {
        t->setValue(tvalue);
        t->createLeftChild();
        t->createRightChild();
        inpostcreatetree(t->getLeftChild(),leftchild_in,leftchild_post);        //�ݹ鴴������
        inpostcreatetree(t->getRightChild(),rightchild_in,rightchild_post);     //�ݹ鴴���Һ���
    }
}
int main()
{
    BinaryTree<char> tree;
    string m,n;
    cout<<"������ǰ�����У�"<<endl;
    cin>>m;//ABDFGCEH
    cout<<"�������������У�"<<endl;
    cin>>n;//BFDGACEH
    tree.create1(m,n);
    /*cout<<"�������������У�"<<endl;
    cin>>m;
    cout<<"������������У�"<<endl;
    cin>>n;//FGDBHECA
    tree.create2(m,n);*/
    cout<<"�ö�����������ȱ�������Ϊ��"<<endl;//ABCDEFGH
    tree.levelOrder(tree.getRoot());
    cout<<"\n�ö������ݹ�ǰ���������Ϊ��"<<endl;
    tree.preOrder(tree.getRoot());
    cout<<"\n�ö������ǵݹ�ǰ���������Ϊ��"<<endl;
    tree.PreOrderWithoutRecusion(tree.getRoot());
    cout<<"\n�ö������ݹ������������Ϊ��"<<endl;
    tree.inOrder(tree.getRoot());
    cout<<"\n�ö������ǵݹ������������Ϊ��"<<endl;
    tree.InOrderWithoutRecusion(tree.getRoot());
    cout<<"\n�ö������ݹ�����������Ϊ��"<<endl;
    tree.postOrder(tree.getRoot());
    cout<<"\n�ö������ǵݹ�����������Ϊ��"<<endl;
    tree.PostOrderWithoutRecusion(tree.getRoot());
    return 0;
}
