// BinTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BinaryTree.h"

int _tmain(int argc, _TCHAR* argv[])
{
	BinTree root;
	init(root);
	//NON - BST 
	//init(root, 50);
	//NodeTr* p = root;
	//addRight(p, 99);
	//addLeft(p, 5);
	//p = p->left;
	//addRight(p, 12);
	//addLeft(p, 2);
	//p = root->right;
	//addLeft(p, 9);
	//addRight(p, 10);
	//p = p->left;
	//addLeft(p, 56);
	//addRight(p, 40);        

	//preOrder(root);
	//cout << endl;
	//inOrder(root);
	//cout << endl;
	//postOrder(root);

	//BST 1
	/*insBSTWithOutRe(root, 50);
	insBSTWithOutRe(root, 30);
	insBSTWithOutRe(root, 10);
	insBSTWithOutRe(root, 5);
	insBSTWithOutRe(root, 90);
	insBSTWithOutRe(root, 20);
	insBSTWithOutRe(root, 40);
	insBSTWithOutRe(root, 60);
	insBSTWithOutRe(root, 100);
	insBSTWithOutRe(root, 110);
	
	inOrderWithOutRe(root);
	preOrderWithOutRe(root);
	postOrderWithOutRe(root);*/


	//BST 2
	insBSTWithOutRe(root, 50);
	insBSTWithOutRe(root, 30);
	insBSTWithOutRe(root, 60);
	insBSTWithOutRe(root, 25);
	insBSTWithOutRe(root, 35);
	insBSTWithOutRe(root, 20);
	insBSTWithOutRe(root, 26);
	insBSTWithOutRe(root, 33);
	insBSTWithOutRe(root, 37);
	insBSTWithOutRe(root, 18);
	insBSTWithOutRe(root, 55);
	insBSTWithOutRe(root, 70);
	insBSTWithOutRe(root, 58);
	insBSTWithOutRe(root, 65);
	insBSTWithOutRe(root, 34);
	
	deleteNodeTr(root, 30);
	deleteNodeTr(root, 34);
	deleteNodeTr(root, 37);
	inOrderWithOutRe(root);
	if (isBalanced(root))
		cout << "Balanced binary search tree " << endl;
	else
		cout << "Non-balanced binary search tree" << endl;

	return 0;
}

