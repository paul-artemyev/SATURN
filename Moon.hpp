#ifndef MOON_HPP
#define MOON_HPP


#include "CelestialBody.hpp"
#include "Planet.hpp"
#include <memory>

class Moon : public CelestialBody {
private:
    std::shared_ptr<Planet> parentPlanet;
    int yearDiscovered;  // 0 если неизвестно

public:
    Moon(const std::string& name, double mass_kg, double radius_km,
         std::shared_ptr<Planet> parent, int yearDiscovered = 0);

    std::string description() const override;

    double relativeSizeToParent() const;

    int getYearDiscovered() const { return yearDiscovered; }
    std::shared_ptr<Planet> getParent() const { return parentPlanet; }
};


#endif
