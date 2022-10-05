 /* 	Grace Todd
	CS 491: Simulation and Game Programming
	Fall 2022

	Project 2: Using GLM to manipulate matrices and transformations
	To Compile: g++ -o proj2 proj02.cpp
				./proj2
				or
				g++ proj02.cpp test02.o -o proj02
*/

/********************************
			HEADER FILES
	(Comment out for submission)
*********************************/

#include <stdio.h>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>

#define GLM_FORCE_RADIANS
#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/matrix_inverse.hpp"


glm::mat4
Multiply( glm::mat4 a, glm::mat4 b )
{
	// Multiplication between two 4x4 matrices is fairly straightforward
	// Since there is no conversion needed, GLM lets you just multiply

	return a * b;
}


glm::vec3
Multiply( glm::mat4 a, glm::vec3 b )
{
	// Multiply a 4x4 matrix with a vec3
	// 1. Turn vec3 into vec4
	// 2. Multiply mat4 and vec4
	// 3. Convert vec4 to vec3. This takes off the last element, 1.
	
	glm::vec3 c;
	glm::vec4 bVec4 = glm::vec4(b, 1.);
	glm::vec4 cVec4= a * bVec4;
	c = glm::vec3(cVec4);

    return c;
}


glm::vec3
ScalePointAroundAnotherPoint( glm::vec3 inputPoint, glm::vec3 centerPoint, glm::vec3 scale )
{
	// Create a scaling matrix and apply it to a point, returning the resulting point
	// Translate point before applying scaling properties:
	glm::vec3 relativePoint = inputPoint - centerPoint;

	// Develop scaling matrix
	glm::mat4 identity = glm::mat4(1.);
	glm::mat4 scalingMatrix = glm::scale(identity, scale);

	// Apply scaling to point
	glm::vec4 relativePointMatrix = scalingMatrix * glm::vec4(relativePoint, 1.);
	glm::vec3 resultPoint = glm::vec3(relativePointMatrix);

	// Return the scaled point, transformed back from the origin:
    return resultPoint + centerPoint;
}


glm::vec3
RotatePointAroundAnotherPoint( glm::vec3 inputPoint, glm::vec3 centerPoint, glm::mat4 first, glm::mat4 second, glm::mat4 third )
{
	// Rotates inputPoint by multiplying it by first, 
	// then multiplying it by seccond, then multiplying it by third.
	// Translate point before applying rotation matrices:
	glm::vec3 rotatedPoint = inputPoint - centerPoint;
	return rotatedPoint + centerPoint;
}


void
WhoAmI( std::string &yourName, std::string &yourEmailAddress )
{
	yourName = "Grace Todd";
	yourEmailAddress = "toddgr@oregonstate.edu" ;
}


void
PrintMatrix( glm::mat4 mat )
{
	for( int row = 0; row < 4; row++ )
	{
		fprintf( stderr, "  %7.2f %7.2f %7.2f %7.2f\n", mat[row][0], mat[row][1], mat[row][2], mat[row][3] );
	}
}

/********************************
		MAIN FUNCTION
	(Comment out for submission)
*********************************/

int main() {
	return 0;
}