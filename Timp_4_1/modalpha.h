/**
 * @file modalpha.h
 * @brief Описание класса modAlphaCipher
 * @author Еремян М.Т.
 * @version 1.0
 * @date 20/04/22
 * @copyright ИБСТ ПГУ
 */
#pragma once
#include <vector>
#include <locale>
#include <string>
#include <map>
#include <cctype>
#include <stdexcept>
using namespace std;

/** @class modAlphaCipher
 *  @brief Класс, реализующий модуль шифрования русскоязычных сообщений методом "Гронсвельда".
 */
class modAlphaCipher
{
/// @brief закрытая секция класса modAlphaCipher
private:
    /// @brief Русский алфавит по порядку, используемый для сообщений
    wstring numAlpha =L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; //алфавит по порядку
    /// @brief Ассоциативный массив "номер по символу"
    map <char,int> alphaNum; //ассоциативный массив "номер по символу"
    /// @brief атрибут ключа
    vector <int> key; //ключ
    /** @brief метод класса, преобразовывающий строку в числовой вектор
    *  @details исходная строка посимвольно перебирается и в вектор result записывается индекс символа типа int в зависимости от его позиции в алфавите "numAlpha"
    * @return метод возвращает, в котором хранятся индексы алфавита "numAlpha" из строки
    */
    vector<int> convert(const wstring& s); //преобразование строка-вектор
    /** @brief метод, преобразовывающий числовой вектор обратно в строку
     * @details в строку типа wstring записывается, сформированная из индексов алфавита "numAlpha"
     */
    wstring convert(const vector<int>& v); //преобразование вектор-строка
    /** @brief Проверка на валидацию ключа.
     * @details Происходит проверка на пустоту ключа и на корректность введённых данных при помощи условий.
     * @details Если хотя бы одно условие не выполняется, то возбуждается исключение throw cipher_error.
     * @return Метод возвращает значение ключа типа wstring, прошедшее обе проверки.
     */
    wstring getValidKey(const wstring& s);
    /** @brief Проверка валидации введённого пользователем сообщения
     * @details Происходит проверка валилации текста шифрования и расшифрования на пустоту строки и на корректность введённых данных при помощи условий.
     * @details если хотя бы одно условие не выполняется, то возбуждается исключение throw cipher_error.
     * @return Метод возвращает значение текста шифрования/расшифрования типа wstring, прошедшее обе проверки.
     */
    wstring getValidText(const wstring & s);
/// @brief открытая секция класса modAlphaCipher
public:
/// @brief Конструктор, запрещающий объявление объектов класса без параметров.
    modAlphaCipher()=delete; //запретим конструктор без параметров
    /** @brief Конструктор для установки ключ шифрования/расшифрования
     * @param const wstring& skey - ключ в виде строки
     * @details Конструктор хранит ключ в виде числового вектора.
     */
    modAlphaCipher(const wstring& skey); //конструктор для установки ключа
    /** @brief Метод, предназначенный для шифрования текста.
     * @details Формируется числовой вектор work из исходной строки с помощью метода convert.
     * @details (Затем каждый элемент вектора work складывается с ключом) по модулю alphanum.size().
     * @return Метод возвращает зашифрованное сообщение типа wstring.
     */
    wstring encrypt(const wstring& open_text);  //зашифрование
    /** @brief Метод, предназначенный для расшифрования текста.
     * @details Формируется числовой вектор work из зашифрованной строки с помощью метода convert.
     * @details (Затем каждый элемент вектора work складывается с модулем alphanum.size(), вычитается ключ) по модулю alphanum.size().
     * @return Метод возращает расшифрованное сообщение типа wstring.
     */
    wstring decrypt(const wstring& cipher_text); //расшифрование
};
/** @class cipher_error
 * @brief Класс для возбуждения и обработки исключений, которые могут возникнуть при взаимодействии с программой.
 * @details Класс "cipher_error" был унаследован от класса "invalid_argument" из библиотеки <stdexcept>
 */
class cipher_error: public std::invalid_argument
{
public:
    explicit cipher_error (const std::string& what_arg):
        std::invalid_argument(what_arg) {}
    explicit cipher_error (const char* what_arg):
        std::invalid_argument(what_arg) {}

};
