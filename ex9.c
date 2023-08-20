#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y, z;
} Point3D;

Point3D translate(Point3D point, double dx, double dy, double dz) {
    point.x += dx;
    point.y += dy;
    point.z += dz;
    return point;
}

Point3D rotate(Point3D point, double angle, double axisX, double axisY, double axisZ) {
    double radian = angle * M_PI / 180.0;
    double cosA = cos(radian);
    double sinA = sin(radian);

    double newX = (cosA + (1 - cosA) * axisX * axisX) * point.x +
                  ((1 - cosA) * axisX * axisY - sinA * axisZ) * point.y +
                  ((1 - cosA) * axisX * axisZ + sinA * axisY) * point.z;
    
    double newY = ((1 - cosA) * axisX * axisY + sinA * axisZ) * point.x +
                  (cosA + (1 - cosA) * axisY * axisY) * point.y +
                  ((1 - cosA) * axisY * axisZ - sinA * axisX) * point.z;
    
    double newZ = ((1 - cosA) * axisX * axisZ - sinA * axisY) * point.x +
                  ((1 - cosA) * axisY * axisZ + sinA * axisX) * point.y +
                  (cosA + (1 - cosA) * axisZ * axisZ) * point.z;

    point.x = newX;
    point.y = newY;
    point.z = newZ;

    return point;
}

Point3D scale(Point3D point, double scaleX, double scaleY, double scaleZ) {
    point.x *= scaleX;
    point.y *= scaleY;
    point.z *= scaleZ;
    return point;
}

int main() {
    Point3D point = {1.0, 2.0, 3.0};
    printf("Original point: (%.2f, %.2f, %.2f)\n", point.x, point.y, point.z);
    
    // Perform translation
    point = translate(point, 2.0, 3.0, 1.0);
    printf("Translated point: (%.2f, %.2f, %.2f)\n", point.x, point.y, point.z);
    
    // Perform rotation
    point = rotate(point, 45.0, 1.0, 1.0, 1.0);
    printf("Rotated point: (%.2f, %.2f, %.2f)\n", point.x, point.y, point.z);
    
    // Perform scaling
    point = scale(point, 2.0, 2.0, 2.0);
    printf("Scaled point: (%.2f, %.2f, %.2f)\n", point.x, point.y, point.z);
    
    return 0;
}
