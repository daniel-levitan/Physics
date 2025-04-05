#include <gtest/gtest.h>
#include "core/core.h"  // Ensure this points to your actual header location

using namespace physicsEngine;

class Vector3Test : public ::testing::Test {
protected:
    Vector3 v1{1.0, 2.0, 3.0};
    Vector3 v2{-1.0, 4.0, 0.5};
    real epsilon = 1e-6;
};

TEST_F(Vector3Test, InvertTest) {
    v1.invert();
    EXPECT_NEAR(v1.x, -1.0, epsilon);
    EXPECT_NEAR(v1.y, -2.0, epsilon);
    EXPECT_NEAR(v1.z, -3.0, epsilon);
}

TEST_F(Vector3Test, MagnitudeTest) {
    real mag = v1.magnitude();
    EXPECT_NEAR(mag, std::sqrt(14.0), epsilon);
}

TEST_F(Vector3Test, SquareMagnitudeTest) {
    EXPECT_NEAR(v1.squareMagnitude(), 14.0, epsilon);
}

TEST_F(Vector3Test, NormalizeTest) {
    v1.normalize();
    EXPECT_NEAR(v1.magnitude(), 1.0, epsilon);
}

TEST_F(Vector3Test, ScalarMultiplication) {
    Vector3 scaled = v1 * 2.0;
    EXPECT_NEAR(scaled.x, 2.0, epsilon);
    EXPECT_NEAR(scaled.y, 4.0, epsilon);
    EXPECT_NEAR(scaled.z, 6.0, epsilon);
}

TEST_F(Vector3Test, ScalarMultiplicationAssignment) {
    v1 *= 3.0;
    EXPECT_NEAR(v1.x, 3.0, epsilon);
    EXPECT_NEAR(v1.y, 6.0, epsilon);
    EXPECT_NEAR(v1.z, 9.0, epsilon);
}

TEST_F(Vector3Test, AdditionOperator) {
    Vector3 result = v1 + v2;
    EXPECT_NEAR(result.x, 0.0, epsilon);
    EXPECT_NEAR(result.y, 6.0, epsilon);
    EXPECT_NEAR(result.z, 3.5, epsilon);
}

TEST_F(Vector3Test, AdditionAssignmentOperator) {
    v1 += v2;
    EXPECT_NEAR(v1.x, 0.0, epsilon);
    EXPECT_NEAR(v1.y, 6.0, epsilon);
    EXPECT_NEAR(v1.z, 3.5, epsilon);
}

TEST_F(Vector3Test, SubtractionOperator) {
    Vector3 result = v1 - v2;
    EXPECT_NEAR(result.x, 2.0, epsilon);
    EXPECT_NEAR(result.y, -2.0, epsilon);
    EXPECT_NEAR(result.z, 2.5, epsilon);
}

TEST_F(Vector3Test, SubtractionAssignmentOperator) {
    v1 -= v2;
    EXPECT_NEAR(v1.x, 2.0, epsilon);
    EXPECT_NEAR(v1.y, -2.0, epsilon);
    EXPECT_NEAR(v1.z, 2.5, epsilon);
}

TEST_F(Vector3Test, AddScaledVector) {
    v1.addScaledVector(v2, 2.0);
    EXPECT_NEAR(v1.x, -1.0, epsilon);
    EXPECT_NEAR(v1.y, 10.0, epsilon);
    EXPECT_NEAR(v1.z, 4.0, epsilon);
}

TEST_F(Vector3Test, ComponentProduct) {
    Vector3 result = v1.componentProduct(v2);
    EXPECT_NEAR(result.x, -1.0, epsilon);
    EXPECT_NEAR(result.y, 8.0, epsilon);
    EXPECT_NEAR(result.z, 1.5, epsilon);
}

TEST_F(Vector3Test, ComponentProductUpdate) {
    v1.componentProductUpdate(v2);
    EXPECT_NEAR(v1.x, -1.0, epsilon);
    EXPECT_NEAR(v1.y, 8.0, epsilon);
    EXPECT_NEAR(v1.z, 1.5, epsilon);
}

TEST_F(Vector3Test, ScalarProduct) {
    real result = v1.scalarProduct(v2);
    EXPECT_NEAR(result, (1.0)*(-1.0) + (2.0)*(4.0) + (3.0)*(0.5), epsilon);
}

TEST_F(Vector3Test, OperatorScalarProduct) {
    real result = v1 * v2;
    EXPECT_NEAR(result, (1.0)*(-1.0) + (2.0)*(4.0) + (3.0)*(0.5), epsilon);
}

TEST_F(Vector3Test, VectorProduct) {
    Vector3 result = v1.vectorProduct(v2);
    EXPECT_NEAR(result.x, -11.0, epsilon);
    EXPECT_NEAR(result.y, -3.5, epsilon);
    EXPECT_NEAR(result.z, 6.0, epsilon);
}

TEST_F(Vector3Test, OperatorVectorProduct) {
    Vector3 result = v1 % v2;
    EXPECT_NEAR(result.x, -11.0, epsilon);
    EXPECT_NEAR(result.y, -3.5, epsilon);
    EXPECT_NEAR(result.z, 6.0, epsilon);
}

TEST_F(Vector3Test, OperatorVectorProductAssignment) {
    v1 %= v2;
    EXPECT_NEAR(v1.x, -11.0, epsilon);
    EXPECT_NEAR(v1.y, -3.5, epsilon);
    EXPECT_NEAR(v1.z, 6.0, epsilon);
}
