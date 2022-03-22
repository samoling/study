#include<iostream>
#include<assert.h>
using namespace std;
typedef int ElemType;
typedef struct Node
{
	ElemType data;      //������
	struct Node* prio;  //ǰ�����ָ����
	struct Node* next;  //��̽��ָ����
}Node, * PNode;

//˫�������ṹ
typedef struct List
{
	PNode first; //ָ��ͷ���
	PNode last; //ָ��β���
	int   size; //������Ч������
}List;

//��ȡ���
Node* getnode(ElemType n)
{
	//������ռ�
	Node* p = new Node;
	assert(p != nullptr);
	//Ϊ����������
	p->data = n;
	p->next = p->prio = nullptr;
	return p;
}

//��ʼ��˫����
void createList(List* list)
{
	//����ͷ���
	Node* p = new Node;
	assert(p != nullptr);
	//��ʼ��ʱ������ͷָ���βָ�붼ָ��ͷ���
	list->first = list->last = p;
	//ͷ����ǰ��ָ����ͺ��ָ�����ȸ�ֵΪ��
	list->last->next = nullptr;
	list->first->prio = nullptr;
	//��ʱ��û����Ч���
	list->size = 0;
}

//β������
void pushback(List* list, ElemType x)
{
	//��ȡҪ�������Ч���
	Node* p = getnode(x);
	//�ý����ǰ����㽨������
	p->prio = list->last;
	//ǰ�������ý�㽨������
	list->last->next = p;
	//���¹�������βָ�����ָ��
	list->last = p;
	//������Ч�����
	list->size++;
}

//ͷ��
void pushfront(List* list, ElemType x)
{
	//��ȡͷ��Ľ��
	Node* p = getnode(x);
	//������ǵ�һ����Ч���
	if (list->first == list->last)
	{
		//s->prio = list->first;
		//list->first->next = s;
		list->last = p;//���Ĺ�����βָ��ָ��
	}
	else //������ǵ�һ����Ч���
	{
		//���ò�����ĺ��ָ��
		p->next = list->first->next;
		//������������Ϊ��һ����ǰ��
		p->next->prio = p;
	}
	//���ò������ǰ��
	p->prio = list->first;
	//������������Ϊͷ���ĺ��
	list->first->next =p;
	//������Ч�����
	list->size++;
}
//�鿴˫�����ڵ���������
void showlist(List* list)
{
	//ָ���һ����Ч���
	Node* p = list->first->next;
	cout << "˫����洢������Ϊ��" << endl;
	while (p != nullptr)//��ÿ����Ч����ڵ��������
	{
		cout << p->data<<"    ";
		p = p->next;
	}
	cout << endl;
}
//βɾ
void popback(List* list)
{
	//���û����Ч�������ɾ��
	if (list->size == 0)
		return;
	//����ɾ������ǰ�����
	Node* p = list->first;
	while (p->next != list->last)
		p = p->next;
	//ɾ�����
	delete list->last;
	//���¹������βָ��ָ��
	list->last = p;
	//��β���ĺ������Ϊ��
	list->last->next =nullptr;
	//������Ч�����
	list->size--;
}

//ͷɾ
void popfront(List* list)
{
	//���û����Ч�������ɾ��
	if (list->size == 0)
		return;
	//ָ��Ҫɾ�����
	Node* p = list->first->next;
	//��������������һ����Ч��㣬��Ҫ���Ĺ�����βָ��ָ��
	if (list->first->next == list->last)
	{
		list->last = list->first;
		list->last->next = nullptr;
	}
	else //����������һ����Ч���
	{
		//������һ������ǰ��ָ��
		p->next->prio = list->first;
		//����ͷ���ĺ��ָ��
		list->first->next = p->next;
	}
	//�Ƿ���ռ�
	delete p;
	//������Ч�����
	list->size--;
}
//��ֵ���루��ǰ˫�����Ѿ�����
void insertval(List* list, ElemType x)
{
	//���Ҳ������ǰһ���
	Node* p = list->first;
	while (p->next != nullptr && p->next->data < x)
		p = p->next;
	//�����������ͷ���
	if (p->next ==nullptr)
	{
		pushback(list, x);//����β��
	}
	else //�������ͷ���
	{
		//��ȡ������
		Node* q = getnode(x);
		//���ò�����ĺ��
		q->next = p->next;
		//������������Ϊ��һ������ǰ��
		q->next->prio = q;
		//���ò������ǰ��
		q->prio = p;
		//������������Ϊ��һ���ĺ��
		p->next = q;
		//������Ч�����
		list->size++;
	}
}

//����
Node* find(List* list, ElemType key)
{
	//ָ���һ����Ч���
	Node* p = list->first->next;
	//���û���ҵ�����Ч��㻹û������ͼ������Ʋ���
	while (p != nullptr && p->data != key)
		p = p->next;
	return p;
}
//����Ч������
int  length(List* list)
{
	return list->size;
}

//ɾ���ض�ֵ�Ľ��
void deleteval(List* list, ElemType key)
{
	//���û����Ч��㣬������ɾ��
	if (list->size == 0)
		return;
	//����Ҫɾ�����
	Node* p = find(list, key);
	if (p == nullptr) //���û���ҵ��˳�
	{
		cout << "Ҫɾ����ֵ������." << endl;
		return;
	}

	if (p == list->last) //����ý����β��㣬�����βɾ
	{
		list->last = p->prio;
		list->last->next = nullptr;
	}
	else //��ͨλ�õĽ��ֱ��ɾ��
	{
		//��Ҫɾ��������һ�������Ϊ�ý����һ����ǰ��
		p->next->prio = p->prio;
		//��Ҫɾ��������һ�������Ϊ�ý����һ���ĺ��
		p->prio->next = p->next;
	}
	//�ͷſռ�
	delete p;
	//������Ч�����
	list->size--;
}
//������С��������
void sort(List* list)
{
	//�����Ч������С�ڵ���һ����ô�Ͳ���Ҫ��������
	if (list->size == 0 || list->size == 1)
		return;
	//�Ͽ�˫����
	Node* p = list->first->next; //ָ��ǰһ��˫����Ŀǰֻ��һ����Ч��㣩
	Node* q = p->next;//ָ���һ����㣨���г���һ����Ч���֮���������Ч��㣩
	//��ʱ˫����Ĺ���������һ��˫��������βָ��ָ��
	list->last = p;
	list->last->next = nullptr;

	//���ڶ���˫�����л�������Ч��㣬��Ҫ����ȡ����������һ��˫������
	while (q != nullptr)
	{
		//ȡ���ڶ���˫�������Ч���
		p = q;
		q = q->next;

		//���Ҳ����λ��
		Node* p = list->first;
		while (p->next != nullptr && p->next->data < p->data)
			p = p->next;

		if (p->next == nullptr)//�������λ����β��������β��
		{
			//���ò�����ĺ�̽��Ϊ��
			p->next = nullptr;
			//���ò������ǰ�����Ϊ֮ǰ��β���
			p->prio = list->last;
			//���ò�����Ϊ֮ǰβ���ĺ�̽��
			list->last->next = p;
			//���¹�������β���ָ��
			list->last = p;
		}
		else //������м�λ�ò���
		{
			//���ò�����ĺ��
			p->next = p->next;
			//������������Ϊ����һ����ǰ�����
			p->next->prio = p;
			//���ò������ǰ�����
			p->prio = p;
			//������������Ϊ����һ���ĺ��
			p->next = p;
		}
	}
}
//����˫����
void resver(List* list)
{
	//�����Ч���ĸ���С����1����ô��������
	if (list->size == 0 || list->size == 1)
		return;
	//��˫������
	Node* p = list->first->next; //ָ��ǰһ��˫����Ŀǰֻ��һ����Ч��㣩
	Node* q = p->next;//ָ���һ����㣨���г���һ����Ч���֮���������Ч��㣩
	//��ʱ˫����Ĺ���������һ��˫��������βָ��ָ��
	list->last = p;
	list->last->next = nullptr;
	//���ڶ���˫�����л�������Ч��㣬��Ҫ����ȡ��ͷ�嵽��һ��˫������
	while (q != nullptr)
	{
		//ȡ���ڶ���˫�������Ч���
		p = q;
		q = q->next;
		//ͷ�嵽��һ��˫������
		p->next = list->first->next;
		p->next->prio = p;
		p->prio = list->first;
		list->first->next = p;
	}
}
//���������Ч���
void clear(List* list)
{
	//���û����Ч�������ɾ��
	if (list->size == 0)
		return;
	//�������Ч��㣬���Ͻ���ͷɾ��ֱ��ɾ�����
	Node* p = list->first->next;
	while (p != nullptr)
	{
		//���ɾ���������������һ����Ч���
		if (p == list->last)
		{
			//���ù������βָ��ָ��
			list->last = list->first;
			list->last->next = nullptr;
		}
		else//ͷɾ
		{
			//����ɾ�������һ����ǰ��Ϊͷ���
			p->next->prio = list->first;
			//����ͷ���ĺ��Ϊɾ��������һ���
			list->first->next = p->next;
		}
		//�ͷ��ڴ�ռ�
		free(p);
		//��ȡ��һ��Ч���
		p = list->first->next;
	}
	//������Ч�����
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
		cout << "[1] �������ݣ���̣�[2] �������ݣ�ǰ����  " << endl
			 << "[3] ������������    [4] ɾ�����һ�����  " << endl
			 << "[5] ɾ����һ�����  [6] ��������          " << endl
			 << "[7] ���ҽ������    [8] �鿴˫������    " << endl
			 << "[9] ɾ��Ŀ������    [10] ����˫����       " << endl
			 << "[11] ����˫����     [12] ���˫����       " << endl
			 << "[0] �˳� " << endl
			 << "��ѡ��:" << endl;
		cin >>x;
		if (x == 0)
			break;
		switch (x)
		{
		case 1:
			cout << "������Ҫ���������(-1����):" << endl;
			while (cin>>n, n != -1)
			{
				pushback(&mylist, n);
			}
			break;
		case 2:
			cout << "������Ҫ���������(-1����):" << endl;
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
			cout << "������Ҫ���������:" << endl;
			cin>>n;
			insertval(&mylist, n);
			break;
		case 7:
			cout << "������Ҫ���ҵ�����:" << endl;
			cin>>n;
			p = find(&mylist, n);
			if (p == NULL)
			{
				cout << "Ҫ���ҵ������������в�����." << endl;
			}
			break;
		case 8:
			cout << "������ĳ���Ϊ:" << length(&mylist) << endl;
			break;
		case 9:
			cout << "������Ҫɾ����ֵ:"<<endl;
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
			cout << "������������,����������." << endl;
			break;
		}
	}
	clear(&mylist);
}