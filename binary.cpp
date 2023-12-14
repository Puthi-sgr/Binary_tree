#include <iostream>

struct bst_node{
    int data;
    bst_node* left;
    bst_node* right;
};

bst_node* get_new_node(int data){
    bst_node* newNode = new bst_node;
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}//a function that retrieves the node pointer 

bst_node* insert(bst_node* root, int data){
    if(root == NULL){
        std::cout << "it is null\n";
        root = get_new_node(data);
    }else if(data <= root -> data){
        std::cout << "insert at left \n";
        root -> left = insert(root -> left , data);
    }else if(data > root -> data){
        std::cout << "insert at right \n";
        root -> right = insert(root -> right, data); 
    }
    return root;
}

bool search(bst_node* root, int data){
    if(root == NULL){
        return false;
    }else if(data == root -> data){
        return true; // if the data in root it self
    }else if(data <= root -> data){
        return search(root -> left, data);
    }else if(data > root -> data){
        return search(root -> right, data);
    }
return  0;
}

int main() {
    bst_node* root = NULL;
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 0);
    root = insert(root, 4);
    //insert(&root, );
    if(search(root, 5)){
        std::cout << "found";
    }else{
        std::cout << "not found";
    }

    return 0;
}