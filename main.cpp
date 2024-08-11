#include <functional>
#include <iostream>
#include <sys/types.h>

#include "Contact.h"
#include "Graph.h"
#include "Ship.h"

void coordinatesTest() {
  std::vector<Ship> ocean;
  Ship myShip;

  ocean.push_back(myShip);
  ocean.push_back(Ship(100, 0));
  ocean.push_back(Ship(0, 100));
  ocean.push_back(Ship(-100, 0));
  ocean.push_back(Ship(0, -100));
  ocean.push_back(Ship(100, 100));
  ocean.push_back(Ship(-100, 100));
  ocean.push_back(Ship(-100, -100));
  ocean.push_back(Ship(100, -100));

  std::multiset<Contact, std::greater<Contact>> contacts = myShip.listen(ocean);
  const Graph graph;
  graph.draw(std::cout, contacts) << std::endl;

  for (const Contact &contact : contacts)
    std::cout << contact << std::endl;
}

// FIXME: Sth wrong here
void movingTest() {
  std::vector<Ship> ocean;
  const Graph graph;

  ocean.emplace_back(Ship());
  ocean.emplace_back(Ship(100, 0));

  graph.header(std::cout) << std::endl;
  for (unsigned int i = 0; i < 1000; i++) {
    ocean[1].move(10);
    if (i % 10 == 0) {
      ocean[1].rotate(Rotation::RIGHT);
    }
    if (i % 10 == 0) {
      std::multiset<Contact, std::greater<Contact>> contacts =
          ocean[0].listen(ocean);
      graph.graphContacts(std::cout, contacts) << std::endl;
    }
  }
}

int main(int argc, char **argv) {
  movingTest();
  return 0;
}
