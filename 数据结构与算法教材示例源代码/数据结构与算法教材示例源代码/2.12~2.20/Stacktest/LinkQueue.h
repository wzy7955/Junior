#include "Queue.h"
#include "LinkNode.h"

template<class T>
class LinkQueue:public Queue<T>
{
private:
	int size;              		//�����е�ǰԪ�صĸ���
	LinkNode<T> * front;       	//��ʾ���е�ͷָ��
	LinkNode<T> * rear;         	//��ʾ���е�βָ��

public:
	LinkQueue(int size)        	//���캯�����������е�ʵ��
	{
		size = 0;
		front = rear = NULL;
	}

	~LinkQueue()               	//��������
	{
		Clear();
	}

	void Clear()             		//��ն���
	{
		while(front != NULL)
		{
			rear = front;
			front = front->link;
			delete rear;
		}
		rear = NULL;
		size = 0;
	}

	bool EnQueue(const T item)	//item��ӣ������β
	{
		if(rear == NULL)
		{
			front = rear = new LinkNode<T>(item, NULL);
		}
		else
		{
			rear->link = new LinkNode<T>(item, NULL);
			rear = rear->link;
		}
		size++;
		return true;
	}

	bool DeQueue(T & item) 		//��ȡ��ͷԪ�ز�ɾ��
	{
		LinkNode<T> * temp;
		if(size == 0)
		{
			cout << "����Ϊ��" << endl;
			return false;
		}
		item = front->data;
		temp = front;
		front = front->link;
		delete temp;
		if(front == NULL)
		{
			rear = NULL;
		}
		size--;
		return true;
	}

	bool GetFront(T & item) 		//���ض�ͷԪ�أ�����ɾ��
	{
		if(size == 0)
		{
			cout << "����Ϊ��" << endl;
			return false;
		}
		item = front->data;
		return true;
	}
};
