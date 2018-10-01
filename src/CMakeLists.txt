cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../bin")
find_package (Eigen3 3.3 REQUIRED NO_MODULE)

include_directories("../include")

set(HEADER_FILES 
	MovingModel.hpp
	)

add_executable(ParticleFilter 
	ParticleFilter.cxx
       	Particle.cxx
  Position3d.cxx
  MovingModel.cxx
  PerceptionModel.cxx
  ${HEADER_FILES}
)


target_link_libraries(ParticleFilter -ldl -lnsl -lm Eigen3::Eigen)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z")
set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -W")

