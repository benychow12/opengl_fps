#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

enum Camera_Movement {
    CAM_FORWARD,
    CAM_BACKWARD,
    CAM_LEFT,
    CAM_RIGHT,
};

class Camera
{
    public:
        // camera attributes
        glm::vec3 Position;
        glm::vec3 Front;
        glm::vec3 Up;
        glm::vec3 Right;
        glm::vec3 WorldUp;

        // Euler Angles
        float Yaw;
        float Pitch;

        // Camera options
        float MovementSpeed;
        float MouseSensitivity;

        // constructor with vectors
        Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f));
        // constructor with scalars
        Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);
    
        // returns the view matrix calculated using Euler angles and the lookat
        // matrix
        glm::mat4 GetViewMatrix();

        glm::vec3 GetPosition();
        glm::vec3 GetFront();

        // process input received from any keyboard-linked input system
        // accepts input paramters in the form of a camera defined enum (for
        // abstraction)
        void ProcessKeyboardCamera(Camera_Movement direction, float deltaTime);

        // process input received from mouse input
        // expects offset value in both x and y direction
        void ProcessMouseMovementCamera(float xoffset, float yoffset, GLboolean constrainPitch = true);

        void no_clip_toggle();

    private:
        // calculate the front vector from camera's (updated) Euler angles
        void UpdateCameraVectors();

        bool no_clip;
};
#endif
