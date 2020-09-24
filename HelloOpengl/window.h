#pragma once
#ifndef WINDOW_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void framebufferSizeCallback(GLFWwindow* window, int width, int height);
GLFWwindow* createWindow(unsigned width, unsigned height);
bool shouldKeepWindow(GLFWwindow* window);
void run(GLFWwindow* window);
#endif // !WINDOW_H
