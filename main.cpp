#include <iostream>
#include <string.h>
#include "AlgorithmG_TS.h"
#include "Chromosome.h"

using namespace std;
int main() {
	string CITYES="ABCDE";
	int S_POBLATION = 5;
	int Generations = 20;
	int S_CHROMOSOME = 5;
	AGenetic AlgGenetic(CITYES, S_POBLATION, S_CHROMOSOME);
	srand(time(NULL));
	AlgGenetic.INITIAL_POBLATION();
	//pair<char, pair<char, int>
	for (unsigned int i = 0; i < AlgGenetic.DISTANCE.size();i++) {
		cout << AlgGenetic.DISTANCE[i].first << " - " << AlgGenetic.DISTANCE[i].second.first <<"-"<<AlgGenetic.DISTANCE[i].second.second << endl;
	}
	cout << "-----------------------------------------------------------------------------------" << endl;
	for (unsigned int j = 0; j < Generations; j++) {
		AlgGenetic.FITNESS_FUNCTION();		
		cout << "Generation : " << j+1 << endl;
		for (unsigned int i = 0; i < AlgGenetic.Poblation.size(); i++) {
			cout << "Cromosome :" << AlgGenetic.Poblation[i].Get_CHROMOSOME() << " / ";
			cout << "Fitness :" << AlgGenetic.Poblation[i].FITNESS << endl;
		}
		cout << "Best Cromosome :" << AlgGenetic.Poblation[AlgGenetic.Get_BEST()].FITNESS<<" / ";
		cout << "Best Fitness :" << AlgGenetic.Poblation[AlgGenetic.Get_BEST()].Get_CHROMOSOME() << endl;
		AlgGenetic.SELECTION();
	}
	
	return 0;
}

