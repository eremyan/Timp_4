/**
 * @file RouteTableCipher.h
 * @author Еремян М.Т.
 * @date 20/04/22
 * @version 1.0
 * @brief Шифрование методом табличной маршрутной перестановки
 * @copyright ИБСТ ПГУ
 */
/**
* @brief Подключаемые библиотеки
*/
#pragma once
#include <string>
#include <locale>
#include <stdexcept>
#include <cctype>

using namespace std;
/**
 * @class RouteTableCipher
 * @brief Данный класс реализует шифрование сообщений методом табличной маршрутной перестановки
 * @warning Реализация производится с использованием английского языка 
 */
class RouteTableCipher
{
private:
/// Атрибут класса, хранящий ключ шифрования и расшифрования
    int key;// ключ (число столбцов)
public:
/// Запрет конструктора без параметров
    RouteTableCipher()=delete;
/**
 * @brief Конструктор, выполняющий установку ключа
 * @param skey - ключ в виде целого числа
 * @details Внутри конструктора атрибуту класса присваивается значение входного параметра
 */
    RouteTableCipher(const int& skey); // конструктор для установки ключа
/**
 * @brief Метод, предназначеннный для шифрования сообщений методом маршрутной табличной перестановки
 * @param open_text - открытый текст
 * @param skey - ключ
 * @details Метод формирует таблицу, в каждую ячейку которой записывается символ введённого пользователем сообщения;
 * @details Таблица состоит из количества столбцов, введённого пользователем, количество строк определяется в зависимости от длины сообщения;
 * @details Метод по маршруту записи фиксирует текст в таблице и по маршруту считывания формирует зашифрованное сообщение.
 * @return Метод возвращает зашифрованное сообщение типа string
 */
    string encrypt(string open_text, const int& skey); // метод шифрования
/**
 * @brief Метод, предназначенный для расшифрования сообщений
 * @param cipher_text - зашифрованный текст
 * @param skey - ключ
 * @details Метод формирует таблицу, записывает в каждую ячейку символ зашифрованного сообщения и формирует расшифрованное сообщение.
 * @return Метод возвращает расшифрованное сообщение типа string
 */
    string decrypt(string cipher_text, const int& skey); // метод расшифрования

};
/**
 * @class cipher_error
 * @brief Данный класс нужен для обработки ошибок, которые могут возникнуть в течение работы программы 
 */

class cipher_error: public invalid_argument
{
public:
/**
 * @brief Конструктор принимает на вход строку и возбуждает исключение
 * @param what_arg
 */
    explicit cipher_error (const string& what_arg):
        invalid_argument(what_arg) {}
/**
 * @brief Конструктор принимает на вход си-строку и возбуждает исключение
 * @param what_arg
 */
    explicit cipher_error (const char* what_arg):
        invalid_argument(what_arg) {}
/**
 * @brief Метод, который реализует проерку на валидацию ключа 
 * @param skey
 * @throw cipher_error, если в ключе содержатся недопустимые символы или он является пустым
 */
    static int getValidKey(const string skey);
/**
 * @brief Метод, который реализует проверку на валидацию зашифрованного и расшифрованного текста
 * @param text
 * @throw cipher_error, если в тексте пристуствуют русские буквы или он является пустым
 */
    static int getValidText(const string text);
};