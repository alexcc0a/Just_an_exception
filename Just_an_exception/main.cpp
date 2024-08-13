//
//  main.cpp
//  Just_an_exception
//
//  Created by Александр Нестеров on 13/8/24.
//


#include <iostream>
#include <string>
#include <stdexcept>

class bad_length : public std::exception {
public:
    const char* what() const noexcept override {
        return "Вы ввели строку запретной длины!";
    }
};

int function(const std::string& str, int forbidden_length) {
    if (str.length() == forbidden_length) {
        throw bad_length();
    }
    return str.length();
}

int main() {
    int forbidden_length;
    std::cout << "Введите запретную длину: ";
    std::cin >> forbidden_length;
    std::string word;
    
    while (true) {
        std::cout << "Введите слово: ";
        std::cin >> word;

        try {
            int length = function(word, forbidden_length);
            std::cout << "Длина слова \"" << word << "\" равна " << length << std::endl;
        } catch (const bad_length& e) {
            std::cout << e.what() << " До свидания." << std::endl;
            break;
        }
    }
    return 0;
}

