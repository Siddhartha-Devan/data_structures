
#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *left;
    struct node *right;
};

struct node* tree_builder(int inp_arr[], int size){

    struct node* q_arr[size];
    printf("%d %d\n", sizeof(q_arr), sizeof(q_arr[0]));
    
    int elem = 0;
    struct node* root; 
    root = malloc(sizeof(struct node));

    root->value = inp_arr[elem];  
    root->right = NULL;
    root->left = NULL;
    // printf("%p \n", root.right);
    // printf("%s", );
    q_arr[0] = root;
    // printf("%p \n",&root);
    elem = 1;
    int rear = 0;
    int front = 0;
    // printf("%p \n",&root);
    while (elem<size){
        // printf("%p \n",&root);
        if (q_arr[rear]->left == NULL){
            struct node* left_n;
            left_n = malloc(sizeof(struct node));
            // printf("%p \n",&root);
            left_n->value = inp_arr[elem];
            left_n->left = NULL;
            left_n->right = NULL;
            elem+=1;
            q_arr[rear]->left = left_n;
            front+= 1;
            q_arr[front] = left_n;
            // printf("%p  %d\n", left_n, inp_arr[elem]);
        }
        else if (q_arr[rear]->right == NULL){
            struct node* right_n;
            right_n = malloc(sizeof(struct node));
            right_n->value = inp_arr[elem];
            right_n->right = NULL;
            right_n->left = NULL;
            elem+=1;
            q_arr[rear]->right = right_n;
            front+=1;
            q_arr[front] = right_n;
            // printf("%p  %d \n", right_n, inp_arr[elem]);
            rear+=1;
        }
 
        
    }
    for (int i=0; i<size; i++){
        printf("%p ", q_arr[i]);
        // printf("%d  %d \n", sizeof(q_arr[i]), sizeof(&q_arr[i]));
        // // printf("\n");

        printf("%d \n", q_arr[i]->value);


    }
  
    return root;

}

void tree_printer_bfs(struct node* root){
    // struct node q_arr = []
    struct node* q_arr[50];
    printf("%d %d\n", sizeof(q_arr), sizeof(q_arr[0]));
    int rear = 0;
    int front = 1; 
    q_arr[0] = root;

    printf("%d \n", root->value);

    while((q_arr[rear]->left!=NULL) || (q_arr[rear]->right!=NULL)){
        // printf("%d \n", q_arr[rear]->value);
        q_arr[front] = q_arr[rear]->left;
        front+=1;
        printf("%d \n", q_arr[rear]->left->value);

        q_arr[front] = q_arr[rear]->right;
        front+=1;
        printf("%d \n", q_arr[rear]->right->value);

        rear+=1;
    }
    printf("%d %p %p \n", q_arr[rear]->value, q_arr[rear]->left, q_arr[rear]->right);
    printf("%d \n", rear);
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


int add_node(struct node* root, struct node* new_node){
    // struct node* q_arr[30];
    // int rear = 0;
    // int front = 0;

    struct node* temp =root;
    // temp = malloc(sizeof(struct node));
    // temp = root;
    printf("%p %p %p \n", temp->right, temp, temp->left);
    while (temp->right != NULL){
        temp = temp->right;
        printf("%p %p %p \n", temp->right, temp, temp->left);
    }
    printf("%p %p %p \n", temp->right, temp, temp->left);

    if (temp->left == NULL){
        temp->left = new_node;
    }
    else if(temp->right == NULL){
        temp->right = new_node;
    }
    printf("%p %p %p \n", temp->right, temp, temp->left);
    int order = 1;
    // tree_printer_dfs(root, order);

    return 1;

}





int main() {
    int inp_arr[] = {1,2,3,4,5,6,7,8,9, 10, 11, 12, 13, 14, 15};
    printf("%d %d \n", sizeof(inp_arr), sizeof(inp_arr[2]));
    int len = sizeof(inp_arr) / sizeof(inp_arr[2]);
    struct node* new_root = tree_builder(inp_arr, len);

    printf("\n\n");
    // tree_printer_bfs(new_root);
    int order = 0;
    // tree_printer_dfs(new_root, order);
    struct node* new_node;
    new_node = malloc(sizeof(struct node));
    new_node->value = 16;
    new_node->left = NULL;
    new_node->right = NULL; 

    struct node* new_node2;
    new_node2 = malloc(sizeof(struct node));
    new_node2->value = 17;
    new_node2->left = NULL;
    new_node2->right = NULL; 

    add_node(new_root, new_node);
    add_node(new_root, new_node2);

    tree_printer_bfs(new_root);
    tree_printer_dfs(new_root, order);

    return 0;
}
