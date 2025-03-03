#define GL_SILENCE_DEPRECATION

#ifdef _WINDOWS
#include <GL/glew.h>
#endif

#define GL_GLEXT_PROTOTYPES 1
#include <SDL.h>
#include <SDL_opengl.h>
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "ShaderProgram.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "Entity.h"

#define PLATFORM_COUNT 32
#define ENEMY_COUNT 3
struct GameState {
    Entity* player;
    Entity* platforms;
    Entity* enemies;
};

GameState state;

SDL_Window* displayWindow;
bool gameIsRunning = true;

ShaderProgram program;
glm::mat4 viewMatrix, modelMatrix, projectionMatrix;
int number_of_kills = 0;
GLuint LoadTexture(const char* filePath) {
    int w, h, n;
    unsigned char* image = stbi_load(filePath, &w, &h, &n, STBI_rgb_alpha);

    if (image == NULL) {
        std::cout << "Unable to load image. Make sure the path is correct\n";
        assert(false);
    }

    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    stbi_image_free(image);
    return textureID;
}


void Initialize() {
    SDL_Init(SDL_INIT_VIDEO);
    displayWindow = SDL_CreateWindow("George vs Mikes!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);
    SDL_GLContext context = SDL_GL_CreateContext(displayWindow);
    SDL_GL_MakeCurrent(displayWindow, context);

#ifdef _WINDOWS
    glewInit();
#endif

    glViewport(0, 0, 640, 480);

    program.Load("shaders/vertex_textured.glsl", "shaders/fragment_textured.glsl");

    viewMatrix = glm::mat4(1.0f);
    modelMatrix = glm::mat4(1.0f);
    projectionMatrix = glm::ortho(-5.0f, 5.0f, -3.75f, 3.75f, -1.0f, 1.0f);

    program.SetProjectionMatrix(projectionMatrix);
    program.SetViewMatrix(viewMatrix);

    glUseProgram(program.programID);

    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glEnable(GL_BLEND);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    // Initialize Game Objects

    // Initialize Player
    state.player = new Entity();
    state.player->entityType = PLAYER;
    state.player->position = glm::vec3(-4,-1,0);
    state.player->movement = glm::vec3(0);
    state.player->acceleration = glm::vec3(0, -9.8f, 0);
    state.player->speed = 2.0f;
    state.player->height = 0.8f;
    state.player->width = 0.5f;
    state.player->textureID = LoadTexture("george_0.png");

    state.player->animRight = new int[4]{ 3, 7, 11, 15 };
    state.player->animLeft = new int[4]{ 1, 5, 9, 13 };
    state.player->animUp = new int[4]{ 2, 6, 10, 14 };
    state.player->animDown = new int[4]{ 0, 4, 8, 12 };

    state.player->animIndices = state.player->animRight;
    state.player->animFrames = 4;
    state.player->animIndex = 0;
    state.player->animTime = 0;
    state.player->animCols = 4;
    state.player->animRows = 4;

    state.player->jumpPower = 7.0f;

    state.platforms = new Entity[PLATFORM_COUNT];

    GLuint platformTextureID = LoadTexture("platformPack_tile016.png");
    state.platforms[0].textureID = platformTextureID;
    state.platforms[0].position = glm::vec3(-1, -3.25f, 0);

    state.platforms[1].textureID = platformTextureID;
    state.platforms[1].position = glm::vec3(0, -3.25f, 0);

    state.platforms[2].textureID = platformTextureID;
    state.platforms[2].position = glm::vec3(1, -3.25f, 0);

    state.platforms[3].textureID = platformTextureID;
    state.platforms[3].position = glm::vec3(2, -3.25f, 0);
    //state.platforms[3].isActive = false;

    state.platforms[4].textureID = platformTextureID;
    state.platforms[4].position = glm::vec3(3, -3.25f, 0);
    //state.platforms[4].isActive = false;

    state.platforms[5].textureID = platformTextureID;
    state.platforms[5].position = glm::vec3(4, -3.25f, 0);
    //state.platforms[5].isActive = false;

    state.platforms[6].textureID = platformTextureID;
    state.platforms[6].position = glm::vec3(5, -3.25f, 0);

    state.platforms[7].textureID = platformTextureID;
    state.platforms[7].position = glm::vec3(-2, -3.25f, 0);

    state.platforms[8].textureID = platformTextureID;
    state.platforms[8].position = glm::vec3(-3, -3.25f, 0);

    state.platforms[9].textureID = platformTextureID;
    state.platforms[9].position = glm::vec3(-4, -3.25f, 0);

    state.platforms[10].textureID = platformTextureID;
    state.platforms[10].position = glm::vec3(-5, -3.25f, 0);

    state.platforms[11].textureID = platformTextureID;
    state.platforms[11].position = glm::vec3(-5, -2.25f, 0);

    state.platforms[12].textureID = platformTextureID;
    state.platforms[12].position = glm::vec3(-5, -1.25f, 0);

    state.platforms[13].textureID = platformTextureID;
    state.platforms[13].position = glm::vec3(-5, -0.25f, 0);

    state.platforms[14].textureID = platformTextureID;
    state.platforms[14].position = glm::vec3(-5, 0.75f, 0);

    state.platforms[15].textureID = platformTextureID;
    state.platforms[15].position = glm::vec3(-5, 1.75f, 0);

    state.platforms[16].textureID = platformTextureID;
    state.platforms[16].position = glm::vec3(-5, 2.75f, 0);

    state.platforms[17].textureID = platformTextureID;
    state.platforms[17].position = glm::vec3(-5, 3.75f, 0);

    state.platforms[18].textureID = platformTextureID;
    state.platforms[18].position = glm::vec3(5, -2.25f, 0);

    state.platforms[19].textureID = platformTextureID;
    state.platforms[19].position = glm::vec3(5, -1.25f, 0);

    state.platforms[20].textureID = platformTextureID;
    state.platforms[20].position = glm::vec3(5, -0.25f, 0);

    state.platforms[21].textureID = platformTextureID;
    state.platforms[21].position = glm::vec3(5, 0.75f, 0);

    state.platforms[22].textureID = platformTextureID;
    state.platforms[22].position = glm::vec3(5, 1.75f, 0);

    state.platforms[23].textureID = platformTextureID;
    state.platforms[23].position = glm::vec3(5, 2.75f, 0);

    state.platforms[24].textureID = platformTextureID;
    state.platforms[24].position = glm::vec3(5, 3.75f, 0);

    state.platforms[25].textureID = platformTextureID;
    state.platforms[25].position = glm::vec3(4, 0.75f, 0);

    state.platforms[26].textureID = platformTextureID;
    state.platforms[26].position = glm::vec3(3, 0.75f, 0);

    state.platforms[27].textureID = platformTextureID;
    state.platforms[27].position = glm::vec3(2, 0.75f, 0);

    state.platforms[28].textureID = platformTextureID;
    state.platforms[28].position = glm::vec3(1.5, 0.75f, 0);

    state.platforms[29].textureID = platformTextureID;
    state.platforms[29].position = glm::vec3(-4, 0.75f, 0);

    state.platforms[30].textureID = platformTextureID;
    state.platforms[30].position = glm::vec3(-1, -1.25f, 0);

    state.platforms[31].textureID = platformTextureID;
    state.platforms[31].position = glm::vec3(-3, 0.75f, 0);

    for (int i = 0; i < PLATFORM_COUNT; i++) {
        state.platforms[i].entityType = PLATFORM;
        state.platforms[i].Update(0, NULL,  NULL, NULL, 0, 0);
    }

    state.enemies = new Entity[ENEMY_COUNT];
    GLuint enemyTextureID = LoadTexture("mike.png");

    state.enemies[0].entityType = ENEMY;
    state.enemies[0].textureID = enemyTextureID;
    state.enemies[0].position = glm::vec3(4, -2.40f, 0);
    state.enemies[0].height = 0.8f;
    state.enemies[0].acceleration = glm::vec3(0, -9.8f, 0);
    state.enemies[0].speed = 1.0f;
    state.enemies[0].aiType = WAITANDGO;
    state.enemies[0].aiState = WALKING;

    state.enemies[1].entityType = ENEMY;
    state.enemies[1].textureID = enemyTextureID;
    state.enemies[1].position = glm::vec3(4, 5.0f, 0);
    state.enemies[1].height = 0.8f;
    state.enemies[1].acceleration = glm::vec3(0, -9.8f, 0);
    state.enemies[1].speed = 1.0f;
    state.enemies[1].aiType = WAITANDGO;
    state.enemies[1].aiState = IDLE;

    state.enemies[2].entityType = ENEMY;
    state.enemies[2].textureID = enemyTextureID;
    state.enemies[2].position = glm::vec3(-4, 5.0f, 0);
    state.enemies[2].height = 0.8f;
    state.enemies[2].acceleration = glm::vec3(0, -9.8f, 0);
    state.enemies[2].speed = 1.0f;
    state.enemies[2].aiType = WALKER;
    state.enemies[2].aiState = WALKING;
}

void ProcessInput() {

    state.player->movement = glm::vec3(0);

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
        case SDL_WINDOWEVENT_CLOSE:
            gameIsRunning = false;
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
            case SDLK_LEFT:
                // Move the player left
                break;

            case SDLK_RIGHT:
                // Move the player right
                break;

            case SDLK_SPACE:
                // Some sort of action
                if (state.player->collidedBottom) {
                    state.player->jump = true;
                }
                break;
            }
            break; // SDL_KEYDOWN
        }
    }

    const Uint8* keys = SDL_GetKeyboardState(NULL);

    if (keys[SDL_SCANCODE_LEFT]) {
        state.player->movement.x = -1.0f;
        state.player->animIndices = state.player->animLeft;
    }
    else if (keys[SDL_SCANCODE_RIGHT]) {
        state.player->movement.x = 1.0f;
        state.player->animIndices = state.player->animRight;
    }


    if (glm::length(state.player->movement) > 1.0f) {
        state.player->movement = glm::normalize(state.player->movement);
    }

}

#define FIXED_TIMESTEP 0.0166666f
float lastTicks = 0;
float accumulator = 0.0f;
void Update() {
    float ticks = (float)SDL_GetTicks() / 1000.0f;
    float deltaTime = ticks - lastTicks;
    lastTicks = ticks;

    deltaTime += accumulator;
    if (deltaTime < FIXED_TIMESTEP) {
        accumulator = deltaTime;
        return;
    }

    while (deltaTime >= FIXED_TIMESTEP) {
        // Update. Notice it's FIXED_TIMESTEP. Not deltaTime
        if (state.player->lastCollision == ENEMY && state.player->collidedBottom) {
            for (int i = 0; i < ENEMY_COUNT; i++) {
                if (state.enemies[i].lastCollision == PLAYER) {
                    state.enemies[i].isActive = false;
                    number_of_kills++;
                }
            }
        }
        state.player->Update(FIXED_TIMESTEP, state.player, state.enemies, state.platforms, PLATFORM_COUNT, ENEMY_COUNT);
        
        for (int i = 0; i < ENEMY_COUNT; i++) {
            state.enemies[i].Update(FIXED_TIMESTEP, state.player, state.enemies, state.platforms, PLATFORM_COUNT, ENEMY_COUNT);
            
        }
        deltaTime -= FIXED_TIMESTEP;
        
    }

    

    accumulator = deltaTime;
}


void Render() {
    glClear(GL_COLOR_BUFFER_BIT);

    for (int i = 0; i < PLATFORM_COUNT; i++) {
        state.platforms[i].Render(&program);
    }
    for (int i = 0; i < ENEMY_COUNT; i++) {
        state.enemies[i].Render(&program);
    }
    state.player->Render(&program);

    if (number_of_kills == ENEMY_COUNT) {
        return;
    }

    SDL_GL_SwapWindow(displayWindow);
}


void Shutdown() {
    SDL_Quit();
}

int main(int argc, char* argv[]) {
    Initialize();

    while (gameIsRunning) {
        ProcessInput();
        Update();
        Render();
    }

    Shutdown();
    return 0;
}
