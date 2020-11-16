#pragma once
template<class EdgeType>
class listData           				//�ڽӱ�߽������ݲ��ֶ���
{
public:
	int vertex;             			//�ߵ��յ�
	EdgeType weight;      			//�ߵ�Ȩ
};
template<class Elem>         		//����߽��
class ListNode {
public:
	Elem element;             		//�߽�������
	ListNode<Elem> *next;     		//�߽��ָ�룬ָ����һ���߽��
	ListNode(const Elem& elemval, ListNode<Elem> *nextval = NULL) { element = elemval; next = nextval; }
	ListNode(ListNode<Elem> *nextval = NULL) { next = nextval; }
};
template<class Elem>
class EdgeList {          			//ÿ�������������ı߱�
public:
	ListNode<Elem>* head;   		//headָ��
	EdgeList() {              			//���캯��
		head = new ListNode<Elem>();
	}
	void removeall()      			//�ͷű߱����б߽��ռ�ݵĿռ�
	{
		ListNode<Elem> *tmp;
		while (head != NULL)    		//���ͷ�ÿ���߽��ռ�ݵĿռ�
		{
			tmp = head;
			head = head->next;
			delete tmp;
		}
	}

	~EdgeList() { removeall(); }	//��������
};
template <class EdgeType>
class ListGraph : public Graph<EdgeType>	//ͼ���ڽӱ��ʾ
{
private:
	EdgeList<listData<EdgeType>> *graList;
	//graList�Ǳ������б߱������
public:
	ListGraph(int verticesNum) :Graph<EdgeType>::Graph(verticesNum) //���캯��
	{//����ռ䣬��vertexNum����������vertexNum���߱�
		graList = new EdgeList<listData<EdgeType>>[this->vertexNum];
	}
	~ListGraph()           			//��������
	{
		delete[] graList;
	}
	Edge<EdgeType> FirstEdge(int oneVertex) 	//���ض���oneVertex�ĵ�һ����
	{
		Edge<EdgeType> tmpEdge; 	//����tmpEdge��Ϊ�����ķ���ֵ
		tmpEdge.start = oneVertex;
		ListNode<listData<EdgeType>> *temp = graList[oneVertex].head;  			   //graList[oneVertex].head������Ƕ���oneVertex�ı߱�					   //temp->nextָ�򶥵�oneVertex�ĵ�һ����(���temp->next��Ϊnull)
		if (temp->next != NULL)		//����oneVertex�ĵ�һ���ߴ���
		{
			tmpEdge.end = temp->next->element.vertex;
			tmpEdge.weight = temp->next->element.weight;
		}
		return tmpEdge;
	}
	Edge<EdgeType> NextEdge(Edge<EdgeType> oneEdge)
	{//�������OneEdge����ͬ�����������һ����
		Edge<EdgeType> tmpEdge;
		tmpEdge.start = oneEdge.start;
		ListNode<listData<EdgeType>>*temp = graList[oneEdge.start].head;
		//ȷ����oneEdge�ڱ߱��е�λ��,�����oneEdge����һ����ȷʵ���ڣ�
		//��temp->nextָ��ָ����һ���ߵı�Ŀ
		while (temp->next != NULL && temp->next->element.vertex <= oneEdge.end)
			temp = temp->next;
		if (temp->next != NULL)         //��oneEdge����һ���ߴ��� 
		{
			tmpEdge.end = temp->next->element.vertex;
			tmpEdge.weight = temp->next->element.weight;
		}
		return tmpEdge;
	}
	void setEdge(int start, int end, EdgeType weight)//Ϊͼ�趨һ����
	{
		ListNode<listData<EdgeType>> *temp = graList[start].head;
		while (temp->next != NULL && temp->next->element.vertex < end)
			//ȷ����(start,end)��<start,end>�ڱ߱��е�λ��,���������,���				//(start,end)��<start,end>Ϊ�¼ӵ�һ����
			temp = temp->next;
		if (temp->next == NULL)
		{//���ڱ߱��в��������ڱ߱����������������,
		 //���ڱ߱��м���������
			temp->next = new ListNode<listData<EdgeType>>;
			temp->next->element.vertex = end;
			temp->next->element.weight = weight;
			this->edgeNum++;
			return;
		}
		if (temp->next->element.vertex == end)		//���ڱ߱����Ѵ���
		{
			temp->next->element.weight = weight;
			return;
		}
		if (temp->next->element.vertex > end)
		{//���ڱ߱��в�����,���ڱ߱���������������,
		 //���ڱ߱��в���������
			ListNode<listData<EdgeType>> *other = temp->next;
			temp->next = new ListNode<listData<EdgeType>>;
			temp->next->element.vertex = end;
			temp->next->element.weight = weight;
			temp->next->next = other;
			this->edgeNum++;

		}
	}
	void delEdge(int start, int end)         	//ɾ��ͼ��һ����
	{
		ListNode<listData<EdgeType>> *temp = graList[start].head;
		while (temp->next != NULL && temp->next->element.vertex < end)
			temp = temp->next;
		if (temp->next == NULL) return;        	//�߲�����,�����κβ���
		if (temp->next->element.vertex == end)//�ߴ���,����ɾ��
		{
			ListNode<listData<EdgeType>> *other = temp->next->next;
			delete temp->next;
			temp->next = other;
			this->edgeNum--;
		}
	}
};
