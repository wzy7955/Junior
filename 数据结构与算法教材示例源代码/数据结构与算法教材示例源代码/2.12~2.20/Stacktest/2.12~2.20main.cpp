#include<iostream>
//#include "ArrayStack.h"
//#include "LinkStack.h"
//#include "ArrayQueue.h"
//#include "LinkQueue.h"
using namespace std;
/*  �׳˺�������
long factorial(long n)
	{
	    if(n <= 0)
		    return 1;
    	return n * factorial(n-1);
	}
*/
int main()
{
	/*
	// 2.12-2.14����
    ArrayStack<int>* s = new ArrayStack<int>(3);
	int a=0;
  
    cout<<"------Test for ArrayStack-------"<<endl;  
    
    s->Push(1);
	s->Push(2);
	s->Push(3);
	//s->Push(4);  // ջ�����
	if(s->Top(a))
		cout << a << endl;
	if(s->Pop(a))
		cout << a << endl;
	s->Clear();
	if(s->Top(a))
		cout << a << endl;
	*/
    /*
	// 2.15����
    LinkStack<int>* s = new LinkStack<int>(3);
	int a=0;
  
    cout<<"------Test for LinkStack-------"<<endl;  
    
    s->Push(1);
	s->Push(2);
	s->Push(3);
	//s->Push(4);  // ջ�����
	if(s->Top(a))
		cout << a << endl;
	if(s->Pop(a))
		cout << a << endl;
	s->Clear();
	if(s->Top(a))
		cout << a << endl;
    */
    /*
	// 2.16-2.17����
	cout<<"------Test for Factorial-------"<<endl;  
  	cout << factorial(4) << endl;
	return 0;
	*/

	/*
	// 2.18-2.19����
    ArrayQueue<int>* q = new ArrayQueue<int>(3);
	int i=0;
  
    cout<<"------Test for ArrayQueue-------"<<endl;  
    
    q->EnQueue(1);
	q->EnQueue(2);
	q->EnQueue(3);
	q->EnQueue(4);  //�������������
	if(q->GetFront(i))
		cout << i << endl;
	if(q->DeQueue(i))
		cout << i << endl;
	q->Clear();
	if(q->GetFront(i))
		cout << i << endl;
    */

    /*
	// 2.20����
    LinkQueue<int>* q = new LinkQueue<int>(3);
	int i=0;
  
    cout<<"------Test for LinkQueue-------"<<endl;  
    
    q->EnQueue(1);
	q->EnQueue(2);
	q->EnQueue(3);
	if(q->GetFront(i))
		cout << i << endl;
	if(q->DeQueue(i))
		cout << i << endl;
	q->Clear();
	if(q->GetFront(i))
		cout << i << endl;
    */


	return 0;
	  
}
