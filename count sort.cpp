// ******************** Count sort ****************************/
//Write a program to sort 30 students ID according to their grades(A,B,C,D,E,F) 
//using count sort. Generate random data.

#define SIZE 30
struct st
{
	int id;
	char grade ;
};
void main(void)
{
	struct st list[SIZE] , temp[SIZE];
	int k;
	int counters[6] ;
	char ch;
//	srand(time(NULL));
	//Generate random data (serial 30 id start from 1001 and random grade from A to F)
	for(k = 0 ; k < SIZE ; k++)
	{
		list[k].id = k + 1001 ;
		list[k].grade = 'A' + rand() % 6 ;
		cout << k << "\t" << list[k].id << "\t" << list[k].grade << "\n";
	}

	for(k = 0 ; k < 6 ; k++)		counters[k] = 0;

	for(k = 0 ; k < SIZE ; k++)		counters[list[k].grade - 'A']++;

	cout << "\n Counters:\n";
	for(k = 0 ; k < 6 ; k++)
	{
		ch = 'A' + k ;
		cout << k << "\t" << ch << "\t" << counters[k] << "\n";
	}

	cout << "New counters \n" << 0 << "\t" << 'A' << "\t" << counters[0] << "\n";
	for(k = 1 ; k < 6 ; k++)
	{
		ch = 'A' + k ;
		counters[k] = counters[k-1] + counters[k] ;
		cout << k << "\t" << ch << "\t" << counters[k] << "\n";
	}

	for(k = SIZE-1 ; k >= 0 ; k--)
		temp[--counters[list[k].grade - 'A']] = list[k];

	cout << "Data after sorting according to grade: \n";
	for(k = 0 ; k < SIZE ; k++)
	{
		list[k] = temp[k];
		cout << k << "\t" << list[k].id << "\t" << list[k].grade << "\n";
	}
	getch();
}
