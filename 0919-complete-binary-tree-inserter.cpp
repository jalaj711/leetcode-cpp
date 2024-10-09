struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Node {
  TreeNode * node;
  Node * next;
  Node(TreeNode * tree): node(tree), next(nullptr) {};
};

class CBTInserter {
  Node * head;
  Node * tail;
  Node * ptr;
  int size;

  TreeNode * _root;

  void addNode(TreeNode * node) {
    auto n = new Node(node);
    if (head == nullptr) {
      head = tail = ptr = n;
      size = 1;
      return;
    }

    tail -> next = n;
    tail = n;
    size++;
  }

  void pop() {
    auto n = head;
    head = head -> next;
    if (ptr == n) ptr = head;
    delete n;
    size--;
  }

  void incr() {
    if (ptr == tail) {
      int sz = size;
      for(int i=0;i<sz;i++) {
        auto node = head;
        addNode(node->node->left);
        addNode(node->node->right);
        pop();
      }
      ptr = head;
      return;
    }
    ptr = ptr->next;
  }

public:
  CBTInserter(TreeNode* root) {
    head = tail = ptr = nullptr;
    size = 0;
    _root = root;
    addNode(root);
    while(ptr->node->left!=nullptr && ptr->node->right!=nullptr) {
      incr();
    }
  }

  int insert(int val) {
    if (ptr->node-> left == nullptr) {
      ptr->node->left = (new TreeNode(val));
      return ptr->node-> val;
    }
    if (ptr->node-> right == nullptr) {
      ptr->node-> right = (new TreeNode(val));
      return ptr->node-> val;
    }
    incr();
    ptr->node-> left = (new TreeNode(val));
    return ptr->node-> val;
  }

  TreeNode* get_root() {
    return _root;
  }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */