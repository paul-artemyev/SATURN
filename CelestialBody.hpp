#ifndef CELESTIAL_BODY_HPP
#define CELESTIAL_BODY_HPP


#include <string>

class CelestialBody {
protected:
    std::string name;
    double mass_kg;
    double radius_km;

public:
    CelestialBody() = default;
    CelestialBody(const std::string& name, double mass_kg, double radius_km);
    virtual ~CelestialBody();

    virtual std::string description() const = 0;

    virtual double density() const;

    std::string getName() const { return name; }
    double getMass() const { return mass_kg; }
    double getRadius() const { return radius_km; }
};


#endif
