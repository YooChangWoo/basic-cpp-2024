#include <iostream>
#include "clang17_1_filedivi.h"

AClass::AClass(int anum) {
    num = anum;

}

void AClass::AInfo() {
    std::cout << "A Class::num" << num << std::endl;

}

int main()
{
    

    return 0;

}