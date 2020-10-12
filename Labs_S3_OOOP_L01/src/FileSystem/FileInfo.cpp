#include "FileInfo.hpp"
#include "SearchPattern.hpp"


FileInfo::FileInfo(
    std::string name, 
    DateTime dateTimeCreation, 
    uint64_t length, 
    FileType fileType, 
    std::string symlinkTarget)
{
    this->parent = nullptr;
    this->name = name;
    this->dateTimeCreation = dateTimeCreation;
    this->dateTimeModification = dateTimeCreation;
    this->length = length;
    this->fileType = fileType;
    this->symlinkTarget = symlinkTarget;
}

std::string FileInfo::getFullPath()
{
    if (!parent)
        return name;
    else
        return parent->getFullPath() + "\\" + name;
}

void FileInfo::createFile(FileInfo* file)
{
    if (fileType != FileType::directory)
    {
        throw std::invalid_argument("This file type is not a directory.");
        return;
    }
    file->parent = this;
    children.push_back(file);
}

bool FileInfo::isMatchesPatternOR(SearchPattern pattern)
{
    //return true if any of parameters matches

    if (pattern.toSearchByName)
        if (name.find(pattern.searchInfo.name) != std::string::npos)
            return true;

    if (pattern.toSearchByDate)
        if (dateTimeCreation == pattern.searchInfo.dateTimeCreation)
            return true;

    if (pattern.toSearchBySize)
        if (length == pattern.searchInfo.length)
            return true;

    if (pattern.toSearchByType)
        if (fileType == pattern.searchInfo.fileType)
            return true;

    //nothing matched
    return false;
}

bool FileInfo::isMatchesPatternAND(SearchPattern pattern)
{
    //return false if any of parameters not matches

    if (pattern.toSearchByName)
        if (name.find(pattern.searchInfo.name) == std::string::npos)
            return false;

    if (pattern.toSearchByDate)
        if (dateTimeCreation != pattern.searchInfo.dateTimeCreation)
            return false;

    if (pattern.toSearchBySize)
        if (length != pattern.searchInfo.length)
            return false;

    if (pattern.toSearchByType)
        if (fileType != pattern.searchInfo.fileType)
            return false;

    //everything matched
    return true;
}
