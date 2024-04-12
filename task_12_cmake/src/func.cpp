#include <func.hpp>
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>

namespace TimeLogger {

    std::string getCurrentTime() {
        auto now = std::chrono::system_clock::now();
        std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
        return std::ctime(&currentTime);
    }

    void logStartTime(const std::string& filePath) {
        std::ofstream file(filePath, std::ios::app);
        if (file.is_open()) {
            // Определяем текущий номер запуска
            int currentRunNumber = 0;
            std::ifstream inputFile(filePath);
            if (inputFile.is_open()) {
                std::string line;
                while (std::getline(inputFile, line)) {
                    currentRunNumber++;
                }
                inputFile.close();
            }

            // Записываем в файл информацию о запуске
            file << currentRunNumber + 1 << " " << getCurrentTime();
            file.close();
        }
        else {
            std::cout << "Unable to open file: " << filePath << std::endl;
        }
    }

}
