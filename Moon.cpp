#include "Moon.hpp"
#include <sstream>

Moon::Moon(const std::string& name, double mass_kg, double radius_km,
           std::shared_ptr<Planet> parent, int yearDiscovered)
    : CelestialBody(name, mass_kg, radius_km),
      parentPlanet(parent),
      yearDiscovered(yearDiscovered) {}

std::string Moon::description() const {
    std::ostringstream oss;
    oss << "Спутник " << name << " планеты " << parentPlanet->getName()
        << ", масса " << mass_kg << " кг"
        << ", радиус " << radius_km << " км";
    if (yearDiscovered > 0) {
        oss << ", открыт в " << yearDiscovered << " г.";
    }
    return oss.str();
}

double Moon::relativeSizeToParent() const {
    if (parentPlanet && parentPlanet->getRadius() > 0) {
        return radius_km / parentPlanet->getRadius();
    }
    return 0;
}
