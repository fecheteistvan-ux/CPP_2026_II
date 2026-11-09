#ifndef FILE_H
#define FILE_H

#include "FileSystemItem.h"

class File : public FileSystemItem {
private:
    long size;

public:
    File(const std::string& name, long size);
    ~File() override = default;

    long getSize() const override;
    void display(std::ostream& os = std::cout, int depth = 0) const override;
    FileSystemItem* clone() const override;
};

#endif // FILE_H