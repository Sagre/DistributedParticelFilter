#include "MovingModel.hpp"


/*
 * 	Gets a suspected movement and rotation of the agent. Uses a custom movement model to return a possible position based on the model and the detected movement
 *	Adapt this to match a model of the movement of your agent
 *	
 */
Position3d MovementModel::getNewPosition(Position3d oldPosition, Vector3d shift, Quaternion rotation){
	//TEMP
	oldPosition.shift(shift);
	oldPosition.rotate(rotation);

	return oldPosition;
	//END TEMP
}
	
MovementModel::MovementModel(MovementParams params){
	this->params = params;
}

MovementModel::MovementModel(){
}


