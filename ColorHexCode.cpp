#include <iostream>
#include <string>

//Write a class called "Color" that uses an enum class to represent different colors (e.g. red, green, blue).
//The class should have a function called "getHexCode()" that returns the hexadecimal code for the color (e.g. #FF0000 for red).
enum class Color {
    RED,
    GREEN,
    BLUE
};

class ColorUtils {
public:
    static std::string getHexCode(Color color) {
        switch (color) {
            case Color::RED:
                return "#FF0000";
            case Color::GREEN:
                return "#00FF00";
            case Color::BLUE:
                return "#0000FF";
            default:
                return "#000000";
        }
    }
};

int main() {
    Color color = Color::RED;
    std::cout << ColorUtils::getHexCode(color) << std::endl;
}
