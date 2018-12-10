#pragma once

#include "Body.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;
class SaveFile
{
public:
	SaveFile();
	void saveGameFile(std::map<int, Body*> bodyMap_);
	~SaveFile();
};

