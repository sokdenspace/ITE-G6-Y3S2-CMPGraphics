### Author: Sok Den
### Date created: 03/25/2022
### Licence: Sok Den

------------------------------

### GitHub: https://github.com/sokdenspace/ITE-G6-Y3S2-Graphics-OpenGL
### git clone https://github.com/sokdenspace/ITE-G6-Y3S2-Graphics-OpenGL.git

### Tools:

IDE: Visual Studio 2019																	<br/>
"Win32 Console Application"																<br/>
FreeGLUT																				<br/>
deprecated/legacy OpenGL 1.1 (docs: https://docs.microsoft.com/en-us/windows/desktop/opengl/opengl)

### Settings:

### Spoiler

### 1. Configurations `All Platforms`
Configuration: All Configurations														<br/>
Platforms: All Platforms																<br/>

`VC++ Directories -> Include Directories:`												<br/>
$(SolutionDir)Dependencies\freeglut\include												<br/>
$(SolutionDir)Dependencies\glew\include													<br/>

`VC++ Directories -> Library Directories:`												<br/>
$(SolutionDir)Dependencies\freeglut\lib\$(Platform)										<br/>
$(SolutionDir)Dependencies\glew\lib\Release\$(Platform)									<br/>

`Linker -> Input -> Additional Dependencies`											<br/>
freeglut.lib																			<br/>
glew32.lib																				<br/>

`Build Events -> Post-Build Event`														<br/>
xcopy /y /d "$(SolutionDir)Dependencies\freeglut\bin\Win32\freeglut.dll" "$(OutDir)"	<br/>
xcopy /y /d "$(SolutionDir)Dependencies\glew\bin\Release\x64\glew32.dll" "$(OutDir)"	<br/>

# `OR`																					<br/>

`C/C++ -> Genaral -> Additional Include Directories:`									<br/>
$(SolutionDir)Dependencies\freeglut\include												<br/>
$(SolutionDir)Dependencies\glew\include													<br/>

`Linker -> Input -> Additional Dependencies`											<br/>
freeglut.lib																			<br/>
glew32.lib																				<br/>

`Build Events -> Post-Build Event`														<br/>
xcopy /y /d "$(SolutionDir)Dependencies\freeglut\bin\Win32\freeglut.dll" "$(OutDir)"	<br/>
xcopy /y /d "$(SolutionDir)Dependencies\glew\bin\Release\x64\glew32.dll" "$(OutDir)"	<br/>

# 2. Configurations `Win32`																<br/>
Configuration: All Configurations														<br/>
Platforms: Win32																		<br/>

`Linker -> General -> Additional Library Directories:`									<br/>
$(SolutionDir)Dependencies\freeglut\lib\Win32											<br/>

`Build Events -> Post-Build Event`														<br/>
xcopy /y /d "$(SolutionDir)Dependencies\freeglut\bin\Win32\freeglut.dll" "$(OutDir)"	<br/>
xcopy /y /d "$(SolutionDir)Dependencies\glew\bin\Release\x64\glew32.dll" "$(OutDir)"	<br/>

# 3. Configurations `x64`																<br/>
Configuration: All Configurations														<br/>
Platforms: x64																			<br/>

`Linker -> General -> Additional Library Directories:`									<br/>
$(SolutionDir)Dependencies\freeglut\lib\Win64											<br/>

`Build Events -> Post-Build Event`														<br/>
xcopy /y /d "$(SolutionDir)Dependencies\freeglut\bin\Win32\freeglut.dll" "$(OutDir)"	<br/>
xcopy /y /d "$(SolutionDir)Dependencies\glew\bin\Release\x64\glew32.dll" "$(OutDir)"	<br/>

`Main.cpp`

# Spoiler