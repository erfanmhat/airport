#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <conio.h>
/****************************************/
#include "base.h"
#include "classm.h"//class metods

using namespace std;

void menu(ALL&);//main menu
void add(ALL&);//add menu
void removef(ALL&);//remove menu
void report(ALL&);//report menu
void edit(ALL&);//edit menu
bool compDate(Man*,Man*);//sort comp
bool compLName(Man*,Man*);//sort comp
bool compProceeds(Fly*,Fly*);//sort comp
/*??????????????????????????????????????*/
int main()
{
	system("color 3F");
	ALL all;
	ifstream fstt("data.dat");
	if(!fstt.is_open())
	{
		ofstream f("data.dat");
		if(!f.is_open())
		{
			cerr<<"error file!!!"<<endl;
			exit(1);
		}
		f.close();
		fstt.open("data.dat");
	}
	else fstt>>all;
	fstt.close();
	while(1)
	{
		system("cls");
		menu(all);
	}
}
/*??????????????????????????????????????*/
void menu(ALL &all)
{
    char temp;
    mainmenu:
    cout<<"            >>Menu<<"<<endl<<endl;
    cout<<"[1] add"<<endl;
    cout<<"[2] remove"<<endl;
    cout<<"[3] report"<<endl;
    cout<<"[4] edit"<<endl;
    cout<<"[0] Exit"<<endl;
    temp=getch();
    switch(temp)
    {
        case '1':
        {
            add(all);
            break;
        }
        case '2':
        {
            removef(all);
            break;
        }
        case '3':
        {
            report(all);
            break;
        }
        case '4':
        {
            edit(all);
            break;
        }
        case '0':
        {
            system("cls");
            exit(0);
            break;
        }
        default:
        {
            system("cls");
            cout<<"Error invalid input!!!"<<endl;
            system("pause");
            system("cls");
            goto mainmenu;
        }

    }
}
/*??????????????????????????????????????*/
void add(ALL& all)
{
	Tickets tickets;
	Pickup pickup;
	Passenger passenger;
	Aircraft aircraft;
	Stewardess stewardess;
	Pilot pilot;
	Fly fly;
	char temp;
	system("cls");
    mainadd:
	cout<<"            >>add<<"<<endl<<endl;
    cout<<"[1] Add a pilot"<<endl;
    cout<<"[2] add a tickets"<<endl;
    cout<<"[3] add a stewardess"<<endl;
    cout<<"[4] add a fly"<<endl;
    cout<<"[5] add a pickup"<<endl;
    cout<<"[6] add a aircraft"<<endl;
    cout<<"[7] add a passenger"<<endl;
    cout<<"[0] Back to main menu"<<endl;
    temp=getch();
    switch(temp)
    {
        case '1':
        {
            cin>>pilot;
			all.addPilot(pilot);
            break;
        }
        case '2':
        {
			cin>>tickets;
			all.addTickets(tickets);
            break;
        }
        case '3':
        {
			cin>>stewardess;
			all.addStewardess(stewardess);
            break;
        }
        case '4':
        {
			cin>>fly;
			all.addFly(fly);
            break;
        }
        case '5':
        {
			cin>>pickup;
			all.addPickup(pickup);
            break;
        }
        case '6':
        {
			cin>>aircraft;
			all.addAircraft(aircraft);
            break;
        }
        case '7':
        {
            cin>>passenger;
			all.addPassenger(passenger);
            break;
        }
        case '0':
        {
            system("cls");
            return;
        }
        default:
        {
            system("cls");
            cout<<"Error invalid input!!!"<<endl;
            system("pause");
            system("cls");
            goto mainadd;
        }
    }
    cout<<"added"<<endl;
    system("pause");
    ofstream fout("data.dat");
    fout<<all;
}
/*??????????????????????????????????????*/
void removef(ALL& all)
{
	char temp;
	string str;
	int index;
	system("cls");
    mainremove:
    cout<<"            >>remove<<"<<endl<<endl;
    cout<<"[1] remove a pilot"<<endl;
    cout<<"[2] remove a tickets"<<endl;
    cout<<"[3] remove a stewardess"<<endl;
    cout<<"[4] remove a fly"<<endl;
    cout<<"[5] remove a pickup"<<endl;
    cout<<"[6] remove a aircraft"<<endl;
    cout<<"[7] remove a passenger"<<endl;
    cout<<"[0] Back to main menu"<<endl;
    temp=getch();
    switch(temp)
    {
        case '1':
        {
        	if(all.getVPilot().size()==0)
        	{
        		system("cls");
        		cout<<"number of pilot is zero!!!"<<endl<<endl<<endl;
        		system("pause");
        		break;
        	}
        	temp=0;
        	system("cls");
        	cout<<"enter pilot national code :"<<endl;
        	cin>>str;
        	cin.ignore();
        	for(int i=0;i<all.getVPilot().size();i++)
        	{
        		if(all.getVPilot()[i].getNationalCode()==str)
        		{
        			index=i;
        			temp=1;
        			break;
        		}
        	}
        	if(temp==1)
        	{
        		cout<<all.getVPilot()[index];
        		cout<<"enter y for remove "<<endl;
        		cin>>temp;
        		cin.ignore();
        		if(temp=='y'||temp=='Y')
        		{
        			all.getVPilot().erase(all.getVPilot().begin()+index);
        			cout<<"removed"<<endl<<endl<<endl;
        			system("pause");
				}
				else
				{
					cout<<"not removed!!!"<<endl<<endl<<endl;
					system("pause");
				}
        	}
        	else
        	{
        		cout<<"No pilots with "<<str<<" national code were found!!!"<<endl<<endl<<endl;
        		system("pause");
        	}
			break;
        }
        case '2':
        {
        	if(all.getVTickets().size()==0)
        	{
        		system("cls");
        		cout<<"number of tickets is zero!!!"<<endl<<endl<<endl;
        		system("pause");
        		break;
        	}
        	temp=0;
        	system("cls");
        	cout<<"enter tickets is passenger national code :"<<endl;
        	cin>>str;
        	cin.ignore();
        	for(int i=0;i<all.getVTickets().size();i++)
        	{
        		if(all.getVTickets()[i].getPassengerNationalCode()==str)
        		{
        			index=i;
        			temp=1;
        			break;
        		}
        	}
        	if(temp==1)
        	{
        		cout<<all.getVTickets()[index];
        		cout<<"enter y for remove "<<endl;
        		cin>>temp;
        		cin.ignore();
        		if(temp=='y'||temp=='Y')
        		{
        			all.getVTickets().erase(all.getVTickets().begin()+index);
        			cout<<"removed"<<endl<<endl<<endl;
        			system("pause");
				}
				else
				{
					cout<<"not removed!!!"<<endl<<endl<<endl;
					system("pause");
				}
        	}
        	else
        	{
        		cout<<"No ticket with "<<str<<" passenger national code were found!!!"<<endl<<endl<<endl;
        		system("pause");
        	}
            break;
        }
        case '3':
        {
        	if(all.getVStewardess().size()==0)
        	{
        		system("cls");
        		cout<<"number of stewardes is zero!!!"<<endl<<endl<<endl;
        		system("pause");
        		break;
        	}
        	temp=0;
        	system("cls");
        	cout<<"enter stewardess national code :"<<endl;
        	cin>>str;
        	cin.ignore();
        	for(int i=0;i<all.getVStewardess().size();i++)
        	{
        		if(all.getVStewardess()[i].getNationalCode()==str)
        		{
        			index=i;
        			temp=1;
        			break;
        		}
        	}
        	if(temp==1)
        	{
        		cout<<all.getVStewardess()[index];
        		cout<<"enter y for remove "<<endl;
        		cin>>temp;
        		cin.ignore();
        		if(temp=='y'||temp=='Y')
        		{
        			all.getVStewardess().erase(all.getVStewardess().begin()+index);
        			cout<<"removed"<<endl<<endl<<endl;
        			system("pause");
				}
				else
				{
					cout<<"not removed!!!"<<endl<<endl<<endl;
					system("pause");
				}
        	}
        	else
        	{
        		cout<<"No stewardess with "<<str<<" national code were found!!!"<<endl<<endl<<endl;
        		system("pause");
        	}
            break;
        }
        case '4':
        {
        	if(all.getVFly().size()==0)
        	{
        		system("cls");
        		cout<<"number of flight is zero!!!"<<endl<<endl<<endl;
        		system("pause");
        		break;
        	}
        	temp=0;
        	system("cls");
        	cout<<"enter fly flight serial :"<<endl;
        	cin>>str;
        	cin.ignore();
        	for(int i=0;i<all.getVFly().size();i++)
        	{
        		if(all.getVFly()[i].getFlightSerial()==str)
        		{
        			index=i;
        			temp=1;
        			break;
        		}
        	}
        	if(temp==1)
        	{
        		cout<<all.getVFly()[index];
        		cout<<"enter y for remove "<<endl;
        		cin>>temp;
        		cin.ignore();
        		if(temp=='y'||temp=='Y')
        		{
        			all.getVFly().erase(all.getVFly().begin()+index);
        			cout<<"removed"<<endl<<endl<<endl;
        			system("pause");
				}
				else
				{
					cout<<"not removed!!!"<<endl<<endl<<endl;
					system("pause");
				}
        	}
        	else
        	{
        		cout<<"No fly with "<<str<<" flight serial were found!!!"<<endl<<endl<<endl;
        		system("pause");
        	}
            break;
        }
        case '5':
        {
        	if(all.getVPickup().size()==0)
        	{
        		system("cls");
        		cout<<"number of pickup is zero!!!"<<endl<<endl<<endl;
        		system("pause");
        		break;
        	}
        	temp=0;
        	system("cls");
        	cout<<"enter pickup serial :"<<endl;
        	cin>>str;
        	cin.ignore();
        	for(int i=0;i<all.getVPickup().size();i++)
        	{
        		if(all.getVPickup()[i].getSerial()==str)
        		{
        			index=i;
        			temp=1;
        			break;
        		}
        	}
        	if(temp==1)
        	{
        		cout<<all.getVPickup()[index];
        		cout<<"enter y for remove "<<endl;
        		cin>>temp;
        		cin.ignore();
        		if(temp=='y'||temp=='Y')
        		{
        			all.getVPickup().erase(all.getVPickup().begin()+index);
        			cout<<"removed"<<endl<<endl<<endl;
        			system("pause");
				}
				else
				{
					cout<<"not removed!!!"<<endl<<endl<<endl;
					system("pause");
				}
        	}
        	else
        	{
        		cout<<"No pickup with "<<str<<" serial were found!!!"<<endl<<endl<<endl;
        		system("pause");
        	}
            break;
        }
        case '6':
        {
        	if(all.getVAircraft().size()==0)
        	{
        		system("cls");
        		cout<<"number of aircraft is zero!!!"<<endl<<endl<<endl;
        		system("pause");
        		break;
        	}
        	temp=0;
        	system("cls");
        	cout<<"enter aircraft serial :"<<endl;
        	cin>>str;
        	cin.ignore();
        	for(int i=0;i<all.getVAircraft().size();i++)
        	{
        		if(all.getVAircraft()[i].getSerial()==str)
        		{
        			index=i;
        			temp=1;
        			break;
        		}
        	}
        	if(temp==1)
        	{
        		cout<<all.getVAircraft()[index];
        		cout<<"enter y for remove "<<endl;
        		cin>>temp;
        		cin.ignore();
        		if(temp=='y'||temp=='Y')
        		{
        			all.getVAircraft().erase(all.getVAircraft().begin()+index);
        			cout<<"removed"<<endl<<endl<<endl;
        			system("pause");
				}
				else
				{
					cout<<"not removed!!!"<<endl<<endl<<endl;
					system("pause");
				}
        	}
        	else
        	{
        		cout<<"No aircraft with "<<str<<" serial were found!!!"<<endl<<endl<<endl;
        		system("pause");
        	}
            break;
        }
        case '7':
        {
        	if(all.getVPassenger().size()==0)
        	{
        		system("cls");
        		cout<<"number of passenger is zero!!!"<<endl<<endl<<endl;
        		system("pause");
        		break;
        	}
        	temp=0;
        	system("cls");
        	cout<<"enter passenger national code :"<<endl;
        	cin>>str;
        	cin.ignore();
        	for(int i=0;i<all.getVPassenger().size();i++)
        	{
        		if(all.getVPassenger()[i].getNationalCode()==str)
        		{
        			index=i;
        			temp=1;
        			break;
        		}
        	}
        	if(temp==1)
        	{
        		cout<<all.getVPassenger()[index];
        		cout<<"enter y for remove "<<endl;
        		cin>>temp;
        		cin.ignore();
        		if(temp=='y'||temp=='Y')
        		{
        			all.getVPassenger().erase(all.getVPassenger().begin()+index);
        			cout<<"removed"<<endl<<endl<<endl;
        			system("pause");
				}
				else
				{
					cout<<"not removed!!!"<<endl<<endl<<endl;
					system("pause");
				}
        	}
        	else
        	{
        		cout<<"No passenger with "<<str<<" national code were found!!!"<<endl<<endl<<endl;
        		system("pause");
        	}
            break;
        }
        case '0':
        {
            system("cls");
            return;
        }
        default:
        {
            system("cls");
            cout<<"Error invalid input!!!"<<endl;
            system("pause");
            system("cls");
            goto mainremove;
        }
    }
    ofstream fout("data.dat");
    fout<<all;
}
/*??????????????????????????????????????*/
void report(ALL& all)
{
	system("cls");
    char temp;
    string str;
    Date d;
    vector<Man*>man;
    mainreport:
    cout<<"            >>report<<"<<endl<<endl;
    cout<<"[1] dayli flight"<<endl;
    cout<<"[2] employee & passenger sorted by birthday"<<endl;
    cout<<"[3] employee sorted by last name"<<endl;
    cout<<"[4] flys sorted by proceeds"<<endl;
    cout<<"[5] machine is job list"<<endl;
    cout<<"[6] employee is job list"<<endl;
    cout<<"[7] identify"<<endl;
    cout<<"[0] Back to main menu"<<endl;
    temp=getch();
    system("cls");
    switch(temp)
    {
        case '1':
        {
        	cout<<"enter date for show flys (yyyy/mm/dd):"<<endl;
        	cin>>d;
        	temp=0;
        	for(int i=0;i<all.getVFly().size();i++)
        	{
        		if(all.getVFly()[i].getFlightDate()==d)
        		{
        			cout<<all.getVFly()[i];
        			temp=1;
        		}
        	}
        	if(temp==0)cout<<"There is no flight on the "<<d<<" day !!!"<<endl;
            break;
        }
        case '2':
        {
        	for(int i=0;i<all.getVPassenger().size();i++)
        	{
        		man.push_back(&(all.getVPassenger()[i]));
        	}
        	for(int i=0;i<all.getVPilot().size();i++)
        	{
        		man.push_back(&(all.getVPilot()[i]));
        	}
        	for(int i=0;i<all.getVStewardess().size();i++)
        	{
        		man.push_back(&(all.getVStewardess()[i]));
        	}
        	if(man.size()==0)
			{
				cout<<"number of employee & passenger is zero!!!"<<endl;
        		break;
        	}
        	sort(man.begin(),man.end(),compDate);
        	for(int i=0;i<man.size();i++)
        	{
        		man[i]->show();
        	}
            break;
        }
        case '3':
        {
        	for(int i=0;i<all.getVPilot().size();i++)
        	{
        		man.push_back(&(all.getVPilot()[i]));
        	}
        	for(int i=0;i<all.getVStewardess().size();i++)
        	{
        		man.push_back(&(all.getVStewardess()[i]));
        	}
        	if(man.size()==0)
			{
				cout<<"number of pilot & stewardess is zero!!!"<<endl;
        		break;
        	}
        	sort(man.begin(),man.end(),compLName);
        	for(int i=0;i<man.size();i++)
        	{
        		man[i]->show();
        	}
            break;
        }
        case '4':
        {
        	vector<Fly*>fly;
        	for(int i=0;i<all.getVFly().size();i++)
        	{
        		fly.push_back(&(all.getVFly()[i]));
        	}
        	if(man.size()==0)
			{
				cout<<"number of flys is zero!!!"<<endl;
        		break;
        	}
			sort(fly.begin(),fly.end(),compProceeds);
			for(int i=0;i<fly.size();i++)
        	{
        		cout<<*(fly[i]);
        	}
            break;
        }
        case '5':
        {
			cout<<"enter Machine serial :"<<endl;
			cin>>str;
			for(int i=0;i<all.getVPickup().size();i++)
			{
				if((all.getVPickup()[i]).getSerial()==str)
				{
					cout<<all.getVPickup()[i]<<endl;
					all.getVPickup()[i].showJobList();
					cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
				}
			}
			for(int i=0;i<all.getVAircraft().size();i++)
			{
				if((all.getVAircraft()[i]).getSerial()==str)
				{
					cout<<all.getVAircraft()[i]<<endl;
					all.getVAircraft()[i].showJobList();
					cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
				}
			}
            break;
        }
        case '6':
        {
            vector<Employee*>employee;
            cout<<"enter employee personnel code :"<<endl;
            cin>>str;
            system("cls");
            for(int i=0;i<all.getVStewardess().size();i++)
            {
                if(all.getVStewardess()[i].getPersonnelCode()==str)employee.push_back(&(all.getVStewardess()[i]));
            }
            for(int i=0;i<all.getVPilot().size();i++)
            {
                if(all.getVPilot()[i].getPersonnelCode()==str)employee.push_back(&(all.getVPilot()[i]));
            }
            if(employee.size()==0)
            {
                cout<<"no result founded for "<<str<<"employee personnel code"<<endl;
                break;
            }
            for(int i=0;i<employee.size();i++)
            {
                employee[i]->showJobList();
            }
            break;
        }
        case '7':
        {
        	temp=0;
        	cout<<"enter national code :"<<endl;
        	cin>>str;
        	system("cls");
        	for(int i=0;i<all.getVPassenger().size();i++)
        	{
        		man.push_back(&(all.getVPassenger()[i]));
        	}
        	for(int i=0;i<all.getVPilot().size();i++)
        	{
        		man.push_back(&(all.getVPilot()[i]));
        	}
        	for(int i=0;i<all.getVStewardess().size();i++)
        	{
        		man.push_back(&(all.getVStewardess()[i]));
        	}
        	for(int i=0;i<man.size();i++)
        	{
        		if(man[i]->getNationalCode()==str)
				{
					man[i]->show();
					temp=1;
				}
        	}
        	if(temp==0)
			{
				cout<<"no result founded for "<<str<<" national code!!!"<<endl<<endl<<endl;
        		break;
        	}
            break;
        }
        case '0':
        {
        	system("cls");
            return;
        }
        default:
        {
            system("cls");
            cout<<"Error invalid input!!!"<<endl;
            system("pause");
            system("cls");
            goto mainreport;
        }
    }
    system("pause");
    system("cls");
}
/*??????????????????????????????????????*/
void edit(ALL& all)
{
	char temp;
    int index;
    string str;
	system("cls");
    mainedit:
    cout<<"            >>edit<<"<<endl<<endl;
    cout<<"[1] edit a pilot"<<endl;
    cout<<"[2] edit a tickets"<<endl;
    cout<<"[3] edit a stewardess"<<endl;
    cout<<"[4] edit a fly"<<endl;
    cout<<"[5] edit a pickup"<<endl;
    cout<<"[6] edit a aircraft"<<endl;
    cout<<"[7] edit a passenger"<<endl;
    cout<<"[0] Back to main menu"<<endl;
    temp=getch();
    switch(temp)
    {
        case '1':
        {
			if(all.getVPilot().size()==0)
        	{
        		system("cls");
        		cout<<"number of pilot is zero!!!"<<endl<<endl<<endl;
        		system("pause");
        		break;
        	}
        	temp=0;
        	system("cls");
        	cout<<"enter pilot national code :"<<endl;
        	cin>>str;
        	cin.ignore();
        	for(int i=0;i<all.getVPilot().size();i++)
        	{
        		if(all.getVPilot()[i].getNationalCode()==str)
        		{
        			index=i;
        			temp=1;
        			break;
        		}
        	}
        	if(temp==1)
        	{
        		cout<<all.getVPilot()[index];
        		cout<<"enter y for edit "<<endl;
        		cin>>temp;
        		cin.ignore();
        		if(temp=='y'||temp=='Y')
        		{
        			system("cls");
        			Pilot pilot;
        			cin>>pilot;
        			all.getVPilot()[index]=pilot;
        			cout<<"edited"<<endl<<endl<<endl;
        			system("pause");
				}
				else
				{
					cout<<"not edited!!!"<<endl<<endl<<endl;
					system("pause");
				}
        	}
        	else
        	{
        		cout<<"No pilots with "<<str<<" national code were found!!!"<<endl<<endl<<endl;
        		system("pause");
        	}
            break;
        }
        case '2':
        {
			if(all.getVTickets().size()==0)
        	{
        		system("cls");
        		cout<<"number of tickets is zero!!!"<<endl<<endl<<endl;
        		system("pause");
        		break;
        	}
        	temp=0;
        	system("cls");
        	cout<<"enter tickets is passenger national code :"<<endl;
        	cin>>str;
        	cin.ignore();
        	for(int i=0;i<all.getVTickets().size();i++)
        	{
        		if(all.getVTickets()[i].getPassengerNationalCode()==str)
        		{
        			index=i;
        			temp=1;
        			break;
        		}
        	}
        	if(temp==1)
        	{
        		cout<<all.getVTickets()[index];
        		cout<<"enter y for edit "<<endl;
        		cin>>temp;
        		cin.ignore();
        		if(temp=='y'||temp=='Y')
        		{
        			system("cls");
        			Tickets tickets;
        			cin>>tickets;
        			all.getVTickets()[index]=tickets;
        			cout<<"edited"<<endl<<endl<<endl;
        			system("pause");
				}
				else
				{
					cout<<"not edited!!!"<<endl<<endl<<endl;
					system("pause");
				}
        	}
        	else
        	{
        		cout<<"No ticket with "<<str<<" passenger national code were found!!!"<<endl<<endl<<endl;
        		system("pause");
        	}
            break;
        }
        case '3':
        {
			if(all.getVStewardess().size()==0)
        	{
        		system("cls");
        		cout<<"number of stewardes is zero!!!"<<endl<<endl<<endl;
        		system("pause");
        		break;
        	}
        	temp=0;
        	system("cls");
        	cout<<"enter stewardess national code :"<<endl;
        	cin>>str;
        	cin.ignore();
        	for(int i=0;i<all.getVStewardess().size();i++)
        	{
        		if(all.getVStewardess()[i].getNationalCode()==str)
        		{
        			index=i;
        			temp=1;
        			break;
        		}
        	}
        	if(temp==1)
        	{
        		cout<<all.getVStewardess()[index];
        		cout<<"enter y for edit "<<endl;
        		cin>>temp;
        		cin.ignore();
        		if(temp=='y'||temp=='Y')
        		{
        			system("cls");
        			Stewardess stewardess;
        			cin>>stewardess;
        			all.getVStewardess()[index]=stewardess;
        			cout<<"edited"<<endl<<endl<<endl;
        			system("pause");
				}
				else
				{
					cout<<"not edited!!!"<<endl<<endl<<endl;
					system("pause");
				}
        	}
        	else
        	{
        		cout<<"No stewardess with "<<str<<" national code were found!!!"<<endl<<endl<<endl;
        		system("pause");
        	}
            break;
        }
        case '4':
        {
			if(all.getVFly().size()==0)
        	{
        		system("cls");
        		cout<<"number of flight is zero!!!"<<endl<<endl<<endl;
        		system("pause");
        		break;
        	}
        	temp=0;
        	system("cls");
        	cout<<"enter fly flight serial :"<<endl;
        	cin>>str;
        	cin.ignore();
        	for(int i=0;i<all.getVFly().size();i++)
        	{
        		if(all.getVFly()[i].getFlightSerial()==str)
        		{
        			index=i;
        			temp=1;
        			break;
        		}
        	}
        	if(temp==1)
        	{
        		cout<<all.getVFly()[index];
        		cout<<"enter y for edit "<<endl;
        		cin>>temp;
        		cin.ignore();
        		if(temp=='y'||temp=='Y')
        		{
        			system("cls");
        			Fly fly;
        			cin>>fly;
        			all.getVFly()[index]=fly;
        			cout<<"edited"<<endl<<endl<<endl;
        			system("pause");
				}
				else
				{
					cout<<"not edited!!!"<<endl<<endl<<endl;
					system("pause");
				}
        	}
        	else
        	{
        		cout<<"No fly with "<<str<<" flight serial were found!!!"<<endl<<endl<<endl;
        		system("pause");
        	}
            break;
        }
        case '5':
        {
			if(all.getVPickup().size()==0)
        	{
        		system("cls");
        		cout<<"number of pickup is zero!!!"<<endl<<endl<<endl;
        		system("pause");
        		break;
        	}
        	temp=0;
        	system("cls");
        	cout<<"enter pickup serial :"<<endl;
        	cin>>str;
        	cin.ignore();
        	for(int i=0;i<all.getVPickup().size();i++)
        	{
        		if(all.getVPickup()[i].getSerial()==str)
        		{
        			index=i;
        			temp=1;
        			break;
        		}
        	}
        	if(temp==1)
        	{
        		cout<<all.getVPickup()[index];
        		cout<<"enter y for edit "<<endl;
        		cin>>temp;
        		cin.ignore();
        		if(temp=='y'||temp=='Y')
        		{
        			system("cls");
        			Pickup pickup;
        			cin>>pickup;
        			all.getVPickup()[index]=pickup;
        			cout<<"edited"<<endl<<endl<<endl;
        			system("pause");
				}
				else
				{
					cout<<"not edited!!!"<<endl<<endl<<endl;
					system("pause");
				}
        	}
        	else
        	{
        		cout<<"No pickup with "<<str<<" serial were found!!!"<<endl<<endl<<endl;
        		system("pause");
        	}
            break;
        }
        case '6':
        {
			if(all.getVAircraft().size()==0)
        	{
        		system("cls");
        		cout<<"number of aircraft is zero!!!"<<endl<<endl<<endl;
        		system("pause");
        		break;
        	}
        	temp=0;
        	system("cls");
        	cout<<"enter aircraft serial :"<<endl;
        	cin>>str;
        	cin.ignore();
        	for(int i=0;i<all.getVAircraft().size();i++)
        	{
        		if(all.getVAircraft()[i].getSerial()==str)
        		{
        			index=i;
        			temp=1;
        			break;
        		}
        	}
        	if(temp==1)
        	{
        		cout<<all.getVAircraft()[index];
        		cout<<"enter y for edit "<<endl;
        		cin>>temp;
        		cin.ignore();
        		if(temp=='y'||temp=='Y')
        		{
        			system("cls");
        			Aircraft aircraft;
        			cin>>aircraft;
        			all.getVAircraft()[index]=aircraft;
        			cout<<"edited"<<endl<<endl<<endl;
        			system("pause");
				}
				else
				{
					cout<<"not edited!!!"<<endl<<endl<<endl;
					system("pause");
				}
        	}
        	else
        	{
        		cout<<"No aircraft with "<<str<<" serial were found!!!"<<endl<<endl<<endl;
        		system("pause");
        	}
            break;
        }
        case '7':
        {
			if(all.getVPassenger().size()==0)
        	{
        		system("cls");
        		cout<<"number of passenger is zero!!!"<<endl<<endl<<endl;
        		system("pause");
        		break;
        	}
        	temp=0;
        	system("cls");
        	cout<<"enter passenger national code :"<<endl;
        	cin>>str;
        	cin.ignore();
        	for(int i=0;i<all.getVPassenger().size();i++)
        	{
        		if(all.getVPassenger()[i].getNationalCode()==str)
        		{
        			index=i;
        			temp=1;
        			break;
        		}
        	}
        	if(temp==1)
        	{
        		cout<<all.getVPassenger()[index];
        		cout<<"enter y for edit "<<endl;
        		cin>>temp;
        		cin.ignore();
        		if(temp=='y'||temp=='Y')
        		{
        			system("cls");
        			Passenger passenger;
        			cin>>passenger;
        			all.getVPassenger()[index]=passenger;
        			cout<<"edited"<<endl<<endl<<endl;
        			system("pause");
				}
				else
				{
					cout<<"not edited!!!"<<endl<<endl<<endl;
					system("pause");
				}
        	}
        	else
        	{
        		cout<<"No passenger with "<<str<<" national code were found!!!"<<endl<<endl<<endl;
        		system("pause");
        	}
            break;
        }
        case '0':
        {
            system("cls");
            return;
        }
        default:
        {
            system("cls");
            cout<<"Error invalid input!!!"<<endl;
            system("pause");
            system("cls");
            goto mainedit;
        }
    }
    ofstream fout("data.dat");
    fout<<all;
}
//****************************************/
bool compDate(Man* man1,Man* man2)
{
	return((man1->getDateOfBirth())<(man2->getDateOfBirth()));
}
//****************************************/
bool compLName(Man* man1,Man* man2)
{
	return((man1->getLName())<(man2->getLName()));
}
//****************************************/
bool compProceeds(Fly* fly1,Fly* fly2)
{
	return((fly1->getProceedsFromTicketSales())<(fly2->getProceedsFromTicketSales()));
}
/*??????????????????????????????????????*/
