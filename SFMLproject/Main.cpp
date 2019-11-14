#include "Game.h"



int main()
{
	//program entry point
	Game game; // creating our game object

	while (!game.GetWindow()->isDone())
	{
		//while loop
		game.HandleInput();
		game.Update();
		game.Render();
	}
	
}