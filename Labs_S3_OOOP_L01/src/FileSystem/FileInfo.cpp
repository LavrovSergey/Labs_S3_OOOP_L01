#include "FileInfo.hpp"

FileInfo::FileInfo(std::string name, DateTime dateTimeCreation, uint64_t length, FileType fileType)
{
    this->parent = nullptr;
    this->name = name;
    this->dateTimeCreation = dateTimeCreation;
    this->dateTimeModification = dateTimeCreation;
    this->length = length;
    this->fileType = fileType;
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
