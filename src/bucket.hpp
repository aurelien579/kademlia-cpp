#ifndef BUCKET_HPP
#define BUCKET_HPP

#include <list>

#include "contact.hpp"

class Bucket
{
public:
    static const size_t SIZE = 20;
    Bucket();

    void addContact(const Contact &contact);
    std::list<Contact>::iterator find(const Contact &contact);
    std::list<Contact>::const_iterator end() const;
    std::list<Contact>::const_iterator begin() const;

private:
    std::list<Contact> m_contacts;
};

std::ostream& operator<<(std::ostream& os, const Bucket &bucket);

#endif
