#include "Menu.h"
#define LEVEL3_WIDTH 14
#define LEVEL3_HEIGHT 8
#define LEVEL3_ENEMY_COUNT 1
unsigned int menu_data[] =
{
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

void Menu::Initialize() {

    state.nextScene = -1;

    GLuint mapTextureID = Util::LoadTexture("tileset.png");
    state.map = new Map(LEVEL3_WIDTH, LEVEL3_HEIGHT, menu_data, mapTextureID, 1.0f, 4, 1);
    

    state.player = new Entity();
    state.player->textureID = Util::LoadTexture("george_0.png");
    state.player->isActive = false;
    state.player->position = glm::vec3(5, -4, 0);

   


    state.enemies = new Entity[LEVEL3_ENEMY_COUNT];
    fonttextureID = Util::LoadTexture("font2.png");
   
}
void Menu::Update(float deltaTime) {
    state.player->Update(deltaTime, state.player, state.enemies, LEVEL3_ENEMY_COUNT, state.map);
    
}
void Menu::Render(ShaderProgram* program) {
    state.map->Render(program);
    state.player->Render(program);

    Util::DrawText(program, fonttextureID, "Box Bouncers!", 1, -0.5f, glm::vec3(2,-4,0));

    if (lives == 0) {
        Util::DrawText(program, fonttextureID, "You Lose!", 1, -0.5f, glm::vec3(2, -5, 0));
    }
}