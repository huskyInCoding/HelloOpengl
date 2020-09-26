#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Windows.h>
#include "ctime"
#include "window.h"
#include "shaderSource.h"
#include "shader.h"
#include <direct.h>
#include "stb_image.h"
#include "texture.h"
int main() {
    float vertices[] = {
        //     ---- 位置 ----       ---- 颜色 ----     - 纹理坐标 -
             0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // 右上
             0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // 右下
            -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // 左下
            -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // 左上
    };

    unsigned int indices[] = { // 注意索引从0开始! 
        0, 1, 3, // 第一个三角形
        1, 2, 3  // 第二个三角形
    };
    GLFWwindow* window = createWindow(800, 600);

    shader myShader;
    myShader.getVertShaderSource("D:\\project\\HelloOpengl\\HelloOpengl\\shaders\\vert.txt");
    myShader.getFragShaderSource("D:\\project\\HelloOpengl\\HelloOpengl\\shaders\\frag.txt");
    myShader.compileShader();
    myShader.linkProgram();
    myShader.useProgram();

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    
    unsigned int EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    


    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    //texture coordinate
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);


    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    
    texture t1, t2;
    t1.generateTexture("D:\\project\\HelloOpengl\\HelloOpengl\\wall.jpg", GL_RGB);
    t2.generateTexture("D:\\project\\HelloOpengl\\HelloOpengl\\awesomeface.png", GL_RGBA);

    texture::activeTexture(GL_TEXTURE0);
    t1.bindTexture();
    texture::activeTexture(GL_TEXTURE1);
    t2.bindTexture();

    
    myShader.useProgram();
    glUniform1i(glGetUniformLocation(myShader.getProgramId(), "texture0"), 0);
    glUniform1i(glGetUniformLocation(myShader.getProgramId(), "texture1"), 1);
    while (shouldKeepWindow(window)) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        run(window);
    }
    glfwTerminate();

    return 0;

}