// main.c++: Starter for EECS 672 Projects 2-4

#include "ExtendedController.h"
#include "Tree.h"
#include "Block.h"

void createScene(ExtendedController& c, ShaderIF* sIF)
{	
	double grassColor[] = {0, 92, 9};
	c.addModel(new Block(sIF, 0.2, -0.009, 1.29, 0.001, 0.3, 0.3, grassColor));

	double treeTrunkColor[] = {165, 100, 6};
	double treeLeafColor[] = {77, 168, 59};

	double treeTrunksPosAlongY[] = {0.01, 0.03, 0.26, 0.05};
	double treeLeavesPosAlongY[] = {treeTrunksPosAlongY[0] - 0.009, treeTrunksPosAlongY[1] - 0.009, treeTrunksPosAlongY[2] - 0.009, treeTrunksPosAlongY[3] - 0.009};

	double treeTrunksPosAlongZ[] = {1.56, 1.4, 1.34, 1.53};
	double treeLeavesPosAlongZ[] = {treeTrunksPosAlongZ[0] - 0.01, treeTrunksPosAlongZ[1] - 0.01, treeTrunksPosAlongZ[2] - 0.01, treeTrunksPosAlongZ[3] - 0.01};

	c.addModel(new Tree(sIF, treeTrunksPosAlongY[0], treeTrunksPosAlongZ[0], 0.05, 0.23, treeLeavesPosAlongY[0], treeLeavesPosAlongZ[0], 0.022, 0.022, 0.022, treeLeafColor, treeTrunkColor));
	c.addModel(new Tree(sIF, treeTrunksPosAlongY[1], treeTrunksPosAlongZ[1], 0.05, 0.23, treeLeavesPosAlongY[1], treeLeavesPosAlongZ[1], 0.022, 0.022, 0.022, treeLeafColor, treeTrunkColor));
	c.addModel(new Tree(sIF, treeTrunksPosAlongY[2], treeTrunksPosAlongZ[2], 0.05, 0.23, treeLeavesPosAlongY[2], treeLeavesPosAlongZ[2], 0.022, 0.022, 0.022, treeLeafColor, treeTrunkColor));
	c.addModel(new Tree(sIF, treeTrunksPosAlongY[3], treeTrunksPosAlongZ[3], 0.05, 0.23, treeLeavesPosAlongY[3], treeLeavesPosAlongZ[3], 0.022, 0.022, 0.022, treeLeafColor, treeTrunkColor));
}

void set3DViewingInformation(double overallBB[])
{
	// be able to see entire screen initially (viewing strategy #1)
	ModelView::setMCRegionOfInterest(overallBB);

	// MC -> EC:
	double minX = overallBB[0];
	double maxX = overallBB[1];
	double minY = overallBB[2];
	double maxY = overallBB[3];
	double minZ = overallBB[4];
	double maxZ = overallBB[5];

	double midX = (maxX + minX) / 2;
	double midY = (maxY + minY) / 2;
	double midZ = (maxZ + minZ) / 2;

	// calculate radius for x, y, and z
	double xRadius = (maxX - minX) / 2;
	double yRadius = (maxY - minY) / 2;
	double zRadius = (maxZ - minZ) / 2;

	// set radius to be x or y or z (whichever value is greatest)
	double radius = xRadius;
	if (yRadius > radius)
	{
		radius = yRadius;
	}
	if (zRadius > radius)
	{
		radius = zRadius;
	}

	// compute/set eye, center, up
	double distance = 3.5 * radius;
	cryph::AffVector directionFromCenterToEye = cryph::AffVector(0, 0, 1);
	cryph::AffPoint center(midX, midY, midZ);
	cryph::AffPoint eye = center + (distance * directionFromCenterToEye);
	cryph::AffVector up = cryph::AffVector(1, 0, 0);
	ModelView::setEyeCenterUp(eye, center, up);

	// EC -> LDS:

	// specify the initial projection type desired
	ModelView::setProjection(PERSPECTIVE);

	// compute/set ecZmin, ecZmax (it is often useful to exaggerate
	// these limits somewhat to prevent unwanted depth clipping)
	double ecZmin = -distance - radius;
	double ecZmax = -distance + radius;
	ModelView::setECZminZmax(ecZmin, ecZmax);

	// compute/set ecZpp
	double ecZpp = ecZmax;
	ModelView::setProjectionPlaneZ(ecZpp);
}

int main(int argc, char* argv[])
{
	ExtendedController c("Feel the Snow Tribute", MVC_USE_DEPTH_BIT);
	c.reportVersions(std::cout);

	ShaderIF* sIF = new ShaderIF("shaders/basic.vsh", "shaders/phong.fsh");

	createScene(c, sIF);

	glClearColor(1.0, 1.0, 1.0, 1.0);

	double xyz[6];
	c.getOverallMCBoundingBox(xyz);
	std::cout << "Bounding box: " << xyz[0] << " <= x <= " << xyz[1] << '\n';
	std::cout << "              " << xyz[2] << " <= y <= " << xyz[3] << '\n';
	std::cout << "              " << xyz[4] << " <= z <= " << xyz[5] << "\n\n";
	set3DViewingInformation(xyz);

	c.run();

	delete sIF;

	return 0;
}
