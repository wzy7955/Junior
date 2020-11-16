#include "Queue.h"

template<class T>
class ArrayQueue:public Queue<T>
{
	private:
		int maxSize;        			//��Ŷ�������Ĵ�С
		int front;           			//��ʾ��ͷ����λ�õ��±�
		int rear;              		//��ʾ��β����λ�õ��±�
		int *queue;                  	//�������ΪT�Ķ���Ԫ�ص�����

	public:
		ArrayQueue(int size)    		//�������е�ʵ��
		{
			maxSize = size + 1;    	//���һ���ռ䣬���ֶ��п�����
			queue = new T[maxSize];
			front = rear = 0;
		}

		~ArrayQueue()               	//��������
		{
			delete [] queue;
		}

		void Clear()              	//��ն���
		{
			front = rear;
		}

		bool EnQueue(const T item)	//item��ӣ������β
		{
			if((rear + 1) % maxSize == front)
			{
				cout << "�������������" << endl;
				return false;
			}
			queue[rear] = item;
			rear = (rear + 1) % maxSize;
			return true;
		}

		bool DeQueue(T & item)  	//���ض�ͷԪ�أ���ɾ����Ԫ��
		{
			if(front == rear)
			{
				cout << "����Ϊ��" << endl;
				return false;
			}
			item = queue[front];
			front = (front + 1) % maxSize;
			return true;
		}

		bool GetFront(T & item)  	//���ض�ͷԪ�أ�����ɾ��
		{
			if(front == rear)
			{
				cout << "����Ϊ��" << endl;
				return false;
			}
			item = queue[item];
			return true;
		}
};