#define dim 7
#define inf 99

int weight[dim][dim] =   { { 0, 1, inf, inf, inf, 2, inf },
			{ 1, 0, 8, inf, inf, inf, inf },
			{ inf, 8, 0, 4, inf, 3, inf },
			{ inf, inf, 4, 0, 6, inf, inf },
			{ inf, inf, inf, 6, 0, 5, inf },
			{ 2, inf, 3, inf, 5, 0, 2 },
			{ inf, inf, inf, inf, inf, 2, 0 } };

int main(void)
{
	int z[dim][3], source, des, r, min, rmin;

	for (r = 0; r < dim; r++)
	{
		z[r][0] = -1;  z[r][1] = inf;  z[r][2] = 0;
	}

	cout << "Enter source  ";
	cin >> source;

	cout << "Enter destination  ";
	cin >> des;

	rmin = source;
	min = weight[rmin][rmin];
	z[source][0] = source; z[source][1] = 0;	z[source][2] = 1;

	do{
		for (r = 0; r < dim; r++)
		{
			if ((z[r][2] == 0) &&
				(z[r][1] > (weight[rmin][r] + min)))
			{
				z[r][1] = weight[rmin][r] + min;
				z[r][0] = rmin;
			}
		}

		min = inf;  rmin = -1;
		for (r = 0; r < dim; r++)
			if ((z[r][2] == 0) && (z[r][1] < min))
			{
				min = z[r][1]; rmin = r;
			}

		for (r = 0; r < dim; r++)
			cout << "\t" << r << "\t" << z[r][0] << "\t" << z[r][1] << "\t" << z[r][2] << "\n";
		cout << "rmin= " << rmin << "\t min = " << min << "\n\n";

		z[rmin][2] = 1;


	} while (rmin != des);

	cout << "\n Final Result ";
	r = des;
	cout << "\t" << r;
	while (r != source)
	{
		r = z[r][0];
		cout << "\t" << r;
	}
	cout << "\n";
}
