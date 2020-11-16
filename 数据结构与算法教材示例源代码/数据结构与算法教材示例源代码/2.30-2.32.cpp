#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;

//����2.30�����ص��ַ���ģʽƥ���㷨��
int NaiveStrMatching(const string & T, const string & P)
{
	int p = 0;                		//ģʽ���±����
	int t = 0;                		//Ŀ����±����
	int plen = P.length();  	//ģʽ�ĳ���
	int tlen = T.length();  	//Ŀ��ĳ���
	if(tlen < plen)           	//���Ŀ���ģʽ�̣�ƥ���޷��ɹ�
		return -1;
	while(p< plen && t < tlen)	//�����Ƚ϶�Ӧ�ַ�����ƥ��
	{
		if(T[t] == P[p])
		{
			p++;
			t++;

		}
		else
		{
			t = t - p + 1;
			p = 0;
		}
	}
	if(p >= plen)
		return (t - plen);
	else
		return -1;
}


//����2.31�����������������㷨��

int * Next(string P)
{
	int m = P.size();         		//ģʽP�ĳ���
	assert(m > 0);                	//��m = 0�����˳�
	int * N = new int[m];          	//�ڶ�̬�洢�������µ�����
	assert(N != 0);
	N[0] = 0;
	for(int i = 1; i < m; i++)    	//��P��ÿһ��λ�ý��з���
	{
		int k = N[i - 1];         	//��i-1λ�õ��ǰ׺������
		while(k > 0 && P[i] != P[k])
			k = N[k - 1];
		if(P[i] == P[k])
			N[i] = k + 1;
		else
			N[i] = 0;
	}
	return N;
}

//����2.32��KMPģʽƥ���㷨��



int KMPStrMatching(string T, string P, int * N, int startIndex)
{
	int lastIndex = T.size() - P.size();
	if((lastIndex - startIndex) < 0) //��startIndex�������޷�ƥ��ɹ�
		return (-1);
	int i;                         	//ָ��T�ڲ��ַ����α�
	int j = 0;                    	//ָ��P�ڲ��ַ����α�
	for(  i = startIndex;i < T.size(); i++)
	{
		while(P[j] != T[i] && j > 0)
			j = N[j - 1];               
		if(P[j] == T[i])		//��P�ĵ�jλ��T�ĵ�iλ��ͬʱ�������
			j++;
		if(j == P.size())
			return (i -j + 1);	//ƥ��ɹ������ظ�T�Ӵ��Ŀ�ʼλ��
	}
	return (-1);
}


int main()
{
	string s1="acabaabaabcacaabc";
	string s2="abaabcac";
	//����2.30
	cout<<NaiveStrMatching(s1,s2)<<endl;
        //����2.31
	int *k=Next(s2);
       //����2.32
	cout<<KMPStrMatching(s1,s2,k,2)<<endl;
	return 0;
}
