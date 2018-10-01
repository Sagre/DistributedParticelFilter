#include <iostream>
#include <cmath>

#ifndef POSITION
#define POSITION

#include "Position3d.hpp"

#endif


/*
 * @brief Struct containing all parameters needed for the movement model
 * Adapt this to your needs
 */
struct MovementParams {

};

/**
 * @brief MovementModel class. Stores a set of parameters. Has to offer  function that returns a new position for a given starting position and a measuret movement. The returned position is based on the user defined movement model
 */
class MovementModel{
	private: MovementParams params;
	
	public:	 
	/**
	 * @brief Returns a new position for a given old position and a movement that the agent was suspected to do. Adapt this function such that it represents a model of the uncertainty in the movement of the agent.
	 * 
	 *
	 * @param oldPosition The position at which the agent was in the beginning
	 * @param shift The suspected shift of the position relative to the old position
	 * @param rotation The suspected rotation of the agent relative to the old orientation
	 *
	 * @return A new possible position according to a model that represents the uncertainty of the agent
	 */
 	 Position3d getNewPosition(Position3d oldPosition,Vector3d shift, Quaternion rotation);
	
	 MovementModel(MovementParams params);
	 MovementModel();
};

	



