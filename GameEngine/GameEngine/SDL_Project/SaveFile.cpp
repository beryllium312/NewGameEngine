#include "SaveFile.h"



SaveFile::SaveFile()
{
}

void SaveFile::saveGameFile(std::map<int, Body*> bodyMap_)
{
	std::string userInputTxt;
	std::cout << "Type a file name, NO SPACES or EXTENSION" << endl;
	cin >> userInputTxt;

	string extension = ".txt";
	std::string newFileName = userInputTxt.append(extension);

	ofstream file;
	file.open(newFileName);
	if (file.is_open()) {

		std::map<int, Body*>::iterator it = bodyMap_.begin();

		/*std::for_each(bodyMap_.begin(), bodyMap_.end(),
			[](std::pair<int, Body*> element) {

			
		});*/

		for (std::pair<int, Body*> element : bodyMap_) {
			
			Body* body = element.second;			

			if (body->getImage == "mainChar.bmp")
			{
				file << body->getImage << endl;
				file << body->pos << endl;
				file << "t 1" << endl;
			}
			if (body->getImage == "mainEnemy.bmp")
			{
				file << body->getImage << endl;
				file << body->pos << endl;
				file << "t 2" << endl;
			}
			if (body->getImage == "gameTile.bmp")
			{
				file << body->getImage << endl;
				file << body->pos << endl;
				file << "t 3" << endl;
			}
		}		
	}
	file.close();
	std::cin.get();//can delete just keeps up the screen


}

SaveFile::~SaveFile()
{
}
