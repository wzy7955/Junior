#include <iostream>
using namespace std;
//6.9
template<class T>
void SelectionSort(T Data[], int n)
{
	for (int i = 1; i < n; i++)      	//������n-1��ѡ��
	{//��i��ʱ�Ĵ�������ΪData[i-1],��,Data[n-1]
		int k = i - 1;             		//��¼��ǰ�������еĵ�һ��Ԫ��
		for (int j = i; j < n; j++)	//�ҵ�������������СԪ�ص��±�
		{
			if (Data[j] < Data[k])
				k = j;
		}
		if (k != i - 1)		//������СԪ�ص���ǰ�������еĵ�һ��λ��
		{
			T t = Data[k];
			Data[k] = Data[i - 1];
			Data[i - 1] = t;
		}
	}
}
//6.10
template<class T>
void SiftDown(T Data[], int i, int n)
{//���������Խ��iΪ�������ѵ����ʣ�n������Ԫ�صĸ���
	int l = 2 * i + 1, r = 2 * i + 2, min = i;//�ҵ�i�����������ӵ��±�
	if (l < n && Data[min] < Data[l])	   //�����ӽ����бȽ�
		min = l;
	if (r < n && Data[min] < Data[r])	   //�����ӽ����бȽ�
		min = r;
	if (min != i)						   //�ж��Ƿ���Ҫ���е���
	{
		T t = Data[min];
		Data[min] = Data[i];
		Data[i] = t;
		SiftDown(Data, min, n);			   //�ݹ���ӽ����е���
	}
}
template<class T>
void BuildHeap(T Data[], int n)
{
	int p = n / 2 - 1;				//�����Ҷ�ӽ�������±�
	for (int i = p; i >= 0; i--)
	{
		SiftDown(Data, i, n);		//����SiftDown�������������ѵ�����
	}
}
template<class T>
void MaxHeap(T Data[], int m, int n) 
{//����ȡ�����Ԫ�غ�Ķ�
	for (int i = n / 2 - 1; i >= m; i--)
		SiftDown(Data, i, n);
}
template<class T>
void HeapSort(T Data[], int n)
{
	BuildHeap(Data, n);				//���Ƚ���һ������
	for (int i = n - 1; i > 0; i--)	//����ѭ��
	{
		T t = Data[0];				//ÿ��ȡ�����Ԫ�غ󲻶ϵ�������
		Data[0] = Data[i];
		Data[i] = t;
		MaxHeap(Data, 0, i);
	}
}
//6.11
template<class T>
void Merge(T Data[], int start, int mid, int end)
{
	int len1 = mid - start + 1, len2 = end - mid;//�ֱ��ʾ�����鲢����ĳ���
	int i, j, k;
	T *left = new int[len1];   //��ʱ�����������Data[start,mid]����
	T *right = new int[len2];   //��ʱ�����������Data[mid+1,end]
	for (i = 0; i < len1; i++)   //ִ�����ݸ��Ʋ���
	{
		left[i] = Data[i + start];
	}
	for (i = 0; i < len2; i++)    //ִ�����ݸ��Ʋ���
	{
		right[i] = Data[i + mid + 1];
	}
	i = 0, j = 0;
	for (k = start; k<end; k++)   //ִ�й鲢
	{
		if (i == len1 || j == len2)
		{
			break;
		}
		if (left[i] <= right[j])
		{
			Data[k] = left[i++];
		}
		else
		{
			Data[k] = right[j++];
		}
	}
	while (i < len1)     //��Data[start,mid]���д��鲢���ݣ���ŵ�Data����
	{
		Data[k++] = left[i++];
	}
	while (j < len2)      //��Data[mid+1,end]�������ִ��ͬ���Ĳ���
	{
		Data[k++] = right[j++];
	}
	delete[] left;    //�ͷ��ڴ�
	delete[] right;
}
//6.12
template<class T>
void MergeSort(T Data[], int start, int end)
{//��Data[start]-Data[end]֮������н��й鲢����
	if (start < end)
	{
		T mid = (start + end) / 2;   	//�����м�λ��
		MergeSort(Data, start, mid);    	//����������й鲢����
		MergeSort(Data, mid + 1, end);    	//���ұ������й鲢����
		Merge(Data, start, mid, end);  	//�鲢�������ߵ���������
	}
}
//6.13
const int RADIX = 10;					//����������������ֲ�ͬ����
template<class T>
struct LinkNode {						//������ʽ�ṹ�Ľ��
	T data;
	LinkNode* next;
};
template<class T>
struct TubNode {							//�������������
	LinkNode<T>*rear;
	LinkNode<T>*front;
};
/*
�������
���룺Data[]�������飬n Ԫ�ظ���, ith��i�η������
�����ִ�з������֮���һ���������顣
*/
template<class T>
TubNode<T>* Distribute(T Data[], int n, int ith)
{
	//�����ڴ�
	TubNode<T>* tube = new TubNode<T>[RADIX];
	//ִ�г�ʼ��
	memset(tube, 0, sizeof(TubNode<T>)*RADIX);
	LinkNode<T>* t;
	for (int i = 0; i<n; i++)
	{
		T v = Data[i];
		int j = ith - 1;
		while (j--)					//���i��λ�ϵ�����
			v = v / RADIX;
		v = v % RADIX;
		t = new LinkNode<T>;		//�����µ�������
		t->data = Data[i];
		t->next = NULL;
		if (tube[v].front)			//�����Ӧ�Ķ��в�Ϊ�գ���ŵ�ĩβ
		{
			tube[v].rear->next = t;
			tube[v].rear = t;
		}
		else						//���򣬳�ʼ������ͷ��β
		{
			tube[v].front = tube[v].rear = t;
		}

	}
	return tube;
}
/*
�ռ���������tube�������ռ���Data������
���룺Data�������飬tubeִ����������֮��Ķ�������
�������
*/
template<class T>
void Collect(T Data[], TubNode<T>* tube)
{
	LinkNode<T>*t, *p;				//��ʱ����
	int index = 0;					//�����±�
	for (int i = 0; i<RADIX; i++)
	{
		p = t = tube[i].front;
		while (t)
		{
			Data[index++] = t->data;//���ƶ�Ӧ����
			t = t->next;
			delete p;				//�ͷ��ڴ�
			p = t;
		}
	}
	delete[] tube;					//�ͷ��ڴ�
}

/*
�������򣬶�Data[]�����ݽ������򣬲���������뵽Data[]��
���룺Data[]���ݣ�nԪ�ظ�����keys�ؼ��ָ���
�������
*/
template<class T>
void RadixSort(T Data[], int n, int keys)//��������
{
	TubNode<T>* tube;
	for (int i = 0; i<keys; i++)			//ѭ��ִ��keys�η�����ռ�����
	{
		tube = Distribute<T>(Data, n, i + 1);
		Collect<T>(Data, tube);
	}
}
int main()
{
	int a[10] = { 0,2,3,5,6,7,1,9,8,4 };

	SelectionSort(a, 10);
	HeapSort(a, 10);
	MergeSort(a, 0, 9);
	RadixSort(a, 10, 1);
	for (int i = 0; i < 10;i++)
		cout << a[i];

	system("pause");
	return 0;
}