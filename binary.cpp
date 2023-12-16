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
};//a function that retrieves the node pointer 

bst_node* insert(bst_node* root, int data){
    if(root == NULL){
        root = get_new_node(data);
    }else if(data <= root -> data){
        root -> left = insert(root -> left , data);
    }else if(data > root -> data){
        root -> right = insert(root -> right, data); 
    };
    return root;
};

bool search(bst_node* root, int data){
    if(root == NULL){
        return false;
    }else if(data == root -> data){
        return true; // if the data in root it self
    }else if(data <= root -> data){
        return search(root -> left, data);
    }else if(data > root -> data){
        return search(root -> right, data);
    };
return  0;
};

//iterative 
int find_min_iterative(bst_node* root){
    bst_node* current = root; 
    while(current -> left != NULL){
        current = current -> left;
    };
    return current -> data;     
};
//iterative
int find_max_iterative(bst_node* root){
    bst_node* current = root; 
    while(current -> right != NULL){
        current = current -> right;
    };
    return current -> data;     
};

//recursive
int find_min_value_recursive(bst_node* root){
    if(root -> left == NULL){
        return root -> data;
    };
    return find_min_value_recursive(root -> left);
};

int find_max_value_recursive(bst_node* root){
    if(root -> right == NULL){
        return root -> data;
    };
    return find_max_value_recursive(root -> right);
};

//displaying data using the pre-order method
//DLR 
void pre_order_method(bst_node* root){
    if(root == NULL){
        return;
    };//base condition
    std::cout << "Pre-ordered Data: " << root -> data << "\n";
    pre_order_method(root -> left);
    pre_order_method(root -> right);
};
//LDR
void in_order_method(bst_node* root){
    if(root == NULL){
        return;
    };//base condition
    in_order_method(root -> left);
    std::cout << "In-ordered Data: " << root -> data << "\n";
    in_order_method(root -> right);
};
//LRD
void post_order_method(bst_node* root){
    if(root == NULL){
        return;
    };
    post_order_method(root -> left);
    post_order_method(root -> right);
    std::cout << "Post-ordered Data: " << root -> data << "\n";
};

int main() {
    bst_node* root = NULL;
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 0);
    root = insert(root, 4);
    root = insert(root, -2);
    root = insert(root, -1);
    root = insert(root, 9);
    //insert(&root, );
    if(search(root, 5)){
        std::cout << "found\n";
    }else{
        std::cout << "not found\n";
    };

    int min_value = find_min_iterative(root);
    int max_value = find_max_iterative(root);

    std::cout << "min_value is : " << min_value << "\n";
    std::cout << "max_value is : " << max_value << "\n";

    std::cout << "min_value of recursive method : " << find_min_value_recursive(root) << "\n";
    std::cout << "max_value of recursive method : " << find_max_value_recursive(root) << "\n";

    std::cout << "----------------------------------------------------\n";

    pre_order_method(root);

    std::cout << "----------------------------------------------------\n";

    in_order_method(root);

    std::cout << "----------------------------------------------------\n";

    post_order_method(root);

    return 0;
}