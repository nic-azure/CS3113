#include "Scene.h"
class Level2 : public Scene {
	GLuint fonttextureID;
public:
	void Initialize() override;
	void Update(float deltaTime) override;
	void Render(ShaderProgram* program) override;
};
