#include<stdio.h>
#include<math.h>
#include<bits/stdc++.h>
#define pi 3.1415926
using namespace std;
int main()
{
	/*double r;
	scanf("%lf",&r);
	
	printf("input r:%8.2f\n",r);
	printf("area_1:%8.2f\n", 2*3.14*r);
	printf("area_2:%.2f\n",2*pi*r);*/
	
	/*int x= 0xaffbc;
	printf("%d",x);*/
	 
	/*float a = +1e+1;
	float b = -.60;*/
	
	/*int i = 2;
	char c = 'A';
	printf("%d", i+c);*/
	
	/*double x=2 ,y;
	printf("%f",x+3/2);*/
	/*int a =12;
	printf("%d",a+=a-=a*=a);*/
	
	/*int x,i,j,k;
	printf("%d",x=(i=4,j=16,k=32));*/
	
	
	/*int N;
	printf("��������");
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N-i;j++){
			printf(" ");
		}
		for(int k=1;k<=2*i-1;k++){
			printf("*");
		}
		printf("\n");
	}
	for(int i=N-1;i>0;i--){
		for(int j=N-i;j>0;j--){
			printf(" ");
		}
		for(int k=2*i-1;k>0;k--){
			printf("*");
		}
		printf("\n");
	}*/
	
	
	
	/*
		TODO:��дһ���������ͼ�ε��⡣�������⣩
       *
     *   *
    *     *
     *   *
       *
	*/
	
	
	/*int n,j,i;                            
    printf("����ͼ�������ǵĸ߶�n:");
    scanf("%d",&n);

    for(i = 1;i <= n;i++)               \
    {
        for(j = 1;j <= n - 1 + i;j++)       
        {
            if(j == n - 1 -i+2 || j == n - 1 - i + 2 * i )
                printf(" *");
            else
                printf("  ");
        }
        printf("\n");
    }
    for(i = n - 1 ;i >= 1;i--)               
    {                             
        for(j=1;j<=n - 1 +i;j++)         
            if(j == n - 1 -i+2 || j == n - 1 -i + 2 * i )
                printf(" *");
            else
                printf("  ");
        printf("\n");
    }

    printf("\n");
    system("pause");*/
	
    
    /*
		TODO:����3���������3�����е�����ߣ����3������ƽ��ֵ��
	*/
    
    /*
		int a,b,c,average;
		printf("a=");
		scanf("%d",&a);
		printf("b=");
		scanf("%d",&b);
		printf("c=");
		scanf("%d",&c);
		average=(a+b+c)/3;
		printf("a,b,c3�����ֵ�ƽ��ֵ��%d",average);
	*/
	
 /*	��дC����, ����a��b����ֵ�����������ľ���ֵ. 
	5.����һ��3λ�������ֱ����ַ��������λ��ʮλ����λ�ϵ�������
	7.����Сд��ĸ�������Ӧ�Ĵ�д��ĸ��
	8.���������εĵ׺͸ߣ���Ϊint �ͣ���������������float�ͣ���
	9.�Լ�дһ���������ʽ�����������õ����������������
*/

	/*
		int a,b,c;
		printf("������������:");
		scanf("%d%d",&a,&b);
		c = abs(a-b);
		printf("��������ľ���ֵΪ:%d \n",c);
	*/
	
	/*
	int a;
	while( EOF == scanf("%d",&a) || a > 999 || a < 100 )
                printf("input integer more than 100 and less than 1000:");

        printf("��λ��%d��ʮλ��%d����λ��%d\n",a%10,a/10%10,a/100);
	*/
	/*
	char c;
	printf("������һ����д��ĸ��");
	scanf("%c",&c);
	if((c>='A')&&(c<='Z'))
	{
		printf("��Ӧdao�Ĵ�д��ĸ�ǣ�%c\n",c-'A'+'a');
	}
	else
	{
		printf("����Ĳ��Ǵ�д��ĸ\n");
	}
	*/
	
	/*
	int s,h;
	float area;
	scanf("%d %d", &s,&h);
	area = (float) s*h/2;
	printf("%f",area);
	*/
	
	/*
	double x=1,y=4,z=2;
	int a= (x += ++x *= z /= y, (x>y)?y:x , 100>>2);
	printf("%d", a);
	*/
	
	/*float f;
	double b;
	f = 0.987654321;
	b = 987654321.987654321;
	printf("%f\n", f);
	printf("%f", b);  */
	
	/*float a =0.987654321;
	float b =0.987654322;
	cout<< a << b<<endl;
	if (a == b){
		cout<<"equal"<<endl;
	}
	else cout<<"unequal"<<endl;
	
	cout<<fabs(a-b);   */
	
/*	int value,x,y;
	value= (x=10,y=5,x+y);
	printf("%d\n",value); 
	
	value= x=10,y=5,x+y;
	printf("%d",value); */
	/*int a=65;
	printf("%c",a);    //�����A */
	/*int a = -5;
	unsigned int b=1;
	if(a+b>0) printf("yes");
	else printf("no"); */
	int length = 100/200;
	int len = 1.0/2.0;
	cout<<len;
} 

 
