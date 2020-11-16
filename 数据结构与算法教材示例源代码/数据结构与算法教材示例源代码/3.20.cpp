#include <iostream>
#include<stdlib.h>
using namespace std;

template <class T>
class HuffmanTreeNode {
	//friend class HuffmanTree<T>;
	
	
public:
	T element;                      	//����������
	HuffmanTreeNode<T>* leftChild;   	//�������ӽ��
	HuffmanTreeNode<T>* rightChild;   	//�����Һ��ӽ��
	HuffmanTreeNode<T>* parent;
	HuffmanTreeNode() {
		leftChild = NULL;
		rightChild = NULL;
		parent = NULL;
	}//Ĭ�Ϲ��캯��
	HuffmanTreeNode(T ele, HuffmanTreeNode<T> * l = NULL, HuffmanTreeNode<T> * r = NULL, HuffmanTreeNode<T> * p = NULL){
		element = ele;
		leftChild = l;
		rightChild = r;
		parent = p;
	}			//��������ֵ�����Һ��ӽ��Ĺ��캯��
	bool operator <=(HuffmanTreeNode<T> &r) {
         return element <= r.element;

	}
     bool operator <(HuffmanTreeNode<T> &r) {
         return element<r.element;

	}
     bool operator >=(HuffmanTreeNode<T> &r) {
         return element >= r.element;

	}
     bool operator >(HuffmanTreeNode<T> &r) {
         return element>r.element;

	}

};

template <class T>
class MinHeap
{
private:
	T* heapArray;               		//��Ŷ����ݵ�����
	int CurrentSize;             		//��ǰ����Ԫ����Ŀ
	//int MaxSize;                		//���������ɵ����Ԫ����Ŀ
public:
	MinHeap(int num)
	{
		this->heapArray = new T[num];
		this->CurrentSize = 0;
	}
	virtual ~MinHeap(){
		delete[]heapArray;
	}	//��������
	void SiftUp(int position)	//��position���Ͽ�ʼ������ʹ���г�Ϊ��
	{
		//׼��
		int i = position;           //��ʶ������½��
		int j = (i - 1) / 2;   //��ʶ�����
		T temp = heapArray[i];     	//�����½��Ĺؼ���
									//��ɸ
		while (i > 0)
		{
			if (*temp < *heapArray[j])
			{                             //�ý��Ĺؼ�����ڸ�����ֵʱ
				heapArray[i] = heapArray[j];	//������Ӧֵ
				i = j;
				j = (i - 1) / 2;              //���ϼ����ж��Ƿ��������ѵ�����
			}
			else break;
		}
		heapArray[i] = temp;
	}

	void SiftDown(int left,int m)//ɸѡ������������left��ʾ��ʼ����������±�
	{
		//׼��
		int i = left;            			//��ʶ�����
		int j = 2 * i + 1;           		//��ʶ���ӽ��
		T temp = heapArray[i];     		//���游���Ĺؼ���
										//��ɸ
		while (j <= m)
		{
			if ((j < m) && (heapArray[j] > heapArray[j + 1]))
				j++;
			//�ý�����Һ������Һ��ӵĹؼ���С�����ӵĹؼ���ʱ��jָ�����ӽ��
			if (temp>heapArray[j])
			{                       //�ý��Ĺؼ���������Һ����бȽ�С���Ǹ�ʱ
				heapArray[i] = heapArray[j];	//������Ӧֵ
				i = j;
				j = 2 * j + 1;                 //���¼����ж��Ƿ��������ѵ�����
			}
			else break;
		}
		heapArray[i] = temp;
	}
	
	bool Insert(const T& newNode)	//����в�����Ԫ��newNode
	{	
		heapArray[CurrentSize] = newNode;
		SiftUp(CurrentSize);
		CurrentSize++;
		return true;
	}
	bool RemoveMin(T& x)                  	//�ӶѶ�ɾ��
	{
		if (!CurrentSize)
			return false;
		x = heapArray[0];
		heapArray[0] = heapArray[CurrentSize - 1];
		CurrentSize--;
		SiftDown(0,CurrentSize-1);
		return true;
	}
	T* getMinHeap() {
		return heapArray;
	}
	int getCurrSize()
	{
		return CurrentSize;
	}
};

template <class T>
class HuffmanTree
{
private:
	HuffmanTreeNode<T>* root;                               //Huffman��������
public:	
	HuffmanTree(T weight[], int n);                         //����Huffman����weight��Ȩֵ�����飬n�����鳤��
	~HuffmanTree() { DeleteTree(root); }	        //��������
	HuffmanTreeNode<T> * getRoot() {
		return root;
	}//����Huffman���ĸ����
	void preOrder(HuffmanTreeNode<T> *root);                //���������rootΪ����������
	void inOrder(HuffmanTreeNode<T> *root);                 //���������rootΪ����������
	//void visit(HuffmanTreeNode<T> *t);
	void MergeTree(HuffmanTreeNode<T> *ht1, HuffmanTreeNode<T> *ht2, HuffmanTreeNode<T>* parent);//��ht1��ht2Ϊ����Huffman�����ϲ���һ����parentΪ���Ķ�����
	void DeleteTree(HuffmanTreeNode<T>* root);              //ɾ��Huffman����������

};


template<class T>
	HuffmanTree<T>::HuffmanTree(T weight[], int n)
	{
		MinHeap <HuffmanTreeNode<T>*> heap(n);  		//������С��
		HuffmanTreeNode<T>* parent, *firstchild, *secondchild,*temp;
		//HuffmanTreeNode<T>* NodeList = new HuffmanTreeNode<T>[n];
		
		for (int i = 0; i<n; i++)
		{
			temp = new HuffmanTreeNode<T>(weight[i]);
			heap.Insert(temp);
		}
		for (int i = 0; i < n - 1; i++)			//ͨ��n-1�κϲ�����Huffman��
		{
			parent = new HuffmanTreeNode<T>;
			firstchild = new HuffmanTreeNode<T>;
			secondchild = new HuffmanTreeNode<T>;
			heap.RemoveMin(firstchild);       	//ѡ��Ȩֵ��С�Ľ��
            heap.RemoveMin(secondchild);
			MergeTree(firstchild, secondchild, parent);//�ϲ�Ȩֵ��С��������
			heap.Insert(parent);              	//��parent���뵽����ȥ
			root = parent;                       	//���������
		}
	}

template<class T>
	void HuffmanTree<T>::MergeTree(HuffmanTreeNode<T> *ht1, HuffmanTreeNode<T> *ht2,HuffmanTreeNode<T>* parent)
	{
		parent->element = ht1->element + ht2->element;
		parent->leftChild = ht1;
		parent->rightChild = ht2;
		ht1->parent = parent;
		ht2->parent = parent;
	}

	template<class T>
	void HuffmanTree<T>::DeleteTree(HuffmanTreeNode<T>* root)
	{
		if (root == NULL)return;
		DeleteTree(root->leftChild);
		DeleteTree(root->rightChild);
		delete root;
	}

	template <class T>
	void HuffmanTree<T>::preOrder(HuffmanTreeNode<T> *root)                 //ǰ�����
	{
		if (root != NULL)
		{
			cout<<root->element<<" ";			         	//���ʵ�ǰ���
			preOrder(root->leftChild);			//����������
			preOrder(root->rightChild);	   		//����������
		}
	}


	template <class T>
	void HuffmanTree<T>::inOrder(HuffmanTreeNode<T> *root)                  //�������
	{
		if (root != NULL)
		{
			inOrder(root->leftChild);			//����������
			cout << root->element << " ";			//���ʵ�ǰ���
			inOrder(root->rightChild);	    	//����������
		}
	}

	int main()
	{

		int a[4] = { 7,5,2,4 };

		HuffmanTree<int> ht1(a,4);

		cout << "�ù��������ݹ�ǰ���������Ϊ��" << endl;
		ht1.preOrder(ht1.getRoot());

		cout << "�ù��������ݹ������������Ϊ��" << endl;
		ht1.inOrder(ht1.getRoot());

		system("pause");
		return 0;
	}
