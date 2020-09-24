#pragma once
#include <string>
class shaderSource
{
private:
	const char* vertPtr;
	const char* fragPtr;
	const char* geomPtr;
	std::string vertShader;
	std::string fragShader;
	std::string geomShader;
public:
	enum SHADERTYPE {
		VERT,
		GEOM,
		FRAG
	};
	const char** getVert();
	const char** getFrag();
	const char** getGeom();

	void readShaderFromFile(std::string File, SHADERTYPE st);
};

