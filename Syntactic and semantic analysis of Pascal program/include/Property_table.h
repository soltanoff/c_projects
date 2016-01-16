#ifndef PROPERTY_TABLE_H
#define PROPERTY_TABLE_H

#include <stdio.h>
#include <Windows.h>

#ifndef _p_tab
#define _p_tab
typedef struct
{
	int row; // кол-во строк в таблице
	int col; // кол-во столбцов
	int **l; // принимаемая l
	int *mu; // значение функции mu(l)
} prop_table;/**/
#endif

int PROP_TAB_FAIL;

int get_prop_table(char* filename, prop_table** p_table, int *count)
{

	FILE* file_f = fopen(filename, "r");
	if (!file_f)
	{
		printf("\n[ERROR] Couldn't open file with table of property grammar.\n");
		PROP_TAB_FAIL = 1;
		system("pause");
		return 0;
	}
	else
	{
		fscanf(file_f, "%i", count);
		(*p_table) = (prop_table*)malloc(sizeof(prop_table) * (*count));
		for(int i = 0 ; i < (*count); i++)
		{
			fscanf(file_f, "%i", &((*p_table)[i].row));
			fscanf(file_f, "%i", &((*p_table)[i].col));

			(*p_table)[i].l = (int**)malloc(sizeof(int*) * (*p_table)[i].row);
			for(int j = 0; j < (*p_table)[i].row; j++)
					(*p_table)[i].l[j] = (int*)malloc(sizeof(int) * (*p_table)[i].col);

			for(int j = 0; j < (*p_table)[i].row; j++)
			{
				for(int k = 0; k < (*p_table)[i].col; k++)
				{
					fscanf(file_f, "%i", &((*p_table)[i].l[j][k]));
				}
			}

			(*p_table)[i].mu = (int*)malloc(sizeof(int*) * (*p_table)[i].row);
			for(int j = 0; j < (*p_table)[i].row; j++)
			{
				fscanf(file_f, "%i", &((*p_table)[i].mu[j]));
			}
		}
	}
	fclose(file_f);
	return 1;
}
int calculate_mu(int* l, prop_table* table, int index)
{
    index--;
	int found = 0;
	for(int i = 0; i < table[index].row; i++)
	{
		for(int k = 0; k < table[index].col; k++)
		{
			if (l[k] == table[index].l[i][k]) found = 1;
			else { found = 0; break; }
		}
		if (found) return table[index].mu[i];
	}
	return -1;
}
void view_prop_table(prop_table *table, int count)
{
	printf("Property table:");
	for(int i = 0; i < count; i++)
	{
		printf("\n\tRule #%i", i + 1);
		for(int j = 0; j < table[i].row; j++)
		{
			printf("\t\nL%i: ", j + 1);
			for(int k = 0; k < table[i].col; k++)
				printf("%i ", table[i].l[j][k]);
			printf("\tMu%i: %i", j + 1, table[i].mu[j]);
		}
	}
}
int free_prop_table(prop_table** table, int count)
{
	for(int i = 0; i < count; i++)
	{
		free((*table)[i].mu);

		for(int j = 0; j < (*table)[i].row; j++)
			free((*table)[i].l[j]);
		free((*table)[i].l);
	}
	free(*table);

	(*table) = NULL;
	return 1;
}
#endif // PROPERTY_TABLE_H