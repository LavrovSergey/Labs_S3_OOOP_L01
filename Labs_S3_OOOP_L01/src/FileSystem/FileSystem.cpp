#include "FileSystem.hpp"

std::string FileSystem::printNode(const std::string& prefix, const FileInfo* node, bool isLast)
{
    std::string result;
    if (node)
    {
        result = prefix;

        const unsigned char opened = 195;
        const unsigned char closed = 192;
        const unsigned char line = 196;

        //give direction
        result += (isLast ? closed : opened);
        result += line;
        result += line;

        //add node value
        result += node->name + "\n";
        //std::cout << result;
        for (auto& i : node->children)
            result += printNode(prefix + (isLast ? "    " : "|   "), i, i == node->children.back());
        //enter the next tree level - left and right branch
        //for (auto i = root->children.begin(); i != root->children.end(); ++i)
        //if (node->children.size() > 0)
        //{
            //for (int i = 0; i < node->children.size() - 2; ++i)
                //result += printNode(prefix + (isLast ? "|   " : "    "), (*i), false);

            //result += printNode(prefix + (isLast ? "|   " : "    "), node->children.back(), true);
        //}
       
    }
    return result;
}

FileSystem::FileSystem()
{
    root = new FileInfo("root", 0, 0, FileType::directory);
}

FileSystem::FileSystem(std::string realPath)
{
    root = new FileInfo("root", 0, 0, FileType::directory);
    for (const auto& entry : fs::directory_iterator(realPath))
    {
        std::stringstream spath;
        spath << entry.path();
        std::string path = spath.str();

        createFile(path, 0, entry.file_size(),
            entry.is_regular_file() ? FileType::file :
            entry.is_directory() ? FileType::directory :
            entry.is_symlink() ? FileType::link :
            entry.is_fifo() ? FileType::fifo :
            entry.is_block_file() ? FileType::block :
            entry.is_character_file() ? FileType::character :
            entry.is_socket() ? FileType::soket :
            FileType::directory);

    }
}

std::vector<FileInfo*> FileSystem::searchByName(FileInfo* searchFrom, std::string pattern)
{
    std::vector<FileInfo*> results;

    //if currrent matches pattern
    if (searchFrom->name.find(pattern) != std::string::npos)
        results.push_back(searchFrom);

    //search in all children
    for (auto& i : searchFrom->children)
    {
        auto subresult = searchByName(i, pattern);
        results.insert(results.end(), subresult.begin(), subresult.end());
    }
    return results;
}

FileInfo* FileSystem::createFile(std::string path, DateTime dateTimeCreation, uint64_t length, FileType fileType)
{
    //split path on subdirs
    auto subdirs = Helper::splitString(path, "\\");
    auto subdir = root;
    for (auto& i : subdirs)
    {
        if (i == "")
            continue;
        std::string subPath = i;
        subPath.erase(std::remove(subPath.begin(), subPath.end(), '\\'), subPath.end());
        subPath.erase(std::remove(subPath.begin(), subPath.end(), '\"'), subPath.end());
        //for every subdir check it existance
        bool hasChild = false;
        for (auto& j : subdir->children)
        {
            //go level down if exist
            if (j->name == subPath &&
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
            auto newDir = subdirs.back() != subPath ?
                new FileInfo(subPath, DateTime(0), 0, FileType::directory) :
                new FileInfo(subPath, dateTimeCreation, length, fileType);
            subdir->createFile(newDir);
            subdir = newDir;
        }
    }
    return subdir;
}

std::string FileSystem::print()
{
    return printNode("", root, true);
}
