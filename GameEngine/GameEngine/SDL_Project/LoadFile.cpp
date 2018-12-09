#include "LoadFile.h"


LoadFile::LoadFile() {}

LoadFile::LoadFile(std::string fileName)
{
	LoadObj(fileName);
}

void LoadFile::LoadObj(std::string fileName)
{
	ifstream objectFile(fileName);//check to see if the file can is found = null	
	string nextLine;
	int pieceType = -1;
	string tempImageName;
	Vec3 tempPosition;

	if (!objectFile)
	{
		std::cout << "File not found" << std::endl;
	}

	while (getline(objectFile, nextLine))
	{
		string::iterator it = nextLine.begin();

		if (*it == 'f') {
			string tempName;
			// load the rest of the string into a new string and put it in a variable for the filename
			for (auto it2 = it + 2; it2 != nextLine.end(); ++it2) {
				tempName += *it2;
				tempImageName = tempName;
			}
		}
		else if (*it == 'v') {
			Vec3 tempPos;

			tempPos.x = iterateVect(nextLine);//local Vec3 inside the read file function			
			tempPos.y = iterateVect(nextLine);			
			tempPos.z = iterateVect(nextLine);
		
			tempPosition.x = tempPos.x;
			tempPosition.y = tempPos.y;
			tempPosition.z = tempPos.z;
		}

		else if (*it == 't') {
			string typestring;
			pieceType = -1;
			if (pieceType = -1) {
				for (auto it2 = it + 2; it2 != nextLine.end(); ++it2) {
					typestring += *it2;
				}
				pieceType = std::stoi(typestring);//convert str to int/////changed this to types

				switch (pieceType) {
				case 1:
				case 2:
				case 3:

					makeGamePiece(tempImageName, tempPosition, pieceType);

					break;

				default:
					cout << "default case" << endl;
					break;
				}

				continue;
			}
			else {

				objectFile.close();
			
			}
		}
	}
}


void LoadFile::makeGamePiece(std::string imageFile_, Vec3 objVector_, int typeOfPiece_)
{
	cout << "Inside makeGame" << endl;	

	switch (typeOfPiece_) {
	case 1:
		characterSpriteName = imageFile_;
		characterVector = objVector_;
		imageNames.push_back(characterSpriteName);
		postions.push_back(characterVector);
		cout << "Inside case 1" << endl;
		//Body* body = new Body(characterSpriteName, characterVector);
		//vecOfBodies.push_back(new Body(characterSpriteName, characterVector));
		//vecOfBodies.insert(std::pair<int, Body*>(count, body));
		break;

	case 2:
		enemySpriteName = imageFile_;
		enemyVector = objVector_;
		imageNames.push_back(enemySpriteName);
		postions.push_back(enemyVector);
		
		break;

	case 3:
		landSpriteName = imageFile_;
		landVector = objVector_;
		imageNames.push_back(landSpriteName);
		postions.push_back(landVector);
	
		break;

	default:
		break;
	}

}

void LoadFile::sendInfo(std::vector<std::string> spriteImage_, std::vector<Vec3> spritePosition_)
{

}

float LoadFile::iterateVect(std::string nextLine)
{
	string tempString;
	string tempSt;
	static int c = 0;
	++c;

	auto index = nextLine.find(" ");//find the first space
	tempString = nextLine.substr(index + 1, nextLine.length());
	index = tempString.find(" ");//find the next space after a number
	auto xValue = tempString.substr(0, index);

	tempSt = tempString.substr(index + 1, tempString.length());
	index = tempSt.find(" ");
	auto yValue = tempSt.substr(0, index);

	tempString = tempSt.substr(index + 1, tempSt.length());
	index = tempString.find(EOF);
	auto zValue = tempString.substr(0, index);

	switch (c)
	{
	case 1:
		return std::stof(xValue);//convert to float
		break;

	case 2:
		return std::stof(yValue);//convert to float
		break;

	case 3:
		c = 0;
		return std::stof(zValue);//convert to float		
		break;

	default:
		break;
	}
	return 0;
}

int LoadFile::iterateRect(std::string nextLine)
{
	string tempString;
	string tempSt;
	static int t = 0;
	++t;

	auto index = nextLine.find(" ");
	tempString = nextLine.substr(index + 1, nextLine.length());
	index = tempString.find(" ");
	auto xValue = tempString.substr(0, index);

	tempSt = tempString.substr(index + 1, tempString.length());	//5 length	
	index = tempString.find(" ");//after 5	
	auto yValue = tempSt.substr(0, index);//5 ""

	tempString = tempSt.substr(index + 1, tempSt.length());	//5 length	
	index = tempString.find(" ");
	auto wValue = tempString.substr(0, index);

	tempSt = tempString.substr(index + 1, tempString.length());	//5 length	
	index = tempSt.find(EOF);
	auto hValue = tempSt.substr(0, index);

	switch (t)
	{
	case 1:
		return std::stoi(xValue);//convert to float
		break;

	case 2:
		return std::stoi(yValue);//convert to float
		break;

	case 3:
		return std::stoi(wValue);//convert to float			
		break;

	case 4:
		t = 0;
		return std::stoi(hValue);//convert to float

		break;

	default:
		break;
	}
	return 0;
}

LoadFile::~LoadFile()
{
}
