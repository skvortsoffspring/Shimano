// прототип функции
// Код возврата: функция возвращает диагностический код
#pragma once
#include <string>

using namespace std;

string GetErrorMsgText(int code);                               // cформировать текст ошибки
string SetErrorMsgText(const std::string& msgText, int code);
