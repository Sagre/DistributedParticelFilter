#include <iostream>
#include <cmath>
#include "Particle.hpp"
#include "PerceptionModel.hpp"
#include "MovingModel.hpp"
#include <vector>
#include <fstream>

/**
 * @brief Class that stores a vector of particles and maintains them. Can integrate movements and measurements. Upon evaluating calculates the new distribution of weights, based on all measurements stored since the last evaluation
 */
class ParticleFilter{
	private: MovementModel movementModel;
	private: PerceptionModel perceptionModel;
	
	/**
	 * @brief The particle set representing the current belief about the position
	 */
	private: std::vector<Particle> particleSet;

	/*
	 * Storage of temporary weights for each measurement. 
	 */
	private: std::vector<std::vector<double>> reweights;
	 
	/**
	  * @brief Returns the particle set (For testing purposes!, do not edit) 
	  *
	  * @return The current Particle set
	  */
	public: std::vector<Particle> getParticleSet();

	/**
	 * @brief Prints the current particle set to the console. For testing purposes
	 *
	 * @return 
	 */
	public: void printParticleSet();

	/**
	 * @brief Prints the current particle set to the logfile. For testing purposes
	 *
	 * @return 
	 */
	public: void printParticleSet(std::ofstream *logFile);

	/**
	 * @brief Normalizes the weights of the particle set such that they sum up to 1
	 *
	 * @return 
	 */
	public: void normalize(); 

	 /**
	  * @brief Evaluates the measuerements and adapts the weight of the particles
	  *
	  * @return 
	  */
	public: void evaluate();

	/**
	 * @brief Adds a movement of the agent and adapts the particle set. The particle set is resampled, and every particle is relocated, based on the MovingModel. The Moving Model returns a new position for a given previous position and a movement relativ to the old position.
	 *
	 * @param shift The supposed/meassured shift of the agent. Given as a vector from the old to the new position
	 * @param rotation The supposed/measured rotation of the agent, relative to the previous rotation
	 *
	 * @return 
	 */
	public: void addMovement(Vector3d shift, Quaternion rotation);
	
	/**
	 * @brief Adds a measurement to the particlefilter. This leads to a reevaluation of the particles. The weights of the particles according to the measurement are stored until a new movement is added. Then the weights of the particles are adapted according to all measurements to this time. A measurement is given as a Perception object. The perception structure has to be adapted to what the specific agent is able to percieve. The particles are reevaluated according to the perception model. The perception model has to calculate the probability of percieving a measurement for given positions of two agents.
	 *
	 * @param emitterPartSet The particle Set which represents the belief about the position of the other agent
	 * @param measurement The measurement that was percieved
	 *
	 * @return 
	 */
	public: void addMeasurement(std::vector<Particle> emitterPartSet,Perception measurement);

	/**
	 * @brief Constructor for a particlefilter with given initial position and the desired number of particles. The particle set is initiated with uniform distributed weights.
	 *
	 * @param ParticleCount The desired maximum number of particles
	 * @param initialPosition The initial position of the agent.
	 * @param MovementParams The parameter of the custom movement model
	 * @param PerceptionParams The parameter of the custom perception model
	 *
	 * @return 
	 */
	public: ParticleFilter(int ParticleCount,Position3d initialPosition,MovementParams movementParams,PerceptionParams perceptionParams);

	/**
	 * @brief Returns a particle out of the particle set with the probability of its weight
	 *
	 * @return The chosen particle
	 */
	private: Particle getRandomParticle();
};

/**
 * @brief Returns the Certainty of the agent about its position. (1/Variance)
 *
 * @param std::vector The particle set 
 *
 * @return 1/variance of the particle set
 */
double getCertainty(std::vector<Particle>);

/**
 * @brief Calculates the central/mean position of the given particle set. x = sum(x_i * w_i)
 *
 * @param std::vector The particle set
 *
 * @return The central/mean position of the particle set
 */
Position3d getCentralPosition(std::vector<Particle>);

/**
 * @brief Returns the spread of the particle set (Variance)
 *
 * @param std::vector The particle set
 *
 * @return The variance of the particle set
 */
double getVariance(std::vector<Particle>);

/**
 * @brief Returns the distance between a position and particle set
 *
 * @param std::vector
 * @param Position3d
 *
 * @return 
 */
double getDistance(std::vector<Particle>,Position3d);
