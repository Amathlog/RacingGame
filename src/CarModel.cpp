// Created by Oleg Klimov
// Adapted to C++ by Adrien Logut

#include "include/CarModel.h"

#include "Box2D/Box2D.h"
#include <array>
#include "include/utils.h"

namespace Constants
{
    constexpr float SIZE = 0.02f;
    constexpr float ENGINE_POWER = 100000000.0f * SIZE * SIZE;
    constexpr float WHEEL_MOMENT_OF_INERTIA = 4000.0f * SIZE * SIZE;
    constexpr float FRICTION_LIMIT = 1000000.0f * SIZE * SIZE;     // friction ~= mass ~= size ^ 2 (calculated implicitly using density)
    constexpr float WHEEL_R = 27.0f;
    constexpr float WHEEL_W = 14.0f;
    constexpr std::array<Point2D, 4> WHEELPOS{
        Point2D(-55.0f, 80.0f),
        Point2D(55.0f, 80.0f),
        Point2D(-55.0f, 82.0f),
        Point2D(55.0f, 82.0f)
    };

    constexpr std::array<Point2D, 4> HULL_POLY1{
        Point2D(-60.0f, 130.0f),
        Point2D(60.0f, 130.0f),
        Point2D(60.0f, 110.0f),
        Point2D(-60.0f, 110.0f)
    };

    constexpr std::array<Point2D, 4> HULL_POLY2{
        Point2D(-15.0f, 120.0f),
        Point2D(15.0f, 120.0f),
        Point2D(20.0f, 20.0f),
        Point2D(-20.0f, 20.0f)
    };

    constexpr std::array<Point2D, 8> HULL_POLY2{
        Point2D(25.0f, 20.0f),
        Point2D(50.0f, -10.0f),
        Point2D(50.0f, -40.0f),
        Point2D(20.0f, -90.0f),
        Point2D(-20.0f, -90.0f),
        Point2D(50.0f, -40.0f),
        Point2D(-50.0f, -10.0f),
        Point2D(-25.0f, 20.0f)
    };
        //                HULL_POLY4 = [
        //                    (-50, -120), (+50, -120),
        //                        (+50, -90), (-50, -90)
        //                ]
        //                WHEEL_COLOR = (0.0, 0.0, 0.0)
        //                        WHEEL_WHITE = (0.3, 0.3, 0.3)
        //                        MUD_COLOR = (0.4, 0.4, 0.0)
}

CarModel::CarModel()
{

}

CarModel::~CarModel()
{

}

void CarModel::SetGas(float gas)
{

}
void CarModel::SetSteer(float steer)
{

}

void CarModel::SetBrake(float brake)
{

}

void CarModel::Step(float dt)
{

}
