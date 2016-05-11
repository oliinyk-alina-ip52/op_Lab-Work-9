#include"stdafx.h"
#include"struct.h"

using namespace std;

int n,k[10];
Work work[20];

void input(char *t)
{
	FILE *f;
	fopen_s(&f, t, "wb");
	if (f == NULL)
		printf("Can't open file\n");
	else
	{
		cout << "Enter number of works: "; cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> work[i].name;
			//cin >> k[i];
			cin >> work[i].author;
			cin >> work[i].nation;
			fwrite(&work[i], sizeof(Work), 1, f);
		}
	}
	fclose(f);
}

void output(char *t)
{
	FILE *f;
	fopen_s(&f, t, "rb");
	if (f == NULL)
		printf("Can't find file\n");
	else
	{
		while (!feof(f)){
			for (int i = 0; i < n; i++){
				fread(&work[i], sizeof(Work), n, f);
				//fscanf_s(f,"%s  %d %s %s\n", work[i].name, work[i].year,  work[i].author, work[i].nation);
				printf("%s %s %s\n", work[i].name, work[i].author,work[i].nation);
			}
		}
	}
	system("pause");
	fclose(f);
}