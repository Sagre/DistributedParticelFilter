#include <cmath>

#ifndef POSITION
#define POSITION
#include "Position3d.hpp"
#endif

/**
 * @brief Basic particle class. Stores a position and a weight. 
 */
class Particle {
	private: Position3d position;

	private: double weight;

	
	 /**
	  * @brief Constructor for a particle with given coordinates and weight
	  *
	  * @param xPos x-Coordinate
	  * @param yPos y-Coordinate
	  * @param zPos z-Coordinate
	  * @param xOri x-Value of the quaternion representing the orientation
	  * @param yOri y-Value of the quaternion representing the orientation
	  * @param zOri z-Value of the quaternion representing the orientation
	  * @param wOri w-Value of the quaternion representing the orientation
	  * @param w Desired weight of the particle
	  *
	  * @return 
	  */
	public: Particle(double xPos, double yPos ,double zPos, double xOri, double yOri, double zOri, double wOri, double w);


	/**
	 * @brief 
	 *
	 * @param Vector3d The desired position of the particle
	 * @param Quaternion The desired orientation of the particle
	 * @param double The desired weight of the particle
	 *
	 * @return 
	 */
	public: Particle(Vector3d, Quaternion, double);
	/**
	 * @brief Constructor for a particle with a given Position
	 *
	 * @param Position3d The desired Position of the particle
	 * @param double The desired weight of the particle
	 *
	 * @return A new Particle Object
	 */
	public: Particle(Position3d,double);
	
	/**
	 * @brief Constructor for an empty particle object
	 *
	 * @return An empty particle
	 */
	public: Particle(){};	
	
	/**
	 * @brief Changes the weight of the particle
	 *
	 * @param double The desired weight
	 *
	 * @return 
	 */
	public: void setWeight(double);

	/**
	 * @brief Returns the current weight of the particle 
	 *
	 * @return The current weight
	 */
	public: double getWeight();

	/**
	 * @brief Returns the 3d Position of the Particle 
	 *
	 * @return The position
	 */
	public: Position3d getPosition();

	/**
	 * @brief Changes the position of the particle
	 *
	 * @param pos The desired position of the particle
	 *
	 * @return 
	 */
	public: void setPosition(Position3d pos);

	/**
	 * @brief Moves the particle to a new position and rotates it
	 *
	 * @param Vector3d Vector from the old position to the new position
	 * @param Quaternion Rotation relative to the old orientation
	 *
	 * @return 
	 */
	public: void move(Vector3d,Quaternion);
	
};


/**
 * @brief Calculates the distance between two particles
 *
 * @param Particle The first particle
 * @param Particle The second particle
 *
 * @return The distance between the two given particles
 */
double getDistance(Particle, Particle);

