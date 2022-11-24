#include <iostream>
#include "Address.hh"

using namespace std;

int main(int argc, char** argv) {

    cout << "libobjs: " << endl;

    Address* address = new Address("13528 Hammerhill Way", "", "Fort Wayne", "IN", "46845");

    cout << address->toString() << endl;
    delete address;
    return 0;
}
