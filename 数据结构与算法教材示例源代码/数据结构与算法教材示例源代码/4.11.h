#ifndef INCLUDE_DIJKSTRA
#define INCLUDE_DIJKSTRA
#define UNVISITED 0
#define VISITED 1
#define AFFINITY 999999
#include<iostream>
#include<string>
#include<stack>
#include"AdjGraph.h"
#include"Edge.h"
#include"Graph.h"
template<class EdgeType>
void Dijkstra(Graph<EdgeType> &G, int s, EdgeType* D, int * Path){
	/*Dijkstra�㷨�����в���s��Դ�㣬D���������·�����ȣ�Path[i]Ϊ·����i��ǰ��������*/
	int n = G.VerticesNum();//����ͼ�Ľڵ���Ŀ
	for (int i = 0; i < n; i++){
		//��ʼ��
		G.Mark[i] = UNVISITED;//һ��·����û�У���û�б����ʹ�
		D[i] = AFFINITY;//��s��ÿ������������·���ĳ��ȳ�ʼ��Ϊ���ֵ
		Path[i] = s;//���е��ǰ����ʼΪԴ��s
	}
	D[s] = 0;//s���������̳���Ϊ0
	for (int j = 0; j < n; j++){
		//ÿ��ѭ�����ҵ�һ�����·��
		//�ҵ�һ���������·��,��min{D[j]&&G.Mark[j]==UNVISITED, 0<=j<n}
		EdgeType min = AFFINITY;//minΪ��СȨ
		int k;
		for (int i = 0; i < n; i++){
			if (G.Mark[i] == UNVISITED&&D[i] < min){
				k = i;
				min = D[i];
			}
		}
		//��ȷ��s��k�����·��
		G.Mark[k] = VISITED;
		//�����޸�D
		//����k���µ�����δ���ʶ�����������·��
		for (Edge<EdgeType> e = G.FirstEdge(k); G.IsEdge(e); e = G.NextEdge(e)){
			int endVertex = e.end;
			if (G.Mark[endVertex] == UNVISITED&&D[endVertex] > (D[k] + e.weight)){
				//������ָ�С��·��,�͸���
				D[endVertex] = D[k] + e.weight;//���µ�endVertex���������·��
				Path[endVertex] = k;//����ǰ���ڵ���
			}
		}
	}
}

//�����������ĸ�������
template<class EdgeType>
void PrintDj(AdjGraph<EdgeType> &G, int s, EdgeType* &D, int * &P){//��ʽ�����·���Լ�����
	stack<int> sta;//����ջ����·���ڵ�
	int n = G.VerticesNum();
	for (int i = 0; i < n; i++){
		cout << "��" << G.Vertex[s] << "��" << G.Vertex[i] << "�����·��Ϊ��";
		sta.push(i);//������ҽڵ� �����ѹջ
		int j = i;
		while (P[j] != s){//�������Դ��s�ͼ�������
			sta.push(P[j]);
			j = P[j];
		}
		sta.push(s);
		while (!sta.empty()){//���γ�ջ�õ�·��
			int temp = sta.top();
			sta.pop();
			cout << G.Vertex[temp] << "  ";
		}
		cout << "����Ϊ��" << D[i] << endl;
	}
}

#endif