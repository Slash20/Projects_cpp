#ifndef FUNC_HPP
#define FUNC_HPP

#include <string>

namespace TimeLogger {

    // ������� ��� ��������� �������� ���������� ������� � ������� ������
    std::string getCurrentTime();

    // ������� ��� ������ ������� ������� ��������� � ����
    void logStartTime(const std::string& filePath);

}

#endif
