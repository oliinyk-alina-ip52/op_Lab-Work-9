enum Art { poetry, prose, paint }; //жанр

enum PoetryForm{ Lyrica, Dramatical, Prose, Epic };//форма стиха

enum PoetrySize{ Yamb, Chorey, Amfibrahiy, Anapest, Dactyl };//размер стиха

enum PaintStyle{ Still_life, Portrait, Paysage };//направление

enum PaintTechn{ Pastel, Oil, Gouache, Encaustic, Acril };//техника исполнения

struct Work
{
	char name[40];
	Art tag;
	int year;
	char author[50];
	char nation[20];
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