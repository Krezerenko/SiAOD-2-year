#include "Graph.h"

#include <iostream>
#include <queue>
#include <string>

#include "Global.h"

Graph::Graph(const std::vector<std::vector<double>>& adjacencyMatrix)
{
    m_nodeAmount = m_adjacencyMatrix.size();
    m_adjacencyMatrix = adjacencyMatrix;
}

Graph::Graph(std::vector<std::vector<double>>&& adjacencyMatrix)
{
    m_nodeAmount = m_adjacencyMatrix.size();
    m_adjacencyMatrix = std::move(adjacencyMatrix);
}

Graph::Graph()
{
    m_nodeAmount = 0;
}

void Graph::AddNodes(const unsigned int amount)
{
    if (amount == 0) return;

    for (int i = 0; i < amount; ++i)
    {
        m_adjacencyMatrix.emplace_back(m_nodeAmount + amount, 0);
    }
    for (int i = 0; i < m_nodeAmount; ++i)
    {
        m_adjacencyMatrix[i].resize(m_nodeAmount + amount);
        for (int j = 0; j < amount; ++j)
        {
            m_adjacencyMatrix[i][m_nodeAmount + j] = 0;
        }
    }
    m_nodeAmount += amount;
}

bool Graph::RemoveNode(const unsigned int index)
{
    if (index >= m_nodeAmount) return false;

    m_adjacencyMatrix.erase(m_adjacencyMatrix.begin() + index);
    m_nodeAmount--;
    for (int i = 0; i < m_nodeAmount; ++i)
    {
        m_adjacencyMatrix[i].erase(m_adjacencyMatrix[i].begin() + index);
    }
    return true;
}

bool Graph::SetEdge(const unsigned int index1, const unsigned int index2, const double weight)
{
    if (index1 >= m_nodeAmount) return false;
    if (index2 >= m_nodeAmount) return false;

    m_adjacencyMatrix[index1][index2] = weight;
    return true;
}

void Graph::AddEdge(const unsigned int index1, const unsigned int index2, const double weight)
{
    const unsigned int max = std::max(index1, index2);
    if (max >= m_nodeAmount)
    {
        AddNodes(max - m_nodeAmount + 1);
    }

    m_adjacencyMatrix[index1][index2] = weight;
}

void Graph::LeastDistances(const unsigned int start, std::vector<double>& distances, std::vector<unsigned int>& nodes) const
{
    distances = std::vector<double>(m_nodeAmount, std::numeric_limits<double>::infinity());
    nodes = std::vector<unsigned int>(m_nodeAmount);
    if (start >= m_nodeAmount) return;

    distances[start] = 0;
    nodes[start] = start;
    bool* visited = new bool[m_nodeAmount];
    for (int i = 0; i < m_nodeAmount; ++i)
    {
        visited[i] = false;
    }
    auto compareDistance = [&distances](unsigned int a, unsigned int b) { return distances[a] > distances[b]; };
    std::priority_queue<unsigned int, std::vector<unsigned int>, decltype(compareDistance)> nodeQueue(compareDistance);
    nodeQueue.push(start);

    while (!nodeQueue.empty())
    {
        unsigned int currentNode = nodeQueue.top();
        visited[currentNode] = true;
        for (int i = 0; i < m_nodeAmount; ++i)
        {
            if (visited[i]) continue;
            const double adjacentDistance = m_adjacencyMatrix[currentNode][i];
            if (adjacentDistance == 0) continue;

            if (adjacentDistance + distances[currentNode] < distances[i])
            {
                distances[i] = adjacentDistance + distances[currentNode];
                nodes[i] = currentNode;
                nodeQueue.push(i);
            }
        }
        nodeQueue.pop();
    }

    delete[] visited;
}

void Graph::Print(unsigned int space) const
{
    std::cout << std::string(space, ' ');
    for (int i = 0; i < m_nodeAmount; ++i)
    {
        std::cout << SpaceAround(space, std::to_string(i));
    }
    std::cout << '\n';
    for (int i = 0; i < m_nodeAmount; ++i)
    {
        std::cout << SpaceAround(space, std::to_string(i));
        for (int j = 0; j < m_nodeAmount; ++j)
        {
            double rounded = round(m_adjacencyMatrix[i][j] * 10) / 10;
            std::string str = std::to_string(rounded);
            str = str.substr(0, str.find('.') + 2);
            std::cout << SpaceAround(space, str);
        }
        std::cout << '\n';
    }
}
