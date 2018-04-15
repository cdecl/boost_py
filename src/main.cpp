
#include <iostream>
#include <string>
using namespace std;

#include <boost/python.hpp>
#include <intcrypt.h>

class crypto
{
  public:
    string encrypt(string domain, string key, string text)
    {
        char enc[1024];
        Encrypt(domain.c_str(), key.c_str(), text.c_str(), enc);
        return enc;
    }

    string decrypt(string domain, string key, string text)
    {
        char enc[1024];
        Decrypt(domain.c_str(), key.c_str(), text.c_str(), enc);
        return enc;
    }
};

class config
{
public:
    string source()
    {
        return __FILE__;
    }
};

BOOST_PYTHON_MODULE(simple)
{
    using namespace boost::python;

    class_<crypto>("crypto")
        .def("encrypt", &crypto::encrypt)
        .def("decrypt", &crypto::decrypt)
    ;

    class_<config>("config")
        .def("source", &config::source)
    ;
}
