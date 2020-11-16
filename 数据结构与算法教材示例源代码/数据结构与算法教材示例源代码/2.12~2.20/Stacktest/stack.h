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

