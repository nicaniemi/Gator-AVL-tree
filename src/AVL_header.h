#ifndef AVL_HEADER_H
#define AVL_HEADER_H

#include <utility>
#include <vector>
#include <string>
using namespace std;

class AVL
{
private:
    struct TreeNode
    {
        string name;
        int val;
        int height = 0;
        TreeNode *left;
        TreeNode *right;
        TreeNode(string studentName, const int id) : name(std::move(studentName)), val(id), left(nullptr), right(nullptr) {}
    };

    TreeNode* root = nullptr;
    static int getHeight(const TreeNode* helpRoot);
    static int getBalanceFactor(const TreeNode* helpRoot);
    static TreeNode* rotateLeft(TreeNode* helpRoot);
    static TreeNode* rotateRight(TreeNode* helpRoot);
    static TreeNode* helperInsert(TreeNode* helpRoot, const string &name, int id);
    static void helperInOrder(const TreeNode* helpRoot, std::vector<int>& result);
    static void helperPreOrder(const TreeNode* helpRoot, std::vector<int>& result);
    static void helperPostOrder(const TreeNode *helpRoot, vector<int> &result);
    static bool helperSearchByID(const TreeNode* helpRoot, int id);
    static bool helperSearchByName(const TreeNode* helpRoot, const string& name);
    static TreeNode* helperRemoveByID(TreeNode* helpRoot, int id);
    static std::vector<int> helperLevelCount(TreeNode* helpRoot);

public:
    std::vector<int> inOrder() const;
    std::vector<int> preOrder() const;
    std::vector<int> postOrder() const;
    string insert(const string &name, int id);
    string printInOrder() const;
    string printPreOrder() const;
    string printPostOrder() const;
    unsigned int printLevelCount() const;
    string searchByID(int id) const;
    string searchByName(const string &name) const;
    string removeByID(int id);
    string removeInOrder(int n);
};

#endif