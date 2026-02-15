#include "CelestialBody.hpp"
#include <cmath>

CelestialBody::CelestialBody(const std::string& name, double mass_kg, double radius_km)
{
    this->name = name;
    this->mass_kg = mass_kg;
    this->radius_km = radius_km;
}

CelestialBody::~CelestialBody() {}

double CelestialBody::density() const {
    double volume = (4.0/3.0) * M_PI * pow(radius_km * 1000, 3);
    return mass_kg / volume;
}
