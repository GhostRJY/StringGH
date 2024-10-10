#pragma once
#include <iomanip>
#include <cstring>
#include <cassert>

// проблема линковки файлов поэтому описываю класс в хедере
class StringGH
{
    friend std::ostream &operator<<(std::ostream &oStream, const StringGH &right)
    {
        oStream << right.m_stringPtr;
        return oStream;
    }

    friend std::istream &operator>>(std::istream &iStream, StringGH &right)
    {
        char temp[100];
        iStream >> std::setw(100) >> temp;
        right = temp;
        return iStream;
    }

private:
    int m_length;
    char *m_stringPtr;

    // вспомогательная фун-ия инициализации строки
    void setString(const char *original);

public:
    // конструктор преобразования
    StringGH(const char *arg = "");

    // конструктор копирования
    StringGH(const StringGH &arg);
    ~StringGH();

    // оператор копирования
    const StringGH &operator=(const StringGH &right);
    const StringGH &operator+=(const StringGH &right);

    // операторы сравнения
    bool operator!() const;
    bool operator==(const StringGH &right) const;
    bool operator<(const StringGH &right) const;

    // операторы сравнения реализованные посредством основных операторов сравнения
    bool operator!=(const StringGH &right) const;
    bool operator>(const StringGH &right) const;
    bool operator<=(const StringGH &right) const;
    bool operator>=(const StringGH &right) const;

    // операторы возврата символа
    char &operator[](int index);
    const char &operator[](int index) const;

    // оператоп возврата подстроки
    StringGH operator()(int from, int to);
    int getLength() const;
};

StringGH::StringGH(const char *arg) : m_length{(int)std::strlen(arg)}
{
    setString(arg);
}

StringGH::StringGH(const StringGH &arg) : m_length{(int)std::strlen(arg.m_stringPtr)}
{
    setString(arg.m_stringPtr);
}

StringGH::~StringGH()
{
    delete m_stringPtr;
}

void StringGH::setString(const char *original)
{
    m_stringPtr = new char[m_length];
    assert(m_stringPtr != nullptr);
    std::strcpy(m_stringPtr, original);
}

const StringGH &StringGH::operator=(const StringGH &right)
{
    if (&right != this)
    {
        delete[] m_stringPtr;
        m_length = right.m_length;
        setString(right.m_stringPtr);
    }

    return *this;
}

const StringGH &StringGH::operator+=(const StringGH &right)
{
    char *temp = m_stringPtr;
    m_length += right.m_length;
    m_stringPtr = new char[m_length + 1];

    assert(m_stringPtr != 0);

    std::strcpy(m_stringPtr, temp);
    std::strcat(m_stringPtr, right.m_stringPtr);
    delete[] temp;
    return *this;
}

bool StringGH::operator!() const
{
    return m_length == 0;
}

bool StringGH::operator==(const StringGH &right) const
{
    return std::strcmp(m_stringPtr, right.m_stringPtr) == 0;
}

bool StringGH::operator<(const StringGH &right) const
{
    return std::strcmp(m_stringPtr, right.m_stringPtr) < 0;
}

bool StringGH::operator!=(const StringGH &right) const
{
    return !(*this == right);
}

bool StringGH::operator>(const StringGH &right) const
{
    return right < *this;
}

bool StringGH::operator<=(const StringGH &right) const
{
    return !(right < *this);
}

bool StringGH::operator>=(const StringGH &right) const
{
    return !(*this < right);
}

char &StringGH::operator[](int index)
{
    assert(index >= 0 && index < m_length);
    return m_stringPtr[index];
}

const char &StringGH::operator[](int index) const
{
    assert(index >= 0 && index < m_length);
    return m_stringPtr[index];
}

StringGH StringGH::operator()(int from, int to)
{
    assert(from >= 0 && from < m_length && to >= 0);

    int len;
    if ((to == 0) || (from + to > m_length))
        len = m_length - from;
    else
        len = to;

    char *temp = new char[len + 1];
    assert(temp != nullptr);
    std::strncpy(temp, &m_stringPtr[from], len);
    temp[len] = '\0';
    StringGH tempStr(temp);
    delete[] temp;

    return tempStr;
}

int StringGH::getLength() const
{
    return m_length;
}