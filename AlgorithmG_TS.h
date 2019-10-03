#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>  
#include <time.h> 
#include <vector>
#include <map>
#include <utility> 
#include <algorithm>
#include "Chromosome.h"

using namespace std;
class AGenetic{
public:
	AGenetic(string,int,int);
	~AGenetic();
	void INITIAL_POBLATION();
	bool FITNESS_FUNCTION();
	void SELECTION();
	Chromosome CROSSOVER(Chromosome,Chromosome);
	void MUTATION(Chromosome&);		
	Chromosome Generate_CHROMOSOME();
	vector<Chromosome>Poblation;
	vector<pair<char, pair<char, int> >>DISTANCE;
	int Get_BEST();
	bool Solution();
private:	
	string GENES;
	char Generate_GEN(string);
	int GENE_LENGHT;
	void generate_DISTANCE();
	int generate_RANDOM(int,int,int);
	int Roullete();
	int calculate_DISTANCE(char,char);	
	int TOTAL_SUM;
	bool State;
	int POBLATION_LENGHT;
};
