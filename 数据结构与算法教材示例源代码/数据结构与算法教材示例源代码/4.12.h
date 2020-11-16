#ifndef INCLUDE_FLOYD
#define INCLUDE_FLOYD
#include<iostream>
#define UNVISITED 0
#define VISITED 1
#define AFFINITY 999999
#include<stack>
#include"AdjGraph.h"
#include"Graph.h"
#include"Edge.h"

template<class EdgeType>
void Floyd(Graph<EdgeType> &G, EdgeType **adjArray, int **Path){
	//��Ȩ ����ͼ��adjArray[i][j]Ϊ��i��j�����·�����ȣ�Path[i][j]Ϊ���·���ж���j��ǰ��������
	int i, j, v;
	int n = G.VerticesNum();
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			if (i == j){
				adjArray[i][j] = 0;//���������С·��Ϊ0
			}
			else{
				adjArray[i][j] = AFFINITY;//�����������
			}
			Path[i][j] = i;//ǰ������ ��� ������
		}
	}//��ʼ��
	for (v = 0; v < n; v++){
		//�������ߣ�����v,end����Ȩֵ��ΪadjArray[v][end]
		for (Edge<EdgeType> e = G.FirstEdge(v); G.IsEdge(e); e = G.NextEdge(e)){
			adjArray[v][e.end] = e.weight;
		}
	}
	//�����������i,j֮������·����������v������adjArray[i][j]>(adjArray[i][v]+adjArray[v][j])���͸���adjArray[i][j]��Path[i][j]��ֵ
	for (v = 0; v < n; v++){
		for (i = 0; i < n; i++){
			for (j = 0; j < n; j++){
				if (adjArray[i][j] >(adjArray[i][v] + adjArray[v][j])){
					adjArray[i][j] = adjArray[i][v] + adjArray[v][j];//�������·��
					Path[i][j] = v;
				}
			}
		}
	}
}

//�����������ĸ�������
template<class EdgeType>
void PrintFloyd(AdjGraph<EdgeType> &G, EdgeType **&adjArray, int **&Path){
	int n = G.VerticesNum();
	stack<int> sta;//����ջ����·���ڵ�
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout << G.Vertex[i] << "��" << G.Vertex[j] << "�����·������Ϊ:" << adjArray[i][j] << "    ·��Ϊ";
			sta.push(j);//������ҽڵ� �����ѹջ
			int s = j;
			while (Path[i][s] != i){//�������Դ��i�ͼ�������
				sta.push(Path[i][s]);
				s = Path[i][s];
			}
			sta.push(i);
			while (!sta.empty()){//���γ�ջ�õ�·��
				int temp = sta.top();
				sta.pop();
				cout << G.Vertex[temp] << "  ";
			}
			cout << endl;
		}
	}
}
#endif