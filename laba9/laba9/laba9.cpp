// laba9.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include"modules.h"
#include"Task3.h"
#include <iostream>

void UserMenu();

int _tmain(int argc, _TCHAR* argv[])
{
	UserMenu();

	return 0;
}

void UserMenu()
{
	int c;
	while (true) {
		printf("\n1.Output information\n"
			"2.Write new information\n"
			"3.Find ukrainian authors\n"
			"4.Calculate number of naturmort paints\n"
			"5.Find romans wiht over 200 pages\n"

			"9.Exit\n");
		scanf_s("%d", &c);
		switch (c) {
		case 1:
			OutputTable("in.bin");;
			break;
		case 2:
			InputTable("in.bin");
			break;
		case 3:
			//Task1("in.bin");
			break;
		case 4:

			break;
		case 5:Task3("in.bin","new.bin");

			break;
		case 9:
			return;
		default:
			printf("Input error\n");
		}
	}
}