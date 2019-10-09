#pragma once

// Created by Oleg Klimov
// Adapted to C++ by Adrien Logut

class CarModel
{
public:
    CarModel();
    ~CarModel();

    void SetGas(float gas);
    void SetSteer(float steer);
    void SetBrake(float brake);

    void Step(float dt);
};