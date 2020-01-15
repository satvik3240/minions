#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<math.h>
#include<dos.h>
#include<fstream.h>
#include<string.h>
#include<process.h>
#include<time.h>
#include<stdlib.h>
void physics();
void chemistry();
void maths();
void pulley();
void inclinepulley();
void pendulum();
void gravity();
void pascals();
void thermodynamics();
void elements();
void atmstruct();
void ph();
void solutions();
void calc();
void stlines();
void apgp();
void quadeq();
void animation();
void anim2();
void thankyou();
void pcm();
void dltrec();
char fng[50];
class record
{
	char nm[30],roll_no[15],pswrd[50],sch[100];
	char cls;
     public:
		int ob;
		void in();
		void out();
		void modi();
		friend void signup();
		friend void login();
		friend void dlt();
};
record r;
	void record::in()
{
	char pswrdc[50];
	do
	{
	cout<<"Password: ";
	gets(pswrd);
	cout<<"Confirm Password: ";
	gets(pswrdc);
	if(strcmp(pswrd,pswrdc))
	cout<<"\nPassword did not match...Renter the Password\n";
	}while(strcmp(pswrd,pswrdc));
	cout<<"\n\nName: ";
	gets(nm);
	cout<<"School\\College: ";
	gets(sch);
	cout<<"Class\\Semester: ";
	cin>>cls;
	cout<<"Roll Number:  ";
	gets(roll_no);


}
     void record::modi()
     {
     cout<<"\nEnter new data: \n";
     cout<<"Enter the name: ";
     gets(nm);
     cout<<"Enter your School: ";
     gets(sch);
     cout<<"Enter roll number: ";
     gets(roll_no);
     cout<<"Enter  your class: ";
     cin>>cls;
     cout<<"\n\n\tAccount Updated successfully!!!";
     }

	void record::out()
{
      cout<<"Name: "<<nm<<endl;
     // cout<<"Date & Time of joining: "<<dt<<" at "<<time<<endl;
      cout<<"School: "<<sch<<endl;
      cout<<"Class: "<<cls<<endl;
      cout<<"Roll number: "<<roll_no<<endl<<"\n\n";

    }
	void signup()
{       char flnm[50];
	fstream f;
	cout<<"Enter your desired Student Helper's ID: ";
	gets(flnm);
	f.open(flnm,ios::out|ios::binary|ios::noreplace);
	if(!f)
	{
	cout<<"\n\tAccount Already exist!!!";
	goto failed;
	}
	r.in();
	f.write((char*)&r,sizeof(r));
	cout<<"\n\n\nThank You for signing up " ;
	failed:

	f.close();
	getch();

}

	void login()
{       char logch,scs;
	char pswrdl[50];
	fstream f;
	char ch;
	cout<<"Enter Student Helper's ID: ";
	gets(fng);
	f.open(fng,ios::in|ios::out|ios::binary|ios::nocreate);
	f.seekg(0,ios::beg);
	f.read((char*)&r,sizeof(r));
	if(!f)
	{
	cout<<"\nMake sure that you have entered correct User ID";
	getch();
	}
	if(f)
	{
	cout<<"\nPassword: ";
	gets(pswrdl);
	if(strcmp(pswrdl,r.pswrd))
	{
	cout<<"\n\n\tIncorrect Password!!!";
	getch	();
	goto logout;
	}
	else
	do
	{
	clrscr();
	cleardevice();
	setbkcolor(BLACK);
	cout<<"\nHello "<<r.nm;
	cout<<"\n\n\n\n1.To the Student Helper...\n2.Account Settings\n3.Previous Record\n4.Delete Previous Record\n5.Logout\n";
	cout<<"\n\n\tEnter your choice here: ";
	cin>>logch;
	switch(logch)
	{
	case '1':
	pcm();
	break;
	case '2':
	{
	 char ch;
	 do
	 {
	 clrscr();
	 cleardevice();
	 setbkcolor(BLACK);
	 cout<<"\nACCOUNT SETTINGS";
	 cout<<"\n\n\n1.Get Account Details\n2.Update/Change Account Details\n3.Delete this Account\n4.Home";
	 cout<<"\n\n\tEnter your choice: ";
	 cin>>ch;
	 if(ch=='1')
	 {
	f.seekg(0,ios::beg);
	f.read((char*)&r,sizeof(r));
	r.out();
	getch();
	}
	else if(ch=='2')
	{
	f.seekg(0,ios::beg);
	f.read((char*)&r,sizeof(r));
	r.modi();
	f.seekg(0,ios::beg);
	f.write((char*)&r,sizeof(r));
	getch();
	}
	else if(ch=='3')
	{
	dlt();
	goto logout;
	}
	else if(ch=='4')
	goto home;
	else
	while(ch!='4'&&ch!='3'&&ch!='2'&&ch!='1')
	{
	cout<<"\nEnter a valid choice: ";
	cin>>ch;
	}
	}while(ch!='4');
	}
	home:
	break;
	case '3':
	{
	cout<<"\n\nSelect the scrolling speed: ";
	cout<<"\n1.Very Slow\n2.Slow\n3.Medium\n4.Fast\n5.Very Fast\n";
	cout<<"Enter here: ";
	cin>>scs;
	while(scs!='1'&&scs!='2'&&scs!='3'&&scs!='4'&&scs!='5')
	{
	cout<<"Enter a valid selection: ";
	cin>>scs;
	}
	clrscr();
	cleardevice();
	setbkcolor(BLACK);
	f.seekg(198);
	while(!f.eof())
	{

	ch=f.get();
	cout<<ch;
	if(scs=='1')
	delay(250);
	else if(scs=='2')
	delay(150);
	else if(scs=='3')
	delay(100);
	else if(scs=='4')
	delay(50);
	else if(scs=='5')
	delay(20);
	}
	getch();
	}
	break;
	case '4':
	 dltrec();
	break;
	case '5':
	f.close();
	goto logout;
	default:
	while(logch!='1'&&logch!='2'&&logch!='3'&&logch!='4'&&logch!='5')
		{
	cout<<"Enter a valid choice: ";
	cin>>logch;
	}
	}
	}
	while(logch!='5');
	}
	logout:
	}

  void dlt()
{
	ifstream f1(fng,ios::in|ios::binary);
	ofstream f2("stay",ios::out|ios::binary);
		char con='n';
		cout<<"\n\tAre you sure you want to delete your account \n\t\t(y/n)";
		cin>>con;
		if(con=='n'|| con=='N')
		cout<<"\nAccount deletion failed!!!";
		else
	       {f2.write((char*)&r,sizeof(r));
		f2.close();
		remove(fng);
		cout<<"Account with the ID - \' "<<fng<<" \' Successfully Deleted!!!";
		}
		getch();
}

void dltrec()
{
	ifstream f(fng,ios::in);
	ofstream file("temp",ios::out);
	f.read((char*)&r,sizeof(r));
	file.write((char*)&r,sizeof(r));
	f.close();
	file.close();
	remove(fng);
	rename("temp",fng);
	cout<<"\n\n\n\t\tRecord deleted successfully";
	getch();
 }

void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
anim2();

char ch;
do
{
clrscr();
cleardevice();

setbkcolor(BLACK);
setcolor(RED);
cout<<"\n\n\n\t\t1.Sign up "<<endl;
cout<<"\n\t\t2.Login "<<endl;
cout<<"\n\t\t3.Exit\n";
cout<<"\n\nOption no. : ";
cin>>ch;
while(ch!='1'&&ch!='2'&&ch!='3')
{
cout<<"\n\nEnter a valid Option: ";
cin>>ch;
}
switch(ch)
{
case '1':
signup();
break;
case '2':
login();
break;
case '3':
animation();
thankyou();
break;
}
}
while(ch!='3');
closegraph();
}
void pcm()
{
int exit=0;
while(exit==0)
{
clrscr();
cleardevice();
setbkcolor(BLACK);
char cn;
settextstyle(4,0,5);
setbkcolor(15);
setfillstyle(CLOSE_DOT_FILL,13);
floodfill(1,1,1);
settextstyle(3,0,5);
setcolor(2);
outtextxy(170,8,"STUDENT HELPER");
settextstyle(0,0,3);
setcolor(9);
outtextxy(20,140,"1.Physics");
outtextxy(20,170,"2.Chemistry");
outtextxy(20,200,"3.Maths");
outtextxy(20,230,"4.Quit");
settextstyle(0,0,2);
outtextxy(40,340,"Enter the topic number: ");
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n ";
cin>>cn;
if(cn!='1'&&cn!='2'&&cn!='3'&&cn!='4')
{
cout<<cn;
getch();
int i=0;
while(cn!='1'&&cn!='2'&&cn!='3'&&cn!='4')
{
outtextxy(20,360+i,"Enter valid topic number");
cout<<"\n\n\n";
cin>>cn;
i=i+20;
}
}
else if(cn=='1')
physics();
else if(cn=='2')
chemistry();
else if(cn=='3')
maths();
else if(cn=='4')
exit=32;
cleardevice();
}
}
void physics()
{
int exit=0;
while(exit==0)
{
clrscr();
cleardevice();
setbkcolor(BLACK);
int cn;

setbkcolor(15);
setfillstyle(XHATCH_FILL,9);
floodfill(1,1,1);
settextstyle(3,0,5);
setcolor(6);
outtextxy(230,8,"PHYSICS");
settextstyle(0,0,2);
setcolor(8);
outtextxy(20,130,"1.Simple Pulley");
outtextxy(20,150,"2.Pulley on an inclined Plane");
outtextxy(20,170,"3.Simple Pendulum");
outtextxy(20,190,"4.Gravitaion");
outtextxy(20,210,"5.Hydraulic lift");
outtextxy(20,230,"6.Thermodynamics");
outtextxy(20,250,"7.Exit to main menu");
settextstyle(1,0,2);
outtextxy(40,300,"Enter the topic number: ");
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n ";
cin>>cn;
if(cn>7||cn<1)
{
int i=0;
while(cn>7||cn<1)
{
outtextxy(20,320+i,"Enter valid topic number");
cout<<"\n\n\n";
cin>>cn;
i=i+20;
}
}
else if(cn==1)
pulley();
else if(cn==2)
inclinepulley();
else if(cn==3)
pendulum();
else if(cn==4)
gravity();
else if(cn==5)
pascals();
else if(cn==6)
thermodynamics();
else if(cn==7)
exit=32;
}
}
void pulley()
{
fstream f;

f.open(fng,ios::app|ios::binary);

int i=0;
while(i==0)
{
clrscr();
cleardevice();
setbkcolor(BLACK);
char ch;
float m1,m2,a,t;


line(5,10,75,10);
line(20,10,40,30);
line(60,10,40,30);
circle(40,30,10);
line(30,30,30,60);
rectangle(20,60,40,80);
line(50,30,50,100);
rectangle(40,100,60,120);
settextstyle(1,0,1);
outtextxy(25,65,"M1");
outtextxy(45,105,"M2");
settextstyle(1,0,2);
setcolor(4);
outtextxy(250,15,"Acceleration and tension calculator");
setcolor(3);
outtextxy(350,75,"Simple pulley");
settextstyle(0,0,1);
setcolor(15);
cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tEnter the value of M1:" ;
cin>>m1;
while(m1<0)
{cout<<"Mass cannot be negative\nRenter the value:";
cin>>m1;}
f<<"\n\n\nSIMPLE PULLEY: ";			//**koi bhi function se related
						//statement daalne se pahele
						//topic ka naam capital me daalna 3\n laga ke
f<<"\nM1: "<<m1<<"Kg";
cout<<"\n\t\t\t\t\tEnter the value of M2:" ;
cin>>m2;
while(m2<0)
{cout<<"Mass cannot be negative\nRenter the value:";
cin>>m2;}
f<<"\nM2: "<<m2<<"Kg";
a=(9.8*(m2-m1))/(m1+m2);
cout<<"\nAcceleration produced is: "<<a<<" m/s^2";
f<<"\nAcceleration produced: "<<a<<"m/s^2";
if(a==0)
cout<<"\nNothing will happen";
else if(a<0)
{
for(int i=0;i<65;i++)
{
line(205,10,275,10);
line(220,10,240,30);
line(260,10,240,30);
circle(240,30,10);
line(230,30,230,60+i);
rectangle(220,60+i,240,80+i);
line(250,30,250,100-i);
rectangle(240,100-i,260,120-i);
outtextxy(222,65+i,"M1");
outtextxy(242,105-i,"M2");
setcolor(15);
delay(30);
if(i<64)
cleardevice();
}
cout<<"\nAcceleration produced is: "<<a<<" m/s^2";
cout<<"\n'-' shows that the mass M2 will accelerate upwards";
}
else
{for(int i=0;i<25;i++)
{
line(205,10,275,10);
line(220,10,240,30);
line(260,10,240,30);
circle(240,30,10);
line(230,30,230,60-i);
rectangle(220,60-i,240,80-i);
line(250,30,250,100+i);
rectangle(240,100+i,260,120+i);
outtextxy(222,65-i,"M1");
outtextxy(242,105+i,"M2");
setcolor(15);
delay(40);
if(i<24)
cleardevice();
}
cout<<"\nAcceleration produced is: "<<a<<" m/s^2";
cout<<"\nMass M2 will accelerate downwards";
}
t=2*9.8*m1*m2/(m1+m2);
f<<"\nTension in the string: "<<t<<"N";
cout<<"\nTension in the string is: "<<t<<" N";
cout<<"\nEnter 'E' to exit or any other key to restart the topic";
cin>>ch;
if(ch=='E'||ch=='e')
i=32;
}
f.close();
}
void inclinepulley()
{
int i=0;
while(i==0)
{
clrscr();
cleardevice();
setbkcolor(BLACK);
fstream f(fng,ios::app|ios::binary);
f<<"\n\n\nPulley on Inclined Plane: \n";


char ch;
float m1,m2,u,A,B,a,t;
int x,y;
int massp[10]={93,93,113,113,133,93,113,73,93,93};
line(35,35,150,150);
line(35,150,150,150);
line(35,35,35,150);
circle(35,35,15);
line(20,35,20,100);
rectangle(5,100,32,130);
line(44,23,104,81);
drawpoly(5,massp);
arc(150,150,135,180,25);
outtextxy(10,105,"M1");
outtextxy(110,90,"M2");
outtextxy(115,130,"A");
outtextxy(60,80,"u");
settextstyle(1,0,2);
setcolor(4);
outtextxy(250,15,"Acceleration and tension calculator");
setcolor(3);
outtextxy(350,75,"Inclination and pulley");
settextstyle(0,0,1);
setcolor(15);
cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tEnter the value of M1:" ;
cin>>m1;
while(m1<0)
{cout<<"Mass cannot be negative\nRenter the value:";
cin>>m1;}
f<<"Mass M1: "<<m1<<"Kg\n";
cout<<"\n\t\t\t\t\tEnter the value of M2:" ;
cin>>m2;
while(m2<0)
{cout<<"Mass cannot be negative\nRenter the value:";
cin>>m2;}
f<<"Mass M2: "<<m2<<"Kg\n";
cout<<"\n\t\t\t\tEnter the angle 'A'(in degrees): ";
cin>>A;
while(A>90)
{cout<<"According to diagram angle cannot be greater than 90\nRenter A: ";
cin>>A;
}
f<<"Angle of Inclination A: "<<A<<"Degrees\n";
while(A<0)
{cout<<"According to diagram angle cannot be negative\nRenter A: ";
cin>>A;
}
cout<<"Enter the value of 'u'(coefficient of friction between m2 and surface): ";
cin>>u;
while(u>1)
{cout<<"u is never greater than 1\nRenter the value of u: ";
cin>>u;
}
while(u<0)
{cout<<"u cannot be negative\nRenter the value of u:";
cin>>u;
}
f<<"Coefficient of friction(u): "<<u<<endl;
B=A*3.14/180;
a=9.8*(m1-m2*(sin(B)+(u*cos(B))))/(m1+m2);
t=m2*(a+9.8*(sin(B)+(u*cos(B))));
f<<"Acceleration produced: "<<a<<"m/s^2\n";
f<<"Tension in the string: "<<t<<"N\n";
if(a>0)
{
cout<<"Acceleration produced is: "<<a<<"m/s^2";
cout<<"\nMass M1 will move downward";
cout<<"\nTension in the string is: "<<t<<"N";
}
else if(a<0)
{
cout<<"Acceleration produced is: "<<a<<"m/s^2";
cout<<"\nMass M1 will move upward";
cout<<"\nTension in the string is: "<<t<<"N";
}
else
{
cout<<"Acceleration produced is: "<<a<<"m/s^2";
cout<<"\nNothing will happen";
cout<<"\nTension in the string is: "<<t<<"N";
}
cout<<"\nEnter 'E' to exit or any other key to restart the topic";
cin>>ch;
if(ch=='E'||ch=='e')
i=32;

f.close();
}
}
void gravity()
{
fstream f(fng,ios::app|ios::binary);
f<<"\n\n\nGravitation: \n";
char ch;
int e=1;
while(e==1)
{
clrscr();
cleardevice();
setbkcolor(BLACK);
float g,t,h,v;
double long r;


settextstyle(1,0,2);
setcolor(4);
outtextxy(400,15,"Gravity");
setcolor(3);
outtextxy(300,75,"Acceleration,Speed & Time");
setcolor(15);
circle(95,155,55);
setcolor(GREEN);
settextstyle(3,0,3);
outtextxy(65,135,"EARTH");
setcolor(15);
rectangle(85,15,105,25);
line(90,30,100,30);
line(95,30,95,95);
line(90,95,100,95);
settextstyle(2,0,7);
outtextxy(99,62,"h");
settextstyle(2,0,5);
outtextxy(205,130,"A body is to be released from height h.");
outtextxy(205,142,"To know the acceleration due to gravity(g')");
outtextxy(205,154,"acting at height h from earth and the time(t)");
outtextxy(205,166,"taken by the body to reach the surface of");
outtextxy(205,178,"the earth and also the velcity(v) with which");
outtextxy(245,190,"it will strike the earth");
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tEnter the height(h) : ";
cin>>h;
f<<"Height of object: "<<h<<"m\n";
r=6400000;
g=9.81*((r*r)/((r+h)*(r+h)));
v=pow((2*g*h),0.5);
t=pow(((2*h)/g),0.5);
f<<"Acceleration due to gravity(g): "<<g<<"m/s^2\n";
f<<"Velocity of object just before touching the Earth: "<<v<<"m/s\n";
f<<"Time taken by object to reach the Earth surface: "<<t<<"s\n";
for(int i=0;i<65;i++)
{
settextstyle(1,0,2);
setcolor(4);
outtextxy(400,15,"Gravity");
setcolor(3);
outtextxy(300,75,"Acceleration,Speed & Time");
setcolor(15);
circle(95,155,55);
setcolor(GREEN);
settextstyle(3,0,3);
outtextxy(65,135,"EARTH");
setcolor(15);
rectangle(85,15+i,105,25+i);
settextstyle(2,0,5);
outtextxy(205,130,"A body is to be released from height h.");
outtextxy(205,142,"To know the acceleration due to gravity(g')");
outtextxy(205,154,"acting at height h from earth and the time(t)");
outtextxy(205,166,"taken by the body to reach the surface of");
outtextxy(205,178,"the earth and also the velcity(v) with which");
outtextxy(245,190,"it will strike the earth");
delay(32);
if(i<=63)
cleardevice();
}
cout<<"\n\n\n\n\tAcceleration(g'): "<<g<<" m/s";
cout<<"\n\tVelocity(v): "<<v;
cout<<"\n\tTime(t): "<<t;
cout<<"\n\n\nEnter 'E' to exit or any other key to restart the topic: ";
cin>>ch;
if(ch=='e'||ch=='E')
e=32;

}
f.close();
}
void pendulum()
{
fstream f(fng,ios::app|ios::binary);
f<<"\n\n\nSimple Pendulum: \n";
int e=0;
char ch;
while(e==0)
{
clrscr();
cleardevice();
setbkcolor(BLACK);
float x,y,l,t;
char str[50];
int i=0;

settextstyle(1,0,2);
setcolor(4);
outtextxy(250,15,"Time period calculator");
setcolor(3);
outtextxy(350,75,"Simple Pendulem");
setcolor(15);
x=15;
line(50,15,70,15);
y=pow((12500-((x-60)*(x-60))),0.5)+15;
line(60,15,x,y);
circle(x,y,10);
x=60;
line(50,15,70,15);
y=pow((12500-((x-60)*(x-60))),0.5)+15;
line(60,15,x,y);
circle(x,y,10);
x=95;
line(50,15,70,15);
y=pow((12500-((x-60)*(x-60))),0.5)+15;
line(60,15,x,y);
circle(x,y,10);
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\tEnter the length(m) of the pendulem: ";
cin>>l;
while(l<0)
{
cout<<"\nLength cannot be negative. Renter the length: ";
cin>>l;
}
f<<"Length of Pendulum: "<<l<<"m\n";
t=2*3.14*pow((l/9.81),0.5);
f<<"Time periode of Pendulum: "<<t<<"s\n";
sprintf(str,"Time period of the pendulem is %fsec.",t);
for(x=15;x<95;i++)
{
settextstyle(1,0,2);
setcolor(4);
outtextxy(250,15,"Time period calculator");
setcolor(3);
outtextxy(350,75,"Simple Pendulem");
setcolor(15);
line(50,15,70,15);
y=pow((12500-((x-60)*(x-60))),0.5)+15;
line(60,15,x,y);
circle(x,y,10);
if(x==94)
for(;x>16;x--)
{
settextstyle(1,0,2);
setcolor(4);
outtextxy(250,15,"Time period calculator");
setcolor(3);
outtextxy(350,75,"Simple Pendulem");
setcolor(15);
line(50,15,70,15);
y=pow((12500-((x-60)*(x-60))),0.5)+15;
line(60,15,x,y);
circle(x,y,10);
delay(20);
cleardevice();
}
x++;
if(i==130)
goto exit;
delay(20);
cleardevice();
}
exit:
settextstyle(5,0,2);
setcolor(7);
outtextxy(150,250,str);
cout<<"\n\n\n\n\n\n\n\nEnter 'E' to exit or any other key to restart the topic: ";
cin>>ch;
if(ch=='e'||ch=='E')
e=32;
}
f.close();
}
void pascals()
{
fstream f(fng,ios::app|ios::binary);
f<<"\n\n\nHydraulic Lift: \n";
float a,A,m,f1;
int e=0;
char ch;
while(e==0)
{

clrscr();
cleardevice();
setbkcolor(BLACK);

line(25,30,25,100);
line(40,30,40,85);
line(25,100,220,100);
line(40,85,160,85);
line(160,40,160,85);
line(220,40,220,100);
line(32,15,32,45);
line(25,45,40,45);
line(188,40,188,65);
line(192,40,192,65);
line(160,65,220,65);
line(140,40,240,40);
rectangle(175,25,205,40);
settextstyle(1,0,2);
setcolor(4);
outtextxy(400,15,"Pascal's law");
setcolor(3);
outtextxy(400,75,"Hydraulic Lift");
setcolor(15);
settextstyle(2,0,7);
outtextxy(43,15,"F");
outtextxy(190,15,"m");
cout<<"\n\n\n\n\n\n\n\n\n\n\tEnter the mass(m) to be lifted(in kg): ";
cin>>m;
f<<"\nMass tobe lifted: "<<m<<"kg";
cout<<"\n\tEnter the smaller cross-sectional area(in cm^2): ";
cin>>a;
f<<"\n Smaller cross-sectional area: "<<a<<"cm^2";
cout<<"\n\tEnter the larger cross-sectional area: ";
cin>>A;
f<<"\n Larger cross-sectional area: "<<A<<"cm^2";
f1=(a*m*9.81)/A;
f<<"\nForce required to lift the body of mass "<<m<<"Kg is: "<<f1<<"N";
for(int i=0;i<=25;i++)
{
line(25,30,25,100);
line(40,30,40,85);
line(25,100,220,100);
line(40,85,160,85);
line(160,40,160,85);
line(220,40,220,100);
line(32,10+i,32,45+i);
line(25,45+i,40,45+i);
line(188,40-i,188,65-i);
line(192,40-i,192,65-i);
line(160,65-i,220,65-i);
line(140,40-i,240,40-i);
rectangle(175,25-i,205,40-i);
settextstyle(1,0,2);
setcolor(4);
outtextxy(400,15,"Pascal's law");
setcolor(3);
outtextxy(400,75,"Hydraulic Lift");
setcolor(15);
settextstyle(2,0,7);
outtextxy(43,15,"F");
outtextxy(190,15-i,"m");
delay(80);
if(i<25)
cleardevice();
//clrscr();
}
cout<<"Force required to lift the body of mass "<<m<<"Kg is: "<<f1<<"N";
cout<<"\nEnter 'E' to exit or any other key to restart topic: ";
cin>>ch;
if(ch=='e'||ch=='E')
e=32;
}
f.close();
}
void thermodynamics()
{
fstream f(fng,ios::app|ios::binary);
f<<"\n\n\nThermodynamics: \n";
int e=0;
char ch;
while(e==0)
{
clrscr();
cleardevice();
setbkcolor(BLACK);
float v1,v2,p,w,dv;
float t,p1,p2,n;
int tp,gq;


settextstyle(1,0,2);
setcolor(4);
outtextxy(230,15,"Thermodynamics");
setcolor(3);
outtextxy(250,50,"Work Done");
setcolor(15);
cout<<"\n\n\n\n\n\n\nChoose the theodynamic condition:";
cout<<"\n\t\t1.Isobaric\n\t\t2.Isochoric\n\t\t3.Isothermal\n\t\t4.Adiabatic";
cout<<"\n\n\tEnter your choice: ";
cin>>tp;
if(tp==1)
{
f<<"\nThermodynamic condition : "<<"\tIsobaric ";
cout<<"\n\nSelect the given quantity: ";
cout<<"\n\t1.Initial and final volume\n\t2.Change in volume";
cout<<"\nEnter your selection: ";
cin>>gq;
if(gq!=1&&gq!=2)
{
while(gq!=1&&gq!=2)
{
cout<<"Enter a valid selection: ";
cin>>gq;
}
}
if(gq==1)
{
f<<"\nQyantity selected : "<<"Initial and final volume ";
cout<<"\n\n\tEnter initial volume(V1 in litres): ";
cin>>v1;
f<<"\nInitial volume -> "<<v1<<'L';
cout<<"\tEnter final volume(V2 in litres): ";
cin>>v2;
f<<"\nFinal volume -> "<<v2<<'L';
cout<<"\tEnter pressure exerted(in atm): ";
cin>>p;
f<<"\nPressure exerted-> "<<p<<"atm";
w=p*(v2-v1);
f<<"\nWork done is-> "<<w<<'J';
cout<<"\n\tWork done is: "<<w<<'J';
}
if(gq==2)
{
f<<"\nQyantity selected : "<<"Change in volume ";
cout<<"\n\tEnter the change in volume(dV in litres): ";
cin>>dv;
f<<"\nChange in volume-> "<<dv<<'L';
cout<<"\n\tEnter pressure exerted(in atm): ";
cin>>p;
f<<"\nPressure exerted-> "<<p<<"atm";
w=p*dv;
f<<"\nWork done is"<<w<<'J';
cout<<"\n\tWork done is"<<w<<'J';
}
}
else if(tp==2)
{
f<<"\nThermodynamic condition : "<<"\tIsochoric ";
f<<"\nIn isochoric process,workdone is 0";
cout<<"\n\n\tIn isochoric process,workdone is 0";
}
else if(tp==3)
{
f<<"\nThermodynamic condition : "<<"\tIsothermal ";
cout<<"\n\nEnter the given quantity: ";
cout<<"\n\t\t1.Pressure\n\t\t2.Volume";
cout<<"\nEnter your selection here: ";
cin>>gq;
if(gq!=1&&gq!=2)
{
while(gq!=1&&gq!=2)
{
cout<<"\nEnter a valid selection: ";
cin>>gq;
}
}
if(gq==1)
{
f<<"\nThe quantity selected is Pressure ";
cout<<"\n\tEnter the temperature(in kelvin): ";
cin>>t;
f<<"\nTemperature-> "<<t<<'K';
cout<<"\tEnter the initial pressure(p1 in atm): ";
cin>>p1;
f<<"\nInitial pressure(p1)-> "<<p1<<"atm";
cout<<"\tEnter the final pressure(p2 in atm): ";
cin>>p2;
f<<"\nFinal pressure(p2)-> "<<p2<<"atm";
cout<<"\tEnter the number of moles of gas: ";
cin>>n;
f<<"\nNumber of moles of gas-> "<<n<<"moles";
w=n*8.31*t*log(p2/p1);
f<<"\nWork done is-> "<<w<<'J';
cout<<"\nWork done is "<<w<<'J';
}
if(gq==2)
{
f<<"\nThe quantity selected is Volume ";
cout<<"\n\tEnter the temperature(in kelvin): ";
cin>>t;
f<<"\nTemperature-> "<<t<<'K';
cout<<"\tEnter the initial volume(v1in litres): ";
cin>>v1;
f<<"\nInitial volume -> "<<v1<<'L';
cout<<"\tEnter final volume(V2 in litres): ";
cin>>v2;
f<<"\nFinal volume -> "<<v2<<'L';
cout<<"\tEnter the number of moles of gas: ";
cin>>n;
f<<"\nNumber of moles of gas-> "<<n<<"moles";
w=n*8.31*t*log(v1/v2);
f<<"\nWork done is-> "<<w<<'J';
cout<<"\nWork done is "<<w<<'J';
}
}
if(tp==4)
{
f<<"\nThermodynamic condition : "<<"\tAdiabatic ";
cout<<"\n\n\tIn Adiabatic process workdone is equal to the change in internal energy";
f<<"\n\n\tIn Adiabatic process workdone is equal to the change in internal energy";
}
cout<<"\n\n\n\nTo exit the topic enter 'E' or to restart enter any other key: ";
cin>>ch;
if(ch=='e'||ch=='E')
e=32;
}
f.close();
}
void chemistry()
{
int exit=0;
while(exit==0)
{
clrscr();
cleardevice();
setbkcolor(BLACK);
int cn;

setbkcolor(15);
setfillstyle(LTSLASH_FILL,2);
floodfill(1,1,1);
settextstyle(3,0,5);
setcolor(12);
outtextxy(235,8,"CHEMISTRY");
settextstyle(0,0,2);
setcolor(9);
outtextxy(20,130,"1.Periodic table");
outtextxy(20,150,"2.Atomic structures");
outtextxy(20,170,"3.pH calculator");
outtextxy(20,190,"4.Solutions");
outtextxy(20,210,"5.Exit to main menu");
//outtextxy(20,230,"6.Thermodynamics");
//outtextxy(20,250,"7.Exit to main menu");
settextstyle(0,0,2);
outtextxy(40,300,"Enter the topic number: ");
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n ";
cin>>cn;
if(cn>5||cn<1)
{
int i=0;
while(cn>5||cn<1)
{
outtextxy(20,320+i,"Enter valid topic number");
cout<<"\n\n\n";
cin>>cn;
i=i+20;
}
}
else if(cn==1)
elements();
else if(cn==2)
atmstruct();
else if(cn==3)
ph();
else if(cn==4)
solutions();
else if(cn==5)
exit=32;
}
}
void elements()
{
fstream f(fng,ios::app|ios::binary);
f<<"\n\n\nElements: \n";
int e=0;
char ch;
while(e==0)
{
clrscr();
cleardevice();
setbkcolor(BLACK);
settextstyle(3,0,3);
setcolor(2);
outtextxy(260,10,"Elements");
	 int n, s1, s2, p2, s3, p3, s4, d3, p4, s5, d4, p5, s6, f4, d5, p6, s7, f5, d6, p7;
	 cout<<"\n\n\n\n\n\t Enter atomic number :";
	 cin>>n;
	 if(n<0)
	 while(n<0)
	 {
	 cout<<"Atomic number cannot be negative, renter: ";
	 cin>>n;
	 }
	 f<<"\nAtomic number: "<<n;
	 if (n<=2)
	  s1=n;
	 else if (n>2)
		s1=2;

	 if (n<=4 && n>=2)
	  s2=n-2;
	 else if (n<2)
	  s2=0;
	 else
	  if (n>4)
		s2=2;

	 if (n<=10 && n>=4)
		p2=(n-4);
	 else if (n<4)
		p2=0;
	 else
		if (n>10)
		p2=6 ;

	 if (n<=12 && n>=10)
		s3=n-10;
	 else if (n<10)
		s3=0;
	 else
		if (n>12)
		s3=2;

	 if (n<=18 && n>=12)
		p3=n-12;
	 else if (n<12)
		p3=0;
	 else
		if (n>18)
		p3=6;

	 if (n<=20 && n>=18)
		s4=n-18;
	 else if (n<18)
		 s4=0;
	 else
		if(n>20)
		s4=2;

	 if (n<=30 && n>=20)
		d3=n-20;
	 else if (n<20)
		d3=0;
	 else
		if (n>30)
		d3=10;

	 if (n<=36 && n>=30)
		p4=n-30;
	 else if (n<30)
		p4=0;
	 else
		if(n>36)
		p4=6;

	 if (n<=38 && n>=36)
		s5=n-36;
	 else if (n<36)
		s5=0;
	 else
		if(n>38)
		s5=2;

	 if (n<=48 && n>=38)
		d4=n-38;
	 else if (n<38)
		d4=0;
	 else
		d4=10;

	 if (n<=54 && n>=48)
		p5=n-48;
	 else if (n<48)
		p5=0;
	 else
		if (n>54)
		p5=6;

	 if (n<=56 && n>=54)
		s6=n-54;
	 else if (n<54)
		s6=0;
	 else
		if (n>56)
		s6=2;
	 if (n<=70 &&  n>=56)
		f4=n-56;
	 else if (n<56)
		f4=0;
	 else
		if(n>70)
		f4=14;

	 if (n<=80 && n>=70)
		d5=n-70;
	 else if (n<70)
		d5=0;
	 else
		if (n>80)
		d5=10;

	 if (n<=86 && n>=80)
		p6=n-80;
	 else if (n<80)
		p6=0;
	 else
		p6=6;

	 if (n<=88 && n>=86)
		s7=n-86;
	 else if (n<86)
		s7=0;
	 else
		if(n>88)
		s7=2;

	 if(n<=102 && n>=88)
		f5=n-88;
	 else if (n<88)
		f5=0;
	 else
		if (n>102)
		f5=14;

	 if (n<=112 && n>=102)
		d6=n-102;
	 else if (n<102)
		d6=0;
	 else
		 if(n>112)
		 d6=10;

	 if (n<118 && n>=112)
		p7=n-112;

	 else if (n<112)
		p7=0;
	 else
		if (n==118)
		p7=6;
	 if (n>118)
	{ cout<<"Element NOT Discovered";
	goto error;
	}
	     f<<"\nElectronic configuration: ";
		if(s1>0)
		{
		cout<<"\n\n 1s"<<s1;
		  f<<" 1s"<<s1;
		}if(s2>0)
		{cout<<" 2s"<<s2;
		   f<<" 2s"<<s2;
		}if (p2>0)
		{cout<<" 2p"<<p2;
		   f<<" 2p"<<p2;
		}if (s3>0)
		{cout<<" 3s"<<s3;
		   f<<" 3s"<<s3;
		}if(p3>0)
		{cout<<" 3p"<<p3;
		   f<<" 3p"<<p3;
		}if(d3>0)
		{cout<<" 3d"<<d3;
		   f<<" 3d"<<d3;
		}if(s4>0)
		{cout<<" 4s"<<s4;
		  f<<" 4s"<<s4;
		}if(p4>0)
		{
		cout<<" 4p"<<p4;
		  f<<" 4p"<<p4;
		}if(d4>0)
		{cout<<" 4d"<<d4;
		  f<<" 4d"<<d4;
		}if(f4>0)
		{cout<<" 4f"<<f4;
		  f<<" 4f"<<f4;
		}if(s5>0)
		{cout<<" 5s"<<s5;
		  f<<" 5s"<<s5;
		}if(p5>0)
		{cout<<" 5p"<<p5;
		  f<<" 5p" <<p5;
		}if(d5>0)
		{cout<<" 5d"<<d5;
		 f<<" 5d"<<d5;
		}if(f5>0)
		{cout<<" 5f"<<f5;
		  f<<" 5f"<<f5;
		}if(s6>0)
		{cout<<" 6s"<<s6;
		 f<<" 6s"<<s6;
		}if(p6>0)
		{cout<<" 6p"<<p6;
		 f<<" 6p"<<p6;
		}if(d6>0)
		{cout<<" 6d"<<d6;
		 f<<" 6d"<<d6;
		}
		if(s7>0)
		{cout<<" 7s"<<s7;
		 f<<" 7s"<<s7;
		}if(p7>0)
		cout<<" 7p"<<p7;
		cout<<"\n\n\tThe element is: ";
		switch(n)
		{
		case 1:
		cout<<"Hydrogen";
		break;
		case 2:
		cout<<"Helium";
		break;
		case 3:
		cout<<"Lithium";
		break;
		case 4:
		cout<<"Berylium";
		break;
		case 5:
		cout<<"Boron";
		break;
		case 6:
		cout<<"Carbon";
		break;
		case 7:
		cout<<"Nitrogen";
		break;
		case 8:
		cout<<"Oxygen";
		break;
		case 9:
		cout<<"Fluorine";
		break;
		case 10:
		cout<<"Neon";
		break;
		case 11:
		cout<<"Sodium";
		break;
		case 12:
		cout<<"Magnesium";
		break;
		case 13:
		cout<<"Alluminium";
		break;
		case 14:
		cout<<"silicon";
		break;
		case 15:
		cout<<"Phosphorus";
		break;
		case 16:
		cout<<"Sulphur";
		break;
		case 17:
		cout<<"Chlorine";
		break;
		case 18:
		cout<<"Argon";
		break;
		case 19:
		cout<<"Potassium";
		break;
		case 20:
		cout<<"Calcium";
		break;
		case 21:
		cout<<"Scandium";
		break;
		case 22:
		cout<<"Ttanium";
		break;
		case 23:
		cout<<"Vanedium";
		break;
		case 24:
		cout<<"Chromium";
		break;
		case 25:
		cout<<"Mangnese";
		break;
		case 26:
		cout<<"Iron";
		break;
		case 27:
		cout<<"Cobalt";
		break;
		case 28:
		cout<<"Nickel";
		break;
		case 29:
		cout<<"Copper";
		break;
		case 30:
		cout<<"Zinc";
		break;
		case 31:
		cout<<"Galium";
		break;
		case 32:
		cout<<"Germanium";
		break;
		case 33:
		cout<<"Arsenic";
		break;
		case 34:
		cout<<"Selenium";
		break;
		case 35:
		cout<<"Bromine";
		break;
		case 36:
		cout<<"Krypton";
		break;
		case 37:
		cout<<"Rubidium";
		break;
		case 38:
		cout<<"Stontium";
		break;
		case 39:
		cout<<"Yitrium";
		break;
		case 40:
		cout<<"Zirconium";
		break;
		case 41:
		cout<<"Niobium";
		break;
		case 42:
		cout<<"Molybdenum";
		break;
		case 43:
		cout<<"Technitium";
		break;
		case 44:
		cout<<"Ruthenium";
		break;
		case 45:
		cout<<"Rhodium";
		break;
		case 46:
		cout<<"Paladium";
		break;
		case 47:
		cout<<"Silver";
		break;
		case 48:
		cout<<"Cadmium";
		break;
		case 49:
		cout<<"Indium";
		break;
		case 50:
		cout<<"Tin";
		break;
		case 51:
		cout<<"Antimony";
		break;
		case 52:
		cout<<"Tellurium";
		break;
		case 53:
		cout<<"Iodine";
		break;
		case 54:
		cout<<"Xenon";
		break;
		case 55:
		cout<<"Cesium";
		break;
		case 56:
		cout<<"Barium";
		break;
		case 57:
		cout<<"Lanthanum";
		break;
		case 58:
		cout<<"Cerium";
		break;
		case 59:
		cout<<"Praseodymium";
		break;
		case 60:
		cout<<"Neodymium";
		break;
		case 61:
		cout<<"Promethium";
		break;
		case 62:
		cout<<"Samarium";
		break;
		case 63:
		cout<<"Europium";
		break;
		case 64:
		cout<<"Gadolinium";
		break;
		case 65:
		cout<<"Terbium";
		break;
		case 66:
		cout<<"Dysprosium";
		break;
		case 67:
		cout<<"Holmium";
		break;
		case 68:
		cout<<"Erbium";
		break;
		case 69:
		cout<<"Thulium";
		break;
		case 70:
		cout<<"Ytterbium";
		break;
		case 71:
		cout<<"Lutetium";
		break;
		case 72:
		cout<<"Hafmium";
		break;
		case 73:
		cout<<"Tantalum";
		break;
		case 74:
		cout<<"Tungsten";
		break;
		case 75:
		cout<<"Rhenium";
		break;
		case 76:
		cout<<"Osmium";
		break;
		case 77:
		cout<<"Iridium";
		break;
		case 78:
		cout<<"Platinum";
		break;
		case 79:
		cout<<"Gold";
		break;
		case 80:
		cout<<"Mercury";
		break;
		case 81:
		cout<<"Thalium";
		break;
		case 82:
		cout<<"Lead";
		break;
		case 83:
		cout<<"Bismuth";
		break;
		case 84:
		cout<<"Polonium";
		break;
		case 85:
		cout<<"Astatine";
		break;
		case 86:
		cout<<"Radon";
		break;
		case 87:
		cout<<"Francium";
		break;
		case 88:
		cout<<"Radium";
		break;
		case 89:
		cout<<"Actinium";
		break;
		case 90:
		cout<<"Thorium";
		break;
		case 91:
		cout<<"Protactinum";
		break;
		case 92:
		cout<<"Uranium";
		break;
		case 93:
		cout<<"Nectunium";
		break;
		case 94:
		cout<<"Plutonium";
		break;
		case 95:
		cout<<"Americium";
		break;
		case 96:
		cout<<"Curium";
		break;
		case 97:
		cout<<"Berkelium";
		break;
		case 98:
		cout<<"Callifornium";
		break;
		case 99:
		cout<<"Einsteinium";
		break;
		case 100:
		cout<<"Fermium";
		break;
		case 101:
		cout<<"Mendelevium";
		break;
		case 102:
		cout<<"Nobelium";
		break;
		case 103:
		cout<<"Lawrencium";
		break;
		case 104:
		cout<<"Rutherfordium";
		break;
		case 105:
		cout<<"Dubnium";
		break;
		case 106:
		cout<<"Seaborgium";
		break;
		case 107:
		cout<<"Bohrium";
		break;
		case 108:
		cout<<"Hassium";
		break;
		case 109:
		cout<<"Meitnerium";
		break;
		case 110:
		cout<<"Darmstadtium";
		break;
		case 111:
		cout<<"Roentgenium";
		break;
		case 112:
		cout<<"Copernicium";
		break;
		case 113:
		cout<<"Ununtrium";
		break;
		case 114:
		cout<<"Flerovium";
		break;
		case 115:
		cout<<"Ununpentium";
		break;
		case 116:
		cout<<"Livermorium";
		break;
		case 117:
		cout<<"Ununseptium";
		break;
		case 118:
		cout<<"Ununoctium";
		break;
		}
		error:
		cout<<"\n\n\n\tEnter 'E' to exit or any other key to restart the topic";
		cin>>ch;
		if(ch=='e'||ch=='E')
		e=32;
		}
		f.close();
		}
void atmstruct()
{
fstream f(fng,ios::app|ios::binary);
f<<"\n\n\nAtomic structure: \n";
int e=0;
char y,c,ch;
while(e==0)
{
clrscr();
cleardevice();
setbkcolor(BLACK);
cout<<"Press any key to open Fundamental Table   ";
f<<"\nYou viewed the fundamental table of atomic structure ";
getch();
cleardevice();
settextstyle(2,0,5);
line(60,60,500,60);
line(500,60,500,340);
line(500,340,60,340);
line(60,340,60,60);
line(60,90,500,90);
line(135,60,135,340);//1 down
line(200,60,200,340);//2 DOWN
//setcolor(GREEN);
//line(70,84,120,84);//underline1
setcolor(WHITE);
line(320,60,320,340);
line(410,60,410,340);
line(60,170,500,170);//lin1
line(60,260,500,260);//lin2
setcolor(YELLOW);
outtextxy(78,75,"Name");
outtextxy(144,75,"Symbol");//symbol
outtextxy(225,65,"Absolute");//abs
outtextxy(227,78,"Charge/C");
outtextxy(335,72,"Mass/kg");
outtextxy(420,65,"Relative");
outtextxy(425,78,"Charge");
//setcolor(GREEN);
//line(70,84,120,84);//underline1
//line(144,84,190,84);//under2
//line(225,88,290,88);//undercharge
//line(225,75,290,75);//underabsolute
//line(335,80,390,80);//underlinemass
//line(420,75,480,75);
//line(424,86,480,86);
setcolor(CYAN);
outtextxy(68,125,"Electron");
outtextxy(68,205,"Proton");
outtextxy(68,290,"Neutron");
setcolor(BROWN);
//line(68,135,130,135);
//line(66,215,120,215);
//line(68,300,125,300);
line(50,55,530,55);
setcolor(MAGENTA);
outtextxy(160,128,"e");
outtextxy(160,200,"p");
outtextxy(160,290,"n");
setcolor(LIGHTGRAY);
outtextxy(205,128,"-1.6022*10^-19");
outtextxy(205,200,"+1.6022*10^-19");
outtextxy(255,290,"0");
setcolor(LIGHTGREEN);
outtextxy(355,128,"+1");
outtextxy(355,200,"-1");
outtextxy(360,290,"0");
setcolor(LIGHTRED);
outtextxy(420,128,"9.1*10^-31");
outtextxy(420,200,"1.6*10^-27");
outtextxy(420,290,"1.6*10^-27");
setcolor(LIGHTBLUE);
settextstyle(7,0,2);
outtextxy(50,30,"PROPERTIES OF FUNDAMENTAL PARTICLES");
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\n\n\n\t\t\t\t\t\t\t\tTHANK YOU\nEnter 'E' to exit or any other key to restart the topic: ";
cin>>ch;
if(ch=='e'||ch=='E')
e=32;
}
f.close();
}
void ph()
{
fstream f(fng,ios::app|ios::binary);
f<<"\n\n\npH calculator: \n";
int e=0;
char ch;
while(e==0)
{
clrscr();
cleardevice();
setbkcolor(BLACK);
int r=800,y=14;
setcolor(BLUE);
for(int i=0;i<15;i++)
{
setcolor(y);
circle(40,1003,r);
r+=10;
y--;
}
double h,ph;
cout<<"^*^*^*^*^*^*^*^*^*^Enter the concentration of H+ ion^*^*^*^*^*^*^*^*\n";
cout<<"\n\n\t\tEnter here = ";
cin>>h;
f<<"\nThe concentration of H+ ion is-> "<<h;
ph=-log10(h);
f<<"\npH -> "<<ph;
cout<<"\n\t\t\tph = " <<ph ;
cout<<"\n\n\n\n\n\nAnd the concentration of OH- ion is "<<pow(10,-14)/h;
f<<"\nThe concentration of OH- ion is->  "<<pow(10,-14)/h;
cout<<"\n\n\nEnter 'E' to exit or any other key to restart the topic: ";
cin>>ch;
if(ch=='e'||ch=='E')
e=32;
}
f.close();
}
void solutions()
{
fstream f(fng,ios::app|ios::binary);
f<<"\n\n\nSolutions: \n";

int y,x,ex=0;
char k,e,ch;
float b,h,c;
float a,s,d,p;
while(ex==0)
{
clrscr();
cleardevice();
setbkcolor(BLACK);
settextstyle(7,0,5);
setcolor(LIGHTRED);
outtextxy(150,20,"SOLUTIONS");
cout<<"\n\n\n\n\n\nIn the below given equation \n\t\t\tA + B -->C  \n";
cout<<"\n\n\tA-->solute \n\tB-->solvent \n\tC-->solution\n";
cout<<"\nEnter the value of Number of moles of A   ";
cin>>b;
f<<"\nIn the equation  \n\t\t\tA + B -->C \n "<<"\nValue of  Number of moles of A-> "<<b;
cout<<"\nEnter the value of Number of moles of B   ";
cin>>h;
f<<"\nValue of Number of moles of B-> "<<h;
cout<<"\nEnter the value of volume of C (in litres)  ";
cin>>s;
f<<"\nValue of volume of C-> "<<s<<'L';
cout<<"\nEnter the value of weight of B(in kg)     ";
cin>>a;
cout<<"\nValue of weight of B-> "<<a<<"Kg";

clrscr();
cleardevice();
setbkcolor(BLACK);
settextstyle(7,0,5);
setcolor(LIGHTRED);
outtextxy(150,20,"SOLUTIONS");
cout<<"\n\n\n\n\n\n\tThe molarity of given solution is  " <<h/s<<"mol/ltr. \n";
cout<<"\n\tThe molality of given solution is  " <<h/a<<"mol/kg. \n";
cout<<"\n\tThe mole fraction of A in the given solution is  " <<b/(b+h)<<"\n";
cout<<"\n\tThe molarity of given B in the given solution is  " <<h/s;
f<<"\nThe molarity of given solution is-> " <<h/s<<"mol/ltr. \n";
f<<"\nThe molality of given solution is-> " <<h/a<<"mol/kg. \n";
f<<"\nThe mole fraction of A in the given solution is-> " <<b/(b+h)<<"\n";
f<<"\ntThe molarity of given B in the given solution is-> " <<h/s<<"\n";
cout<<"\n\n\nEnter 'E' to exit or any other key to restart the topic: ";
cin>>ch;
if(ch=='e'||ch=='E')
ex=32;
}
f.close();
}
void maths()
{
int exit=0;
while(exit==0)
{
clrscr();
cleardevice();
setbkcolor(BLACK);
int cn;

setbkcolor(15);
setfillstyle(HATCH_FILL,6);
floodfill(1,1,1);
settextstyle(3,0,5);
setcolor(9);
outtextxy(255,8,"MATHS");
settextstyle(0,0,2);
setcolor(2);
outtextxy(20,130,"1.Calculator");
outtextxy(20,150,"2.Straight lines");
outtextxy(20,170,"3.Sequence and series");
outtextxy(20,190,"4.Quadratics equations");
outtextxy(20,210,"5.Exit to main menu");
settextstyle(0,0,2);
outtextxy(40,300,"Enter the topic number: ");
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n ";
cin>>cn;
if(cn>5||cn<1)
{
int i=0;
while(cn>5||cn<1)
{
outtextxy(20,320+i,"Enter valid topic number");
cout<<"\n\n\n";
cin>>cn;
i=i+20;
}
}
else if(cn==1)
calc();
else if(cn==2)
stlines();
else if(cn==3)
apgp();
else if(cn==4)
quadeq();
else if(cn==5)
exit=32;
}
}
void calc()
{
fstream f(fng,ios::app|ios::binary);
f<<"\n\n\nCalculator: \n";
int a,b,c,d,e,f2,g,h,i;
char k,l;
float w,x,y,z=1;
int ex=0;
char ch;
while(ex==0)
{
clrscr();
cleardevice();
setbkcolor(BLACK);
settextstyle(6,0,6);
setcolor(LIGHTRED);
outtextxy(150,10,"CALCULATOR");
cout<<"\n\n\n\n\n\nEnter your desired choice \n\t\t\t1.Addition \n\t\t\t2.Subtraction \n\t\t\t3.Division \n\t\t\t4.Multiplication \n\t\t\t5.Factorial \n\t\t\t6.Percentage \n\t\t\t7.Log   . . . . .   ";
cout<<"\n\n\t\t\tHere: ";
cin>>b;
if(b<1||b>7)
{
while(b<1||b>7)
{
cout<<"\n\tEnter a valid choice: ";
cin>>b;
}
}
switch(b)
{
case 1:
cleardevice();
f<<"\nYour selected choice-> "<<"Addition ";
settextstyle(6,0,6);
setcolor(LIGHTRED);
outtextxy(150,10,"CALCULATOR");
cout<<"Enter the two numbers ";
cin>>w>>x;
f<<"\nThe two numbers are-> "<<w<<"and "<<x;
y=w+x;
f<<"\nThe addition of the given two numbers-> "<<y;
cout<<"\t\t"<<w<<" + "<<x<<" = "<<y;
break;
case 2:
cleardevice();
f<<"\nYour selected choice-> "<<"Subtraction ";
settextstyle(6,0,6);
setcolor(LIGHTRED);
outtextxy(150,10,"CALCULATOR");
cout<<"Enter the two numbers ";
cin>>w>>x;//w>x
f<<"\nThe two numbers are-> "<<w<<"and "<<x;
y=w-x;
cout<<"\t\t"<<w<<" - "<<x<<" = "<<y;
f<<"\nThe subtration of the given two numbers-> "<<y;
break;
case 3:
cleardevice();
f<<"\nYour selected choice-> "<<"Division ";
settextstyle(6,0,6);
setcolor(LIGHTRED);
outtextxy(150,10,"CALCULATOR");
cout<<"Enter the two numbers ";
cin>>w>>x;
f<<"\nThe two numbers are-> "<<w<<"and "<<x;
y=w/x;
cout<<"\t\tThe quotient is "<<y;
f<<"\nThe quotient of the given two numbers-> "<<y;
break;
case 4:
cleardevice();
f<<"\nYour selected choice-> "<<"Multiplication ";
settextstyle(6,0,6);
setcolor(LIGHTRED);
outtextxy(150,10,"CALCULATOR");
cout<<"Enter the two numbers ";
cin>>w>>x;
f<<"\nThe two numbers are-> "<<w<<"and "<<x;
y=w*x;
cout<<"\t\t"<<w<<" X "<<x<<" = "<<y;
f<<"\nThe product of the given two numbers-> "<<y;
break;
case 5:
cleardevice();
settextstyle(6,0,6);
setcolor(LIGHTRED);
outtextxy(150,10,"CALCULATOR");
f<<"\nYour selected choice-> "<<"Factorial ";
cout<<"Enter the  number   ";
cin>>w;
f<<"\nThe number is-> "<<w;
for(int i=1;i<=w;i++)
{
z=z*i;
}
cout<<"\t\t\tThe factorial("<<w<<"!) = "<<z;
f<<"\nThe factorial of the given number "<<w<<"  is  "<<z;
break;
case 6:
cleardevice();
f<<"\nYour selected choice-> "<<"Percentage ";
settextstyle(6,0,6);
setcolor(LIGHTRED);
outtextxy(150,10,"CALCULATOR");
cout<<"Enter the  number   \n";
cin>>x;
f<<"\nNumber entered-> "<<x;
cout<<"Enter the  percentage , you want to  calculate for this number \n";
cin>>w;
f<<"\nThe percentage , you want to  calculate for this number "<<w;
y=(w/100)*x;
f<<"\n\t\t\t"<<w<<" % of "<<x<<" is "<<y;
cout<<"\n\t\t\t"<<w<<" % of "<<x<<" is "<<y;
break;
case 7:
cleardevice();
f<<"\nYour selected choice-> "<<"Log ";
settextstyle(6,0,6);
setcolor(LIGHTRED);
outtextxy(150,10,"CALCULATOR");
cout<<"Enter the number of which you want to calculate the log  ";
cin>>w;
f<<"\nNumber entered-> "<<w;
y=log10(w);
f<<"\n\n\t\tlog("<<w<<") = "<<y;
cout<<"\n\n\t\tlog("<<w<<") = "<<y;
break;
}
cout<<"\n\n\n\nEnter 'E' to exit or any other key to restart the topic: ";
cin>>ch;
if(ch=='e'||ch=='E')
ex=32;
}
f.close();
}
void stlines()
{
fstream f(fng,ios::app|ios::binary);
f<<"\n\n\nStraight Lines: \n";
int ex=0;
char ch;
while(ex==0)
{
int z;
char y,e;
int b;
float a,s,d,p;
clrscr();
cleardevice();
setbkcolor(BLACK);
setcolor(YELLOW);
settextstyle(7,0,3);
outtextxy(190,5,"STRAIGHT LINES");
setcolor(RED);
settextstyle(1,0,1);
line(10,110,180,110);
cout<<"\n\n\n\n\nEnter your choice as: \n\t\t\t\t1.Pair of lines \n\t\t\t\t2.Angle between two lines \n\t\t\t\t3.calculation of angle";
cout<<"\n\n\t\t\tHere: ";
gotoxy(500,60);
cin>>b;
switch(b)
{
case 1:
{
cleardevice();
f<<"\nYour selected choice-> "<<"Pair of lines ";
setcolor(LIGHTRED);
cout<<"Enter the slopes of the lines ";
cin>>a>>s;
f<<"\nThe slopes of the lines are -> "<<a<<" and "<<s;
d=a*s;
if(d == -1)
{
cleardevice();
setcolor(LIGHTRED);
cout<<"The lines are perpendicular";
f<<"\nThe lines are perpendicular ";
line(100,200,400,200);
line(250,80,250,200);
outtextxy(160,300,"Here the product of slopes of lines i.e:->");

outtextxy(160,330,"m1 * m2 = -1");
}
else if(d==a*a)
{
cleardevice();
f<<"\nThe lines are parallel ";
cout<<"\tThe lines are parallel";
line(2,100,300,100);
line(2,180,300,180);
outtextxy(160,300,"Here the slopes of the two lines i.e:-> m1 and m2 are equal");
outtextxy(160,340," => m1=m2 ");
}
else
{
f<<"\nThe line sare neither parallelnor perpendicular ";
cout<<"The lines are neither parallel nor perpendicular";
}
break;
}
case 2:
{
cleardevice();
f<<"\nYour selected choice-> "<<"Angle between two lines ";


outtextxy(40,90,"The angle between two lines i.e:-> ");
outtextxy(160,200,"tanA=+ m2-m1");
outtextxy(225,200,"________");
outtextxy(215,218," 1+m1m2");
outtextxy(400,200,"&");
outtextxy(470,200,"tanA= - m2-m1");
outtextxy(550,210,"________");
outtextxy(540,228," 1+m1m2");
cleardevice();
clrscr();
}
break;
case 3:
{
cleardevice();
f<<"\nYour selected choice-> "<<"Calculation of Angle between two lines ";
cout<<"Enter the value of m1 and m2  ";
cout<<" ";
cin>>a>>s;
f<<"\nThe value of slope of two lines is "<<a<<"and"<<s;
p=(s-a)/(1+a*s);
cout<<"\nThe tan of the angle between the given two lines is "<<p;
f<<"\nThe tan of the angle between the given two lines is "<<p;
}
}
cout<<"\n\n\n\n\n\n\n\n\nEnter 'E' to exit or any other key to restart the topic: ";
cin>>ch;
if(ch=='e'||ch=='E')
ex=32;
}
}
void apgp()
{
int e=0;
char ch;
while(e==0)
{
int se,n;
float a,r,d,an,s;

clrscr();
cleardevice();
setbkcolor(BLACK);
settextstyle(1,0,3);
setcolor(3);
outtextxy(180,15,"Sequence and Series");
cout<<"\n\n\n\nSelect the type of Series:";
cout<<"\n\t1.Arithmatic Progression\n\t2.Geomtric Progression";
cout<<"\nEnter your selection here: ";
cin>>se;
if(se!=1&&se!=2)
{
while(se!=1&&se!=2)
{
cout<<"Enter a valid number: ";
cin>>se;
}
}
if(se==1)
{
cout<<"\nEnter the first number(a): ";
cin>>a;
cout<<"Enter the common difference(d): ";
cin>>d;
cout<<"Enter number the number of terms: ";
cin>>n;
an=a+(n-1)*d;
s=(n*((2*a)+((n-1)*d)))/2;
cout<<"\n\n\tNth term of the AP is: "<<an;
cout<<"\tSum of the AP is "<<s;
}
if(se==2)
{
cout<<"\nEnter the first number of the series: ";
cin>>a;
cout<<"Enter the common rario: ";
cin>>r;
cout<<"Enter the number of terms in the GP: ";
cin>>n;
an=a*pow(r,(n-1));
s=a*(1-pow(r,n))/(1-r);
cout<<"\n\n\tNth term of the GP is: "<<an;
cout<<"\tSum of the GP is: "<<s;
}
cout<<"\n\n\n\n\n\nEnter 'E' to exit or any other key to restart topic: ";
cin>>ch;
if(ch=='e'||ch=='E')
e=32;
}
}
void quadeq()
{
fstream f(fng,ios::app|ios::binary);
f<<"\n\n\nQuadratic Equations: \n";
int e=0;
char ch;
while(e==0)
{
clrscr();
cleardevice();
setbkcolor(BLACK);
settextstyle(3,0,3);
setcolor(3);
outtextxy(200,10,"Quadratic Equations");
float a,b,c,x1,x2,d;
cout<<"\n\n\n\n\n\nIF THE GIVEN EQUATION IS IN THE FORM ax^2+bx+c THEN: ";
cout<<"\n\nENTER a,b AND c RESPECTIVELY:\n ";
f<<"\n\n\n\n\n\nIF THE GIVEN EQUATION IS IN THE FORM ax^2+bx+c THEN: ";
cout<<"a: ";
cin>>a;
f<<"\nvalue of a entered -> "<<a;
cout<<"b: ";
cin>>b;
f<<"\nvalue of b entered -> "<<b;
cout<<"c: ";
cin>>c;
f<<"\nvalue of c entered -> "<<c;
d=(b*b)-4*a*c;
f<<"\nThe determinant of the given quadratic equation is "<<d;
if(d<0)
{
cout<<"roots are imaginary";
f<<"roots are imaginary";
}
else
{
x1=(pow(((b*b)-4*a*c),0.5)-b)/2*a;
x2=(-pow(((b*b)-4*a*c),0.5)-b)/2*a;
cout<<"\n\n\t\tSolutions are : "<<x1<<','<<x2;
f<<"\n\n\t\tThe roots are-> "<<x1<<','<<x2;
}
cout<<"\n\n\n\n\nEnter 'E' to exit or any other key to restart topic: ";
cin>>ch;
if(ch=='e'||ch=='E')
e=32;
}
f.close();
}
void animation()
{
int i,j,k,l,m,xx;

clrscr();
cleardevice();
setbkcolor(BLACK);
int X=getmaxx();
for(i=0;i<=639;i++)
{
settextstyle(3,0,4);
settextstyle(1,0,4);
setcolor(2);
outtextxy(30,400,"GUIDED by: HARPREET mam");
setcolor(6);
outtextxy(289,159,"Made by");
settextstyle(2,0,6);
setcolor(15);
line(0,330,X,330);
setcolor(3);
rectangle(10+i,270,110+i,310);
setcolor(4);
circle(30+i,320,10);
circle(90+i,320,10);
setcolor(6);
outtextxy(45+i,285,"SATVIK");
setcolor(15);
line(0,80,X,80);
setcolor(3);
rectangle(629-i,20,529-i,60);
setcolor(4);
circle(609-i,70,10);
circle(549-i,70,10);
setcolor(6);
outtextxy(534-i,35,"SHREYANSH");
if(i>=280&&i<=300)
{
xx=25;
if((i%2)==0)
sound(xx);
else
sound(xx+10);
delay(100);
}
else
{
if(i>=300)
xx=30+i-300-10;
else
xx=29+i;
sound(xx);
delay(3);
}
if(i<265||i>275)
cleardevice();
}
nosound();

}
void anim2()
{
int r=10,y=20;
clrscr();
cleardevice();
setbkcolor(BLACK);
for(int i=1;i<=400;i++)
{
settextstyle(2,0,4);
outtextxy(110+i,40,"STUDENT HELPER");
settextstyle(3,0,3);
setcolor(4);
outtextxy(269,180,"STUDENT HELPER");
setcolor(15);
line(130,230,130,240);
line(550,230,550,240);
line(130,230,550,230);
line(325,210,325,240);
settextstyle(1,0,2);
setcolor(9);
outtextxy(130,240,"Physics");
setcolor(2);
outtextxy(325,240,"Chemistry");
setcolor(6);
outtextxy(550,240,"Maths");
setcolor(RED);
circle(100+i,80,y);//tire1
setcolor(WHITE);
line(0,100,639,100);//ROAD
setcolor(BLUE);
line(100+i,80,200+i,80);
setcolor(RED);
circle(200+i,80,y);//tire2
setcolor(BLUE);
line(100+i,80,100+i,40);
line(200+i,80,200+i,50);//front
line(170+i,30,120+i,30);//roof
line(100+i,40,120+i,30);//back
line(200+i,50,170+i,30);//HOOD
setcolor(GREEN);
line(100+i,50,50+i,50);//LINK
setcolor(BROWN);
line(50+i,80,50+i,40);//FRONT2
line(50+i,80,50+i,30);//
setcolor(RED);
line(50+i,30,40+i,48);//SLANT1
setcolor(BROWN);
line(40+i,48,10+i,48);//TOYBASE
setcolor(RED);
line(10+i,48,1+i,31);//SLANT2
setcolor(BROWN);
line(1+i,31,1+i,80);//BACK2
setcolor(BLUE);
line(1+i,80,50+i,80);//BASE2
circle(5+i,90,r);//bktire1
circle(45+i,90,r);//bktire2
setcolor(GREEN);
line(0+i,50,-50+i,50);//LINK1
setcolor(BROWN);
line(-50+i,80,-50+i,40);//FRONT2
line(-50+i,80,-50+i,30);//
setcolor(RED);
line(-50+i,30,-60+i,48);//SLANT1
setcolor(BROWN);
line(-60+i,48,-90+i,48);//TOYBASE1
setcolor(RED);
line(-90+i,48,-99+i,31);//SLANT2
setcolor(BROWN);
line(-99+i,31,-99+i,80);//BACK2
setcolor(BLUE);
line(-99+i,80,-50+i,80);//BASE2
circle(-95+i,90,r);//bktire1
circle(-55+i,90,r);//bktire2
setcolor(GREEN);
line(-100+i,50,-150+i,50);//LINK2
setcolor(BROWN);
line(-150+i,80,-150+i,40);//FRONT2
line(-150+i,80,-150+i,30);//
setcolor(RED);
line(-150+i,30,-160+i,48);//SLANT1
setcolor(BROWN);
line(-160+i,48,-190+i,48);//TOYBASE2
setcolor(RED);
line(-190+i,48,-199+i,31);//SLANT2
setcolor(BROWN);
line(-199+i,31,-199+i,80);//BACK2
setcolor(BLUE);
line(-199+i,80,-150+i,80);//BASE2
circle(-195+i,90,r);//bktire1
circle(-155+i,90,r);//bktire2
setcolor(6);
settextstyle(1,0,3);
outtextxy(20+i,50,"M");
outtextxy(-80+i,50,"C");
outtextxy(-180+i,50,"P");
if(i<=200)
{
sound(20+i+i);
delay(5);
}
else if(i>200&&i<400)
{
sound(420-((i-200)*2));
}
else if(i==400)
{
nosound();
delay(3240);
}
cleardevice();
}
nosound();
}
void thankyou()
{

setbkcolor(14);
setfillstyle(8,15);
floodfill(1,1,1);
settextstyle(10,0,4);
setcolor(1);
outtextxy(140,200,"T");
setcolor(2);
outtextxy(180,200,"H");
setcolor(3);
outtextxy(220,200,"A");
setcolor(4);
outtextxy(260,200,"N");
setcolor(5);
outtextxy(300,200,"K");
setcolor(6);
outtextxy(370,200,"Y");
setcolor(2);
outtextxy(410,200,"O");
setcolor(8);
outtextxy(450,200,"U");
setcolor(5);
outtextxy(480,200,"!");
setcolor(10);
outtextxy(490,200,"!");
setcolor(11);
outtextxy(500,200,"!");

int x=1;
delay(1100);
while(x<321)
{
delay(13);
setcolor(random(7));
line(x,1,x,479);
line(640-x,1,640-x,489);
 x++;
 }
setbkcolor(WHITE);
floodfill(1,1,15);
delay(100);
}