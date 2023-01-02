struct binary_node
{
	int data;
	binary_node *left, *right;
};

class binary_search_tree
{
private:
	binary_node *root;
	binary_node* make_new_node(int dd);
	void rec_insertion(binary_node *ptr, int dd);
	void rec_pre_order(binary_node *ptr);
	void rec_in_order(binary_node *ptr);
	void rec_post_order(binary_node *ptr);
	bool rec_search(binary_node *ptr , int dd);
	bool rec_delete_data(binary_node **ptr , int dd);
public:
	binary_search_tree()  { root = NULL; }
	void insert_data(int dd);
	bool search_data(int dd);
	bool remove_data(int dd);
	void print_pre_order(void);
	void print_in_order(void);
	void print_post_order(void);
};

	binary_node*  binary_search_tree::make_new_node(int dd)
	{
		binary_node *temp = new binary_node;
		temp->data = dd;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}

void binary_search_tree::insert_data(int dd)
{
	if(root == NULL)		root = make_new_node(dd);
	else							rec_insertion(root,dd);
}
void binary_search_tree::rec_insertion(binary_node *ptr , int dd)
{
	if(dd < ptr->data)
	{
		if(ptr->left == NULL)		ptr->left = make_new_node(dd);
		else								rec_insertion(ptr->left , dd);
	}
	else if(dd > ptr->data)
	{
		if(ptr->right == NULL)	ptr->right = make_new_node(dd);
		else								rec_insertion(ptr->right , dd);
	}
}

void binary_search_tree::print_pre_order(void)
{
	if(root == NULL)	cout << "Empty tree, pre order print will be canceled \n";
	else
	{
		cout << "Nodes by Pre order:\t";
		rec_pre_order(root);
		cout << "\n";
	}
}

void binary_search_tree::print_in_order(void)
{
	if(root == NULL)	cout << "Empty tree, pre order print will be canceled \n";
	else
	{
		cout << "Nodes by in order:\t";
		rec_in_order(root);
		cout << "\n";
	}
}
void binary_search_tree::print_post_order(void)
{
	if(root == NULL)	cout << "Empty tree, pre order print will be canceled \n";
	else
	{
		cout << "Nodes by post order:\t";
		rec_post_order(root);
		cout << "\n";
	}
}

void binary_search_tree::rec_pre_order(binary_node *ptr)
{
	if(ptr == NULL)		return;
	cout << ptr->data << "\t";
	rec_pre_order(ptr->left);
	rec_pre_order(ptr->right);
}

void binary_search_tree::rec_in_order(binary_node *ptr)
{
	if(ptr == NULL)		return;
	rec_in_order(ptr->left);
	cout << ptr->data << "\t";
	rec_in_order(ptr->right);
}

void binary_search_tree::rec_post_order(binary_node *ptr)
{
	if(ptr == NULL)		return;
	rec_post_order(ptr->left);
	rec_post_order(ptr->right);
	cout << ptr->data << "\t";
}

bool binary_search_tree::search_data(int dd)
{
	if(root == NULL)	
	{ cout << "You can not search for " << dd << " in an empty tree\n";  return false; }
	else  return rec_search(root , dd);
}

bool binary_search_tree::rec_search(binary_node *ptr , int dd)
{
	if(ptr == NULL)	
	{ cout << dd << "could not be found \n";  return false;  }
	else if(ptr-> data == dd)	
	{   cout << " We find " << dd << " in the tree\n";		return true; }
	else if(ptr->data < dd)		return rec_search(ptr->right , dd);
	else if(ptr->data > dd)		return rec_search(ptr->left , dd);
}

bool binary_search_tree::remove_data(int dd)
{
	if(root == NULL)	
	{  cout << "You can not delete from an empty tree\n";  return false; }
	else  return rec_delete_data(&root , dd);
}

bool binary_search_tree:: rec_delete_data(binary_node **pt, int key)
{
	if (*pt == NULL)		{ cout << "The number " << key << " could not be deleted\n"; return false; }

	if ((*pt)->data > key)				return rec_delete_data(&((*pt)->left), key);
	else	if ((*pt)->data < key)		return rec_delete_data(&((*pt)->right), key);
	else if ((*pt)->data == key)
	{
		if ((*pt)->left == NULL)		*pt = (*pt)->right;
		else if ((*pt)->right == NULL)		*pt = (*pt)->left;
		else if((*pt)->left->right == NULL)	{(*pt)->left->right = (*pt)->right ;	*pt = (*pt)->left ; }  
		else if((*pt)->right->left == NULL)	{(*pt)->right->left = (*pt)->left ;		*pt = (*pt)->right ; }
		else
		{
			binary_node *temp;
			temp = *pt;
			temp = temp->left;
			while (temp->right->right != NULL)
				temp = temp->right;
			(*pt)->data = temp->right->data;
			temp->right = temp->right->left;
		}
		cout << "\nNumber " << key << " will be replaced in the tree by number " << (*pt)->data << "\n";
		return true;
	}
}

void main(void)
{
	binary_search_tree bst;
	bst.insert_data(5);
	bst.insert_data(1);
	bst.insert_data(2);
	bst.insert_data(8);
	bst.insert_data(5);
	bst.insert_data(7);
	bst.insert_data(8);
	bst.insert_data(6);
	bst.insert_data(4);
	bst.insert_data(3);
	bst.print_pre_order();
	bst.print_in_order();
	bst.print_post_order();

	bst.remove_data(1);

	bst.print_pre_order();
	bst.print_in_order();
	bst.print_post_order();

	if(bst.search_data(5) == true)		cout << "5 mawguda \n";
	else												cout << "5 mesh mawguda \n";
	bst.search_data(3);
	bst.search_data(7);
	bst.search_data(1);
	cout << "Every thing is ok \n";
}

