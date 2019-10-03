#pragma once
#include <string>
using namespace std;
class Chromosome{
public:
	Chromosome(string,int);
	~Chromosome();
	string & Get_CHROMOSOME();
	void Set_CHROMOSOME(string);
	int& Get_FITNESS();
	void Set_FITNESS(int);
	int FITNESS;
private:
	
	string CHROMOSOME;
};
