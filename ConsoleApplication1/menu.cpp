#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#include "Console.h"

#include "menu.h"
#include "extra.h"
#include "jogo.h"

//#define COR_FUNDO_PRETO (WORD) 0x000000

int modo = 0;
//	HANDLE da thread da trilha sonora
HANDLE hndTrilhaSonora;

DWORD WINAPI trilhaSonora(LPVOID lpParam);

menu::menu()
{
	clrscr();

	DWORD dwThreadId;
	hndTrilhaSonora = CreateThread(
		NULL,           // default security attributes
		0,              // use default stack size  
		trilhaSonora,   // thread function 
		0,		        // argument to thread function 
		0,              // use default creation flags 
		&dwThreadId);

	init();

}

void menu::init()
{
	do
	{
		update();
		if (modo == 0) draw();
		Sleep(100);
	} while (menuIciou);

}

void menu::update()
{
	if (kbhit())
	{
		int tecla = getch();

		if (tecla == 13 && escolha == 1) {
			modo = 1;
			jogo initigame;
		} else {
			if (tecla == 13 && escolha == 2)
			{
				modo = 2;
				extra initExtra;
			}
		}

		if (tecla == 113) {
			modo = 0;
			menu initiExtraTomenu;
		}
		
		if (tecla == 27)
			menuIciou = false;

		switch (tecla) {
		case 72: 
			escolha = 1;
		break;
		case 80:
			escolha = 2;
		break;

		}

	}
}

void menu::draw()
{

	char** titulo;
	titulo = (char **)malloc(sizeof(char *) * alturaTitulo);

	for (int i = 0; i < alturaTitulo; i++) {
		titulo[i] = (char *)malloc(sizeof(char) * larguraTitulo);
	}

	titulo[0] = "#$$$$$#  #$$$$$#  #@   @#  @     @  #$$$$$#  #$$$$$#  @";
	titulo[1] = "@        @     @  @ @ @ @  @     @  @     @  @     @  @";
	titulo[2] = "@$$$$$@  @     @  @  @  @  @     @  @     @  @     @  @";
	titulo[3] = "      @  @$$$$$@  @     @  @     @  @$$$$@   @$$$$$@  @";
	titulo[4] = "@$$$$$@  @     @  @     @  @$$$$$@  @    $#  @     @  @";
	titulo[5] = "                                                       ";
	titulo[6] = "                                                       ";
	titulo[7] = "         #$$$$$#  @     @  #@   @#  #$$$$$#  @         ";
	titulo[8] = "              @@  @     @  @ @ @ @  @     @  @         ";
	titulo[9] = "           @@@    @     @  @  @  @  @$$$$@   @         ";
	titulo[10] = "         @@       @     @  @     @  @     @  @         ";
	titulo[11] = "         @$$$$$#  @$$$$$@  @     @  #$$$$$#  @         ";

	char especialChM = ' ';

	for (int i = 0; i < alturaTitulo; i++) {
		for (int a = 0; a < larguraTitulo; a++) {
			especialChM = titulo[i][a];
			if (especialChM == '@') {
				especialChM = 219;
			}
			else if (especialChM == '#') {
				especialChM = 220;
			}
			else if (especialChM == '$') {
				especialChM = 223;
			}
			if (especialChM != ' ') {
				char str[2] = { especialChM, 0 };
				mostrar(15 + a, 1 + i, FOREGROUND_RED, str);
			}
		}
	}

	if (escolha == 1)
	{
		mostrar(30, 16, FOREGROUND_WHITE | BACKGROUND_GREEN, "  Iniciar jogo ");
		mostrar(30, 18, FOREGROUND_WHITE, "  Extras       ");
	}

	if (escolha == 2)
	{
		mostrar(30, 16, FOREGROUND_WHITE, "  Iniciar jogo ");
		mostrar(30, 18, FOREGROUND_WHITE | BACKGROUND_GREEN, "  Extras       ");
	}

	mostrar(5, 22, FOREGROUND_WHITE, "Movimentos: Esquerda-Direita-Espada[Espaco]");
	mostrar(5, 24, FOREGROUND_WHITE, "Vidas: ");
	mostrar(12, 24, FOREGROUND_RED, "&&&");
}

DWORD WINAPI trilhaSonora(LPVOID lpParam)
{
	if (modo == 0)
	{
		while (modo == 0)
		{
			// Example of how to make different beep tones
			// Beep(523,500); // 523 hertz (C5) for 500 milliseconds


			// "Metallica : Harvester of Sorrow" Opening by DigiP
			// Notes and their Frequencies
			// http://www.phy.mtu.edu/~suits/notefreqs.html
			// 329: E
			// 493: B
			// 698: F^
			// 659: E^
			// 783: G^

			// 392: G
			// 440: A
			// 587: D
			// 349: F
			Beep(329, 300); //E
			Beep(493, 300); //B
			Beep(698, 300); //F^
			Beep(659, 600); //E^

			Beep(783, 300); //G^
			Beep(698, 300); //F^
			Beep(659, 600); //E^

			Beep(329, 100);
			Beep(493, 300);
			Beep(698, 300);
			Beep(659, 600);

			Beep(392, 250);
			Beep(440, 200);
			Beep(587, 300);

			Beep(349, 250);
			Beep(587, 500);

			Beep(329, 300);
			Beep(493, 300);
			Beep(698, 300);
			Beep(659, 600);

			Beep(783, 300);
			Beep(698, 300);
			Beep(659, 600);

			Beep(329, 100);
			Beep(493, 300);
			Beep(698, 300);
			Beep(659, 600);

			Beep(392, 250);
			Beep(440, 200);
			Beep(587, 300);

			Beep(349, 250);
			Beep(587, 400);

		}

	}
	else
	{
		ExitThread(0);
	}
	
}
