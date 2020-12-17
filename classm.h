#ifndef CLASSM_H
#define CLASSM_H
#include "class.h"

/*??????????????????????????????????????*/
/**class Date*/
/*??????????????????????????????????????*/
Date::Date(int c,int b,int a)
{
    setDate(c,b,a);
}
/****************************************/
Date::Date(const Date &A)
{
    setDate(A.y,A.m,A.d);
}
/****************************************/
void Date::setDate(int c,int b,int a)
{
    d=a>=1&&a<=31?a:1;
    m=b>=1&&b<=11?b:1;
    y=c>=1900&&c<=2200?c:2000;
}
/****************************************/
ofstream& operator <<(ofstream& fout,Date& date)
{
    fout<<encrypterInt(date.y);
    fout<<' ';
    fout<<encrypterInt(date.m);
    fout<<' ';
    fout<<encrypterInt(date.d);
    fout<<' ';
}
/****************************************/
ifstream& operator >>(ifstream& fin,Date& date)
{
	int y,m,d;
    string str;
    fin>>str;
    y=decrypterInt(str);
    fin>>str;
    m=decrypterInt(str);
    fin>>str;
    d=decrypterInt(str);
    date.setDate(y,m,d);
}
/****************************************/
ostream& operator <<(ostream& cout,Date& date)
{
    cout<<date.y;
    cout<<'/';
    cout<<date.m;
    cout<<'/';
    cout<<date.d;
}
/****************************************/
istream& operator >>(istream& cin,Date& date)
{
    int a,b,c;
    char temp;
    cin>>c;
    cin>>temp;
    cin>>b;
    cin>>temp;
    cin>>a;
    cin.ignore();
    date.setDate(c,b,a);
}
/****************************************/
bool operator ==(Date& date1,Date& date2)
{
	return ((date1.d==date2.d)&&(date1.m==date2.m)&&(date1.y==date2.y))?1:0;
}
/****************************************/
bool operator <(Date& date1,Date& date2)
{
	if(date1==date2)return 0;
	if(date1.y<date2.y)return 1;
	else if(date1.y==date2.y)
	{
		if(date1.m<date2.m)return 1;
		else if(date1.m==date2.m)
		{
			if(date1.d<date2.d)return 1;
			else if(date1.d==date2.d)return 0;
			else return 0;
		}
		else return 0;
	}
	else return 0;
}
/*??????????????????????????????????????*/
/**class Time*/
/*??????????????????????????????????????*/
Time::Time( int hr, int minu, int sec )
{
   setTime( hr, minu, sec );
}
/****************************************/
Time& Time::setTime( int h, int m, int s )
{
   setHour( h );
   setMinute( m );
   setSecond( s );
   return *this;
}
/****************************************/
Time& Time::setHour( int h )
{
   hour = ( h >= 0 && h < 24 ) ? h : 0;
   return *this;
}
/****************************************/
Time& Time::setMinute( int m )
{
   minute = ( m >= 0 && m < 60 ) ? m : 0;
   return *this;
}
/****************************************/
Time& Time::setSecond( int s )
{
   second = ( s >= 0 && s < 60 ) ? s : 0;
   return *this;
}
/****************************************/
int Time::getHour() const
{
  return hour;
}
/****************************************/
int Time::getMinute() const
{
   return minute;
}
/****************************************/
int Time::getSecond() const
{
   return second;
}
/****************************************/
ofstream& operator <<(ofstream& fout,Time& time)
{
	fout<<encrypterInt(time.hour);
	fout<<' ';
	fout<<encrypterInt(time.minute);
	fout<<' ';
	fout<<encrypterInt(time.second);
	fout<<' ';
}
/****************************************/
ifstream& operator >>(ifstream& fin,Time& time)
{
	string str;
	fin>>str;
	time.hour=decrypterInt(str);
	fin>>str;
	time.minute=decrypterInt(str);
	fin>>str;
	time.second=decrypterInt(str);
}
/****************************************/
ostream& operator <<(ostream& cout,Time& time)
{
	cout << setfill( '0' ) << setw( 2 ) << time.hour << ":"<< setw( 2 ) << time.minute << ":" << setw( 2 ) << time.second;
}
/****************************************/
istream& operator >>(istream& cin,Time& time)
{
	char temp;
	int a,b,c;
	cin>>c;
	cin>>temp;
	cin>>b;
	cin>>temp;
	cin>>a;
	time.setTime(c,b,a);
}
/*??????????????????????????????????????*/
/**class ALL*/
/*??????????????????????????????????????*/
Tickets& ALL::getTickets(int num)
{
	if(tickets.size()==0)
	{
		cout<<"Error:vector wrong index!!!"<<endl;
		exit(1);
	}
	return tickets[num];
}
/****************************************/
Pickup& ALL::getPickup(int num)
{
	if(pickup.size()==0)
	{
		cout<<"Error:vector wrong index!!!"<<endl;
		exit(1);
	}
	return pickup[num];
}
/****************************************/
Passenger& ALL::getPassenger(int num)
{
	if(passenger.size()==0)
	{
		cout<<"Error:vector wrong index!!!"<<endl;
		exit(1);
	}
	return passenger[num];
}
/****************************************/
Aircraft& ALL::getAircraft(int num)
{
	if(aircraft.size()==0)
	{
		cout<<"Error:vector wrong index!!!"<<endl;
		exit(1);
	}
	return aircraft[num];
}
/****************************************/
Stewardess& ALL::getStewardess(int num)
{
	if(stewardess.size()==0)
	{
		cout<<"Error:vector wrong index!!!"<<endl;
		exit(1);
	}
	return stewardess[num];
}
/****************************************/
Pilot& ALL::getPilot(int num)
{
	if(pilot.size()==0)
	{
		cout<<"Error:vector wrong index!!!"<<endl;
		exit(1);
	}
	return pilot[num];
}
/****************************************/
Fly& ALL::getFly(int num)
{
	if(fly.size()==0)
	{
		cout<<"Error:vector wrong index!!!"<<endl;
		exit(1);
	}
	return fly[num];
}
/****************************************/
void ALL::addTickets(Tickets &t)
{
	tickets.push_back(t);
}
/****************************************/
void ALL::addPickup(Pickup &p)
{
	pickup.push_back(p);
}
/****************************************/
void ALL::addPassenger(Passenger &p)
{
	passenger.push_back(p);
}
/****************************************/
void ALL::addAircraft(Aircraft &a)
{
	aircraft.push_back(a);
}
/****************************************/
void ALL::addStewardess(Stewardess &s)
{
	stewardess.push_back(s);
}
/****************************************/
void ALL::addPilot(Pilot &p)
{
	pilot.push_back(p);
}
/****************************************/
void ALL::addFly(Fly &f)
{
	fly.push_back(f);
}
/****************************************/
vector<Tickets>& ALL::getVTickets()
{
	return tickets;
}
/****************************************/
vector<Pickup>& ALL::getVPickup()
{
	return pickup;
}
/****************************************/
vector<Passenger>& ALL::getVPassenger()
{
	return passenger;
}
/****************************************/
vector<Aircraft>& ALL::getVAircraft()
{
	return aircraft;
}
/****************************************/
vector<Stewardess>& ALL::getVStewardess()
{
	return stewardess;
}
/****************************************/
vector<Pilot>& ALL::getVPilot()
{
	return pilot;
}
/****************************************/
vector<Fly>& ALL::getVFly()
{
	return fly;
}
/****************************************/
ofstream& operator <<(ofstream& fout,ALL& all)
{
	fout<<encrypterInt(all.tickets.size())<<endl;
	fout<<encrypterInt(all.pickup.size())<<endl;
	fout<<encrypterInt(all.passenger.size())<<endl;
	fout<<encrypterInt(all.aircraft.size())<<endl;
	fout<<encrypterInt(all.stewardess.size())<<endl;
	fout<<encrypterInt(all.pilot.size())<<endl;
	fout<<encrypterInt(all.fly.size())<<endl<<endl;

	for(int i=0;i<all.tickets.size();i++)//Tickets
	{
		fout<<all.tickets[i];
	}
	for(int i=0;i<all.pickup.size();i++)//Pickup
	{
		fout<<all.pickup[i];
	}
	for(int i=0;i<all.passenger.size();i++)//Passenger
	{
		fout<<all.passenger[i];
	}
	for(int i=0;i<all.aircraft.size();i++)//Aircraft
	{
		fout<<all.aircraft[i];
	}
	for(int i=0;i<all.stewardess.size();i++)//Stewardess
	{
		fout<<all.stewardess[i];
	}
	for(int i=0;i<all.pilot.size();i++)//Pilot
	{
		fout<<all.pilot[i];
	}
	for(int i=0;i<all.fly.size();i++)//Fly
	{
		fout<<all.fly[i];
	}
}
/****************************************/
ifstream& operator >>(ifstream& fin,ALL& all)
{
	string str;
	Tickets tempTickets;
	Pickup tempPickup;
	Passenger tempPassenger;
	Aircraft tempAircraft;
	Stewardess tempStewardess;
	Pilot tempPilot;
	Fly tempFly;
	
	fin>>str;
	int numTickets=decrypterInt(str);
	fin>>str;
	int numPickup=decrypterInt(str);
	fin>>str;
	int numPassenger=decrypterInt(str);
	fin>>str;
	int numAircraft=decrypterInt(str);
	fin>>str;
	int numStewardess=decrypterInt(str);
	fin>>str;
	int numPilot=decrypterInt(str);
	fin>>str;
	int numFly=decrypterInt(str);

	for(int i=0;i<numTickets;i++)//Tickets
	{
		fin>>tempTickets;
		all.tickets.push_back(tempTickets);
	}
	for(int i=0;i<numPickup;i++)//Pickup
	{
		fin>>tempPickup;
		all.pickup.push_back(tempPickup);
	}
	for(int i=0;i<numPassenger;i++)//Passenger
	{
		fin>>tempPassenger;
		all.passenger.push_back(tempPassenger);
	}
	for(int i=0;i<numAircraft;i++)//Aircraft
	{
		fin>>tempAircraft;
		all.aircraft.push_back(tempAircraft);
	}
	for(int i=0;i<numStewardess;i++)//Stewardess
	{
		fin>>tempStewardess;
		all.stewardess.push_back(tempStewardess);
	}
	for(int i=0;i<numPilot;i++)//Pilot
	{
		fin>>tempPilot;
		all.pilot.push_back(tempPilot);
	}
	for(int i=0;i<numFly;i++)//Fly
	{
		fin>>tempFly;
		all.fly.push_back(tempFly);
	}
}
/*??????????????????????????????????????*/
/**class Man*/
/*??????????????????????????????????????*/
void Man::setFName(string str)
{
	fName=str;
}
/****************************************/
void Man::setLName(string str)
{
    lName=str;
}
/****************************************/
void Man::setNationalCode(string str)
{
    nationalCode=str;
}
/****************************************/
void Man::setDateOfBirth(Date d)
{
    dateOfBirth=d;
}
/****************************************/
string Man::getFName()const
{
    return fName;
}
/****************************************/
string Man::getLName()const
{
    return lName;
}
/****************************************/
string Man::getNationalCode()const
{
    return nationalCode;
}
/****************************************/
Date& Man::getDateOfBirth()
{
    return this->dateOfBirth;
}
/*??????????????????????????????????????*/
/**class Employee*/
/*??????????????????????????????????????*/
void Employee::setPersonnelCode(string str)
{
    personnelCode=str;
}
/****************************************/
void Employee::setHiringDate(Date d)
{
    hiringDate=d;
}
/****************************************/
void Employee::setJob(Fly flyt)
{
	flyt.getVStewardess().clear();
	flyt.getPilot().getJobList().clear();
	flyt.getVPassenger().clear();
	jobList.push_back(flyt);
}
/****************************************/
string Employee::getPersonnelCode()const
{
    return personnelCode;
}
/****************************************/
Date& Employee::getHiringDate()
{
    return hiringDate;
}
/****************************************/
vector<Fly>& Employee::getJobList()
{
	return jobList;
}
/****************************************/
void Employee::showJobList()
{
	this->show();
	if(jobList.size()==0)
	{
		cout<<"employee job list is empty!!!"<<endl;
		return;
	}
	for(int i=0;i<jobList.size();i++)
	{
		cout<<jobList[i];
	}
}
/*??????????????????????????????????????*/
/**class Machine*/
/*??????????????????????????????????????*/
void Machine::setSerial(string str)
{
    serial=str;
}
/****************************************/
void Machine::setProductionDate(Date d)
{
	productionDate=d;
}
/****************************************/
string Machine::getSerial()const
{
    return serial;
}
/****************************************/
Date& Machine::getProductionDate()
{
    return productionDate;
}
/****************************************/
void Machine::setJob(Fly)
{
	//.............................................................................
}
/****************************************/
vector<Fly>& Machine::getJobList()
{
	//..............................................................................
}
/****************************************/
void Machine::showJobList()
{
	if(jobList.size()==0)
	{
		cout<<"employee job list is empty!!!"<<endl;
		return;
	}
	for(int i=0;i<jobList.size();i++)
	{
		cout<<jobList[i];
	}
}
/*??????????????????????????????????????*/
/**class AirTrip*/
/*??????????????????????????????????????*/
void AirTrip::setOrigin(string str)
{
	origin=str;
}
/****************************************/
void AirTrip::setDestination(string str)
{
	destination=str;
}
/****************************************/
void AirTrip::setFlightDate(Date d)
{
	flightDate=d;
}
/****************************************/
void AirTrip::setFlightTime(Time t)
{
	flightTime=t;
}
/****************************************/
void AirTrip::setFlightSerial(string str)
{
	flightSerial=str;
}
/****************************************/
void AirTrip::setAircraftSerial(string str)
{
	aircraftSerial=str;
}
/****************************************/
void AirTrip::setProceedsFromTicketSales(int n)
{
	proceedsFromTicketSales=n;
}
/****************************************/
string AirTrip::getOrigin()const
{
    return origin;
}
/****************************************/
string AirTrip::getDestination()const
{
    return destination;
}
/****************************************/
Date& AirTrip::getFlightDate()
{
    return flightDate;
}
/****************************************/
Time& AirTrip::getFlightTime()
{
    return flightTime;
}
/****************************************/
string AirTrip::getFlightSerial()const
{
    return flightSerial;
}
/****************************************/
string AirTrip::getAircraftSerial()const
{
    return aircraftSerial;
}
/****************************************/
int AirTrip::getProceedsFromTicketSales()const
{
    return proceedsFromTicketSales;
}
/*??????????????????????????????????????*/
/**class Tickets*/
/*??????????????????????????????????????*/
void Tickets::setPassengerFName(string str)
{
	passengerFName=str;
}
/****************************************/
void Tickets::setPassengerLName(string str)
{
	passengerLName=str;
}
/****************************************/
void Tickets::setPassengerNationalCode(string str)
{
	passengerNationalCode=str;
}
/****************************************/
void Tickets::setPilotPersonnelCode(string str)
{
	pilotPersonnelCode=str;
}
/****************************************/
void Tickets::setPickupSerial(string str)
{
	pickupSerial=str;
}
/****************************************/
void Tickets::setPrice(int n)
{
	price=n;
}
/****************************************/
string Tickets::getPassengerFName()const
{
    return passengerFName;
}
/****************************************/
string Tickets::getPassengerLName()const
{
    return passengerLName;
}
/****************************************/
string Tickets::getPassengerNationalCode()const
{
    return passengerNationalCode;
}
/****************************************/
string Tickets::getPilotPersonnelCode()const
{
    return pilotPersonnelCode;
}
/****************************************/
string Tickets::getPickupSerial()const
{
    return pickupSerial;
}
/****************************************/
int Tickets::getPrice()const
{
    return price;
}
/****************************************/
ofstream& operator <<(ofstream& fout,Tickets& t)
{
	fout<<encrypterStr(t.getOrigin())<<' ';
    fout<<encrypterStr(t.getDestination())<<' ';
    fout<<t.getFlightDate()<<' ';
    fout<<t.getFlightTime()<<' ';
    fout<<encrypterStr(t.getFlightSerial())<<' ';
    fout<<encrypterStr(t.getAircraftSerial())<<' ';
    fout<<encrypterInt(t.getProceedsFromTicketSales())<<' ';
    fout<<encrypterStr(t.getPassengerFName())<<' ';
	fout<<encrypterStr(t.getPassengerLName())<<' ';
	fout<<encrypterStr(t.getPassengerNationalCode())<<' ';
	fout<<encrypterStr(t.getPilotPersonnelCode())<<' ';
	fout<<encrypterStr(t.getPickupSerial())<<' ';
	fout<<encrypterInt(t.getPrice())<<endl;
}
/****************************************/
ifstream& operator >>(ifstream& fin,Tickets& t)
{
	string str;
	Date d;
	Time tt;
	int n;

	fin>>str;
	t.setOrigin(decrypterStr(str));
	fin>>str;
	t.setDestination(decrypterStr(str));
    fin>>d;
	t.setFlightDate(d);
	fin>>tt;
	t.setFlightTime(tt);
    fin>>str;
	t.setFlightSerial(decrypterStr(str));
    fin>>str;
	t.setAircraftSerial(decrypterStr(str));
    fin>>str;
	t.setProceedsFromTicketSales(decrypterInt(str));
    fin>>str;
	t.setPassengerFName(decrypterStr(str));
    fin>>str;
	t.setPassengerLName(decrypterStr(str));
	fin>>str;
	t.setPassengerNationalCode(decrypterStr(str));
	fin>>str;
	t.setPilotPersonnelCode(decrypterStr(str));
	fin>>str;
	t.setPickupSerial(decrypterStr(str));
	fin>>str;
	t.setPrice(decrypterInt(str));
}
/****************************************/
ostream& operator <<(ostream& cout,Tickets& t)
{
	cout<<"--------------------------------------"<<endl;
	cout<<"tickets :"<<endl;
	cout<<"origin                     : "<<t.getOrigin()<<endl;
    cout<<"destination                : "<<t.getDestination()<<endl;
    cout<<"flight date                : "<<t.getFlightDate()<<endl;
    cout<<"flight time                : "<<t.getFlightTime()<<endl;
    cout<<"flight serial              : "<<t.getFlightSerial()<<endl;
    cout<<"aircraft serial            : "<<t.getAircraftSerial()<<endl;
    cout<<"proceeds from ticket sales : "<<t.getProceedsFromTicketSales()<<endl;
    cout<<"passenger first name       : "<<t.getPassengerFName()<<endl;
	cout<<"passenger last name        : "<<t.getPassengerLName()<<endl;
	cout<<"passenger national code    : "<<t.getPassengerNationalCode()<<endl;
	cout<<"pilot personnel code       : "<<t.getPilotPersonnelCode()<<endl;
	cout<<"pickup serial              : "<<t.getPickupSerial()<<endl;
	cout<<"price                      : "<<t.getPrice()<<endl;
	cout<<"--------------------------------------"<<endl;
}
/****************************************/
istream& operator >>(istream& cin,Tickets& t)
{
	string str;
	Date d;
	Time ti;
	int n;
	
	system("cls");
	cout<<"enter passenger first name :"<<endl;
	cin>>str;
	t.setPassengerFName(str);

	system("cls");
	cout<<"enter passenger last name :"<<endl;
	cin>>str;
	t.setPassengerLName(str);

	system("cls");
	cout<<"enter passenger national code :"<<endl;
	cin>>str;
	t.setPassengerNationalCode(str);

	system("cls");
	cout<<"enter flight serial :"<<endl;
	cin>>str;
	t.setFlightSerial(str);

	system("cls");
	cout<<"enter flight date (yyyy/mm/dd):"<<endl;
	cin>>d;
	t.setFlightDate(d);

	system("cls");
	cout<<"enter flight time (hh:mm:ss):"<<endl;
	cin>>ti;
	t.setFlightTime(ti);

	system("cls");
	cout<<"enter aircraft serial :"<<endl;
	cin>>str;
	t.setAircraftSerial(str);

	system("cls");
	cout<<"enter origin :"<<endl;
	cin>>str;
	t.setOrigin(str);

	system("cls");
	cout<<"enter destination :"<<endl;
	cin>>str;
	t.setDestination(str);

	system("cls");
	cout<<"enter pilot personnel code :"<<endl;
	cin>>str;
	t.setPilotPersonnelCode(str);

	system("cls");
	cout<<"enter pickup serial :"<<endl;
	cin>>str;
	t.setPickupSerial(str);

	system("cls");
	cout<<"enter tickets price :"<<endl;
	cin>>n;
	cin.ignore();
	t.setPrice(n);

	system("cls");
	cout<<"enter airport interest rate :"<<endl;
	cin>>n;
	cin.ignore();
	t.setProceedsFromTicketSales(n);
}
/*??????????????????????????????????????*/
/**class Pickup*/
/*??????????????????????????????????????*/
void Pickup::setJobList()
{
	//.........................................................................................
}
/****************************************/
Tickets& Pickup::getJobList()
{
    //.......................................................................................
}
/****************************************/
ofstream& operator <<(ofstream& fout,Pickup& p)
{
	fout<<encrypterStr(p.getSerial())<<' ';
	fout<<p.getProductionDate()<<endl;
}
/****************************************/
ifstream& operator >>(ifstream& fin,Pickup& p)
{
	string str;
	Date d;
	fin>>str;
	p.setSerial(decrypterStr(str));
	fin>>d;
	p.setProductionDate(d);
}
/****************************************/
ostream& operator <<(ostream& cout,Pickup& p)
{
	cout<<"--------------------------------------"<<endl;
	cout<<"pickup :"<<endl;
	cout<<"serial         : "<<p.getSerial()<<endl;
	cout<<"ProductionDate : "<<p.getProductionDate()<<endl;
	cout<<"--------------------------------------"<<endl;
}
/****************************************/
istream& operator >>(istream& cin,Pickup& p)
{
	string str;
	Date d;

	system("cls");
	cout<<"enter pickup serial :"<<endl;
	cin>>str;
	p.setSerial(str);

	system("cls");
	cout<<"enter pickup production date (yyyy/mm/dd):"<<endl;
	cin>>d;
	p.setProductionDate(d);
}
/*??????????????????????????????????????*/
/**class Passenger*/
/*??????????????????????????????????????*/
void Passenger::setFatherIsName(string str)
{
	fatherIsName=str;
}
/****************************************/
string Passenger::getFatherIsName()const
{
    return fatherIsName;
}
/****************************************/
ofstream& operator <<(ofstream& fout,Passenger& p)
{
	fout<<encrypterStr(p.getFName())<<' ';
	fout<<encrypterStr(p.getLName())<<' ';
	fout<<encrypterStr(p.getNationalCode())<<' ';
	fout<<p.getDateOfBirth()<<' ';
	fout<<encrypterStr(p.getFatherIsName())<<endl;
}
/****************************************/
ifstream& operator >>(ifstream& fin,Passenger& p)
{
	string str;
	Date d;
	fin>>str;
	p.setFName(decrypterStr(str));
	fin>>str;
	p.setLName(decrypterStr(str));
	fin>>str;
	p.setNationalCode(decrypterStr(str));
	fin>>d;
	p.setDateOfBirth(d);
	fin>>str;
	p.setFatherIsName(decrypterStr(str));
}
/****************************************/
ostream& operator <<(ostream& cout,Passenger& p)
{
	cout<<"--------------------------------------"<<endl;
	cout<<"passenger :"<<endl;
	cout<<"first name     : "<<p.getFName()<<endl;
	cout<<"last name      : "<<p.getLName()<<endl;
	cout<<"national code  : "<<p.getNationalCode()<<endl;
	cout<<"birthday       : "<<p.getDateOfBirth()<<endl;
	cout<<"name of father : "<<p.getFatherIsName()<<endl;
	cout<<"--------------------------------------"<<endl;
}
/****************************************/
istream& operator >>(istream& cin,Passenger& p)
{
	string str;
	Date d;

	system("cls");
	cout<<"enter passenger first name :"<<endl;
	cin>>str;
	p.setFName(str);

	system("cls");
	cout<<"enter passenger last name :"<<endl;
	cin>>str;
	p.setLName(str);

	system("cls");
	cout<<"enter passenger national code :"<<endl;
	cin>>str;
	p.setNationalCode(str);

	system("cls");
	cout<<"enter passenger Birthday (yyyy/mm/dd):"<<endl;
	cin>>d;
	p.setDateOfBirth(d);

	system("cls");
	cout<<"enter passenger father name :"<<endl;
	cin>>str;
	p.setFatherIsName(str);
}
/****************************************/
void Passenger::show()
{
	cout<<*this;
}
/*??????????????????????????????????????*/
/**class Aircraft*/
/*??????????????????????????????????????*/
void Aircraft::setNumberOfSeats(int n)
{
	numberOfSeats=n;
}
/****************************************/
void Aircraft::setJobList()
{
	//...........................................................................................
}
/****************************************/
int Aircraft::getNumberOfSeats()const
{
    return numberOfSeats;
}
/****************************************/
Fly& Aircraft::getJobList()
{
    //.......................................................................................
}
/****************************************/
ofstream& operator <<(ofstream& fout,Aircraft& a)
{
	fout<<encrypterStr(a.getSerial())<<' ';
	fout<<encrypterInt(a.getNumberOfSeats())<<' ';
	fout<<a.getProductionDate()<<endl;
}
/****************************************/
ifstream& operator >>(ifstream& fin,Aircraft& a)
{
	string str;
	Date d;
	fin>>str;
	a.setSerial(decrypterStr(str));
	fin>>str;
	a.setNumberOfSeats(decrypterInt(str));
	fin>>d;
	a.setProductionDate(d);
}
/****************************************/
ostream& operator <<(ostream& cout,Aircraft& a)
{
	cout<<"--------------------------------------"<<endl;
	cout<<"aircraft :"<<endl;
	cout<<"serial : "<<a.getSerial()<<endl;
	cout<<"number of seats :"<<a.getNumberOfSeats()<<endl;
	cout<<"production date : "<<a.getProductionDate()<<endl;
	cout<<"--------------------------------------"<<endl;
}
/****************************************/
istream& operator >>(istream& cin,Aircraft& a)
{
	string str;
	Date d;
	int n;

	system("cls");
	cout<<"enter aircraft serial :"<<endl;
	cin>>str;
	a.setSerial(str);

	system("cls");
	cout<<"enter aircraft production date (yyyy/mm/dd):"<<endl;
	cin>>d;
	a.setProductionDate(d);

	system("cls");
	cout<<"enter number of seats :"<<endl;
	cin>>n;
	cin.ignore();
	a.setNumberOfSeats(n);
}
/*??????????????????????????????????????*/
/**class Stewardess*/
/*??????????????????????????????????????*/
ofstream& operator <<(ofstream& fout,Stewardess& s)
{
	fout<<encrypterStr(s.getFName())<<' ';
	fout<<encrypterStr(s.getLName())<<' ';
	fout<<encrypterStr(s.getNationalCode())<<' ';
	fout<<s.getDateOfBirth()<<' ';
	fout<<encrypterStr(s.getPersonnelCode())<<' ';
	fout<<s.getHiringDate()<<endl;
}
/****************************************/
ifstream& operator >>(ifstream& fin,Stewardess& s)
{
	string str;
	Date d;
	fin>>str;
	s.setFName(decrypterStr(str));
	fin>>str;
	s.setLName(decrypterStr(str));
	fin>>str;
	s.setNationalCode(decrypterStr(str));
	fin>>d;
	s.setDateOfBirth(d);
	fin>>str;
	s.setPersonnelCode(decrypterStr(str));
	fin>>d;
	s.setHiringDate(d);
}
/****************************************/
ostream& operator <<(ostream& cout,Stewardess& s)
{
	cout<<"--------------------------------------"<<endl;
	cout<<"stewardess :"<<endl;
	cout<<"first Name     : "<<s.getFName()<<endl;
	cout<<"last Name      : "<<s.getLName()<<endl;
	cout<<"national Code  : "<<s.getNationalCode()<<endl;
	cout<<"birthday       : "<<s.getDateOfBirth()<<endl;
	cout<<"personnel Code : "<<s.getPersonnelCode()<<endl;
	cout<<"hiring Date    : "<<s.getHiringDate()<<endl;
	cout<<"--------------------------------------"<<endl;
}
/****************************************/
istream& operator >>(istream& cin,Stewardess& s)
{
	string str;
	Date d;

	system("cls");
	cout<<"enter stewardess first name :"<<endl;
	cin>>str;
	s.setFName(str);

	system("cls");
	cout<<"enter stewardess last name :"<<endl;
	cin>>str;
	s.setLName(str);

	system("cls");
	cout<<"enter stewardess national code :"<<endl;
	cin>>str;
	s.setNationalCode(str);

	system("cls");
	cout<<"enter stewardess Birthday (yyyy/mm/dd):"<<endl;
	cin>>d;
	s.setDateOfBirth(d);


	system("cls");
	cout<<"enter stewardess  personnel code:"<<endl;
	cin>>str;
	s.setPersonnelCode(str);

	system("cls");
	cout<<"enter stewardess hiring Date (yyyy/mm/dd):"<<endl;
	cin>>d;
	s.setHiringDate(d);
}
/****************************************/
void Stewardess::show()
{
	cout<<*this;
}
/*??????????????????????????????????????*/
/**class Pilot*/
/*??????????????????????????????????????*/
void Pilot::setRankk(int r)
{
	rankk=r>0&&r<4?r:3;
}
/****************************************/
int Pilot::getRankk()const
{
    return rankk;
}
/****************************************/
ofstream& operator <<(ofstream& fout,Pilot& p)
{
	fout<<encrypterStr(p.getFName())<<' ';
	fout<<encrypterStr(p.getLName())<<' ';
	fout<<encrypterStr(p.getNationalCode())<<' ';
	fout<<p.getDateOfBirth()<<' ';
	fout<<encrypterStr(p.getPersonnelCode())<<' ';
	fout<<p.getHiringDate()<<' ';
	fout<<encrypterInt(p.getRankk())<<endl;	
}
/****************************************/
ifstream& operator >>(ifstream& fin,Pilot& p)
{
	string str;
	Date d;
	fin>>str;
	p.setFName(decrypterStr(str));
	fin>>str;
	p.setLName(decrypterStr(str));
	fin>>str;
	p.setNationalCode(decrypterStr(str));
	fin>>d;
	p.setDateOfBirth(d);
	fin>>str;
	p.setPersonnelCode(decrypterStr(str));
	fin>>d;
	p.setHiringDate(d);
	fin>>str;
	p.setRankk(decrypterInt(str));	
}
/****************************************/
ostream& operator <<(ostream& cout,Pilot& p)
{
	cout<<"--------------------------------------"<<endl;
	cout<<"pilot :"<<endl;
	cout<<"first name     : "<<p.getFName()<<endl;
	cout<<"last name      : "<<p.getLName()<<endl;
	cout<<"national code  : "<<p.getNationalCode()<<endl;
	cout<<"birthday       : "<<p.getDateOfBirth()<<endl;
	cout<<"personnel code : "<<p.getPersonnelCode()<<endl;
	cout<<"hiring date    : "<<p.getHiringDate()<<endl;
	cout<<"rank           : "<<p.getRankk()<<endl;
	cout<<"--------------------------------------"<<endl;
}
/****************************************/
istream& operator >>(istream& cin,Pilot& p)
{
	string str;
	Date d;
	int r;

	system("cls");
	cout<<"enter pilot first name :"<<endl;
	cin>>str;
	p.setFName(str);

	system("cls");
	cout<<"enter pilot last name :"<<endl;
	cin>>str;
	p.setLName(str);

	system("cls");
	cout<<"enter pilot national code :"<<endl;
	cin>>str;
	p.setNationalCode(str);

	system("cls");
	cout<<"enter pilot Birthday (yyyy/mm/dd):"<<endl;
	cin>>d;
	p.setDateOfBirth(d);


	system("cls");
	cout<<"enter pilot  personnel code:"<<endl;
	cin>>str;
	p.setPersonnelCode(str);

	system("cls");
	cout<<"enter pilot hiring Date (yyyy/mm/dd):"<<endl;
	cin>>d;
	p.setHiringDate(d);

	system("cls");
	cout<<"enter rank :"<<endl;
	cin>>r;
	cin.ignore();
	p.setRankk(r);
}
/****************************************/
void Pilot::show()
{
	cout<<*this;
}
/*??????????????????????????????????????*/
/**class Fly*/
/*??????????????????????????????????????*/
void Fly::setNumberOfPassenger(int n)
{
	numberOfPassenger=n;
}
/****************************************/
void Fly::setPilot(Pilot p)
{
	pilot=p;
}
/****************************************/
void Fly::setStewardess(Stewardess s)
{
	stewardess.push_back(s);
}
/****************************************/
void Fly::setPassenger(Passenger p)
{
	passenger.push_back(p);
}
/****************************************/
int Fly::getNumberOfPassenger()const
{
    return numberOfPassenger;
}
/****************************************/
Pilot& Fly::getPilot()
{
    return pilot;
}
/****************************************/
vector<Stewardess>& Fly::getVStewardess()
{
    return stewardess;
}
/****************************************/
vector<Passenger>& Fly::getVPassenger()
{
    return passenger;
}
/****************************************/
ofstream& operator <<(ofstream& fout,Fly& f)
{
	fout<<encrypterStr(f.getOrigin())<<' ';
    fout<<encrypterStr(f.getDestination())<<' ';
    fout<<f.getFlightDate()<<' ';
    fout<<f.getFlightTime()<<' ';
    fout<<encrypterStr(f.getFlightSerial())<<' ';
    fout<<encrypterStr(f.getAircraftSerial())<<' ';
    fout<<encrypterInt(f.getProceedsFromTicketSales())<<' ';
    fout<<encrypterInt(f.getNumberOfPassenger())<<endl;
}
/****************************************/
ifstream& operator >>(ifstream& fin,Fly& f)
{
	string str;
	Date d;
	Time tt;
	Pilot pilot;

	fin>>str;
	f.setOrigin(decrypterStr(str));
	fin>>str;
	f.setDestination(decrypterStr(str));
    fin>>d;
	f.setFlightDate(d);
    fin>>tt;
	f.setFlightTime(tt);
    fin>>str;
	f.setFlightSerial(decrypterStr(str));
    fin>>str;
	f.setAircraftSerial(decrypterStr(str));
    fin>>str;
	f.setProceedsFromTicketSales(decrypterInt(str));
    fin>>str;
    f.setNumberOfPassenger(decrypterInt(str));
}
/****************************************/
ostream& operator <<(ostream& cout,Fly& f)
{
	cout<<"--------------------------------------"<<endl;
	cout<<"fly :"<<endl;
	cout<<"origin                     : "<<f.getOrigin()<<endl;
    cout<<"destination                : "<<f.getDestination()<<endl;
    cout<<"flight date                : "<<f.getFlightDate()<<endl;
    cout<<"flight time                : "<<f.getFlightTime()<<endl;
    cout<<"flight serial              : "<<f.getFlightSerial()<<endl;
    cout<<"aircraft serial            : "<<f.getAircraftSerial()<<endl;
    cout<<"proceeds from ticket sales : "<<f.getProceedsFromTicketSales()<<endl;
    cout<<"number of passenger        : "<<f.getNumberOfPassenger()<<endl;
	cout<<"pilot                      : NULL"/*<<f.getPilot().getFName()<<"  "<<f.getPilot().getLName()*/<<endl;
	cout<<"--------------------------------------"<<endl;
}
/****************************************/
istream& operator >>(istream& cin,Fly& f)
{
	string str;
	Date d;
	Time t;
	int n;

	system("cls");
	cout<<"enter flight serial :"<<endl;
	cin>>str;
	f.setFlightSerial(str);

	system("cls");
	cout<<"enter flight date (yyyy/mm/dd):"<<endl;
	cin>>d;
	f.setFlightDate(d);

	system("cls");
	cout<<"enter flight time (hh:mm:ss):"<<endl;
	cin>>t;
	f.setFlightTime(t);

	system("cls");
	cout<<"enter aircraft serial :"<<endl;
	cin>>str;
	f.setAircraftSerial(str);

	system("cls");
	cout<<"enter origin :"<<endl;
	cin>>str;
	f.setOrigin(str);

	system("cls");
	cout<<"enter destination :"<<endl;
	cin>>str;
	f.setDestination(str);

	system("cls");
	cout<<"enter airport interest rate :"<<endl;
	cin>>n;
	cin.ignore();
	f.setProceedsFromTicketSales(n);

	system("cls");
	cout<<"enter number of passenger :"<<endl;
	cin>>n;
	cin.ignore();
	f.setNumberOfPassenger(n);
}
/*??????????????????????????????????????*/
#endif // CLASSM_H
