#inlcude<>



struct node *findSmallestele(struct node *tree)
{
	if(tree==NULL||(tree->left==NULL))
		return tree;
	else
		return findSmallestele(tree->left);
}

struct node *findLargestele(struct node *tree)
{
	if(tree==NULL||(tree->right==NULL))
		return tree;
	else
		return findLargestele(tree->right);
} 

void preorderTraversal(struct node *tree)
{
	if(tree!=NULL)
	{
		printf("%d\t",tree->data);
		preorderTraversal(tree->left);
		preorderTraversal(tree->right);
	}
}

void inorderTraversal(struct node *tree)
{
	if(tree!=NULL)
	{
		inorderTraversal(tree->left);
		printf("%d\t",tree->data);
		inorderTraversal(tree->right);
	}
}

void postorderTraversal(struct node *tree)
{
	if(tree!=NULL)
	{
		postorderTraversal(tree->left);
		postorderTraversal(tree->right);
		printf("%d\t",tree->data);
	}
}

int totalNodes(struct node *tree)
{
	if(tree==NULL)
		return 0;
	else
		return(totalNodes(tree->left)+totalNodes(tree->right)+1);
}

int totalExternalNodes(struct node *tree)
{
	if(tree==NULL)
		return 0;
	else if
			return 1;
		else
			return(totalExternalNodes(tree->left)+totalExternalNodes(tree->right));
}

int totalInternalNodes(struct node *tree)
{
	if(tree==NULL||(tree->left==NULL&&(tree->right==NULL)))
		return 0;
	else
		return (totalInternalNodes(tree->left)+totalInternalNodes(tree->right)+1);
}


