#include<iostream>
#include<cstring>
#include<string>
using namespace std;
class cricketteam {
private:
	string* membernames;
	int no_of_members;
	char * teamName;
	int Scoreinlast10matches[10];
	int Rank;
	string captain;
public:
	cricketteam();
	cricketteam(string  teamName, int no_of_members);
	cricketteam(string file);
	void setcaptain(string captainname);
	void setRank(int R);
	void setteamName(string team);
	void setnoofmembers(int);
	string getcaptain();
	int getRank();
	string getteamName();
	int getnoofmembers();
	float  averagscore();
	bool compare(cricketteam other);
	void printteam();
	void input();
};
