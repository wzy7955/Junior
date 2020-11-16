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
	printf("输入行数");
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
		TODO:编写一个输出如下图形的题。（必做题）
       *
     *   *
    *     *
     *   *
       *
	*/
	
	
	/*int n,j,i;                            
    printf("输入图案上三角的高度n:");
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
		TODO:输入3个数，输出3个数中的最大者，输出3个数的平均值。
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
		printf("a,b,c3个数字的平均值：%d",average);
	*/
	
 /*	编写C程序, 输入a与b的数值，输出两数差的绝对值. 
	5.输入一个3位整数，分别按照字符型输出个位、十位、百位上的整数。
	7.输入小写字母，输出对应的大写字母。
	8.输入三角形的底和高（均为int 型），并求出其面积（float型）。
	9.自己写一个算术表达式，计算结果，用到所有算术运算符。
*/

	/*
		int a,b,c;
		printf("输入两个整数:");
		scanf("%d%d",&a,&b);
		c = abs(a-b);
		printf("两个数差的绝对值为:%d \n",c);
	*/
	
	/*
	int a;
	while( EOF == scanf("%d",&a) || a > 999 || a < 100 )
                printf("input integer more than 100 and less than 1000:");

        printf("个位：%d，十位：%d，百位：%d\n",a%10,a/10%10,a/100);
	*/
	/*
	char c;
	printf("请输入一个大写字母：");
	scanf("%c",&c);
	if((c>='A')&&(c<='Z'))
	{
		printf("对应dao的大写字母是：%c\n",c-'A'+'a');
	}
	else
	{
		printf("输入的不是大写字母\n");
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
	printf("%c",a);    //输出是A */
	/*int a = -5;
	unsigned int b=1;
	if(a+b>0) printf("yes");
	else printf("no"); */
	int length = 100/200;
	int len = 1.0/2.0;
	cout<<len;
} 

 
