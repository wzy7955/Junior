#ifndef INCLUDE_STRACTGRAPH
#define INCLUDE_STRACTGRAPH
#include"Edge.h"
using namespace std;
//G=��V,E������һ��ͼ��V���Ƕ���ķǿ����޼��ϣ�E�Ǳߣ��򻡣��ļ���
template<class EdgeType>
class Graph
{
public:
	Graph(int verticesNum);		//���캯��
	~Graph();                 		//��������
	virtual Edge<EdgeType> FirstEdge(int oneVertex) = 0;
	//�����붥��oneVertex������ĵ�һ����
	virtual Edge<EdgeType> NextEdge(Edge<EdgeType> oneEdge) = 0;
	//�������oneEdge����ͬ������һ����
	virtual void setEdge(int start, int end, EdgeType weight) = 0;
	//���ñߣ�start,end��,Ȩ��Ϊweight
	virtual void delEdge(int start, int end) = 0;
	//ɾ���ߣ�start,end��
	int getVertexNum();			//����ͼ�Ķ������
	int getEdgeNum();       		//����ͼ�ı���
	bool isEdge(Edge<EdgeType> oneEdge);
	//���oneEdge�Ǳ��򷵻�TRUE�����򷵻�FALSE
	int StartVertex(Edge<EdgeType> oneEdge);//���ر�oneEdge��ʼ��
	int EndVertex(Edge<EdgeType> oneEdge);//���ر�oneEdge���յ�
	EdgeType Weight(Edge<EdgeType> oneEdge);	//���ر�oneEdge��Ȩ
};
#endif