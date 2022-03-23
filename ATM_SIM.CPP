#include<time.h>
#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<graphics.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>
#include<stdio.h>
int x,y,z=0;
union REGS in, out;
void mouseposition(int &xpos,int &ypos,int &click)
{in.x.ax=3;
int86(51,&in,&out);
click=out.x.bx;
xpos=out.x.cx;
ypos=out.x.dx;
}
void setposition(int &xpos,int &ypos)
{in.x.ax=4;
in.x.cx=xpos;
in.x.dx=ypos;
int86(51,&in,&out);
}
void callmouse ()
{
	in.x.ax = 1;
	int86 (0X33,&in,&out);
}
void hide_mouse ()
{
	in.x.ax = 2;
	int86 (0X33,&in,&out);
}

void detect_mouse ()
{
	in.x.ax = 0;
	int86 (0X33,&in,&out);
		if (out.x.ax == 0)
		{cout<<"\nMouse Failed To Initialize";
		 exit(0);}
}

void password(char *);


void screen()
{    cleardevice();
    setbkcolor(BLUE);
  settextstyle(1,0,3);
  setcolor(7);
  outtextxy(215,50,"!!!WELCOME TO ATM!!!");
  rectangle(0,0,638,477);
  setcolor(2);
  rectangle(250,198,380,230);
  outtextxy(265,200,"1.ADMIN");
  rectangle(250,235,380,270);
  outtextxy(265,240,"2.USER");
  rectangle(250,275,380,310);
  outtextxy(265,280,"3.EXIT");

}
void graphics_initialize()
{int gd=DETECT,gm;
 initgraph(&gd,&gm,"..\\BGI");
 detect_mouse();
 callmouse();
}
class admin
{public:
 char pin[5],name[30],fname[30],age[12],ac;long sum,cc_no,contact,pin_change;
 
 void new_user();
 void admin_mainpage();
 void change_pin();
 int count(long);
 void display();
 void delete_account(long);
 void search_account();
 void admin_login();
 void loading(int);
 void box_screen(char *p,char);
 void bar_print(char *p);
 void bar_print(char *p,long req);
 void exit_code();
 void main_page();
 void modify_account();
};
class user:public admin
{public:
user()
{sum=0;pin_change=0;
}
void user_login();
void user_screen();
long transfer();
void user_display();
long fastcash();
long deposit();
void statement(char *p,long amt_req);
void login();
void user_mainpage();
void balance_enquiry();
long withdraw();
void fastcash_screen();
void generate();
void first_login();
int account_type(char *g,char *op1,char *op2);
char ask_invoice(char *g,char *op1,char *op2);
void invoice_screen(char *g,char *op1,char *op2);
};

class time1
{public:char dt[39],action[18];long su,ac;
 void record(char p[15],long s,long a)
 {   time_t t = time(0);
    strcpy(dt,ctime(&t));
    strcpy(action,p);
    su=s;
    ac=a;
 }
void display_record();
 friend class user;
};
void time1::display_record()
{cleardevice();
  int i=0;
  settextstyle(1,0,1);
  setcolor(7);
rectangle(10,10,626,70);
line(10,110,626,110);
line(120,10,120,450);
line(626,10,626,450);
line(360,10,360,450);
line(10,450,626,450);
line(10,40,10,626);
outtextxy(14,14,"Account ");
outtextxy(14,30,"Number");
outtextxy(135,14,"Actions");
outtextxy(370,14,"Time");
fstream fout;     char pa[10];           time1 u;
fout.open("tran.bin",ios::in);fout.seekp(0,ios::beg);
fout.read((char*)&u,sizeof(u));
while(fout)
 { line(10,70+i,626,70+i);
  ltoa(u.ac,pa,10);
  outtextxy(14,74+i,pa);
   outtextxy(150,74+i,u.action);
   outtextxy(370,74+i,u.dt);   i=i+40;
   fout.read((char*)&u,sizeof(u));
 }
 setcolor(2);
fout.close();
getch();
}
void user::invoice_screen(char *g,char *op1,char *op2)
{ cleardevice(); setbkcolor(BLUE);setcolor(15);
  setfillstyle(1,1);
  settextstyle(1,0,2);
  outtextxy(100,100,g);
    outtextxy(500,300,op1);
     outtextxy(500,380,op2);
     rectangle(480,370,560,409);
     rectangle(480,290,560,330);
     settextstyle(0,0,3);

}

char user::ask_invoice(char *g,char *op1,char *op2)
{ clrscr();cleardevice();int a;char p;
 while(1)
  {z=0;
  invoice_screen(g,op1,op2);
    do
    {a=0;mouseposition(x,y,z);
     if(x>480&&x<=560&&y>=370&&y<=409)
       if(z==1)
	  {a=1;}
      if(x>480&&x<=560&&y>=290&&y<=330)
       if(z==1)
	{a=2;}
	switch(a)
	{case 1: p='n';
		 break;
	 case 2:p='y';
		 break;
	}
     }while(z==0);
   return(p);}

}
int user::account_type(char *g,char *op1,char *op2)
{ clrscr();int a,p=0;
 while(1)
  {z=0;
  invoice_screen(g,op1,op2);
    do
    {a=0;mouseposition(x,y,z);
     if(x>480&&x<=600&&y>=370&&y<=409)
       if(z==1)
	 if(ac=='c') {a=1;}
      if(x>480&&x<=600&&y>=290&&y<=330)
       if(z==1)
       if(ac=='s') {a=2;}
	switch(a)
	{case 1: p=1;
		 break;
	 case 2:p=1;
		 break;
	}
     }while(z==0);
   return(p);}
}


void user::statement(char *p,long amt_req)
{cleardevice();
 char dt[10];
 setcolor(15);
  setfillstyle(1,1);
  settextstyle(1,0,2);
 outtextxy(270,10,"ATM receipt");
 outtextxy(0,45,"--------------------------------------------------------------------------------");
 outtextxy(50,75,"Date:");
 outtextxy(250,75,"Time:");
 time_t t = time(0);
 strcpy(dt,ctime(&t));
 outtextxy(50,105,dt);
 outtextxy(50,135,"Card Number:");
 sprintf(dt,"%ld",cc_no%100);
 outtextxy(215,135,dt);
 outtextxy(190,135,"XX");
 outtextxy(50,180,"Terminal:");
 outtextxy(175,180,"#");
 srand((unsigned) time(&t));
 long n = rand() % (99999-2000+1) + 1;
 sprintf(dt,"%ld",n);
  outtextxy(186,180,dt);
 outtextxy(50,230,"Transaction's form:");
 outtextxy(250,230,p);
 if(stricmp("transfer",p)!=0)
   {outtextxy(50,280,"Amount Requested:");
	gotoxy(35,19);cout<<amt_req;
   }
 if(stricmp("transfer",p)==0)
	{outtextxy(50,280,"Transferred to:");
	 gotoxy(35,19);cout<<amt_req;
	}
 outtextxy(50,330,"Account balance:");
 sprintf(dt,"%ld",sum);
 outtextxy(250,330,dt);
outtextxy(0,365,"--------------------------------------------------------------------------------");
outtextxy(180,380,"Thank you for banking with us!");
outtextxy(230,410,"Visit Us Online");
outtextxy(278,430,"OR");
outtextxy(140,450,"Call our Customer Care Service Line 01-4455445");
     settextstyle(0,0,3);
  {delay(1800);getch();cleardevice(); exit_code();}
}

void user::first_login()
{clrscr();cleardevice();
 bar_print("Welcome to our banking service and please change your pincode as a random pincode has been generated for your account.Thank you!!!!");
delay(1000);
}
void admin::exit_code()
 {clrscr();cleardevice();bar_print("Thank you for using our banking services, please visit us again");
  exit(0);
 }

void admin::bar_print(char *p,long req)
 {clrscr(); cleardevice();setcolor(15);int i,len;char ra[15],*s="Rs ";
  setfillstyle(1,8);
   sprintf(ra,"%ld",req);
   strcat(s,ra);
  strcat(s,p);
  len=strlen(s);
  bar(60,150,len*11+110,250);
  settextstyle(1,0,2);
  if(len<49) outtextxy(80,170,s);
  else
   {char *r;
    for(i=0;i<49;i++)
      {  r[i]=s[i];
      }
      outtextxy(80,170,r);
       for(i=49;i<len;i++)
	{r[i-49]=s[i];
	}
	 outtextxy(80,200,r);
   }
  settextstyle(0,0,3);
  delay(2000);
  
 }

void admin::bar_print(char *p)
{ cleardevice();setcolor(15);int i,len;
  setfillstyle(1,8);
  len=strlen(p);
  bar(60,150,len*11+110,250);
  settextstyle(1,0,2);
  if(len<49) outtextxy(80,170,p);
  else
   {char *r;
    for(i=0;i<49;i++)
      {  r[i]=p[i];
      }
      outtextxy(80,170,r);
       for(i=49;i<len;i++)
	{r[i-49]=p[i];
	}
	 outtextxy(80,200,r);
   }
  settextstyle(0,0,3);
  delay(2000);
}

void admin::loading(int a)
{ cleardevice();
    int c=0,i=0,r;
   time_t t;
setcolor(15);
  setfillstyle(1,1);
  settextstyle(1,0,2);
   srand((unsigned) time(&t));
  switch(a)
  {case 1: rectangle(30,150,620,250);          gotoxy(1,12);
   outtextxy(40,170,"Please wait while your transaction is being proceed");
   gotoxy(72,12);
    do
    {
    a: i=rand()%(233-17)+17;
    r=rand()%(799-240)+2;
    r=r%i;
    c++;
    cout<<"."; delay(300);
    if(c%3==0) { bar(568,170,598,200);gotoxy(72,12);delay(150);}
    if(c<4) goto a;
    }while(r%3!=0) ;    break;
   case 2: rectangle(230,170,380,230);  gotoxy(7,12);
	   outtextxy(252,184,"Loading");       gotoxy(43,13);
    do
    {
    m: i=rand()%(233-17)+17;
    r=rand()%(799-240)+2;
    r=r%i;
    c++;
    cout<<"."; delay(300);
    if(c%3==0) { bar(329,190,360,210);gotoxy(43,13);delay(150);}
    if(c<4) goto m;
    }while(r%3!=0) ;
   break;
   case 3: rectangle(230,170,400,230);  gotoxy(7,12);
	   outtextxy(252,184,"Logging Out");       gotoxy(47,13);
    do
    {
    n: i=rand()%(233-17)+17;
    r=rand()%(799-240)+2;
    r=r%i;
    c++;
    cout<<"."; delay(150);
    if(c%3==0) { bar(369,190,390,210);gotoxy(47,13);delay(150);}
    if(c<4) goto n;
    }while(r%3!=0) ;
   break;
  }
  settextstyle(0,0,3);
  clrscr();
  cleardevice();
}

void user::generate()
{long n;
 user obj;
 time_t t;
 fstream fin;
 fin.open("Data9.bin",ios::in);
 do{
  srand((unsigned) time(&t));
  fin.read((char*)&obj,sizeof(obj));
  n = rand() % (99999-10001+1) + 1;
  }while(obj.cc_no==n&&(!fin.eof()));
 fin.close();
 cc_no=n;
}

void admin::box_screen(char *p,char r='p')
{ clrscr();cleardevice();
setbkcolor(BLUE);
setcolor(1);
  setfillstyle(1,8);
  bar(90,100,550,400);
  settextstyle(1,0,2);
  outtextxy(100,120,p);
  settextstyle(1,0,1);
  if(r=='r') outtextxy(210,175,"RS");
  setfillstyle(1,7);
  bar(245,170,390,200);
  gotoxy(33,12);
}
void frontscreen()
{
do{
for(int i=0;i<15;i++)
{

if(kbhit())
 break;
setbkcolor(BLACK);
settextstyle(4,0,5);
outtextxy(250,70,"WELCOME");
delay(100);
outtextxy(315,140,"TO");
delay(100);
outtextxy(300,210,"OUR");
delay(100);
outtextxy(275,280," ATM");
delay(100);
setcolor(i);
settextstyle(4,0,2);
outtextxy(205,400,"  Press any key to continue...");
 }
}while(!kbhit());

 }

void user::fastcash_screen()
{clrscr();cleardevice();

  setbkcolor(BLUE);
  settextstyle(1,0,2);
  setcolor(7);
  outtextxy(200,100,"PLEASE SELECT AN OPTION");
  rectangle(0,0,638,477);
  setcolor(2);

  rectangle(10,198,50,230);
  outtextxy(25,200,"1");
  rectangle(70,198,300,230);
  outtextxy(75,200,"   Rs 1000");


   rectangle(10,260,50,292);
   outtextxy(25,262,"2");
    rectangle(70,260,300,292);
    outtextxy(75,262,"   Rs 2000");


   rectangle(10,322,50,354);
   outtextxy(25,324,"3");
    rectangle(70,322,300,354);
    outtextxy(75,324,"   Rs 5000");

    rectangle(10,386,50,416);
     outtextxy(25,386,"4");
   rectangle(70,385,300,416);
   outtextxy(75,386,"   Rs 8000");

  rectangle(590,198,630,230);
  outtextxy(605,200,"5");
  rectangle(340,198,570,230);
  outtextxy(345,200,"   Rs 10000");


   rectangle(340,260,570,292);
    outtextxy(605,262,"6");
   rectangle(590,260,630,292);
   outtextxy(345,262,"   Rs 15000");


   rectangle(340,322,570,354);
   outtextxy(605,324,"7");
   rectangle(590,322,630,354);
   outtextxy(345,324,"   Rs 20000");

   rectangle(340,386,570,416);
    outtextxy(605,386,"8");
   rectangle(590,386,630,416);
   outtextxy(345,386,"   Rs 25000");
}

long user::withdraw()
{cleardevice();int i=0;
long s;
 ap:
box_screen("Enter the amount you want to withdraw",'r');
cin>>s;
if(s<=sum)
 {sum=sum-s;
  bar_print(" has been deducted sucessfully.",s);
 }
 else{
 bar_print("Invalid choice");i++;
   if(i<=2) goto ap;
    else exit_code();
     }
     return s;
}

void admin::modify_account()
{       int  c=0;      cleardevice();
long sr;int a,loc;
box_screen("Enter account number to be modified:");
cin>>sr;
user u;
fstream fsr,fwr;
fsr.open("data9.bin",ios::in);
fwr.open("data9.bin",ios::app);
fsr.read((char*)&u,sizeof(u));
while(fsr)
 {if(u.cc_no==sr)
    {c=1;clrscr();cleardevice();
      cout<<"\n1.Update Name\n2.Update DOB\n3.Update contact number\n\n\n\tPress any key to goto homescreen\n";
       cin>>a;
       if(a>=1&&a<=3) delete_account(u.cc_no);
       switch(a)
       {case 1:clrscr();cout<<"\nEnter new name:";cin>>u.name;break;
       case 2:clrscr();cout<<"\nEnter new DOB:";
	      cin>>u.age;break;
       case 3:clrscr();cout<<"\nEnter new contact number:";
	      cin>>u.contact;break;
       default:clrscr();admin_mainpage();
       }

	fwr.write((char*)&u,sizeof(u));
      bar_print("Sucessfully modified");delay(1000);
     }

	fsr.read((char*)&u,sizeof(u));
 } fsr.close();   fwr.close();

 if(c==0)
     {bar_print("Account doesn't exist");
      }

}

void admin::search_account()
{cleardevice();int c=0;
long sr;
box_screen("Enter Credit Card Number to be searched:");
cin>>sr;
user u;
fstream fsr;
fsr.open("data9.bin",ios::in);
fsr.read((char*)&u,sizeof(u));
while(fsr)
 {if(u.cc_no==sr)
   {loading(1);c=1;clrscr();cleardevice();cout<<"\nAccount found";
   cout<<"\nDo you want to display the details(Y/N)?\n";
   if(getch()=='y'||getch()=='Y') {loading(2);cleardevice();u.display();delay(3000); break; }
   }
  fsr.read((char*)&u,sizeof(u));
 }
  if(c==0)
  {bar_print("Account doesn't exist");
   }
    fsr.close();
}

void admin::delete_account(long nm)
{cleardevice();loading(1);int c=0;
user obj,temp;
fstream finout,ftemp;
finout.open("data9.bin",ios::in);finout.seekg(0,ios::beg);
 ftemp.open("temp.bin",ios::out|ios::trunc);ftemp.seekg(0,ios::beg);
 finout.read((char*)&temp,sizeof(temp));
 while(finout)
  {if(temp.cc_no==nm) c=1;
    if(temp.cc_no!=nm)
    {ftemp.write((char*)&temp,sizeof(temp));
      }
    finout.read((char*)&temp,sizeof(temp));
  }ftemp.close();finout.close();
  finout.open("data9.bin",ios::out);
  ftemp.open("temp.bin",ios::in);ftemp.seekg(0,ios::beg);
  ftemp.read((char*)&temp,sizeof(temp));
  while(ftemp)
   {
    finout.write((char*)&temp,sizeof(temp));
   ftemp.read((char*)&temp,sizeof(temp));
   }
   ftemp.close();
  finout.close();
 if(c==0) bar_print("Account doesn't exist, please enter valid parameters");
}



int admin::count(long s)
{int count;
while(s!=0)
  {s=s/10;count++;
  }
  return(count);
}

void user::balance_enquiry()
{cleardevice();
 box_screen("Your total balance is ",'r');cout<<sum<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\tPress any key to continue";getch();
}

void admin::change_pin()
{clrscr();cleardevice();setbkcolor(BLUE);
char s[6],g[6];
outtextxy(50,60,"Enter old pin");
setcolor(15);
rectangle(375,55,490,85);
setfillstyle(SOLID_FILL,RED);
floodfill(386,65,15);
gotoxy(52,5);
password(s);
if(strcmp(s,pin)==0)
 {
 setcolor(15);
outtextxy(50,188,"Enter new pin");
 rectangle(375,188,490,215);
 setfillstyle(SOLID_FILL,RED);
 floodfill(386,195,15);
 gotoxy(52,13);
 password(g);
  if(strcmp(g,s)!=0)
   {strcpy(pin,g);pin_change+=1;
   loading(1);
   bar_print("Your pincode has been changed");
   }
   else
   bar_print("New password matches with old pincode");
 }
 else bar_print("Invalid pincode");
}
void password(char *pass)
{
char ch;int i=0;
 while((ch=getch())!=13)
  {
       if(ch==8)
     {if(i==0) continue;
     cout<<"\b \b";i--;continue;
     }
    cout<<"*";
    pass[i]=ch;
    i++;
  }
    pass[i]='\0';
}

long user::transfer()
{cleardevice();
long cc,bal;
user tra;
fstream fin1,fin2;
 fin1.open("data9.bin",ios::in);
   box_screen("Enter account number to transfer:");
   cin>>cc;
   loading(1);
 do{
    fin1.read((char*)&tra,sizeof(tra));
  }while(cc!=tra.cc_no&&fin1);
   if(cc==tra.cc_no)
   {box_screen("Enter amount to be transferred:",'r');
    cin>>bal;
    if(sum-bal>=0)
     {tra.sum+=bal;
       sum=sum-bal;
       delete_account(tra.cc_no);
       fin2.open("data9.bin",ios::app);
       fin2.write((char*)&tra,sizeof(tra));
	time1 t;
       t.record("Transfer",bal,cc_no);
       ofstream fout;
       fout.open("tran.bin",ios::app);
       fout.write((char*)&t,sizeof(t));
       fout.close();
       bar_print(" has been transferred",bal);delay(800);
       }
      else
      {bar_print("!!!!!Please enter valid parameters!!!!!");delay(800);
      }
  }
   else
  {bar_print("Account number doesn't exist");delay(800);
  }
 return(cc);
}

long user::deposit()
{cleardevice();
long s;
box_screen("Enter the amount you want to deposit",'r');
cin>>s;
sum=sum+s;
loading(1);
bar_print(" has been deposited sucessfully",s);
time1 t;
t.record("deposit",s,cc_no);
ofstream fout;
fout.open("tran.bin",ios::app);
fout.write((char*)&t,sizeof(t));
fout.close();
return(s);
getch();
}
void user::user_screen()
{ cleardevice(); callmouse();
   setbkcolor(BLUE);
  settextstyle(1,0,2);
  setcolor(7);
  outtextxy(215,30,"PLEASE SELECT AN OPTION");
  rectangle(0,0,638,477);
  setcolor(2);

  rectangle(25,98,200,130);
  outtextxy(25,100,"      Deposit");


    rectangle(25,190,200,222);
    outtextxy(25,192,"      Fast Cash");



    rectangle(25,284,200,316);
    outtextxy(25,286,"      Display");


   rectangle(25,385,200,416);
   outtextxy(25,387,"     Log Out");

  rectangle(440,98,610,130);
  outtextxy(445,100,"    Transfer");



   rectangle(440,190,610,222);
   outtextxy(445,192,"     Change pin");


   rectangle(440,284,610,316);
   outtextxy(445,286,"      Balance enquiry");

   rectangle(440,385,610,416);
   outtextxy(445,387,"      Withdraw");

}
void user::user_display()
{cleardevice();
 setbkcolor(BLUE);
  callmouse();
  settextstyle(1,0,2);
  setcolor(7);
  outtextxy(215,50,"Your personal details are:");
  rectangle(0,0,638,477);
  setcolor(5);
  rectangle(90,100,550,450);
  setcolor(1);
  setfillstyle(1,9);
  bar(90,100,550,450);
  settextstyle(1,0,2);
  line(290,100,290,320);
  line(295,100,295,320);
  line(90,140,550,140);
  line(90,170,550,170);
  line(90,200,550,200);
  line(90,230,550,230);
  line(90,260,550,260);
  line(90,290,550,290);
  line(90,350,550,350);
  line(90,395,550,395);
   line(90,320,550,320);
  outtextxy(100,110,"Name:");
  outtextxy(105,140,"Account Type(s/c)");
  outtextxy(100,170,"Date of Birth");
  outtextxy(100,200,"Father's Name:");
  outtextxy(100,230,"Contact NO:");
  outtextxy(100,260,"Credit Card NO:");
  outtextxy(100,290,"Sum:");
  gotoxy(40,8);
 cout<<name;
  gotoxy(40,10);
 if(ac=='s'||ac=='S') cout<<"Saving";
 if(ac=='c'||ac=='C') cout<<"Current";
  gotoxy(40,12);
  cout<<age;
  gotoxy(40,14);
  cout<<fname;
  gotoxy(40,16);
     cout<<contact;
  gotoxy(40,18);
  cout<<cc_no;
  gotoxy(40,20);
  cout<<sum;
  }
void user::user_login()
{clrscr();cleardevice();setbkcolor(BLUE);
callmouse();
setcolor(1);
  setfillstyle(1,8);
  bar(190,150,500,300);
  settextstyle(1,0,2);
  outtextxy(250,150,"******* User *******");
  line(190,180,500,180);
  line(190,185,500,185);
  settextstyle(1,0,1);
  outtextxy(200,200,"CC no:");
  outtextxy(200,235,"Pin no:");
  setfillstyle(1,7);
  bar(270,200,400,225);
  bar(270,235,400,260);

}

void user::user_mainpage()
{
 setbkcolor(BLUE);
 setposition(2,2);char ask,co;
long amt_req=0;
int a=0,c=0;callmouse();
 fstream fin,fout,ff;
user obj;char p[6];long s;
 user_login();
  gotoxy(36,14);
  cin>>s;
  gotoxy(36,16);
  password(p);
      fin.open("data9.bin",ios::in);fin.seekg(0,ios::beg);
      fin.read((char*)&obj,sizeof(obj));
    while(!fin.eof())
 {if( (strcmp(obj.pin,p)==0&&(s==obj.cc_no) &&(obj.pin_change==0)&&obj.account_type("Please choose your account setting !","Saving","Current")==1))
   {c=1;first_login();
    // system("cls");graphics_initialize();
     obj.change_pin();
     delete_account(obj.cc_no);
     ff.open("data9.bin",ios::app);
     ff.write((char*)&obj,sizeof(obj));
     ff.close();
    }
  if( (strcmp(obj.pin,p)==0&&(s==obj.cc_no) &&(obj.pin_change!=0)&&obj.account_type("Please choose your account setting !","Saving","Current")==1))
  { c=1;
  while(1)
   {callmouse();setposition(2,2);// system("Cls");graphics_initialize();
    z=0;
    user_screen();amt_req=0;
    do
    { a=0;
     mouseposition(x,y,z);
     if( z==1&&(x>=25&&x<201)&&(y>=98&&y<=130))
      { {a=1;z=0;}
      }
     if(z==1&& (x>=25&&x<201)&&(y>=190&&y<=222))
      {   {a=2;z=0;}
       }
     if(z==1&& (x>=25&&x<201)&&(y>=284&&y<=316))
      { {a=3;z=0;}
       }
      if(z==1&& (x>=25&&x<201)&&(y>=385&&y<=416))
      { {a=4;z=0;}
	}
      if(z==1&& (x>=440&&x<611)&&(y>=98&&y<=130))
      { {a=5;z=0;}
      }
      if(z==1&&(x>=440&&x<611)&&(y>=190&&y<=222))
     { {a=6;z=0;}
     }
     if(z==1&&(x>=440&&x<611)&&(y>=284&&y<=316))
     { {a=7;z=0;}
      }
     if(z==1&&(x>=440&&x<611)&&(y>=385&&y<=416))
     { {a=8;z=0;}
      }
 switch(a)
  {case 1:clrscr();
	   loading(2);
	   ask= ask_invoice("Do you want printed invoice?","Yes","No");
	   loading(2);
	   // system("cls");graphics_initialize();
	   amt_req=obj.deposit();
	  delete_account(obj.cc_no);
	    ff.open("data9.bin",ios::app);
	     ff.write((char*)&obj,sizeof(obj));
	    ff.close();
	   co=ask_invoice("Do you want to continue?","Yes","No");
	    if(ask=='y'&&co=='n')  {obj.statement("Deposit",amt_req);}
	   if(ask=='n'&&co=='n') {exit_code();}
	   break;
   case 2: clrscr();loading(2);
		//system("cls");graphics_initialize();
	   amt_req=obj.fastcash();
	   ask= ask_invoice("Do you want printed invoice?","Yes","No") ;
	 //system("cls");graphics_initialize();
	   loading(2);
	   delete_account(obj.cc_no);
	    ff.open("data9.bin",ios::app);
	      ff.write((char*)&obj,sizeof(obj));
	     ff.close();time1 t;
             t.record("Deleted",0,cc_no);
     		  ofstream fout;
    	     fout.open("tran.bin",ios::app);
      	     fout.write((char*)&t,sizeof(t));
       		fout.close();
	    co=ask_invoice("Do you want to continue?","Yes","No");
	    if(ask=='y'&&co=='n')  {obj.statement("Fastcash",amt_req);}
	   if(ask=='n'&&co=='n') {exit_code();}
	   break;
   case 3: clrscr();loading(2);
	   //system("cls");graphics_initialize();
	   obj.user_display();getch();
	   break;
    case 4:clrscr();loading(3);//system("cls");graphics_initialize();
	    main_page();break;
    case 5:clrscr();
	   loading(2);
	     //	system("cls");graphics_initialize();
	      amt_req=obj.transfer();
	      ask= ask_invoice("Do you want printed invoice?","Yes","No");
	     loading(2);
	    delete_account(obj.cc_no);
	     ff.open("data9.bin",ios::app);
	    ff.write((char*)&obj,sizeof(obj));
	     ff.close();
		co=ask_invoice("Do you want to continue?","Yes","No");
	   if(ask=='y'&&co=='n') {obj.statement("Transfer",amt_req);}
	   if(ask=='n'&&co=='n') {exit_code();}
	     break;

    case 6:clrscr();
	   loading(2);
	   obj.change_pin();
	    delete_account(obj.cc_no);
	      ff.open("data9.bin",ios::app);
	     ff.write((char*)&obj,sizeof(obj));
	     ff.close();
	    break;
     case 7:clrscr();
	   loading(2);
	   ask= ask_invoice("Do you want printed invoice?","Yes","No") ;
	   loading(2);
	   // system("cls");graphics_initialize();
	    obj.balance_enquiry();delay(1300);
	   co=ask_invoice("Do you want to continue?","Yes","No");
	   if(ask=='y'&&co=='n') {obj.statement("Balance enquiry",0);}
	  if(ask=='n'&&co=='n') {exit_code();}
	   break;
     case 8:clrscr();
	    loading(2);
	    ask= ask_invoice("Do you want printed invoice?","Yes","No") ;
	    loading(2);
		//system("cls");graphics_initialize();
	    amt_req=obj.withdraw();
	     delete_account(obj.cc_no);
	     ff.open("data9.bin",ios::app);
	    ff.write((char*)&obj,sizeof(obj));
	     ff.close();
	co=ask_invoice("Do you want to continue?","Yes","No");
	   if(ask=='y') {obj.statement("Withdraw",amt_req);}
	  if(ask=='n'&&co=='n') {exit_code();}
	     break;
     }

    }while(a==0);
   }
  }


	 fin.read((char*)&obj,sizeof(obj))  ;
 }
	if(c==0) bar_print("Invalid Credit card number or pincode");
	fin.close();

}

void admin::display()
{cout<<"--------------------------------------------------------------------------------\n";
cout<<"\tName: "<<name<<"\n\tAge: "<<age<<"\n\tFather's Name: "<<fname<<"\n\tContact: "<<contact<<"\n\tAccount type :";
if(ac=='s') cout<<"Saving";
if(ac=='c') cout<<"Current";
cout<<"\n\tCredit card: "<<cc_no<<"\n\tSum: "<<sum<<"\n";
cout<<"--------------------------------------------------------------------------------\n";
}




long user::fastcash()
{
int s=0,b;
  time1 t;

 {
 clrscr();
  fastcash_screen();

do{
 b=0;
  mouseposition(x,y,z);
      if((x>=70&&x<301)&&(y>=198&&y<=230))
      if(z==1)
 {  b=1;
 }
  if((x>=70&&x<301)&&(y>=260&&y<=292))
  if(z==1)
  { b=2;
  }
  if((x>=70&&x<301)&&(y>=322&&y<=354))
  if(z==1)
  { b=3;
  }
    if((x>=70&&x<301)&&(y>=385&&y<=416))
  if(z==1)
  { b=4;
  }
  if((x>=340&&x<571)&&(y>=198&&y<=230))
  if(z==1)
  { b=5;
  }
  if((x>=340&&x<=570)&&(y>=260&&y<=292))
  if(z==1)
  { b=6;
  }
  if((x>=340&&x<=570)&&(y>=322&&y<=354))
  if(z==1)
  { b=7;
   }

  if((x>=340&&x<=570)&&(y>=386&&y<=416))
  if(z==1)
  { b=8;
   }
    switch(b)
    {
      case 1:
      if(sum<1000)
      {
        bar_print("Insufficient balance");
       }
      else
      {sum=sum-1000;   s=1000;
       bar_print("The remaining balance is ",sum);return(sum);
       }
       break;
       case 2:
	if(sum<2000)
	  {
	    bar_print("Insufficient balance");
	    }
	else
	    {sum=sum-2000;    s=2000;
	    bar_print("The remaining balance is ",sum);return(sum);
		      }
	     break;
	 case 3:
	     if(sum<5000)
	       {
		  bar_print("Insufficient balance");
		}
		 else
		  {sum=sum-5000;     s=5000;
		    bar_print("The remaining balance is ",sum);return(sum);
		   }
		    break;
		   case 4:
		    if(sum<8000)
		     {
		       bar_print("Insufficient balance");
		       }
		     else
			 {sum=sum-8000;     s=8000;
			   bar_print("The remaining balance is ",sum); return(sum); }
			 break;
		      case 5:
			     if(sum<10000)
			     {
			      bar_print("Insufficient balance");
				 }
			else
			   {sum=sum-10000;
			   s=10000;
			   bar_print("The remaining balance is ",sum);}return(sum);break;
		      case 6:  if(sum<15000)
			     {
			      bar_print("Insufficient balance");
				 }
			else
			   {sum=sum-15000;bar_print("The remaining balance is",sum);return(sum);}break;
		      case 7: if(sum<20000)
			     {
			      bar_print("Insufficient balance");
				 }
			else
			   {sum=sum-20000;
			   s=20000;bar_print("The remaining balance is",sum);return(sum);}break;

		      case 8:if(sum<25000)
			     {
			     bar_print("Insufficient balance");
				 }
			else
			   {sum=sum-20000;
			   s=20000;bar_print("The remaining balance is",sum);return(sum);}break;
	    }

}while(b==0);

   if(s<sum)
    {
	t.record("withdrawn",s,cc_no);
	ofstream fout;
	fout.open("tran.bin",ios::app);
	fout.write((char*)&t,sizeof(t));
	fout.close();delay(1300);
    }
    else s=0;

  }
    return s;
}

void insideadmin()
{ clrscr();cleardevice();

  callmouse();
  setbkcolor(BLUE);
  setposition(2,2);
  settextstyle(1,0,2);
  setcolor(7);
  outtextxy(215,40,"PLEASE SELECT AN OPTION");
  rectangle(0,0,638,477);
  setcolor(2);
 rectangle(220,138,470,173);
 outtextxy(245,142,"Change password");
 rectangle(220,138,470,173);
 outtextxy(245,142,"Change password");
  rectangle(220,178,470,210);
  outtextxy(245,180,"NEW USER");
  rectangle(220,215,470,250);
  outtextxy(245,220,"DISPLAY ALL USER ");
  rectangle(220,255,470,290);
  outtextxy(245,260,"DELETE");
rectangle(220,295,470,330);
  outtextxy(245,300,"SEARCH");
rectangle(220,335,470,370);
  outtextxy(245,340,"MODIFY");
rectangle(220,375,470,410);
  outtextxy(245,380,"Transactions");
rectangle(220,420,470,455);
  outtextxy(245,425,"Log Out");

}

void admin::admin_mainpage()
{int a=0;user obj;z=0;callmouse();
fstream fin;
while(1)
{z=0;
insideadmin();
setposition(2,2);

do
{a=0;
 mouseposition(x,y,z);
  if(x>=220&&x<=470&&y>=138&&y<=173)
   {
	if(z==1) {a=8;z=0;}
    }
    if(x>=220&&x<=470&&y>=178&&y<=210)
    {if(z==1) {a=1;z=0;}
    }
    if(x>=220&&x<=470&&y>=215&&y<=250)
    {if(z==1) {a=2;z=0;}
    }
    if(x>=220&&x<=470&&y>=255&&y<=290)
    {if(z==1) {a=3;z=0;}
    }
    if(x>=220&&x<=470&&y>=295&&y<=330)
    {if(z==1) {a=4;z=0;}
    }
    if(x>=220&&x<=470&&y>=335&&y<=370)
    {if(z==1) {a=5;z=0;}
    }
    if(x>=220&&x<=470&&y>=375&&y<=410)
    {if(z==1) {a=6;z=0;}
    }
     if(x>=220&&x<=470&&y>=420&&y<=455)
    {if(z==1) {a=7;z=0;}
    }

  switch(a)
   {case 1:clrscr();loading(2);new_user();break;
    case 2:clrscr();
	    cleardevice();
	    loading(2);
	    fin.open("data9.bin",ios::in);
	     fin.seekg(0,ios::beg);
	     fin.read((char*)&obj,sizeof(obj));
	     while(fin)
		{obj.display();fin.read((char*)&obj,sizeof(obj));
		 }
		 fin.close();
		 getch();
		 break;
   case 3:clrscr();
	   loading(2);
	   long nm;box_screen("Enter Credit Card number to delete:");cin>>nm;delete_account(nm);bar_print("Account deleted sucessfully");break;
   case 4:clrscr();loading(2);
	  search_account();break;
   case 5:clrscr();modify_account();break;
   case 6:clrscr();
	   loading(2);time1 t;
	    t.display_record();break;
   case 7:clrscr();loading(3);main_page();break;
   case 8:break;
  }
 }while(a==0);
 }
}
void admin::new_user()
{ user obj;
 clrscr();
 cleardevice();
callmouse();
  settextstyle(1,0,2);
  setcolor(7);
  outtextxy(215,50,"PLEASE FILL UP THE FORM");
  rectangle(0,0,638,477);
  setcolor(5);
  rectangle(90,100,550,450);
  setcolor(1);
  setfillstyle(1,9);
  bar(90,100,550,450);
  settextstyle(1,0,2);
  line(290,100,290,320);
  line(295,100,295,320);
  line(90,140,550,140);
  line(90,170,550,170);
  line(90,200,550,200);
  line(90,230,550,230);
  line(90,260,550,260);
  line(90,290,550,290);
  line(90,320,550,320);
  line(90,350,550,350);
  line(90,395,550,395);
  outtextxy(100,110,"Name:");
  outtextxy(100,140,"Account Type(s/c)");
  outtextxy(100,170,"Date of Birth");
  outtextxy(100,200,"Father's Name:");
  outtextxy(100,230,"Contact NO:");
  outtextxy(100,260,"Credit Card NO:");
   outtextxy(100,290,"Pincode:");
  outtextxy(100,358,"  ***Please fill up the form carefully***");
   gotoxy(40,8);
 cin>>obj.name;
  gotoxy(40,10);
 cin>>obj.ac;
  gotoxy(40,12);
cin>>obj.age;
  gotoxy(40,14);
 cin>>obj.fname;
gotoxy(40,16);
cin>>obj.contact;
 obj.generate();

 char cc[8];
  sprintf(cc,"%ld",obj.cc_no);
  outtextxy(298,260,cc);
  strcpy(obj.pin,"1234");
  outtextxy(298,290,"1234");
       ofstream fout;
       fout.open("data9.bin",ios::app);
       fout.write((char*)&obj,sizeof(obj));
       fout.close(); 
    fout.open("tran.bin",ios::app);
    fout.close();
delay(2000);
bar_print("Account sucessfully created");
time1 t;
t.record("account created",obj.sum,obj.cc_no);

fout.open("tran.bin",ios::ate);
fout.write((char*)&t,sizeof(t));
fout.close();
getch();

}


void adminlogin()
{cleardevice();callmouse();setbkcolor(BLUE);
 setcolor(1);
  setfillstyle(1,8);
  bar(190,150,500,300);
  settextstyle(1,0,2);
  outtextxy(250,170,"******* ADMIN *******");
  settextstyle(1,0,1);
  outtextxy(263,220,"PASSWORD:");
  setfillstyle(1,7);
  bar(360,220,450,245);
  gotoxy(47,15);
}
     void admin::admin_login()
     {char p[6];int i=0,c=0;
       do
       {
       adminlogin();
       password(p);
	 if(strcmp(p,"12345")==0) {loading(2);cleardevice();admin_mainpage();c=1;break;}
	 else i++;
	if(i==3)
     {bar_print("!!!Maximum limit reached please try again later!!!");
    exit(0);
      }
  }while(strcmp(p,"12345")!=0);
  if(c==0) bar_print("Invalid choice");
  }

void admin::main_page()
{int a=0;callmouse();
while(1)
{clrscr();z=0;
screen();
  do
  { a=0;   mouseposition(x,y,z);
   if(x>=250&&x<=380&&y>=198&&y<=230)
    {if(z==1) {a=1;z=0;}
     }
      if(x>=250&&x<=380&&y>=235&&y<=270)
    {if(z==1) {a=2;z=0;}
     }
       if(x>=250&&x<=380&&y>=275&&y<=310)
    {if(z==1) {a=3;z=0;}
     }
     switch(a)
     {case 1:clrscr();loading(2);
	     system("cls");graphics_initialize();admin_login();break;
      case 2:clrscr();
	      loading(2);system("cls");graphics_initialize();
	     user u;u.user_mainpage();break;
      case 3:exit_code();
     }
   } while(a==0);
  }
}


void main()
{
clrscr();
user u;
graphics_initialize();
frontscreen();
u.main_page();
hide_mouse();
closegraph();
getch();
}
