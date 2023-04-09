#include <iostream>
#include <string>

double check_double_try() {
    std::string str = "";
    bool state = true;
    double test;
    std::size_t pos{};

    std::cout << "Enter the double: ";

    while (state) {
        getline(std::cin, str);

        try {
            test = stod(str, &pos);

            if (pos != str.size()) {
                throw std::invalid_argument("Argument is invalid\n");
            }
            state = false;
        }
        catch (const std::invalid_argument &) {
            std::cout << "Argument is invalid\n";
        }
    }
    return test;
}

double check_double_cin() {
    long double number;
    bool state = true;

    std::cout << "Enter the double: ";

    while (state) {
        std::cin >> number;

        if (std::cin.fail() || std::cin.bad()|| std::cin.peek() != '\n') {
            std::cout << "Incorrect vector size, please enter another one: ";
            std::cin.clear(); // Возвращение потока ввода в начальное состояние
            std::cin.ignore(32767, '\n'); // Очистка потока ввода
        } else
            state = false;
    }
    return number;
}

double check_double_getline() {
    std::string str = "";
    bool state = true;

    std::cout << "Enter the double: ";

    while (state) {
        getline(std::cin, str);

        if (str.find_first_not_of("-.1234567890") != -1 || (str.empty())) {
            std::cout << "You entered the wrong value. Enter it again: " << std::endl;
        } else
            state = false;
    }
    return stod(str);
}

int main(){
    double x= check_double_getline();
    return 0;
}