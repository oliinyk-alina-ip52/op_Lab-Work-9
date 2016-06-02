#include "stdafx.h"
#include "Task3.h"
#include "modules.h"
#include <iostream>

using namespace std;

void Task3(char *t,char *n)
{
	FILE*f = fopen(t, "rb+");
	if (f == nullptr)
	{
		perror("File not found");
		system("pause");
	}
	else
	{
		FILE *file = fopen(n, "wb+");
		int num;
		fscanf(f, "%d\n", &num);
		
		for (int i = 1; i < num; i++)
		{
			Work *table = ReadFromFile(t, i, num, f);
			if (table->tag != 2){
				if (table->prose.page>200){
					
					fprintf(file,"|%-10s|%-10s|%-6s|%-5d|%-10s|", table->name, table->author, table->nation, table->year, art_type[table->tag]);
					fprintf(file, "\n");
						printf("|%-10s|%-10s|%-6s|%-5d|%-10s|", table->name, table->author, table->nation, table->year, art_type[table->tag]);
						switch (table->tag){
						case(prose) : {
										  fprintf(file,"%11c%13c%-5d%14c%11c\n", '|', '|', table->prose.page, '|', '|\n');
										  printf("%11c%13c%-5d%14c%11c\n", '|', '|', table->prose.page, '|', '|');
										  fprintf(file, "\r\n");
										  break;
						}
						
					}
				}
			}
		}
		fclose(f);
		fclose(file);
	}
	printf("That's all");
}