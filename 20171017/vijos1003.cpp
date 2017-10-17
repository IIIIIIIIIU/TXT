#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef long long ll;

ll check,result_t,final,num[50],op[50];

ll power(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res*=a;
		a*=a,b>>=1;
	}
	return res;
}

void cul(int p,int op)
{
	if(op==0) num[p-1]=num[p-1]+num[p];
	if(op==1) num[p-1]=num[p-1]-num[p];
	if(op==2) num[p-1]=num[p-1]*num[p];
	if(op==5) num[p-1]=power(num[p-1],num[p]);
	
}

using std::string;

long long result(string str)
{
	int op_nxt,len=str.length(),p=-1,q=-1;
	ll num_nxt=0;
	for(int i=0;i<len;i++)
	{
		if(str[i]=='a')
			num[++p]=check;
		else if(str[i]>='0'&&str[i]<='9')
			num_nxt=num_nxt*10+(str[i]-'0');
		else if(str[i]!=' ')
		{
			if(num_nxt!=0)
			{
				num[++p]=num_nxt;
				num_nxt=0;
			}
			if(str[i]=='+') op_nxt=0;
			if(str[i]=='-') op_nxt=1;
			if(str[i]=='*') op_nxt=2;
			if(str[i]=='^') op_nxt=5;
			if(str[i]=='(') op_nxt=6;
			if(str[i]==')') op_nxt=7;
			if(op_nxt==6)
				op[++q]=op_nxt;
			else if(op_nxt==7)
				while(q>=0&&op[q--]!=6)
					cul(p--,op[q+1]);
			else
			{
				while(q>=0&&op[q]<=5&&op[q]/2>=op_nxt/2)
					cul(p--,op[q--]);
				op[++q]=op_nxt;
			}
		}
	}
	if(num_nxt!=0)
	{
		num[++p]=num_nxt;
		num_nxt=0;
	}
	while(q>=0)
		cul(p--,op[q--]);
	return num[0];
}

int main()
{
	string str1,str2;
	int n;
	final=0;
	getline(std::cin,str1);
	std::cin>>n;
	getline(std::cin,str2);
	while(n--)
	{
		bool flag=true;
		getline(std::cin,str2);
		for(int i=10;i<=20;i++)
		{
			check=i;
			if(result(str1)!=result(str2))
			{
				flag=false;
				break;
			}
		}
		if(flag)
			std::cout<<(char)('A'+final);
			final++;
	}
	std::cout<<std::endl;
	return 0;
}
