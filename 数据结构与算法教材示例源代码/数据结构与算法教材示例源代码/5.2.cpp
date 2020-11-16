#include <iostream>

using namespace std;

template <class T>
int BiSearch(T Array[], T key, int n)
{ //�۰���ҹ��̣�Array[0,��,n-1]Ϊ�����ҵ��������ݼ�¼��keyΪ���ҵļ�¼
	int left = 0;          	//������ҷ�Χ�����
	int right = n-1;       	//������ҷ�Χ���Ҷˣ�n��ʾ����ĳ���
	int mid;                	//������ҷ�Χ���м��
	while (left <= right)
	{//������ҷ�Χ��Ч������в��ң������������
		mid = (left + right)/2;
		if (key < Array[mid])
		{ //�����ҷ�Χ��С���м�Ԫ�ص����
			right = mid - 1;
		}
		else if (key > Array[mid])
		{//�����ҷ�Χ��С���м�Ԫ�ص��ұ�
			left = mid + 1;
		}
		else
			return mid;    		//���ҳɹ������ظ�Ԫ������λ��
	}
	return -1;            		//���Ҳ��ɹ�������-1
}



int main()
{
    int A[]={1,2,3,6,7,45};
    int m=BiSearch(A,2,6);

    cout << "���ҵ�������"<<m<<"��"<< endl;
    return 0;
}
