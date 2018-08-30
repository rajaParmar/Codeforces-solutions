#include<stdio.h>
int main()
{
	long long n,m,a,row=0,t=0;
	scanf("%lld%lld%lld",&m,&n,&a);
	row=n/a;
	if(n%a!=0)
		row++;
	m-=a;
	t=row;
	t+=m/a*row;
	if(m%a!=0 && m>0)
		t=t+row;

	printf("%lld",t);
return 0;

}
