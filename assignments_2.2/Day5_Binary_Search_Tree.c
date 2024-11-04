#include <stdio.h>
#include <stdlib.h>

struct Binary_Search_Tree;
typedef struct Node
{
	int data;
	struct Binary_Search_Tree *leftChild, *rightChild;
} Node;

// wrapper around root node
typedef struct Binary_Search_Tree
{
	Node *root;
} Binary_Search_Tree;

// checks if a tree is empty (ie its root is NULL)
int empty(Binary_Search_Tree const *const _tree) { return _tree->root == NULL; }
// checks if a non empty tree is a leaf or not
int leaf(Binary_Search_Tree const *const _tree)
{
	if (empty(_tree))
		return 0;
	return empty(_tree->root->leftChild) && empty(_tree->root->rightChild);
}

// allocates memory for an empty tree
Binary_Search_Tree *create_tree(void)
{
	Binary_Search_Tree *tree =
		(Binary_Search_Tree *)malloc(sizeof(Binary_Search_Tree));
	tree->root = NULL;

	return tree;
}

// leaves the argument as an empty tree
void delete_tree(Binary_Search_Tree *const _tree)
{
	if (empty(_tree))
		return;

	delete_tree(_tree->root->leftChild);  // first make the left child empty
	delete_tree(_tree->root->rightChild); // then make the right child empty

	// now that children are empty we can free its children and its root and mark
	// it as empty
	free(_tree->root->leftChild);
	free(_tree->root->rightChild);
	free(_tree->root);
	_tree->root = NULL; // mark this tree as empty
}

// allocates memory for a new node with a brand new id and two empty subtrees
Node *create_node(int const _data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = _data;
	newNode->leftChild = create_tree();
	newNode->rightChild = create_tree();

	return newNode;
}

unsigned maximum(unsigned const _a, unsigned const _b)
{
	return _a > _b ? _a : _b;
}
unsigned number_of_levels(Binary_Search_Tree const *const _tree)
{
	if (empty(_tree))
		return 0;
	if (leaf(_tree))
		return 1;
	return 1 + maximum(number_of_levels(_tree->root->leftChild),
					   number_of_levels(_tree->root->rightChild));
}
int balance_factor(Binary_Search_Tree const *const _tree)
{
	if (empty(_tree) || leaf(_tree))
		return 0;

	// these have to be integer ( so that their difference can be negative )
	int heightOfLeftChild = number_of_levels(_tree->root->leftChild);
	int heightOfRightChild = number_of_levels(_tree->root->rightChild);

	return heightOfLeftChild - heightOfRightChild;
}

int height_balanced(Binary_Search_Tree const *const _tree)
{
	if (empty(_tree))
		return 1;
	return abs(balance_factor(_tree)) < 2 && height_balanced(_tree->root->leftChild) && height_balanced(_tree->root->rightChild);
}

void print_balance_factors(Binary_Search_Tree const *const _tree)
{
	if (empty(_tree))
		return;

	// inorder print
	print_balance_factors(_tree->root->leftChild);
	printf("Node data %d, balance factor = %d\n", _tree->root->data,
		   balance_factor(_tree));
	print_balance_factors(_tree->root->rightChild);
}
void LL_rotate(Binary_Search_Tree *const _tree)
{
	if (balance_factor(_tree) >= 1 && balance_factor(_tree->root->leftChild) >= 0)
	{
		Node *pivot = _tree->root;
		Node *leftChildOfPivot = pivot->leftChild->root;
		Node *rightChildOfLeftChildOfPivot = leftChildOfPivot->rightChild->root;

		_tree->root = leftChildOfPivot;
		_tree->root->rightChild->root = pivot;
		_tree->root->rightChild->root->leftChild->root = rightChildOfLeftChildOfPivot;
	}
}

void RR_rotate(Binary_Search_Tree *const _tree)
{
	if (balance_factor(_tree) <= -1 && balance_factor(_tree->root->rightChild) <= 0)
	{
		Node *pivot = _tree->root;
		Node *rightChildOfPivot = pivot->rightChild->root;
		Node *leftChildOfRightChildOfPivot = rightChildOfPivot->leftChild->root;

		_tree->root = rightChildOfPivot;
		_tree->root->leftChild->root = pivot;
		_tree->root->leftChild->root->rightChild->root = leftChildOfRightChildOfPivot;
	}
}

void LR_rotate(Binary_Search_Tree *const _tree)
{
	if (balance_factor(_tree) >= 1 && balance_factor(_tree->root->leftChild) <= 0)
	{
		RR_rotate(_tree->root->leftChild);
		LL_rotate(_tree);
	}
}
void RL_rotate(Binary_Search_Tree *const _tree)
{
	if (balance_factor(_tree) <= -1 && balance_factor(_tree->root->leftChild) >= 0)
	{
		LL_rotate(_tree->root->rightChild);
		RR_rotate(_tree);
	}
}
void insert_element(Binary_Search_Tree *const _tree, int const _data,
					unsigned const _level)
{
	// try to insert in this level
	if (empty(_tree))
	{
		_tree->root = create_node(_data);
		// printf("Insertion done at level %d\n", _level);
		return;
	}

	if (_data < _tree->root->data)
	{
		insert_element(_tree->root->leftChild, _data, _level + 1);
		LL_rotate(_tree);
		LR_rotate(_tree);
	}
	else
	{
		insert_element(_tree->root->rightChild, _data, _level + 1);
		RR_rotate(_tree);
		RL_rotate(_tree);
	}
}

int remove_element(Binary_Search_Tree *const _tree, int const _data,
				   unsigned const _level)
{
	if (empty(_tree))
		return 0;
	if (_data == _tree->root->data)
	{
		if (leaf(_tree))
		{
			printf("Deleting Node data %d at level %d\n", _tree->root->data, _level);
			// make this tree empty
			delete_tree(_tree);
			return 1;
		}
		if (empty(_tree->root->leftChild))
		{
			// free the left child tree wrapper
			free(_tree->root->leftChild);
			// save right child's root address in a variable
			Node *rightChildRoot = _tree->root->rightChild->root;
			// free right child tree wrapper
			free(_tree->root->rightChild);
			// free this tree's root node (actual deletion)
			printf("Deleting Node data %d at level %d\n", _tree->root->data, _level);
			free(_tree->root);
			// copy the right child's root address to this tree's root
			_tree->root = rightChildRoot;
			return 1;
		}
		if (empty(_tree->root->rightChild))
		{
			// free the right child tree wrapper
			free(_tree->root->rightChild);
			// save left child's root address in a variable
			Node *leftChildRoot = _tree->root->leftChild->root;
			// free left child tree wrapper
			free(_tree->root->leftChild);
			// free this tree's root node (actual deletion)
			printf("Deleting Node data %d at level %d\n", _tree->root->data, _level);
			free(_tree->root);
			// copy the left child's root address to this tree's root
			_tree->root = leftChildRoot;
			return 1;
		}
		// if none of left and right child are empty then codeflow comes here
		// we can copy a node's data to this tree root's data if
		// that node satisfies the binary tree condition
		// such node is found in the left subtrees of the right subtree of this tree
		Node *nodeToCopyFrom = _tree->root->rightChild->root;
		while (!empty(nodeToCopyFrom->leftChild))
			nodeToCopyFrom = nodeToCopyFrom->leftChild->root;
		// copy the data
		_tree->root->data = nodeToCopyFrom->data;

		// now delete that original node from where we copied (it is somewhere in
		// the rightchild)
		remove_element(_tree->root->rightChild, nodeToCopyFrom->data, _level + 1);
		return 1;
	}

	if (_data < _tree->root->data)
	{
		int removedFromLeftChild = remove_element(_tree->root->leftChild, _data, _level + 1);
		// we might need an RR/RL rotation after this
		RR_rotate(_tree);
		RL_rotate(_tree);
		return removedFromLeftChild;
	}
	// if deleted from rightchild
	else
	{
		int removedFromRightChild = remove_element(_tree->root->rightChild, _data, _level + 1);
		// we might need an LL/LR rotation after this
		LL_rotate(_tree);
		LR_rotate(_tree);
		return removedFromRightChild;
	}
}

void traverse_in_order(Binary_Search_Tree const *const _tree)
{
	if (empty(_tree))
		return;

	traverse_in_order(_tree->root->leftChild);
	printf("%d ", _tree->root->data);
	traverse_in_order(_tree->root->rightChild);
}

unsigned two_to_the_power_of(unsigned const _exponent)
{
	if (_exponent == 0)
		return 1;
	return 2 * two_to_the_power_of(_exponent - 1);
}
void print_level_order(Binary_Search_Tree const *const _tree,
					   unsigned const _totalNumberOfLevels,
					   unsigned const _allowedDepth, unsigned const _level)
{
	if (empty(_tree) && _level != _allowedDepth)
		return;
	if (_level > _allowedDepth)
		return;
	if (_level == _allowedDepth)
	{
		if (empty(_tree))
		{
			printf(".");
			for (unsigned i = 0;
				 i < two_to_the_power_of(_totalNumberOfLevels - _level) - 1; i++)
				printf(" ");
			return;
		}
		else
		{
			printf("%d", _tree->root->data);
			for (unsigned i = 0;
				 i < two_to_the_power_of(_totalNumberOfLevels - _level) - 1; i++)
				printf(" ");
		}
	}
	print_level_order(_tree->root->leftChild, _totalNumberOfLevels, _allowedDepth,
					  _level + 1);
	print_level_order(_tree->root->rightChild, _totalNumberOfLevels,
					  _allowedDepth, _level + 1);
	return;
}

int main(void)
{
	Binary_Search_Tree *tree = create_tree();

	unsigned choice, nodeID;
	int data;
	do
	{
		printf("\nMenu:\n");
		printf("1. Insert Element\n");
		printf("2. Delete Element\n");
		printf("3. Print Balance Factor\n");
		printf("4. Traverse In Order\n");
		printf("0. Exit\n");

		printf("Enter your choice: ");
		scanf("%u", &choice);
		// printf("\n");

		switch (choice)
		{
		case 1:
			printf("Enter the data to be inserted: ");
			scanf("%d", &data);
			// printf("\n");
			insert_element(tree, data, 0);
			break;
		case 2:
			printf("Enter the data to be deleted: ");
			scanf("%d", &data);
			// printf("\n");
			if (!remove_element(tree, data, 0))
				printf("Deletion Failed.\n");
			break;
		case 3:
			print_balance_factors(tree);
			if (!height_balanced(tree))
				printf("Not ");
			printf("balanced\n");
			break;
		case 4:
			printf("Traversing In Order:\n");
			traverse_in_order(tree);
			break;
		case 0:
			printf("Exiting Program ...\n");
			break;
		default:
			printf("Invalid choice. Please try again.\n");
			break;
		}

		// printing the tree
		printf("Tree:\n");
		for (unsigned allowedDepth = 0; allowedDepth < number_of_levels(tree);
			 allowedDepth++)
		{
			for (unsigned i = 0;
				 i <
				 two_to_the_power_of(number_of_levels(tree) - allowedDepth - 1) - 1;
				 i++)
				printf(" ");
			print_level_order(tree, number_of_levels(tree), allowedDepth, 0);
			printf("\n");
		}

	} while (choice);

	delete_tree(tree);
	return 0;
}