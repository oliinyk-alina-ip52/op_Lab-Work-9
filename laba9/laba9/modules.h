#include "stdafx.h"
#include <string.h>

using namespace std;

#pragma warning(disable : 4996)


enum Art { poetry, prose, paint }; //жанр
extern char* art_type[];

enum PoetryForm{ Lyrica, Dramatical, Prose, Epic };//форма стиха
extern char* poetry_form[];

enum PoetrySize{ Yamb, Chorey, Amfibrahiy, Anapest, Dactyl };//размер стиха
extern char* poetry_size[];

enum PaintStyle{ Impressionism, Gotic, Minimalism, Renesance, Cubism, Naturmort };
extern char* paint_style[];
enum PaintTechn{ Pastel, Oil, Gouache, Encaustic, Acril };//техника исполнения
extern char* paint_techn[];

struct Work
{
	char name[10];
	Art tag;
	int year;
	char author[10];
	char nation[10];
	union
	{
		struct
		{
			int page;
		} prose;
		struct
		{
			PoetryForm form;
			PoetrySize size;
		} poetry;
		struct
		{
			PaintStyle style;
			PaintTechn tec;
		} paint;
	};
};

Work *ReadFromFile(char*, int, int, FILE*);
void OutputTable(char*s);
void InputTable(char*);

int ChooseArt();
int ChooseForm();
int ChooseSize();
int ChooseStyle();
int ChooseTechn();