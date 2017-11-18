#ifndef FILESYSTEM_H_
#define FILESYSTEM_H_

#include "Files.h"


class FileSystem {
private:
	Directory* rootDirectory;
	Directory* workingDirectory;
public:
	FileSystem();
	Directory& getRootDirectory() const; // Return reference to the root directory
	Directory& getWorkingDirectory() const; // Return reference to the working directory
	void setWorkingDirectory(Directory *newWorkingDirectory); // Change the working directory of the file system
    //RULE OF 5
	void clear();
	void copy(FileSystem& other);
	virtual ~FileSystem();//Destructor
	FileSystem(FileSystem &other);//Copy constructor
	FileSystem& operator=(FileSystem &other);//Copy assignment
	FileSystem(FileSystem &&other);//Move constructor
	FileSystem& operator=(FileSystem &&other);//Move assignment
};


#endif
