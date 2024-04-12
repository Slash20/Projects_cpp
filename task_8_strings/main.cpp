// Вариант 4.
// Подзадача 1.
// Дан файл, содержащий русский текст. Найти в тексте N<=2000 самых длинных слов,
// в которых согласные буквы упорядочены
// по алфавиту. Записать найденные слова в текстовый файл в порядке невозрастания длины.
// Все найденные слова должны быть разными!

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>


//bool isConsonant(char c) {
//    const std::string consonants = "бвгджзйклмнпрстфхцчшщ";
//    return consonants.find(tolower(c)) != std::string::npos;
//}
//
//
//bool consonantsOrdered(const std::string& word) {
//    for (size_t i = 0; i < word.length() - 1; ++i) {
//        if (!(tolower(word[i]) <= tolower(word[i + 1]) && isConsonant(word[i]) && isConsonant(word[i + 1])))
//            return false;
//    }
//    return true;
//}
//
//
//struct WordInfo {
//    std::string word;
//    size_t length;
//};
//
//bool compareByLength(const WordInfo& a, const WordInfo& b) {
//    return a.length > b.length;
//}
//
//int main() {
//    std::ifstream in("input.txt");
//    std::ofstream out("output.txt");
//
//    if (!in.is_open() || !out.is_open()) {
//        std::cerr << "Не найден файл" << std::endl;
//        return 1;
//    }
//
//    std::vector<WordInfo> words;
//    std::string word;
//
//    while (in >> word) {
//        if (consonantsOrdered(word)) {
//            words.push_back({word, word.length()});
//        }
//    }
//
//    std::sort(words.begin(), words.end(), compareByLength);
//
//    int N = std::min(2000, static_cast<int>(words.size()));
//    for (int i = 0; i < N; ++i) {
//        out << words[i].word << std::endl;
//    }
//
//    in.close();
//    out.close();
//
//    return 0;
//}


// Подзадача 2.
// Дана строка, содержащая русский текст.
// Вывести в алфавитном порядке слова текста,
// содержащие не более 3-х согласных,
// в остальных словах удалить гласные и продублировать согласные буквы.


//const int max_words = 100;
//
//std::string words[max_words];
//int words_cnt = 0;
//
//int vowels3_to_word[max_words];
//int vowels3_size = 0;
//
//int others[max_words];
//int others_size = 0;
//
//bool is_vowel(char c) {
//    char vowels[10] = { 'а', 'у', 'о', 'ы', 'и', 'э', 'я', 'ю', 'ё', 'е' };
//    c = std::tolower(c);
//    for (int i = 0; i < 10; i++)
//    {
//        if (c == vowels[i])
//            return true;
//    }
//    return false;
//}
//
//bool is_consonant(char c) {
//    const char* consonants = "бвгджзйклмнпрстфхцчшщ";
//    c = std::tolower(c);
//    for (int i = 0; i < strlen(consonants); i++)
//    {
//        if (c == consonants[i])
//            return true;
//    }
//    return false;
//}
//
//int count_vowels(const std::string& word) {
//    int cnt = 0;
//    for (auto c: word) {
//        if (is_vowel(c))
//            cnt++;
//    }
//    return cnt;
//}
//
//std::string word_to_lowercase(const std::string& word) {
//    auto result = word;
//    std::transform(result.begin(), result.end(), result.begin(),
//                   [](unsigned char c) { return std::tolower(c); });
//    return result;
//}
//
//int main()
//{
//    system("chccp 65001");
//
//    std::ifstream in("input.txt", std::ios::in);
//    std::ofstream out("output.txt", std::ios::out);
//
//    std::string str;
//
//    int i = 0;
//    while (!in.eof()) {
//        in >> words[i];
//        int vowels_cnt = count_vowels(words[i]);
//        if (vowels_cnt >= 3) {
//            vowels3_to_word[vowels3_size] = i;
//            vowels3_size++;
//        }
//        else {
//            others[others_size] = i;
//            others_size++;
//        }
//        i++;
//    }
//    words_cnt = i;
//    in.close();
//
//    for (int i = 1; i < vowels3_size; ++i)
//    {
//        for (int j = 0; j < vowels3_size - 1; j++)
//        {
//            int left =vowels3_to_word[j];
//            int right = vowels3_to_word[j + 1];
//            if (word_to_lowercase(words[left]) < word_to_lowercase(words[right]))
//            {
//                std::swap(words[left], words[right]);
//            }
//        }
//    }
//
//    for (int i = 0; i < vowels3_size; i++)
//    {
//        out << words[vowels3_to_word[i]] << std::endl;
//    }
//    out << "Остальные слова:\n";
//    for (int i = 0; i < others_size; i++)
//    {
//        out << words[others[i]] << " ";
//    }
//    out.close();
//
//}


// Подзадча 3.

const std::string letters = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
int letters_cnts[33] = { 0 };

const int rating_size = 8;
std::vector<int> frequent_letters;

char to_lower_case(char c) {
    if (c <= 'Я' && c >= 'А')
        c += std::abs('Я' - 'я');
    if (c == 'Ё')
        c += 16;
    return c;
}

bool is_letter(char c) {
    return c >= 'А' && c <= 'я' || c >= 'а' && c <= 'я' || c == 'Ё' || c == 'ё';
}


int main()
{
    auto cc = 'a';
    std::cout << cc << " " << sizeof('a') << std::endl;

    system("chcp 65001");

    std::ifstream in("input.txt", std::ios::in);

    char c;
    while (in.get(c)) {
        if (is_letter(c)) {
            c = to_lower_case(c);
            for (int i = 0; i < letters.size(); i++)
            {
                if (letters[i] == c) {
                    letters_cnts[i]++;
                }
            }
        }
    }
    in.close();

    // заполняем список самых часто встречающщихся букв
    for (int i = 0; i < letters.size(); i++) {
        int cnt = letters_cnts[i];

        if (cnt == 0) { // пропускаем если символа в тексте нет
            continue;
        }
        if (frequent_letters.empty()) {
            frequent_letters.push_back(i);
            continue;
        }

        int position = 0;
        while (position < frequent_letters.size())
        {
            int letter_id = frequent_letters[position];
            if (cnt > letters_cnts[letter_id]) {
                break;
            }
            position++;
        }
        if (position < frequent_letters.size() || position < rating_size) {
            frequent_letters.insert(frequent_letters.begin() + position, i);
            if (frequent_letters.size() > rating_size) {
                frequent_letters.resize(rating_size);
            }
        }
    }

    for (int i = 0; i < frequent_letters.size(); i++)
    {
        std::cout << "raiting_num" << i << std::endl;
        int letter_id = frequent_letters[i];
        std::cout << letters[letter_id] << " " << letters_cnts[letter_id] << std::endl;
    }

    // Теперь у нас есть рейтинг 8 самых свтречаемых букв

    std::ofstream out("output.txt", std::ios::out);
    std::string word;

    in.open("input.txt", std::ios::in);
    while (!in.eof()) {
        in >> word;

        // Проверяем, подходит ли слово под условие
        std::string word_letters = ""; // быквы в слове из рейтинга
        for (int i = 0; i < word.size(); i++)
        {
            char c = word[i];
            // перебираем буквы из рейтинга
            for (int k = 0; k < frequent_letters.size(); k++)
            {
                int letter_id = frequent_letters[k];
                if (c == letters[letter_id]) {
                    word_letters += c;
                }
            }
        }
        if (word_letters.size() > 5) {
            std::transform(word.begin(), word.end(), word.begin(), ::toupper);
            out << word << "(" << word_letters << ") ";
        }
        else
            out << word << " ";
    }
    in.close();
    out.close();
}
