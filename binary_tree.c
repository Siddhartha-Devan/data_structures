
#include <stdio.h>
struct node {
    int value;
    struct node *left;
    struct node *right;
};

struct node tree_builder(int inp_arr[]){
    struct node* q_arr[10];
    printf("%d %d\n", sizeof(q_arr), sizeof(q_arr[0]));
    
    int elem = 0;
    struct node root;
    root.value = inp_arr[elem];  
    root.right = NULL;
    root.left = NULL;
    // printf("%p \n", root.right);
    // printf("%s", );
    q_arr[0] = &root;
    // printf("%p \n",&root);
    elem = 1;
    int rear = 0;
    int front = 0;
    // printf("%p \n",&root);
    while (elem<=8){
        // printf("%p \n",&root);
        
        if (q_arr[rear]->left == NULL){
            struct node left_n;
            printf("%p \n",&root);
            left_n.value = inp_arr[elem];
            left_n.left = NULL;
            left_n.right = NULL;
            elem+=1;
            q_arr[rear]->left = &left_n;
            front+= 1;
            q_arr[front] = &left_n;
            printf("%p \n", &left_n);
        }
        else if (q_arr[rear]->right == NULL){
            struct node right_n;
            right_n.value = inp_arr[elem];
            right_n.right = NULL;
            right_n.left = NULL;
            elem+=1;
            q_arr[rear]->right = &right_n;
            front+=1;
            q_arr[front] = &right_n;
            printf("%p \n", &right_n);
        }
        else{
            rear+=1;
        }
        
    }
    for (int i=0; i<=8; i++){
        printf("%p \n", &q_arr[i]);
        printf("%d  %d \n", sizeof(q_arr[i]), sizeof(&q_arr[i]));
    }
    
    return root;
}

void tree_printer(struct node root){
    // struct node q_arr = []
    struct node* q_arr[10];
    printf("%d %d\n", sizeof(q_arr), sizeof(q_arr[0]));
    
    
    
}

int main() {
    int inp_arr[] = {1,2,3,4,5,6,7,8,9};
    // int elem = 0;
    // struct node root;
    // root.value = inp_arr[elem];
    // printf("%p \n",&root);
    // elem+=1;
    
    // struct node l1;
    // l1.value = inp_arr[elem];
    // elem+=1;
    // root.left = &l1;
    
    // struct node r1;
    // r1.value = inp_arr[elem];
    // elem+=1;
    // root.right = &r1;
    
    
    
    // printf("%d \n %p,\n %p %p \n %d %d \n %p %p", root.value, &root, root.left, &l1, (root.left)->value, l1.value, root.right, &r1);
    struct node new_root = tree_builder(inp_arr);
    
    
    return 0;
}