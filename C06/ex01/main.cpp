#include "Serializer.hpp"

int main()
{
    Data* dat= new Data;
    dat->num = 6;
    dat->c = 'a';
    uintptr_t uin = Serializer::serialize(dat);
    std::cout << " serialize : " << uin << std::endl;
    Data* dese = Serializer::deserialize(uin);
    std::cout << "deserialize : " << dese->num << ", " << dese->c << std::endl;
}

