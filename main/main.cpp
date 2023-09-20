#include"Silnikgry.h"

int main()
{

	srand(static_cast<unsigned>(time(0)));

	//Obiekt gry
	SilnikGry silnikGry; 

	//Pętla gry
	silnikGry.run();
	

	return 0;
}