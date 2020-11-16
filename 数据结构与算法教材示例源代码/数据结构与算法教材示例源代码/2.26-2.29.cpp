#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;
class String
{
public:
String(char *str = NULL); // ��ͨ���캯��
String  &operator = (const String& s);//��ֵ���� 
String  operator +(String &other); // ƴ�����㺯��
String Substr(int index, int count);// ��ȡ�ַ�������
void display(); 
~ String(); // ��������
private:
char *str; // ���ڱ����ַ���
int size;

}; 
String::~String()
{ 
  delete [] str; 
} 
 void String::display() 
{
  cout<<str<<endl;
} 
 
 
//����2.26��String�����캯����

String::String(char * s)
{
   if(s==NULL)
  { 
    str=new char[1]; //�Կ��ַ����Զ������Ž�����־'\0'�Ŀռ� 
    assert(str != '\0');     	//�����ٶ�̬���򲻳ɹ�ʱ�������쳣���˳�
    str[0]='\0'; 
  } 
else
{
	int size = strlen(s);          	//������ĳ���
	str = new char[size + 1];	//��̬����һ��ռ䣬��Ҫ�洢������'\0'�����Գ���Ϊsize+1
	assert(str != '\0');     	//�����ٶ�̬���򲻳ɹ�ʱ�������쳣���˳�
	strcpy(str, s);            	//����ֵs���Ƶ�str��ָ�Ĵ洢�ռ�
}
	
}
 
 //����2.27����ֵ�������ʵ�֡�

String& String::operator = (const String &s)
{
	if (this == &s) //����Ը�ֵ 
  { return *this; }
  
	if(size != s.size)		//���Ȳ�ͬ�����ͷű����洢�ռ䲢�����µĿռ�
	{
		delete [] str;  				//�ͷ�ԭ�ռ�
		str = new char[s.size + 1];		//�����ٿռ�ʧ�ܣ����˳�
		assert(str != '\0');
		size = s.size;
	}
	strcpy(str, s.str);
	return *this;
}

//����2.28��ƴ���������ʵ�֡�

String String::operator + (String& s)
{
	String temp;               		//����һ����temp
	int len;
	len = size + s.size;        		//ƴ�ӳ����ĳ���
	delete [] temp.str;           	//�ͷ�temp����ʱnew����Ĵ洢�ռ�
	temp.str = new char[len + 1];	//Ϊ�������ٴ洢�ռ�
	//temp = new char[len + 1];	/Ϊ�������ٴ洢�ռ�
	assert(temp.str != NULL);    	//�����ٴ洢�ռ䲻�ɹ������˳�
	temp.size = len;
	strcpy(temp.str, str);       	//�Ȱѱ�ʵ����˽����str�浽temp
	strcat(temp.str, s.str);     	//�����ַ�����ƴ��
	return temp;
}


//����2.29����ȡ�ַ���������ʵ�֡�

String String::Substr(int index, int count)
{
	int left = size - index;	//���±�index���Ҽ�������β������Ϊleft
	String temp;
	char *p, *q;
	if(index >= size)  			//���±�ֵindex����������ʵ�ʳ��ȣ��򷵻ؿմ�
		return temp;
	if(count > left) 			//��count������index���ҵ��ӷ������ȣ���count��С
		count = left;
	delete [] temp.str;			//�ͷ�ԭ���Ĵ洢�ռ�
	temp.str = new char[count + 1];
	assert(temp.str != NULL);	//�����ٴ洢�ռ䲻�ɹ������˳�
	p = temp.str;          		//pָ���������ݵĿմ�
	q = &str[index];       		//qָ��ʵ����str�����±�index��
	for(int i = 0; i < count; i++)
		*p++ = *q++;     		//��q��ָ�����ݸ�ֵ��p��ͬʱ����
	*p = '\0';             		//���������־'\0'
	temp.size = count;
	return temp;
}

int main()
{
	//����2.26 
	String str1("Love"), str2("China"),str3,str4;
	str1.display();
	
	//����2.27
	str3=str2;
	str3.display();
	//����2.28
	str3=str1+str3;
	str3.display(); 
	//����2.29
	str3.Substr(3,5).display();
	
	return 0;
 } 
