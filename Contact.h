#ifndef CONTACT_H
#define CONTACT_H

#include <ostream>
#include <vector>

class Contact {
private:
  unsigned int m_travelTime;
  unsigned int m_angle;

public:
  Contact(unsigned int travelTime, unsigned int angle)
      : m_travelTime(travelTime),
        m_angle(angle % 2 ? (angle + 1) % 360 : angle) {}

  Contact(const Contact &other)
      : m_travelTime(other.getTravelTime()), m_angle(other.getAngle()){};

  unsigned int getTravelTime() const { return this->m_travelTime; }
  unsigned int getAngle() const { return this->m_angle; }
};

inline std::ostream &operator<<(std::ostream &os, Contact const &c) {
  return os << "Contact=(travelTime=" << c.getTravelTime()
            << ", angle=" << c.getAngle() << "º)";
}

inline bool operator<(const Contact &self, const Contact &other) {
  if (self.getTravelTime() == other.getTravelTime())
    return self.getAngle() < other.getAngle();
  return self.getTravelTime() < other.getTravelTime();
}

inline bool operator>(const Contact &self, const Contact &other) {
  return !(self < other);
}

#endif // CONTACT_H
