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
	IMG_Init(IMG_INIT_PNG);

	projectionMatrix = MMath::viewportNDC(w, h) * MMath::orthographic(0.0f, 30.0f, 0.0f, 15.0f, 0.0f, 1.0f);

	PickFileToLoad loadFile;	
	std::string theUserLoadFile = loadFile.searchAndStoreFileName("loadWorkingFiles/");	//checks directory, returns string
	LoadFile emptyFile(theUserLoadFile);//sends string to load file

	//LoadFile emptyFile("empty_game.txt");//always loads this one
	
	spriteImage = emptyFile.imageNames;//is a vector holds images
	spritePosition = emptyFile.postions;//is a vector holds positions

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

	//Click button to save game?

}

void GameEngine::Render()
{
	SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
	SDL_Rect imageRectangle;
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xff, 0xff, 0xff));

	for (int i = 3; i < gameMap.size(); i++) {//changed to 3 so it doesn't render the base ones

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
