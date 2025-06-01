/*
 * TRABALHO1 - DESENHAR 3 QUADRADOS DE TAMANHOS DISTINTOS PARTINDO DO MESMO PONTO INICIAL
 * @Authors: Gabriel Roza, Lucas Weiss e Victor Hennemann
*/

#include <iostream>
#include "libs/EdubotLib.hpp"

void quadrado(EdubotLib * robo, int delay);

int main(){

	EdubotLib *edubotLib = new EdubotLib();

	if(edubotLib->connect())
	{
		quadrado(edubotLib, 500);
		quadrado(edubotLib, 1000);
		quadrado(edubotLib, 2000);

		edubotLib->neutral();
		edubotLib->sleepMilliseconds(2000);

		edubotLib->stop();
		edubotLib->sleepMilliseconds(2000);

		edubotLib->disconnect();
	}
	else
    {
		std::cout << "Could not connect on robot!" << std::endl;
	}

	return 0;
}

void quadrado(EdubotLib * robo, int delay)
{
	for(int i = 0; i < 4; i++)
	{
		robo->move(0.5);
		robo->sleepMilliseconds(delay);
		robo->rotate(90);
		robo->sleepMilliseconds(2500);
	}
}
