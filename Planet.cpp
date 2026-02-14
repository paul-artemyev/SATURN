#include "Planet.hpp"
#include <sstream>

Planet::Planet(const std::string& name, double mass_kg, double radius_km, bool hasRings)
    : CelestialBody(name, mass_kg, radius_km), hasRings(hasRings) {}

std::string Planet::description() const {
    std::ostringstream oss;
    oss << "Планета " << name
        << ", масса " << mass_kg << " кг"
        << ", радиус " << radius_km << " км"
        << ", " << (hasRings ? "есть кольца" : "нет колец");
    return oss.str();
}
