#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

int n,m,p,lie[20];

using std::string;

struct node
{
	string name;
	int P[20+1];
	int NotP[20+1];
	int day[7+1];
	int Me;
	int NotMe;
}student[20+1];

int IsHe(int k,int g)
{
	int i;
	for(i=1;i<=m;i++)
		if(i!=g&&student[k].P[i]==1)
			return 0;
	if(student[k].P[g]==1)
		return 1;
	return -1;
}

int NotHe(int k,int g)
{
	int i;
	if(student[k].NotP[g]==1)
		return 0;
	for(i=1;i<=m;i++)
		if(i!=g&&student[k].NotP[i]==1)
			return 1;
	return -1;
}

int Today(int k,int day)
{
	for(int i=1;i<=7;i++)
		if(i!=day&&student[k].day[i]==1)
			return 0;
	if(student[k].day[day]==1)
		return 1;
	return -1;
}

int err(int k)
{
	int Num=0,i;
	for(i=1;i<=m;i++)
		if(student[k].P[i]==1)
			Num++;
	if(Num>1)
		return 0;
	Num=0;
	for(i=1;i<=7;i++)
		if(student[k].day[i]==1)
			Num++;
	if(Num>1)
		return 0;
	return 1;
}

int judge(int g,int day)
{
	int j,k,lieNum;
	memset(lie,0,sizeof(lie));
	for(k=1;k<=m;k++)
	{
		if(err(k)==0)
		{
			if(lie[k]==1)
				return 0;
			else
				lie[k]=-1;
		}
		if(student[k].Me==1&&k==g)
		{
			if(lie[k]==-1)
				return 0;
			else
				lie[k]=1;
		}
		if(student[k].NotMe==1&&k==g)
		{
			if(lie[k]==1)
				return 0;
			else
				lie[k]=-1;
		}
		if(student[k].Me==1&&k!=g)
		{
			if(lie[k]==1)
				return 0;
			else
				lie[k]=-1;
		}
		if(student[k].NotMe==1&&k!=g)
		{
			if(lie[k]==-1)
				return 0;
			else
				lie[k]=1;
		}
		if(student[k].P[g]==1)
		{
			if(lie[k]==-1)
				return 0;
			else
				lie[k]=1;
		}
		if(student[k].NotP[g]==1)
		{
			if(lie[k]==1)
				return 0;
			else
				lie[k]=-1;
		}
		if(IsHe(k,g)==0)
		{
			if(lie[k]==1)
				return 0;
			else
				lie[k]=-1;
		}
		if(NotHe(k,g)==1)
		{
			if(lie[k]==-1)
				return 0;
			else
				lie[k]=1;
		}
		if(Today(k,day)==0)
		{
			if(lie[k]==1)
				return 0;
			else
				lie[k]=-1;
		}
		if(Today(k,day)==1)
		{
			if(lie[k]==-1)
				return 0;
			else
				lie[k]=1;
		}
	}
	lieNum=0;
	for(j=1;j<=m;j++)
		if(lie[j]==-1)
			lieNum++;
	if(lieNum>n)
		return 0;
	lieNum=0;
	for(j=1;j<=m;j++)
		if(lie[j]==1)
			lieNum++;
	if(lieNum>m-n)
		return 0;
	return 1;
}

int main()
{
	int i,j,index,BadManNum=0;
	string temp,BadMan;
	char word[250];
	std::cin>>m>>n>>p;
	for(i=1;i<=m;i++)
		std::cin>>student[i].name;
	gets(word);
	for(i=1;i<=p;i++)
	{
		string temp=gets(word);
		int pos=temp.find(":",0);
		string tl(temp,0,pos);
		for(j=1;j<=m;j++)
			if(student[j].name==tl)
				index=j;
		temp.erase(0,pos+2);
		if(temp=="I am guilty.")
			student[index].Me=1;
		else if(temp=="I am not guilty.")
			student[index].NotMe=1;
		else if(temp=="Today is Monday.")
			student[index].day[1]=1;
		else if(temp=="Today is Tuesday.")
			student[index].day[2]=1;
		else if(temp=="Today is Wednesday.")
			student[index].day[3]=1;
		else if(temp=="Today is Thursday.")
			student[index].day[4]=1;
		else if(temp=="Today is Friday.")
			student[index].day[5]=1;
		else if(temp=="Today is Saturday.")
			student[index].day[6]=1;
		else if(temp=="Today is Sunday.")
			student[index].day[7]=1;
		else
		{
			for(j=1;j<=m;j++)
			{
				tl=student[j].name+" is guilty.";
				if(temp==tl)
					student[index].P[j]=1;
			}
			for(j=1;j<=m;j++)
			{
				tl=student[j].name+" is not guilty.";
				if(temp==tl)
					student[index].NotP[j]=1;
			}
		}
	}
	for(i=1;i<=m;i++)
		for(j=1;j<=7;j++)
		{
			if(judge(i,j)==0)
				continue;
			else if(judge(i,j)==1)
			{
				if(BadMan!=student[i].name)
					BadManNum++;
				BadMan=student[i].name;
			}
		}
	if(BadManNum==1)
		std::cout<<BadMan<<std::endl;
	else if(BadManNum>1)
		std::cout<<"Cannot Determine"<<std::endl;
	else
		std::cout<<"Impossible"<<std::endl;
	return 0;
}
