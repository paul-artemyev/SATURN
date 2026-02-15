#ifndef PLANET_HPP
#define PLANET_HPP


#include "CelestialBody.hpp"

class Planet : public CelestialBody {
private:
    bool hasRings;

public:
    Planet(const std::string& name, double mass_kg, double radius_km, bool hasRings = false);

    std::string description() const;

    bool getHasRings() const { return hasRings; }
};


#endif
