#pragma once

#include "MMath.h"
#include "Scene.h"
#include "Body.h" 
#include "LoadFile.h"
#include <map>
#include <vector>
#include <SDL.h>
#include "SDL_image.h"

using namespace MATH;
using namespace std;

class GameEngine : public Scene
{
private:
	int typeOfPiece;
	string imageName;
	Vec3 positionVec;

public:

	std::map<int, Body*> gameMap;
	std::vector<Body*> gameBodies;

	std::string folder;
	std::vector<std::string> spriteImage;
	std::vector<Vec3> spritePosition;

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
	void populateMap(std::map<int, std::string> spriteImage_);
	void populateVec(std::vector<std::string> spriteImage_, std::vector<Vec3> spritePosition_);
	~GameEngine();
};

