#ifndef TRIE_H
#define TRIE_H

#include <stdbool.h>

#define TRIE_SIZE 256

typedef struct Trie
{
    struct Trie* child[TRIE_SIZE];
    bool terminal;
}trie_t;

#endif