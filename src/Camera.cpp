#include "Camera.h"
#include <cmath>
#include <algorithm>

static double lerp(double a, double b, double t) {
    return a + (b - a) * t;
}

void Camera::update(double playerX, double playerY,
    double velX, double velY,
    double dt)
{

    double desiredLookX = 0;
    double desiredLookY = 0;

    if (fabs(velX) > 1)
        desiredLookX = (velX > 0 ? 1 : -1) * lookAheadDistX;

    if (fabs(velY) > 1)
        desiredLookY = (velY > 0 ? 1 : -1) * lookAheadDistY;

    lookAheadX = lerp(lookAheadX, desiredLookX, 0.08);
    lookAheadY = lerp(lookAheadY, desiredLookY, 0.08);

    double left = x - deadzoneW / 2;
    double right = x + deadzoneW / 2;

    if (playerX < left)
        x = playerX + deadzoneW / 2;

    if (playerX > right)
        x = playerX - deadzoneW / 2;


    double top = y - deadzoneH / 2;
    double bottom = y + deadzoneH / 2;

    if (playerY < top)
        y = playerY + deadzoneH / 2;

    if (playerY > bottom)
        y = playerY - deadzoneH / 2;

    x += lookAheadX * 0.02;
    y += lookAheadY * 0.02;

    x = std::clamp(x,
        viewW / 2.0,
        (double)worldW - viewW / 2.0);

    y = std::clamp(y,
        viewH / 2.0,
        (double)worldH - viewH / 2.0);
}

int Camera::getViewX() const {
    return (int)floor(x - viewW / 2);
}

int Camera::getViewY() const {
    return (int)floor(y - viewH / 2);
}