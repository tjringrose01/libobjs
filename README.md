# libobjs
Standard libraries for C++

## Dependencies

### Compilers

Using yum, install c++ and cmake.

<CODE>
sudo yum -y install gcc-c++ cmake
</CODE>

### Conan

Install conan from conan's website - <A HREF=https://conan.io/downloads>https://conan.io/downloads</A>

<CODE>
cd ~ && wget https://github.com/conan-io/conan/releases/download/2.15.1/conan-2.15.1-linux-x86_64.tgz
tar -xvf conan-2.15.1-linux-x86_64.tgz
</CODE>

Initialize conan

<CODE>
conan profile detect
</CODE>

## To Compile

yum install g++ autoconf automake

aclocal; autoconf; automake --add-missing; ./configure

To Complile Tests

sudo apt-get install libgtest-dev

g++ -o PhoneNumberTest PhoneNumberTest.cpp -lgtest -lgtest_main -pthread

