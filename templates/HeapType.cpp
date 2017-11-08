#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn=1e6+5;

class HeapType
{
	private:
		int data[maxn],size;
	public:
		void push(int x)
		{
			data[++size]=x;
			int now=size;
			while(now!=1&&data[now>>1]>data[now])
			{
				std::swap(data[now>>1],data[now]);
				now>>=1;
			}
		}
		
		int top()
		{
			return data[1];
		}
		
		void pop()
		{
			data[1]=data[size--];
			if(!size)
				return;
			int tmp,tmp2,now=1;
			while(1)
			{
				tmp=0;
				tmp2=data[now];
				if((now<<1)<=size&&data[now<<1]<tmp2)
				{
					tmp2=data[now<<1];
					tmp=(now<<1);
				}
				if((now<<1|1)<=size&&data[now<<1|1]<tmp2)
				{
					tmp2=data[now<<1|1];
					tmp=(now<<1|1);
				}
				if(!tmp)
					return;
				std::swap(data[now],data[tmp]);
				now=tmp;
			}
		}
};

class HeapType heap;

int n;

inline void read(int &now)
{
	char Cget;
	now=0;
	int if_z=1;
	while((Cget=getchar())>'9'||Cget<'0')
		if(Cget=='-')
			if_z=-1;
	while(Cget>='0'&&Cget<='9')
	{
		now=now*10+Cget-'0';
		Cget=getchar();
	}
	now*=if_z;
}

int main()
{
	read(n);
	for(int i=1,op,x;i<=n;i++)
	{
		read(op);
		if(op==1)
		{
			read(x);
			heap.push(x);
		}
		if(op==2)
			printf("%d\n",heap.top());
		if(op==3)
			heap.pop();
	}
	return 0;
}
