##### Author: Sok Den
##### Date created: 03/25/2022
##### Licence: Sok Den

##### https://github.com/sokdenspace/ITE-G6-Y3S2-Graphics-OpenGL
##### git clone https://github.com/sokdenspace/ITE-G6-Y3S2-Graphics-OpenGL.git

##### Tools:

Visual Studio 2019
"Win32 Console Application"
FreeGLUT
deprecated/legacy OpenGL 1.1 (docs: https://docs.microsoft.com/en-us/windows/desktop/opengl/opengl)

### Settings:

### Spoiler

### 1. Configurations `All Platforms`
Configuration: All Configurations<br/>
Platforms: All Platforms<br/>

`VC++ Directories -> Include Directories:`<br/>
$(SolutionDir)Dependencies\freeglut\include
$(SolutionDir)Dependencies\glew\include

`VC++ Directories -> Library Directories:`<br/>
$(SolutionDir)Dependencies\freeglut\lib\$(Platform)
$(SolutionDir)Dependencies\glew\lib\Release\$(Platform)

`Linker -> Input -> Additional Dependencies`<br/>
freeglut.lib
glew32.lib

`Build Events -> Post-Build Event`<br/>
xcopy /y /d "$(SolutionDir)Dependencies\freeglut\bin\Win32\freeglut.dll" "$(OutDir)"
xcopy /y /d "$(SolutionDir)Dependencies\glew\bin\Release\x64\glew32.dll" "$(OutDir)"

# `OR`

`C/C++ -> Genaral -> Additional Include Directories:`<br/>
$(SolutionDir)Dependencies\freeglut\include
$(SolutionDir)Dependencies\glew\include

`Linker -> Input -> Additional Dependencies`<br/>
freeglut.lib
glew32.lib

`Build Events -> Post-Build Event`<br/>
xcopy /y /d "$(SolutionDir)Dependencies\freeglut\bin\Win32\freeglut.dll" "$(OutDir)"
xcopy /y /d "$(SolutionDir)Dependencies\glew\bin\Release\x64\glew32.dll" "$(OutDir)"

# 2. Configurations `Win32`
Configuration: All Configurations
Platforms: Win32

`Linker -> General -> Additional Library Directories:`<br/>
$(SolutionDir)Dependencies\freeglut\lib\Win32

`Build Events -> Post-Build Event`
xcopy /y /d "$(SolutionDir)Dependencies\freeglut\bin\Win32\freeglut.dll" "$(OutDir)"
xcopy /y /d "$(SolutionDir)Dependencies\glew\bin\Release\x64\glew32.dll" "$(OutDir)"

# 3. Configurations `x64`
Configuration: All Configurations
Platforms: x64

`Linker -> General -> Additional Library Directories:`<br/>
$(SolutionDir)Dependencies\freeglut\lib\Win64

`Build Events -> Post-Build Event`<br/>
xcopy /y /d "$(SolutionDir)Dependencies\freeglut\bin\Win32\freeglut.dll" "$(OutDir)"
xcopy /y /d "$(SolutionDir)Dependencies\glew\bin\Release\x64\glew32.dll" "$(OutDir)"

`Main.cpp`

# Spoiler