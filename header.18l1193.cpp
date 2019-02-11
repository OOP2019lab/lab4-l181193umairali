#include"source.cpp"
#include"body.cpp";
int main()
{
	string teamname;
	cricketteam x1 = cricketteam("C:\\Users\\Lab\\Desktop\\team.txt");
	cout << teamname;
	cricketteam teamone;
	teamone.printteam;
	cricketteam teamsecond;
	teamsecond.printteam;
	int result = teamone.compare(teamsecond);
	cout << result;
	teamone.input();
		system("pause");
	return 0;
}