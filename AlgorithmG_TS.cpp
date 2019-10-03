#include "AlgorithmG_TS.h"
AGenetic::AGenetic(string gen, int Pobla_size, int gene_size) {
	GENES = gen;
	GENE_LENGHT = gene_size;	
	this->POBLATION_LENGHT = Pobla_size;
	this->TOTAL_SUM = 0;
	this->State = false;
	generate_DISTANCE();
}
bool Compare(const Chromosome& P1, const Chromosome& P2) { return (P1.FITNESS < P2.FITNESS); }

void AGenetic::generate_DISTANCE() {
	for (unsigned int i = 0; i < GENE_LENGHT - 1; i++) {
		for (unsigned int j = i + 1; j < GENE_LENGHT; j++) {
			DISTANCE.push_back(make_pair(GENES[i], make_pair(GENES[j], rand() % 30)));
		}
	}
}
bool AGenetic::Solution() {
	return State;
}
int AGenetic::generate_RANDOM(int ini,int fin,int distinc) {
	int r;
	while (distinc == (r = (rand() % fin + ini)));
	return r;
}
Chromosome AGenetic::CROSSOVER(Chromosome P1, Chromosome P2) {
	int ini = generate_RANDOM(0,GENE_LENGHT,-1);
	int fin = generate_RANDOM(0,GENE_LENGHT,ini);

	int m_ini = min(ini,fin);
	int m_fin = max(ini,fin);

	int pos_i = 0;
	Chromosome Child = P1;
	string invalid = P1.Get_CHROMOSOME().substr(m_ini, m_fin-m_ini+1);
	for (unsigned int i = 0; i < m_ini; i++) {
		while (string::npos != invalid.find(P2.Get_CHROMOSOME()[pos_i])) {		
			pos_i++;
		}	
		Child.Get_CHROMOSOME()[i] = P2.Get_CHROMOSOME()[pos_i];
		pos_i++;
	}
	for (unsigned int i = m_fin+1; i < GENE_LENGHT; i++) {
		while (string::npos != invalid.find(P2.Get_CHROMOSOME()[pos_i])) {
			pos_i++;
		}
		Child.Get_CHROMOSOME()[i] = P2.Get_CHROMOSOME()[pos_i];
		pos_i++;
	}
	return Child;
}
void AGenetic::MUTATION(Chromosome& P1) {
	int Ini = generate_RANDOM(1, GENE_LENGHT-1, -1);
	int Fin = generate_RANDOM(1, GENE_LENGHT - 1, Ini);
	swap(P1.Get_CHROMOSOME()[Ini], P1.Get_CHROMOSOME()[Fin]);
}
int AGenetic::Roullete() {
	float random = generate_RANDOM(0, TOTAL_SUM, -1);
	float partial = 0;
	for (unsigned int i = 0; i < POBLATION_LENGHT; i++) {
		partial += Poblation[i].Get_FITNESS();
		if (random < partial) {
			return i;
		}
	} 
}
void AGenetic::SELECTION() {/*VALIDAR QUE LOS PADRES SEAN DIFERENTES*/
	vector<Chromosome>new_GENERATION;	
	for (unsigned int i = 0; i < POBLATION_LENGHT;i++) {
		Chromosome P1(Poblation[Roullete()].Get_CHROMOSOME(), 0);
		Chromosome P2(Poblation[Roullete()].Get_CHROMOSOME(), 0);
		Chromosome Child = CROSSOVER(P1, P2);
		MUTATION(Child);
		new_GENERATION.push_back(Child);
	}
	Poblation = new_GENERATION;	
}
int AGenetic::calculate_DISTANCE(char a, char b) {
	for (unsigned int i = 0; i < DISTANCE.size(); i++) {
		if ((DISTANCE[i].first == a && DISTANCE[i].second.first == b) || (DISTANCE[i].second.first == a && DISTANCE[i].first == b)) {
			return DISTANCE[i].second.second;
		}
	}
	return 0;
}

char AGenetic::Generate_GEN(string REMAINING) {
	int size = REMAINING.size();
	return REMAINING[rand() % size];
}
Chromosome AGenetic::Generate_CHROMOSOME() {
	string REMAINING=GENES;
	string chromo="";
	char INITIAL = GENES[0];
	char LAST;
	chromo += INITIAL;
	REMAINING.erase(REMAINING.find(INITIAL),1);
	for (unsigned int i = 0; i < GENE_LENGHT-1; i++) {
		LAST= Generate_GEN(REMAINING);
		chromo += LAST;
		REMAINING.erase(REMAINING.find(LAST),1);		
	}
	return Chromosome(chromo, 0);
}
void AGenetic::INITIAL_POBLATION() {
	for (unsigned int i = 0; i < POBLATION_LENGHT; i++) {
		Poblation.push_back(Generate_CHROMOSOME());
	}
}
int AGenetic::Get_BEST() {
	int min_=56789876546;
	int index=-1;
	for (unsigned int  i = 0; i < Poblation.size(); i++){
		if (min_> Poblation[i].Get_FITNESS()) {
			min_ = Poblation[i].Get_FITNESS();
			index = i;
		}
	}
	return index;
}
bool AGenetic::FITNESS_FUNCTION() {
	int fitns = 0;
	TOTAL_SUM = 0;
	for (unsigned int i = 0; i < Poblation.size(); i++) {
		for (unsigned int j = 0; j < GENE_LENGHT - 1; j++) {
			fitns += calculate_DISTANCE(Poblation[i].Get_CHROMOSOME()[j], Poblation[i].Get_CHROMOSOME()[j + 1]);		
		}
		TOTAL_SUM += fitns;
		Poblation[i].Set_FITNESS(fitns);		
		fitns = 0;
	}
	return false;
}
AGenetic::~AGenetic() {


}