//Write a program to generate n random unrepeated integer numbers with values 
//less than 100. Sort these nuumbers using heap sort algorithm. 
// Print the numbers after sorting.

void build_heap_tree(int * , int);
void fill_random_numbers(int * , int , int );
void print_array(int * , int  );
void heapify_node(int*,int,int);
void heap_sort(int* , int);
void main(void)
{
	int *arr , n ;	
//	cout<< "Enter value of n: ";
//	cin >> n ;
	n = 10;
	arr = new int[n];
	fill_random_numbers(arr,n,100);
	print_array(arr , n);
	heap_sort(arr , n);
	print_array(arr , n);
	getch();
}

void fill_random_numbers(int *ptr , int size , int max)
{
//	srand(time(NULL));
	srand(2);
	int k , *repeated , counter , temp;
	repeated = new int[max+1];
	for(k = 0 ; k <= max ; k++)		repeated[k] = 0;

	counter = 0;
	while(counter < size)
	{
		temp = rand() % (max+1);
		if(repeated[temp] < 1)			
			{ ptr[counter] = temp ;  counter++; 	repeated[temp]++;}
	}
}


void print_array(int *arr , int size)
{
	for(int k = 0 ; k < size ; k++)			cout << arr[k] << "\t" ;
	cout << "\n";
}

void heap_sort(int *arr , int size)
{
	int k , temp;
	build_heap_tree(arr,size);
	cout << "Heap tree: ";
	print_array(arr,size);
	cout << "\n";
	for(k = size -1 ; k > 0 ; k--)
	{
		temp = arr[0] ; arr[0] = arr[k] ; arr[k] = temp ;
		heapify_node(arr , 0 , k);
		print_array(arr,size);
		cout << "\n";
	}
}

void build_heap_tree(int *arr , int size)
{
	int k;
	for(k = size / 2 -1 ; k >= 0 ; k--)		heapify_node(arr , k , size);
}

void heapify_node(int *arr , int n , int size)
{
	int temp;
	if(n*2+1 >= size)			return;
	if((n*2+2 >= size) && (n*2+1 < size))
	{
		if(arr[n] < arr[n*2+1])		{temp = arr[n] ; arr[n] = arr[n*2+1] ; arr[n*2+1] = temp; }
		return;
	}
	else	if((arr[n] >= arr[n*2+1]) && (arr[n] >= arr[n*2 + 2]))			return;
	else if(arr[n*2+1] > arr[n*2+2])	
	{ 
		temp = arr[n] ; arr[n] = arr[n*2+1] ; arr[n*2+1] = temp; 
		if(n*2+1 < size/2)	heapify_node(arr, n*2+1,size);
	}
	else 
	{ 
		temp = arr[n] ; arr[n] = arr[n*2+2] ; arr[n*2+2] = temp; 
		if(n*2+2 < size/2)	heapify_node(arr, n*2+2,size);
	}
}
