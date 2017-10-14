#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

int main()
{
	freopen("T2DATAfromBOOM.txt","r",stdin);
	freopen("route.cpp","w",stdout);
	puts("#include <cstdio>");
	puts("int ai[1005]={0");
	int tmp;
	for(int i=1;i<=1000;i++)
	{
		scanf("%d",&tmp);
		printf(",%d",tmp);
	}
	puts("};");
	puts("int main()");
	puts("{");
	puts("	int n;");
	puts("	std::cin>>n;");
	puts("	std::cout<<ai[n];");
	puts("	return 0");
	puts("}");
	return 0;
}
