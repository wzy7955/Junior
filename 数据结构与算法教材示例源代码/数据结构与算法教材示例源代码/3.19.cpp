#include <iostream>
#include<stdlib.h>
using namespace std;

template <class T>
class MinHeap
{
private:
	T* heapArray;               		//��Ŷ����ݵ�����
	int CurrentSize;             		//��ǰ����Ԫ����Ŀ
	int MaxSize;                		//���������ɵ����Ԫ����Ŀ
public:
	MinHeap(T* array, int num, int max) {
		this->heapArray = new T[num];
		for (int i = 0; i<num; i++) {
			this->heapArray[i] = array[i];
		}

		this->CurrentSize = num;
		this->MaxSize = max;
	}
	virtual ~MinHeap() {};    		//��������
	void BuildHeap();
	bool isLeaf(int pos) const;		//�����Ҷ��㣬����TRUE
	int leftchild(int pos) const;	//��������λ��
	int rightchild(int pos) const;	//�����Һ���λ��
	bool Remove(int pos, T& node);	//ɾ�������±��Ԫ��
	void SiftDown(int left);//ɸѡ������������left��ʾ��ʼ����������±�
	void SiftUp(int position);	//��position���Ͽ�ʼ������ʹ���г�Ϊ��
	bool Insert(const T& newNode);	//����в�����Ԫ��newNode
	void MoveMin();                  	//�ӶѶ��ƶ���Сֵ��β��
	T& RemoveMin();                  	//�ӶѶ�ɾ����Сֵ
	T* getMinHeap();
	int getCurrSize();
};

template<class T>
void MinHeap<T>::BuildHeap()
{
	for (int i = CurrentSize / 2 - 1; i >= 0; i--)
		SiftDown(i);
}

template<class T>
T* MinHeap<T>::getMinHeap()
{
	return heapArray;
}

template<class T>
int MinHeap<T>::getCurrSize()
{
	return CurrentSize;
}

template<class T>
T& MinHeap<T>::RemoveMin()
{                                     		//ɾ���Ѷ�Ԫ��
	if (CurrentSize == 0)
	{
		//�ն����
		cout << "Can't Delete";
		exit(1);
	}
	else
	{
		T temp = heapArray[0];       		//ȡ�Ѷ�Ԫ��
		heapArray[0] = heapArray[CurrentSize - 1];//����βԪ���������Ѷ�
		CurrentSize--;	              	//����Ԫ��������1
		if (CurrentSize > 1)    			//����Ԫ�ظ�������1ʱ����Ҫ����
											//�ӶѶ���ʼɸѡ
			SiftDown(0);
		cout << temp << ' ';
		return temp;
	}
}

template<class T>
void MinHeap<T>::SiftDown(int left)
{
	//׼��
	int i = left;            			//��ʶ�����
	int j = 2 * i + 1;           		//��ʶ���ӽ��
	T temp = heapArray[i];     		//���游���Ĺؼ���
									//��ɸ
	while (j < CurrentSize)
	{
		if ((j < CurrentSize - 1) && (heapArray[j] > heapArray[j + 1]))
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

int main()
{

	int a[10] = { 15,2,7,17,5,30,13,12,9,18 };

	MinHeap<int> mh1(a, 10, 20);

	mh1.BuildHeap();
	int *b = mh1.getMinHeap();
	cout << "��С�ѵĹ��������";
	for (int i = 0; i<10; i++) {
		cout << b[i] << ' ';
	}
	cout << endl;
	cout << "���ȶ��еĳ��ӽ����";
	while (mh1.getCurrSize()>0)
	{
		mh1.RemoveMin();
	}

	return 0;
}
