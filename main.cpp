#include <iostream>
#include "Planet.hpp"
#include "Moon.hpp"

int main() {
    Planet saturn("Сатурн", 5.683e26, 58232, true);

    Moon titan("Титан", 1.345e23, 2575, &saturn, 1655);
    Moon rhea("Рея", 2.306e21, 764, &saturn, 1672);
    Moon dione("Диона", 1.095e21, 561, &saturn, 1684);
    Moon tethys("Тефия", 6.174e20, 533, &saturn, 1684);
    Moon enceladus("Энцелад", 1.080e20, 252, &saturn, 1789);
    Moon mimas("Мимас", 3.749e19, 198, &saturn, 1789);
    Moon hyperion("Гиперион", 5.620e18, 135, &saturn, 1848);
    Moon phoebe("Феба", 8.292e18, 107, &saturn, 1899);
    Moon iapetus("Япет", 1.805e21, 734, &saturn, 1671);
    Moon pan("Пан", 4.95e15, 14, &saturn, 1990);

    std::cout << "=== Система Сатурна ===\n\n";
    std::cout << saturn.description() << std::endl;
    std::cout << "Плотность Сатурна: " << saturn.density() << " кг/м³\n\n";

    std::cout << "=== Спутники Сатурна ===\n";
    std::cout << titan.description() << std::endl;
    std::cout << rhea.description() << std::endl;
    std::cout << dione.description() << std::endl;
    std::cout << tethys.description() << std::endl;
    std::cout << enceladus.description() << std::endl;
    std::cout << mimas.description() << std::endl;
    std::cout << hyperion.description() << std::endl;
    std::cout << phoebe.description() << std::endl;
    std::cout << iapetus.description() << std::endl;
    std::cout << pan.description() << std::endl;

    return 0;
}
