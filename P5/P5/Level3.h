#include "Scene.h"
class Level3 : public Scene {
	GLuint fonttextureID;
public:
	void Initialize() override;
	void Update(float deltaTime) override;
	void Render(ShaderProgram* program) override;
};
