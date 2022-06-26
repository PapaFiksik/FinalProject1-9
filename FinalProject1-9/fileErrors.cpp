#include "fileErrors.h"

const char* fileErrors::what() const {
    return "Ошибка: не удалось открыть или создать файл!";
}