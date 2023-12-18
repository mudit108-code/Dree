#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

void exploreFolder(const fs::path& folderPath, int depth = 0) {
    for (const auto& entry : fs::directory_iterator(folderPath)) {
        if (fs::is_directory(entry.status())) {
            // It's a directory, explore it recursively
            std::cout << std::string(depth, ' ') << "[Directory] " << entry.path().filename() << "\n";
            exploreFolder(entry, depth + 1);
        } else if (fs::is_regular_file(entry.status())) {
            // It's a regular file
            std::cout << std::string(depth, ' ') << "[File] " << entry.path().filename() << "\n";
        }
    }
}

int main() {
    // Replace "your_folder_path" with the path of the folder you want to explore
    fs::path folderPath("your_folder_path");

    if (fs::exists(folderPath) && fs::is_directory(folderPath)) {
        std::cout << "Exploring folder: " << folderPath << "\n";
        exploreFolder(folderPath);
    } else {
        std::cerr << "Invalid folder path.\n";
    }

    return 0;
}
