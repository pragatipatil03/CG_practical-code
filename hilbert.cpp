#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
void move(int j,int h,int &x,int &y)
{
	if(j==1)
	    y=y+h;
	else if(j==2)
	    x=x+h;
	else if(j==3)
	    y=y-h;
	else if(j==4)
	    x=x-h;
	lineto(x,y);
	
}
void hilbert(int d,int r,int u,int l,int n,int h,int &x,int &y)
{
	if(n>0)
	{
		n--;
		hilbert(r,d,l,u,n,h,x,y);
		move(d,h,x,y);
		hilbert(d,r,u,l,n,h,x,y);
		move(r,h,x,y);
		hilbert(d,r,u,l,n,h,x,y);
		move(u,h,x,y);
		hilbert(l,u,r,d,n,h,x,y);
	}
	
}
int main()
{
	int gd = DETECT,gm;
	initgraph(&gd,&gm,NULL);
	int x=50,y=150,h=50,n;
	int d=1,r=2,u=3,l=4;
	cout<<"enter the value of n: ";
	cin>>n;
	moveto(x,y);
	hilbert(d,r,u,l,n,h,x,y);
	delay(10000);
	getch();
	closegraph();
	return 0;
}
