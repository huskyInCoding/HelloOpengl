#pragma once
#include "shaderSource.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
class shader
{
private:
	unsigned vertID;
	unsigned fragID;
	unsigned geomID;
	unsigned programID;
	shaderSource shaderCtx;
	bool getCompileRes(unsigned ID);
public:
	inline unsigned getProgramId() {
		return programID;
	}
	bool getVertShaderSource(std::string file);
	bool getFragShaderSource(std::string file);
	bool getGeomShaderSource(std::string file);
	bool compileShader();
	bool linkProgram();
	void useProgram();

};

