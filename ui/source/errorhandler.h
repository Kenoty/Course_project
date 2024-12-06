#include <string>
#include <typeinfo>
#include <QLineEdit>

class ErrorHandler
{
private:

public:
    template<typename T>
    std::string getPointerTypeName(T* ptr);
    void checkEmail(QLineEdit*);
};

template<typename T>
std::string ErrorHandler::getPointerTypeName(T* ptr)
{
    return typeid(ptr).name();
}
