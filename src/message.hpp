#ifndef MESSAGE_HPP
#define MESSAGE_HPP

class Message
{
    const int REQUEST = 0;
    const int RESPONSE = 1;

public:
    Message(int type);

private:
    int m_type;
};

#endif
