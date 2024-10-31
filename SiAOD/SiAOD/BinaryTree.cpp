#include "BinaryTree.h"

#include <iostream>

#include "Global.h"
#include <string>

BinaryTree::BinaryTree(const std::string& value)
{
    m_value = value;
    m_left = nullptr;
    m_right = nullptr;
}

BinaryTree::BinaryTree() : 
    BinaryTree("")
{
}

BinaryTree::~BinaryTree()
{
    delete m_left;
    delete m_right;
}

std::string BinaryTree::Value()
{
    return m_value;
}

BinaryTree* BinaryTree::Left() const
{
    return m_left;
}

void BinaryTree::SetLeft(BinaryTree* left)
{
    m_left = left;
}

BinaryTree* BinaryTree::Right() const
{
    return m_right;
}

void BinaryTree::SetRight(BinaryTree* right)
{
    m_right = right;
}


void BinaryTree::Insert(const std::string& value)
{
    BinaryTree* newNode = new BinaryTree(value);
    BinaryTree* currentNode = this;
    while (true)
    {
        if (CompareStrings(newNode->Value(), currentNode->Value()) < 0)
        {
            if (currentNode->Left() == nullptr)
            {
                currentNode->SetLeft(newNode);
                return;
            }
            currentNode = currentNode->Left();
            continue;
        }
        if (currentNode->Right() == nullptr)
        {
            currentNode->SetRight(newNode);
            return;
        }
        currentNode = currentNode->Right();
    }
}

void BinaryTree::Print(unsigned int space, unsigned int level) const
{
    if (m_right != nullptr)
    {
        m_right->Print(space, level + 1);
    }
    std::string line(level * space, ' ');
    if (m_value.length() > space)
    {
        line += m_value.substr(0, space) + '\n';
        std::cout << line;
    }
    else
    {
        unsigned int edge_space = (space - m_value.length()) / 2;
        line += std::string(edge_space, ' ') + m_value + '\n';
        std::cout << line;
    }
    if (m_left != nullptr)
    {
        m_left->Print(space, level + 1);
    }
}

void BinaryTree::TraverseInOrder(std::vector<std::string>& result) const
{
    if (m_left != nullptr)
    {
        m_left->TraverseInOrder(result);
    }
    result.push_back(m_value);
    if (m_right != nullptr)
    {
        m_right->TraverseInOrder(result);
    }
}

void BinaryTree::TraversePostOrder(std::vector<std::string>& result) const
{
    if (m_left != nullptr)
    {
        m_left->TraversePostOrder(result);
    }
    if (m_right != nullptr)
    {
        m_right->TraversePostOrder(result);
    }
    result.push_back(m_value);
}

int BinaryTree::Find(const std::string& value, unsigned int level) const
{
    int comp = CompareStrings(value, m_value);
    if (comp == 0)
    {
        return level;
    }
    if (comp < 0 && m_left != nullptr)
    {
        return m_left->Find(value, level + 1);
    }
    if (comp > 0 && m_right != nullptr)
    {
        return m_right->Find(value, level + 1);
    }
    return -1;
}

std::string BinaryTree::Average() const
{
    std::string out;
    std::vector<float> average;
    std::vector<std::string> values;
    TraverseInOrder(values);
    for (const std::string& value : values)
    {
        if (average.size() < value.length())
            average.resize(value.length());

        for (unsigned int i = 0; i < value.length(); ++i)
        {
            average[i] += value[i];
        }
    }
    for (float& a : average)
    {
        a /= values.size();
        out.push_back(static_cast<char>(a));
    }
    return out;
}
