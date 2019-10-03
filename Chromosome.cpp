#include "Chromosome.h"
string& Chromosome::Get_CHROMOSOME() {
	return CHROMOSOME;
}
int& Chromosome::Get_FITNESS() {
	return FITNESS;
}
void Chromosome::Set_FITNESS(int value) {
	this->FITNESS = value;
}
void Chromosome::Set_CHROMOSOME(string value) {
	this->CHROMOSOME = value;
}
Chromosome::Chromosome(string chro_, int size_) {
	CHROMOSOME = chro_;
	FITNESS = size_;
}
Chromosome::~Chromosome() {

}