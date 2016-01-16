#ifndef TABLE_H
#define TABLE_H

#ifndef _tab
#define _tab
typedef struct Table
{
	char* ident; // имя идентификатора
	int prop; // текущее свойство индентификатора
	struct Table* next; // указатель н следующий элемент
} table;/**/
#endif

int SEM_ERROR;
table* DEC_LIST;
char* ERROR_MSG;
extern int line_counter;
extern const int MSG_SIZE;

table* find_in_table(char* ident, table* phead)
{
	table *temp = phead;
	while(temp)
	{
		if (!strcmp(ident, temp->ident)) { return temp; }
		temp = temp->next;
	}
	return NULL;
}
int add_table(char* ident, int prop, table** phead)
{
	if (!(*phead))
	{
		(*phead) = (table*)malloc(sizeof(table));
		(*phead)->ident = (char*)malloc(sizeof(char) * (strlen(ident) + 1));
		strcpy((*phead)->ident, ident);
		(*phead)->prop = prop;
		(*phead)->next = NULL;
	}
	else
	{
		table *p = find_in_table(ident, *phead);
		if (p) p->prop = prop;
		else
		{
			p = (*phead);
			while(p->next)
				p = p->next;
			table *temp = (table*)malloc(sizeof(table));
			temp->ident = (char*)malloc(sizeof(char) * (strlen(ident) + 1));
			strcpy(temp->ident, ident);
			temp->prop = prop;
			temp->next = NULL;
			p->next = temp;
		}
	}
	return 1;
}
int remove_table(char* ident, table** phead)
{
	if (phead)
	{
		table* temp = (*phead);
		if (!strcmp(temp->ident, ident))
		{
			(*phead) = temp->next;
			free(temp);
			temp = NULL;
			return 1;
		}
		else
		{
			table* before_p = temp;
			temp = temp->next;
			while(temp)
			{
				if (!strcmp(temp->ident, ident))
				{
					if (temp->next) before_p->next = temp->next;
					else before_p->next = NULL;
					free(temp);
					temp = NULL;
					return 1;
				}
				else
				{	
					before_p = temp;
					temp = temp->next;
				}
			}
		}
	}
	return 0;
}
void view_table(table* phead)
{
	table* temp = phead;
	printf("\nIdentifiers table:");
	for(int i = 1; temp; i++)
	{
		printf("\n\tIdentifier #%i:", i);
		printf("\n\t\tName: %s", temp->ident);
		printf("\n\t\tProperty: %i", temp->prop);
		temp = temp->next;
	}
}
int free_table(table** phead)
{
	while(*phead)
	{
		table* temp = *phead;
		*phead = temp->next;
		free(temp);
	}
	(*phead) = NULL;
	return 1;
}

table* test(int* l, table *list1, table *list2, prop_table *p_table, int rule_number)
{
	table* temp = (table*)malloc(sizeof(table));
	temp->next = NULL;
	temp->prop = NULL;
	int add_this = 1;

	table* result = NULL;

	l[0] = 0;
	l[1] = 0;

	while((list1) || (list2))
	{
		add_this = 1;
		if (list1)
		{
			temp->ident = (char*)malloc(sizeof(char*) * (strlen((list1)->ident) + 1));
			strcpy(temp->ident, (list1)->ident);
			l[0] = (list1)->prop;
		}
		else l[0] = 0;

		if (list2)
		{
			if (list1)
			{
				table* t = find_in_table(temp->ident, (list2));
				if (t)
				{
					l[1] = t->prop;
				    remove_table(t->ident, &list2);
				}
				else l[1] = 0;
			}
			else
			{
				temp->ident = (char*)malloc(sizeof(char*) * (strlen((list2)->ident) + 1));
				strcpy(temp->ident, (list2)->ident);
				l[1] = (list2)->prop;
				remove_table(temp->ident, &list2);
			}
		}
		else l[1] = 0;

		if (list1) remove_table(temp->ident, &list1);

		temp->prop = calculate_mu(l, p_table, rule_number);
		if (temp->prop < 0)
		{
			//char str_line[MSG_SIZE];
		    SEM_ERROR = 1;
			//view_table(DEC_LIST);
		    table* p = find_in_table(temp->ident, DEC_LIST);
			if (strlen(ERROR_MSG) >= 2)
				strcat(ERROR_MSG, "[ERROR] Semantic error: \a");
			else
				strcpy(ERROR_MSG, "\n[ERROR] Semantic error: \a");
			if (p)
            {
                if (p->prop == 2)
                {
                    strcat(ERROR_MSG, "The string identifier \"");
                    strcat(ERROR_MSG, temp->ident);
                    strcat(ERROR_MSG, "\" is used as a variable of type \"integer\".");
                }
                if (p->prop == 1)
                {
                    strcat(ERROR_MSG, "The integer identifier \"");
                    strcat(ERROR_MSG, temp->ident);
                    strcat(ERROR_MSG, "\" is used as a variable of type \"string\".");
                }
            }
            else
            {
                strcat(ERROR_MSG, "Unknown identifier \"");
                strcat(ERROR_MSG, temp->ident);
                strcat(ERROR_MSG, "\".");
            }

			strcat(ERROR_MSG, "\n");
			add_this = NULL;

		}
		if (add_this) add_table(temp->ident, temp->prop, &result);
		free(temp->ident);
	}/**/
	return result;
}
#endif // TABLE_H
