// BANK MANAGEMENT SYSTEM - USING HASHING WITH TEXTFILE

#include<math.h>
#include<iostream.h>
#include<ctype.h>
#include<conio.h>
#include<graphics.h>
#include<process.h>
#include<fstream.h>
#include<dos.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>



union REGS in,out;
ifstream fin;
ofstream fout;

void screen();   // LOGIN SCREEN
void draw_1();   // BANKING SCREEN
void draw_2();   // LOANS SCREEN
void ms();       // MAIN SCREEN
void login(char[],char[]);   // FUNCTION TO LOGIN
void conc();     // TO CONCLUDE AND EXIT

void create();   // TO CREATE A NEW ACCOUNT
void view();     // TO VIEW EXISTING BANK ACCOUNTS
void del();      // TO DELETE BANK ACCOUNTS
void edit();     // TO EDIT BANK ACCOUNTS

void newloan();     // TO CREATE NEW LOAN
void oldloan();     // TO VIEW EXISTING LOAN
void tariff();      // TO DISPLAY TARIFF
void clearloan();   // TO CLEAR LOANS

int search(long,int);     // TO SEARCH FOR A RECORD
void Remove(int,int);               // TO REMOVE A RECORD
void display(int);              // TO DISPLAY A SPECIFIC RECORD
void declare();                  // TO WITHDRAW OR DEPOSITE
void modify(int,unsigned long);     // TO MODIFY A SPECIFIC RECORD

void bank();            // TO DISPLAY TRANASACTIONS SCREEN
void l_unpack();

int r,z,l,k;

void hit()              //  A BREAK TO RETURN TO MAIN SCREEN
{
  cleardevice();
  setcolor(10);
  settextstyle(1,0,3);
  outtextxy(30,30,"PRESS ANY KEY");
}


void screen()
{
  cleardevice();

  setcolor(10);
  settextstyle(3,0,0);
  outtextxy(200,15,"W E L C O M E");
  setcolor(RED);
  setlinestyle(0,2,3);
  line(190,60,450,60);

  setcolor(14);
  outtextxy(60,70," ");
  setlinestyle(3,2,3);
 // line(60,110,130,110);
  outtextxy(130,100,"GLOBAL BANK OF INDIA");

  int poly[]={200,150,90,350,310,350,200,150};
  setcolor(GREEN);
  setfillstyle(1,12);
  fillpoly(4,poly);

  setcolor(BROWN);
  circle(200,205,55);
  circle(90,350,55);
  circle(310,350,55);
  setfillstyle(1,CYAN);
  floodfill(200,205,BROWN);
  floodfill(90,350,BROWN);
  floodfill(310,350,BROWN);

  setcolor(15);
  outtextxy(190,190,"G");
  outtextxy(80,330,"U");
  outtextxy(310,330,"I");

  setcolor(BLUE);
  outtextxy(150,280,"  FS");

  setcolor(8);
  outtextxy(100,420,"Graphical User Interface");

  setcolor(12);
  settextstyle(3,0,1);
  outtextxy(250,455," Powered by Global Academy of Technology ");


  gotoxy(55,14);
  cout<<"LOGIN !!";
  char usn[10];
  gotoxy(50,17);
  cout<<"ENTER USERNAME : ";
  cin>>usn;
  gotoxy(50,18);
  cout<<"ENTER PASSCODE : ";
  int i=0;
  char  ch,x,c[20];
  while(i>=0)
   {
     ch=getch();
     if(ch==13)
       {
	login(usn,c);
	break;
       }
     c[i]=ch;
     cout<<"*";
     c[i+1]='\0';
     i++;
   }
}


				  // TO DISPLAY MOUSE
void callmouse()
{
  in.x.ax=1;
  int86(51,&in,&out);
  in.x.ax=7;
  in.x.cx=1;
  in.x.dx=650;
  int86(51,&in,&out);
  in.x.ax=8;
  in.x.cx=10;
  in.x.dx=500;
  int86(51,&in,&out);
}
			       // TO HIDE MOUSE
void hidemouse()
{
  in.x.ax=2;
  int86(51,&in,&out);
}
			     // DISPLAY LOADING SCREEN
void load()
{
  cleardevice();
  settextstyle(1,0,3);
  setcolor(RED);
  outtextxy(250,200,"LOADING......");
  setlinestyle(SOLID_LINE,0,2);
  line(0,400,0,450);
  for(int i=0;i<=650;i++)
    {
       setcolor(8);
       line(i,400,i,450);
       delay(2);
     }
}

int no,kk;
int hash(int m)
{   int r,q;
    r=m%10;
q=rand()/10;
    q=m/10;
    kk=(q+r+7)%10;
    return kk;
}
class banking
{
   public: int flag;
    char name[20],num[20];
	unsigned long int amount;
	
	 // int getdet();          // TO GET BANKING DETAILS
  void showdet();     
	
	//,amount[20];
}rec[10];

void unpack()
{   int i=0;
    fstream in;
    in.open("abc.txt",ios::in);
    char buf[80];
    while(!in.eof())
    {
      in.getline(buf,80,'\n');
      sprintf(buf,"|%s|%s|%lu|",rec[i].name,rec[i].num,rec[i].amount);
      //in.getline(rec[i].itemno,20,'|');
      //in.getline(rec[i].amount,20,'\n');
      i++;
    }
    in.close();
}

void main()                       // MAIN FUNC !!!!
{
  int g=DETECT,m;
  r=l=1;
  initgraph(&g,&m,"\\tc\\bgi");
  cleardevice();
  screen();
  while(z==1)
    {
      load();
      ms();
      getch();
    }
  closegraph();
}



void login(char usn[],char pass[])
{
  if(strcmp(usn,"worldbank")==0 && strcmp(pass,"money")==0)
     {
       hidemouse();
       z=1;
     }
  else
     {
       gotoxy(55,20);
       cout<<"Invalid Passcode... !!";
       getch();
       clrscr();
       screen();
      }
}


void ms()
{
  cleardevice();
  setlinestyle(0,1,3);
  settextstyle(1,0,1);

  setcolor(10);
  rectangle(50,50,285,185);
  outtextxy(125,110,"BANKING");

  setcolor(14);
  rectangle(330,50,565,185);
  outtextxy(415,110,"LOANS");

  setcolor(12);
  circle(300,270,70);
  outtextxy(280,260,"EXIT");

  setcolor(9);
  arc(280+10,340,180,315,100);
  arc(300+10,340,225,0,100);

  while(!kbhit())
   {
     callmouse();
     in.x.ax=3;
     int86(51,&in,&out);

     if(out.x.bx==1 && out.x.cx>=50 && out.x.dx>=50 && out.x.cx<=285 && out.x.dx<=185)
      {
       r=1;
       hidemouse();
       while(r==1)
	{
	   load();
	   draw_1();
	   if(r==0)
	   break;
	   getch();
	}
       z=1;
      }

    if(out.x.bx==1 && out.x.cx>=330 && out.x.dx>=50 && out.x.cx<=565 && out.x.dx<=185)
     {
       l=1;
       hidemouse();
       while(l==1)
	{
	  load();
	  draw_2();
	  if(l==0)
	   break;
	  getch();
	}
       z=1;
     }

    if(out.x.bx==1 && out.x.cx>=230 && out.x.dx>=200 && out.x.cx<=370 && out.x.dx<=340)
    {
      hidemouse();
      conc();
      z=0;
    }

  }

}


void draw_2()
{
  cleardevice();
  setlinestyle(0,1,3);
  settextstyle(1,0,2);

  setcolor(14);
  rectangle(50,50,275,175);
  outtextxy(105,100,"NEW LOAN");

  setcolor(12);
  rectangle(375,50,600,175);
  outtextxy(415,100,"EXISTING LOANS");

  setcolor(3);
  rectangle(50,300,275,425);
  outtextxy(100,350,"CLEAR LOANS");

  setcolor(2);
  rectangle(375,300,600,425);
  outtextxy(450,350,"TARIFF");

  setcolor(6);
  circle(325,236,50);
  outtextxy(300,225,"BACK");

  while(!kbhit())
   {
     callmouse();
     in.x.ax=3;
     int86(51,&in,&out);

     if(out.x.bx==1 && out.x.cx>=50 && out.x.dx>=50 && out.x.cx<=275 && out.x.dx<=175)
       {
     hidemouse();
    newloan();
       }
      else if(out.x.bx==1 && out.x.cx>=375 && out.x.dx>=50 && out.x.cx<=600 && out.x.dx<=175)
       {
     hidemouse();
     oldloan();
       }
      else if(out.x.bx==1 && out.x.cx>=50 && out.x.dx>=300 && out.x.cx<=275 && out.x.dx<=425)
       {
     hidemouse();
     clearloan();
       }
      else if(out.x.bx==1 && out.x.cx>=375 && out.x.dx>=300 && out.x.cx<=600 && out.x.dx<=425)
       {
     hidemouse();
     tariff();
       }
      else if(out.x.bx==1 && out.x.cx>=275 && out.x.dx>=186 && out.x.cx<=375 && out.x.dx<=286)
       {
     hidemouse();
     l=0;
     hit();
       }

    }
}


void draw_1()
{
  cleardevice();
  setlinestyle(0,1,3);
  settextstyle(1,0,2);

  setcolor(14);
  rectangle(50,50,275,175);
  outtextxy(90,100,"CREATE/DELETE");
  outtextxy(50,20,"left click to create");
  outtextxy(50,180,"right click to delete");

  setcolor(12);
  rectangle(375,50,600,175);
  outtextxy(450,100,"V I E W");

  setcolor(3);
  rectangle(50,300,275,425);
  outtextxy(120,350,"MODIFY");

  setcolor(2);
  rectangle(375,300,600,425);
  outtextxy(420,350,"TRANSACTIONS");

  setcolor(6);
  circle(325,236,50);
  outtextxy(300,225,"BACK");

  while(!kbhit())
   {
     callmouse();
     in.x.ax=3;
     int86(51,&in,&out);

     if(out.x.bx==1 && out.x.cx>=50 && out.x.dx>=50 && out.x.cx<=275 && out.x.dx<=175)
      {
    hidemouse();
    create();
      }
     else if(out.x.bx==1 && out.x.cx>=375 && out.x.dx>=50 && out.x.cx<=600 && out.x.dx<=175)
      {
    hidemouse();
    view();
      }
     else if(out.x.bx==2 && out.x.cx>=50 && out.x.dx>=50 && out.x.cx<=275 && out.x.dx<=175)
      {
    hidemouse();
    del();
       }
     else if(out.x.bx==1 && out.x.cx>=50 && out.x.dx>=300 && out.x.cx<=275 && out.x.dx<=425)
      {
    hidemouse();
    edit();
       }
     else if(out.x.bx==1 && out.x.cx>=375 && out.x.dx>=300 && out.x.cx<=600 && out.x.dx<=425)
       {
    hidemouse();
    cleardevice();
    declare();
       }
     else if(out.x.bx==1 && out.x.cx>=275 && out.x.dx>=186 && out.x.cx<=375 && out.x.dx<=286)
       {
    hidemouse();
    r=0;
    hit();
       }

    }
   hidemouse();
}


void banking :: showdet()
{
  clrscr();
  cleardevice();
  setcolor(2);
  settextstyle(3,0,3);
  outtextxy(160,10," DISPLAYING SPECIFIC RECORD\n\n");
  cout<<"\n\n\n\n";
  int m,i,f=0;
  char num[15];
    cout<<endl;
    cout<<"enter num:";
    cin>>num;
    m=atoi(num);
    kk=hash(m);
    unpack();
    for(i=0;i<10;i++)
    {
      if((strcmp(rec[kk%10].num,num))==0)
      {
      cout<<"\n found at "<<kk<<": ";
      //cout<<rec[k].num<<"\t"<<rec[k].name<<"\t"<<rec[k].amount<<"\n";
      cout<<"\n\n\n\n       Account Number             : " <<rec[kk].num;
	  cout<<"\n\n\n\n       Name                       : "<<rec[kk].name;
	  cout<<"\n\n\n\n       Balance Amt                : "<<rec[kk].amount;
      f=1;
      }
      kk=kk+1;
    }
    if(f!=1)
    cout<<"\n\n\t AcCoUnT nOt fOuNd...............!!!!!!!!!!!!!!!!! \n";
	 getch();
    return;


}
class loan
{
 public:
  char l_num[20];
  unsigned long int principle;
  int rate;
  long double l_amt;
  long double emi;
  char code[8];
  char l_name[20];
  int time;
  float r;
  int flag;


  void l_showdet();       // TO SHOW LOAN DETAILS

  void disp_amt()       // TO CALCULATE LOAN AMOUNT  OR EMI
  {
       long double t1,t2;
       r=rate/100.0;
       t1=pow(1+r,time);
       t2=(pow(1+r,time)-1);
       emi = principle * r * t1 / t2;
       cout<<"\n\n\t E M I                      : "<<emi;
       l_amt = emi*time;
       cout<<"\n\t Total amount to be cleared : "<<l_amt;
       cout<<"\n\n\t EXTRA Interest Amount      : "<<l_amt-principle;

  }

  void l_rate()           // TO CALCULATE RATE OF INTEREST
   {
     if(strcmp(code,"h001")==0)
       rate=15;
     else if(strcmp(code,"v002")==0)
       rate=12;
     else if(strcmp(code,"g003")==0)
       rate=10;
     else if(strcmp(code,"e004")==0)
       rate=8;
     else if(strcmp(code,"p005")==0)
       rate=18;
     else
       rate=0;

     if(rate==0)
       cout<<" \n Invalid Code "<<"\n TRY AGAIN ";
     else
       {
       cout<<"\n\n\n\t Rate of INTEREST = "<<rate<<"%";
       disp_amt();
       }


  }




}loanee[20];    // OBJECT OF LOAN

 void l_unpack()
{   int i=0;
    fstream in;
    in.open("abcloan.txt",ios::in);
    char buf[80];
    while(!in.eof())
    {
      in.getline(buf,80,'\n');
      sprintf(buf,"|%s|%s|%lu|%d|%s|%d|%Lf|%Lf|",loanee[i].l_name,loanee[i].l_num,loanee[i].principle,loanee[i].time,loanee[i].code,loanee[i].rate,loanee[i].emi,loanee[i].l_amt);
      //in.getline(loanee[i].itemno,20,'|');
      //in.getline(loanee[i].amount,20,'\n');
      i++;
    }
    in.close();
}

 



void loan::l_showdet()
{
  setcolor(2);
  clrscr();
  cleardevice();
  settextstyle(3,0,3);
  outtextxy(90,10," DISPLAYING DETAILS OF SPECIFIC RECORD\n\n");
  cout<<"\n\n\n\n";
  cout<<"\n\n   Loan ID                          : ";
  puts(l_id);
  cout<<"\n\n   Name                             : ";
  puts(name);
  cout<<"\n\n   Code                             : ";
  puts(code);
  cout<<"\n\n   Principal Amount                 : ";
  cout<<principle;
  cout<<"\n\n   Time Period ( in months )        : ";
  cout<<time<<endl;
  cout<<"\n\n   Rate                             : "<<rate <<"%";;
  cout<<"\n\n   Remaning Loan To Be Cleared      : "<<l_amt;


}

void create()
{
  char ch='y';
  int y;
  int m;
    char num[20],name[20];//,amount[20];
    unsigned int amount;
  /*int l=0;
  no=1;
  while(tolower(ch)=='y' && l<no)
   {*/
     textcolor(14);
     clrscr();
     cleardevice();
     setcolor(14);
     settextstyle(3,0,3);
     outtextxy(180,10," CREATE AN ACCOUNT\n\n");
     cout<<"\n\n\n\n";

    cout<<"\n\n\t\tEnter no of records : ";
    cin>>no;
    if(no<=10)
    {
    for(int l=0;l<no;l++)
    rec[l].flag=0;
    for(int i=0;i<no;i++)
    {
	  again:
    cout<<"\n\n\t Enter Account Number : ";
	cin>>num;
	m=atoi(num);
    kk=hash(m);
    unpack();
    for(int i=0;i<10;i++)
    {
      if((strcmp(rec[kk%10].num,num))==0)
      {
		  cout<<"\n\n\t\tDUPLICATE RECORD....ENTER AGAIN";
		  goto again;
      }
      kk=kk+1;
    }

	cout<<"\n\n\t Enter Name           : ";
	cin>>name;
	cout<<"\n\n\t Enter Amount         : ";
	cin>>amount;
	m=atoi(num);
	kk=hash(m);
	cout<<"\n\n\t Address              : "<<kk<<"\n";
	if(rec[kk].flag==0)
	{
	    strcpy(rec[kk].name,name);
	    strcpy(rec[kk].num,num);
	    //strcpy(rec[kk].amount,amount);
	    rec[kk].amount=amount;
		rec[kk].flag=1;
	}
	else
	{
	    for(int j=kk+1;j%10<10;j++)
	    {
		if(rec[j%10].flag==0)
		 {
			strcpy(rec[j%10].name,name);
			strcpy(rec[j%10].num,num);
		//	strcpy(rec[j%10].amount,amount);
			rec[j%10].amount=amount;
			rec[j%10].flag=1;
			break;
		}
	    }
	}
    }
    /*cout<<"The file output is: \n";
    for(i=0;i<10;i++)
    {
    if(rec[i].flag==1)
    cout<<rec[i].name<<"\t"<<rec[i].num<<"\t"<<rec[i].amount<<"\n";
    else
    cout<<"## \n";
    }*/
    fstream f1;
    f1.open("abc.txt",ios::out);
    for(i=0;i<10;i++)
	{
	    if(rec[i].flag==0)
	    f1<<"#|#"<<"\n";
	    else
	    f1<<rec[i].name<<"|"<<rec[i].num<<"|"<<rec[i].amount<<"\n";
	}
    f1.close();
   }












	/*
     cout<<" Enter Account Number                  : ";
	 cin>>num;


	  m=atoi(num);
    kk=hash(m);
    unpack();
    for(i=0;i<10;i++)
    {
      if((strcmp(rec[k%10].num,num))==0)
      {
		  cout<<"\n\n\t\tDUPLICATE RECORD....ENTER AGAIN";
		  goto again;
      }
      k=k+1;
    }

	cout<<"\n Enter  Name (max 50 characters)       : ";
	gets(name);
	AMT:
	cout<<"\n Enter Starting Amount (min 1000)      : ";
	cin>>amount;
	if(amount>=1000)
	{
	  fout.write((char*) &acc,sizeof(acc));
	  fout.close();
	  cout<<" \n\n\n\n\n ACCOUNT CREATED ......!! ";
	  cout<<"\n\n\n Do You Want To ADD again y/n  : ";
	  ch=getch();
	  if(ch=='y')
		no++;
	  cout<<ch;
	}
	else
	{
	  cout<<"\n\n Minimum Balance REQUIRED "<<endl;
	  goto AMT;
	}


    l++;
   }*/
}


void view()
{
  int ch;
  do
   {
     clrscr();
     cleardevice();
     setcolor(12);
     settextstyle(3,0,3);
     outtextxy(190,10," VIEWING RECORDS\n\n");
     cout<<"\n\n\n\n\n\n";

     cout<<"\n\n 1. Specific Record ";
     cout<<"\n\n 2. Full List";
     cout<<"\n\n 3. Exit";
     cout<<"\n\n ENTER YOUR CHOICE   : ";
     cin>>ch;
     switch(ch)
      {
       case 1:
		display(1);
		 break;

       case 2:
	 clrscr();
	 cleardevice();
	 setcolor(2);
	 settextstyle(3,0,3);
	 outtextxy(190,10," DISPLAYING ALL RECORDS\n\n");
	 cout<<"\n\n\n\n";

	 settextstyle(2,0,2);
	 setcolor(3);
	 outtextxy(10,65,"#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*##*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*");
	 cout<<"\n\n\n";
	 cout<<"     NAME\t\t\tACCOUNT NUMBER\t\t\tBALANCE"<<endl;

	 settextstyle(2,0,2);
	 setcolor(3);
	 outtextxy(10,160,"#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*##*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*");
	 cout<<"\n\n\n";

	  for(int i=0;i<10;i++)
	   {
		 if(rec[i].flag==1)
			  cout<<"     "<<rec[i].name<<" \t\t\t   "<<rec[i].num<<" \t\t\t\t "<<rec[i].amount<<endl;
		}
	   getch();
       break;

     case 3:
       r=1;
       setcolor(7);
       settextstyle(3,0,1);
       outtextxy(250,380,"HIT ENTER AGAIN");
       break;
      default:cout<<"\n\n\t\tENTER A VALID CHIOOICE ";break;
    }
  }while(ch!=3);
}


void del()
{
  int ch;
  do
   {
     clrscr();
     cleardevice();
     setcolor(14);
     settextstyle(3,0,3);
     outtextxy(190,10," DELETING RECORDS\n\n");
     cout<<"\n\n\n\n";
     cout<<" \n\n\n 1. Specific Record ";
     cout<<" \n\n\n 2. All Records ";
     cout<<" \n\n\n 3. Exit ";
     cout<<" \n\n\n\t ENTER YOUR CHOICE    : ";
     cin>>ch;
     switch(ch)
      {
       case 1:
		 int m,i,f=0,cc;
	char vv[20];
   char tt[20],num[20];
   unsigned long amt;
    cout<<endl;
    cout<<"\n\n\t\tENTER ACCOUNT NUMBER : ";
    cin>>num;
    m=atoi(num);
    kk=hash(m);
    unpack();
    for(i=0;i<10;i++)
    {
      if((strcmp(rec[kk%10].num,num))==0)
      {
      f=1;
      cout<<" \n\n\t\tDELETED :) "    ;
      rec[i].flag=0;
      break;
      }
     kk=kk+1;
    }
    fstream f1;
    f1.open("abc.txt",ios::out);
    for(i=0;i<10;i++)
    {
      if(rec[i].flag==0)
	{
		  f1<<"#|#"<<"\n";}
      //else if(strcmp(vv,rec[i].num)==0)
	//f1<<"#|#                   ";
      else
	{
		  f1<<rec[i].num<<"|"<<rec[i].name<<"|"<<rec[i].amount<<"\n";}
    }
   f1.close();
    if(f!=1)
    cout<<"\n\n\t Not found...!!!!!!!!!!!! \n";   getch();
    return;


	   case 2:

		fstream f12;
	f12.open("abc.txt",ios::out);
	for(i=0;i<10;i++)
	{
		if(rec[i].flag==0)
			f12<<"#|#"<<"\n";
		else
			  {
			  rec[i].flag=0;
			  f12<<"#|#"<<"\n";
			  }
	}
		f12.close();
		      cout<<" \n\n\t\tDELETED ALL RECORDS     :) "    ;

	    break;


    case 3:

	 hidemouse();
	 r=1;
	 setcolor(7);
	 settextstyle(3,0,1);
	 outtextxy(250,380,"HIT ENTER AGAIN");
	 break;
      }
   }while(ch<3);
}


void edit()
{
	int m,i,f=0,cc;

   char tt[20],num[20];
   unsigned long amt;
  int e;
  char ch='y';
  textcolor(CYAN);
  clrscr();
  cleardevice();
  setcolor(3);
  settextstyle(3,0,3);
  outtextxy(190,10," UPDATING RECORDS\n\n");
  cout<<"\n\n\n\n";
  char x[20];
 // while(tolower(ch)=='y')

     cout<<"\n\n\n\n\t Enter Account Number     : ";
     cin>>x;
    m=atoi(x);
    kk=hash(m);
    unpack();
    for(i=0;i<10;i++)
    {
      if((strcmp(rec[kk%10].num,x))==0)
      {
      cout<<"\n\n\t Found aT : "<<kk<<"\n ";
      cout<<"\n Enter Modifed Name : ";
      cin>>tt;
      strcpy(rec[kk].name,tt);
      cout<<"\nAfter modification details   :\n\n";
      cout<<"\n\n\n\n       Account Number             : " <<rec[kk].num;
	  cout<<"\n\n\n\n       Name                       : "<<rec[kk].name;
	  cout<<"\n\n\n\n       Balance Amt                : "<<rec[kk].amount;

      f=1;
      break;
      }
     kk=kk+1;
    }
    fstream f1;
    f1.open("abc.txt",ios::out);
    for(i=0;i<10;i++)
    {
      if(rec[i].flag==0)
      f1<<"#|#"<<"\n";
      else
      f1<<rec[i].num<<"|"<<rec[i].name<<"|"<<rec[i].amount<<"\n";
    }
   f1.close();
    if(f!=1)
    cout<<"\n Not founD................!!!!!!!!!!! \n";
    getch();
    return;

}






void conc()
{
  cleardevice();
  hidemouse();
  setcolor(2);
  settextstyle(1,0,3);
  outtextxy(20,15,"tHaNk YoU FoR uSiNg BanK MaNaGeMeNT sYsTeM !!!! " );

  setcolor(3);
  settextstyle(1,0,1);
  outtextxy(20,80,"DONE BY :-");
  outtextxy(50,110,"NARSIMHAN N - 1GA15IS024");
  outtextxy(50,130,"SURAJ S     - 1GA15IS044");


  setcolor(12);
  settextstyle(3,0,1);
  outtextxy(70,200,"");
  outtextxy(50,220," Powered by Global Academy of Technology ");

  setcolor(14);
  settextstyle(3,0,0);
  outtextxy(200,300,".....Hit To Continue.....");
  setcolor(6);
  setlinestyle(3,0,3);
  ellipse(370,325,0,360,200,50);

}


void display(int fl)
{
    int m,i,f=0;
    char num[15];
    clrscr();
    cleardevice();
    cout<<endl;
    cout<<"\n\t Enter Account Number : ";
    cin>>num;
    m=atoi(num);
    kk=hash(m);
    unpack();
    for(i=0;i<10;i++)
    {
      if((strcmp(rec[kk%10].num,num))==0)
      {
      cout<<"\n found at "<<kk<<": ";
      cout<<"\n\n\t\tACCOUNT NUMBER  : "<<rec[kk].num;
      cout<<"\n\n\t\tACCOUNT NAME    : "<<rec[kk].name;
	  cout<<"\n\n\t\tACCOUNT BALANCE : "<<rec[kk].amount;
      f=1;
      }
      kk=kk+1;
    }
    if(f!=1)
    cout<<"\n\n\t\t Not FounD  :( \n";    getch();
    return;
}



void declare()
{
  int y,m,f=0;
  clrscr();
  cleardevice();
  setcolor(2);
  settextstyle(3,0,3);
  outtextxy(210,10," BANKING TRANSACTIONS\n\n");
  cout<<"\n\n ";

   cout<<"\n\n Enter Account Number : ";

	char tt[20],num[20];
    unsigned long amt;
    cin>>num;
    m=atoi(num);
    kk=hash(m);
    unpack();
    for(int i=0;i<10;i++)
    {
    if((strcmp(rec[kk%10].num,num))==0)
      {
     cout<<"\n\n\n\n\n\n\n\n\n\n\n\n Found aT : "<<kk<<"\n\nCHOICE :  ";
      //cout<<"\n\n\t CURRENT AMOUNT : "<<rec[k].amount;
      //cout<<"\n\n PRESS 1 to DEPOSIT \n\n PRESS 2 to WITHDRAW : ";
     //cin>>cc;
     //clrscr();
     //cleardevice();
	 setlinestyle(1,1,3);
	 settextstyle(3,0,2);
	 setcolor(2);
	 rectangle(355,100,600,225);
	 rectangle(55,100,300,225);
	 setcolor(12);
	 outtextxy(390,150,"WITHDRAW : Press 2");
	 outtextxy(110,150,"DEPOSIT : Press 1");
	// gotoxy(500,500);
	 int yy;
	 cin>>yy;
    while(!kbhit())
    {
      callmouse();
      in.x.ax=3;
      int86(51,&in,&out);
      //if(out.x.bx==1 && out.x.cx>=355 && out.x.dx>=100 && out.x.cx<=600 && out.x.dx<=225)
      if(yy==1)
	   {
	   	clrscr();
	   	cleardevice();
	   	cout<<"\n\n\n\t\tHELLO "<<rec[kk].name;
	   	cout<<"\n\n\n\n\t\t CURRENT BALANCE : "<<rec[kk].amount;
	   cout<<"\n\n\n\n\t ENTER AMOUNT TO DEPOSITE : ";
       cin>>amt;
       rec[kk].amount=rec[kk].amount+amt;
       //strcpy(rec[k].amount,tt);
       cout<<"\n\n\n\n\t\tUPDATED BALANCE AMOUNT : "<<rec[kk].amount;

	fstream f1;
 	   f1.open("abc.txt",ios::out);
 	   for(i=0;i<10;i++)
 	   {
 	     if(rec[i].flag==0)
    	  f1<<"#|#"<<"\n";
      	else
      	f1<<rec[i].num<<"|"<<rec[i].name<<"|"<<rec[i].amount<<"\n";
   		 }
  	 	f1.close();
   		 if(f!=1)
    //	cout<<"\n not found \n";   
		getch();

       }



      //else if(out.x.bx==1 && out.x.cx>=55 && out.x.dx>=100 && out.x.cx<=300 && out.x.dx<=225)
       if(yy==2)
	   {
	   	clrscr();
	   	cleardevice();
	   	cout<<"\n\n\n\n\t\tHellO "<<rec[kk].name;
	   	cout<<"\n\n\n\n\t\t CURRENT BALANCE : "<<rec[kk].amount;
	   	cout<<"\n\n\n\n\t ENTER AMOUNT TO WITHDRAW : ";
      cin>>amt;
      if(amt>=rec[kk].amount)
		{
		cout<<"\n\n\t\tINSUFFICIENT FUNDS";
		getch();
		return;
		}
       rec[kk].amount=rec[kk].amount-amt;
      //strcpy(rec[k].amount,tt);
        cout<<"\n\n\n\n\t\tUPDATED BALANCE AMOUNT : "<<rec[kk].amount;
		 fstream f1;
	    f1.open("abc.txt",ios::out);
    	for(i=0;i<10;i++)
    	{
      	if(rec[i].flag==0)
      	f1<<"#|#"<<"\n";
      	else
      	f1<<rec[i].num<<"|"<<rec[i].name<<"|"<<rec[i].amount<<"\n";
    	}
   		f1.close();
    	if(f!=1)
    	//cout<<"\n not found \n";   
		getch();


       }
      f=1;
      break;
    }}
     kk=kk+1;
   }
}


void newloan()
{
  char ch='y';
  int y;
  int m,time;
    char num[20],name[20],code[10];//,amount[20];
    unsigned int pri;
  /*int l=0;
  no=1;
  while(tolower(ch)=='y' && l<no)
   {*/
     textcolor(14);
     clrscr();
     cleardevice();
     setcolor(14);
     settextstyle(3,0,3);
     outtextxy(180,10," CREATE A LOAN ACCOUNT\n\n");
     cout<<"\n\n\n\n";

    cout<<"\n\n\t\tEnter no of Loans to be Created : ";
    cin>>no;
    if(no<=10)
    {
    for(int l=0;l<no;l++)
    loanee[l].flag=0;
    for(int i=0;i<no;i++)
    {
	  again:
    cout<<"\n\n\t Enter Loan ID : ";
	cin>>num;
	m=atoi(num);
    kk=hash(m);
    l_unpack();
    for(int i=0;i<10;i++)
    {
      if((strcmp(loanee[kk%10].l_num,num))==0)
      {
		  cout<<"\n\n\t\tPAY YOUR OLD LOAN...!!";
		  goto again;
      }
      kk=kk+1;
    }

   cout<<"\n\n\t Enter Name  (max 6 characters)     : ";
   gets(name);
   cout<<"\n\n\t Enter Principal Amount             : ";
   cin>>pri;
   cout<<"\n\n\t Enter Time Period ( in months )    : ";
   cin>>time;
   cout<<"\n\n\t Enter code                         : ";
   gets(code);
  

	m=atoi(num);
	kk=hash(m);
	cout<<"\n\n\t Address              : "<<kk<<"\n";
	if(loanee[kk].flag==0)
	{
	    strcpy(loanee[kk].l_name,name);
	    strcpy(loanee[kk].l_num,num);
	    //strcpy(loanee[kk].amount,amount);
	    loanee[kk].principle=pri;
	    loanee[kk].time=time;
	    strcpy(loanee[kk].code,code);
		loanee[kk].flag=1;
		loanee[kk].l_rate();
	}
	else
	{
	    for(int j=kk+1;j%10<10;j++)
	    {
		if(loanee[j%10].flag==0)
		 {
			strcpy(loanee[j%10].l_name,name);
			strcpy(loanee[j%10].l_num,num);
		//	strcpy(loanee[j%10].amount,amount);
			loanee[j%10].priciple=pri;
			loanee[j%10].time=time;
	        strcpy(loanee[j%10].code,code);
			loanee[j%10].flag=1;
			loanee[j%10].l_rate();
			break;
		}
	    }
	}
    }
    /*cout<<"The file output is: \n";
    for(i=0;i<10;i++)
    {
    if(loanee[i].flag==1)
    cout<<loanee[i].name<<"\t"<<loanee[i].num<<"\t"<<loanee[i].amount<<"\n";
    else
    cout<<"## \n";
    }*/
    fstream f1;
    f1.open("abcloan.txt",ios::out);
    for(i=0;i<10;i++)
	{
	    if(loanee[i].flag==0)
	    f1<<"#|#"<<"\n";
	    else
	    f1<<loanee[i].l_name<<"|"<<loanee[i].l_num<<"|"<<loanee[i].principle<<"|"<<loanee[i].time<<"|"<<loanee[i].code<<"|"<<loanee[i].rate<<"|"<<loanee[i].emi<<"|"<<loanee[i].l_amt<<"\n";
	}
    f1.close();
   }
}


void oldloan()
{
  int ch;
  do
    {
      textcolor(RED);
      clrscr();
      cleardevice();
      setcolor(14);
      settextstyle(3,0,3);
      outtextxy(190,10," VIEWING LOANS\n\n");
      cout<<"\n\n\n\n\n";
      cout<<"\n\n 1. Specific Loan ";
      cout<<"\n\n 2. Full List";
      cout<<"\n\n 3. Exit";
      cout<<"\n\n\n ENTER YOUR CHOICE : ";
      cin>>ch;
      switch(ch)
       {
	case 1:
	    int m,i,f=0;
  		char num[15];
        clrscr();
    	cleardevice();
    	cout<<endl;
    	cout<<"\n\t Enter Load ID : ";
    	cin>>num;
    	m=atoi(num);
    	kk=hash(m);
        l_unpack();
    	for(i=0;i<10;i++)
    	{
      	if((strcmp(loanee[kk%10].l_num,num))==0)
      		{
      			
      			cout<<"\n found at "<<kk<<": ";
      			loanee[kk].l_showdet();
      		}
      	kk=kk+1;
    	}
    	if(f!=1)
    		cout<<"\n\n\t\t Not FounD  :( \n";    getch();
	     	break;

	case 2:
	     int a=0;
	     clrscr();
	     cleardevice();
	     setcolor(2);
	     settextstyle(3,0,3);
	     outtextxy(150,10," DISPLAYING ALL LOAN DETAILS\n\n");

	     fin.open("Loan.dat",ios::binary);
	     settextstyle(2,0,2);
	     setcolor(3);
	     outtextxy(7,65,"#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*##*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*");
	     cout<<"\n\n\n\n\n\n";
	     cout<<" NAME       LOAN ID    TYPE CODE   PRINCIPLE AMT    BALANCE AMT     TIME PERIOD"<<endl;

	     settextstyle(2,0,2);
	     setcolor(3);
	     outtextxy(7,125,"#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*##*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*");
	     cout<<"\n\n\n";
	      for(int i=0;i<10;i++)
	   		{
		 if(loanee[i].flag==1)
			
				cout<<loanee[i].l_name<<" \t    "<<loanee[i].l_id<<"\t\t"<<loanee[i].code<<"\t    "<<loanee[i].principle<<"\t     "<<loanee[i].l_amt<<"\t       "<<loanee[i].time<<endl;
	

	      }
	     fin.close();
	     //outtextxy(10,((a*60)+100),"*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*##*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*");

	     getch();
	     break;

	case 3:
	     l=1;
	     setcolor(7);
	     settextstyle(3,0,1);
	     outtextxy(250,300," HIT ENTER AGAIN");
	     break;
     }
  }while(ch<3);
}

void clearloan()
{
  char ch='y';
  loan loanee_b;
  char num[20];
  int f=0;
  int  x,z;
   while(ch=='y'||ch=='Y')
   {
     clrscr();
     cleardevice();
     setcolor(CYAN);
     settextstyle(3,0,3);
     outtextxy(190,10," CLEARING LOANS\n\n");
     cout<<"\n\n\n\n ";
     cout<<"\n Enter Loan ID                 : ";
     cin>>num;
     m=atoi(num);
     kk=hash(m);
     l_unpack();
   	for(i=0;i<10;i++)
   	{
      	if((strcmp(loanee[kk%10].l_num,num))==0)
      		{
      			
      			cout<<"\n found at "<<kk<<": ";
      			f=1;
      	    	 cout<<" \t\t CURRENT LOAN AMOUNT : "<<loanee.l_amt;
		 		cout<<" \n\t\t LOAN AMOUNT CLEARED : " <<loanee.emi;
				 loanee.l_amt-=loanee.emi;
		 		--loanee.time;
		 		if(loanee.time==0)
		     		loanee.l_amt=0;
				 cout<<" \n\n\n\t\t ThAnK yOu!! ";
				 cout<<" \n\n\t\t REMAINING LOAN AMOUNT : "<<loanee.l_amt;
				 cout<<" \n\t\t REMAINING TIME LEFT   : "<<loanee.time;
  
			  if(loanee_b.l_amt==0 || loanee_b.time==0)
			     	cout<<" \n\n CONGO LOAN CLEARED !!! :D";
	   
	  		 	cout<<" \n\n Do You Want To CLEAR  another loan (y/n) : ";
	 			 ch=getch();
	  			cout<<ch;
      			
      		}
      	kk=kk+1;
    	}
    	if(f!=1)
    		cout<<"\n\n\t\t No ID  FounD  :( \n";    getch();
	     	break;
	}


  l=1;
}

void tariff()
{
  cleardevice();
  setcolor(14);
  settextstyle(3,0,0);
  outtextxy(250,12,"TARRIF");
  settextstyle(2,0,2);
  setcolor(3);
  outtextxy(10,70,"#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*##*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*");
  setcolor(10);
  settextstyle(3,0,2);
  outtextxy(20,90,"TYPE OF LOAN           CODE             RATE OF INTEREST ");

  settextstyle(2,0,2);
  setcolor(3);
  outtextxy(10,120,"#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*##*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*");
  settextstyle(2,1,2);
  settextstyle(2,1,2);
  outtextxy(210,70,"*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*");
  outtextxy(380,70,"*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*");
  settextstyle(2,0,2);
  outtextxy(10,320,"#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*##*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*");


  setcolor(12);
  settextstyle(1,0,2);
  outtextxy(10,150," HOUSING LOAN           h001             15%");
  outtextxy(10,180," VEHICLE LOAN            v002             12%");
  outtextxy(10,240," EDUCATION LOAN         e004              8%");
  outtextxy(10,210," GOLD LOAN               g003             10%");
  outtextxy(10,270," PERSONAL LOAN          p005             18%");
  getch();
  setcolor(7);
  settextstyle(3,0,1);
  outtextxy(250,380,"HIT AGAIN");
  l=1;

}

  /*  A PROJECT BY :
		      NARASIMHAN.N
		      SURAJ S

  */
