#pragma once


#include <tchar.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <filesystem>
namespace fs = std::experimental::filesystem;

using namespace std;

class PickFileToLoad
{	
public:
	PickFileToLoad();
	std::string getFileName(std::vector<string> listOfFiles_);
	std::string searchAndStoreFileName(const std::string& folderName_);
	~PickFileToLoad();
};

