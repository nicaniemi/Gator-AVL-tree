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
        string val;
        int height = 0;
        TreeNode *left;
        TreeNode *right;
        TreeNode(string studentName, string id) : name(std::move(studentName)), val(std::move(id)), left(nullptr), right(nullptr) {}
    };

    TreeNode* root = nullptr;
    static int getHeight(const TreeNode* helpRoot);
    static int getBalanceFactor(const TreeNode* helpRoot);
    static TreeNode* rotateLeft(TreeNode* helpRoot);
    static TreeNode* rotateRight(TreeNode* helpRoot);
    static TreeNode* helperInsert(TreeNode* helpRoot, const string &name, const string &id);
    static void helperInOrder(const TreeNode* helpRoot, std::vector<string> &result);
    static void helperPreOrder(const TreeNode* helpRoot, std::vector<string> &result);
    static void helperPostOrder(const TreeNode *helpRoot, vector<string> &result);
    static bool helperSearchByID(const TreeNode* helpRoot, const string &id);
    static bool helperSearchByName(const TreeNode* helpRoot, const string &name);
    static TreeNode* helperRemoveByID(TreeNode* helpRoot, const string &id);
    static std::vector<int> helperLevelCount(TreeNode* helpRoot);

public:
    std::vector<string> inOrder() const;
    std::vector<string> preOrder() const;
    std::vector<string> postOrder() const;
    string insert(const string &name, const string& id);
    string printInOrder() const;
    string printPreOrder() const;
    string printPostOrder() const;
    unsigned int printLevelCount() const;
    string searchByID(const string &id) const;
    string searchByName(const string &name) const;
    string removeByID(const string& id);
    string removeInOrder(int n);
};

#endif