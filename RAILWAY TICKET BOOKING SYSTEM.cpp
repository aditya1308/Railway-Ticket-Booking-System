#include<iostream>
#include<fstream>
#include<cmath>
#include<string>
#include<string.h>
#include<conio.h>
#include <cstdlib>
#include<stdio.h>
#include<ctime>

using namespace std;

class detail{
	int trno;
	char name[30];
	char brdp[30];
	char dest[30];
	
	public:
		
		void getdetail()
		{
			fflush(stdin);
			cout<<"Enter train name:"<<endl;
			gets(name);
			cout<<"Enter train no:"<<endl;
			cin>>trno;
			fflush(stdin);
			cout<<"Enter boarding point:"<<endl;
			gets(brdp);
			fflush(stdin);
			cout<<"Enter destination point:"<<endl;
			gets(dest);
			
		}
		void showdetail()
		{
			
			cout<<"Train No.\t"<<"Train Name\t"<<"Boarding Point\t"<<"Destination Point"<<endl<<endl;
			cout<<"\t"<<trno<<"\t\t"<<name<<"\t   "<<brdp<<"\t   "<<dest<<endl;
		}
};

class trainbook{
	int trno,dist;
	char trname[30];
	char dest[30];
	char bordp[30];
	int jclass;
	
	
	public:
		long long int pnr;
		fstream f;
		char nme[30];
		float fare;
		float fc;
		void getdata()
		{
			fflush(stdin);
			cout<<"Enter name of passenger"<<endl;
			gets(nme);
			cout<<"Enter train name"<<endl;
			gets(trname);
			cout<<"Enter train number"<<endl;
			cin>>trno;
			fflush(stdin);
			cout<<"Enter boarding point"<<endl;
			gets(bordp);
			cout<<"Enter destination point"<<endl;
			gets(dest);
			cout<<"Enter distance between "<<bordp<<" and "<<dest<<endl;
			cin>>dist;
			fflush(stdin);
			cout<<"Enter journey class"<<endl;
			cout<<"(1.SL- sleeper ,2.3AC- AC 3 Tier, 3.2AC- AC 2 Tier, 4.1AC- AC 1 Tier)"<<endl;
			cin>>jclass;
			fc=farecal(jclass);
			
		}
		
		int farecal(int jclas)
		{
				if(jclas==1)
				fare=124+(dist*0.2);
				else
				if(jclas==2)
				fare=421+(dist*0.4);
				else
				if(jclas==3)
				fare=621+(dist*0.4);
				else
				if(jclas==4)
				fare=955+(dist*0.4);
				
				return fare;
		}
		
		void showdata()
		{
	
			cout<<"Passenger name\t  "<<"Train name\t"<<"Train No.\t   ";
			cout<<"BRD PT.\t    "<<"DEST PT.\t "<<"Fare"<<endl<<endl;
			cout<<nme<<"\t\t"<<trname<<"\t"<<trno<<"\t   "<<bordp<<"\t"<<dest<<"\t"<<fare<<endl;
		}
		void pnrout()
		{
			f.open("pnr.txt",ios::in);
			f>>pnr;
			pnr=pnr+789;
			f.close();
			f.open("pnr.txt",ios::out);
			f<<pnr;
			f.close();
			f.open("pnr.txt",ios::in);
			f>>pnr;
			cout<<"PNR No.\t"<<pnr<<endl<<endl;
		}
};
class canc{
	
	public:
		char name[30];
		void get_detail()
		{
			fflush(stdin);
			cout<<"Enter the name of passenger to cancel the ticket"<<endl;
			gets(name);
		}
};

string getpass(const char *prompt, bool show_asterisk=true)
{
  const char BACKSPACE=8;
  const char RETURN=13;

  string password;
  unsigned char ch=0;

 cout <<prompt<<endl;

  while((ch=getch())!=RETURN)
    {
       if(ch==BACKSPACE)
         {
            if(password.length()!=0)
              {
                 if(show_asterisk)
                 cout <<"\b \b";
                 password.resize(password.length()-1);
              }
         }
       else if(ch==0 || ch==224) // handle escape sequences
         {
             getch(); // ignore non printable chars
             continue;
         }
       else
         {
             password+=ch;
             if(show_asterisk)
                 cout <<'*';
         }
    }
  cout <<endl;
  return password;
}


void admin();
void user();
void usermanage();
void userlogin();
void reserve();
void cancel();
void cancell();
void book();
void schedule();

int main()
{
	int ch;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"                              WELCOME TO RAILWAY TICKET BOOKING PORTAL                              "<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl;
	mainmenu:
	for(int i=0;i<=3;i++)
	{
		cout<<"Enter your choice:-"<<endl;
		cout<<"1.Admin Login"<<endl;
		cout<<"2.User Login"<<endl;
		cout<<"3.Exit"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				admin();
				break;
			case 2:
				user();
				break;
			case 3:
				exit(1);
			default:
				cout<<"\nInvalid Choice!!!"<<endl<<endl;
		}	
	}
	
}
void admin()
{
	detail a;
	trainbook t;
	fstream f;
	int ch;
	char c;
	char ch1;
//	const char *correct_password="                                          .                                   ";
	while(1)
	{
		string password=getpass("Enter admin password to continue",true); // Show asterisks
		if(password==correct_password)
		{
			cout <<"Welcome admin"<<endl;
			goto ad;
		}
		else
		cout <<"Incorrect password. Try again"<<endl;
	}
		ad:
			{
				cout<<"......................................ADMINISTRATOR MENU.........................................\n";
	            cout<<"1.Create detail data base"<<endl;
	            cout<<"2.Display booking details"<<endl;
				cout<<"3.User management"<<endl;
				cout<<"4.Return to main menu"<<endl;
	            cout<<"Enter your choice:"<<endl;
	            cin>>ch;
	            switch(ch)
	            {
	            	case 1:
	            		f.open("details.txt",ios::out|ios::binary|ios::app);
	            		while(1)
	            		{
	            			a.getdetail();
	            			f.write((char *)&a,sizeof(a));
	            			cout<<"Do you want to add more records?"<<endl;
	            			cout<<"Y - for YES"<<endl;
	            			cout<<"N - for NO"<<endl;
	            			cin>>c;
	            			if(c=='Y'|c=='y')
	            			continue;
	            			else
	            			break;
						}
						break;
						f.close();
					case 2:
						f.open("copybooking.txt",ios::in);//|ios::binary|ios::app);
						while(f.read((char *)&t,sizeof(t)))
						{
							t.showdata();
						}
						f.close(); 
						break;
					case 3:
						usermanage();
						break;
					case 4:
					
						break;
					
						      		
				}
			}
	
}
void usermanage()
{
	int ch1;
	fstream f;
	string ch;
	cout<<"1.Display user details"<<endl;
	cout<<"2.Return to main menu"<<endl;
	cin>>ch1;
	switch(ch1)
	{
		case 1:
		cout<<"---------------------------------USER DETAILS ARE---------------------------------------------"<<endl;
		f.open("registration.txt",ios::in|ios::binary);
    	cout<<"ID"<<"\t\t"<<"PASSWORD"<<endl;
    	cout<<"-------------------------"<<endl;
        while(f.eof()==0)
        {
        	getline(f,ch,'\n');
        	cout<<ch;
        	cout<<"\t\t";
        	getline(f,ch,'\n');
			cout<<ch;
        	cout<<endl;
		}
			break;
		case 2:
			break;
	}
}
void user()
{
	cout<<"......................................WELCOME TO USER MENU.........................................\n";
	string ch,command,name, password, 
    inName, inPassword, 
    registerName, registerPassword; 
	int ch1;
	fstream f;
	cout<<"1.LOGIN - for existing users"<<endl;
	cout<<"2.SIGN UP - for new users"<<endl;
	cin>>ch1;
	switch(ch1)
	{
		case 1:
			userlogin();
			break;
		case 2:
			f.open("registration.txt",ios::out|ios::binary|ios::app);
			fflush(stdin);
            cout<<"\n\n\n"<<"New Username: ";
            getline(cin, registerName); 
            cout<<"New Password: ";
            getline(cin, registerPassword); 
            f<<registerName; 
            f<<'\n'; 
            f<<registerPassword;
			f<<'\n';
            f.close(); 
	}	

}
void userlogin()
{
		string ch,command,name, password,inName,inPassword,registerName,registerPassword;
		fstream f,f1;
		int flag;
		int ch2;
		time_t timtoday;
		time(&timtoday);
		
		while(1)
		{
		    cout<<"\n\n";
			f1.open("registration.txt",ios::in|ios::binary|ios::app); 
			fflush(stdin);
	        cout<<"Enter Username: ";
            getline(cin, inName);
            cout<<"Enter Password: ";
            getline(cin, inPassword);
            flag=-1;
            while (f1.eof()==0)
            {
            getline(f1, name, '\n'); 
            getline(f1, password, '\n');
                
                if (inName==name && inPassword==password)
                {
                  flag=1;
                  goto ul;
                }
        
            }
			if(flag==-1)
			{
				cout<<"Try again";
				f1.close();
			}
			
		}
			ul:
				{
					 do
		            {
		            	cout<<endl<<"Welcome User"<<"\t\t"<<"Login at:  "<<asctime(localtime(&timtoday))<<endl;
						cout<<"-----------------------------------------------------------------------";
						cout<<"----------------------------"<<endl;
		                cout<<"1.Reserve\n2.Cancel\n3.Train Details-(By train no)\n4.Return to the main menu\n";
		                cout<<"Enter your choice:";
		                cin>>ch2;
		                cout<<endl;
		                switch(ch2)
		                {
		                case 1:
		                   reserve();
		                    break;
		                case 2:
		                   cancell();
		                    break;
		                case 3:
		                   schedule();
		                    break;
		                case 4:
		                	break;
		                }
		            }
		            while(ch2<=3);
				}
				
		
}
void reserve()
{
	int ch;
    do
    {
        cout<<"1.Book Ticket"<<endl;
		cout<<"2.Return to the main menu"<<endl;
        cout<<"Enter your choice:";
        cin>>ch;
        switch(ch)
        {
        case 1:
            book();
            break;
        }
    }
    while(ch==1);
}
void book()
{
	
	fstream f,f1,f2;
	trainbook t;
	char c,ch;
	f.open("booking.txt",ios::out);//|ios::binary);//|ios::app);
	while(1)
	{
		t.getdata();
		f.write((char *)&t,sizeof(t));
		f<<t.fc;
		cout<<"Do you want to add more passengers?"<<endl;
		cout<<"Y - for YES"<<endl;
		cout<<"N - for NO"<<endl;
		cin>>c;
		if(c=='Y'|c=='y')
		continue;
		else
		break;
	}
	//BOOKING DETAILS COPYING
	f.close();
	f1.open("copybooking.txt",ios::out/*|ios::binary*/|ios::app);
	f.open("booking.txt",ios::in);//|ios::binary);
	ch=f.get();
	while(!f.eof())
	{
		f1<<ch;
		ch=f.get();
	}
	f1.close();
	f.close();
	
	cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
	cout<<"-------------TICKET HAS BEEN BOOKED----------HAPPY JOURNEY!!!---------------"<<endl<<endl<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~DETAILS OF BOOKING ARE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	f.open("booking.txt",ios::in);//|ios::binary);//|ios::app);
	f.seekg(0);
	while(f.read((char *)&t,sizeof(t)))
	{
		t.showdata();
		t.pnrout();	
	}
	f.close();
	
}
void cancell()
{
	int ch;
    do
    {
        cout<<".................CANCELLATION MENU.........\n";
        cout<<"1.Cancel"<<endl;
		cout<<"2.Return to the main menu"<<endl;
        cout<<"Enter your choice:";
        cin>>ch;
        cout<<endl;
        switch(ch)
        {
        case 1:
            cancel();
            break;
        }
    }
    while(ch==1);
}
void cancel()
{
	trainbook t;
	canc c;
	fstream f1,f2,f3,f4;
	char ch;
	
	f2.write((char *)&c,sizeof(c));
	c.get_detail();
	f1.open("copybooking.txt",ios::in|ios::out);
	f3.open("allbooking.txt",ios::out|ios::app);
	
	while(f1.read((char *) & t,sizeof(t)))
	{
		if(strcmp(c.name,t.nme))
		{
			f3.write((char *)&t,sizeof(t));
		}	
	}
	f1.close();
	f3.close();
	remove("copybooking.txt");
	rename("allbooking.txt","copybooking.txt");
	cout<<"Ticket has been cancelled"<<endl;
	
}
void schedule()
{
	fstream f;
	string ch;
	f.open("schedule.txt",ios::in);
	while(f.eof()==0)
	{
		getline(f,ch,'\n');
		cout<<ch;	
		cout<<endl;
		cout<<endl;
	}
}
