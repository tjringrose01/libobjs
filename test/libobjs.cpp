#include <iostream>

#include "EmailAddress.hpp"
#include "Address.hpp"
#include "PhoneNumber.hpp"
#include "Person.hpp"
#include "SSN.hpp"

using namespace std;

int main(int argc, char** argv) {

    cout << "libobjs: " << endl;

    Address address = Address("411 Main Street", "Apartment 2", "Springfield", "OH", "45501");

    cout << address.toString() << endl;

    Address addr2 = address;

    cout << addr2.toString() << endl;

    PhoneNumber pn = PhoneNumber("1", "555", "555", "5555");

    cout << pn.toString() << endl;

    Dt birthDate = Dt(1980,12,14);

    SSN ssn = SSN("123","45","6789");

    EmailAddress email = EmailAddress("john@lala.com");

    //cout << ssn.toString() << endl;

    try {
        SSN ssn2 = SSN("000","00","0000");
    } catch (exception& exc) {
        cerr << "ERROR: Unable to assign SSN." << endl;
    }

    //cout << ssn.toString() << endl;

    Person per = Person("John", "Adams", "Smith", address, pn, 0, birthDate, ssn, email);

    cout << per.toString() << endl;

    return 0;
}
