#ifndef FILESYSTEMITEM_H
#define FILESYSTEMITEM_H

#include <string>
#include <iostream>


class FileSystemItem {
protected:
    std::string name;

public:
    FileSystemItem(const std::string& name);
    virtual ~FileSystemItem() = default;

    std::string getName() const;


    virtual void display(std::ostream& os = std::cout, int depth = 0) const = 0;
    virtual FileSystemItem* clone() const = 0;
    virtual long getSize() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const FileSystemItem& item);
    bool operator<(const FileSystemItem& other) const;
};

#endif // FILESYSTEMITEM_H