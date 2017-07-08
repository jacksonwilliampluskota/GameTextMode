#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include"Console.h"
#include "gameOver.h"

#include <Windows.h>


gameOver::gameOver(int pontuacao)
{
	clrscr();
	char** titulo;
	titulo = (char **)malloc(sizeof(char *) * alturaGameOver);

	for (int i = 0; i < alturaGameOver; i++) {
		titulo[i] = (char *)malloc(sizeof(char) * larguraGamerOver);
	}

	titulo[0] = "#$$$$$#  #$$$$$#  #@   @#  @@@@@@@           ";
	titulo[1] = "@        @     @  @ @ @ @  @                 ";
	titulo[2] = "@   $$@  @     @  @  @  @  @@@@@@@           ";
	titulo[3] = "@     @  @$$$$$@  @     @  @                 ";
	titulo[4] = "@$$$$$@  @     @  @     @  @$$$$$@           ";
	titulo[5] = "                                             ";
	titulo[6] = "                                             ";
	titulo[7] = "          #$$$$$#  @    @  @@@@@@@  #$$$$$#  ";
	titulo[8] = "          @     @  @    @  @        @     @  ";
	titulo[9] = "          @     @  @    @  @@@@@@@  @     @  ";
	titulo[10] = "          @     @  @   @   @        @$$$$@   ";
	titulo[11] = "          #$$$$$#   $@$    @$$$$$@  @    $#  ";

	char especialChM = ' ';

	for (int i = 0; i < alturaGameOver; i++) {
		for (int a = 0; a < larguraGamerOver; a++) {
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
				mostrar(25 + a, 10 + i, FOREGROUND_RED, str);
			}
		}
	}

	mostrar(60, 27, FOREGROUND_YELLOW, "Pontos: ");
	mostrar(70, 27, FOREGROUND_RED, pontuacao);
	init();

}

void gameOver::init()
{
	do
	{
		update();
		if (modo == 3) draw();
		Sleep(100);
	} while (gameover);
}

void gameOver::update()
{
	if (kbhit())
	{
		int tecla = getch();
		if (tecla == 27)
			gameover = false;
	}
}

void gameOver::draw()
{
}