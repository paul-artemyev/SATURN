#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <iomanip>
#include "Planet.hpp"
#include "Moon.hpp"

int main() {
    setlocale(LC_ALL, "Russian");

    // Создаём Сатурн
    auto saturn = std::make_shared<Planet>("Сатурн", 5.683e26, 58232, true);

    // Создаём спутники
    std::vector<std::shared_ptr<Moon>> moons;
    moons.push_back(std::make_shared<Moon>("Титан", 1.345e23, 2575, saturn, 1655));
    moons.push_back(std::make_shared<Moon>("Рея", 2.306e21, 764, saturn, 1672));
    moons.push_back(std::make_shared<Moon>("Диона", 1.095e21, 561, saturn, 1684));
    moons.push_back(std::make_shared<Moon>("Тефия", 6.174e20, 533, saturn, 1684));
    moons.push_back(std::make_shared<Moon>("Энцелад", 1.080e20, 252, saturn, 1789));
    moons.push_back(std::make_shared<Moon>("Мимас", 3.749e19, 198, saturn, 1789));
    moons.push_back(std::make_shared<Moon>("Гиперион", 5.620e18, 135, saturn, 1848));
    moons.push_back(std::make_shared<Moon>("Феба", 8.292e18, 107, saturn, 1899));
    moons.push_back(std::make_shared<Moon>("Япет", 1.805e21, 734, saturn, 1671));
    moons.push_back(std::make_shared<Moon>("Пан", 4.95e15, 14, saturn, 1990));

    std::cout << "=== Система Сатурна ===\n\n";
    std::cout << saturn->description() << std::endl;
    std::cout << "Плотность Сатурна: " << std::fixed << std::setprecision(2)
              << saturn->density() << " кг/м³\n\n";

    // Крупнейшие спутники (радиус > 500 км)
    std::cout << "=== Крупнейшие спутники (радиус > 500 км) ===\n";
    for (const auto& moon : moons) {
        if (moon->getRadius() > 500) {
            std::cout << "- " << moon->getName() << " ("
                      << moon->getRadius() << " км)\n";
        }
    }

    // Спутники, открытые до 1800 года
    std::cout << "\n=== Спутники, открытые до 1800 года ===\n";
    for (const auto& moon : moons) {
        if (moon->getYearDiscovered() > 0 && moon->getYearDiscovered() < 1800) {
            std::cout << "- " << moon->getName() << " ("
                      << moon->getYearDiscovered() << ")\n";
        }
    }

    // Относительный размер (Топ-5)
    std::cout << "\n=== Относительный размер (спутник/Сатурн) ===\n";
    std::vector<std::shared_ptr<Moon>> sorted_moons = moons;
    std::sort(sorted_moons.begin(), sorted_moons.end(),
              [](const auto& a, const auto& b) {
                  return a->relativeSizeToParent() > b->relativeSizeToParent();
              });

    for (int i = 0; i < std::min(5, (int)sorted_moons.size()); ++i) {
        std::cout << "- " << sorted_moons[i]->getName() << ": "
                  << std::fixed << std::setprecision(2)
                  << sorted_moons[i]->relativeSizeToParent() * 100 << "%\n";
    }

    return 0;
}
