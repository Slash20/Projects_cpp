#ifndef FUNC_HPP
#define FUNC_HPP

#include <string>

namespace TimeLogger {

    // Функция для получения текущего системного времени в формате строки
    std::string getCurrentTime();

    // Функция для записи времени запуска программы в файл
    void logStartTime(const std::string& filePath);

}

#endif
