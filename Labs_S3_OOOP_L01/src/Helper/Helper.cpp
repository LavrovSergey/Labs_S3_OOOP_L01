#include "Helper.hpp"

std::vector<std::string> Helper::splitString(std::string input, std::string delimiter)
{
    std::vector<std::string> result;
    size_t pos = 0;
    std::string token;
    while ((pos = input.find(delimiter)) != std::string::npos) 
    {
        token = input.substr(0, pos);
        result.push_back(token);
        input.erase(0, pos + delimiter.length());
    }
    result.push_back(input);
    return result;
}

bool Helper::isFileExists(const std::string& name)
{
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
}
