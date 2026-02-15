#include "Planet.hpp"
#include <string>

Planet::Planet(const std::string& name, double mass_kg, double radius_km, bool hasRings) {
    this->name = name;
    this->mass_kg = mass_kg;
    this->radius_km = radius_km;
    this->hasRings = hasRings;
}

std::string Planet::description() const {
    return "Планета " + name +
           ", масса " + std::to_string(mass_kg) + " кг" +
           ", радиус " + std::to_string(radius_km) + " км" +
           ", " + (hasRings ? "есть кольца" : "нет колец");
}
