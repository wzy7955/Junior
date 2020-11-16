#include "stack.h"
#include "LinkNode.h"

template<class T>
class LinkStack:public Stack<T>
{
	private:
		LinkNode <T> *top;           		//ָ��ջ����ָ��
		int size;                     		//���Ԫ�صĸ���

	public:
		LinkStack(int s)             		//���캯��
		{
			top = NULL;
			size = 0;
		}
		~LinkStack()               		//��������
		{
			Clear();
		}
		void Clear()                		//���ջ����
		{
			while(top != NULL)
			{
				LinkNode <T> *tmp = top;
				top = top->link;
				delete tmp;
			}
			size = 0;
		}
		bool Push(const T item)     		//��ջ��������ʽʵ��
		{
			LinkNode <T> *tmp = new LinkNode<T>(item, top);
			top = tmp;
			size++;
			return true;
		}
		bool Pop(T & item)           		//��ջ��������ʽʵ��
		{
			LinkNode<T> *tmp;
			if(size == 0)
			{
				cout << "ջΪ�գ�����ִ�г�ջ����" << endl;
				return false;
			}
			item = top->data;
			tmp = top->link;
			delete top;
			top = tmp;
			size--;
			return true;
		}
		bool Top(T & item)            //��ȡջ��Ԫ�أ�����ɾ��
		{
			if(size == 0)
			{
				cout << "ջΪ�գ����ܶ�ȡջ��Ԫ��" << endl;
				return false;
			}
			item = top->data;
			return true;
		}
};