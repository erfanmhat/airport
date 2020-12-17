//this header file is for decleartion of all class's
#ifndef CLASS_H
#define CLASS_H
#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>
#include <vector>

using namespace std;

class Date;
class Time;
/*****************************************/
class ALL;//main data class of program
/*****************************************/
class Man;
class Employee;
class Machine;
class AirTrip;
/*****************************************/
class Tickets;
class Pickup;
class Passenger;
class Aircraft;
class Stewardess;
class Pilot;
class Fly;
/*??????????????????????????????????????*/
class Date
{
	private:
        int d;
        int m;
        int y;
    public:
        Date(int=0,int=0,int=0);
        Date(const Date &);

        void setDate(int,int,int);

        friend ofstream& operator <<(ofstream&,Date&);
        friend ifstream& operator >>(ifstream&,Date&);
        friend ostream& operator <<(ostream&,Date&);
        friend istream& operator >>(istream&,Date&);
        friend bool operator ==(Date&,Date&);
        friend bool operator <(Date&,Date&);
};
/*****************************************/
class Time {
	private:
	   int hour;
	   int minute;
	   int second;
	public:
	   Time( int = 0, int = 0, int = 0 );
	   Time &setTime( int, int, int );
	   Time &setHour( int );
	   Time &setMinute( int );
	   Time &setSecond( int );

	   int getHour() const;
	   int getMinute() const;
	   int getSecond() const;

	   friend ofstream& operator <<(ofstream&,Time&);
	   friend ifstream& operator >>(ifstream&,Time&);
	   friend ostream& operator <<(ostream&,Time&);
	   friend istream& operator >>(istream&,Time&);
};
/*****************************************/
class ALL
{
	public:
		vector<Tickets>tickets;
		vector<Pickup>pickup;
		vector<Passenger>passenger;
		vector<Aircraft>aircraft;
		vector<Stewardess>stewardess;
		vector<Pilot>pilot;
		vector<Fly>fly;
	
		void addTickets(Tickets&);
		void addPickup(Pickup&);
		void addPassenger(Passenger&);
		void addAircraft(Aircraft&);
		void addStewardess(Stewardess&);
		void addPilot(Pilot&);
		void addFly(Fly&);

		Tickets& getTickets(int);
		Pickup& getPickup(int);
		Passenger& getPassenger(int);
		Aircraft& getAircraft(int);
		Stewardess& getStewardess(int);
		Pilot& getPilot(int);
		Fly& getFly(int);

		vector<Tickets>& getVTickets();
		vector<Pickup>& getVPickup();
		vector<Passenger>& getVPassenger();
		vector<Aircraft>& getVAircraft();
		vector<Stewardess>& getVStewardess();
		vector<Pilot>& getVPilot();
		vector<Fly>& getVFly();

		friend ofstream& operator <<(ofstream&,ALL&);
		friend ifstream& operator >>(ifstream&,ALL&);
};
/*****************************************/
class Man
{
    private:
        string fName;
        string lName;
        string nationalCode;
        Date dateOfBirth;
    public:
        void setFName(string);
		void setLName(string);
		void setNationalCode(string);
		void setDateOfBirth(Date);

		string getFName()const;
		string getLName()const;
		string getNationalCode()const;
		Date& getDateOfBirth();

		virtual void show()=0;
};
/*****************************************/
class Employee:public Man
{
    private:
        string personnelCode;
        Date hiringDate;
        vector<Fly>jobList;
    public:
    	void setPersonnelCode(string str);
		void setHiringDate(Date);
		void setJob(Fly);

		string getPersonnelCode()const;
		Date& getHiringDate();
		vector<Fly>& getJobList();

		void showJobList();
};
/*****************************************/
class Machine
{
    private:
    	string serial;
    	Date productionDate;
    	vector<Fly>jobList;
    public:
    	void setSerial(string);
		void setProductionDate(Date);
		void setJob(Fly);

		string getSerial()const;
		Date& getProductionDate();
		vector<Fly>& getJobList();

		void showJobList();
};
/*****************************************/
class AirTrip
{
    private:
        string origin;
        string destination;
        Date flightDate;
        Time flightTime;
        string flightSerial;
        string aircraftSerial;
        int proceedsFromTicketSales;
    public:
    	void setOrigin(string);
		void setDestination(string);
		void setFlightDate(Date);
		void setFlightTime(Time);
		void setFlightSerial(string);
		void setAircraftSerial(string);
		void setPassenger();
		void setProceedsFromTicketSales(int);

		string getOrigin()const;
		string getDestination()const;
		Date& getFlightDate();
		Time& getFlightTime();
		string getFlightSerial()const;
		string getAircraftSerial()const;
		int getProceedsFromTicketSales()const;
};
/*****************************************/
class Tickets:public AirTrip
{
    private:
	    string passengerFName;
	    string passengerLName;
	    string passengerNationalCode;
	    string pilotPersonnelCode;
	    string pickupSerial;
	    int price;
    public:
    	void setPassengerFName(string);
		void setPassengerLName(string);
		void setPassengerNationalCode(string);
		void setPilotPersonnelCode(string);
		void setPickupSerial(string);
		void setPrice(int);

		string getPassengerFName()const;
		string getPassengerLName()const;
		string getPassengerNationalCode()const;
		string getPilotPersonnelCode()const;
		string getPickupSerial()const;
		int getPrice()const;

		friend ofstream& operator <<(ofstream&,Tickets&);
		friend ifstream& operator >>(ifstream&,Tickets&);
		friend ostream& operator <<(ostream&,Tickets&);
		friend istream& operator >>(istream&,Tickets&);
};
/*****************************************/
class Pickup:public Machine
{
    private:
    	vector <Tickets> jobList;
    public:
    	void setJobList();

    	Tickets& getJobList();

    	friend ofstream& operator <<(ofstream&,Pickup&);
		friend ifstream& operator >>(ifstream&,Pickup&);
		friend ostream& operator <<(ostream&,Pickup&);
		friend istream& operator >>(istream&,Pickup&);
};
/*****************************************/
class Passenger:public Man
{
    private:
    	string fatherIsName;
    public:
    	void setFatherIsName(string);

    	string getFatherIsName()const;

    	friend ofstream& operator <<(ofstream&,Passenger&);
		friend ifstream& operator >>(ifstream&,Passenger&);
		friend ostream& operator <<(ostream&,Passenger&);
		friend istream& operator >>(istream&,Passenger&);

		void show();
};
/*****************************************/
class Aircraft:public Machine
{
    private:
	    int numberOfSeats;
	    vector <Fly> jobList;
    public:
    	void setNumberOfSeats(int);
		void setJobList();

		int getNumberOfSeats()const;
		Fly& getJobList();

		friend ofstream& operator <<(ofstream&,Aircraft&);
		friend ifstream& operator >>(ifstream&,Aircraft&);
		friend ostream& operator <<(ostream&,Aircraft&);
		friend istream& operator >>(istream&,Aircraft&);
};
/*****************************************/
class Stewardess:public Employee
{
    public:
		friend ofstream& operator <<(ofstream&,Stewardess&);
		friend ifstream& operator >>(ifstream&,Stewardess&);
		friend ostream& operator <<(ostream&,Stewardess&);
		friend istream& operator >>(istream&,Stewardess&);

		void show();
};
/*****************************************/
class Pilot:public Employee
{
    private:
	    int rankk;
	public:
		void setRankk(int);

		int getRankk()const;

		friend ofstream& operator <<(ofstream&,Pilot&);
		friend ifstream& operator >>(ifstream&,Pilot&);
		friend ostream& operator <<(ostream&,Pilot&);
		friend istream& operator >>(istream&,Pilot&);

		void show();
};
/*****************************************/
class Fly:public AirTrip
{
    private:
	    int numberOfPassenger;
	    Pilot pilot;
	    vector<Stewardess> stewardess;
	    vector<Passenger> passenger;
	public:
		void setNumberOfPassenger(int);
		void setPilot(Pilot);
		void setStewardess(Stewardess);
		void setPassenger(Passenger);

		int getNumberOfPassenger()const;
		Pilot& getPilot();
		vector<Stewardess>& getVStewardess();
		vector<Passenger>& getVPassenger();

		friend ofstream& operator <<(ofstream&,Fly&);
		friend ifstream& operator >>(ifstream&,Fly&);
		friend ostream& operator <<(ostream&,Fly&);
		friend istream& operator >>(istream&,Fly&);
};
/*??????????????????????????????????????*/
#endif // CLASS_H
