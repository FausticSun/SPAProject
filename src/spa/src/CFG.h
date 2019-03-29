#pragma once
#include "Table.h"
#include <map>

class CFG {
private:
  // Map from original line number to compressed node index
  std::map<int, int> initialToCompressed;
  // Map from compressed node index to original line number
  std::map<int, std::vector<int>> compressedToInitial;
  std::vector<std::vector<int>> initialGraph;
  std::vector<std::vector<int>> forwardCompressedGraph;
  std::vector<std::vector<int>> reverseCompressedGraph;
  int numCompressedNodes = 0;

  void populateInitialToCompressed(int, Table, std::vector<int>);
  void populateCompressedToInitial();
  void populateCompressedGraph(Table);
  std::vector<int> traverseCFG(int, bool) const;
  std::vector<int> getAffectsVector(int, bool, std::string) const;

public:
  CFG();
  CFG(Table, Table, Table, int);
  Table getNextT() const;
  Table getNextT(int, bool) const;
  Table getAffects() const;
  Table getAffects(int, int) const;
  Table getAffects(int, bool) const;
};
