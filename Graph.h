#ifndef GRAPH_H
#define GRAPH_H

#include <algorithm>
#include <ostream>
#include <set>
#include <string>

#include "Contact.h"

class Graph {
private:
  const unsigned int m_bracketSize = 100;

public:
  Graph() : Graph(25){};
  Graph(unsigned int bracketSize) : m_bracketSize(bracketSize){};

  std::ostream &header(std::ostream &) const;
  std::ostream &
  graphContacts(std::ostream &,
                const std::multiset<Contact, std::greater<Contact>> &) const;

  std::ostream &
  draw(std::ostream &,
       const std::multiset<Contact, std::greater<Contact>> &) const;
};

#endif // GRAPH_H
