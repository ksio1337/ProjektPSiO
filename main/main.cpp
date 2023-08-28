#include"Silnikgry.h"

int main()
{
	//Initialize random seed
	srand(static_cast<unsigned>(time(0)));

	//Initialize game object
	SilnikGry silnikGry; 

	//Game loop
	silnikGry.run();
	/*while (silnikGry.running())
	{
		silnikGry.update();
		silnikGry.render();

	}*/

	//End of application
	return 0;
}