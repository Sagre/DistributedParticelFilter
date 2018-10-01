#include "ParticleFilter.hpp"

std::vector<Particle> ParticleFilter::getParticleSet(){
	return this->particleSet;
}

// Prints the Particle Set
void ParticleFilter::printParticleSet(){
	std::cout.precision(16);
	for(int i = 0; i < particleSet.size(); ++i){
		Position3d pos = particleSet[i].getPosition();
		std::cout << particleSet[i].getWeight() << " " << pos.getPos()->x << " " << pos.getPos()->y << " " << pos.getPos()->z << std::endl;
		 
	}

}

// Prints the Particle Set to a log file
void ParticleFilter::printParticleSet(std::ofstream *logFile){
	std::cout.precision(16);
	for(int i = 0; i < particleSet.size(); ++i){
		Position3d pos = particleSet[i].getPosition();
		(*logFile) << particleSet[i].getWeight() << " " << pos.getPos()->x << " " << pos.getPos()->y << " " << pos.getPos()->z << std::endl;
		 
	}

}

// Adapts the position of the particles
void ParticleFilter::addMovement(Vector3d shift, Quaternion rotation){
	//If there are measurements avaiable, reevaluate the weights
	if(reweights.size()!=0){
		evaluate();
	}

	std::vector<Particle> newParticleSet;
	double weight = 1;

	//Initial unifomly distributed weight
	weight = weight/particleSet.size();
	for(int i = 0; i < particleSet.size();++i){
		Particle chosen = getRandomParticle();
		//Gets a new position according to the moving model
		chosen.setPosition(movementModel.getNewPosition(chosen.getPosition(),shift,rotation));
		chosen.setWeight(weight);
		newParticleSet.push_back(chosen);
	
	}	
	particleSet=newParticleSet;
}

// Adds a measurement. The weights according to this measurement are stored in reweights
void ParticleFilter::addMeasurement(std::vector<Particle> emitterPartSet, Perception measurement){
	std::vector<double> weightAdaption;
	weightAdaption.resize(particleSet.size());

	for(int i = 0; i < weightAdaption.size();  ++i){
		double w = 0; 
		for (int j = 0; j < emitterPartSet.size(); ++j){
			w += perceptionModel.getProbability(getDistance(particleSet[i],emitterPartSet[j]),measurement) * emitterPartSet[j].getWeight();
		}		
		
		//Reweight the weight according to the uncertainty of the emitter about its position
		weightAdaption[i]= w * getCertainty(emitterPartSet);
	}	
	reweights.push_back(weightAdaption);
}

void ParticleFilter::evaluate(){
	if(reweights.size() == 0){
	 	std::cout << "Tried to evaluate, but no measurements\n";      
		return;
	}
	for(int i = 0; i < particleSet.size(); ++i){
		double w = 0; 
		for(int j = 0; j < reweights.size(); ++j){
			w += reweights[j][i];
		}
		particleSet[i].setWeight(w);
	}
	normalize();
	reweights.clear();
}

void ParticleFilter::normalize(){
	double totalWeight = 0;
	for(int i = 0; i<particleSet.size(); ++i){
		totalWeight += particleSet[i].getWeight();
	}
	totalWeight= 1/totalWeight;
	for(int i = 0; i<particleSet.size(); ++i){
		particleSet[i].setWeight(particleSet[i].getWeight()*totalWeight);
	}
}

Particle ParticleFilter::getRandomParticle(){
    double totalWeight = 0;

    double rand = (double)std::rand()/RAND_MAX;
       
    for(int i = 0; i < particleSet.size(); i++){
        totalWeight += particleSet[i].getWeight();
        if(rand<= totalWeight){
            return particleSet[i];
        }
    }
 
}

ParticleFilter::ParticleFilter(int ParticleCount, Position3d initialPosition, MovementParams movementParams, PerceptionParams perceptionParams){
	this->movementModel = MovementModel(movementParams);
	this->perceptionModel = PerceptionModel(perceptionModel);

	this->particleSet.resize(ParticleCount);

	double uniformWeight = 1/(double)ParticleCount;
	
	for(int i = 0; i<particleSet.size(); i++){
		particleSet[i].setPosition(initialPosition);
		particleSet[i].setWeight((double)uniformWeight);
	}
	
	std::cout << "Initiated ParticleSet at Position " << initialPosition.getPos()->x << " " << initialPosition.getPos()->y << " " << initialPosition.getPos()->z << " with " << ParticleCount << " particles" << std::endl;
}

double getVariance(std::vector<Particle> partSet){
	Position3d central = getCentralPosition(partSet);
	double ret = 0;
	for(int i = 0; i < partSet.size(); ++i){
		ret += partSet[i].getWeight() * pow(partSet[i].getPosition().getPos()->x - central.getPos()->x,2);
		ret += partSet[i].getWeight() * pow(partSet[i].getPosition().getPos()->y - central.getPos()->y,2);
		ret += partSet[i].getWeight() * pow(partSet[i].getPosition().getPos()->z - central.getPos()->z,2);
	}
	ret = ret/partSet.size();
	return sqrt(ret);
}

double getDistance(std::vector<Particle> partSet, Position3d pos){
	double dist = 0;
	for(int i = 0; i< partSet.size(); ++i){
		dist += getDistance(partSet[i].getPosition(),pos)*partSet[i].getWeight();
	}
	return dist;
}


Position3d getCentralPosition(std::vector<Particle> partSet){
	Vector3d centralPos(0,0,0);
	Quaternion centralOri(0,0,0,0);
	for(int i = 0; i < partSet.size(); ++i){
		centralPos.x += partSet[i].getPosition().getPos()->x * partSet[i].getWeight();
		centralPos.y += partSet[i].getPosition().getPos()->y * partSet[i].getWeight();
		centralPos.z += partSet[i].getPosition().getPos()->z * partSet[i].getWeight();
		centralOri.x += partSet[i].getPosition().getOri()->x * partSet[i].getWeight();
		centralOri.y += partSet[i].getPosition().getOri()->y * partSet[i].getWeight();
		centralOri.z += partSet[i].getPosition().getOri()->z * partSet[i].getWeight();
		centralOri.w += partSet[i].getPosition().getOri()->w * partSet[i].getWeight();
	}
	Position3d ret(centralPos,centralOri);
	return ret;
}

double getCertainty(std::vector<Particle> partSet){
	Position3d central = getCentralPosition(partSet);
	double certainty = 0;
	for(int i = 0; i < partSet.size(); ++i){
		certainty += getDistance(central,partSet[i].getPosition()) * partSet[i].getWeight();
	}
	certainty = sqrt(certainty);
	certainty = 1/(certainty+1);
	return certainty;
}


