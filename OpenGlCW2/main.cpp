#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Camera.h"
#include "Shader.h"
//window dimensions
const unsigned int SCR_WIDTH = 1280;
const unsigned int SCR_HEIGHT = 720;
//camera
Camera camera(glm::vec3(0.0f, 1.5f, 5.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;
//timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;
//floor vertices
float floorVertices[] = {
    //positions //normals
    -50.0f, 0.0f, -50.0f, 0.0f, 1.0f, 0.0f,
     50.0f, 0.0f, -50.0f, 0.0f, 1.0f, 0.0f,
     50.0f, 0.0f, 50.0f, 0.0f, 1.0f, 0.0f,
    -50.0f, 0.0f, -50.0f, 0.0f, 1.0f, 0.0f,
     50.0f, 0.0f, 50.0f, 0.0f, 1.0f, 0.0f,
    -50.0f, 0.0f, 50.0f, 0.0f, 1.0f, 0.0f
};
unsigned int floorVAO, floorVBO;

// NEW: CUBE TARGET VERTICES (FULL CUBE WITH NORMALS)
float cubeVertices[] = {
    // positions          // normals
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
     0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
     0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,

    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
     0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
     0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
     0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
};
unsigned int cubeVAO, cubeVBO;

// NEW: TARGET POSITIONS (5 CUBES AT DIFFERENT LOCATIONS)
glm::vec3 targetPositions[] = {
    glm::vec3(0.0f, 1.0f, -10.0f),
    glm::vec3(5.0f, 1.5f, -15.0f),
    glm::vec3(-5.0f, 0.5f, -12.0f),
    glm::vec3(3.0f, 2.0f, -20.0f),
    glm::vec3(-3.0f, 1.0f, -18.0f)
};
bool targetHit[5] = {false, false, false, false, false};
int score = 0;

// NEW: CROSSHAIR VERTICES (SIMPLE LINES IN 2D NDC SPACE)
unsigned int crosshairVAO, crosshairVBO;
float crosshairVertices[] = {
    -0.02f,  0.0f,
     0.02f,  0.0f,
    0.0f,  -0.02f,
    0.0f,   0.02f
};

void processInput(GLFWwindow* window);
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn);

// NEW: IMPROVED SHOOT FUNCTION (ACCURATE RAY-SPHERE HIT DETECTION)
void shoot() {
    glm::vec3 rayDir = camera.Front;
    glm::vec3 rayOrigin = camera.Position;

    float closestDist = 1000.0f; // large initial value
    int hitIndex = -1;

    for (int i = 0; i < 5; i++) {
        if (targetHit[i]) continue;

        glm::vec3 targetCenter = targetPositions[i];
        float radius = 0.75f; // half cube size after scale(1.5) -> 1.5/2 = 0.75

        // Vector from ray origin to sphere center
        glm::vec3 toCenter = targetCenter - rayOrigin;

        float distToCenter = glm::length(toCenter);
        glm::vec3 normalizedToCenter = toCenter / distToCenter;

        // Angle check (must be aiming fairly directly)
        float dotAngle = glm::dot(normalizedToCenter, rayDir);
        if (dotAngle < 0.95f) continue; // tighter aim required

        // Distance from ray line to sphere center (perpendicular)
        float perpDist = glm::length(glm::cross(toCenter, rayDir));

        // If perpendicular distance <= radius, it's a potential hit
        if (perpDist <= radius && distToCenter < closestDist) {
            closestDist = distToCenter;
            hitIndex = i;
        }
    }

    if (hitIndex != -1) {
        targetHit[hitIndex] = true;
        score++;
        std::cout << "HIT TARGET " << hitIndex << "! SCORE: " << score << std::endl;
    }
    else {
        std::cout << "MISS!" << std::endl;
    }
}
int main()
{
    //GLFW initialization
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "First-Person Target Shooter", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    //GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
    glEnable(GL_DEPTH_TEST);
    //floor VAO/VBO setup
    glGenVertexArrays(1, &floorVAO);
    glGenBuffers(1, &floorVBO);
    glBindVertexArray(floorVAO);
    glBindBuffer(GL_ARRAY_BUFFER, floorVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(floorVertices), floorVertices, GL_STATIC_DRAW);
    // osition attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    //normal attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);

    // NEW: CUBE TARGET VAO/VBO SETUP
    glGenVertexArrays(1, &cubeVAO);
    glGenBuffers(1, &cubeVBO);
    glBindVertexArray(cubeVAO);
    glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);

    // NEW: CROSSHAIR VAO/VBO SETUP
    glGenVertexArrays(1, &crosshairVAO);
    glGenBuffers(1, &crosshairVBO);
    glBindVertexArray(crosshairVAO);
    glBindBuffer(GL_ARRAY_BUFFER, crosshairVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(crosshairVertices), crosshairVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);

    //load shader
    Shader ourShader("shaders/vertex.shader", "shaders/fragment.shader");
    //render loop
    while (!glfwWindowShouldClose(window))
    {
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        processInput(window);
        glClearColor(0.2f, 0.3f, 0.6f, 1.0f); //sky blue background
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // Activate shader
        ourShader.use();
        // Create matrices
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / SCR_HEIGHT, 0.1f, 100.0f);
        glm::mat4 view = camera.GetViewMatrix();
        glm::mat4 model = glm::mat4(1.0f); //identity for floor
        //pass matrices to shader
        ourShader.setMat4("projection", projection);
        ourShader.setMat4("view", view);
        ourShader.setMat4("model", model);
        //simple light
        ourShader.setVec3("lightPos", glm::vec3(0.0f, 10.0f, 10.0f));
        ourShader.setVec3("lightColor", glm::vec3(1.0f, 1.0f, 1.0f));

        // DRAW FLOOR
        ourShader.setVec3("objectColor", glm::vec3(0.6f, 0.4f, 0.2f)); // brown floor
        glBindVertexArray(floorVAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        // DRAW TARGETS (ONLY IF NOT HIT)
        ourShader.setVec3("objectColor", glm::vec3(1.0f, 0.0f, 0.0f)); // RED TARGETS
        for (int i = 0; i < 5; i++) {
            if (targetHit[i]) continue;
            model = glm::mat4(1.0f);
            model = glm::translate(model, targetPositions[i]);
            model = glm::scale(model, glm::vec3(1.5f)); // BIGGER CUBES
            ourShader.setMat4("model", model);
            glBindVertexArray(cubeVAO);
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }

        // NEW: DRAW CROSSHAIR (2D OVERLAY - NO DEPTH TEST)
        glDisable(GL_DEPTH_TEST);
        glBindVertexArray(crosshairVAO);
        glDrawArrays(GL_LINES, 0, 4);
        glEnable(GL_DEPTH_TEST);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glDeleteVertexArrays(1, &floorVAO);
    glDeleteBuffers(1, &floorVBO);
    glDeleteVertexArrays(1, &cubeVAO);
    glDeleteBuffers(1, &cubeVBO);
    glDeleteVertexArrays(1, &crosshairVAO);
    glDeleteBuffers(1, &crosshairVBO);
    glfwTerminate();
    return 0;
}
//controls
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);
    camera.Position.y = 1.5f;

    // NEW: LEFT MOUSE CLICK TO SHOOT
    static bool lastLeft = false;
    bool currentLeft = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;
    if (currentLeft && !lastLeft) {
        shoot();
    }
    lastLeft = currentLeft;
}
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }
    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos;
    lastX = xpos;
    lastY = ypos;
    camera.ProcessMouseMovement(xoffset, yoffset);
}
