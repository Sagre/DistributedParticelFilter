#include <iostream>
#include <cmath>

/*
 * @brief Adapt this struct to fit to the type of measurements
 * you are able to percieve
 */
struct Perception{
};


/*
 * @brief Adapt this struct to contain all parameters needed for the custom perception model
 */
struct PerceptionParams{

};

/**
 * @brief PerceptionModel class. Stores a set of parameters, passed by construction. Has to offer a getProbability function, that returns a value between 0 and 1 for a given measurement and a distance.
 */
class PerceptionModel{
	private: PerceptionParams perceptionParams;

	public:
		
		 /**
		  * @brief Should return a value between 0 and 1 for a given measurement and a distance. Have to be implemented on your own!
		  *
		  * @param dist Distance between the two points the measurement was taken
		  * @param measurement The measurement. The content of a measurement has to be defined by you
		  *
		  * @return The probability of the measurement
		  */
		double getProbability(double dist, Perception measurement);
		
		PerceptionModel(PerceptionParams perceptionParams);
		PerceptionModel();
};
