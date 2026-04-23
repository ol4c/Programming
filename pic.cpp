#include <iostream>
#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;

int main() {
    // Define the root path
    std::string rootPath = "F:\\Family\\2568";

    try {
        if (!fs::exists(rootPath) || !fs::is_directory(rootPath)) {
            std::cerr << "Error: Path does not exist or is not a directory." << std::endl;
            return 1;
        }

        // Iterate through each item in the root directory
        for (const auto& entry : fs::directory_iterator(rootPath)) {
            if (fs::is_directory(entry)) {
                std::string folderName = entry.path().filename().string();
                int photoCount = 1;

                std::cout << "Processing folder: " << folderName << std::endl;

                // Look inside the subfolder
                for (const auto& file : fs::directory_iterator(entry.path())) {
                    if (fs::is_regular_file(file)) {
                        std::string ext = file.path().extension().string();
                        
                        // Check if the file is an image (add more extensions if needed)
                        if (ext == ".jpg" || ext == ".jpeg" || ext == ".png" || ext == ".JPG") {
                            
                            // Construct new filename: FOLDERNAME_1.jpg
                            std::string newFileName = folderName + "_" + std::to_string(photoCount) + ext;
                            fs::path destination = fs::path(rootPath) / newFileName;

                            try {
                                // Copy file (using overwrite_existing to avoid errors if re-run)
                                fs::copy_file(file.path(), destination, fs::copy_options::overwrite_existing);
                                std::cout << "  Copied: " << file.path().filename() << " -> " << newFileName << std::endl;
                                photoCount++;
                            } catch (const fs::filesystem_error& e) {
                                std::cerr << "  Failed to copy " << file.path().filename() << ": " << e.what() << std::endl;
                            }
                        }
                    }
                }
            }
        }
        std::cout << "\nOperation complete! All photos extracted to " << rootPath << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "A critical error occurred: " << e.what() << std::endl;
    }

    return 0;
}