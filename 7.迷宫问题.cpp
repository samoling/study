#include <iostream>
using namespace std;
#define MaxSize 1000
#define M 8 
#define N 8
typedef struct {
	int i;
	int j;
	int di;
}Box;
typedef struct
{
	Box data[MaxSize];
	int top;
}StType;
int mg[M + 2][N + 2] = { {1,1,1,1,1,1,1,1,1,1},{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},{1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},{1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},{1,0,1,1,1,0,1,1,0,1},
	{1,1,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1}
};
void InitStack(StType *&st)
{
	st = new StType;
	st->top = -1;
}
void Push(StType *&st, Box& e)
{
	st->top++;
	st->data[st->top] = e;
}
bool StackEmpty(StType* st)
{
	return (st->top==-1);
}
void GetTop(StType* &st, Box& e)
{
	e = st->data[st->top];
}
void Pop(StType* &st, Box& e)
{
	e = st->data[st->top];
	st->top--;
}
void DestroyStack(StType* &st)
{
	delete st;
}
bool mgpath(int xi, int yi, int xe, int ye)
{	
	Box path[MaxSize], e;
	int i, j, di, il, jl, k;
	bool find;
	StType* st;
	InitStack(st);
	e.i = xi; e.j = yi; e.di = -1;
	Push(st, e);
	mg[xi][yi] = -1;
	while (!StackEmpty(st))
	{
		GetTop(st, e);
		i = e.i; j = e.j; di = e.di;
		if (i == xe && j == ye)
		{
			cout << "一条迷宫路径如下：" << endl;
			k = 0;
			while (!StackEmpty(st))
			{
				Pop(st, e);
				path[k++] = e;
			}
			while (k >= 1)
			{
				k--;
				cout << "\t(" << path[k].i << "," << path[k].j << ")";
				if ((k + 2) % 5 == 0)
					cout << endl;
			}
			cout << endl;
			DestroyStack(st);
			return true;
		}
		find = false;
		while (di < 4 && !find)
		{
			di++;
			switch (di) {
			case 0:il = i - 1; jl = j; break;
			case 1:il = i; jl = j + 1; break;
			case 2:il = i + 1; jl = j; break;
			case 3:il = i; jl = j - 1; break;
			}
			if (mg[il][jl] == 0)find = true;
		}
		if (find)
		{
			st->data[st->top].di = di;
			e.i = il; e.j = jl; e.di = -1;
			Push(st, e);
			mg[il][jl] = -1;
		}
		else
		{
			Pop(st, e);
			mg[e.i][e.j] = 0;
		}
	}
	DestroyStack(st);
	return false;
}
void main()
{
	if (!mgpath(1, 1, M, N))
		cout << "该迷宫无解！" << endl;
}