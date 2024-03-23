#ifndef Bst_H_
#define Bst_H_

#include <iostream>
#include "BstNode.h"

using namespace std;

class BST {
  private:
    BstNode* root;

    void print(BstNode* root){
      if (root == nullptr) return;
      this->print(root->left);
      cout << root->data << " ";
      this->print(root->right);
    }
    
    int height(BstNode* root) {
      if (root == nullptr) return -1;
      int leftH = this->height(root->left);
      int rightH = this->height(root->right);
      
      if (leftH > rightH) {
        return leftH + 1;
      }
      return rightH + 1;
    }

    BstNode* min(BstNode* root){
      if (root == nullptr) return nullptr;
      while (root->left != nullptr) {
        root = root->left;
      }
      return root;
    }
    
    BstNode* max(BstNode* root){
      if (root == nullptr) return nullptr;
      while (root->right != nullptr) {
        root = root->right;
      }
      return root;
    }

    BstNode* pop(BstNode* root, int data) {
      if (root == nullptr) return nullptr;

      if (data < root->data) {
        root->left = this->pop(root->left, data);
        return root;
      }

      if (data > root->data) {
        root->right = this->pop(root->right, data);
        return root;
      }
      
      if (root->left == nullptr && root->right == nullptr) {
        delete root;
        return nullptr;
      }

      if (root->left == nullptr) {
        BstNode* temp = root->right;
        delete root;
        return temp;
      }

      if (root->right == nullptr) {
        BstNode* temp = root->left;
        delete root;
        return temp;
      }
      
      BstNode* max = this->max(root->left);
      root->data = max->data;
      root->left = this->pop(root->left, max->data);

      return root;
    }

  public:
    
    BST(){
      this->root = nullptr;
    };
    
    void push(int data){
      BstNode** rootPtr = &this->root;
      while (*rootPtr != nullptr) {
        BstNode* root = *rootPtr;
        if(data <= root->data) {
          rootPtr = &root->left;
          continue;
        }
        rootPtr = &root->right;
      }
      *rootPtr = new BstNode(data);
    }

    void pop(int data) {
      this->root = this->pop(this->root, data);
    }
    
    BstNode* search(int data){
      BstNode* root = this->root;
      while(root != nullptr){
        if (root->data == data) return root;
        if (data <= root->data) {
          root = root->left;
          continue;
        }
        root = root->right;
      }
      return nullptr;
    }
    
    void print() {
      if (this->root == nullptr) {
        cout << "vacio" << endl;
        return;
      }
      this->print(this->root);
      cout << endl;
    }
    
    BstNode* max(){
      return this->max(this->root);
    }

    BstNode* min(){
      return this->min(this->root);
    }
    
    bool isEmpty(){
      return this->root == nullptr;
    }
    
    int height(){
      return this->height(this->root);  
    }
};

#endif // !Bst_H_
