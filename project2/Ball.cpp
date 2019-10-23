// Ball.c++

#include "Ball.h"

Ball::Ball(ShaderIF* sIF) : shaderIF(sIF)
{
	// DON'T FORGET TO SET INSTANCE VARIABLES, PERHAPS USING
	// SOME CONSTRUCTOR PARAMETERS
}

Ball::~Ball()
{
}

// xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
void Ball::getMCBoundingBox(double* xyzLimits) const
{
	xyzLimits[0] = -1000.0; // xmin  Give real values!
	xyzLimits[1] = 1000.0;  // xmax         |
	xyzLimits[2] = -1234.5; // ymin         |
	xyzLimits[3] = -1011.2; // ymax         |
	xyzLimits[4] = -3000.0; // zmin         |
	xyzLimits[5] = -2000.0; // zmax        \_/
}

void Ball::render()
{
	// 1. Save current and establish new current shader program
	// ...

	// 2. Establish "mc_ec" and "ec_lds" matrices
	// ...

	renderXxx();

	// 5. Reestablish previous shader program
	// ...
}

void Ball::renderXxx()
{
	// 3. Set GLSL's "ka" and "kd" uniforms using this object's "ka" and "kd"
	//    instance variables
	// ...

	// 4. Establish any other attributes and make one or more calls to
	//    glDrawArrays and/or glDrawElements
	// ...
}
