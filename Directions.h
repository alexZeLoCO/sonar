#ifndef DIRECTION_H
#define DIRECTION_H

#include <ostream>

enum Direction { NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3 };

enum Rotation { LEFT = -1, RIGHT = 1 };

inline std::ostream &operator<<(std::ostream &os, Direction const &d) {
  switch (d) {
  case (Direction::NORTH):
    return os << "NORTH";
  case (Direction::EAST):
    return os << "EAST";
  case (Direction::SOUTH):
    return os << "SOUTH";
  case (Direction::WEST):
    return os << "WEST";
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, Rotation const &r) {
  switch (r) {
  case (Rotation::LEFT):
    return os << "LEFT";
  case (Rotation::RIGHT):
    return os << "RIGHT";
  }
  return os;
}

#endif // DIRECTION_H
