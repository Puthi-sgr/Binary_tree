#include <iostream>

struct bst_node{
    int data;
    bst_node* left;
    bst_node* right;
};

bst_node* get_new_node(int data){
    bst_node* newNode = new bst_node();
    newNode -> data = data;
    newNode -> left = newNode -> right = NULL;
    return newNode;
}//a function that retrieves the node pointer 

bst_node* insert(bst_node** root, int data){
    std::cout << *root;
    if(root == NULL){
        return get_new_node(data);
    }else if(data <= (*root) -> data){
        (*root) -> left = insert(&((*root)->left) , data);
    }else if(data >= (*root) -> data){
        (*root) -> right = insert(&(*root) -> right, data);
    }
    return *root;
}

int main() {
    bst_node* root = NULL;
    insert(&root, 2);
    std::cout << root;
    return 0;
}