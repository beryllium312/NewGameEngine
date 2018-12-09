#pragma once
#include "GameEngine.h"
#include "Scene.h"
#include "Window.h"
#include "Timer.h"
#include <iostream>

class GameManager {
private:
	
	class Window *ptr;
	class Timer *timer;
	bool isRunning;
	Scene *currentScene;

public:
	GameManager();
	~GameManager();
	bool OnCreate();
	void OnDestroy();

	void Run();
};



