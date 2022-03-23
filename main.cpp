#include "bst.hpp"

int main( void )
{
	bst<int>*	tree = new bst<int>();
	tree->add_value(5);
	tree->add_value(18);
	tree->add_value(2);
	tree->add_value(9);
	tree->add_value(15);
	tree->add_value(19);
	tree->add_value(17);
	tree->add_value(13);
	tree->inorder_walk();
	delete tree;
}
