#pragma once

#include <string>
#include <vector>

class BinaryTree
{
private:
    std::string m_value;
    BinaryTree* m_left;
    BinaryTree* m_right;

public:
    explicit BinaryTree(const std::string& value);
    BinaryTree();
    ~BinaryTree();

    std::string Value();
    BinaryTree* Left() const;
    void SetLeft(BinaryTree* left);
    BinaryTree* Right() const;
    void SetRight(BinaryTree* right);

    void Insert(const std::string& value);
    void Print(unsigned int space, unsigned int level) const;
    void TraverseInOrder(std::vector<std::string>& result) const;
    void TraverseLevelOrder(std::vector<std::string>& result) const;
    void TraversePostOrder(std::vector<std::string>& result) const;
    int Find(const std::string& value, unsigned int level) const;
    std::string Average() const;
};

