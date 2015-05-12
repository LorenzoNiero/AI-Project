#ifndef __AStar__Node__
#define __AStar__Node__

#include <list>
#include "NodeState.h"
#include <iostream>
using namespace std;

class Node
{
public:

	Node();
	bool operator==(const Node& other) const;
	bool operator!=(const Node& other) const;

	void setConfiguration(int config[]);
	int* getConfiguration();
	int getConfigurationIndexed(int index) { return configuration[index]; };


	friend ostream& operator<<(ostream& out, const Node* a);

	NodeState           eState;
	Node*               pParent;
	int                 iF;
	int                 iG;
	int                 iH;
	std::list<Node*>    lAdj;

private:
	//configurazione scacchiera corrente
	int					configuration[16];
};

#endif /* defined(__AStar__Node__) */
