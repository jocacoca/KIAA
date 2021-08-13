/*Design an algorithm that for every node in tree, prints it's path from root to that node, no recursion*/
#include <bits/stdc++.h>
#include <unordered_map>

struct Node
{
    Node ()
    {
      left = right = nullptr;
    }
    int key;
    Node *left;
    Node *right;
};

void add_node(Node **root, int key)
{
    if (*root == nullptr) {
      *root = new Node();
      (*root)->key = key;
      return ;
    }

    if ((*root)->key > key)
      add_node(&(*root)->left, key);
    else
      add_node(&(*root)->right, key);
}

void free_tree(Node *root)
{
  if (root == nullptr)
    return ;

  free_tree(root->left);
  free_tree(root->right);

  delete root;
}

void print_tree(Node *root)
{
  if (root == nullptr)
    return ;

  print_tree(root->left);
  print_tree(root->right);
  std::cout << root->key << " ";
}

bool is_leaf(Node* node){
  return (node->left == nullptr && node->right == nullptr);
}

void print_path(Node* leaf_node,std::unordered_map<Node*,Node*>map){

  Node* tmp = leaf_node;


}
