#ifndef __AStar__AStar__
#define __AStar__AStar__

#include <iostream>
#include <list>
#include "Node.h"
#include <vector>


class AStar
{
public:
	void Run(vector<Node> &result);
	void Setup();

private:	
	void CreateGraph();
	void CreateGraphAdjs(Node* currentNode);
	void CreateNodeAdj(Node* currentNode, int* adjNodeConfiguration);
	int* CreateNewConfiguration(int[], int*, int);

	void ComputeGraphHeuristics();
	void ComputeNodeHeuristic(Node* pNode);

	void Clean();

	void Search(vector<Node> &result);
	Node* VisitNode();
	void AddNodeToOpenList(Node* pParent, Node* pNode);

	void PrintPath(Node* pNode) const;

	Node* iStartNode;
	Node* iEndNode;
	
	int startConfig[16];
	int endConfig[16];
	int adjNodeConfiguration[16];

	std::list<Node*> tRoot; //Lista di tutti i nodi (contenenti configurazioni)
	std::list<Node*> qOpenList;
};

#endif /* defined(__AStar__AStar__) */
