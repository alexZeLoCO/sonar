#ifndef Ship_H
#define Ship_H

#include <ostream>
#include <vector>
#include <set>

#include "Contact.h"
#include "Directions.h"

class Ship {
private:
  int m_xPosition;
  int m_yPosition;
  Direction m_direction;

public:
  Ship() : Ship(0, 0) {}

  Ship(int xPosition, int yPosition)
      : Ship(xPosition, yPosition, Direction::NORTH) {}

  Ship(int xPosition, int yPosition, Direction direction)
      : m_xPosition(xPosition), m_yPosition(yPosition), m_direction(direction) {
  }

  int getXPosition() const { return this->m_xPosition; }
  int getYPosition() const { return this->m_yPosition; }
  Direction getDirection() const { return this->m_direction; }

  void rotate(Rotation);
  void move();
  void move(unsigned int);
  std::multiset<Contact, std::greater<Contact>> listen(const std::vector<Ship> &) const;

  bool operator==(const Ship &);
};

inline std::ostream &operator<<(std::ostream &os, Ship const &ch) {
  return os << "Ship(x=" << ch.getXPosition() << ", y=" << ch.getYPosition()
            << ", direction=" << ch.getDirection() << ")";
}

inline bool Ship::operator==(const Ship &other) {
  return other.getXPosition() == this->getXPosition() &&
         other.getYPosition() == this->getYPosition();
}

#endif // Ship_H
