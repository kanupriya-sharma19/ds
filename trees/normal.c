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
struct node *findSmallestElement(struct node *);
struct node *findLargestElement(struct node *);
struct node *deleteElement(struct node *, int);
struct node *deleteNode(struct node *, int);
struct node *mirrorImage(struct node *);
int totalNodes(struct node *);
int totalExternalNodes(struct node *);
int totalInternalNodes(struct node *);
int Height(struct node *);
struct node *deleteTree(struct node *);
struct node * searchIter(struct node* tree, int key);

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
        printf("\n 5. Find the smallest element");
        printf("\n 6. Find the largest element");
        printf("\n 7. Delete an element");
        printf("\n 8. Count the total number of nodes");
        printf("\n 9. Count the total number of external nodes");
        printf("\n 10. Count the total number of internal nodes");
        printf("\n 11. Determine the height of the tree");
        printf("\n 12. Find the mirror image of the tree");
        printf("\n 13. Delete the tree");
         printf("\n 14. Search value ");
        printf("\n 15. Exit");
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
                ptr = findSmallestElement(tree);
                if (ptr != NULL)
                    printf("\n Smallest element is: %d", ptr->data);
                else
                    printf("\n The tree is empty.");
                break;
            case 6:
                ptr = findLargestElement(tree);
                if (ptr != NULL)
                    printf("\n Largest element is: %d", ptr->data);
                else
                    printf("\n The tree is empty.");
                break;
            case 7:
                printf("\n Enter the element to be deleted: ");
                scanf("%d", &val);
                tree = deleteNode(tree, val);
                break;
            case 8:
                printf("\n Total no. of nodes = %d", totalNodes(tree));
                break;
            case 9:
                printf("\n Total no. of external nodes = %d", totalExternalNodes(tree));
                break;
            case 10:
                printf("\n Total no. of internal nodes = %d", totalInternalNodes(tree));
                break;
            case 11:
                printf("\n The height of the tree = %d", Height(tree));
                break;
            case 12:
                tree = mirrorImage(tree);
                break;
            case 13:
                tree = deleteTree(tree);
                printf("\n Tree deleted.");
                break;
              
                 case 14:   printf("\n Enter the element to be searched: ");
                scanf("%d", &val);
                tree=searchIter(tree,val);
                 if(tree!=NULL){
    printf("Found: %d", tree->data);
    }
    else{
        printf("Element not found");
    }
        }
    } while (option != 15);

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

struct node *findSmallestElement(struct node *tree) {
    if (tree == NULL || tree->left == NULL)
        return tree;
    else
        return findSmallestElement(tree->left);
}

struct node * searchIter(struct node* tree, int key){
    while(tree!=NULL){
        if(key == tree->data){
            return tree;
        }
        else if(key<tree->data){
            tree = tree->left;
        }
        else{
            tree = tree->right;
        }
    }
    return NULL;
}

struct node *findLargestElement(struct node *tree) {
    if (tree == NULL || tree->right == NULL)
        return tree;
    else
        return findLargestElement(tree->right);
}

struct node *deleteElement(struct node *tree, int val) {
    // Implementation for deleting an element (you may add your logic here)
    return tree;
}

int totalNodes(struct node *tree) {
    if (tree == NULL)
        return 0;
    else
        return (totalNodes(tree->left) + totalNodes(tree->right) + 1);
}

int totalExternalNodes(struct node *tree) { //leaf
    if (tree == NULL)
        return 0;
    else if (tree->left == NULL && tree->right == NULL)
        return 1;
    else
        return (totalExternalNodes(tree->left) + totalExternalNodes(tree->right));
}

int totalInternalNodes(struct node *tree) {//at least ine child
    if (tree == NULL || (tree->left == NULL && tree->right == NULL))
        return 0;
    else
        return (totalInternalNodes(tree->left) + totalInternalNodes(tree->right) + 1);
}

int Height(struct node *tree) {
    if (tree == NULL)
        return 0;
    else {
        int leftheight = Height(tree->left);
        int rightheight = Height(tree->right);
        return (leftheight > rightheight) ? (leftheight + 1) : (rightheight + 1);
    }
}

struct node *mirrorImage(struct node *tree) {
    if (tree != NULL) {
        struct node *temp;
        mirrorImage(tree->left);
        mirrorImage(tree->right);
        temp = tree->left;
        tree->left = tree->right;
        tree->right = temp;
    }
    return tree;
}

struct node *deleteTree(struct node *tree) {
    if (tree != NULL) {
        deleteTree(tree->left);
        deleteTree(tree->right);
        free(tree);
    }
    return NULL;
}
struct node *inOrderPredecessor(struct node* tree){
    tree = tree->left;
    while (tree->right!=NULL)
    {
        tree = tree->right;
    }
    return tree;
}

struct node *deleteNode(struct node *tree, int value){

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
        tree-> left = deleteNode(tree->left,value);
    }
    else if (value > tree->data){
        tree-> right = deleteNode(tree->right,value);
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
        tree->left = deleteNode(tree->left, iPre->data);
    }
    return tree;
}
 