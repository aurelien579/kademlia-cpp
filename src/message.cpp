#include "message.hpp"

Message::Message(int type) :
    m_type(type)
{

}

Message::Message() : Message(0)
{
}
