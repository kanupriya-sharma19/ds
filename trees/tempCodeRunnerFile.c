#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *tree = NULL;

void create_tree(struct node *);
struct node *insertElement(struct node *, int);
void preorderTraversal(struct node *);
void inorderTraversal(struct node *);
void postorderTraversal(struct node *);

struct node *deleteElement(struct node *, int);


int main() {
    int option, val;
    struct node *ptr;
    create_tree(tree);

    do {
        printf("\n ******MAIN MENU******* \n");
        printf("\n 1. Insert Element");
        printf("\n 2. Preorder Traversal");
        printf("\n 3. Inorder Traversal");
        printf("\n 4. Postorder Traversal");
        printf("\n 5. Delete an element");
       
        printf("\n 6. Exit");
        printf("\n\n Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\n Enter the value of the new node: ");
                scanf("%d", &val);
                tree = insertElement(tree, val);
                break;
            case 2:
                printf("\n The elements of the tree are: \n");
                preorderTraversal(tree);
                break;
            case 3:
                printf("\n The elements of the tree are: \n");
                inorderTraversal(tree);
                break;
            case 4:
                printf("\n The elements of the tree are: \n");
                postorderTraversal(tree);
                break;
           
            case 5:
                printf("\n Enter the element to be deleted: ");
                scanf("%d", &val);
                tree = deleteElement(tree, val);
                break;
            
        }
    } while (option != 6);

    return 0;
}

void create_tree(struct node *tree) {
    tree = NULL;
}

struct node *insertElement(struct node *tree, int val) {
    struct node *ptr, *nodeptr, *parentptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;

    if (tree == NULL) {
        tree = ptr;
    } else {
        parentptr = NULL;
        nodeptr = tree;
        while (nodeptr != NULL) {
            parentptr = nodeptr;
            if (val < nodeptr->data)
                nodeptr = nodeptr->left;
            else if(val >nodeptr->data)
                nodeptr = nodeptr->right;
                else {printf("Already data exists %d",val);
                return tree;}

        }
        if (val < parentptr->data)
            parentptr->left = ptr;
        else
            parentptr->right = ptr;
    }
    return tree;
}

void preorderTraversal(struct node *tree) {
    if (tree != NULL) {
        printf("%d\t", tree->data);
        preorderTraversal(tree->left);
        preorderTraversal(tree->right);
    }
}

void inorderTraversal(struct node *tree) {
    if (tree != NULL) {
        inorderTraversal(tree->left);
        printf("%d\t", tree->data);
        inorderTraversal(tree->right);
    }
}

void postorderTraversal(struct node *tree) {
    if (tree != NULL) {
        postorderTraversal(tree->left);
        postorderTraversal(tree->right);
        printf("%d\t", tree->data);
    }
}

struct node *inOrderPredecessor(struct node* tree){
    tree = tree->left;
    while (tree->right!=NULL)
    {
        tree = tree->right;
    }
    return tree;
}

struct node *deleteElement(struct node *tree, int value){

    struct node* iPre;
    if (tree == NULL){
        return NULL;
    }
    if (tree->left==NULL&&tree->right==NULL){
        free(tree);
        return NULL;
    }

    //searching for the node to be deleted
    if (value < tree->data){
        tree-> left = deleteElement(tree->left,value);
    }
    else if (value > tree->data){
        tree-> right = deleteElement(tree->right,value);
    }
    //deletion strategy when the node is found
    else{
 if (tree->left == NULL) {
            struct node* temp = tree->right;
            free(tree);
            return temp;
        } else if (tree->right == NULL) {
            struct node* temp = tree->left;
            free(tree);
            return temp;
        }

        iPre = inOrderPredecessor(tree);
        tree->data = iPre->data;
        tree->left = deleteElement(tree->left, iPre->data);
    }
    return tree;
}
 