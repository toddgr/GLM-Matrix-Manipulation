# GLM-Matrix-Manipulation
This repository contains functions that work with the manipulation of matrices using GLM.

```
mat4 Multiply( mat4, mat4 )
vec3 Multiply( mat4, vec3 b )
vec3 ScalePointAroundAnotherPoint( vec3 inputPoint, vec3 centerPoint, vec3 scale )
vec3 RotatePointAroundAnotherPoint( vec3 inputPoint, vec3 centerPoint, mat4 first, mat4 second, mat4 third )
```

### mat4 Multiply
This function takes in two 4x4 matrices and returns a 4x4 matrix. We simply use GLM to multiply one matrix a by another matrix, b.

### vec3 Multiply
Overloaded function takes in a 4x4 matrix and a 3x1 matrix (a three-element vector) and outputs a three element vector. In order to do this, we must convert the vec3 to a vec4 (we cannot multiply a 4x4 matrix by a 3x1 matrix), perform GLM multiplication, and then convert the resulting 4x1 matrix into a vec3 object.

### Scale point around another point
When we transform points in 3D space, there are a few things that happen that make the process less intuitive. When an object or point is scaled, this
transformation is done about the origin-- (0, 0, 0). But what if our object/point is not at the origin, as they often are not? This function takes in a point to be scaled (inputPoint), a centerPoint from which to scale the inputPoint, and then the scale value in X-Y-Z directions.

### Rotate point around another point
Similarly to `ScalePointAroundAnotherPoint`, there are a series of transformations that need to be done in order for a point to be rotated around a point that is NOT the origin. In this function, we again take an input point, a center point, and then three 4x4 rotation matrices, each of which are multiplied by the input point to perform three individual rotations. The resulting vec3 is the location of the inputPoint after is has been rotated around the centerPoint.
