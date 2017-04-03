#include "ground.h"




//Exercises:

//A: Try to scale the cube by a factor of 2.
//B: Try to rotate the cube around itself.
//C: Try to move the cube to another point.
//D: Try to rotate the cube in a certain distance around the origin.
//E: Try to sheer the cube.
/////




D3DXMATRIX transform_cube(char currentKey)
{
	static D3DXMATRIX M;
	//if you want to make animations, you can use the following variable and change them like rot+=0.001...
	static float rot = 0.0;
	static float trans = 0.0;
	static float scale = 0.0;
	//initialize the matrices as identity matrices
	D3DXMatrixIdentity(&M);
	//R = T = M;

	static D3DXMATRIX S = D3DXMATRIX(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	);

	D3DXMATRIX rotatet = D3DXMATRIX(
		cos(rot), sin(rot), 0, 0,
		-sin(rot), cos(rot), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	);

	D3DXMATRIX rotateX = D3DXMATRIX(
		cos(rot), 0, -sin(rot), 0,
		0, 0, 0, 0,
		sin(rot), cos(rot), 1, 0,
		0, 0, 0, 1
	);

	bool inc = false;
	if (currentKey == 'w') {
		M = M * rotateX;
		inc = true;
	}
	if (currentKey == 'd') {
		M = M * rotatet;
		inc = true;
	}

	if (inc == true) {
		rot += 0.001;
	}

	//M = M * S;
	
	if (rot > 360) {
		rot = 0;
	}
	static bool isBig = false;
	if (isBig == false)
		scale += 0.001;
	else if (isBig == true)
		scale -= 0.001;

	if (scale > 1)
		isBig = true;
	else if (scale < 0.0f)
		isBig = false;


	//Sorry, but the matrix needs to be transposed for intern program reason.
	D3DXMatrixTranspose(&M, &M);	
	return M;	//M will be used as final matrix

}