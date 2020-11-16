#ifndef INCLUDE_CRITICALPATH
#define INCLUDE_CRITICALPATH
#include<iostream>
#define UNVISITED 0
#define VISITED 1
#define AFFINITY 999999
#include"AdjGraph.h"
#include"Graph.h"
#include"Edge.h"
#include"ModifyTopSort.h"
template<class EdgeType>
bool CriticalPath(Graph<EdgeType>& G, int* VE, int* VL, int* TopOrder)
{	//����ͼG�йؼ���������棬�������AOE�����򷵻�false
	//VE��¼���������¼������緢��ʱ��
	//VL��¼���������¼�����ٷ���ʱ��
	//TopOrder��¼��������
	int n = G.VerticesNum(); //��¼ͼ�еĶ������
	int v;
	if (!ModifyTopSort(G, VE, TopOrder))
	{//���ͼ���������򼰸��������¼������緢��ʱ��
		return false;  //���ڻ�,���ܼ���ؼ��
	}
	//���������¼�����ٷ���ʱ�䶼��ʼ���յ��¼������緢��ʱ��
	for (int i = 0; i<n; i++)
		VL[i] = VE[TopOrder[n - 1]];

	//���������������˳��,�޸�start����ĵ��VL,ÿ���ҵ���startΪʼ��ı�,����vl=min{vl-dut}
	for (int i = n - 1; i >= 0; i--){
		int start = TopOrder[i];//ÿ���޸ĵĶ���(Ҳ�Ǳߵ���ʼ��)
		for (Edge<EdgeType> e = G.FirstEdge(start); G.IsEdge(e); e = G.NextEdge(e)){
			int end = e.end;
			EdgeType dut = e.weight;
			if (VL[start]>VL[end] - dut){
				VL[start] = VL[end] - dut;//���չ�ʽ�޸�VL
			}
		}
	}

	EdgeType sum = 0;//������������¼���Ҫ�����ʱ��
	for (v = 0; v<n; v++)
	{//ȷ���ؼ��
		for (Edge<EdgeType> e = G.FirstEdge(v); G.IsEdge(e); e = G.NextEdge(e))
		{//���ձ���ÿ������ı�,Ѱ������ؼ���ı�
			int u = e.end;
			EdgeType dut = e.weight;
			//ȷ���ؼ�������,�ؼ����e=l,����e=ve,l=vl-dut,��˹ؼ�����������¼���ve=vl-dut
			if (VE[v] == VL[u] - dut){
				cout << '(' << v + 1 << ',' << u + 1 << ')' << VE[v] << ' ' << dut << endl;
				sum = sum + dut;//�ۼ�ʱ��
			}
		}
	}
	cout << "��ʱ��Ϊ��" << sum << endl;
	return true;
}
#endif