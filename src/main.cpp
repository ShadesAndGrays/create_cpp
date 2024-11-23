#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <string>
#include <fstream>


int main(){

    std::string projectName;
    std::cout << "Projects Name: ";
    std::cin >> projectName;

    auto path = std::filesystem::current_path();

    path.concat("/"+projectName);

    std::cout << "Current file path" << path << std::endl;

    std::filesystem::create_directory(path);

    std::ofstream file;
    file.open(path.string()+"/CMakeLists.txt");
    file << "cmake_minimum_required(VERSION 3.20.0)" << std::endl;
    file << std::endl;
    file << "set(CMAKE_EXPORT_COMPILE_COMMANDS on)" << std::endl;
    file << std::endl;
    file << "set(CMAKE_CXX_STANDARD 23)" << std::endl;
    file << std::endl;
    file << "project(" << projectName << ")" << std::endl;
    file << std::endl;
    file << "file(GLOB SRC src/**.cpp)" << std::endl;
    file << std::endl;
    file << "add_executable(${PROJECT_NAME} ${SRC})" << std::endl;
    file << std::endl;
    file.close();

    std::filesystem::path srcPath(path);
    srcPath.concat("/src");
    std::filesystem::create_directory(srcPath);

    std::filesystem::path buildPath(path);
    buildPath.concat("/build");
    std::filesystem::create_directory(buildPath);

    file.open(srcPath.string() + "/main.cpp");
    file << "#include <iostream>\nint main(){\n\tstd::cout << \"Hello world\" << std::endl;\n}" << std::endl;
    file.close();

    std::string cmd = "git init " ;
    cmd += path.string();

    int result = system(cmd.c_str());

    if (result == 0){
        std::cout << "Initialzed git repository" << std::endl;
    }else{
        std::cout << "Failed to initialze git repository" << std::endl;
    }

}

