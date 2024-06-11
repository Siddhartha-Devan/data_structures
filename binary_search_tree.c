#include <stdio.h>
#include <stdlib.h>


struct node {
    int value;
    struct node *left;
    struct node *right;
};

struct node* tree_builder(int inp_arr[], int size){
    struct node* root;
    root = malloc(sizeof(struct node));
    root->value = inp_arr[0];
    root->left = NULL;
    root->right = NULL;

    int lr_flag = 0;
    for (int i = 1; i<size; i++){
        struct node* curr_node = root;
        struct node* parent_node = root;
        int new_value = inp_arr[i];
        while (curr_node != NULL){
            // printf("%d \n", size);
            // printf("%d %p %p %p %p %d \n", parent_node->value, parent_node, parent_node->left, parent_node->right, curr_node, curr_node->value);
            
            if (new_value<curr_node->value){
                
                lr_flag = 0;
                
                parent_node = curr_node;
                
                curr_node = curr_node->left;
                // printf("%d \n", new_value);
            }
            else if (new_value>curr_node->value){
                lr_flag = 1;
                parent_node = curr_node;
                curr_node = curr_node->right;
            }
            printf("%d \n", new_value);
            // printf("%d %p %p %p %p\n", parent_node->value, parent_node, parent_node->left, parent_node->right, curr_node);
    
            // printf("%d %p %p %p %p %d \n", parent_node->value, parent_node, parent_node->left, parent_node->right, curr_node, curr_node->value);
    
        }
        struct node* new_node;
        new_node = malloc(sizeof(struct node));
        new_node->value = inp_arr[i];
        new_node->left = NULL;
        new_node->right = NULL;
        if (lr_flag==0){
            parent_node->left = new_node;
        }
        else{
             parent_node->right = new_node;
        }
        printf("%d %p %p %p %p %d \n", parent_node->value, parent_node, parent_node->left, parent_node->right, new_node, new_node->value);
    
    } 

    return root;
} 


void add_node(struct node* root, int n){
    struct node* new_node;
    new_node = malloc(sizeof(struct node));
    new_node->value = n;
    new_node->left = NULL;
    new_node->right = NULL;
    struct node* curr_node;
    struct node* parent_node;
    int lr_flag= 0;
    curr_node = root;
    parent_node = root;
    // printf("%d \n", parent_node->value);

    while (curr_node != NULL){
        if (n<curr_node->value){
            parent_node=curr_node;
            curr_node = curr_node->left;
            lr_flag = 0;
        }
        else if(n>curr_node->value){
            parent_node=curr_node;
            curr_node=curr_node->right;
            lr_flag = 1;
        }
    }
    if (lr_flag==0){
        parent_node->left = new_node;
    }
    else{
            parent_node->right = new_node;
    }


}



void tree_printer_dfs(struct node* new_root, int order){
    if (order == 0){
        if (new_root == NULL){
            return;
        }
        else{
            printf("%d\n ", new_root->value);
            tree_printer_dfs(new_root->left, order);
            tree_printer_dfs(new_root->right, order);
        }
    }
    else if (order == 1){
        if (new_root == NULL){
            return;
        }
        else{
            tree_printer_dfs(new_root->left, order);
            printf("%d\n ", new_root->value);
            tree_printer_dfs(new_root->right, order);
        }
    }
    else{
        if (new_root == NULL){
            return;
        }
        else{
            tree_printer_dfs(new_root->left, order);
            tree_printer_dfs(new_root->right, order);
            printf("%d\n ", new_root->value);
        }
    }
}


int main() {
    struct node* root;
    // root = malloc(sizeof(struct node));
    // root->value = 10;
    // root->left = NULL;
    // root->right = NULL;

    int inp_arr[] = {45, 15, 79, 90, 10, 55, 12, 20, 50 };
    int len = sizeof(inp_arr)/sizeof(inp_arr[0]);
    printf("%p \n", root);
    root = tree_builder(inp_arr, len);
    printf("%p \n", root);
    printf("%d\n", root->value);
    int order = 1;
    // tree_printer_dfs(root, order);
    int n1=60;
    int n2 = 85;
    int n3 = 17;
    add_node(root, n1);
    add_node(root, n2);
    add_node(root, n3);
    tree_printer_dfs(root, order);
    return 0;
}






