#pragma once

#include "MMath.h"
#include "Scene.h"
#include "Body.h" 
#include "LoadFile.h"
#include "PickFileToLoad.h"
#include "SDL_image.h"
#include <map>
#include <vector>
#include <SDL.h>


using namespace MATH;
using namespace std;

class GameEngine : public Scene
{
private:
	string fileName; //the holder for when new file or existing file is choosen
	int typeOfPiece;//start value of adding new item to the map
public:

	std::map<int, Body*> gameMap;	

	std::string folder;//folder append to add to a file
	std::vector<std::string> spriteImage;//list of images taken from LoadFile
	std::vector<Vec3> spritePosition;//list of vecs from LoadFile

private:
	SDL_Window * window;
	Matrix4 projectionMatrix;
	float elapsedTime = 0.0f;
	unsigned long frameCount = 0.0L;


public:
	GameEngine();
	GameEngine(SDL_Window* sdlWindow_);
	bool OnCreate();
	void Update();
	void HandleEvents();
	void Render();
	void OnDestroy();	
	~GameEngine();
};

