template<class T>
class LinkNode
{
	public:
		T data;							//������
		LinkNode<T>*link;				//ָ����ָ��Ľ��

		LinkNode(const T&el, LinkNode<T>*ptr = 0){	//���캯��
			data=el;
			link=ptr;
	}
};
