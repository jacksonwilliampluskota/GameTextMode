#ifndef __GAME_OVER_H__
#define __GAME_OVER_H__

class gameOver
{
private:
	int alturaGameOver = 12;
	int larguraGamerOver = 46;
	bool gameover = true;
	int modo = 3;
	void init();
	void update();
	void draw();

public:
	gameOver(int pontuacao);
};

#endif // !__GAME_OVER_H__
