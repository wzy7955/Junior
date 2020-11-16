#include <iostream>
using namespace std;

// 2.2
template <class T>
class List
{
	void Clear(); //�ÿ����Ա�
	bool IsEmpty(); //���Ա�Ϊ��ʱ,����true
	bool Append(const T value);	//�ڱ�β���Ԫ��value,��ĳ�������1
	bool Insert(const int p, const T value); //��λ��p����Ԫ��value,  ��ĳ�������1
	bool Delete(const int p); //ɾ��λ��p�ϵ�Ԫ��,��ĳ��ȼ�1
	bool GetValue(const int p, T& value); //��λ��p�ϵ�Ԫ��ֵ���ص�����value��
	bool SetValue(const int p, const T value); //��λ��p��Ԫ��ֵ�޸�Ϊvalue
	bool GetPos(int &p, const T value); //��ֵΪvalue��Ԫ�ص�λ�÷��ص�����p��
};

// 2.3
template <class T> //���Ա��Ԫ������ΪT
class ArrayList : public List<T> //����˳���ArrayList
{
	public: //˳�������㼯
		ArrayList(const int size) //����˳���,��Ϊ��󳤶�
		{
		    if(size < 1){ //llz
                cout << "Size must be greater than 0";
                throw -1;
		    }
			maxSize = size;
			arrayList = new T[maxSize];
			curLen = 0;
			position = 0;
		}

		~ArrayList() //��������,����ArrayList��ʵ��
		{
			delete [] arrayList;
		}

		void clear() //���˳���
		{
			delete [] arrayList;
			curLen = 0;
			position = 0;
			arrayList = new T[maxSize];
		}

		int Length(); //����˳����ȣ�llz
		bool Append(const T value); //�ڱ�β���Ԫ��value,��ĳ�������1
		bool Insert(const int p, const T value); //��λ��p����Ԫ��value,��ĳ�������1
		bool Delete(const int p); //ɾ��λ��p�ϵ�Ԫ��,��ĳ��ȼ�1
		bool GetValue(const int p, T& value); //��λ��p�ϵ�Ԫ��ֵ���ص�����value��
		bool SetValue(const int p, const T value); //��λ��p��Ԫ��ֵ�޸�Ϊvalue
		bool GetPos(int &p, const T value); //��ֵΪvalue��Ԫ�ص�λ�÷��ص�����p��

	private: //˽�б���
		T *arrayList; //�洢˳����ʵ��
		int maxSize; //˳���ʵ������󳤶�
		int curLen; //˳���ʵ���ĵ�ǰ����
		int position; //��ǰ����λ��
};

template<class T>
int ArrayList<T> :: Length(){ //����Arraylist����
    return curLen;
}

template<class T>
bool ArrayList<T> :: GetValue(const int p, T& value){
    if(p < 0 || p > curLen)
    {
        cout << "GetValue position is illegal" << endl;
        return false;
    }
    value = arrayList[p];
}

// 2.4
template <class T> //˳����Ԫ������ΪT
bool ArrayList<T> :: Insert(const int p, const T value)
{
	if(curLen >= maxSize) //���˳����Ƿ����
	{
		cout << "The List is overflow" << endl;
		return false;
	}

	if(p < 0 || p > curLen) //������λ���Ƿ�Ϸ�
	{
		cout << "Insertion point is illegal" << endl;
        return false; //llz
	}

	for(int i = curLen; i > p; i--)
	{
		arrayList[i] = arrayList[i-1]; //�ӱ�βcurLen-1������ƶ�һ��λ��ֱ������λ��p
	}
	arrayList[p] = value; //λ��p��������Ԫ��
	curLen++; //���ʵ�ʳ�������1
	return true;
}

// 2.5
template <class T> //˳����Ԫ������ΪT
bool ArrayList<T> :: Delete(const int p)
{
	if(curLen <= 0) //���˳����Ƿ�Ϊ��
	{
		cout << "No element to delete" << endl;
		return false;
	}

	if(p < 0 || p > curLen -1) //���ɾ��λ�õĺϷ���
	{
		cout << "Deletion is illegal" << endl;
		return false;
	}

	for(int i = p; i < curLen - 1; i++)
	{
		arrayList[i] = arrayList[i+1]; //��ɾ��λ��p��ʼÿ��Ԫ����ǰ�ƶ�һ��λ��ֱ����β
	}
	curLen--; //���ʵ�ʳ��ȼ�1
	return true;
}

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
    try{
        ArrayList<Student> l(10);
        l.Insert(0, s[0]);
        l.Insert(1, s[1]);
        l.Insert(2, s[2]);
        l.Delete(1);
        for(int i = 0; i < l.Length(); i++){
            Student stu;
            l.GetValue(i, stu);
            cout << stu;
        }
    }catch(int e){

    }
    return 0;
}
