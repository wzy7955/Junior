#include<iostream>
#include<string>
using namespace std;

//����2.21�����ַ����ĵ�ǰ���ȡ�

int strlen(char s[])
{
	int count = 0;
	while(s[count] != '\0')
		count++;
	return count;
}

//����2.22���ַ����ĸ��ƺ�����

char * strcpy(char * s1, char * s2)
{
	int count = 0;
	if (s2 == NULL)//�����ж�str2�Ƿ�Ϊ��
	{
		return NULL;
	}
	int nleg=strlen(s2);
	s1=new char[nleg];
	while(s2[count] != '\0')
	{
		s1[count] = s2[count];
		count++;
	}
	s1[count] = '\0';
	return s1;
}


//����2.23���ַ����ıȽϺ�����

int strcmp(char * s1, char * s2)
{
	int count = 0;
	while(s1[count] != '\0' && s2[count] != '\0')
	{
		if(s1[count] > s2[count])
			return 1;
		else if(s1[count] < s2[count])
			return -1;
		count++;
	}
	if(s1[count] == '\0' && s2[count] != '\0')
		return -1;
	else if(s1[count] != '\0' && s2[count] == '\0')
		return 1;
	return 0;
}

//����2.24������Ѱ���ַ�������
 char * strchr(char * s, char c)
{
	int count = 0;
	while(s[count] != '\0' && s[count] != c)
		count++;
	if(s[count] == '\0')
		return '\0';
	else 
		return &s[count];
}

//����2.25������Ѱ���ַ�������

char * strrchr(char * s, char c)
{
	int count = 0;
	while(s[count] != '\0')
		count++;
	while(count >= 0 && s[count] != c)
		count--;
	if(count < 0)
		return '\0';
	else 
		return &s[count];
}
int main()
{
	char *str1 = "Hello ";
	char *str2 = "World !!!!";
	//����2.21
	cout<<strlen(str1)<<endl;
	//����2.22 
	str1 = strcpy(str1,str2);
	cout<<str1<<endl;
	//����2.23
    cout<<strcmp(str1,str2)<<endl;
    //����2.24
    char *c=strchr(str1,'l');
    cout<<c<<endl;
     //����2.25
    char *cc=strrchr(str1,'l');
    cout<<cc<<endl;
	return 0;
	
}

