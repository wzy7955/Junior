#include<iostream>
#include<queue>
#include<stack>
#include"graph.h"
#include"AdjGraph.h"
#include"ListData.h"
using namespace std;
int main()
{
	AdjGraph <int> tu(8);     //ͼ���ڽӾ���ʵ��
	//ListGraph <int> tu(8);  //ͼ���ڽӱ�ʵ��
	tu.setEdge(0,1,1);
	tu.setEdge(0,2,1);
	tu.setEdge(1,0,1);
	tu.setEdge(1,3,1);
	tu.setEdge(1,4,1);
	tu.setEdge(2,0,1);
	tu.setEdge(2,5,1);
	tu.setEdge(2,6,1);
	tu.setEdge(3,1,1);
	tu.setEdge(3,7,1);
	tu.setEdge(4,1,1);
	tu.setEdge(4,7,1);
	tu.setEdge(5,2,1);
	tu.setEdge(5,6,1);
	tu.setEdge(6,2,1);
	tu.setEdge(6,5,1);
	tu.setEdge(7,3,1);
	tu.setEdge(7,4,1);
	cout<<"������ȱ������:";
	tu.DFStraverse();
	cout <<endl<<"�ǵݹ�������ȱ������:";
	tu.DFSNoReverse();
	cout<<endl<<"������ȱ��������";
	tu.BFStraverse();
	cout<<endl;
	return 0;
}
