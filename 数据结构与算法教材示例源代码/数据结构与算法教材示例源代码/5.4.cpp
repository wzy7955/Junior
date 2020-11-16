#include <iostream>
#define EMPTY -1   //����ɾ����־
using namespace std;

template<class Key, class T> //KeyΪ�ؼ�������ͣ�TΪ�洢��HashTable�е�Ԫ�ص�����
class HashTable
{
private:
	T* HT;
	int maxSize;             //�洢���ݵ������� 
	int currentSize;         //�洢���ݵĵ�ǰ���� 
	int probe(Key k,int i) const{return k%maxSize+i;};
										//̽�麯����iΪ̽��Ĵ������
	int hash(Key k) const{return k%maxSize;};			//ɢ�к���
public:
	HashTable(int size)                                //���캯�� 
	{
		maxSize=size;
		currentSize=0;
		HT=new T[maxSize];
	}
	~HashTable(){delete []HT;}                   //�������� 
	bool hashInsert(const T& item)const ;	    //��������
	bool hashSearch(const Key& k);	            //��������
	bool hashDelete(const Key& k);				//ɾ������
	//bool empty();
	T * getHT(){return HT;}
};
template <class Key, class T>
bool HashTable<Key,T>::hashInsert(const T& item) const
{
	int flag=0;
	int home=0;									//�洢�ĳ�ʼ̽��λ��
	int i=0;									//̽������б��
	int pos=home=hash(item);
	while(HT[pos]!=EMPTY)                       //EMPTY��ɢ�б�ǰλ��Ϊ�յı�� 
	{
		if(HT[pos]==item){
			flag = 1;       	//�����ظ������ñ�� 
			break;
			}					       
		i++;
		pos=(probe(item,i))%maxSize;	//probe����̽�鲽��
	}
	if(flag == 1){
		cout<<"�������Ѵ��ڣ��������"<<endl;
	}
	else{	
	HT[pos]=item;                      //���±���λ����Ϣ 
	cout<<"λ���ǵ�"<<pos<<endl; 
	} 
	return true;
}
template <class Key, class T>
bool HashTable<Key,T>::hashSearch(const Key& k)
{
	int home=hash(k);
	int i=0;
	int pos=home;
	do
	{
		cout<<"���ڼ�����λ��Ϊ"<<pos<<endl; 
		if(HT[pos]==k)                 //��ǰλ�ô洢����Ϊ�������� 
			return true;
		i++;
		pos=(probe(k,i))%maxSize;   //����̽�ⲽ������Ѱ�� 
	
	}while((HT[pos]!=EMPTY)&&(HT[pos]!=home));
	return false;
}
template <class Key, class T>
bool HashTable<Key,T>::hashDelete(const Key& k)
{
	int home=hash(k);       
	int i=0;
	int pos=home;
	do
	{
		if(HT[pos]==k)
		{	
			HT[pos]=EMPTY; 			
		    cout<<"ɾ���ɹ���"<<endl;
			return true;
		}
		else{
	     	i++;
	     	pos=(probe(k,i))%maxSize;
	    }
		
	}while(HT[pos]!=EMPTY);
	cout<<"����û�и����ݣ�"<<endl;
	return false;
}
int main()
{
    HashTable<int, int> ht(23);
    int *HT = ht.getHT();
	for(int i = 0;i < 23 ;i++){
		HT[i] = EMPTY;
	}
    cout<<"����10����"<<endl;
     int temp;
    for(int i=0;i<10;++i){
        cin>>temp;
        ht.hashInsert(temp);
    }
    
    cout<<"��Ҫɾ������"<<endl;
    int tar;
    cin>>tar;
    ht.hashDelete(tar);
    
    
    cout<<"��Ҫ���ҵ���"<<endl;
    int target;
    cin>>target;
    bool s=ht.hashSearch(target);
    if(s == 0)
     	cout<<"δ�ҵ����ݣ�"<<endl;
	else
		cout<<"�ҵ����ݣ�"<<target<<endl;

    return 0;
}


