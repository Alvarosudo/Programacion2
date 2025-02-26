// -*- mode: c++ -*-

// Compilar con --std=c++17 o superior

#ifndef TREE
#define TREE

#include <cstdint>
#include <iostream>
#include <string>
#include <queue>

///////////////////////////////////////////////////////////////////////////////
//                 Typedefs/Using + Declaraciones adelantadas                //
///////////////////////////////////////////////////////////////////////////////
using Element = char; // Hasta que veamos genericidad usaremos estos
                      // typedef.

struct TreeNode;
using  TreeNodePtr = TreeNode*;

struct Tree;
using  TreePtr = Tree*;

///////////////////////////////////////////////////////////////////////////////
//                                    Tree                                   //
///////////////////////////////////////////////////////////////////////////////
struct Tree {
  TreeNodePtr root;
};

TreePtr      treeCreate        ();
void         treeDestroy       (TreePtr t);
TreeNodePtr& treeRoot          (TreePtr t);
bool         treeEmpty         (TreePtr t);
bool         treeInsert        (TreePtr t, Element x);
bool         treeRemove        (TreePtr t, Element x);
void         treeMakeNull      (TreePtr t);
uint32_t     treeSize          (TreePtr t);
uint32_t     treeHeight        (TreePtr t);
uint32_t     treeLeafTreeNodes (TreePtr t);
TreeNodePtr  treeSearch        (TreePtr t, Element x);
TreeNodePtr  treeParent        (TreePtr t, Element x);
TreeNodePtr  treeParent        (TreePtr t, TreeNodePtr p);
TreeNodePtr  treeMaximum       (TreePtr t);
std::string  treePreOrder      (TreePtr t, char c);
std::string  treePostOrder     (TreePtr t, char c);
std::string  treeInOrder       (TreePtr t, char c);
std::string  treeByLevels      (TreePtr t, char c);

///////////////////////////////////////////////////////////////////////////////
//                                  TreeNode                                 //
///////////////////////////////////////////////////////////////////////////////
struct TreeNode {
  Element key;
  Tree lefts, rights;
};

TreeNodePtr  treeNodeCreate        (Element e);
TreePtr      treeNodeLeftSibling   (TreeNodePtr p);
TreePtr      treeNodeRightSibling  (TreeNodePtr p);
Element&     treeNodeKey           (TreeNodePtr p);
bool         treeNodeIsLeaf        (TreeNodePtr p);

[[maybe_unused]]
static std::string  treeNodeToString   (TreeNodePtr p) {
  std::string s;
  return s + p->key;
}

#endif
