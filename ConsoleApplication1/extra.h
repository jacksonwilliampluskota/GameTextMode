#ifndef __EXTRA_H__
#define __EXTRA_H__

class extra
{
private:
	bool extraInicio = false;
	int modo = 2;
	int alturaTitulo = 25;
	int larguraTitulo = 70;
	void update();
	void draw();
	void init();
public:
	extra();
};

#endif // !__EXTRA_H__

