#include <stdio.h>

struct nodes {
	char val;
	struct nodes* left;
	struct nodes* right;
};

void init_nodes(void);

int main()
{
	init_nodes();




}

void init_nodes(void)
{
	struct nodes node[7];
	
	node[0].val = 'a';
	node[0].left = &node[1];
	node[0].right = &node[2];
	
	node[1].val = 'b';
	node[1].left = &node[3];
	node[1].right = &node[4];

	node[3].val = 'd';
	node[3].left = NULL;
	node[3].right = NULL;

	node[4].val = 'e';
	node[4].left = NULL;
	node[4].right = NULL;
	
	node[2].val = 'c';
	node[2].left = NULL;
	node[2].right = &node[6];

	node[6].val = 'f';
	node[6].left = NULL;
	node[6].right = NULL;
}




