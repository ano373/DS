#define dim 7
#define inf 99

int weight[dim][dim] = { { 0, 1, inf, inf, inf, 2, 9 },
		{ 1, 0, 8, inf, inf, inf, inf },
		{ inf, 8, 0, 4, inf, 3, inf },
		{ inf, inf, 4, 0, 2, inf, inf },
		{ inf, inf, inf, 2, 0, 1, inf },
		{ 2, inf, 3, inf, 1, 0, 2 },
		{ 9, inf, inf, inf, inf, 2, 0 } };

int main(void)
{
	int r, c, x, flag;
	for (r = 0; r < dim; r++)
	{
		for (c = 0; c < dim; c++)
			if (weight[r][c] == inf)		cout << "#\t";
			else								cout << weight[r][c] << "\t";
		cout << "\n";
	}

	do{
		flag = 0;
		for (int src = 0; src < dim; src++)
			for (int dest = 0; dest < dim; dest++)
				for (int via = 0; via < dim; via++)
					if (weight[src][dest] > weight[src][via] + weight[via][dest])
					{
						weight[src][dest] = weight[src][via] + weight[via][dest];
						flag++;
					}
		cout << "\n Flag = " << flag << endl;
		for (r = 0; r < dim; r++)
		{
			for (c = 0; c < dim; c++)
				cout << weight[r][c] << "\t";
			cout << "\n";
		}
		cout << "\n";
	} while (flag > 0);
	getch();
}
