#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

#define m 3  //B-���Ľ�
//#define KeyType int




template <class Key>
class BNode
{
public:
    Key key[m + 1]; // ����key[0]
    BNode<Key> *parent, *ptr[m + 1];
    string record[m + 1]; //�ڵ���
};


template <class Key>
class Result
{
public:
    BNode<Key> *r;           		// ָ���ҵ��Ľ��
    int i;                     	// ��¼����ؼ����ڽ���е�λ��
    bool flag;					// �Ƿ���ҵ��ؼ��ֵı�־
    Result(BNode<Key> * rr, int ii, int flagg)
    {
        r = rr;
        i = ii;
        flag = flagg;
    };
};

template<class Key>
class BTree
{
BNode<Key> *root;
public:

    //BTree();                  		// ���캯��
    //Result<Key> Search(const BTree<Key> &T, Key key);	// ��ѯ�ؼ���x���ڵĽ��
    //BNode<Key> *InsertBTree(Key x,BNode<Key>* p,int i); // ����ؼ���x
    void DeleteBTree(Key x);            		// ɾ���ؼ���x
    BNode<Key> * getroot(){return root;}
    int initTree()
    {
        root = NULL;
        return 0;
    };
    int destroyTree()
    {
        BTree<Key> T;
        T.root = root;
        if(root == NULL)
            return 0;
        for(int i = 0; i <= root->key[0]; i++)
        {
            T.destroyTree();
            root->ptr[i] = NULL;
        }
        delete root;
        return 0;
    };
    Result<Key> Search(Key key);
    int Insert(BNode<Key> *q, int i, Key key, BNode<Key> *ap, string rcd);
    int split(BNode<Key> *q, int s, BNode<Key> *ap);
    int NewRoot(BNode<Key> *q, Key key, BNode<Key> *ap, string rcd);
    int InsertBTree(Key key, BNode<Key>  *q, int i, string rcd);
    int traverse(const BNode<Key> *q);


};




/*template<class Key>
int BTree::destroyTree(BTree<Key> T){
    if(T==NULL)
        return 0;
    for(int i=0; i<=T.root->key[0]; i++){
        T.destroyTree((T.root)->ptr[i]);
        T.root->ptr[i] = NULL;
    }
    delete T;
    return 0;
}*/

/*template<class Key>
int Search<Key> BTree::(const BTree<Key> &T, Key K){
   int i=0,j;
   for(j=1;j<=T->key[0];j++)
       if(K >= T->key[j])
           i=j;
   return i;
}*/




// ��B-���ϲ���
template<class Key>
Result<Key> BTree<Key>::Search(const Key x)
{
    // ��m��B-���в��ҹؼ���x�����ؽ��Result������ҳɹ�����flag=1��ָ��r
// ָ��Ľ���еĵ�i���ؼ��־�������ؼ���x��������Ҳ��ɹ�����flag=0��
// ����x�Ĺؼ���Ӧ������ָ��r��ָ�Ľ���е�i���ؼ��ֺ͵�i+1���ؼ���֮��
    Result<Key> ret(NULL, 0, false);
    BNode<Key> *p = root;
    BNode<Key> *q = NULL;
    int i = 0;
    while (p && !ret.flag)
    {
        for(i = 1; i <= p->key[0]; i++)
        {
            //�ҵ������¼���ڽڵ�
            if(p->key[i] >= x) //��p->key[1��keynum]�в��ң�
                break;            //iʹ�ã�p->key[i]<=X<p-> key[i+1]
        }
        if(i > 0 && p->key[i] == x) //�ڽڵ��в��Ҹü�¼x����ؼ���
        {
            ret.flag = true;//���ҳɹ�
            ret.r = p;
            ret.i = i;
        }
        else
        {
            q = p;        //���Ҳ��ɹ�������x�Ĳ�����Ϣ
            p = p->ptr[i - 1];
            ret.r = q;
            ret.i = i;
        }
    }
    return ret;
}



// ��ʱ������ڵ��������ؼ��֣��������ڲ�����split����

template<class Key>
int BTree<Key>::Insert(BNode<Key> *q, int i, Key key, BNode<Key> *ap, string rcd)
{
    q->key[0]++;
    int j = q->key[0];
    for(; j > i + 1; j--)
    {
        q->key[j] = q->key[j - 1];
        q->ptr[j] = q->ptr[j - 1];
        q->record[j] = q->record[j - 1];
    }
    q->key[j] = key;
    q->ptr[j] = ap;
    q->record[j] = rcd;
    return 0;

}

// ���ˣ���һ���ؼ������з��ѳ�����
template<class Key>
int BTree<Key>::split(BNode<Key> *q, int s, BNode<Key> *ap)
{
    // cout << "s=" << s <<endl;

    BNode<Key> *b;
    ap = b;
//BNode<Key> *p = root;

    //ap = new BNode<int>;
    ap->key[0] = 0;
    root->key[0]--;
    ap->ptr[0] = root->ptr[s];
    if(ap->ptr[0] != NULL)
    {
        ap->ptr[0]->parent = ap;
    }
    ap->parent = root->parent;
    for(int i = s + 1, j = 1; i <= m; i++, j++)
    {
        ap->key[j] = root->key[i];
        ap->ptr[j] = root->ptr[i];
        ap->record[j] = root->record[i];
        ap->key[0] ++;
        root->key[0]--;
        if(ap->ptr[j] != NULL)
        {
            ap->ptr[j]->parent = ap;
        }
    }
    return 0;
}

template<class Key>
int BTree<Key>::NewRoot(BNode<Key> *q, Key key, BNode<Key> *ap, string rcd)
{
    BTree<Key> p;
    p.root = root;
    BTree<Key> T;
    //  T = new BTNode;
    T.root->key[0] = 1;
    T.root->key[1] = key;
    T.root->parent = NULL;
    T.root->ptr[0] = p.root;
    T.root->ptr[1] = ap;
    T.root->record[1] = rcd;
    if(T.root->ptr[0] != NULL)
    {
        T.root->ptr[0]->parent = T.root;
    }
    if(T.root->ptr[1] != NULL)
    {
        T.root->ptr[1]->parent = T.root;
    }
    return 0;
}

// ��B-�������
template<class Key>
int BTree<Key>::InsertBTree(Key key, BNode<Key> *q, int i, string rcd)
{
    Key x = key;
    BTree<Key> T;
    T.root = root;

    string y = rcd;
    BNode<Key> *ap = NULL;
    bool finished = false;
    Result<Key> ret(NULL, 0, false);
    while(q != NULL && !finished)
    {
        Insert(q, i, x, ap, rcd);
        if(q->key[0] < m)
            finished = true;
        else
        {
            int s = (m + 1) / 2; // ��ȡ��
            split(q, s, ap);
            x = q->key[s];
            y = q->record[s];
            q = q->parent;
            if(q != NULL)
                ret = T.Search(x);
        }
    }
    if(!finished)
    {
        NewRoot(T.root, x, ap, y);
    }
    return 0;
}

template<class Key>
int BTree<Key>::traverse(const BNode<Key> *q)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        //if(T->parent!=NULL){
        //    cout << endl << T->key[1] << "parent " << T->parent->key[1] << endl;
        //}
        if(root->ptr[0] != NULL)
        {
            //cout << T->key[1]<< "�ĵ�0����" << endl;
            traverse(root->ptr[0]);
        }
        for(int i = 1; i <= root->key[0]; i++)
        {
            cout << root->key[i] << " "; // visit
            if(root->ptr[i] != NULL)
            {
                //cout << T->key[i]<< "�ĵ�"<<i<<"����" << endl;
                traverse(root->ptr[i]);
            }
        }
        return 0;
    }
}

int main()
{
    BTree<int> T;
    T.initTree();
    int key;
    string str;
    while(cin >> key >> str && key != -1)
    {
        Result<int> s = T.Search(key);
        if(!s.flag)
        {
            cout << "���" << key << "  " << str << endl;
            cout << s.i << endl;
            T.InsertBTree(key, s.r, s.i, str);
            T.traverse(T.getroot());
            cout << endl;
        }
    }
    cout << "Now ��ʼ���ҹ���" << endl;
    while(cin >> key)
    {
        Result<int> s = T.Search(key);
        if(s.flag)
            cout << s.r->key[s.i] << " -> " << s.r->record[s.i] << endl;
        else
            cout << "Not Found! " << endl;
    }
    T.destroyTree();
    // system("pause");
    return 0;
}



