#include<iostream>
using namespace std;
int size = 0;
typedef struct LNode {
    int data;
    struct LNode* next;
}LNode, * LinkList;
//遍历操作
void PrintList(LinkList L) {
    LNode* p = L->next;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

//头插法建立单链表
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

//尾插法建立单链表
LinkList TailInsert(LinkList& L) {
    L = new LNode;
    L->next = nullptr;
    LNode* p1, * p2 = L;
    int tem;
    cout << "输入9999终止输入!" << endl;
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

//按值查找：查找x在L中的位置
int LocateElem(LinkList L, int x) {
    LNode* p = L->next;
    int i = 1;
    while (p && p->data != x) {
        p = p->next;
        i++;
    }
    return i;
}

//按位查找：查找在单链表L中第i个位置的结点
LNode* GetElem(LinkList L, int i) {
    int j = 1;
    LNode* p = L->next;
    if (i == 0)return L;
    if (i < 1)return NULL;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    return p; //如果i大于表长，p=NULL,直接返回p即可
}

//将x插入到单链表L的第i个位置上
void Insert(LinkList& L, int i, int x) {
    LNode* p = GetElem(L, i - 1);
    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->data = x;
    s->next = p->next;
    p->next = s;
    ::size++;
}

//删除操作:将单链表中的第i个结点删除
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
    //初始化，尾插法建立单链表
    LinkList L = TailInsert(L);
    //插入：在第x个位置插入结点，数据为m
    int x; int m;  
    cout << "请输入需要插入的数据：" << endl;
    do {
        cout<< "位置："; cin >> x;
        if (x > ::size + 1)
        {
            cout << "请输入正确的位置。当前链表共有" << ::size << "个数据。" << endl;
        }
        else {
            break;
        }
    } while (true);
    cout << "数据："; cin >> m;
    Insert(L, x, m);
    cout << "插入数据后的链表为：";
    PrintList(L);
    //删除：删除第n个结点
    int n;
    cout << "请输入需要删除的结点的位置：";
    do {
        cin >> n;
        if (n > ::size)
            cout << "请输入正确的位置。当前链表共有" << ::size << "个数据。" << endl;
        else break;
    } while (true);
    Delete(L, n);
    cout << "删除结点后的链表为：";
    PrintList(L);
    //按位查找：查找第n个结点
    cout << "请输入需要查找的结点位置：" << endl;
    do {
        cin >> n;
        if (n > ::size)
            cout << "请输入正确的位置。当前链表共有" << ::size << "个数据。" << endl;
        else break;
    } while (true);
    LNode* p = GetElem(L, n);
    cout << "第"<<n<<"个结点的值为：" << p->data << endl;
    //按值查找：查找数据域为x的结点的指针
    cout << "请输入需要查找的数据：" << endl;
    cin >> x;
    int q = LocateElem(L, x);
        cout << "该数据在链表第" << q << "个" << endl;
    //输出单链表的长度
    cout << "单链表的长度：" << ::size<< endl;
    return 0;
}