#include<iostream>
#include"AdjGraph.h"
#include"Prim.h"
#include"Kruskal.h"
#include"Dijkstra.h"
#include"Floyd.h"
#include"TopologySort.h"
#include"ModifyTopSort.h"
#include"CriticalPath.h"
using namespace std;
int main(){
	//AdjGraph��Graph��ʵ���࣬���������ʾ���ڽӾ���洢Ȩֵ�����ϵĶ����Ҿ��ò������ƣ����Ե�ʱ��
	//�������һЩ�µĴ������ƶ��壬����û�и������������������㷨����ȷ��
	//��4.8 ��������ͼ4-15(a)��ͼ  (b)Ϊ���	
	AdjGraph<int> adjGWei(6, true, false);//������Ȩ���ڶ���������ʾ����Ȩ�أ�������������ʾ�����������������ͬ��
	adjGWei.Vertex[0] = '1';	adjGWei.Vertex[1] = '2';	adjGWei.Vertex[2] = '3';	adjGWei.Vertex[3] = '4';
	adjGWei.Vertex[4] = '5';	adjGWei.Vertex[5] = '6';
	adjGWei.setEdge(0, 0, AFFINITY); adjGWei.setEdge(0, 1, 6); adjGWei.setEdge(0, 2, 1); adjGWei.setEdge(0, 3, 5); adjGWei.setEdge(0, 4, AFFINITY); adjGWei.setEdge(0, 5, AFFINITY);
	adjGWei.setEdge(1, 0, 6); adjGWei.setEdge(1, 1, AFFINITY); adjGWei.setEdge(1, 2, 5); adjGWei.setEdge(1, 3, AFFINITY); adjGWei.setEdge(1, 4, 3); adjGWei.setEdge(1, 5, AFFINITY);
	adjGWei.setEdge(2, 0, 1); adjGWei.setEdge(2, 1, 5); adjGWei.setEdge(2, 2, AFFINITY); adjGWei.setEdge(2, 3, 5); adjGWei.setEdge(2, 4, 6); adjGWei.setEdge(2, 5, 4);
	adjGWei.setEdge(3, 0, 5); adjGWei.setEdge(3, 1, AFFINITY); adjGWei.setEdge(3, 2, 5); adjGWei.setEdge(3, 3, AFFINITY); adjGWei.setEdge(3, 4, AFFINITY); adjGWei.setEdge(3, 5, 2);
	adjGWei.setEdge(4, 0, AFFINITY); adjGWei.setEdge(4, 1, 3); adjGWei.setEdge(4, 2, 6); adjGWei.setEdge(4, 3, AFFINITY); adjGWei.setEdge(4, 4, AFFINITY); adjGWei.setEdge(4, 5, 6);
	adjGWei.setEdge(5, 0, AFFINITY); adjGWei.setEdge(5, 1, AFFINITY); adjGWei.setEdge(5, 2, 4); adjGWei.setEdge(5, 3, 2); adjGWei.setEdge(5, 4, 6); adjGWei.setEdge(5, 5, AFFINITY);
	Edge<int>*  edge;
	int n = adjGWei.vertexNum - 1;
	edge = Prim(adjGWei, 0);
	cout << "prim�㷨:" << endl;
	for (int j = 0; j < n; j++){
		cout << "�ߵ������:" << edge[j].start + 1 << "   �յ���:" << edge[j].end + 1 << "    Ȩֵ��:" << edge[j].weight << endl;
	}

	//��4.9  4.10 ��������ͼ4-15(a)��ͼ  (b)Ϊ���		
	edge = Kruskal(adjGWei);
	cout << "kruskal�㷨:" << endl;
	for (int j = 0; j < n; j++){
		cout << "�ߵ������:" << edge[j].start + 1 << "   �յ���:" << edge[j].end + 1 << "    Ȩֵ��:" << edge[j].weight << endl;
	}

	//��4.11 ��������ͼ4-18��ͼ	
	AdjGraph<int> adjGWeiDi(6, true, true);
	adjGWeiDi.Vertex[0] = '0';	adjGWeiDi.Vertex[1] = '1';	adjGWeiDi.Vertex[2] = '2';	adjGWeiDi.Vertex[3] = '3';
	adjGWeiDi.Vertex[4] = '4';	adjGWeiDi.Vertex[5] = '5';
	adjGWeiDi.setEdge(0, 0, AFFINITY); adjGWeiDi.setEdge(0, 1, 12); adjGWeiDi.setEdge(0, 2, 10); adjGWeiDi.setEdge(0, 3, AFFINITY); adjGWeiDi.setEdge(0, 4, 30); adjGWeiDi.setEdge(0, 5, 100);
	adjGWeiDi.setEdge(1, 0, AFFINITY); adjGWeiDi.setEdge(1, 1, AFFINITY); adjGWeiDi.setEdge(1, 2, 5); adjGWeiDi.setEdge(1, 3, AFFINITY); adjGWeiDi.setEdge(1, 4, AFFINITY); adjGWeiDi.setEdge(1, 5, AFFINITY);
	adjGWeiDi.setEdge(2, 0, AFFINITY); adjGWeiDi.setEdge(2, 1, AFFINITY); adjGWeiDi.setEdge(2, 2, AFFINITY); adjGWeiDi.setEdge(2, 3, 50); adjGWeiDi.setEdge(2, 4, AFFINITY); adjGWeiDi.setEdge(2, 5, AFFINITY);
	adjGWeiDi.setEdge(3, 0, AFFINITY); adjGWeiDi.setEdge(3, 1, AFFINITY); adjGWeiDi.setEdge(3, 2, AFFINITY); adjGWeiDi.setEdge(3, 3, AFFINITY); adjGWeiDi.setEdge(3, 4, AFFINITY); adjGWeiDi.setEdge(3, 5, 10);
	adjGWeiDi.setEdge(4, 0, AFFINITY); adjGWeiDi.setEdge(4, 1, AFFINITY); adjGWeiDi.setEdge(4, 2, AFFINITY); adjGWeiDi.setEdge(4, 3, 20); adjGWeiDi.setEdge(4, 4, AFFINITY); adjGWeiDi.setEdge(4, 5, 60);
	adjGWeiDi.setEdge(5, 0, AFFINITY); adjGWeiDi.setEdge(5, 1, AFFINITY); adjGWeiDi.setEdge(5, 2, AFFINITY); adjGWeiDi.setEdge(5, 3, AFFINITY); adjGWeiDi.setEdge(5, 4, AFFINITY); adjGWeiDi.setEdge(5, 5, AFFINITY);
	cout << "Dijkstra�㷨:" << endl;
	int* D = new int[6];
	int* P = new int[6];
	Dijkstra(adjGWeiDi, 0, D, P);
	PrintDj(adjGWeiDi, 0, D, P);

	//��4.12 ��������ͼ4-20��ͼ
	cout << "Floyd�㷨:" << endl;
	int **adjArray = new int*[n];
	for (int i = 0; i < n; i++){
		adjArray[i] = new int[n];
	}
	int **Path = new int*[n];
	for (int j = 0; j < n; j++){
		Path[j] = new int[n];
	}
	AdjGraph<int> adjGWeiDiTwo(3, true, true);
	adjGWeiDiTwo.Vertex[0] = '0';
	adjGWeiDiTwo.Vertex[1] = '1';
	adjGWeiDiTwo.Vertex[2] = '2';
	adjGWeiDiTwo.setEdge(0, 0, AFFINITY); adjGWeiDiTwo.setEdge(0, 1, 5); adjGWeiDiTwo.setEdge(0, 2, 10);
	adjGWeiDiTwo.setEdge(1, 0, 2); adjGWeiDiTwo.setEdge(1, 1, AFFINITY); adjGWeiDiTwo.setEdge(1, 2, 13);
	adjGWeiDiTwo.setEdge(2, 0, 9); adjGWeiDiTwo.setEdge(2, 1, 6); adjGWeiDiTwo.setEdge(2, 2, AFFINITY);
	Floyd(adjGWeiDiTwo, adjArray, Path);
	PrintFloyd(adjGWeiDiTwo, adjArray, Path);
	
	//��4.13 ��������ͼ4-22��ͼ
	cout << "��������:" << endl;
	AdjGraph<int>  eventGraph(6, false, true);
	int *sortArray = new int[6];
	eventGraph.Vertex[0] = '1'; eventGraph.Vertex[1] = '2'; eventGraph.Vertex[2] = '3'; eventGraph.Vertex[3] = '4'; eventGraph.Vertex[4] = '5'; eventGraph.Vertex[5] = '6';
	eventGraph.setEdge(0, 0, 0);	eventGraph.setEdge(0, 1, 1);	eventGraph.setEdge(0, 2, 1);	eventGraph.setEdge(0, 3, 0);	eventGraph.setEdge(0, 4, 0);	eventGraph.setEdge(0, 5, 0);
	eventGraph.setEdge(1, 0, 0);	eventGraph.setEdge(1, 1, 0);	eventGraph.setEdge(1, 2, 0);	eventGraph.setEdge(1, 3, 0);	eventGraph.setEdge(1, 4, 0);	eventGraph.setEdge(1, 5, 0);
	eventGraph.setEdge(2, 0, 0);	eventGraph.setEdge(2, 1, 0);	eventGraph.setEdge(2, 2, 0);	eventGraph.setEdge(2, 3, 0);	eventGraph.setEdge(2, 4, 1);	eventGraph.setEdge(2, 5, 1);
	eventGraph.setEdge(3, 0, 0);	eventGraph.setEdge(3, 1, 0);	eventGraph.setEdge(3, 2, 0);	eventGraph.setEdge(3, 3, 0);	eventGraph.setEdge(3, 4, 0);	eventGraph.setEdge(3, 5, 1);
	eventGraph.setEdge(4, 0, 0);	eventGraph.setEdge(4, 1, 0);	eventGraph.setEdge(4, 2, 0);	eventGraph.setEdge(4, 3, 0);	eventGraph.setEdge(4, 4, 0);	eventGraph.setEdge(4, 5, 0);
	eventGraph.setEdge(5, 0, 0);	eventGraph.setEdge(5, 1, 0);	eventGraph.setEdge(5, 2, 0);	eventGraph.setEdge(5, 3, 0);	eventGraph.setEdge(5, 4, 0);	eventGraph.setEdge(5, 5, 0);
	cout << "�ܷ�����:" << TopologySort(eventGraph, sortArray) << endl;
	for (int i = 0; i < 6; i++){
		cout << sortArray[i] << "   ";
	}
	//��4.13 ��������ͼ4-24(b)��ͼ
	AdjGraph<int>  adjTuoPo(4, false, true);
	int *sort = new int[4];
	adjTuoPo.Vertex[0] = 'a';
	adjTuoPo.Vertex[1] = 'b';
	adjTuoPo.Vertex[2] = 'c';
	adjTuoPo.Vertex[3] = 'd';
	adjTuoPo.setEdge(0, 0, 0); adjTuoPo.setEdge(0, 1, 1); adjTuoPo.setEdge(0, 2, 1); adjTuoPo.setEdge(0, 3, 0);
	adjTuoPo.setEdge(1, 0, 0); adjTuoPo.setEdge(1, 1, 0); adjTuoPo.setEdge(1, 2, 0); adjTuoPo.setEdge(1, 3, 1);
	adjTuoPo.setEdge(2, 0, 0); adjTuoPo.setEdge(2, 1, 1); adjTuoPo.setEdge(2, 2, 0); adjTuoPo.setEdge(2, 3, 0);
	adjTuoPo.setEdge(3, 0, 0); adjTuoPo.setEdge(3, 1, 0); adjTuoPo.setEdge(3, 2, 1); adjTuoPo.setEdge(3, 3, 0);
	cout << endl;
	cout << "�ܷ���������:" << TopologySort(adjTuoPo, sort) << endl;

	//��4.14 ��������ͼ4-25��ͼ
	cout << "������������¼������緢��ʱ��:" << endl;
	AdjGraph<int>  eventGraph2(7, true, true);
	int *sortArray2 = new int[7];
	int *AE = new int[7];
	eventGraph2.Vertex[0] = '1'; eventGraph2.Vertex[1] = '2'; eventGraph2.Vertex[2] = '3'; eventGraph2.Vertex[3] = '4'; eventGraph2.Vertex[4] = '5';
	eventGraph2.Vertex[5] = '6'; eventGraph2.Vertex[6] = '7';
	eventGraph2.setEdge(0, 0, AFFINITY);	eventGraph2.setEdge(0, 1, 6);	eventGraph2.setEdge(0, 2, 3);	eventGraph2.setEdge(0, 3, AFFINITY);	eventGraph2.setEdge(0, 4, AFFINITY);	eventGraph2.setEdge(0, 5, AFFINITY); eventGraph2.setEdge(0, 6, AFFINITY);
	eventGraph2.setEdge(1, 0, AFFINITY);	eventGraph2.setEdge(1, 1, AFFINITY);	eventGraph2.setEdge(1, 2, AFFINITY);	eventGraph2.setEdge(1, 3, 1);	eventGraph2.setEdge(1, 4, AFFINITY);	eventGraph2.setEdge(1, 5, AFFINITY); eventGraph2.setEdge(1, 6, AFFINITY);
	eventGraph2.setEdge(2, 0, AFFINITY);	eventGraph2.setEdge(2, 1, AFFINITY);	eventGraph2.setEdge(2, 2, AFFINITY);	eventGraph2.setEdge(2, 3, 1);	eventGraph2.setEdge(2, 4, AFFINITY);	eventGraph2.setEdge(2, 5, AFFINITY); eventGraph2.setEdge(2, 6, AFFINITY);
	eventGraph2.setEdge(3, 0, AFFINITY);	eventGraph2.setEdge(3, 1, AFFINITY);	eventGraph2.setEdge(3, 2, AFFINITY);	eventGraph2.setEdge(3, 3, AFFINITY);	eventGraph2.setEdge(3, 4, 9);	eventGraph2.setEdge(3, 5, 6); eventGraph2.setEdge(3, 6, AFFINITY);
	eventGraph2.setEdge(4, 0, AFFINITY);	eventGraph2.setEdge(4, 1, AFFINITY);	eventGraph2.setEdge(4, 2, AFFINITY);	eventGraph2.setEdge(4, 3, AFFINITY);	eventGraph2.setEdge(4, 4, AFFINITY);	eventGraph2.setEdge(4, 5, AFFINITY); eventGraph2.setEdge(4, 6, 2);
	eventGraph2.setEdge(5, 0, AFFINITY);	eventGraph2.setEdge(5, 1, AFFINITY);	eventGraph2.setEdge(5, 2, AFFINITY);	eventGraph2.setEdge(5, 3, AFFINITY);	eventGraph2.setEdge(5, 4, AFFINITY);	eventGraph2.setEdge(5, 5, AFFINITY); eventGraph2.setEdge(5, 6, 3);
	eventGraph2.setEdge(6, 0, AFFINITY);	eventGraph2.setEdge(6, 1, AFFINITY);	eventGraph2.setEdge(6, 2, AFFINITY);	eventGraph2.setEdge(6, 3, AFFINITY);	eventGraph2.setEdge(6, 4, AFFINITY);	eventGraph2.setEdge(6, 5, AFFINITY); eventGraph2.setEdge(6, 6, AFFINITY);
	cout << "�ܷ�����:" << ModifyTopSort(eventGraph2, AE, sortArray2) << endl;
	for (int i = 0; i < 7; i++){
		cout << sortArray2[i]+1 << "   ";
	}
	cout << endl;
	cout << "�¼������緢��ʱ��:" << endl;
	for (int i = 0; i < 7; i++){
		cout << "�¼�" << i+1 << "  AE��" << AE[i] << "   " << endl;
	}

	//��4.15 ��������ͼ4-25��ͼ
	cout << "ȷ���ؼ��:" << endl;
	int* VE = new int[n];    //��¼���������¼������緢��ʱ��
	int* VL = new int[n];    //��¼���������¼�����ٷ���ʱ��
	int* TopOrder = new int[n];  //��¼��������
	cout << "�ܷ�����:" << CriticalPath(eventGraph2, VE, VL, TopOrder) << endl;
	for (int i = 0; i < 7; i++){
		cout << TopOrder[i] + 1 << "   ";
	}
	cout << endl;
	cout << "�¼������緢��ʱ��:" << endl;
	for (int i = 0; i < 7; i++){
		cout << "�¼�" << i + 1 << "  AE��" << VE[i] << "   " << endl;
	}
	cout << "�¼���������ʱ��:" << endl;
	for (int i = 0; i < 7; i++){
		cout << "�¼�" << i + 1 << "  AE��" << VL[i] << "   " << endl;
	}
	system("pause");
	return 0;
}