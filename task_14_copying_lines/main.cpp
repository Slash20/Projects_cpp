//#include <iostream>
//
//
//class MyString {
//private:
//	char* str;
//
//public:
//	
//	MyString(char *str) {
//		int lenght = strlen(str);
//		this->str = new char[lenght + 1];
//
//		for (int i = 0; i < lenght; i++) {
//			this->str[i] = str[i];
//		}
//
//		this->str[lenght] = '\0';
//	}
//	
//	
//
//	// Конструктор копирования
//	MyString(const MyString& other) {
//		int lenght = strlen(other.str);
//		this->str = new char[lenght + 1];
//
//		for (int i = 0; i < lenght; ++i) {
//			this->str[i] = other.str[i];
//		}
//
//		this->str[lenght] = '\0';
//	}
//
//	// Оператор присваивания копирования
//	MyString& operator=(const MyString& other) {
//		if (this->str = nullptr) {
//			delete[] str;
//		}
//
//		int lenght = strlen(other.str);
//		this->str = new char[lenght + 1];
//
//		for (int i = 0; i < lenght; ++i) {
//			this->str[i] = other.str[i];
//		}
//
//		this->str[lenght] = '\0';
//
//		return *this;
//
//	}
//
//	~MyString() {
//		delete[] str;
//	}
//
//	char* getString() {
//		return str;
//	}
//
//};
//
//int main()
//{
//	MyString str("TESTABC");
//
//	str.getString();
//
//	return 0;
//}


#include <iostream>

class MyString {
private:
    char* str; 
    int length; 

public:

    // Консутруктор 
    MyString(char* s = "") {
        length = 0;
        while (s[length] != '\0') {
            length++;
        }
        str = new char[length + 1];
        for (int i = 0; i < length; ++i) {
            str[i] = s[i];
        }
        str[length] = '\0';
    }

    // Конструктор копирования
    MyString(MyString& other) {
        length = other.length;
        str = new char[length + 1];
        for (int i = 0; i < length; ++i) {
            str[i] = other.str[i];
        }
        str[length] = '\0';
    }

    // Оператор присваивания копированием
    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            for (int i = 0; i < length; ++i) {
                str[i] = other.str[i];
            }
            str[length] = '\0';
        }
        return *this;
    }

    // Деструктор 
    ~MyString() {
        delete[] str;
    }

    char* getString() {
        return str;
    }

    unsigned int getLength() {
        return length;
    }
};

int main() {
    MyString str1("TESTABC");
    MyString str2(str1);
    MyString str3 = str2; 
    MyString str4;
    str4 = str3; 

    std::cout << "str1: " << str1.getString() << ", length: " << str1.getLength() << std::endl;
    std::cout << "str2: " << str2.getString() << ", length: " << str2.getLength() << std::endl;
    std::cout << "str3: " << str3.getString() << ", length: " << str3.getLength() << std::endl;
    std::cout << "str4: " << str4.getString() << ", length: " << str4.getLength() << std::endl;

    return 0;
}

