#include<stdio.h>
#include<stdlib.h>
#include<iostream> 
#include <conio.h>  
#include <stdlib.h> 
#include <errno.h>
#include<string.h>

void input(char*);
void output(char*);

enum Art { poetry, prose, paint }; //жанр

enum PoetryForm{ Lyrica, Dramatical, Prose, Epic };//форма стиха

enum PoetrySize{ Yamb, Chorey, Amfibrahiy, Anapest, Dactyl };//размер стиха

enum PaintStyle{ Still_life, Portrait, Paysage };//направление

enum PaintTechn{ Pastel, Oil, Gouache, Encaustic, Acril };//техника исполнения

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