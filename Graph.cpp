#include "Graph.h"

std::ostream &Graph::header(std::ostream &os) const {
  unsigned int offset = 0;
  for (unsigned int degree = 0; degree < 360; degree += 2) {
    unsigned int offsetDegree = (degree + 180) % 360;
    std::string textDegree = std::to_string(offsetDegree);
    if (offsetDegree % 45 == 0) {
      os << textDegree;
      offset += textDegree.length() - 1;
    } else if (offset == 0)
      os << " ";
    else
      offset -= 1;
  }
  os << 180;
  return os;
}

std::ostream &Graph::graphContacts(
    std::ostream &os,
    const std::multiset<Contact, std::greater<Contact>> &contacts) const {
  for (unsigned int degree = 0; degree < 360; degree += 2) {
    bool hasShip = false;
    for (const Contact &contact : contacts)
      if ((degree + 180) % 360 == contact.getAngle()) {
        hasShip = true;
        os << "X";
      }
    if (!hasShip)
      os << "-";
  }
  return os;
}

std::ostream &Graph::draw(
    std::ostream &os,
    const std::multiset<Contact, std::greater<Contact>> &contacts) const {
  this->header(os) << std::endl;
  unsigned int currentBracket = 0;
  for (const Contact &contact : contacts)
    if (contact.getTravelTime() > currentBracket)
      currentBracket = contact.getTravelTime();
  currentBracket = ((currentBracket + 99) / 100) * 100;
  while (currentBracket > 0) {
    std::multiset<Contact, std::greater<Contact>> bracketContacts;
    for (const Contact &contact : contacts)
      if (contact.getTravelTime() <= currentBracket)
        bracketContacts.emplace(contact);
    this->graphContacts(os, bracketContacts);
    os << std::endl;
    currentBracket -= this->m_bracketSize;
  }
  return os;
}
