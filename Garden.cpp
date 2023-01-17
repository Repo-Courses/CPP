#include <numeric>
#include <string>
#include <iostream>
#include <vector>

enum class Color {
    RED,
    GREEN,
    BLUE
};

class Flower {
public:
    Flower(std::string t, Color c) : type(t), color(c) {}
    std::string type;
    Color color;
};


class Garden {
public:
    void addFlower(const std::string type, Color color) {
        flowers.emplace_back(type, color);
    }

    /*
     * In this case, since we're only reading the type attribute of each Flower object and comparing it to the passed type parameter,
     * it doesn't matter whether we use [=] or [&] in the capture list.
     * However, if you were to modify the content of flower inside the lambda function you should use [&] to reflect the changes on the original object.
     */
    int getFlowerCount(std::string type) {
        return std::count_if(flowers.begin(), flowers.end(), [=](Flower flower) { return flower.type == type; });
    }

    // Raw for loop kullanacagin yerde for_each tercih edebilirsin.
    // Remember that A raw for loop also allows you to change the contents of the container, whereas std::for_each can only access the contents of the container and cannot change it.
    std::vector<Color> getFlowerColors(const std::string& type) {
        std::vector<Color> colors;
        std::for_each(flowers.begin(), flowers.end(), [&](Flower flower){ if(flower.type == type) colors.push_back(flower.color); });
        return colors;
    }

    void removeFlowers(const std::string& type, const Color& color) {
        flowers.erase(std::remove_if(flowers.begin(), flowers.end(),
                                     [&](Flower flower) { return (flower.type == type && flower.color == color); }), flowers.end());
    }

    void sortByType() {
        std::sort(flowers.begin(), flowers.end(), [](const Flower& a, Flower& b) {return a.type < b.type;});
    }

    void sortByColor() {
        std::sort(flowers.begin(), flowers.end(), [](const Flower& a, Flower& b) {return a.color < b.color;});
    }

    std::vector<Flower> flowers;
};

void printFlower(Flower flower);

int main() {

    Garden garden;
    garden.addFlower("Rose", Color::RED);
    garden.addFlower("Rose", Color::RED);
    garden.addFlower("Rose", Color::BLUE);
    garden.addFlower("Lily", Color::GREEN);

    std::cout << "Number of Roses: " << garden.getFlowerCount("Rose") << std::endl;

    std::vector<Color> roseColors = garden.getFlowerColors("Rose");
    std::cout << "Colors of Roses: ";
    for (const auto color : roseColors) {
        switch(color){
            case Color::RED:
                std::cout << "RED" << ", ";
                break;
            case Color::GREEN:
                std::cout << "GREEN" << ", ";
                break;
            case Color::BLUE:
                std::cout << "BLUE" << ", ";
                break;
        }
    }
    std::cout << std::endl;

    garden.removeFlowers("Rose", Color::RED);
    std::cout << "Number of Roses after removing red roses: " << garden.getFlowerCount("Rose") << std::endl;

    garden.sortByType();
    std::cout << "Sorted flowers by type: " << std::endl;
    for  (auto flower : garden.flowers) {
        printFlower(flower);
    }
    garden.sortByColor();
    std::cout << "Sorted flowers by color: " << std::endl;
    for (const auto flower : garden.flowers) {
        printFlower(flower);
    }


    return 0;
}

void printFlower(Flower flower) {
    std::cout << "Type: " << flower.type << ", Color: ";
    switch(flower.color){
        case Color::RED:
            std::cout << "RED" << std::endl;
            break;
        case Color::GREEN:
            std::cout << "GREEN" << std::endl;
            break;
        case Color::BLUE:
            std::cout << "BLUE" << std::endl;
            break;
    }
}
