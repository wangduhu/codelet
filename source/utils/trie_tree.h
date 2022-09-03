#ifndef _TRIE_TREE_H_
#define _TRIE_TREE_H_

#include <vector>

#define TRIE_MAX_CHAR_NUM 26

struct TrieNode {
    TrieNode* children[TRIE_MAX_CHAR_NUM];
    bool is_end;
    TrieNode() : is_end(false) {
        for (int i = 0; i < TRIE_MAX_CHAR_NUM; i++) children[i] = nullptr;
    }
};


class TrieTree {
public:
    TrieTree() {}
    ~TrieTree() {
        for (auto node : nodes) delete node;
    }

    void insert(const char* word) {
        TrieNode* ptr = root();
        while (*word) {
            int pos = *word - 'a';
            if (ptr->children[pos] == nullptr) {
                ptr->children[pos] = new_node();
            }
            ptr = ptr->children[pos];
            word++;
        }
        ptr->is_end = true;
    }

    bool search(const char* word) {
        TrieNode* ptr = root();
        while (*word) {
            int pos = *word - 'a';
            if (ptr->children[pos] == nullptr) return false;
            ptr = ptr->children[pos];
            word++;
        }
        return ptr->is_end;
    }

    bool startsWith(const char* prefix) {
        TrieNode* ptr = root();
        while (*prefix) {
            int pos = *prefix - 'a';
            if (ptr->children[pos] == nullptr) return false;
            ptr = ptr->children[pos];
            prefix++;
        }
        return true;
    }

    TrieNode* root() {
        return &_root;
    }

private:
    TrieNode* new_node() {
        TrieNode* node = new TrieNode();
        nodes.push_back(node);
        return node;
    }

    std::vector<TrieNode*> nodes;
    TrieNode _root;
};

#endif
