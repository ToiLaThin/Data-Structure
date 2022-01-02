#include<iostream>
#include<algorithm>
#include "Stack.h"
using namespace std;

struct NodeTr{
	int info;
	NodeTr* left;
	NodeTr* right;
}; typedef struct NodeTr* BinTree;

//init the ancestor NodeTr in a BinTree
void init(BinTree &bTr)
{
	bTr = NULL;
}

//pointer must still must have "&" to keep the change outside the function
//init a NodeTr in a BinTree
void init(NodeTr* &p, int x)
{
	p = new NodeTr();
	p->info = x;
	p->left = NULL;
	p->right = NULL;
}

void addLeft(BinTree &root, int x)
{
	if (root != NULL)
	{
		NodeTr* p;
		init(p, x);
		root->left = p;
	}
}

void addRight(BinTree &root, int x)
{
	if (root != NULL)
	{
		NodeTr* p;
		init(p, x);
		root->right = p;
	}
}

void preOrder(BinTree root)
{
	if (root == NULL)
		return;
	cout << root->info << endl;
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(BinTree root)
{
	if (root == NULL)
		return;
	inOrder(root->left);
	cout << root->info << endl;
	inOrder(root->right);
}

//non-tail Recursion nen O() tang
void postOrder(BinTree root)
{
	if (root == NULL)
		return;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->info << endl;
}

bool insBinSearchTree(BinTree &root, int x)
{
	if (root == NULL)//root la left hoac right cua 1 nut la
	{
		NodeTr* p; init(p, x);
		root = p;
		return true;
	}
	else if (x == root->info)
		return false;
	else if (x < root->info)
		insBinSearchTree(root->left, x);
	else if (x > root->info)
		insBinSearchTree(root->right, x);
}
//O(v)
void preOrderWithOutRe(BinTree root)
{
	Stack<NodeTr*, 100> st= Stack<NodeTr*,100>();
	st.push(root);
	while (!st.isEmpty())
	{
		NodeTr* p = st.peek();
		cout << p->info << " ";
		st.pop();
		if (p->right)
			st.push(p->right);
		if (p->left)
			st.push(p->left);
	}
	st.~Stack();
	cout << endl;
}

void inOrderWithOutRe(BinTree root)
{
	Stack<NodeTr*, 100> st = Stack<NodeTr*, 100>();
	NodeTr* p = root;
	while (!st.isEmpty() || p)//dk p de khi p=p->right !=NULL nhung chua kip push vo stack(st.isEmpty nhung van co 1 phan tu chua push vao)
	{
		while (p){//dam sau xuong nhanh con trai
			st.push(p);
			p = p->left;
		}

		p = st.peek();
		cout << p->info << " ";
		st.pop();

		//di 1 nut con phai cua st.peek()
		//neu khac NULL thi tiep tuc dam nhanh con trai
		//neu la NULL thi bo qua vong while de pop()
		if (p->right)
			p = p->right;
		else
			p = NULL; 
	} 


	st.~Stack();
	cout << endl;
}

void postOrderWithOutRe(BinTree root)
{/* Use 2 Stack
	if (root == NULL)
		return;

	Stack<NodeTr*, 100> stPro = Stack<NodeTr*, 100>(); stPro.push(root);
	Stack<NodeTr*, 100> stOut = Stack<NodeTr*, 100>();
	while (!stPro.isEmpty())
	{
		NodeTr* p = stPro.peek();
		stOut.push(p);
		stPro.pop();

		if (p->left)
			stPro.push(p->left);
		if (p->right)
			stPro.push(p->right);
	}


	while (!stOut.isEmpty())
	{
		cout << stOut.peek()->info << " ";
		stOut.pop();
	}
	cout << endl;*/

	/*Use 1 Stack*/
	//C1
	//if (root == NULL)
	//	return;

	//Stack<NodeTr*, 100> st = Stack<NodeTr*, 100>();
	//NodeTr* prePrt = NULL;//node da duoc duyet truoc do
	//NodeTr* p = root;

	//while (p != NULL || !st.isEmpty())
	//{
	//	while (p!=NULL){//chay ve cay con trai toi khi null
	//		st.push(p);
	//		p = p->left;
	//	}

	//	p = st.peek();
	//	if (p->right == NULL || p->right == prePrt){//ktr NEU nut hien tai la nut la hoac nut co cay con phai DA DUOC DUYET thi DUYET nut hien tai
	//		cout << p->info << " ";
	//		prePrt = p;//chinh node prePrt cho lan duyet ke tiep
	//		st.pop();
	//		p = NULL;//de bo qua vong while dau tien;tranh vong lap vo tan
	//	}
	//	else//cay con phai cua nut hien tai chua duoc duyet
	//		p = p->right;
	//}

	//C2
		// Check for empty tree 
		if (root == NULL)
			return;

		Stack<NodeTr*, 100> st = Stack<NodeTr*, 100>();
		NodeTr* p = root;
		while (p != NULL || !st.isEmpty())
		{
			// Move to leftmost node 
			while (p!=NULL){
				// Push root's right child and then root to stack. 
				if (p->right != NULL)
					st.push(p->right);
				st.push(p);
				// Set root as root's left child   
				p = p->left;
			}

			// Pop an item from stack and set it as root     
			p = st.pop();

			// If the popped item has a right child and the right child is not 
			// processed yet, then make sure right child is processed before root 
			if (p->right!=NULL && st.peek() == p->right){
				st.pop();  // remove right child from stack 
				st.push(p);  // push root back to stack 
				p = p->right; // change root so that the right child is processed next 
			}
			else  // Else print root's data and set root as NULL 
			{
				cout << p->info << " ";
				p = NULL;
			}
		}
		cout << endl;
}

//O(h)
void insBSTWithOutRe(BinTree &root, int x)
{
	NodeTr* pre = NULL; NodeTr* curr = root;
	NodeTr* ins; init(ins, x);//nut can chen co gia tri la x
	if (root == NULL)
		root = ins;
	else{
		while (curr)
		{
			pre = curr;
			if (ins->info < pre->info)
				curr = curr->left;
			else if (ins->info > pre->info)
				curr = curr->right;
		}
		//neu curr co pre là lá thì chen ins tai vi tri curr *** luu y neu curr=ins thi khong duoc vi luc nay curr==NULL
		if (ins->info < pre->info)
			pre->left = ins;
		else if (ins->info > pre->info)
			pre->right = ins;

	}
}

//ham xoa 1 nut leaf nam(khong tim kiem da chac chan nut hien tai la leaf)
void deleteNodeTrLeaf(BinTree &root)
{
	if (root == NULL)
		return;
	delete root;
	root = NULL;
}
//ham xoa 1 nut parent co 1 child (left hoac right)
void deleteNodeTrOneChild(BinTree &root)
{
	NodeTr* delNodeTr = root;
	if (root->left && !root->right)//NEU CHI CO CAY CON TRAI
		root = root->left;//ĐẨY CÂY CON LEN VI TRI HIEN TAI **CO CAP NHAT LUON VI TRI TRUOC VI TRI HIEN TAI(vi tham chieu)???**
	else if (!root->left && root->right)//NEU CHI CO CAY CON PHAI
		root = root->right;
	//DON DEP NODE CU
	delete delNodeTr;
	delNodeTr = NULL;
}
//ham xoa 1 nut tong quat(chua ca hai ham delete truoc)
void deleteNodeTr(BinTree &root, int x)
{
	if (root == NULL)
		return;
	if (x == root->info)//TIM THAY
	{
		if (!root->right &&!root->left)
			deleteNodeTrLeaf(root);
		else if (root->right && root->left)
		{
			//TIM NODE CON NHO NHAT BEN PHAI
			NodeTr* temp = root->right; NodeTr* preTemp = root;//preTemp de luu lai Node truoc cua temp(1 node leaf)
			while (temp->left != NULL)
			{
				preTemp = temp;
				temp = temp->left;
			}

			//DOI DATA 
			root->info = temp->info;

			//XOA NUT LEAF LA TEMP VA CAP NHAT PRETEMP -> LEFT(CO TH DAC BIET LA RIGHT)
			if (temp->right==NULL)
			{
				if (preTemp == root)//NEU CAY CON PHAI CUA NUT CAN XOA CHI CO 1 LEAF THI XOA BEN PHAI
					preTemp->right = NULL;
				else
					preTemp->left = NULL;
				deleteNodeTrLeaf(temp);//neu chi cho temp=NULL/deleteNodeTrLeaf(temp) thi node truoc do khong duoc cap nhat => BUGS/INFINITE LOOP
			}
			else if (temp->right!=NULL)
			{
				if (preTemp != root)
				{
					preTemp->left = temp->right;
					deleteNodeTrLeaf(temp);
				}
				else
				{
					preTemp->right = temp->right;
					deleteNodeTrLeaf(temp);
				}
			}
		}
		else
			deleteNodeTrOneChild(root);
	}
	else if (x < root->info)
		deleteNodeTr(root->left, x);
	else if (x > root->info)
		deleteNodeTr(root->right, x);
}

//Time Complexity: O(n)
int getHeight(BinTree root)
{
	if (root == NULL)
		return 0;
	int leftHeight = getHeight(root->left);
	int rightHeight = getHeight(root->right);
	return (1 + max(leftHeight, rightHeight));
}

//Time Complexity: O(n)
bool isBalanced(BinTree root)
{
	if (root == NULL)
		return true;
	int heightDiff = abs(getHeight(root->right) - getHeight(root->left));
	if (heightDiff > 1)
		return false;
	else
		return isBalanced(root->left) && isBalanced(root->right);
}