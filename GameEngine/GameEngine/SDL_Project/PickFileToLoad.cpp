#include "PickFileToLoad.h"


PickFileToLoad::PickFileToLoad()
{
}

std::string PickFileToLoad::searchAndStoreFileName(const std::string& folderName_)
{
	fs::path pathToShow(folderName_);
	std::vector<std::string> file_names;//holds the names of the files in dir
	using iterator = fs::recursive_directory_iterator;

	for (iterator iter(pathToShow); iter != iterator{}; ++iter) {
		string tempPath = iter->path().string();//take the dir and file path
		file_names.push_back(iter->path().string());//stores the file path
	}	
	
	int userResult;
	std::cout << "Type a number associated with the file name Starting With 0: " << endl;

	for (int i = 0; i < file_names.size(); ++i)//lists the files and prints them
	{
		file_names[i];
		std::cout <<  file_names[i] << endl;
	}	
	
	std::cin >> userResult;
	
	string finalSelection = file_names[userResult];//selects the index fo the file
	std::cout << finalSelection << endl;
	return finalSelection;
}

PickFileToLoad::~PickFileToLoad()
{
}
