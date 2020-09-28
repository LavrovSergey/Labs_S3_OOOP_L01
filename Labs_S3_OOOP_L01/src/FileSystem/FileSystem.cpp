#include "FileSystem.hpp"

FileSystem::FileSystem()
{
    root = new FileInfo("root", 0, 0, FileType::directory);
}

FileInfo* FileSystem::createFile(std::string path, DateTime dateTimeCreation, uint64_t length, FileType fileType)
{
    //split path on subdirs
    auto subdirs = Helper::splitString(path, "\\");
    auto subdir = root;
    for (auto& i : subdirs)
    {
        //for every subdir check it existance
        bool hasChild = false;
        for (auto& j : subdir->children)
        {
            //go level down if exist
            if (j->name == i &&
                j->fileType == FileType::directory)
            {
                subdir = j;
                hasChild = true;
                break;
            }
        }
        //create subdir if not exist
        if (!hasChild)
        {
            //if it's last subdir - it is file, apply parameters
            auto newDir = subdirs.back() != i ?
                new FileInfo(i, DateTime(0), 0, FileType::directory) :
                new FileInfo(i, dateTimeCreation, length, fileType);
            subdir->createFile(newDir);
            subdir = newDir;
        }
    }
    return subdir;
}
