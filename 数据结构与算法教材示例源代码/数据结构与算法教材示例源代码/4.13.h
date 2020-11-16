#ifndef INCLUDE_TOPOLOGYSORT
#define INCLUDE_TOPOLOGYSORT
#include<iostream>
#define UNVISITED 0
#define VISITED 1
#define AFFINITY 999999
#include"AdjGraph.h"
#include"Graph.h"
#include"Edge.h"
template<class EdgeType>
bool TopologySort(Graph<EdgeType> &G, int* SortArray){
	//������ͼ�����������򣬽���������б�����SortArray��
	int n = G.VerticesNum();//��¼ͼ�еĶ������
	int *indegree = new int[n];//����һ�������¼������������ֵ

	int v;
	Edge<EdgeType> e;
	for (v = 0; v<n; v++)
	{//�����������ȳ�ʼ��0,����״̬���Ϊδ����
		indegree[v] = 0; G.Mark[v] = UNVISITED;
	}
	for (v = 0; v<n; v++)
	{ //ͳ�Ƹ�������������Ϣ
		for (e = G.FirstEdge(v); G.IsEdge(e); e = G.NextEdge(e))
		{
			indegree[e.end]++;//�޸ĸ�����������ֵ
		}
	}
	for (int i = 0; i < n; i++){
		//����ȷ����������SortArray�еĵ�i��Ԫ��
		for (v = 0; v < n; v++){
			if (indegree[v] == 0 && G.Mark[v] == UNVISITED){
				//�ҵ� ���Ϊ0 ����û�б����ʵĶ���
				break;//�˳�for(v)ѭ��
			}
		}
		if (v == n){
			//�Ҳ������Ϊ0�Ķ���,�˳���������
			return false;//��Ϊ�л�
		}
		//������v�ŵ�����������,������״̬����ΪVISITED
		G.Mark[v] = VISITED;
		SortArray[i] = v;
		//�ɶ���vΪʼ��ı�ɾȥ�������޸����бߵ��յ�����
		for (e = G.FirstEdge(v); G.IsEdge(e); e = G.NextEdge(e)){
			indegree[e.end]--;
		}
	}
	delete[]indegree;
	return true;
}
#endif