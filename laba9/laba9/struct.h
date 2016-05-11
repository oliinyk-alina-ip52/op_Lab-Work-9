enum Art { poetry, prose, paint }; //����

enum PoetryForm{ Lyrica, Dramatical, Prose, Epic };//����� �����

enum PoetrySize{ Yamb, Chorey, Amfibrahiy, Anapest, Dactyl };//������ �����

enum PaintStyle{ Still_life, Portrait, Paysage };//�����������

enum PaintTechn{ Pastel, Oil, Gouache, Encaustic, Acril };//������� ����������

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