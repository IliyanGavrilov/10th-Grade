#include <stdio.h>
#include <stdlib.h>

struct tree_node_t
{
	char letter;
	int frequency;
	struct tree_node_t *left;
	struct tree_node_t *right;
};

struct queue_t
{
	int size;
	int maxsize;
	struct tree_node_t** array;
};

void sort(struct queue_t* q, int id)
{
	int min = id;
	int left = 2 * id + 1;
	int right = 2 * id + 2;

	if (left < q->size && q->array[left]->frequency < q->array[min]->frequency)
    {
		min = left;
    }

	if (right < q->size && q->array[right]->frequency < q->array[min]->frequency)
    {
        min = right;
    }

	if (min != id) {
		struct tree_node_t* temp = q->array[min];
        q->array[min] = q->array[id];
        q->array[id] = temp;

		sort(q, min);
	}
}

void push(struct queue_t* q, struct tree_node_t* node)
{
	++q->size;
	int i = q->size - 1;

	while (i && node->frequency < q->array[(i - 1) / 2]->frequency)
    {
		q->array[i] = q->array[(i - 1) / 2];
		i = (i - 1) / 2;
	}

	q->array[i] = node;
}

struct tree_node_t* pop(struct queue_t* q)
{
	struct tree_node_t* temp = q->array[0];
	q->array[0] = q->array[q->size - 1];

	--q->size;
	sort(q, 0);

	return temp;
}

struct tree_node_t* create_huffman(int freq[], char letters[], int size)
{
	struct tree_node_t *left, *right, *newnode;

	struct queue_t* q = (struct queue_t*)malloc(sizeof(struct queue_t));
	q->size = 0;
	q->maxsize = size;
	q->array = (struct tree_node_t**)malloc(q->maxsize * sizeof(struct tree_node_t*));

	for (int i = 0; i < size; ++i)
    {
        struct tree_node_t* temp = (struct tree_node_t*)malloc(sizeof(struct tree_node_t));

        temp->left = temp->right = NULL;
        temp->letter = letters[i];
        temp->frequency = freq[i];

        q->array[i] = temp;
    }

	q->size = size;

	int n = q->size - 1;
	int i;

	for (i = (n - 1) / 2; i >= 0; --i)
    {
        sort(q, i);
    }

	while (q->size != 1)
    {

		left = pop(q);
		right = pop(q);

		struct tree_node_t* temp = (struct tree_node_t*)malloc(sizeof(struct tree_node_t));

        temp->left = temp->right = NULL;
        temp->letter = '#';
        temp->frequency = left->frequency + right->frequency;

        newnode = temp;

		newnode->left = left;
		newnode->right = right;

		push(q, newnode);
	}

	struct tree_node_t* root = pop(q);

	return root;
}

void print_tree(struct tree_node_t *root, int level)
{
    if(root == NULL)
    {
        return;
    }

    print_tree(root->left, level + 1);

    int i = 0;
    for(; i<level*4; i++)
        printf(" ");
    printf("%c %d\n", root->letter, root->frequency);

    print_tree(root->right, level + 1);

}

void print_codes(struct tree_node_t* root, int arr[], int level)
{
	if (root->left != NULL)
    {
		arr[level] = 0;
		print_codes(root->left, arr, level + 1);
	}

	if (root->right != NULL)
    {
		arr[level] = 1;
		print_codes(root->right, arr, level + 1);
	}

	if (root->left == NULL && root->right == NULL)
    {
        printf("letter:%c frequency:%d code:", root->letter, root->frequency);

        int i;
        for (i = 0; i < level; ++i)
        {
            printf("%d", arr[i]);
        }

        printf("\n");
	}
}

int main()
{

	int freq[] = {2,4,6,7,8,10,11};
    char letters[] = {'v','g','d','a','c','o','b'};

    struct tree_node_t *root = create_huffman(freq, letters, 7);

    int bits[100];
    print_codes(root, bits, 0);

    printf("\nTree (sideways):\n");
    print_tree(root,0);

	return 0;
}
