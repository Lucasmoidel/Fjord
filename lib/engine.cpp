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
	glClearColor(0.0f, 0.25f, 0.75f, 1.0f);
	//Clear the screen.
	glClear(GL_COLOR_BUFFER_BIT);
    renderer->setDrawColor(255, 255, 255, 255); // sets object color
    for (size_t i = 0; i < nodes.size(); i++){
        nodes[i]->Render(renderer);
        //SDL_RenderDrawLine(renderer, 0, 0, nodes[i]->rect.x, nodes[i]->rect.y);
        //SDL_RenderDrawLine(renderer, 500, 0, nodes[i]->rect.x+200, nodes[i]->rect.y);
        //SDL_RenderDrawLine(renderer, 500, 500, nodes[i]->rect.x+200, nodes[i]->rect.y+200);
        //SDL_RenderDrawLine(renderer, 0, 500, nodes[i]->rect.x, nodes[i]->rect.y+200);
    }
    //root.Render(renderer);
    SDL_GL_SwapWindow(window); // shows render changes
}

std::vector<Node*> Engine::getRectColisions(std::string name){
    std::vector<Node*> intersecting;
    int index = -999;
    for (int i = 0; i < nodes.size(); i++){
        if (nodes[i]->id == name){
            index = i;
        }
    }
    for (int i = 0; i < nodes.size(); i++){
        if (i == index)i++;
        if (SDL_HasIntersection(&nodes[index]->rect, &nodes[i]->rect)){
            intersecting.push_back(nodes[i]);
        }
    }
    return intersecting;
}

void Engine::destroyWindow(){ // destroy window when game exits
        SDL_GL_DeleteContext(glContext);
        SDL_DestroyWindow(window);
        SDL_Quit();
}