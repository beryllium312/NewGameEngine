#pragma once

#include "Body.h"
#include "Vector.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>


using namespace MATH;
using namespace std;

class LoadFile
{
public:
	std::string characterSpriteName;
	std::string enemySpriteName;
	std::string landSpriteName;
	Vec3 characterVector;
	Vec3 enemyVector;
	Vec3 landVector;

	

	//std::map<int, Body*> vecOfBodies;

	//std::string folder;
	std::vector<std::string> imageNames;
	std::vector<Vec3> postions;

	std::vector<Body*> vecOfBodies;

public:
	LoadFile();
	LoadFile(const char * fileName);
	~LoadFile();
private:
	void LoadObj(const char * fileName);
	float iterateVect(std::string nextLine);
	int iterateRect(std::string nextLine);
	void sendInfo(std::vector<std::string> spriteImage_, std::vector<Vec3> spritePosition_);
	void makeGamePiece(std::string imageFile_, Vec3 objVector_, int typeOfPiece_);

};
