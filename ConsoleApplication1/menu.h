#ifndef __MENU_H__
#define __MENU_H__

class menu
{
private:
	bool menuIciou = true;
	int alturaTitulo = 12;
	int larguraTitulo = 56;
	int escolha = 1;
	void update();
	void draw();
	void init();


public:
	menu();

};


#endif // !__MENU_H__

