#include <iostream>
#include "Fjord.h"

bool Engine::initWin(int Win_width, int Win_height, std::string name) { // initilize all SDL2 componets and makes sure that it succedes

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0  && TTF_Init() != 0) {
        printf("init sdl failed\n");
        return false;
    }

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	//Ensure core profile is used
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Win_width, Win_height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    

    if (!window) {
        printf ("failed to create window\n");
        return false;
    }

    glContext = SDL_GL_CreateContext(window);

    if (!glContext) {
        printf ("failed to create glContext\n");
        return false;
    }
    SDL_SetWindowResizable(window, SDL_TRUE);
    


	glewExperimental = GL_TRUE;
	GLenum glewError = glewInit();
	if (glewInit() != GLEW_OK) {
		std::cout << "Error initializing GLEW = " << glewGetErrorString(glewError) << std::endl;
		return false;
	}
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//Create an instance of the rendererGL class to use OpenGL for drawing.
	rendererGL = std::make_unique<RendererGL>(window);
	//Enable vsync
	SDL_GL_SetSwapInterval(1);
    return true;
}

void Engine::Initialize(){
    //YAML::Node physics_defaults = YAML::LoadFile("../lib/def/physics-defaults.yaml"); // Load the defaults

    //b2WorldDef worldDef = b2DefaultWorldDef(); // Create new box2d world

    //worldDef.gravity = (b2Vec2){0.0f, physics_defaults["gravity"].as<float>()}; // Set the gravity to default gravity

    //worldId = b2CreateWorld(&worldDef); // Create the box2d world and set to world id defined in fjord.h
    root = Node(0,0,1,1,"root");
    nodes.push_back(&root);
}