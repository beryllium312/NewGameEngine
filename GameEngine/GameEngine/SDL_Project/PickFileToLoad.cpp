#include "PickFileToLoad.h"


PickFileToLoad::PickFileToLoad()
{
}

std::string PickFileToLoad::searchAndStoreFileName(const std::string& folderName_)
{
	fs::path pathToShow(folderName_);
	std::vector<std::string> file_names;	
	using iterator = fs::recursive_directory_iterator;

	for (iterator iter(pathToShow); iter != iterator{}; ++iter) {
		string tempPath = iter->path().string();

		/*std::filesystem::path p(tempPath);
		p.make_preferred();
		std::string name = p.filename().string();	

		cout << "filename() = " << name << "\n"; for if you want just the file*/
		file_names.push_back(iter->path().string());
	}	

	vector<string> names;
	int userResult;
	std::cout << "Type a number associated with the file name: " << endl;

	for (int i = 0; i < file_names.size(); ++i)
	{
		file_names[i];
		std::cout << file_names[i] << endl;
	}	
	
	std::cin >> userResult;
	
	string finalSelection = file_names[userResult];
	std::cout << finalSelection << endl;
	return finalSelection;
}

PickFileToLoad::~PickFileToLoad()
{
}
