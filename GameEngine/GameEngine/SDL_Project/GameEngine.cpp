#include "GameEngine.h"

GameEngine::GameEngine()
{
}

GameEngine::GameEngine(SDL_Window* sdlWindow_)
{
	window = sdlWindow_;
	elapsedTime = 0.0f;

}

bool GameEngine::OnCreate()
{
	int w, h;
	SDL_GetWindowSize(window, &w, &h);
	//IMG_Init(IMG_INIT_PNG);

	projectionMatrix = MMath::viewportNDC(w, h) * MMath::orthographic(0.0f, 30.0f, 0.0f, 15.0f, 0.0f, 1.0f);
	PickFileToLoad loadFile;	
	std::string theUserLoadFile = loadFile.searchAndStoreFileName("loadWorkingFiles/");
	
	LoadFile emptyFile(theUserLoadFile);
	//LoadFile emptyFile("character_setup.txt");//always loads this one for variables
	//find file to load
	spriteImage = emptyFile.imageNames;
	spritePosition = emptyFile.postions;

	populateVec(emptyFile.imageNames, emptyFile.postions);

	for (int i = 0; i < spriteImage.size(); i++)
	{		
		std::string path = "pics/";
		
		path.append(spriteImage[i]);
		
		
		gameMap.insert(std::pair<int, Body*>(i, new Body(path, spritePosition[i])));

	}

	for (int i = 0; i < gameMap.size(); i++) {
		if (gameMap[0] == nullptr) {
			return false;
		}
		return true;
	}
	return true;

}
void GameEngine::Update()
{
	typeOfPiece = gameMap.size();//the map holding the pieces typeOfPiece can be the new key +1
}
void HandleEvents()
{
	
	//std::cout << "not pure virtual" << endl;
	//switch(key) 
	//{
	//	case 1:
	//		currentItem = createCharacter();
	//		createCharacter() 
	//		{
	//			currentImage = charSpite;
	//			currentVector = charVec;
	//		}

	//		OnMouseClick->Body *obj = new Body();
	//		push_back
	//		//or Char *ob



}

void GameEngine::populateVec(std::vector<std::string> spriteImage_, std::vector<Vec3> spritePosition_)
{
	spriteImage = spriteImage_;
	spritePosition = spritePosition_;
}

void GameEngine::Render()
{
	SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
	SDL_Rect imageRectangle;
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xff, 0xff, 0xff));//clear command, fills screen with white

	for (int i = 0; i < gameMap.size(); i++) {//change to not render the blank

		Vec3 screenCoords = projectionMatrix * gameMap[i]->pos;

		imageRectangle.h = gameMap[i]->getImage()->h;
		imageRectangle.w = gameMap[i]->getImage()->w;
		imageRectangle.x = screenCoords.x;
		imageRectangle.y = screenCoords.y;

		SDL_BlitSurface(gameMap[i]->getImage(), nullptr, screenSurface, &imageRectangle);

	}

	SDL_UpdateWindowSurface(window);
}
void GameEngine::OnDestroy()
{
	/*for (int i = 0; i < gameMap.size(); i++)
	{
		if (gameMap.) {
			delete gameMap;
			*gameMap[i] = nullptr;
		}
	}*/
}


GameEngine::~GameEngine()
{
}
