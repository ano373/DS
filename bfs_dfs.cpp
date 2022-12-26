
struct treeNode
{
	char name, father;
	int order;
};

class mystack
{
private:
	char *arr;
	int top , size;
public:
	mystack(int ss)		{	top = 0;		size = ss;		arr = new char[size];  }
	mystack(void)		{	top = 0;		size = 10;		arr = new char[size];	}
	void push(char data)	{  arr[top++] = data;	}
	char pop(void)	{  return arr[--top];  }
	bool is_empty(void)  	{  	return (top == 0);	}
	bool is_full(void)	{  return(top == size);  }
};

class myqueue
{
private:
	char *arr;
	int front, rear, size, counter;
public:
	myqueue(int ss)					//constructor
	{
		front = rear = counter = 0;
		size = ss;
		arr = new char[size];
	}
	myqueue(void)					//constructor
	{
		front = rear = counter = 0;
		size = 10;
		arr = new char[size];
	}
	void enqueue(char data)
	{
		arr[rear] = data;
		rear = (rear + 1) % size ;
		counter++;
	}
	char dequeue(void)
	{
		char temp;
		temp = arr[front];
		front = (front + 1) % size;
		counter--;
		return temp;
	}
	bool is_empty(void)  	{	return(counter == 0); 	}
	bool is_full(void)		{ 	return(counter == size)	;	}
};
/*
void print_DFS(treeNode*, int);
void print_BFS(treeNode*, int);
void main(void)
{
	struct treeNode treeArray[12] = {{'A','M',2},{'B','M',1},{'C','A',1},
	{'D','H',3},	{'F','H',1},{'G','H',2},{'H','M',3},{'K','B',2},{'M','0',0},
	{'P','K',2},{'X','K',1},{'Y','B',1}};
	cout << "DFS: ";
	print_DFS(treeArray,12);

	cout << "\n BFS: ";
	print_BFS(treeArray, 12);
}
*/
void print_DFS(treeNode *ptr, int size)
{
	int k, counter;
	char *sons;
	sons = new char[size];
	mystack st1;
	for(k = 0 ; k < size ; k++)
		if(ptr[k].father == '0')		{	st1.push(ptr[k].name);    break;  }

		char temp;
		while(st1.is_empty() == false)
		{
			temp = st1.pop();
			cout << temp << "\t";
			counter = 0;
			for(k = 0 ; k < size ; k++)
				if(ptr[k].father == temp)		
				{ sons[ptr[k].order] = ptr[k].name; counter++; }

			for(k = counter ; k >= 1 ; k--)
				st1.push(sons[k]);
		}
}

void print_BFS(treeNode *ptr, int size)
{
	int k, counter;
	char *sons;
	sons = new char[size];
	myqueue qu1;
	for(k = 0 ; k < size ; k++)
		if(ptr[k].father == '0')		{	qu1.enqueue(ptr[k].name);    break;  }

		char temp;
		while(qu1.is_empty() == false)
		{
			temp = qu1.dequeue();
			cout << temp << "\t";
			counter = 0;
			for(k = 0 ; k < size ; k++)
				if(ptr[k].father == temp)		
				   { sons[ptr[k].order] = ptr[k].name; counter++; }

			for(k = 1 ; k <= counter ; k++)
				qu1.enqueue(sons[k]);
		}
}
