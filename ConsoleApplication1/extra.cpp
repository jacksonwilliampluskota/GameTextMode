#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "extra.h"
#include "Console.h"

#include "menu.h"

#include <Windows.h>


//#define COR_FUNDO_PRETO (WORD) 0x000000

//char especialCh = ' ';


extra::extra()
{
	/*
	for (int i = 0; i < alturaTitulo; i++) {
		for (int a = 0; a < larguraTitulo; a++) {
			mostrar(a, i, COR_FUNDO_PRETO, especialCh);
		}
	}
	*/
	clrscr();

	init();
}

void extra::init()
{
	do
	{
		update();
		if (modo == 2) draw();
		Sleep(100);
	} while (extraInicio);
}

void extra::update()
{
	if (kbhit())
	{
		int c = getch();

		if (c == 27)
			extraInicio = false;

	}
}

void extra::draw()
{
	mostrar(15, 10, FOREGROUND_RED, "Desenvolvido por: Jackson William Pluskota");
}
