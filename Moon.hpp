#ifndef MOON_HPP
#define MOON_HPP

#include "CelestialBody.hpp"
#include "Planet.hpp"
#include <string>

class Moon : public CelestialBody {
private:
    Planet* parentPlanet;
    int yearDiscovered;

public:
    Moon(const std::string& name, double mass_kg, double radius_km, Planet* parent, int yearDiscovered = 0);

    std::string description() const;

    double relativeSizeToParent() const;

    int getYearDiscovered() const { return yearDiscovered; }
    Planet* getParent() const { return parentPlanet; }
};

#endif
