#include "stack.h"

template<class T>
class ArrayStack:public Stack<T>
{
	private:
		int maxSize;          		//ջ�����ֵ
		int top;              		//ջ��λ��
		T *st;               			//���ջԪ�ص�����

	public:
		ArrayStack(int size)		//����һ���������ȵ�˳��ջʵ��
		{
			maxSize = size;
			top = -1;
			st = new T[maxSize];
		}

		ArrayStack()          		//����һ��˳��ջʵ��
		{
			top = -1;
		}

		~ArrayStack()         		//��������
		{
			delete [] st;
		}

		void Clear()          		//���ջ������
		{
			top = -1;
		}

		bool Push(const T item)		//��ջ����
		{
			if(top == maxSize - 1)	//ջ����
			{
				cout << "ջ�����" << endl;
				return false;
			}
			else                		//��ջ�����޸�ջ��ָ��
			{
				st[++top] = item;
				return true;
			}      
		}

		
/* �Ľ��Ľ�ջ����
template<class T>             
bool ArrayStack<T>::push(const T item)
{
	if(top == maxSize - 1)
	{
		T * newSt = new T [maxSize * 2];
		for(int i = 0; i <= top; i++)
		{
			newSt[i] = st[i];
		}
		delete [] st;     //�ͷ�ԭջ
		st = newSt;
		maxSize *= 2;
	}
	st[++top] = item;
	return true;
}
*/

		bool Pop(T & item)     		//��ջ����
		{
			if(top == -1)      		//ջΪ��
			{
				cout << "ջΪ�գ����ܽ���ɾ������" << endl;
				return false;
			}
			else
			{
				item = st[top--];	//��ȡջ��Ԫ�ز��޸�ջ��ָ��
				return true;
			}
		}

		bool Top(T & item)      		//��ȡջ��Ԫ�أ�����ɾ��
		{
			if(top == -1)        	//ջΪ��
			{
				cout << "ջΪ�գ����ܶ�ȡջ��Ԫ��" << endl;
				return false;
			}
			else
			{
				item = st[top];
				return true;
			}
		}
};