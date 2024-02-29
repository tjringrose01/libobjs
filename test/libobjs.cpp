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

    cout << address.to_string() << endl;

    Address addr2 = address;

    Address addr3 = address;
    addr3.set_state("MO");

    cout << addr2.to_string() << endl;

    cout << addr3 << endl;

    if (address == addr2) cout << "Address and addr2 are equal!" << endl;

    if (address == addr3) {} else cout << "Address and addr3 are NOT equal!" << endl;

    PhoneNumber pn = PhoneNumber("1", "555", "555", "5555");

    cout << pn.to_string() << endl;

    Dt birthDate = Dt(1980,12,14);
    
    try {
        Dt birthDate2 = Dt(1900,2,29);
    } catch (exception &exc) {
        cerr << "ERROR: Unable to assign birth date." << endl;
    }
    

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
    cout << per << endl;

for (int i=0; i < 1000; i++) {
    Person person1 = Person("Alice", "Jane", "Smith", Address("1234 Elm Street", "Apt 101", "Springfield", "IL", "62701"), PhoneNumber("1","555","123","4567"), 1, Dt(1990,5,15), SSN("123", "45", "6789"), EmailAddress("alice@example.com"));
    cout << person1 << endl;
    Person person2 = Person("Bob", "Michael", "Johnson", Address("5678 Oak Avenue", "Suite 202", "Riverside", "CA", "92501"), PhoneNumber("1","555","987","6543"), 0, Dt(1985,8,20), SSN("123", "65", "4321"), EmailAddress("bob@example.com"));
    cout << person2 << endl;
    Person person3 = Person("Eve", "Marie", "Brown", Address("9101 Pine Road", "Unit 303", "Lakeview", "NY", "10001"), PhoneNumber("1","555","111","2222"), 1, Dt(1976,3,10), SSN("456", "78", "9012"), EmailAddress("eve@example.com"));
    cout << person3 << endl;
    Person person4 = Person("David", "Lee", "Williams", Address("2468 Cedar Lane", "Apt 505", "Hilltown", "TX", "75001"), PhoneNumber("1","555","333","4444"), 0, Dt(1998,11,25), SSN("789", "01", "2345"), EmailAddress("david@example.com"));
    cout << person4 << endl;
    Person person5 = Person("Grace", "Ann", "Miller", Address("3690 Birch Street", "Suite 707", "Sunset", "FL", "33001"), PhoneNumber("1","555","777","8888"), 1, Dt(1982,7,5), SSN("234", "56", "7890"), EmailAddress("grace@example.com"));
    cout << person5 << endl;
    Person person6 = Person("Peter", "John", "Davis", Address("7531 Maple Avenue", "Unit 404", "Greenwood", "WA", "98001"), PhoneNumber("1","555","222","3333"), 0, Dt(1970,1,30), SSN("567", "89", "0123"), EmailAddress("peter@example.com"));
    cout << person6 << endl;
    Person person7 = Person("Sarah", "Louise", "Clark", Address("1592 Walnut Street", "Apt 606", "Riverdale", "GA", "30201"), PhoneNumber("1","555","444","5555"), 1, Dt(1995,9,12), SSN("890", "12", "3456"), EmailAddress("sarah@example.com"));
    cout << person7 << endl;
    Person person8 = Person("Michael", "Thomas", "Young", Address("4826 Pine Lane", "Suite 303", "Hillcrest", "NC", "28001"), PhoneNumber("1","555","666","7777"), 0, Dt(1988,4,18), SSN("345", "67", "8901"), EmailAddress("michael@example.com"));
    cout << person8 << endl;
    Person person9 = Person("Emily", "Rose", "Adams", Address("6257 Cedar Road", "Apt 202", "Woodland", "OR", "97001"), PhoneNumber("1","555","999","0000"), 1, Dt(1978,6,8), SSN("678", "90", "1234"), EmailAddress("emily@example.com"));
    cout << person9 << endl;
    Person person10 = Person("Daniel", "Paul", "Evans", Address("7410 Elm Street", "Unit 101", "Springfield", "MO", "65801"), PhoneNumber("1","555","234","5678"), 0, Dt(1992,10,22), SSN("123", "23", "4567"), EmailAddress("daniel@example.com"));
    cout << person10 << endl;
    Person person11 = Person("Olivia", "Grace", "Baker", Address("8523 Oak Avenue", "Suite 404", "Riverside", "CA", "92501"), PhoneNumber("1","555","876","5432"), 1, Dt(1980,2,14), SSN("123", "23", "6789"), EmailAddress("olivia@example.com"));
    cout << person11 << endl;
    Person person12 = Person("William", "Henry", "Garcia", Address("9635 Pine Road", "Apt 202", "Lakeview", "NY", "10001"), PhoneNumber("1","555","321","6543"), 0, Dt(1975,12,5), SSN("123", "65", "4321"), EmailAddress("william@example.com"));
    cout << person12 << endl;
    Person person13 = Person("Sophia", "Marie", "Collins", Address("1478 Cedar Lane", "Suite 606", "Hilltown", "TX", "75001"), PhoneNumber("1","555","654","3210"), 1, Dt(1997,8,25), SSN("456", "78", "9012"), EmailAddress("sophia@example.com"));
    cout << person13 << endl;
    Person person14 = Person("James", "Robert", "Perez", Address("3690 Birch Street", "Unit 303", "Sunset", "FL", "33001"), PhoneNumber("1","555","987","6543"), 0, Dt(1983,3,10), SSN("789", "01", "2345"), EmailAddress("james@example.com"));
    cout << person14 << endl;
    Person person15 = Person("Ava", "Elizabeth", "Sanchez", Address("7531 Maple Avenue", "Apt 101", "Greenwood", "WA", "98001"), PhoneNumber("1","555","123","4567"), 1, Dt(1973,5,15), SSN("234", "56", "7890"), EmailAddress("ava@example.com"));
    cout << person15 << endl;
    Person person16 = Person("Logan", "Michael", "Nguyen", Address("1592 Walnut Street", "Suite 202", "Riverdale", "GA", "30201"), PhoneNumber("1","555","456","7890"), 0, Dt(1990,11,25), SSN("567", "89", "0123"), EmailAddress("logan@example.com"));
    cout << person16 << endl;
    Person person17 = Person("Mia", "Grace", "Gonzalez", Address("4826 Pine Lane", "Apt 404", "Hillcrest", "NC", "28001"), PhoneNumber("1","555","789","0123"), 1, Dt(1986,7,5), SSN("890", "12", "3456"), EmailAddress("mia@example.com"));
    cout << person17 << endl;
    Person person18 = Person("Ethan", "Alexander", "Martinez", Address("6257 Cedar Road", "Suite 303", "Woodland", "OR", "97001"), PhoneNumber("1","555","234","5678"), 0, Dt(1977,1,30), SSN("345", "67", "8901"), EmailAddress("ethan@example.com"));
    cout << person18 << endl;
    Person person19 = Person("Isabella", "Sophia", "Lopez", Address("7410 Elm Street", "Apt 505", "Springfield", "MO", "65801"), PhoneNumber("1","555","876","5432"), 1, Dt(1993,9,12), SSN("678", "90", "1234"), EmailAddress("isabella@example.com"));
    cout << person19 << endl;
    Person person20 = Person("Noah", "William", "Hernandez", Address("8523 Oak Avenue", "Unit 101", "Riverside", "CA", "92501"), PhoneNumber("1","555","321","6543"), 0, Dt(1979,4,18), SSN("456", "23", "4567"), EmailAddress("noah@example.com"));
    cout << person20 << endl;
}
    



    return 0;
}
