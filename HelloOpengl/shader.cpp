#include "shader.h"
#include <iostream>
bool shader::getVertShaderSource(std::string file) {
    shaderCtx.readShaderFromFile(file, shaderSource::VERT);
    return true;
}
bool shader::getFragShaderSource(std::string file) {
    shaderCtx.readShaderFromFile(file, shaderSource::FRAG);
    return true;
}
bool shader::getGeomShaderSource(std::string file) {
    shaderCtx.readShaderFromFile(file, shaderSource::GEOM);
    return true;
}



bool shader::compileShader() {
    if (!shaderCtx.isVsEmpty()) {
        vertID = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertID, 1, shaderCtx.getVert(), NULL);
        glCompileShader(vertID);
        if (!getCompileRes(vertID)) {
            return false;
        }
    }

    if (!shaderCtx.isFsEmpty()) {
        fragID = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragID, 1, shaderCtx.getFrag(), NULL);
        glCompileShader(fragID);
        if (!getCompileRes(fragID)) {
            return false;
        }
    }

    if (!shaderCtx.isGsEmpty()) {
        geomID = glCreateShader(GL_GEOMETRY_SHADER);
        glShaderSource(geomID, 1, shaderCtx.getGeom(), NULL);
        glCompileShader(geomID);
        if (!getCompileRes(geomID)) {
            return false;
        }
    }
    return true;
}

bool shader::getCompileRes(unsigned ID) {
    int status = 0;
    glGetShaderiv(ID, GL_COMPILE_STATUS, &status);
    if (!status)
    {
        char info[512];
        glGetShaderInfoLog(ID, 512, NULL, info);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << info << std::endl;
    };
    return status;
}

bool shader::linkProgram() {
    programID = glCreateProgram();
    if (vertID != 0) {
        glAttachShader(programID, vertID);
    }
    if (fragID != 0) {
        glAttachShader(programID, fragID);
    }
    if (geomID != 0) {
        glAttachShader(programID, geomID);
    }
    glLinkProgram(programID);
    int status = 0;
    glGetProgramiv(programID, GL_LINK_STATUS, &status);
    if (!status)
    {
        char info[512];
        glGetProgramInfoLog(programID, 512, NULL, info);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << info << std::endl;
    }
    glDeleteShader(vertID);
    glDeleteShader(fragID);
    glDeleteShader(geomID);
    return true;
}

void shader::useProgram() {
    glUseProgram(programID);
}