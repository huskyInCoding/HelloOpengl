#pragma once
#include <string>
class shaderSource
{
private:
	const char* vertPtr = nullptr;
	const char* fragPtr = nullptr;
	const char* geomPtr = nullptr;
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

	bool isVsEmpty();
	bool isFsEmpty();
	bool isGsEmpty();
	void readShaderFromFile(std::string File, SHADERTYPE st);
};

