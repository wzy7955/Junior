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
