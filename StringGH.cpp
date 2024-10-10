// #include <iomanip>
// #include <cstring>
// #include <cassert>
// #include "StringGH.h"

// StringGH::StringGH(const char *arg = "") : m_length{std::strlen(arg)}
// {
//     setString(arg);
// }

// StringGH::StringGH(const StringGH &arg) : m_length{std::strlen(arg.m_stringPtr)}
// {
//     setString(arg.m_stringPtr);
// }

// StringGH::~StringGH()
// {
//     delete m_stringPtr;
// }

// void StringGH::setString(const char *original)
// {
//     m_stringPtr = new char[m_length];
//     assert(m_stringPtr != nullptr);
//     std::strcpy(m_stringPtr, original);
// }

// const StringGH &StringGH::operator=(const StringGH &right)
// {
//     if (&right != this)
//     {
//         delete[] m_stringPtr;
//         m_length = right.m_length;
//         setString(right.m_stringPtr);
//     }

//     return *this;
// }

// const StringGH &StringGH::operator+=(const StringGH &right)
// {
//     char *temp = m_stringPtr;
//     m_length += right.m_length;
//     m_stringPtr = new char[m_length + 1];

//     assert(m_stringPtr != 0);

//     std::strcpy(m_stringPtr, temp);
//     std::strcat(m_stringPtr, right.m_stringPtr);
//     delete[] temp;
//     return *this;
// }

// bool StringGH::operator!() const
// {
//     return m_length == 0;
// }

// bool StringGH::operator==(const StringGH &right) const
// {
//     return std::strcmp(m_stringPtr, right.m_stringPtr) == 0;
// }

// bool StringGH::operator<(const StringGH &right) const
// {
//     return std::strcmp(m_stringPtr, right.m_stringPtr) < 0;
// }

// bool StringGH::operator!=(const StringGH &right) const
// {
//     return !(*this == right);
// }

// bool StringGH::operator>(const StringGH &right) const
// {
//     return right < *this;
// }

// bool StringGH::operator<=(const StringGH &right) const
// {
//     return !(right < *this);
// }

// bool StringGH::operator>=(const StringGH &right) const
// {
//     return !(*this < right);
// }

// char &StringGH::operator[](int index)
// {
//     assert(index >= 0 && index < m_length);
//     return m_stringPtr[index];
// }

// const char &StringGH::operator[](int index) const
// {
//     assert(index >= 0 && index < m_length);
//     return m_stringPtr[index];
// }

// StringGH StringGH::operator()(int from, int to)
// {
//     assert(from >= 0 && from < m_length && to >= 0);

//     int len;
//     if ((to == 0) || (from + to > m_length))
//         len = m_length - from;
//     else
//         len = to;

//     char *temp = new char[len + 1];
//     assert(temp != nullptr);
//     std::strncpy(temp, &m_stringPtr[from], len);
//     temp[len] = '\0';
//     StringGH tempStr(temp);
//     delete[] temp;

//     return tempStr;
// }

// int StringGH::getLength() const
// {
//     return m_length;
// }