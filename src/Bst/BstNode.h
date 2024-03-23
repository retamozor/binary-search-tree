#ifndef BstNode_H_
#define BstNode_H_

class BstNode {
  public:
    int data;
    BstNode* left;
    BstNode* right;
    BstNode(int data) {
      this->data = data;
      this->left = nullptr;
      this->right = nullptr;
    };
};

#endif // !BstNode_H_
