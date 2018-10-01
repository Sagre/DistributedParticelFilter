#include <iostream>

#include "Particle.hpp"

void Particle::setWeight(double w){
	this->weight = w;
}

double Particle::getWeight()
{
	return this->weight;
}

void Particle::setPosition(Position3d pos){
	this->position = pos;
}
	
Position3d Particle::getPosition(){
	return this->position;
}

Particle::Particle(Position3d pos, double w){
	this->position = pos;
	this->weight = w;
}

Particle::Particle(Vector3d pos, Quaternion ori, double w){
	Position3d tmp(pos,ori);
	this->position = tmp;
	this->weight = w;
}

Particle::Particle(double xPos, double yPos, double zPos, double xOri, double yOri, double zOri, double wOri, double w){
	this->weight = w;
	Position3d tmp(xPos,yPos,zPos,xOri,yOri,zOri,wOri);
	this->position = tmp;
}

void Particle::move(Vector3d shift, Quaternion rotation){
	this->position.shift(shift);
	this->position.rotate(rotation);
}

double getDistance(Particle partA, Particle partB){
	return getDistance(partA.getPosition(),partB.getPosition());
}
