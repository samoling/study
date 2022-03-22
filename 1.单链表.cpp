#include<iostream>
using namespace std;
int size = 0;
typedef struct LNode {
    int data;
    struct LNode* next;
}LNode, * LinkList;
//��������
void PrintList(LinkList L) {
    LNode* p = L->next;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

//ͷ�巨����������
LinkList HeadInsert(LinkList& L) {
    L = new LNode;
    L->next = NULL;
    int x;
    cin >> x;
    while (x != 9999) {
        LNode* s = new LNode;
        s->data = x;
        s->next = L->next;
        L->next = s;
        cin >> x;
    }
    return L;
}

//β�巨����������
LinkList TailInsert(LinkList& L) {
    L = new LNode;
    L->next = nullptr;
    LNode* p1, * p2 = L;
    int tem;
    cout << "����9999��ֹ����!" << endl;
    cin >> tem;
    while (tem != 9999) {
        ::size++;
        p1 =new LNode;
        p1->data = tem;
        p2->next = p1;
        p2 = p1;
        cin >> tem;
    }
    p2->next = nullptr;
    return L;
}

//��ֵ���ң�����x��L�е�λ��
int LocateElem(LinkList L, int x) {
    LNode* p = L->next;
    int i = 1;
    while (p && p->data != x) {
        p = p->next;
        i++;
    }
    return i;
}

//��λ���ң������ڵ�����L�е�i��λ�õĽ��
LNode* GetElem(LinkList L, int i) {
    int j = 1;
    LNode* p = L->next;
    if (i == 0)return L;
    if (i < 1)return NULL;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    return p; //���i���ڱ���p=NULL,ֱ�ӷ���p����
}

//��x���뵽������L�ĵ�i��λ����
void Insert(LinkList& L, int i, int x) {
    LNode* p = GetElem(L, i - 1);
    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->data = x;
    s->next = p->next;
    p->next = s;
    ::size++;
}

//ɾ������:���������еĵ�i�����ɾ��
void Delete(LinkList& L, int i) {
    if (i<1 || i>::size) {
        cout << "delete failed: index is wrong." << endl;
        return;
    }
    LNode* p = GetElem(L, i - 1);
    LNode* q = p->next;
    p->next = q->next;
    free(q);
    ::size--;
}


int main() {
    //��ʼ����β�巨����������
    LinkList L = TailInsert(L);
    //���룺�ڵ�x��λ�ò����㣬����Ϊm
    int x; int m;  
    cout << "��������Ҫ��������ݣ�" << endl;
    do {
        cout<< "λ�ã�"; cin >> x;
        if (x > ::size + 1)
        {
            cout << "��������ȷ��λ�á���ǰ������" << ::size << "�����ݡ�" << endl;
        }
        else {
            break;
        }
    } while (true);
    cout << "���ݣ�"; cin >> m;
    Insert(L, x, m);
    cout << "�������ݺ������Ϊ��";
    PrintList(L);
    //ɾ����ɾ����n�����
    int n;
    cout << "��������Ҫɾ���Ľ���λ�ã�";
    do {
        cin >> n;
        if (n > ::size)
            cout << "��������ȷ��λ�á���ǰ������" << ::size << "�����ݡ�" << endl;
        else break;
    } while (true);
    Delete(L, n);
    cout << "ɾ�����������Ϊ��";
    PrintList(L);
    //��λ���ң����ҵ�n�����
    cout << "��������Ҫ���ҵĽ��λ�ã�" << endl;
    do {
        cin >> n;
        if (n > ::size)
            cout << "��������ȷ��λ�á���ǰ������" << ::size << "�����ݡ�" << endl;
        else break;
    } while (true);
    LNode* p = GetElem(L, n);
    cout << "��"<<n<<"������ֵΪ��" << p->data << endl;
    //��ֵ���ң�����������Ϊx�Ľ���ָ��
    cout << "��������Ҫ���ҵ����ݣ�" << endl;
    cin >> x;
    int q = LocateElem(L, x);
        cout << "�������������" << q << "��" << endl;
    //���������ĳ���
    cout << "������ĳ��ȣ�" << ::size<< endl;
    return 0;
}