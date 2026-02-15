#include "Moon.hpp"
#include <string>

Moon::Moon(const std::string& name, double mass_kg, double radius_km,
           Planet* parent, int yearDiscovered) {
    this->name = name;
    this->mass_kg = mass_kg;
    this->radius_km = radius_km;
    this->parentPlanet = parent;
    this->yearDiscovered = yearDiscovered;
}

std::string Moon::description() const {
    std::string result = "Спутник " + name + " планеты " +
                         (parentPlanet ? parentPlanet->getName() : "неизвестно") +
                         ", масса " + std::to_string(mass_kg) + " кг" +
                         ", радиус " + std::to_string(radius_km) + " км";

    if (yearDiscovered > 0) {
        result += ", открыт в " + std::to_string(yearDiscovered) + " г.";
    }

    return result;
}

double Moon::relativeSizeToParent() const {
    if (parentPlanet && parentPlanet->getRadius() > 0) {
        return radius_km / parentPlanet->getRadius();
    }
    return 0;
}
