#include"stdafx.h"
#include"struct.h"

using namespace std;

int n,k;
void input(char *t)
{
	Work work[10];
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
			cin >> k;
			cin>>work[i].year;
			cin>> work[i].author;
			cin>>work[i].nation;
			fwrite(&work[i], sizeof(Work), 1, f);
		}
	}
	fclose(f);
}

void output(char *t)
{
	Work work[20];
	FILE *f;
	fopen_s(&f, t, "rb");
	if (f == NULL)
		printf("Can't find file\n");
	else
	{
		while (!feof(f)){
			for (int i = 0; i < n; i++){
				fread(&work[i], sizeof(Work), 1, f);
				printf("%s %d %d %s %s\n", work[i].name, work[i].year,k, work[i].author,work[i].nation);
				cout << "\n";
			}
		}
	}
	fclose(f);
}