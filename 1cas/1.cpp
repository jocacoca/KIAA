/*1. For this binary search tree print his spiral transversal by levels
    1
   / \
  2   3
 / \ / \
4 5 6   7
1324567 for right to left
1237654 for left to right

 */
#include <bits/stdc++.h>


struct Node{
    Node(){
        left = right = nullptr;
    }
    Node* right;
    Node* left;
    int key;
};

void add_node(Node** root,int key){
    
    if(*root ==nullptr){
        *root = new Node();
        (*root)->key = key;
        return;
    }
    if((*root)->key > key){
        add_node(&(*root)->left,key);
    }else
        add_node(&(*root)->right,key);
}

void free_tree(Node* root){
    
    if(root == nullptr)
        return;
    free_tree(root->left);
    free_tree(root->right);

    delete root;
}

void spiral_transversal(Node* root,bool Left2Right){
    
    std::list<Node*>nodes;
    nodes.push_back(root);

    Left2Right = !Left2Right;

    while (nodes.size())
    {
        int n = nodes.size();

        while(n--){
            if(Left2Right){
                Node *tmp = nodes.front();
                nodes.pop_front();
                std::cout<<tmp->key<<" ";

                if(tmp->left)
                    nodes.push_back(tmp->left);
                if(tmp->right)
                    nodes.push_back(tmp->right);
            
            }else{
                
                Node * tmp = nodes.back();
                nodes.pop_back();
                std::cout<<tmp->key << " ";

                if(tmp->right)
                    nodes.push_front(tmp->right);
                if(tmp->left)
                    nodes.push_front(tmp->left);
            }
        }

        Left2Right = !Left2Right;
        std::cout<<std::endl;
    }

}

int main(){

    Node* root = nullptr;
    std::vector<int> keys = {4,3,5,7,1,9,8,6};
    for(auto x:keys)
        add_node(&root, x);

    spiral_transversal(root, true);

    free_tree(root);

    exit(EXIT_SUCCESS);
}