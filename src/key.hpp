#ifndef KEY_HPP
#define KEY_HPP

#include <iostream>
#include <string>
#include <array>


class Key
{
public:
    static const size_t LENGTH = 20;
    typedef std::array<unsigned char, Key::LENGTH> data_type;

    Key(const std::string &key);
    Key();

    const data_type &bytes() const;

    bool operator<(const Key& rhs) const;
    bool operator>(const Key& rhs) const;
    bool operator<=(const Key& rhs) const;
    bool operator>=(const Key& rhs) const;

    bool operator==(const Key &rhs) const;
    bool operator!=(const Key &rhs) const;

private:
    data_type m_bytes; /* Big endian */
};

std::ostream& operator<<(std::ostream& os, const Key &key);

#endif
