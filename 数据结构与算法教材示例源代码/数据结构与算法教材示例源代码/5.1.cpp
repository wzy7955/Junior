#include <iostream>

using namespace std;

template <class T>
//˳����ҹ��̣�Array[]Ϊ�����ҵ����ݼ�¼���ϣ�nΪ���ϵļ�¼������keyΪҪ���ҵ����ݼ�¼
int Search(T Array[], T key,int n)
{
	for (int index = 0; index < n; index ++)
	{//��������ʼλ�ñ������飬n��ʾ���鳤��
		if( Array[index] == key)//�������Ԫ�ص��ڴ����ҹؼ���
		{
			return index;      	//���ҳɹ������ظ�����Ԫ�����ڵ�λ��
		}
	}
	return -1;                   	//���Ҳ��ɹ�������-1
}


int main()
{
    int A[]={1,2,3,45,6,7};
    int m=Search(A,8,6);

    cout << "���ҵ�������"<<m<<"��"<< endl;
    return 0;
}
