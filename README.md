# libobjs
Standard libraries for C++


To Compile

yum install g++ autoconf automake

aclocal; autoconf; automake --add-missing; ./configure

To Complile Tests

sudo apt-get install libgtest-dev

g++ -o PhoneNumberTest PhoneNumberTest.cpp -lgtest -lgtest_main -pthread

