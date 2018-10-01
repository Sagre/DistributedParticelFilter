#include <iostream>
#include <cmath>

/**
 * @brief Basic struct representing a position in euclidian coordiantes
 */
struct Vector3d{
	double x;
	double y;
	double z;

	Vector3d(double x,double y,double z){
		this->x = x;
		this->y = y;
		this->z = z;
	}
	Vector3d(){
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}
};

/**
 * @brief Basic struct representing an orientation in 3D
 */
struct Quaternion{
	double x;
	double y;
	double z;
	double w;

	Quaternion(double x, double y, double z, double w){
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}
	Quaternion(){
		this->x = 0;
		this->y = 0;
		this->z = 0;
		this->w = 0;
	}
};

/**
 * @brief A class taking care of a position and an orientation in a 3 dimensional space. Stores the position as 3 dimensional vector and the orientation as quaternion
 */
class Position3d{
	/**
	 * @brief Represents the current 3d Position
	 */
	private: Vector3d pos;

	 /**
	  * @brief Represents the current Orientation 
	  */
	private: Quaternion ori;

	 /**
	  * @brief Changes the 3d Position
	  *
	  * @param pos The new position
	  *
	  * @return 
	  */
	public: void setPos(Vector3d &pos);
	
	/**
	 * @brief Changes the orientation
	 *
	 * @param ori The new orientation
	 *
	 * @return 
	 */
	public: void setOri(Quaternion &ori);

	/**
	 * @brief Returns a pointer to the current 3d position
	 *
	 * @return A Pointer to the current position
	 */
	public: Vector3d* getPos();

	/**
	 * @brief Returns a pointer to the current orientation
	 *
	 * @return A pointer to the quaternion that represents the current orientation
	 */
	public: Quaternion* getOri();

	/**
	 * @brief Shifts the position in 3d-space
	 *
	 * @param Vector3d The vector from the old position to the new position
	 *
	 * @return 
	 */
	public: void shift(Vector3d);

	/**
	 * @brief Rotates the position
	 *
	 * @param Quaternion The quaternion representing the relative rotation
	 *
	 * @return 
	 */
	public: void rotate(Quaternion);

	/**
	 * @brief Constructor of a Position3d object with given coordinates and orientation 
	 *
	 * @param double x-Coordinate
	 * @param double y-Coordinate
	 * @param double z-Coordiante
	 * @param double x-Value of quaternion
	 * @param double y-Value of quaternion
	 * @param double z-Value of quaternion
	 * @param double w-Value of quaternion
	 *
	 * @return 
	 */
	public: Position3d(double,double,double,double,double,double,double);
	
	/**
	 * @brief Constructor for a Position3d object with given position and orientation
	 *
	 * @param pos The given position
	 * @param ori The given orientation
	 *
	 * @return 
	 */
	public: Position3d(Vector3d pos,Quaternion ori);
	
	/**
	 * @brief Constructor for an empty Position3d object
	 *
	 * @return 
	 */
	public: Position3d(){};
};

/**
 * @brief Returns the distance between two position3d
 *
 * @param pos1 The first position
 * @param pos2 The second position
 *
 * @return The distance between the two given positions
 */
double getDistance(Position3d pos1,Position3d pos2);
