#include "PerceptionModel.hpp"
#include <stdlib.h>
#include <time.h>

double PerceptionModel::getProbability(double dist, Perception measurement)
{
	return 0;
}

PerceptionModel::PerceptionModel(PerceptionParams perceptionParams){
	this->perceptionParams = perceptionParams;
}

PerceptionModel::PerceptionModel(){

}
