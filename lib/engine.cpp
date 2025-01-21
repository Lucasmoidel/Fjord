#include "Fjord.h"

void Engine::processInput(){ // process keyboard inputs
    SDL_Event event;
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT){
        gameRuning = false;
    }
}

void Engine::update(){
    timeToWait = engine.TARGET_FPS - (SDL_GetTicks() - Engine::last_frame_time);

    if (timeToWait > 0 && timeToWait <= engine.FRAME_TARGET_TIME){
        SDL_Delay(timeToWait);
    }

    Time::deltaTime =  (SDL_GetTicks() - Engine::last_frame_time) / 1000.0f;
    Engine::last_frame_time = SDL_GetTicks();

    
}


void Engine::render(RendererGL* renderer){ // render objects
	//Set the background color.
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	//Clear the screen.
	glClear(GL_COLOR_BUFFER_BIT);
    renderer->setDrawColor(255, 255, 255, 255); // sets object color
    root.Render(renderer);
    SDL_GL_SwapWindow(window); // shows render changes
}

void Engine::destroyWindow(){ // destroy window when game exits
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();
}