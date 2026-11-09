#include "Directory.h"

Directory::Directory(const std::string& name) : FileSystemItem(name) {}

void Directory::clearChildren() {
    for (FileSystemItem* child : children) {
        delete child;
    }
    children.clear();
}

void Directory::copyChildren(const Directory& other) {
    for (const FileSystemItem* child : other.children) {
        if (child) {
            children.push_back(child->clone());
        }
    }
}


Directory::~Directory() {
    clearChildren();
}

Directory::Directory(const Directory& other) : FileSystemItem(other.name) {
    copyChildren(other);
}

Directory& Directory::operator=(const Directory& other) {
    if (this != &other) {
        name = other.name;
        clearChildren();
        copyChildren(other);
    }
    return *this;
}

void Directory::add(FileSystemItem* item) {
    if (item) {
        children.push_back(item);
    }
}


void Directory::remove(const std::string& name) {
    for (auto it = children.begin(); it != children.end(); ++it) {
        if ((*it)->getName() == name) {
            delete *it;
            children.erase(it);
            return;
        }
    }
}


FileSystemItem* Directory::find(const std::string& name) {
    if (this->name == name) {
        return this;
    }
    for (FileSystemItem* child : children) {
        if (child->getName() == name) {
            return child;
        }
        Directory* subDir = dynamic_cast<Directory*>(child);
        if (subDir) {
            FileSystemItem* found = subDir->find(name);
            if (found) {
                return found;
            }
        }
    }
    return nullptr;
}

long Directory::getSize() const {
    long totalSize = 0;
    for (const FileSystemItem* child : children) {
        totalSize += child->getSize();
    }
    return totalSize;
}


void Directory::display(std::ostream& os, int depth) const {
    os << std::string(depth, ' ') << name << "/ (" << getSize() << " bytes)\n";
    for (const FileSystemItem* child : children) {
        child->display(os, depth + 2);
    }
}

FileSystemItem* Directory::clone() const {
    return new Directory(*this);
}


Directory& Directory::operator+=(FileSystemItem* item) {
    add(item);
    return *this;
}

Directory& Directory::operator-=(const std::string& name) {
    remove(name);
    return *this;
}