#include "key.hpp"

#include <cstring>
#include <iomanip>

Key::Key(const std::string &key)
{
    m_bytes.fill(0);

    char buf[3];

    for (int i = Key::LENGTH - 1, j = key.size() - 1; i >= 0 && j >=0; i--, j--) {
        strcpy(buf, "00");
        buf[1] = key[j];

        if (j > 0) {
            j--;
            buf[0] = key[j];
        }

        m_bytes[i] = strtol(buf, NULL, 16);
    }
}

Key::Key()
{
}

const Key::data_type &Key::bytes() const
{
    return m_bytes;
}

bool Key::operator<(const Key& rhs) const
{
    for (size_t i = 0; i < Key::LENGTH; i++) {
        if (bytes().at(i) > rhs.bytes().at(i)) {
            return false;
        } else if (bytes().at(i) < rhs.bytes().at(i)) {
            return true;
        }
    }

    return false;
}

bool Key::operator>(const Key& rhs) const
{
    return rhs < *this;
}

bool Key::operator<=(const Key& rhs) const
{
    return !(*this > rhs);
}

bool Key::operator>=(const Key& rhs) const
{
    return !(*this < rhs);
}

bool Key::operator==(const Key &rhs) const
{
    for (size_t i = 0; i < Key::LENGTH; i++) {
        if (bytes().at(i) != rhs.bytes().at(i)) {
            return false;
        }
    }

    return true;
}

bool Key::operator!=(const Key &rhs) const
{
    return !(*this == rhs);
}

std::ostream& operator<<(std::ostream& os, const Key &key)
{
    for (unsigned char c : key.bytes()) {
        os << std::setfill('0') << std::setw(2) << std::hex << (int) c;
    }

    return os;
}
