#include <iostream>

using namespace std;


template<class T>
void PrintArray(T Data[],int n){
    for(int i=0;i!=n;i++){
        cout<<Data[i]<<",";
    }
    cout<<'\b'<<endl;
}

template<class T>
void InsertionSort(T Data[],int n)
{//����ֱ�Ӳ����������n������Ԫ�ؽ��в���������
	int p,i;
	for( p = 1; p < n; p++)	//ѭ����p��ʾ����������������n-1�˲���
	{
		T temp = Data[p];	//�Ѵ�����Ԫ�ظ���temp
		i = p - 1;
		while( i>= 0 && Data[i] > temp)	//�ѱ�temp���Ԫ�ض�����ƶ�
		{
			Data[i+1] = Data[i];
			i--;
		}
		Data[i+1] = temp;	//i+1Ϊtemp��λ�ã���temp���뵽���λ��
		PrintArray(Data,n);
	}
}

template<class T>
void BinaryInsertionSort(T Data[],int n)	//���������������ݺʹ�����Ԫ													//�ظ���
{
	int left,mid,right,p;				//����һЩ����
	for( p = 1; p < n; p++)				//������n-1�β���
	{
		T temp = Data[p];				//�������������
		left = 0,right = p-1;			  //��ʼ��left��right��ֵ
		while(left <= right)			  //ִ���۰����
			{
			mid = (left + right) / 2;	  //������ĵ�
			if( Data[mid] > temp ) 		  //���ĵ�Ԫ��ֵ�ȴ��������ݴ�
				right = mid -1;			  //����������ֵ
			else
				left = mid + 1;			  //����������ֵ
		}
		for( int i = p-1; i >= left; i--)//ִ���ƶ�����
			Data[i+1] = Data[i];
		Data[left] = temp;				 //��������Ԫ�ز��뵽�������
	}
}


template<class T>
void ShellSort(T Data[],int n)
{
	int d = n/2;						//������ʼ��Ϊ�����С��һ��
	while(d>=1)							//ѭ���������������п���
	{
		for(int k = 0; k<d; k++)		//�������е�������
		{
			for( int i = k+d; i < n; i+=d)	//��ÿһ��������ִ��ֱ�Ӳ�													//������
			{
				T temp = Data[i];
				int j = i - d;
				while( j>= k && Data[j] > temp)
				{
					Data[j+d] = Data[j];
					j -= d;
				}
				Data[j+d] = temp;
			}
		}
		d = d/2;						//������Ϊ�ϴε�һ��
	}
}

template<typename T>
void BubbleSort(T Data[],int n)
{
	for(int i = 0; i < n; i++)			//���ѭ�����������ÿһ��
	{
		for(int j = 1; j < n-i; j++)	//�ڲ�ѭ�����Ʊ����е�ð�ݲ���
		{
			if(Data[j] < Data[j-1])		//���������ģ��򽻻�������Ԫ��
			{
				T t = Data[j];
				Data[j] = Data[j-1];
				Data[j-1] = t;
			}
		}
	}
}

template<class T>
void BubbleSort1(T Data[],int n)
{
	int  flag = 0;               //���ÿһ�˵�ð������������Ƿ����˽���
	for(int i = 0; i < n; i++)			//���ѭ�����������ÿһ��
	{   flag = 0;
		for(int j = 1; j < n-i; j++)	//�ڲ�ѭ�����Ʊ����е�ð�ݲ���
		{
			if(Data[j] < Data[j-1])		//���������ģ��򽻻�������Ԫ��
			{   flag = 1;
				T t = Data[j];
				Data[j] = Data[j-1];
				Data[j-1] = t;
			}
		}
		if (flag == 0)   //���ĳһ�˵�ð�ݹ�����û�з����������������
			return;
	}
}


���������������м��������ķ��ŵ��µĴ���û���б�ע
template <class T>
int Partition2(T Data[],int start, int fin)
{//ʵ�ֶ�data[start]��data[fin]�ķָ�����������ػ��ֺ���Ԫ�ض�Ӧ��λ��
	T pivot = Data[start];
	int left =start, right = fin; 		//��ʼ��left,right
    while(left<=right)					//���ѭ�����Ʊ�������
	{
		while(left<= right && Data[left] <= pivot)//����leftָ����ƶ�
			left++;
		while(left<=right && Data[right] >pivot)	//����rightָ���ƶ�
			right--;
		if(left<right)
        {
            swap(Data[right],Data[left]);//����Data[right]��Data[left]
            left ++; right--;
        }
	}
    swap(Data[start] ,Data[right]);	//����Data[right]����Ԫ��Data[start]
    cout<<"Part2"<<endl;
	return right;				//������Ԫ�ص���λ�ã�ʵ�ַ���
}

template <class T>
int Partition1(T Data[],int left, int right)
{//ʵ�ֶ�data[left]��data[right]�ķָ�����������ػ��ֺ���Ԫ�ض�Ӧ��λ��
	T pivot = Data[left];			//ѡ������ߵ�Ϊ��Ԫ��
	while(left < right)				//���ѭ�����Ʊ�������
	{
		while(left< right && Data[right] > pivot)//����rightָ����ƶ�
			right--;
		Data[left] = Data[right];	//��rightָ��������ƶ���leftλ��
		while(left < right && Data[left] <= pivot)//����leftָ���ƶ�
			left++;
		Data[right] = Data[left];	//��leftָ��������ƶ���rightλ��
	}
	Data[left] = pivot;				//����Ԫ�طŵ�leftλ��
	cout<<"Part1"<<endl;
	return left;					//������Ԫ�ص���λ�ã�ʵ�ַ���
}

template <class T>
void QuickSort(T Data[],int left,int right)
{//�÷��η�ʵ�ֿ��������㷨
	if(left < right)						//���Ʒ��εĽ�������
	{
		int p = Partition1(Data,left,right);	//ʵ�ַָ�ҵ������λ��
		QuickSort(Data,left,p-1);		//����ߵ������н��п�������
		QuickSort(Data,p+1,right);		//���ұߵ������н��п�������
	}
	cout<<"Quick"<<endl;
}

int main()
{
    int Data[]={32,18,65,48,27,9};
    int Data1[]={65,34,25,87,12,38,56,46,14,77,92,23};
    QuickSort<int>(Data1,0,11);
    PrintArray<int>(Data1,12);
    return 0;
}
