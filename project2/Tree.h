// Tree.h

#ifndef Tree_H
#define Tree_H

#include "ModelView.h"
#include "ShaderIF.h"
#include "Cylinder.h"

class Tree : public ModelView
{
public:
	// Tree(ShaderIF* sIF, double xbIn, double ybIn, double rTreeTopIn, double rTrunkIn,
	// double heightIn, int numTreeTopPointsIn=30, int numTrunkPointsIn=25);
	Tree(ShaderIF* sIF, double x, double y, double z);
	virtual ~Tree();

	// xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
	void getMCBoundingBox(double* xyzLimitsF) const;
	void render();
	void renderTree() const;
private:
	ShaderIF* shaderIF;
	GLuint vao[1];
	GLuint vbo[1]; // stores both trunk and treetop points
	int numTrunkTriStripPoints;
	float ka[3], kd[3];
	double xb, yb, rTreeTop, rTrunk, height;
	int numTreeTopPoints, numTrunkPoints;
	double xmin, xmax, ymin, ymax, zmin, zmax;
	Cylinder* cylinders[3];
};

#endif
