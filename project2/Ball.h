// Ball.h

#ifndef Ball_H
#define Ball_H

#ifdef __APPLE_CC__
#include "GLFW/glfw3.h"
#else
#include <GL/gl.h>
#endif

#include "ModelView.h"
#include "ShaderIF.h"

class Ball : public ModelView
{
public:
	Ball(ShaderIF* sIF, double yb, double zb, double r);
	virtual ~Ball();

	// xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
	void getMCBoundingBox(double* xyzLimits) const;
	bool handleCommand(unsigned char anASCIIChar, double ldsX, double ldsY);
	void render();
	void renderBall();
private:
	ShaderIF* shaderIF;
	GLuint vao[1];
	GLuint vbo[2]; // 0: coordinates; 1: normal vectors
	float kd[3];
	double xmin, xmax, ymin, ymax, zmin, zmax;

	void defineBall(double x1, double x2, double yb, double zb, double r);
};

#endif
