#include <iostream>
#include "Address.hh"
#include "PhoneNumber.hh"
#include "Person.hh"

using namespace std;

int main(int argc, char** argv) {

    cout << "libobjs: " << endl;

    Address address = Address("411 Main Street", "Apartment 2", "Springfield", "OH", "45501");

    cout << address.toString() << endl;

    Address addr2 = address;

    cout << addr2.toString() << endl;

    PhoneNumber pn = PhoneNumber("+1", "555", "555", "5555");

    cout << pn.toString() << endl;

    Person per = Person("John", "Adams", "Smith", address, pn, 0);

    cout << per.toString() << endl;

    return 0;
}
