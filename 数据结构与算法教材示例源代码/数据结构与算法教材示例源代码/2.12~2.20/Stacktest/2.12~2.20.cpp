//�޸ĺ�Ĵ���																									

/*����2.12��ջ���ඨ�塣

template<class T>
class Stack
{
	public:
		void Clear();              	//���ջ
		bool Push(const T item);	//ջ��ѹ�����
		bool Pop(T & item);        	//��ȡջ��Ԫ�ص�ֵ��ɾ��
		bool Top(T & item);        	//��ȡջ��Ԫ�ص�ֵ����ɾ��
		bool IsEmpty();            	//�ж�ջ�Ƿ�Ϊ��
		bool IsFull();              	//�ж�ջ�Ƿ�����
}; 

����2.13��ջ��˳��ʵ�֡�

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
			if(top == maxSize - 1)	//ջ����       //�޸�//
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

		bool Pop(T & item)     		//��ջ����
		{
			if(top == -1)      		//ջΪ��
			{
				cout << "ջΪ�գ����ܽ���ɾ������" << endl;     //�޸�//
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

/*
����2.14���Ľ��Ľ�ջ������

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

����2.15��ջ����ʽʵ�֡�

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

����2.16���׳˺�����

long factorial(long n)
{
	if(n <= 0)
		return 1;
	return n * factorial(n-1);
}


����2.17���׳˺���������

#include<iostream>
using namespace std;
int main()
{
	cout << factorial(4) << endl;
	return 0;
}


����2.18�����еĳ����������Ͷ��塣

template<class T>
class Queue
{
public:
	void Clear();                		//��ն���
	bool EnQueue(const T item); 	//���е�β������Ԫ��item
	bool DeQueue(T & item);     		//ȡ�����еĵ�һ��Ԫ�أ���ɾ��
	bool IsEmpty();             		//�ж϶����Ƿ�Ϊ��
	bool IsFull();              		//�ж϶����Ƿ�����
	bool GetFront(T & item);     	//��ȡ��ͷԪ�أ�����ɾ��
};


����2.19�����е�˳��ʵ�֡�

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

����2.20�����е���ʽʵ�֡�

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
			rear->link = new LinkNode<T>(item, NULL);       //�޸�//
			rear = rear->link;                              //�޸�//
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
		&item = front->data;
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

*/
