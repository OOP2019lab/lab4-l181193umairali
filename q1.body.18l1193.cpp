#include"source.cpp";
#include<string>
#include<fstream>
cricketteam::cricketteam()
{
	membernames = nullptr;
	no_of_members = 2;
	teamName = nullptr;
	for (int i = 0; i < 10; i++)
	{
		Scoreinlast10matches[i] = -7;
	}
	Rank = 3;
	captain = nullptr;
}
cricketteam::cricketteam(string teamName, int members)
{
	membernames = nullptr;
	if (members > 0 && members < 12)
		no_of_members = members;
	else
		no_of_members = 0;
	teamName = nullptr;
	int len = name.length();
	teamName = new char[len + 1];
	strcpy(teamName, name.c_str());
	for (int i = 0; i < 10; i++)
		Scoreinlast10matches[i] = -1;
	Rank = 0;
}
cricketteam::cricketteam(string file)
{
	int j = 0, number = 0,lenght=0;
	string array;
	ifstream myfile("C:\\Users\\Ahmad Ali\\Desktop\\team.txt");
	getline(myfile, array, ':');
	while (!myfile.eof()) 
	{
		getline(myfile, array, ':');
		getline(myfile, array);
		int l = array.length;
		teamName = new char[lenght + 1];
		strcpy(teamName, array.c_str());
		getline(myfile, array, ':');
		myfile >> number;
		if (number > 12)
			no_of_members = number;
		else
			no_of_members = 0;

		myfile >> no_of_members;
		membernames = new string[no_of_members];
		for (int i = 0; i < no_of_members; i++) {
			getline(myfile, array);
			membernames[i] = array[i];
		}
		getline(myfile, array, ':');
		myfile >> number;
		if (number > 0)
			Rank = number;
		else
			Rank = 0;
		getline(myfile, array, ':');
		getline(myfile, array);
		captain = array;
		getline(myfile, array, ':');
		for (int i = 0; i < 10; i++)
		{
			getline(myfile, array, ',');
			number = stoi(array);
			Scoreinlast10matches[i] = number;
		}
	}
}

void cricketteam::setcaptain(string captainname)
{
	captain = captainname;
}
string cricketteam::getcaptain()
{
	return captain;
}
void cricketteam::setRank(int R)
{
	if (R > 0) 
		Rank = R;
	else
		Rank = 0;

}
	int cricketteam::getRank()
	{
		return Rank;
	}
	string cricketteam::getteamName()
	{
		return teamName;
	}
	void cricketteam::setteamName(string team) {
		int lenght = 0;
		string name;
		team = teamName;
		teamName = new char[lenght + 1];
		strcpy(teamName, name.c_str());
	}
	int cricketteam::getnoofmembers()
	{
		return 0;
	}
	void cricketteam::setnoofmembers(int number)
	{

		if (number > 0 && number < 12)
			no_of_members = number;
		else
			no_of_members = 0;
		membernames = new string[no_of_members];
	}
	int cricketteam::getnoofmembers()
	{
		return no_of_members;
	}
	float cricketteam::averagscore()
	{
		float sum = 0;
		float averag = 0;
		for (int i = 0; i < 10; i++)
		{
			sum = sum + Scoreinlast10matches[i];
		}
		averag = sum / 10;
		if (averag > 0)
			return averag;
		else
			return 0;
	}
	bool cricketteam::compare(cricketteam other)
	{
		float c = 0, d = 0;
		c = averagscore();
		d = other.averagscore();
		if (d > c)
			return true;
		else
			return false;
	}
	void cricketteam::printteam()
	{
		if (teamName != nullptr)
		{
			cout << "Team Name: ";
			for (int i = 0; teamName[i] != '\0'; i++)
				cout << teamName[i];
		}
		else
			cout << "No team name" << endl;
		cout << "Rank: " << Rank << endl;
		cout << "Captain: " << captain << endl;
		if (membernames != nullptr)
		{
			cout << "Numbers  of members in the team: " << no_of_members << endl;
			for (int i = 0; i < no_of_members; i++)
				cout << membernames[i];
		}
		else
			cout << "There is no team members";
		cout << endl;
		cout << "This is your  Previous Scores :";
		for (int i = 0; i < 10; i++)
			cout << Scoreinlast10matches[i] << " ";
		cout << endl;
	}
	void cricketteam::input()
	{
		int q = 0,number=0,lenght=0;
		string arr;
		ifstream myfile("C:\\Users\\Ahmad Ali\\Desktop\\team.txt");
		cout << "IF you want to take input from compiler Press 2 : \n if you want to input throgh file please  press 1: ";
		cin >> q;
		if (q == 1)
		{
			while (!myfile.eof())
			{
				getline(myfile, arr, ':');
				getline(myfile, arr);
				int l = arr.length();
				teamName = new char[lenght + 1];
				strcpy(teamName, arr.c_str());
				getline(myfile, arr, ':');
				myfile >> number;
				if (number > 12)
					no_of_members = number;
				else
					no_of_members = 0;

				myfile >> no_of_members;
				membernames = new string[no_of_members];
				for (int i = 0; i < no_of_members; i++) {
					getline(myfile, arr);
					membernames[i] = arr[i];
				}
				getline(myfile, arr, ':');
				myfile >> number;
				if (number > 0)
					Rank = number;
			}
			if (q == 2) {
				cout << "Now yoy are going to enter on compiler :";
				cout << "Please enter  team name :" << endl;
				cin >> teamName;
				cout << "Enter Team rank: " << endl;
				cin >> Rank;
				cout << "Enter  Name of the captaion: " << endl;
				cin >> captain;
				cout << "No of Team members: " << endl;
				cin >> no_of_members;
				membernames = new string[no_of_members];
				cout << "Enter members name : " << endl;
				for (int i = 0; i < no_of_members; i++)
				{
					cin >> membernames[i];
				}
				cout << "Enter 10 previous scores: " << endl;
				for (int i = 0; i < 10; i++)
					cin >> Scoreinlast10matches[i];
			}
		}
	}