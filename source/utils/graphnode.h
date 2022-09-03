#ifndef _GRAPHNODE_H_
#define _GRAPHNODE_H_

#include <vector>

struct GraphNode {
    int label;
    std::vector<GraphNode*> neighbors;
    GraphNode(int x): label(x) {}
};

#endif
