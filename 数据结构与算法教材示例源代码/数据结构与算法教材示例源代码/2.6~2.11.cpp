#include <iostream>
using namespace std;

// 2.6
template<class T>
class LinkNode
{
	public:
		T data;	//������
		LinkNode<T>*link; //ָ����ָ��Ľ��
        LinkNode(){  //llz
        }
		LinkNode(const T&el, LinkNode<T>*ptr = 0){ //���캯��
			data=el;
			link=ptr;
        }
};

// 2.7
template<class T>
class LinkList
{
	private:
		LinkNode<T> *head, *tail; //��ͷ�ͱ�βָ��
		LinkNode<T> *prevPtr, *currPtr;	//��¼��ǰ����λ�õ�ָ�룬�ɲ����ɾ����������
		int position; //��ǰԪ���ڱ��е�λ����ţ��ɺ���resetʹ��
	public:
		LinkList();
		~LinkList();
		int getSize()const; //���������е�Ԫ�ظ���
		bool isEmpty()const; //�����Ƿ�Ϊ��
		void reset(int pos = 0); //��ʼ��ָ���λ�ã���һλ����λ����Ϊ0)
		void next(); //ʹָ���ƶ�����һ�����
		bool endOfList()const; //ָ���Ƿ�����β
		int currentPosition(void); //����ָ�뵱ǰ��λ��
		void insertHead(const T&item); //�ڱ�ͷ������
		void insertTail(const T&item); //�ڱ�β��ӽ��
		void insertAt(const T&item); //�ڵ�ǰ���֮ǰ������
		void insertAfter(const T&item);	//�ڵ�ǰ���֮�������
		T deleteHead(); //ɾ��ͷ���
		void deleteCurrent(); //ɾ����ǰ���
		T&data(); //���ضԵ�ǰ����Ա���ݵ�����
		const T&data()const; //���ضԵ�ǰ����Ա���ݵĳ�����
		void clear(); //��������ͷ����н����ڴ�ռ�
		LinkNode<T>* setPos(int pos); //����ָ��λ��pos��ָ��
		bool insertPos(const int i, const T value); //��ָ��λ�ò�����
		bool deletePos(const int i); //ɾ��ָ��λ�õĽ��
		void display(); //llz
};


template<class T>
LinkList<T> :: LinkList(){
    head = new LinkNode<T>();
    tail = new LinkNode<T>();
    prevPtr = new LinkNode<T>();
    currPtr = new LinkNode<T>();
    head->link = NULL;
    tail->link = NULL;
}

template<class T>
LinkList<T> :: ~LinkList(){
    LinkNode<T> *p;
    while(head!=NULL){
        p = head;
        head = p->link;
        delete p;
    }
    delete tail;
}


// 2.8
template<class T>
LinkNode<T> * LinkList<T>::setPos(int pos) //����ָ��λ��pos��ָ��
{
	if(pos == -1) //iΪ-1��λ��ͷ���
		return head;
	int count = 0;
	LinkNode<T> *p = head->link;
	while(p != NULL && count < pos)
	{
		p = p->link;
		count++;
	}
	return p; //ָ���i����㣬��������С��iʱ����NULL
}

// 2.9
template<class T>
bool LinkList<T>::insertPos(const int i, const T value)
{
	LinkNode<T> *p, *q; // q���²���Ľ�㣬llz
	if((p = setPos(i - 1)) == NULL) //p�ǵ�i������ǰ��
	{
		cout << "�������������" << endl;
		return false;
	}

	q = new LinkNode<T>(value, p->link);
	p->link = q;
	if(p == tail) //�ڱ�β���в������
		tail = q;
	return true;
}

// 2.10
template<class T>
bool LinkList<T>::deletePos(const int i)
{
	LinkNode<T> *p, *q;
	if((p = setPos(i - 1)) == NULL || p == tail) //��ɾ���㲻����
	{
		cout << "�Ƿ�ɾ����" << endl;
		return false;
	}

	q = p->link; //qΪ������ɾ����
	if(q == tail) //ɾ����Ϊ��β���޸�βָ��
	{
		tail = p;
		p->link = NULL;
		delete q;
	}
	else if(q != NULL) //ɾ�����q�����޸�ָ��
	{
		p->link = q->link;
		delete q;
	}
	return true;
}


template<class T>
void LinkList<T> ::display(){
    LinkNode<T> *tmp = head->link;
    while(tmp!=NULL){
        cout << tmp->data << endl;
        tmp = tmp->link;
    }
    tmp = NULL;
}

// 2.11
template<class T>
class DLLNode
{
	public:
		T data; //������Ԫ�ص�����
		DLLNode<T> *next; //ָ���̽���ָ��
		DLLNode<T> *prev; //ָ��ǰ������ָ��

		DLLNode(const T info, DLLNode<T> *prevVal = NULL, DLLNode<T> *nextVal = NULL) //���캯��
		{
			data = info;
			prev = prevVal;
			next = nextVal;
		}
		DLLNode(DLLNode<T> *prevVal = NULL, DLLNode<T> *nextVal = NULL) //����ǰ��ָ��Ĺ��캯��
		{
			prev = prevVal;
			next = nextVal;
		}
};

//������
class Student{
    private:
        int id;
        string name;
    public:
        Student(){
        }
        Student(int id, string name){
            this->id = id;
            this->name = name;
        }
        int getId(){
            return this->id;
        }
        void setId(int id){
            this->id = id;
        }
        string getName(){
            return this->name;
        }
        void setName(string name){
            this->name = name;
        }
        friend ostream & operator<<(ostream &out, Student &obj){
            cout << "id: " << obj.id << " ,name: " << obj.name << endl;
            return out;
        }
};

//����������
int main(){
    Student s[5] = {Student(1, "zhangsan"), Student(2, "lisi"),
                    Student(3, "zhaowu"), Student(4, "wangliu"), Student(5, "wuqi")};
    LinkList<Student> *l = new LinkList<Student>();
    l->insertPos(0, s[0]);
    l->insertPos(1, s[1]);
    l->deletePos(0);
    l->display();
    return 0;
}
