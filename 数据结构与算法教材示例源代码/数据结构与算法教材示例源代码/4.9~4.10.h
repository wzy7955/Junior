#ifndef INCLUDE_KRUSKAL
#define INCLUDE_KRUSKAL
#include<iostream>
#include <assert.h>
#include"MinHeap.h"
#include"Edge.h"
#include"AdjGraph.h"
#include"Graph.h"
class UFsets{
private:
	int n;//�ȼ����� �ȼ�Ԫ�ĸ���
	int *root;//root[i]��ʾԪ��i���ڵĵȼ���Ĵ���Ԫ�ر��
	int *next;//next[i]��ʾ�ڵȼ�����,i�ĺ���Ԫ�ر��
	int *length;//length[i]��ʾi������� �ȼ����Ԫ�ظ���
public:
	UFsets(int size){
		n = size;//��ʼsize��Ԫ�صĵȼ���
		root = new int[n];
		next = new int[n];
		length = new int[n];
		for (int i = 0; i < n; i++){
			root[i] = next[i] = i;//����Ԫ�ض��Գ�һ���ȼ���
			length[i] = 1;
		}
	}
	int Find(int v){
		if (v < n){
			return root[v];
		}//���صȼ����еĴ���Ԫ�ر��
		else
		{//�߽���
			cout << "�������Ϸ�" << endl;
		}
	}
	void Union(int v, int u);//�ϲ�v��u���ڵĵȼ��࣬��Ԫ���ٵĺϲ���Ԫ�ض������ȥ
};
void UFsets::Union(int v, int u){
	if (root[u] == root[v]){
		//���������ͬһ���ȼ����У��ͷ���
		return;
	}
	else if (length[root[v]] <= length[root[u]]){
		//���u�ĳ��ȱ�v�ĳ��ȳ�����ô�Ͱ�v�ϵ�u����ȥ
		int rt = root[v];//��¼v���ڵĵȼ���Ĵ���Ԫ��
		length[root[u]] = length[root[u]] + length[root[v]];//�޸�u���ڵĵȼ����Ԫ�صĸ���
		root[rt] = root[u];//�������޸�v���ڵĵȼ��������Ԫ�صĴ���Ԫ��
		for (int j = next[rt]; j != rt; j = next[j]){
			root[j] = root[u];
		}
		//���潻����������Ԫ�� rt,root[u] ��nextֵ
		int temp;
		temp = next[rt];
		next[rt] = next[root[u]];
		next[root[u]] = temp;
	}
	else if (length[root[v]] > length[root[u]]){
		//�෴��һ��
		int rt = root[u];
		length[root[v]] = length[root[v]] + length[root[u]];
		root[rt] = root[v];
		for (int k = next[rt]; k != rt; k = next[k]){
			root[k] = root[v];
		}
		int temp;
		temp = next[rt];
		next[rt] = next[root[v]];
		next[root[v]] = temp;
	}
}
template<class EdgeType>
Edge<EdgeType>* Kruskal(Graph<EdgeType> &G){//��С��������Kruskal�㷨
	//����n�����㡢e���ߵ���ͨͼG����С������ ���رߵļ���
	int n = G.VerticesNum();//��¼������Ŀ
	UFsets sets(n);//����n�����ĵȼ���
	Edge<EdgeType> *MST = new Edge<EdgeType>[n - 1];//Ҫ���ص���С�������ı�
	MinHeap<Edge<EdgeType>> MinH(G.EdgesNum());//���庬��e��Ԫ�ص���С�ѣ�����Ѱ��Ȩֵ��С�ı�
	Edge<EdgeType> edge;
	for (int i = 0; i < n; i++){
		for (edge = G.FirstEdge(i); G.IsEdge(edge); edge = G.NextEdge(edge)){
			if (G.StartVertex(edge) < G.EndVertex(edge)){
				//������ʼ��ı�Ŵ�С˳�򣬷�ֹ����ͼ�еı߱��ظ�����
				MinH.insertNode(edge);
			}
		}
	}
	int edgeNum = 0;//���ɱߵĸ���
	while (edgeNum < n - 1){//n��������ͨͼ����������n-1����
		if (!MinH.isEmpty()){
			//����Ѳ���
			edge = MinH.removemin();//�ҵ�Ȩ����С��δ����ı�  
			int v = edge.start;
			int u = edge.end;
			if (sets.Find(v) != sets.Find(u)){
				//�жϸñ߹����Ķ����Ƿ���һ����ͨ����
				sets.Union(v, u);//�ϲ������������ڵĵȼ���
				MST[edgeNum] = edge;//�����������ı���ӵ��������ı߼�����
				edgeNum++;
			}
		}
		else
		{
			assert("��������С������.");
			return nullptr;
		}

	}
	return MST;
}

#endif