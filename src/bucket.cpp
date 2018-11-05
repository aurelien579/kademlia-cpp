#include "bucket.hpp"

Bucket::Bucket()
{
}

void Bucket::addContact(const Contact &contact)
{
    auto iter = find(contact);

    if (iter != end()) {
        if (m_contacts.size() >= Bucket::SIZE) {
            //TODO: Send ping to last seen (back)
        } else {
            m_contacts.remove(*iter);
            m_contacts.push_front(contact);
        }
    } else {
        m_contacts.push_front(contact);
    }
}

std::list<Contact>::iterator Bucket::find(const Contact &contact)
{
    return std::find(m_contacts.begin(), m_contacts.end(), contact);
}

std::list<Contact>::const_iterator Bucket::begin() const
{
    return m_contacts.begin();
}

std::list<Contact>::const_iterator Bucket::end() const
{
    return m_contacts.end();
}

std::ostream& operator<<(std::ostream& os, const Bucket &bucket)
{
    os << "[" << std::endl;

    for (auto it = bucket.begin(); it != bucket.end(); it++) {
        os << "\t" << *it << ", " << std::endl;
    }
    os << "]";

    return os;
}
