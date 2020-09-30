#include "FileSystem.hpp"

std::string FileSystem::printNode(const std::string& prefix, const FileInfo* node, bool isLast)
{
    std::string result;
    if (node)
    {
        result = prefix;

        std::string type;

        switch (node->fileType)
        {
            case FileType::file :       break;
            case FileType::directory:       type = "<DIR>"; break;
            case FileType::link :           type = "<LNK>"; break;
            case FileType::fifo :           type = "<FIF>"; break;
            case FileType::block :          type = "<BLK>"; break;
            case FileType::character :      type = "<CHR>"; break;
            case FileType::soket :          type = "<SOC>"; break;
            default: break;
        }

        const unsigned char opened = 195;
        const unsigned char closed = 192;
        const unsigned char line = 196;



        //give direction
        result += (isLast ? closed : opened);
        result += line;
        result += line;

        //add node value
        result += type + node->name + "\n";
        for (auto& i : node->children)
            result += printNode(prefix + (isLast ? "    " : "|   "), i, i == node->children.back());
    }
    return result;
}

FileSystem::FileSystem()
{
    root = new FileInfo("root", 0, 0, FileType::directory);
}

void demo_status(const fs::path& p, fs::file_status s)
{
    std::cout << p;
    // alternative: switch(s.type()) { case fs::file_type::regular: ...}
    if (fs::is_regular_file(s)) std::cout << " is a regular file\n";
    if (fs::is_directory(s)) std::cout << " is a directory\n";
    if (fs::is_block_file(s)) std::cout << " is a block device\n";
    if (fs::is_character_file(s)) std::cout << " is a character device\n";
    if (fs::is_fifo(s)) std::cout << " is a named IPC pipe\n";
    if (fs::is_socket(s)) std::cout << " is a named IPC socket\n";
    if (fs::is_symlink(s)) std::cout << " is a symlink\n";
    if (!fs::exists(s)) std::cout << " does not exist\n";
}

FileSystem::FileSystem(std::string realPath)
{
    root = new FileInfo("root", 0, 0, FileType::directory);
    for (const auto& entry : fs::recursive_directory_iterator(realPath))
    {
        std::stringstream spath;
        spath << entry.path();
        std::string path = spath.str();
        auto status = entry.status();
        FileType type = FileType::file;

        if (fs::is_regular_file(status))            type = FileType::file;
        if (fs::is_directory(status))               type = FileType::directory;
        if (fs::is_block_file(status))              type = FileType::block;
        if (fs::is_character_file(status))          type = FileType::character;
        if (fs::is_fifo(status))                    type = FileType::fifo;
        if (fs::is_socket(status))                  type = FileType::soket;
        if (fs::is_symlink(entry.symlink_status())) type = FileType::link;

        createFile(path, 0, entry.file_size(), type);

        
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
    for (int i = 0; i < subdirs.size(); ++i)
    {
        subdirs[i].erase(std::remove(subdirs[i].begin(), subdirs[i].end(), '\\'), subdirs[i].end());
        subdirs[i].erase(std::remove(subdirs[i].begin(), subdirs[i].end(), '\"'), subdirs[i].end());
    }

    for (auto& i : subdirs)
    {
        if (i == "")
            continue;
        
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

            /*if (j->name == i &&
                j->fileType == FileType::link)
            {
                std::string pathLink;
                for (auto &k : subdirs)
                    if(k - subdirs.begin())
                    pathLink += subdirs[k];
                pathLink = j->symlinkTarget + "\\" + pathLink;

                return;
            }*/
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

std::string FileSystem::print()
{
    return printNode("", root, true);
}
