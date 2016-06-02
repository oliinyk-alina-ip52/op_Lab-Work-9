#include"stdafx.h"
#include"modules.h"
#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <conio.h>


char* art_type[] = { "Poetry", "Prose", "Painting" };
char* poetry_form[] = { "Lyric", "Dramatical", "Prose", "Epic" };
char* poetry_size[] = { "Iamb", "Chorey", "Amphibrahiy", "Anapest", "Dactyl" };
char* paint_style[] = { "Impressionism", "Gotic", "Minimalism", "Renesance", "Cubism", "Naturmort" };
char* paint_techn[] = { "Pastel", "Oil", "Gouache", "Encaustic", "Acril" };

Work *ReadFromFile(char *s, int i, int num, FILE * f)
{
	Work *table = new Work;
	if (i < num)
	{
		fscanf(f, "%s %s %s %d %d ", table->name, table->author, table->nation, &table->year, &table->tag);
		switch (table->tag){
		case(poetry) : {
						   fscanf(f, "%d %d\n", &table->poetry.form, &table->poetry.size);
						   break;
		}
		case(prose) :
		{
						fscanf(f, "%d\n", &table->prose.page);
						break;
		}
		case(paint) :
		{
						fscanf(f, "%d %d\n", &table->paint.style, &table->paint.tec);
						break;
		}
		}
		return table;
	}
	else
	{
		fclose(f);
		delete table;
		return NULL;
	}
}
void OutputTable(char*s)
{
	FILE*f;
	fopen_s(&f,s, "rb+");
	if (f == nullptr)
	{
		perror("File not found");
		system("pause");
	}
	else
	{
		int num;
		fscanf_s(f, "%d\n", &num);
		char column[10][15] = { "Name", "Author", "Nation", "Year", "Art", "Form", "Size", "Pages", "Style", "Technic" };
		printf("\n|%-10s|%-10s|%-6s|%-5s|%-10s|%-10s|%-12s|%-5s|%-13s|%-10s|\n",
			column[0], column[1], column[2], column[3], column[4], column[5], column[6], column[7], column[8], column[9], column[10]);
		printf("-----------------------------------------------------------------------------------------------------\n");
		Work *table;
		int i = 0;
		while (table = ReadFromFile(s, i, num, f))
		{
			printf("|%-10s|%-10s|%-6s|%-5d|%-10s|", table->name, table->author, table->nation, table->year, art_type[table->tag]);
			switch (table->tag){
			case(poetry) : {
							   printf("%-10s|%-12s|%6c%14c%11c\n", poetry_form[table->poetry.form], poetry_size[table->poetry.size], '|', '|', '|');
							   break;
			}
			case(prose) :
			{
							printf("%11c%13c%-5d%14c%11c\n", '|', '|', table->prose.page, '|', '|');
							break;
			}
			case(paint) :
			{
							printf("%11c%13c%6c%-13s|%-10s|\n", '|', '|', '|', paint_style[table->paint.style], paint_techn[table->paint.tec]);
							break;
			}
			}
			printf("-----------------------------------------------------------------------------------------------------\n");
			i++;
		}
	}
}
void InputTable(char*s)
{
	FILE*f;
	fopen_s(&f,s, "rb+");
	if (f == nullptr)
	{
		perror("File not found");
		system("pause");
	}
	else
	{
		int num;
		fscanf_s(f, "%d\n", &num);
		char ch;
		Work *table = new Work;
		do{
			fseek(f, 0, SEEK_SET);
			fprintf(f, "%d", num + 1);
			fseek(f, 0, SEEK_END);

			cout << "\nInput name of artwork: "; cin >> table->name; fprintf(f, "\n%s ", table->name);
			cout << "Input surname of author: "; cin >> table->author; fprintf(f, "%s ", table->author);
			cout << "Input nation of author: "; cin >> table->nation; fprintf(f, "%s ", table->nation);
			cout << "Input year creation: "; cin >> table->year; fprintf(f, "%d ", table->year);
			switch (ChooseArt()){
			case(1) : {
						  table->tag = poetry; fprintf(f, "%d ", table->tag);
						  switch (ChooseForm()){
						  case(1) : {table->poetry.form = Lyrica; break; }
						  case(2) : {table->poetry.form = Dramatical; break; }
						  case(3) : {table->poetry.form = Prose; break; }
						  case(4) : {table->poetry.form = Epic; break; }
							  fprintf(f, "%d ", table->poetry.form);
						  }
						  switch (ChooseSize()){
						  case(1) : {table->poetry.size = Yamb; break; }
						  case(2) : {table->poetry.size = Chorey; break; }
						  case(3) : {table->poetry.size = Amfibrahiy; break; }
						  case(4) : {table->poetry.size = Anapest; break; }
						  case(5) : {table->poetry.size = Dactyl; break; }
							  fprintf(f, "%d", table->poetry.size);
						  }
						  break;
			}
			case(2) : {
						  table->tag = prose; fprintf(f, "%d ", table->tag);
						  printf("Input number of pages: ");
						  cin >> table->prose.page;
						  fprintf(f, "%d", table->prose.page);
						  break;
			}
			case(3) : {
						  table->tag = paint; fprintf(f, "%d ", table->tag);
						  switch (ChooseStyle()){
						  case(1) : {table->paint.style = Impressionism; break; }
						  case(2) : {table->paint.style = Gotic; break; }
						  case(3) : {table->paint.style = Minimalism; break; }
						  case(4) : {table->paint.style = Renesance; break; }
						  case(5) : {table->paint.style = Cubism; break; }
						  case(6) : {table->paint.style = Naturmort; break; }
							  fprintf(f, "%d ", table->paint.style);
						  }
						  switch (ChooseTechn()){
						  case(1) : {table->paint.tec = Pastel; break; }
						  case(2) : {table->paint.tec = Oil; break; }
						  case(3) : {table->paint.tec = Gouache; break; }
						  case(4) : {table->paint.tec = Encaustic; break; }
						  case(5) : {table->paint.tec = Acril; break; }
							  fprintf(f, "%d", table->paint.tec);
						  }
						  break;
			}
			}

			printf("Do you want to continue? 'Y' or  'N'\n");
			cin >> ch;
		} while (ch != 'n'&&ch != 'N');



		fclose(f);
	}
}

int ChooseArt()
{
	int k;
	cout << "\nChoose the artway of work:\n1 - poetry, 2 - prose, 3 - painting\nYour choose: ";
	cin >> k;
	if (k == 1 || k == 2 || k == 3)
		return k;
	else
	{
		printf("Press 1, 2 or 3!");
		ChooseArt();
	}
}
int ChooseForm()
{
	int k;
	cout << "\nChoose the poetry size:\n1 - lyric, 2 - dramatic, 3 - prose, 4 - epic\nYour choose: ";
	cin >> k;
	if (k == 1 || k == 2 || k == 3 || k == 4)
		return k;
	else
	{
		printf("Press 1, 2, 3 or 4!");
		ChooseForm();
	}
}
int ChooseSize()
{
	int k;
	cout << "\nChoose the form of poetry:\n1 - iamb, 2 - chorey, 3 - amphibrahiy, 4 - anapest, 5 - dactyl\nYour choose : ";
	cin >> k;
	if (k == 1 || k == 2 || k == 3 || k == 4 || k == 5)
		return k;
	else
	{
		printf("Press 1, 2, 3, 4 or 5!");
		ChooseSize();
	}
}
int ChooseStyle()
{
	int k;
	cout << "\nChoose style of painting:\n1 - impressionism, 2 - gotic, 3 - minimalism, 4 - renesance, 5 - cubism,  6 - naturmort\nYour choose : ";
	cin >> k;
	if (k == 1 || k == 2 || k == 3 || k == 4 || k == 5 || k == 6)
		return k;
	else
	{
		printf("Press 1, 2, 3, 4, 5 or 6!");
		ChooseStyle();
	}
}
int ChooseTechn()
{
	int k;
	cout << "\nChoose technic of painting:\n1 - pastel, 2 - oil, 3 - gouache, 4 - encaustic, 5 - acril\nYour choose : ";
	cin >> k;
	if (k == 1 || k == 2 || k == 3 || k == 4 || k == 5)
		return k;
	else
	{
		printf("Press 1, 2, 3, 4 or 5!");
		ChooseTechn();
	}
}