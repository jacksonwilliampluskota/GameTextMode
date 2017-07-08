#ifndef __JOGO_H__
#define __JOGO_H__

class jogo
{
private:
	bool inicioJogo = true;
	int teclaJogo;
	int posicaoSamuraiX = 5;
	int posicaoSamuraiY = 14;
	int velocidadeSamurai = 1;
	int acaoSamurai;
	int samuraiVida = 3;
	bool atacando = false;
	bool parado = true;
	bool saltou = false;
	//** Zumbi 1
	int zumbiX = 25;
	int zumbiY = 16;
	int velocidadezumbi = 1;
	int zumbiVida = 3;
	int corZumbi = FOREGROUND_GREEN;
	int acaZumbi;
	int andando = 0;
	//** Zumbi 1

	//**Zumbi 2
	int zumbi2X = 72;
	int zumbi2Y = 7;
	int velocidadezumbi2 = 1;
	int zumbi2Vida = 3;
	int corZumbi2 = FOREGROUND_GREEN;
	int acaZumbi2;
	int andando2 = 1;
	//**Zumbi 2

	int floor = 24;


	int floor2X = 40;
	int floor2Y = 15;

	int portaX = 70;
	int portaY = 7;
	int corPorta = FOREGROUND_BLUE;


	int countS = 0;
	int countZ1 = 0;
	int countZ2 = 0;
	/*int alturaTitulo = 5;
	int larguraTitulo = 56;
	void menu();
	void updateMenu();*/
	void init();
	void update();
	void draw();
public:
	jogo();

};


#endif // !__JOGO_H__
