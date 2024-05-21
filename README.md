# GameLearning

Learning to use SFML with C++ for making basic games and learning along the way. Built using CMake.

_The first issue was setting up SFML (Simple and Fast Multimedia Library) with C++ in Visual Studio Code (VSCode) in my Linux system(Manjaro).
I made a guide to guide the builder/any person interested through the process:_

## 1. Install SFML

First, you need to install SFML. Open a terminal and execute the following command:

```sh
sudo pacman -S sfml
```

This command installs SFML on your Manjaro system.

## 2. Set Up a CMake Project

Now you need to install CMake, a build system generator. Here's how you can set up a simple CMake project:<br/>
Create a new directory for your project:

```sh
mkdir SFMLProject
cd SFMLProject
```

Inside this directory, create a _CMakeLists.txt_ file with the following content:

```cmake
cmake_minimum_required(VERSION 3.10)
project(SFMLProject)
set(CMAKE_CXX_STANDARD 17)

# Find SFML
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(SFMLProject main.cpp)

target_link_libraries(SFMLProject sfml-graphics sfml-audio)
```

Create a main.cpp file with a simple SFML example:

```cpp

    #include <SFML/Graphics.hpp>

    int main() {
        sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            window.display();
        }

        return 0;
    }
```

## 4. Configure VSCode for CMake

Open your project in VSCode.

Press Ctrl+Shift+P and type CMake: Configure.

Follow the prompts to select a kit (compiler) and configure your project. I chose my GCC compiler that I use to compile my C++ files as usually. You may need to install _cmake_ if it's not already installed, but check for it's existence if you're unsure:

```sh
sudo pacman -S cmake
```

## 5. Build and Run the Project

Press Ctrl+Shift+P and type CMake: Build to build your project.
To run the project, press F5 or Ctrl+Shift+P and type CMake: Run without Debugging.

Additional Tips

Include Paths: Ensure that VSCode is aware of the include paths. You can configure these in the .vscode/c_cpp_properties.json file if needed.
Terminal: You can use the integrated terminal in VSCode to run commands and interact with your project.

By following these steps, you should have SFML set up with C++ in Visual Studio Code on Manjaro Linux.

If your project grows to include more files, you will need to update your _CMakeLists.txt_ file to ensure all source files are included in the build. Here’s how to multiple source files in your project:

Assume you have the following project structure:

```css

SFMLProject/
├── CMakeLists.txt
├── main.cpp
├── Game.cpp
└── Game.hpp
```

2. Update CMakeLists.txt

You need to modify your CMakeLists.txt to include all your source files. One common approach is to list all the source files explicitly or use file(GLOB ...) to include them automatically.

## Listing Files Explicitly

You can manually add each source file to the add_executable command:

```cmake

cmake_minimum_required(VERSION 3.10)
project(SFMLProject)
set(CMAKE_CXX_STANDARD 17)

# Find SFML
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

# Add all source files here
set(SOURCES main.cpp Game.cpp)

add_executable(SFMLProject ${SOURCES})

target_link_libraries(SFMLProject sfml-graphics sfml-audio)
Using file(GLOB ...)
```

### Alternatively, you can use file(GLOB ...) to automatically include all .cpp files in the directory:

```cmake
cmake_minimum_required(VERSION 3.10)

# Get the name of the current directory
get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

# Find SFML
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

# Collect all source files
file(GLOB SOURCES "*.cpp")

# Create the executable with the project name
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)
```
