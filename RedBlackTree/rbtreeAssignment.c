
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	char color;
	struct node *parent;
	struct node *left;
	struct node *right;
};

struct node* rightroot(struct node* parent) {
	struct node* root = parent->left;
	struct node* grand = parent->parent;
	struct node* temp = root->right;

	if(grand->data > parent->data) grand->right = root;
	else grand->left = root;

	root->right = parent;
	parent->left = temp;

	temp->parent = parent;
	root->parent = grand;
	parent->parent = root;

	return parent;
}

struct node* leftroot(struct node* parent) {
	struct node* root = parent->right;
	struct node* grand = parent->parent;
	struct node* temp = root->left;

	if(grand->data > parent->data) grand->right = root;
	else grand->left = root;

	root->left = parent;
	parent->right = temp;

	temp->parent = parent;
	root->parent = grand;
	parent->parent = root;

	return parent;
}

struct node* rb_rules(struct node* root) {
	if(root == NULL) return 0;
	
	rb_rules(root->left);
	if(root->parent == NULL) root->color == 'B';
	else if (root->parent->left != NULL && root->parent->right != NULL) {
		if(root->parent->left->color == 'R' && (root->parent->left->left != NULL || root->parent->left->right != NULL) && root->parent->right->color == 'R' && (root->parent->right->left != NULL || root->parent->right->right != NULL)) {
			root->parent->left->color = 'B';
			root->parent->right->color = 'B';
		}
	}
	rb_rules(root->right);

	return root;
}

struct node* new_node(int data, struct node* parent) {
	struct node *temp = (struct node*)malloc(sizeof(struct node));

	temp->data = data;
	temp->color = 'R';

	temp->parent = parent;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

struct node* insert(struct node *root, int data) {
	if(root == NULL) {
		root = new_node(data, NULL);
		root->color = 'B';
		return root;
	}

	if(data < root->data) {
		if(root->left == NULL) {
			root->left = new_node(data, root);
		} else {
			root->left = insert(root->left, data);
		}
	} else if(data > root->data) {
		if(root->right == NULL) {
			root->right = new_node(data, root);
		} else {
			root->right = insert(root->right, data);
		}
	}

	root = rb_rules(root);

	return root;
}

void inorder(struct node *root) {
	if(root == NULL) return;
	inorder(root->left);
	printf("%d(%c) ", root->data, root->color);
	inorder(root->right);
}

struct node * minValueNode(struct node* node) {
	struct node* current = node;

	while (current && current->left != NULL)
		current = current->left;

	return current;
}

struct node* deleteNode(struct node* root, int data) {
	if (root == NULL) return root;

	if (data < root->data) root->left = deleteNode(root->left, data);
	else if (data > root->data) root->right = deleteNode(root->right, data);
	else {
		if (root->left == NULL) {
			struct node *temp = root->right;
			free(root);
			return temp;
		} else if (root->right == NULL) {
			struct node *temp = root->left;
			free(root);
			return temp;
		}
		struct node* temp = minValueNode(root->right);

		root->data = temp->data;
		root->right = deleteNode(root->right, temp->data);
	}
	return root;
}

int main() {
	int choice, choice2, ele;
	struct node* root = NULL;
	while(1) {
		printf("\nENTER YOUR CHOICE:\n1. Insert Element\n2. Display\n3. Delete Node\n4. EXIT\n");
		scanf("%d", &choice);
		switch(choice){
		case 1:
			printf("\nEnter element to insert : ");
			scanf("%d", &ele);
			root = insert(root, ele);
                	break;
            	case 2:
                 	printf("\n\nInorder Traversal : ");
                 	inorder(root);
                 	break;
            	case 3:
                	printf("\nEnter node to delete : ");
                	scanf("%d", &ele);
                	root = deleteNode(root, ele);
                	break;
            	case 4:
                	return 0;

            	default:
                	printf("\nWRONG CHOICE ENTERED\n");
        }

    }
    return 0;
}

