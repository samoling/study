#include<iostream>
#include<assert.h>
using namespace std;
typedef int ElemType;
typedef struct Node
{
	ElemType data;      //数据域
	struct Node* prio;  //前驱结点指针域
	struct Node* next;  //后继结点指针域
}Node, * PNode;

//双链表管理结构
typedef struct List
{
	PNode first; //指向头结点
	PNode last; //指向尾结点
	int   size; //保存有效结点个数
}List;

//获取结点
Node* getnode(ElemType n)
{
	//申请结点空间
	Node* p = new Node;
	assert(p != nullptr);
	//为结点添加数据
	p->data = n;
	p->next = p->prio = nullptr;
	return p;
}

//初始化双链表
void createList(List* list)
{
	//申请头结点
	Node* p = new Node;
	assert(p != nullptr);
	//初始化时管理结点头指针和尾指针都指向头结点
	list->first = list->last = p;
	//头结点的前驱指针域和后继指针域都先赋值为空
	list->last->next = nullptr;
	list->first->prio = nullptr;
	//此时还没有有效结点
	list->size = 0;
}

//尾部插入
void pushback(List* list, ElemType x)
{
	//获取要插入的有效结点
	Node* p = getnode(x);
	//该结点与前驱结点建立连接
	p->prio = list->last;
	//前驱结点与该结点建立连接
	list->last->next = p;
	//更新管理结点中尾指针域的指向
	list->last = p;
	//更新有效结点数
	list->size++;
}

//头插
void pushfront(List* list, ElemType x)
{
	//获取头插的结点
	Node* p = getnode(x);
	//如果这是第一个有效结点
	if (list->first == list->last)
	{
		//s->prio = list->first;
		//list->first->next = s;
		list->last = p;//更改管理结点尾指针指向
	}
	else //如果不是第一个有效结点
	{
		//设置插入结点的后继指向
		p->next = list->first->next;
		//将插入结点设置为下一结点的前驱
		p->next->prio = p;
	}
	//设置插入结点的前驱
	p->prio = list->first;
	//将插入结点设置为头结点的后继
	list->first->next =p;
	//更新有效结点数
	list->size++;
}
//查看双链表内的所以数据
void showlist(List* list)
{
	//指向第一个有效结点
	Node* p = list->first->next;
	cout << "双链表存储的数据为：" << endl;
	while (p != nullptr)//将每个有效结点内的数据输出
	{
		cout << p->data<<"    ";
		p = p->next;
	}
	cout << endl;
}
//尾删
void popback(List* list)
{
	//如果没有有效结点无需删除
	if (list->size == 0)
		return;
	//查找删除结点的前驱结点
	Node* p = list->first;
	while (p->next != list->last)
		p = p->next;
	//删除结点
	delete list->last;
	//更新管理结点的尾指针指向
	list->last = p;
	//将尾结点的后继设置为空
	list->last->next =nullptr;
	//更新有效结点数
	list->size--;
}

//头删
void popfront(List* list)
{
	//如果没有有效结点无需删除
	if (list->size == 0)
		return;
	//指向要删除结点
	Node* p = list->first->next;
	//如果这个结点是最后一个有效结点，需要更改管理结点尾指针指向
	if (list->first->next == list->last)
	{
		list->last = list->first;
		list->last->next = nullptr;
	}
	else //如果不是最后一个有效结点
	{
		//更改下一个结点的前驱指向
		p->next->prio = list->first;
		//更改头结点的后继指向
		list->first->next = p->next;
	}
	//是否结点空间
	delete p;
	//更新有效结点数
	list->size--;
}
//按值插入（当前双链表已经有序）
void insertval(List* list, ElemType x)
{
	//查找插入结点的前一结点
	Node* p = list->first;
	while (p->next != nullptr && p->next->data < x)
		p = p->next;
	//如果这个结点是头结点
	if (p->next ==nullptr)
	{
		pushback(list, x);//进行尾插
	}
	else //如果不是头结点
	{
		//获取插入结点
		Node* q = getnode(x);
		//设置插入结点的后继
		q->next = p->next;
		//将插入结点设置为下一个结点的前驱
		q->next->prio = q;
		//设置插入结点的前驱
		q->prio = p;
		//将插入结点设置为上一结点的后继
		p->next = q;
		//更改有效结点数
		list->size++;
	}
}

//查找
Node* find(List* list, ElemType key)
{
	//指向第一个有效结点
	Node* p = list->first->next;
	//如果没有找到且有效结点还没遍历完就继续下移查找
	while (p != nullptr && p->data != key)
		p = p->next;
	return p;
}
//求有效结点个数
int  length(List* list)
{
	return list->size;
}

//删除特定值的结点
void deleteval(List* list, ElemType key)
{
	//如果没有有效结点，不进行删除
	if (list->size == 0)
		return;
	//查找要删除结点
	Node* p = find(list, key);
	if (p == nullptr) //如果没有找到退出
	{
		cout << "要删除的值不存在." << endl;
		return;
	}

	if (p == list->last) //如果该结点是尾结点，则进行尾删
	{
		list->last = p->prio;
		list->last->next = nullptr;
	}
	else //普通位置的结点直接删除
	{
		//将要删除结点的上一结点设置为该结点下一结点的前驱
		p->next->prio = p->prio;
		//将要删除结点的下一结点设置为该结点上一结点的后继
		p->prio->next = p->next;
	}
	//释放空间
	delete p;
	//更新有效结点数
	list->size--;
}
//排序（由小到大排序）
void sort(List* list)
{
	//如果有效结点个数小于等于一个那么就不需要进行排序
	if (list->size == 0 || list->size == 1)
		return;
	//断开双链表
	Node* p = list->first->next; //指向前一个双链表（目前只含一个有效结点）
	Node* q = p->next;//指向第一个结点（含有除第一个有效结点之外的其余有效结点）
	//此时双链表的管理结点管理第一条双链表，设置尾指针指向
	list->last = p;
	list->last->next = nullptr;

	//当第二个双链表中还包含有效结点，需要继续取出按序插入第一个双链表中
	while (q != nullptr)
	{
		//取出第二个双链表的有效结点
		p = q;
		q = q->next;

		//查找插入的位置
		Node* p = list->first;
		while (p->next != nullptr && p->next->data < p->data)
			p = p->next;

		if (p->next == nullptr)//如果插入位置在尾部，进行尾插
		{
			//设置插入结点的后继结点为空
			p->next = nullptr;
			//设置插入结点的前驱结点为之前的尾结点
			p->prio = list->last;
			//设置插入结点为之前尾结点的后继结点
			list->last->next = p;
			//更新管理结点中尾结点指向
			list->last = p;
		}
		else //如果在中间位置插入
		{
			//设置插入结点的后继
			p->next = p->next;
			//将插入结点设置为其下一结点的前驱结点
			p->next->prio = p;
			//设置插入结点的前驱结点
			p->prio = p;
			//将插入结点设置为其上一结点的后继
			p->next = p;
		}
	}
}
//逆置双链表
void resver(List* list)
{
	//如果有效结点的个数小等于1，那么无需逆置
	if (list->size == 0 || list->size == 1)
		return;
	//将双链表拆分
	Node* p = list->first->next; //指向前一个双链表（目前只含一个有效结点）
	Node* q = p->next;//指向第一个结点（含有除第一个有效结点之外的其余有效结点）
	//此时双链表的管理结点管理第一条双链表，设置尾指针指向
	list->last = p;
	list->last->next = nullptr;
	//当第二个双链表中还包含有效结点，需要继续取出头插到第一个双链表中
	while (q != nullptr)
	{
		//取出第二个双链表的有效结点
		p = q;
		q = q->next;
		//头插到第一个双链表中
		p->next = list->first->next;
		p->next->prio = p;
		p->prio = list->first;
		list->first->next = p;
	}
}
//清除所有有效结点
void clear(List* list)
{
	//如果没有有效结点无需删除
	if (list->size == 0)
		return;
	//如果有有效结点，不断进行头删，直到删除完成
	Node* p = list->first->next;
	while (p != nullptr)
	{
		//如果删除的这个结点是最后一个有效结点
		if (p == list->last)
		{
			//设置管理结点的尾指针指向
			list->last = list->first;
			list->last->next = nullptr;
		}
		else//头删
		{
			//设置删除结点下一结点的前驱为头结点
			p->next->prio = list->first;
			//设置头结点的后继为删除结点的下一结点
			list->first->next = p->next;
		}
		//释放内存空间
		free(p);
		//获取下一有效结点
		p = list->first->next;
	}
	//更新有效结点数
	list->size = 0;
}
void main()
{
	List mylist;
	createList(&mylist);
	ElemType n;
	Node* p = nullptr;
	int x = 1;
	while (x)
	{
		cout << "[1] 增加数据（后继）[2] 增加数据（前驱）  " << endl
			 << "[3] 遍历所有数据    [4] 删除最后一个结点  " << endl
			 << "[5] 删除第一个结点  [6] 插入数据          " << endl
			 << "[7] 查找结点数据    [8] 查看双链表长度    " << endl
			 << "[9] 删除目标数据    [10] 排序双链表       " << endl
			 << "[11] 逆置双链表     [12] 清除双链表       " << endl
			 << "[0] 退出 " << endl
			 << "请选择:" << endl;
		cin >>x;
		if (x == 0)
			break;
		switch (x)
		{
		case 1:
			cout << "请输入要插入的数据(-1结束):" << endl;
			while (cin>>n, n != -1)
			{
				pushback(&mylist, n);
			}
			break;
		case 2:
			cout << "请输入要插入的数据(-1结束):" << endl;
			while (cin>>n, n != -1)
			{
				pushfront(&mylist, n);
			}
			break;
		case 3:
			showlist(&mylist);
			break;
		case 4:
			popback(&mylist);
			break;
		case 5:
			popfront(&mylist);
			break;
		case 6:
			cout << "请输入要插入的数据:" << endl;
			cin>>n;
			insertval(&mylist, n);
			break;
		case 7:
			cout << "请输入要查找的数据:" << endl;
			cin>>n;
			p = find(&mylist, n);
			if (p == NULL)
			{
				cout << "要查找的数据在链表中不存在." << endl;
			}
			break;
		case 8:
			cout << "单链表的长度为:" << length(&mylist) << endl;
			break;
		case 9:
			cout << "请输入要删除的值:"<<endl;
			cin>>n;
			deleteval(&mylist, n);
			break;
		case 10:
			sort(&mylist);
			break;
		case 11:
			resver(&mylist);
			break;
		case 12:
			clear(&mylist);
			break;
		default:
			cout << "输入的命令错误,请重新输入." << endl;
			break;
		}
	}
	clear(&mylist);
}