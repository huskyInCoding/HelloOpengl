#include "shaderSource.h"
#include <fstream>

using namespace std;
const char** shaderSource::getVert() {
	vertPtr = vertShader.c_str();
	return (const char**)&vertPtr;
}
const char** shaderSource::getFrag() {
	fragPtr = fragShader.c_str();
	return (const char**)&fragPtr;
}
const char** shaderSource::getGeom() {
	geomPtr = geomShader.c_str();
	return (const char**)&geomPtr;
}

void shaderSource::readShaderFromFile(std::string shaderFile, SHADERTYPE st) {
	std::ifstream in(shaderFile, std::ios::in);
	if (!in) {
		return;
	}
	std::string* strPtr = nullptr;
	switch(st) {
	case VERT: strPtr = &vertShader; break;
	case FRAG: strPtr = &fragShader; break;
	case GEOM: strPtr = &geomShader; break;
	default: break;
	}
	std::istreambuf_iterator<char> beg(in), end;
	std::string strdata(beg, end);
	*strPtr = strdata;
	in.close();
}