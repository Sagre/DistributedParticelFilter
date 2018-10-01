#include "Position3d.hpp"



Vector3d* Position3d::getPos() {
	return &(this->pos);
}

Quaternion* Position3d::getOri() {
	return &(this->ori);
}

void Position3d::setPos(Vector3d &pos) {
	this->pos = pos;
}

void Position3d::setOri(Quaternion &ori) {
	this->ori = ori;
}	

Position3d::Position3d(Vector3d pos, Quaternion ori){
	this->pos = pos;
	this->ori = ori;
}

void Position3d::shift(Vector3d movement){
	this->pos.x += movement.x;
	this->pos.y += movement.y;
	this->pos.z += movement.z;
}

/* 
 * The rotation of a quaternion p with a quaternion q is 
 * defined as qpq^-1
 * Source: https://www.3dgep.com/understanding-quaternions/
*/
void Position3d::rotate(Quaternion rotation){
	Quaternion ret;
	ret.w = this->ori.w*rotation.w - this->ori.x*rotation.x - this->ori.y*rotation.y - this->ori.z*rotation.z;
        ret.x = this->ori.w*rotation.x + rotation.w*this->ori.x + (this->ori.y*rotation.z - this->ori.z*rotation.y);
	ret.y = this->ori.w*rotation.y + rotation.w*this->ori.y + (this->ori.z*rotation.x - this->ori.x*rotation.z);
	ret.z = this->ori.w*rotation.z + rotation.w*this->ori.z + (this->ori.x*rotation.y - this->ori.y*rotation.x);	
	this->ori = ret;
}

Position3d::Position3d(double xPos, double yPos, double zPos, double xOri, double yOri, double zOri, double wOri){
	this->pos.x = xPos;
	this->pos.y = yPos;
	this->pos.z = zPos;
	this->ori.x = xOri;
	this->ori.y = yOri;
	this->ori.z = zOri;
	this->ori.w = wOri;	
}

double getDistance(Position3d pos1,Position3d pos2){
	double ret = 0;
	ret += pow(pos1.getPos()->x-pos2.getPos()->x,2.0);
	ret += pow(pos1.getPos()->y-pos2.getPos()->y,2.0);
	ret += pow(pos1.getPos()->z-pos2.getPos()->z,2.0);
	return sqrt(ret);
}
