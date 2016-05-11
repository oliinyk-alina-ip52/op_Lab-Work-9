#include"stdafx.h"
#include"struct.h"

using namespace std;

int n,k;
Work work;

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
			cin >> work.name;
			cin >> work.year;
			cin >> work.author;
			cin >> work.nation;
			fwrite(&work, sizeof(Work), 1, f);
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
				fread(&work, sizeof(Work), 1, f);
				//fscanf_s(f,"%s  %d %s %s\n", work[i].name, work[i].year,  work[i].author, work[i].nation);
				printf("%s %d %s %s\n", work.name,work.year, work.author,work.nation);
				cout << "\n";
			}
		}
	}
	fclose(f);
}