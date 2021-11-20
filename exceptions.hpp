#include <exception>

class heroTypeException : public std::exception {
    public:
        const char* what () {
            return "bad type given";
        }
};