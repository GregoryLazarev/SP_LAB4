#include <string>
#include "List.h"

int main(int argc, char *argv[])
{
	int n = *argv[1];
	char *str = argv[0];
	List *trigrams = new List();
	int c = 0;
	char tr[3];

	for (int i = 0; i < n; i++)
	{
		if (str[i] != ' ')
		{
			if (c < 3)
				tr[c] = str[i];
			c++;
			if (i == n - 1 && c == 3)
				trigrams->check(tr);
		}
		else
		{
			if (c == 3)
				trigrams->check(tr);
			c = 0;
		}
	}
	trigrams->Print();
	printf("\n");

	exit(0);
}

