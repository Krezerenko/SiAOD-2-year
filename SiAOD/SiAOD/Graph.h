#pragma once
#include <vector>
#include <xstring>

class Graph
{
    unsigned int m_nodeAmount;
    std::vector<std::vector<double>> m_adjacencyMatrix;
public:
    explicit Graph(const std::vector<std::vector<double>>& adjacencyMatrix);
    explicit Graph(std::vector<std::vector<double>>&& adjacencyMatrix);
    Graph();
    void AddNodes(unsigned int amount);
    bool RemoveNode(unsigned int index);
    bool SetEdge(unsigned int index1, unsigned int index2, double weight);
    void AddEdge(unsigned int index1, unsigned int index2, double weight);
    void LeastDistances(unsigned int start, std::vector<double>& distances, std::vector<unsigned int>& nodes) const;
    void Print(unsigned int space) const;
};

