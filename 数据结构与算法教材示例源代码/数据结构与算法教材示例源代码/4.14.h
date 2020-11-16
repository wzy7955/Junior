#ifndef INCLUDE_MODIFYTOPSORT
#define INCLUDE_MODIFYTOPSORT
#include<iostream>
#define UNVISITED 0
#define VISITED 1
#define AFFINITY 999999
#include"AdjGraph.h"
#include"Graph.h"
#include"Edge.h"
template<class EdgeType>
bool ModifyTopSort(Graph<EdgeType>& G, int* VE, int* SortArray)
{//��ͼG������������,��ø��������¼������緢��ʱ��,
	//�������д��������SortArray�У��¼������緢��ʱ���¼��VE��
	int n = G.VerticesNum(); 		//��¼ͼ�еĶ������
	int* indegree = new int[n];		//����һ�������¼������������ֵ
	int v;
	Edge<EdgeType> e;
	for (v = 0; v<n; v++)
	{//�����������ȳ�ʼ��0,����״̬���Ϊδ����,�¼������緢��ʱ���ʼ��Ϊ0
		indegree[v] = 0; 
		G.Mark[v] = UNVISITED;
		VE[v] = 0;
	}
	for (v = 0; v<n; v++)
	{ //ͳ�Ƹ�������������Ϣ
		for (e = G.FirstEdge(v); G.IsEdge(e); e = G.NextEdge(e))
		{
			indegree[e.end]++;
		}
	}
	for (int i = 0; i<n; i++)
	{//����ȷ����������SortArray�еĵ�i��Ԫ��
		//�ҵ����Ϊ0��δ�����ʵĶ���
		for (v = 0; v<n; v++)
		{
			if (indegree[v] == 0 && G.Mark[v] == UNVISITED)
			{
				break; //�˳�for(v)ѭ��
			}
		}
		//�Ҳ������Ϊ0�Ķ���,�˳���������
		if (v == n) { return false; }
		//������v�ŵ�����������,������״̬����ΪVISITED
		G.Mark[v] = VISITED;
		SortArray[i] = v;
		for (e = G.FirstEdge(v); G.IsEdge(e); e = G.NextEdge(e))
		{//�޸�vָ��Ķ�������
			indegree[e.end]--;
			//�޸�v�ĺ���¼������緢��ʱ�� max{ve[i]+dut[i,j]}
			if (VE[e.end]<VE[v] + e.weight)
				VE[e.end] = VE[v] + e.weight;
		}
	}
	delete[]indegree;
	return true;
}
#endif