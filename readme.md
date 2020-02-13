# JAM
### Just Another Minecraft... or whatever
## Description
JAM is intended as a game/render engine. Being the sole developer I suppose it matters why its called JAM.

The reason is, I got tired of fighting with mods and version control when trying to mod the darn game.

Ideally the engine will be extremely customizable.

This would mean the whole system needs to expose some pretty low level OpenGL functionality for high-end manipulation.

## Dependencies
- glfw
- glad
- json_cpp
- glm
- assimp

## Current state

The system is currently based around 3 main modules:
-	GLFW
	- Manages the window systems
	- Exposes the GLFWwindow instance within a wrapper object allowing for universal interaction between modules

-	Engine
	- Manages thee GL render context and its resources.
-	Core
	- The primary component to the project.
	- Serves as the overall interface for interaction within the OpenGL context

These systems are build on the following suplimentairy interfaces:
-	Modules
- 	JsonConfig

These libraries can be examined under `renderengine/libs`
