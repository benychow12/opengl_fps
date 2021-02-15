#include "c_camera.h"
// Debug
#include <iostream>
#include <glm/gtx/string_cast.hpp>

// default camera values
const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 0.1f;
const float SENSITIVITY = 0.5f;

Camera::Camera(glm::vec3 position, glm::vec3 up) :
    Yaw(YAW), Pitch(PITCH), Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY)
{
    Position = position;
    WorldUp = up;
    no_clip = false;
    // Debug
    std::cout << "peepogpog wow" << std::endl;
    std::cout << "Position is..." << Position.x << Position.y << Position.z << std::endl;
    std::cout << "WorldUp is..." << WorldUp.x << WorldUp.y << WorldUp.z << std::endl;
    std::cout << "PITCH is..." << Pitch  << std::endl;
    std::cout << "YAW is..." << Yaw << std::endl;
    std::cout << "FRONT is..." << this->Front.x << this->Front.y << this->Front.z << std::endl;
    std::cout << "UP is..." << this->Up.x << this->Up.y << this->Up.z << std::endl;
    std::cout << "RIGHT is..." << this->Right.x << this->Right.y << this->Right.z << std::endl;
    UpdateCameraVectors();
    std::cout << "FRONT is..." << this->Front.x << this->Front.y << this->Front.z << std::endl;
    std::cout << "UP is..." << this->Up.x << this->Up.y << this->Up.z << std::endl;
    std::cout << "RIGHT is..." << this->Right.x << this->Right.y << this->Right.z << std::endl;
}

Camera::Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch)
    : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY)
{
    Position = glm::vec3(posX, posY, posZ);
    WorldUp = glm::vec3(upX, upY, upZ);
    Yaw = yaw;
    Pitch = pitch;
    no_clip = false;
    UpdateCameraVectors();
}

glm::mat4 Camera::GetViewMatrix()
{
    return glm::lookAt(Position, Position + Front, Up);
}

glm::vec3 Camera::GetPosition()
{
    return this->Position;
}

glm::vec3 Camera::GetFront()
{
    return this->Front;
}

void Camera::ProcessKeyboardCamera(Camera_Movement direction, float deltaTime)
{
    float velocity = MovementSpeed * deltaTime;

    if (direction == CAM_FORWARD)
    {
        if (!this->no_clip)
        {
            Position.x += Front.x * velocity;
            Position.z += Front.z * velocity;
        }
        else
        {
            Position += Front * velocity;
        }
    }
    if (direction == CAM_BACKWARD)
    {
        if (!this->no_clip)
        {
            Position.x -= Front.x * velocity;
            Position.z -= Front.z * velocity;
        }
        else
        {
            Position -= Front * velocity;
        }
    }
    if (direction == CAM_LEFT)
    {
        if (!this->no_clip)
        {
            Position.x -= Right.x * velocity;
            Position.z -= Right.z * velocity;
        }
        else
        {
            Position -= Right * velocity;
        }
    }
    if (direction == CAM_RIGHT)
    {
        if (!this->no_clip)
        {
            Position.x += Right.x * velocity;
            Position.z += Right.z * velocity;
        }
        else
        {
            Position += Right * velocity;
        }
    }
}

void Camera::ProcessMouseMovementCamera(float xoffset, float yoffset, GLboolean constrainPitch)
{
    xoffset *= MouseSensitivity;
    yoffset *= MouseSensitivity;

    Yaw += xoffset;
    Pitch += yoffset;

    // Make sure that when the pitch if oob, screen doesn't get
    // flipped
    if (constrainPitch)
    {
        if (Pitch > 89.0f)
        {
            Pitch = 89.0f;
        }
        if (Pitch < -89.0f)
        {
            Pitch = -89.0f;
        }
    }

    UpdateCameraVectors();
}

void Camera::UpdateCameraVectors()
{
    // calculate the new front vector
    glm::vec3 front;
    front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    front.y = sin(glm::radians(Pitch));
    front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    this->Front = glm::normalize(front);
    
    // Debug
    if (this->Front == glm::vec3(0.0f, 0.0f, 0.0f))
    {
        std::cout << "YO X THIS CAMERA IS BORKEN" << std::endl;
    }
    if (this->Up == glm::vec3(0.0f, 0.0f, 0.0f))
    {
        std::cout << "YO X THIS CAMERA IS BORKEN" << std::endl;
    }
    if (this->Right == glm::vec3(0.0f, 0.0f, 0.0f))
    {
        std::cout << "YO X THIS CAMERA IS BORKEN" << std::endl;
    }
    // Also re-calculate the right and up vector
    // Lengths closer to 0 the more you look up or down which results
    // in slower movement
    this->Right = glm::normalize(glm::cross(Front, WorldUp));
    this->Up = glm::normalize(glm::cross(Right, Front));
    if (this->Up == glm::vec3(0.0f, 0.0f, 0.0f))
    {
        std::cout << "YO X THIS CAMERA IS BORKEN" << std::endl;
    }
    if (this->Right == glm::vec3(0.0f, 0.0f, 0.0f))
    {
        std::cout << "YO X THIS CAMERA IS BORKEN" << std::endl;
    }
}

void Camera::no_clip_toggle()
{
    this->no_clip = !this->no_clip;
}
