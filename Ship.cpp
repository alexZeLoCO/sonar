#include "Ship.h"
#include <cmath>
#include <cstdlib>

void Ship::rotate(Rotation rotation) {
  int newDirection = this->m_direction + rotation;
  if (newDirection < 0)
    newDirection += 4;
  this->m_direction = (Direction)(newDirection % 4);
}

void Ship::move() { this->move(1); }

void Ship::move(unsigned int amount) {
  switch (this->m_direction) {
  case (Direction::NORTH):
    this->m_yPosition += amount;
    break;
  case (Direction::EAST):
    this->m_xPosition += amount;
    break;
  case (Direction::SOUTH):
    this->m_yPosition -= amount;
    break;
  case (Direction::WEST):
    this->m_xPosition -= amount;
    break;
  }
}

std::multiset<Contact, std::greater<Contact>> Ship::listen(const std::vector<Ship> &ocean) const {
    std::multiset<Contact, std::greater<Contact>> contacts;
  for (const Ship &ship : ocean) {
    const int xDif = ship.getXPosition() - this->getXPosition();
    const int yDif = ship.getYPosition() - this->getYPosition();
    const double distance = std::sqrt(pow(xDif, 2) + pow(yDif, 2));
    double degAngle;
    if (distance != 0) {
      if (xDif == 0)
        degAngle = yDif < 0 ? 180 : 0;
      else if (yDif == 0)
        degAngle = xDif < 0 ? 270 : 90;
      else {
        const double radAngle = cos((double)xDif / distance);
        degAngle = radAngle * 180 / M_PI;
        if (yDif > 0 && xDif < 0) degAngle += 270;
        if (yDif < 0 && xDif < 0) degAngle += 180;
        if (yDif < 0 && xDif > 0) degAngle += 90;
      }
      contacts.emplace(distance, degAngle);
    }
  }
  return contacts;
}
