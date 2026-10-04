#include <queue>
#include <vector>
#include <regex>
#include "AVL_header.h"

// Define helper to return height

int AVL::getHeight(const TreeNode* const helpRoot)  // Return the height of the tree
{
    if (helpRoot == nullptr)
        return -1;

    else
        return helpRoot->height;
}

int AVL::getBalanceFactor(const TreeNode* helpRoot) // Return the balance factor of the tree
{
    int const leftHeight = getHeight(helpRoot->left);
    int const rightHeight = getHeight(helpRoot->right);
    int const balanceFactor = leftHeight - rightHeight;

    return balanceFactor;
}

// Define left rotation

AVL::TreeNode* AVL::rotateLeft(TreeNode* helpRoot) // Rotate left if the tree is unbalanced, and update heights
{
    TreeNode* newRoot = helpRoot->right;
    TreeNode* middleSubtree = newRoot->left;

    newRoot->left = helpRoot;
    helpRoot->right = middleSubtree;

    int const leftHeightHelp = getHeight(helpRoot->left);
    int const rightHeightHelp = getHeight(helpRoot->right);
    int const leftHeightNew = getHeight(newRoot->left);
    int const rightHeightNew = getHeight(newRoot->right);

    helpRoot->height = max(leftHeightHelp, rightHeightHelp) + 1;
    newRoot->height = max(leftHeightNew, rightHeightNew) + 1;

    return newRoot;
}

// Define right rotation

AVL::TreeNode* AVL::rotateRight(TreeNode* helpRoot) // Rotate right if the tree is unbalanced, and update heights
{
    TreeNode* newRoot = helpRoot->left;
    TreeNode* middleSubtree = newRoot->right;

    newRoot->right = helpRoot;
    helpRoot->left = middleSubtree;

    int const leftHeightHelp = getHeight(helpRoot->left);
    int const rightHeightHelp = getHeight(helpRoot->right);
    int const leftHeightNew = getHeight(newRoot->left);
    int const rightHeightNew = getHeight(newRoot->right);

    helpRoot->height = max(leftHeightHelp, rightHeightHelp) + 1;
    newRoot->height = max(leftHeightNew, rightHeightNew) + 1;

    return newRoot;
}

// Define insert + helper method

AVL::TreeNode* AVL::helperInsert(TreeNode* helpRoot, const string &name, int const id) // BST Insert function, code from Module 4 Balanced Trees ppt
                                          // "helpRoot" is the current name, and "key" is the GatorID number
{
    if (helpRoot == nullptr) // Create a tree if no nodes inserted
        return new TreeNode(name, id);

    else if (id < helpRoot->val) // If the key is less than the parent key, the root is inserted to the left subtree
    {
        helpRoot->left = helperInsert(helpRoot->left, name, id);
    }

    else // If the key is greater than parent key, insert to the right subtree
    {
        helpRoot->right = helperInsert(helpRoot->right, name, id);
    }

    int const leftHeight = getHeight(helpRoot->left);
    int const rightHeight = getHeight(helpRoot->right);
    int const currentHeight = max(leftHeight, rightHeight) + 1;
    helpRoot->height = currentHeight;

    int const balanceFactor = getBalanceFactor(helpRoot);

    if (balanceFactor > 1)
    {
        if (getBalanceFactor(helpRoot->left) >= 0)
            return rotateRight(helpRoot);

        else
        {
            helpRoot->left = rotateLeft(helpRoot->left);
            return rotateRight(helpRoot);
        }
    }

    if (balanceFactor < -1)
    {
        if (getBalanceFactor(helpRoot->right) <= 0)
        {
            return rotateLeft(helpRoot);
        }

        else
        {
            helpRoot->right = rotateRight(helpRoot->right);
            return rotateLeft(helpRoot);
        }
    }

    return helpRoot;
}

string AVL::insert(const string &name, int const id) // Insert a student into the tree + regex checks to ensure name meets criteria
{

    if (!regex_match(name, regex("^[A-Za-z ]+$"))) // Ensure valid name
        return "unsuccessful";

    string const idString = to_string(id);

    if (!regex_match(idString, regex("^[0-9]{8}$"))) // Copilot helped me write this, I was unsure how to regex check for the ID
        return "unsuccessful";

    this->root = helperInsert(this->root, name, id); // If valid, return that insertion was successful
    return "successful";
}

// Define level count + helper method

std::vector<int> AVL::helperLevelCount(TreeNode* helpRoot) // Function from Edugator 6.4 (Level Sum) - Iterating through tree to determine levels and return # of levels
{
    std::vector<int> totalLevels {};
    std::queue<std::pair<TreeNode*, int>> treeNodes;

    if (helpRoot != nullptr)
        treeNodes.emplace(helpRoot, 0);

    while (!treeNodes.empty())
    {
        const auto p = treeNodes.front(); // Copilot helped me with this portion, I didn't know how c++14 pairs worked
        TreeNode* node = p.first;
        int const level = p.second;
        treeNodes.pop();

        if (totalLevels.size() <= static_cast<size_t>(level)) // Copilot helped me add static_cast because a test case was throwing an error, and when I asked, it said turning level into an unsigned int could be a bigger issue
            totalLevels.resize(level+1);

        if (node->left)
            treeNodes.emplace(node->left, level+1);
        if (node->right)
            treeNodes.emplace(node->right, level+1);
    }

    return totalLevels;
}

unsigned int AVL::printLevelCount() const // Print the # of levels in the tree
{
    if (root != nullptr)
    {
        std::vector<int> const levels = helperLevelCount(this->root);
        return levels.size();
    }
    else
        return 0;
}

// Define in order traversal + helper method and a method to own the result vector

void AVL::helperInOrder(const AVL::TreeNode* helpRoot, std::vector<int>& result) // Create the in order vector for the tree
{
    if (helpRoot == nullptr)
        return;
    else
    {
        helperInOrder(helpRoot->left, result);
        result.push_back(helpRoot->val);
        helperInOrder(helpRoot->right, result);
    }
}

std::vector<int> AVL::inOrder() const // Return an in order vector of the tree, Copilot helped me decide how to structure the in order functions, mainly defining the vector separately
{
    std::vector<int> result;
    helperInOrder(this->root, result);
    return result;
}

string AVL::printInOrder() const // Print the tree in order
{
    std::vector<int> const vals = inOrder();
    string result;

    for (const int v : vals)
        result += searchByID(v) + ", ";

    if (!result.empty())
    {
        result.pop_back();
        result.pop_back();
    }

    return result;
}

// Define pre order traversal + helper method and method to own result vector

void AVL::helperPreOrder(const AVL::TreeNode* helpRoot, std::vector<int>& result) // Push the pre order traversal into result
{
    if (helpRoot == nullptr)
        return;
    else
    {
        result.push_back(helpRoot->val);
        helperPreOrder(helpRoot->left, result);
        helperPreOrder(helpRoot->right, result);
    }
}

std::vector<int> AVL::preOrder() const // Owns the result vector for pre order traversal
{
    std::vector<int> result;
    helperPreOrder(this->root, result);
    return result;
}

string AVL::printPreOrder() const // Return the result vector as a concatenated string of ints
{
    std::vector<int> const vals = preOrder();
    string result;

    for (const int v : vals)
        result += searchByID(v) + ", ";

    if (!result.empty())
    {
        result.pop_back();
        result.pop_back();
    }

    return result;
}

// Define post order traversal + helper and method to own result vector

void AVL::helperPostOrder(const AVL::TreeNode* helpRoot, std::vector<int>& result) // Push the post order traversal into result
{
    if (helpRoot == nullptr)
        return;
    else
    {
        helperPostOrder(helpRoot->left, result);
        helperPostOrder(helpRoot->right, result);
        result.push_back(helpRoot->val);
    }
}

std::vector<int> AVL::postOrder() const // Owns result vector for post order
{
    std::vector<int> result;
    helperPostOrder(this->root, result);
    return result;
}

string AVL::printPostOrder() const // Return the post order traversal as a concatenated string
{
    std::vector<int> const vals = postOrder();
    string result;

    for (const int v : vals)
        result += searchByID(v) + ", ";

    if (!result.empty())
    {
        result.pop_back();
        result.pop_back();
    }

    return result;
}

// Implement search by ID + helper

bool AVL::helperSearchByID(const TreeNode* helpRoot, int const id) // Iterate through the tree to find the ID, return false if not found, don't execute searchByID()
{
    if (helpRoot == nullptr)
        return false;
    if (id == helpRoot->val)
        return true;
    if (id < helpRoot->val)
        return helperSearchByID(helpRoot->left, id);
    if (id > helpRoot->val)
        return helperSearchByID(helpRoot->right, id);

    return false;
}

string AVL::searchByID(const int id) const // Iterate through the tree and retrieve the name associated with the found ID, return unsuccessful if ID not found
{
    TreeNode* current = root;

    while (current != nullptr) {
        if (id == current->val)
            return current->name;
        if (id < current->val)
            current = current->left;
        else
            current = current->right;
    }

    return "unsuccessful";
}

// Implement search by name and helper
bool AVL::helperSearchByName(const TreeNode* helpRoot, const string& name) // Iterate through tree to find name, return false if not found, don't execute searchByName()
{
    if (helpRoot == nullptr)
        return false;
    if (name == helpRoot->name)
        return true;
    if (helperSearchByName(helpRoot->left, name))
        return true;
    if (helperSearchByName(helpRoot->right, name))
        return true;

    return false;
}

string AVL::searchByName(const string &name) const // Check all nodes in the tree and return all of the IDs associated with "name"
{
    std::vector<int> const IDs = preOrder();
    string result;
    bool found = false;
    for (const int v : IDs)
    {
        string currentName = searchByID(v);
        if (currentName == name)
        {
            result += (to_string(v)) + "\n";
            found = true;
        }
    }

    if (found)
    {
        result.pop_back();
        return result;
    }

    return "unsuccessful";
}

AVL::TreeNode* AVL::helperRemoveByID(TreeNode* helpRoot, int const id) // Determine if ID exists, remove it, and then balance the tree and update height
{
    if (helpRoot == nullptr)
        return nullptr;

    else
    {
        if (id < helpRoot->val)
        {
            helpRoot->left = helperRemoveByID(helpRoot->left, id);
        }

        else if (id > helpRoot->val)
        {
            helpRoot->right = helperRemoveByID(helpRoot->right, id);
        }

        else if (id == helpRoot->val)
        {
            if (helpRoot->left == nullptr && helpRoot->right == nullptr)
            {
                delete helpRoot;
                return nullptr;
            }

            else if (helpRoot->left != nullptr && helpRoot->right == nullptr)
            {
                TreeNode* newChild = helpRoot->left;
                delete helpRoot;
                return newChild;
            }

            else if (helpRoot->left == nullptr && helpRoot->right != nullptr)
            {
                TreeNode* newChild = helpRoot->right;
                delete helpRoot;
                return newChild;
            }

            else
            {
                const TreeNode* inOrderSuccessor = helpRoot->right;
                while (inOrderSuccessor->left != nullptr)
                    inOrderSuccessor = inOrderSuccessor->left;

                helpRoot->name = inOrderSuccessor->name;
                helpRoot->val = inOrderSuccessor->val;
                helpRoot->right = helperRemoveByID(helpRoot->right, helpRoot->val);
            }
        }
    }

    int const leftHeight = getHeight(helpRoot->left);
    int const rightHeight = getHeight(helpRoot->right);
    int const currentHeight = max(leftHeight, rightHeight) + 1;
    helpRoot->height = currentHeight;

    int const balanceFactor = getBalanceFactor(helpRoot);

    if (balanceFactor > 1)
    {
        if (getBalanceFactor(helpRoot->left) >= 0)
            return rotateRight(helpRoot);

        else
        {
            helpRoot->left = rotateLeft(helpRoot->left);
            return rotateRight(helpRoot);
        }
    }

    if (balanceFactor < -1)
    {
        if (getBalanceFactor(helpRoot->right) <= 0)
        {
            return rotateLeft(helpRoot);
        }

        else
        {
            helpRoot->right = rotateRight(helpRoot->right);
            return rotateLeft(helpRoot);
        }
    }

    return helpRoot;
}

string AVL::removeByID(int const id) // If ID exists, remove the ID
{
    if (searchByID(id) == "unsuccessful")
        return "unsuccessful";

    else
    {
        root = helperRemoveByID(root, id);
        return "successful";
    }
}

string AVL::removeInOrder(int const n) // Remove a specified node and replace with inorder
{
    std::vector<int> const IDs = inOrder();

    if (n < 0 || n >= static_cast<int>(IDs.size()))
        return "unsuccessful";

    return removeByID(IDs[n]);
}
