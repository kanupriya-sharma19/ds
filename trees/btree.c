#include <stdio.h>
#include <stdlib.h>
#define MAX_KEYS 3

typedef struct BPlusTreeNode {
    int is_leaf;
    int num_keys;
    int keys[MAX_KEYS];
    struct BPlusTreeNode* children[MAX_KEYS + 1];
    struct BPlusTreeNode* next;
} BPlusTreeNode;

BPlusTreeNode* create_node(int is_leaf) {
    BPlusTreeNode* new_node = (BPlusTreeNode*)malloc(sizeof(BPlusTreeNode));
    new_node->is_leaf = is_leaf;
    new_node->num_keys = 0;
    new_node->next = NULL;
    for (int i = 0; i <= MAX_KEYS; ++i) {
        new_node->children[i] = NULL;
    }
    return new_node;
}

int binary_search(int keys[], int num_keys, int key) {
    int left = 0, right = num_keys - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (keys[mid] == key) {
            return mid;
        } else if (keys[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

void insert_internal(BPlusTreeNode* node, int key, BPlusTreeNode* right_child) {
    int pos = binary_search(node->keys, node->num_keys, key);
    for (int i = node->num_keys; i > pos; --i) {
        node->keys[i] = node->keys[i - 1];
        node->children[i + 1] = node->children[i];
    }
    node->keys[pos] = key;
    node->children[pos + 1] = right_child;
    node->num_keys++;
}

BPlusTreeNode* split_internal(BPlusTreeNode* node, int* median_key) {
    int mid = node->num_keys / 2;
    *median_key = node->keys[mid];

    BPlusTreeNode* new_node = create_node(0);
    new_node->num_keys = node->num_keys - mid - 1; 

    for (int i = mid + 1; i < node->num_keys; ++i) {
        new_node->keys[i - mid - 1] = node->keys[i];
        new_node->children[i - mid] = node->children[i];
    }
    new_node->children[new_node->num_keys] = node->children[node->num_keys]; 

    node->num_keys = mid; 

    return new_node;
}

BPlusTreeNode* insert_recursive(BPlusTreeNode* root, int key, int* median_key) {
    if (!root) {
        *median_key = key;
        return create_node(1);
    }

    if (root->is_leaf) {
        int pos = binary_search(root->keys, root->num_keys, key);
        for (int i = root->num_keys; i > pos; --i) {
            root->keys[i] = root->keys[i - 1];
        }
        root->keys[pos] = key;
        root->num_keys++;

        if (root->num_keys > MAX_KEYS) {
            return split_internal(root, median_key);
        }
    } else {
        int pos = binary_search(root->keys, root->num_keys, key);
        BPlusTreeNode* new_child = insert_recursive(root->children[pos], key, median_key);

        if (*median_key != -1) {
            insert_internal(root, *median_key, new_child);
            if (root->num_keys > MAX_KEYS) {
                return split_internal(root, median_key);
            }
        }
    }

    *median_key = -1;
    return root;
}

BPlusTreeNode* insert_key(BPlusTreeNode* root, int key) {
    int median_key = -1;
    BPlusTreeNode* new_root = insert_recursive(root, key, &median_key);

    if (median_key != -1) {
        BPlusTreeNode* new_root_node = create_node(0);
        new_root_node->keys[0] = median_key;
        new_root_node->children[0] = root;
        new_root_node->children[1] = new_root;
        return new_root_node;
    }

    return new_root;
}

BPlusTreeNode* search_key(BPlusTreeNode* root, int key) {
    if (!root) {
        return NULL;
    }

    int pos = binary_search(root->keys, root->num_keys, key);

    if (pos < root->num_keys && root->keys[pos] == key) {
        return root;
    } else if (root->is_leaf) {
        return NULL;
    } else {
        return search_key(root->children[pos], key);
    }
}

void inorder_traversal(BPlusTreeNode* root) {
    if (root) {
        if (root->is_leaf) {
            for (int i = 0; i < root->num_keys; ++i) {
                printf("%d ", root->keys[i]);
            }
        } else {
            for (int i = 0; i < root->num_keys; ++i) {
                inorder_traversal(root->children[i]);
                printf("%d ", root->keys[i]);
            }
            inorder_traversal(root->children[root->num_keys]);
        }
    }
}

void free_tree(BPlusTreeNode* root) {
    if (root) {
        if (!root->is_leaf) {
            for (int i = 0; i <= root->num_keys; ++i) {
                free_tree(root->children[i]);
            }
        }
        free(root);
    }
}

int main() {
    BPlusTreeNode* root = NULL;

    root = insert_key(root, 10);
    root = insert_key(root, 20);
    root = insert_key(root, 5);
    root = insert_key(root, 6);
    root = insert_key(root, 12);
    root = insert_key(root, 30);
    root = insert_key(root, 7);
     root = insert_key(root, 17);

    BPlusTreeNode* search_result = search_key(root, 20);
    if (search_result) {
        printf("Key found!\n");
    } else {
        printf("Key not found.\n");
    }

    printf("In-order traversal: ");
    inorder_traversal(root);
    printf("\n");

    free_tree(root);
    return 0;
}
