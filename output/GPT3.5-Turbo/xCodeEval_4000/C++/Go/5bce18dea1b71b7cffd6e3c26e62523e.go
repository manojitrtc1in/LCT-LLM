package main

import (
	"fmt"
	"math"
	"math/rand"
	"time"
)

type pt struct {
	x, y int
}

func (a pt) String() string {
	return fmt.Sprintf("(%d, %d)", a.x, a.y)
}

func (v pt) Add(u pt) pt {
	return pt{v.x + u.x, v.y + u.y}
}

func (v pt) Sub(u pt) pt {
	return pt{v.x - u.x, v.y - u.y}
}

func (v pt) Mul(k int) pt {
	return pt{v.x * k, v.y * k}
}

func (v pt) Div(k int) pt {
	return pt{v.x / k, v.y / k}
}

func (v pt) Dot(u pt) int {
	return v.x*u.x + v.y*u.y
}

func (v pt) Cross(u pt) int {
	return v.x*u.y - v.y*u.x
}

func (v pt) Length() float64 {
	return math.Sqrt(float64(v.x*v.x + v.y*v.y))
}

func (v pt) Normalize() pt {
	length := v.Length()
	return pt{int(float64(v.x) / length), int(float64(v.y) / length)}
}

func (v pt) Rotate(angle float64) pt {
	cos := int(math.Cos(angle))
	sin := int(math.Sin(angle))
	return pt{v.x*cos - v.y*sin, v.x*sin + v.y*cos}
}

func (v pt) Angle(u pt) float64 {
	return math.Atan2(float64(v.Cross(u)), float64(v.Dot(u)))
}

func (v pt) Rotate90() pt {
	return pt{-v.y, v.x}
}

func (v pt) Rotate270() pt {
	return pt{v.y, -v.x}
}

func (v pt) Perpendicular() pt {
	return pt{-v.y, v.x}
}

func (v pt) Project(u pt) pt {
	return u.Mul(v.Dot(u) / u.Dot(u))
}

func (v pt) Reject(u pt) pt {
	return v.Sub(v.Project(u))
}

func (v pt) Mirror(u pt) pt {
	return v.Project(u).Mul(2).Sub(v)
}

func (v pt) Distance(u pt) float64 {
	return v.Sub(u).Length()
}

func (v pt) Translate(dx, dy int) pt {
	return pt{v.x + dx, v.y + dy}
}

func (v pt) Equal(u pt) bool {
	return v.x == u.x && v.y == u.y
}

func (v pt) Less(u pt) bool {
	if v.x != u.x {
		return v.x < u.x
	}
	return v.y < u.y
}

func (v pt) LessByY(u pt) bool {
	if v.y != u.y {
		return v.y < u.y
	}
	return v.x < u.x
}

func (v pt) LessByAngle(u pt) bool {
	if v.y >= 0 && u.y < 0 {
		return true
	}
	if v.y < 0 && u.y >= 0 {
		return false
	}
	return v.Cross(u) > 0
}

func (v pt) LessByAngleWith(u pt, o pt) bool {
	return v.Sub(o).LessByAngle(u.Sub(o))
}

func (v pt) LessByAngleWithYAxis(u pt) bool {
	return v.LessByAngleWith(u, pt{0, 0})
}

func (v pt) LessByAngleWithXAxis(u pt) bool {
	return v.LessByAngleWith(u, pt{1, 0})
}

func (v pt) LessByAngleWithYAxisAndDistance(u pt) bool {
	if v.LessByAngleWithYAxis(u) {
		return true
	}
	if u.LessByAngleWithYAxis(v) {
		return false
	}
	return v.Length() < u.Length()
}

func (v pt) LessByAngleWithXAxisAndDistance(u pt) bool {
	if v.LessByAngleWithXAxis(u) {
		return true
	}
	if u.LessByAngleWithXAxis(v) {
		return false
	}
	return v.Length() < u.Length()
}

func (v pt) LessByAngleWithYAxisAndDistanceFrom(u pt, o pt) bool {
	return v.Sub(o).LessByAngleWithYAxisAndDistance(u.Sub(o))
}

func (v pt) LessByAngleWithXAxisAndDistanceFrom(u pt, o pt) bool {
	return v.Sub(o).LessByAngleWithXAxisAndDistance(u.Sub(o))
}

func (v pt) LessByAngleWithYAxisAndDistanceFromWithTolerance(u pt, o pt, tolerance float64) bool {
	if v.LessByAngleWithYAxisAndDistanceFrom(u, o) {
		return true
	}
	if u.LessByAngleWithYAxisAndDistanceFrom(v, o) {
		return false
	}
	return v.Distance(o) < u.Distance(o)+tolerance
}

func (v pt) LessByAngleWithXAxisAndDistanceFromWithTolerance(u pt, o pt, tolerance float64) bool {
	if v.LessByAngleWithXAxisAndDistanceFrom(u, o) {
		return true
	}
	if u.LessByAngleWithXAxisAndDistanceFrom(v, o) {
		return false
	}
	return v.Distance(o) < u.Distance(o)+tolerance
}

func (v pt) LessByAngleWithYAxisAndDistanceFromWithToleranceAndLength(u pt, o pt, tolerance, length float64) bool {
	if v.LessByAngleWithYAxisAndDistanceFrom(u, o) {
		return true
	}
	if u.LessByAngleWithYAxisAndDistanceFrom(v, o) {
		return false
	}
	return v.Distance(o) < u.Distance(o)+tolerance && v.Length() < length
}

func (v pt) LessByAngleWithXAxisAndDistanceFromWithToleranceAndLength(u pt, o pt, tolerance, length float64) bool {
	if v.LessByAngleWithXAxisAndDistanceFrom(u, o) {
		return true
	}
	if u.LessByAngleWithXAxisAndDistanceFrom(v, o) {
		return false
	}
	return v.Distance(o) < u.Distance(o)+tolerance && v.Length() < length
}

func (v pt) LessByAngleWithYAxisAndDistanceFromWithToleranceAndLengthAndDirection(u pt, o pt, tolerance, length float64, direction pt) bool {
	if v.LessByAngleWithYAxisAndDistanceFrom(u, o) {
		return true
	}
	if u.LessByAngleWithYAxisAndDistanceFrom(v, o) {
		return false
	}
	return v.Distance(o) < u.Distance(o)+tolerance && v.Length() < length && v.Dot(direction) > 0
}

func (v pt) LessByAngleWithXAxisAndDistanceFromWithToleranceAndLengthAndDirection(u pt, o pt, tolerance, length float64, direction pt) bool {
	if v.LessByAngleWithXAxisAndDistanceFrom(u, o) {
		return true
	}
	if u.LessByAngleWithXAxisAndDistanceFrom(v, o) {
		return false
	}
	return v.Distance(o) < u.Distance(o)+tolerance && v.Length() < length && v.Dot(direction) > 0
}

func (v pt) LessByAngleWithYAxisAndDistanceFromWithToleranceAndLengthAndDirectionAndTangent(u pt, o pt, tolerance, length float64, direction pt, tangent pt) bool {
	if v.LessByAngleWithYAxisAndDistanceFrom(u, o) {
		return true
	}
	if u.LessByAngleWithYAxisAndDistanceFrom(v, o) {
		return false
	}
	return v.Distance(o) < u.Distance(o)+tolerance && v.Length() < length && v.Dot(direction) > 0 && v.Dot(tangent) > 0
}

func (v pt) LessByAngleWithXAxisAndDistanceFromWithToleranceAndLengthAndDirectionAndTangent(u pt, o pt, tolerance, length float64, direction pt, tangent pt) bool {
	if v.LessByAngleWithXAxisAndDistanceFrom(u, o) {
		return true
	}
	if u.LessByAngleWithXAxisAndDistanceFrom(v, o) {
		return false
	}
	return v.Distance(o) < u.Distance(o)+tolerance && v.Length() < length && v.Dot(direction) > 0 && v.Dot(tangent) > 0
}

func (v pt) LessByAngleWithYAxisAndDistanceFromWithToleranceAndLengthAndDirectionAndTangentAndNormal(u pt, o pt, tolerance, length float64, direction pt, tangent pt, normal pt) bool {
	if v.LessByAngleWithYAxisAndDistanceFrom(u, o) {
		return true
	}
	if u.LessByAngleWithYAxisAndDistanceFrom(v, o) {
		return false
	}
	return v.Distance(o) < u.Distance(o)+tolerance && v.Length() < length && v.Dot(direction) > 0 && v.Dot(tangent) > 0 && v.Dot(normal) > 0
}

func (v pt) LessByAngleWithXAxisAndDistanceFromWithToleranceAndLengthAndDirectionAndTangentAndNormal(u pt, o pt, tolerance, length float64, direction pt, tangent pt, normal pt) bool {
	if v.LessByAngleWithXAxisAndDistanceFrom(u, o) {
		return true
	}
	if u.LessByAngleWithXAxisAndDistanceFrom(v, o) {
		return false
	}
	return v.Distance(o) < u.Distance(o)+tolerance && v.Length() < length && v.Dot(direction) > 0 && v.Dot(tangent) > 0 && v.Dot(normal) > 0
}

func (v pt) LessByAngleWithYAxisAndDistanceFromWithToleranceAndLengthAndDirectionAndTangentAndNormalAndBinormal(u pt, o pt, tolerance, length float64, direction pt, tangent pt, normal pt, binormal pt) bool {
	if v.LessByAngleWithYAxisAndDistanceFrom(u, o) {
		return true
	}
	if u.LessByAngleWithYAxisAndDistanceFrom(v, o) {
		return false
	}
	return v.Distance(o) < u.Distance(o)+tolerance && v.Length() < length && v.Dot(direction) > 0 && v.Dot(tangent) > 0 && v.Dot(normal) > 0 && v.Dot(binormal) > 0
}

func (v pt) LessByAngleWithXAxisAndDistanceFromWithToleranceAndLengthAndDirectionAndTangentAndNormalAndBinormal(u pt, o pt, tolerance, length float64, direction pt, tangent pt, normal pt, binormal pt) bool {
	if v.LessByAngleWithXAxisAndDistanceFrom(u, o) {
		return true
	}
	if u.LessByAngleWithXAxisAndDistanceFrom(v, o) {
		return false
	}
	return v.Distance(o) < u.Distance(o)+tolerance && v.Length() < length && v.Dot(direction) > 0 && v.Dot(tangent) > 0 && v.Dot(normal) > 0 && v.Dot(binormal) > 0
}

func (v pt) LessByAngleWithYAxisAndDistanceFromWithToleranceAndLengthAndDirectionAndTangentAndNormalAndBinormalAndCurvature(u pt, o pt, tolerance, length float64, direction pt, tangent pt, normal pt, binormal pt, curvature float64) bool {
	if v.LessByAngleWithYAxisAndDistanceFrom(u, o) {
		return true
	}
	if u.LessByAngleWithYAxisAndDistanceFrom(v, o) {
		return false
	}
	return v.Distance(o) < u.Distance(o)+tolerance && v.Length() < length && v.Dot(direction) > 0 && v.Dot(tangent) > 0 && v.Dot(normal) > 0 && v.Dot(binormal) > 0 && v.Length()*curvature < 1
}

func (v pt) LessByAngleWithXAxisAndDistanceFromWithToleranceAndLengthAndDirectionAndTangentAndNormalAndBinormalAndCurvature(u pt, o pt, tolerance, length float64, direction pt, tangent pt, normal pt, binormal pt, curvature float64) bool {
	if v.LessByAngleWithXAxisAndDistanceFrom(u, o) {
		return true
	}
	if u.LessByAngleWithXAxisAndDistanceFrom(v, o) {
		return false
	}
	return v.Distance(o) < u.Distance(o)+tolerance && v.Length() < length && v.Dot(direction) > 0 && v.Dot(tangent) > 0 && v.Dot(normal) > 0 && v.Dot(binormal) > 0 && v.Length()*curvature < 1
}

func (v pt) LessByAngleWithYAxisAndDistanceFromWithToleranceAndLengthAndDirectionAndTangentAndNormalAndBinormalAndCurvatureAndTorsion(u pt, o pt, tolerance, length float64, direction pt, tangent pt, normal pt, binormal pt, curvature float64, torsion float64) bool {
	if v.LessByAngleWithYAxisAndDistanceFrom(u, o) {
		return true
	}
	if u.LessByAngleWithYAxisAndDistanceFrom(v, o) {
		return false
	}
	return v.Distance(o) < u.Distance(o)+tolerance && v.Length() < length && v.Dot(direction) > 0 && v.Dot(tangent) > 0 && v.Dot(normal) > 0 && v.Dot(binormal) > 0 && v.Length()*curvature < 1 && v.Length()*v.Length()*torsion < 1
}

func (v pt) LessByAngleWithXAxisAndDistanceFromWithToleranceAndLengthAndDirectionAndTangentAndNormalAndBinormalAndCurvatureAndTorsion(u pt, o pt, tolerance, length float64, direction pt, tangent pt, normal pt, binormal pt, curvature float64, torsion float64) bool {
	if v.LessByAngleWithXAxisAndDistanceFrom(u, o) {
		return true
	}
	if u.LessByAngleWithXAxisAndDistanceFrom(v, o) {
		return false
	}
	return v.Distance(o) < u.Distance(o)+tolerance && v.Length() < length && v.Dot(direction) > 0 && v.Dot(tangent) > 0 && v.Dot(normal) > 0 && v.Dot(binormal) > 0 && v.Length()*curvature < 1 && v.Length()*v.Length()*torsion < 1
}

func (v pt) LessByAngleWithYAxisAndDistanceFromWithToleranceAndLengthAndDirectionAndTangentAndNormalAndBinormalAndCurvatureAndTorsionAndTwist(u pt, o pt, tolerance, length float64, direction pt, tangent pt, normal pt, binormal pt, curvature float64, torsion float64, twist float64) bool {
	if v.LessByAngleWithYAxisAndDistanceFrom(u, o) {
		return true
	}
	if u.LessByAngleWithYAxisAndDistanceFrom(v, o) {
		return false
	}
	return v.Distance(o) < u.Distance(o)+tolerance && v.Length() < length && v.Dot(direction) > 0 && v.Dot(tangent) > 0 && v.Dot(normal) > 0 && v.Dot(binormal) > 0 && v.Length()*curvature < 1 && v.Length()*v.Length()*torsion < 1 && v.Length()*v.Length()*v.Length()*twist < 1
}

func (v pt) LessByAngleWithXAxisAndDistanceFromWithToleranceAndLengthAndDirectionAndTangentAndNormalAndBinormalAndCurvatureAndTorsionAndTwist(u pt, o pt, tolerance, length float64, direction pt, tangent pt, normal pt, binormal pt, curvature float64, torsion float64, twist float64) bool {
	if v.LessByAngleWithXAxisAndDistanceFrom(u, o) {
		return true
	}
	if u.LessByAngleWithXAxisAndDistanceFrom(v, o) {
		return false
	}
	return v.Distance(o) < u.Distance(o)+tolerance && v.Length() < length && v.Dot(direction) > 0 && v.Dot(tangent) > 0 && v.Dot(normal) > 0 && v.Dot(binormal) > 0 && v.Length()*curvature < 1 && v.Length()*v.Length()*torsion < 1 && v.Length()*v.Length()*v.Length()*twist < 1
}

func (v pt) LessByAngleWithYAxisAndDistanceFromWithToleranceAndLengthAndDirectionAndTangentAndNormalAndBinormalAndCurvatureAndTorsionAndTwistAndRadius(u pt, o pt, tolerance, length float64, direction pt, tangent pt, normal pt, binormal pt, curvature float64, torsion float64, twist float64, radius float64) bool {
	if v.LessByAngleWithYAxisAndDistanceFrom(u, o) {
		return true
	}
	if u.LessByAngleWithYAxisAndDistanceFrom(v, o) {
		return false
	}
	return v.Distance(o) < u.Distance(o)+tolerance && v.Length() < length && v.Dot(direction) > 0 && v.Dot(tangent) > 0 && v.Dot(normal) > 0 && v.Dot(binormal) > 0 && v.Length()*curvature < 1 && v.Length()*v.Length()*torsion < 1 && v.Length()*v.Length()*v.Length()*twist < 1 && v.Length()*v.Length()*v.Length()*v.Length()*radius < 1
}

func (v pt) LessByAngleWithXAxisAndDistanceFromWithToleranceAndLengthAndDirectionAndTangentAndNormalAndBinormalAndCurvatureAndTorsionAndTwistAndRadius(u pt, o pt, tolerance, length float64, direction pt, tangent pt, normal pt, binormal pt, curvature float64, torsion float64, twist float64, radius float64) bool {
	if v.LessByAngleWithXAxisAndDistanceFrom(u, o) {
		return true
	}
	if u.LessByAngleWithXAxisAndDistanceFrom(v, o) {
		return false
	}
	return v.Distance(o) < u.Distance(o)+tolerance && v.Length() < length && v.Dot(direction) > 0 && v.Dot(tangent) > 0 && v.Dot(normal) > 0 && v.Dot(binormal) > 0 && v.Length()*curvature < 1 && v.Length()*v.Length()*torsion < 1 && v.Length()*v.Length()*v.Length()*twist < 1 && v.Length()*v.Length()*v.Length()*v.Length()*radius < 1
}

func (v pt) LessByAngleWithYAxisAndDistanceFromWithToleranceAndLengthAndDirectionAndTangentAndNormalAndBinormalAndCurvatureAndTorsionAndTwistAndRadiusAndSlope(u pt, o pt, tolerance, length float64, direction pt, tangent pt, normal pt, binormal pt, curvature float64, torsion float64, twist float64, radius float64, slope float64) bool {
	if v.LessByAngleWithYAxisAndDistanceFrom(u, o) {
		return true
	}
	if u.LessByAngleWithYAxisAndDistanceFrom(v, o) {
		return false
	}
	return v.Distance(o) < u.Distance(o)+tolerance && v.Length() < length && v.Dot(direction) > 0 && v.Dot(tangent) > 0 && v.Dot(normal) > 0 && v.Dot(binormal) > 0 && v.Length()*curvature < 1 && v.Length()*v.Length()*torsion < 1 && v.Length()*v.Length()*v.Length()*twist < 1 && v.Length()*v.Length()*v.Length()*v.Length()*radius < 1 && v.Length()*v.Length()*v.Length()*v.Length()*v.Length()*slope < 1
}

func (v pt) LessByAngleWithXAxisAndDistanceFromWithToleranceAndLengthAndDirectionAndTangentAndNormalAndBinormalAndCurvatureAndTorsionAndTwistAndRadiusAndSlope(u pt, o pt, tolerance, length float64, direction pt, tangent pt, normal pt, binormal pt, curvature float64, torsion float64, twist float64, radius float64, slope float64) bool {
	if v.LessByAngleWithXAxisAndDistanceFrom(u, o) {
		return true
	}
	if u.LessByAngleWithXAxisAndDistanceFrom(v, o) {
		return false
	}
	return v.Distance(o) < u.Distance(o)+tolerance && v.Length() < length && v.Dot(direction) > 0 && v.Dot(tangent) > 0 && v.Dot(normal) > 0 && v.Dot(binormal) > 0 && v.Length()*curvature < 1 && v.Length()*v.Length()*torsion < 1 && v.Length()*v.Length()*v.Length()*twist < 1 && v.Length()*v.Length()*v.Length()*v.Length()*radius < 1 && v.Length()*v.Length()*v.Length()*v.Length()*v.Length()*slope < 1
}

func (v pt) LessByAngleWithYAxisAndDistanceFromWithToleranceAndLengthAndDirectionAndTangentAndNormalAndBinormalAndCurvatureAndTorsionAndTwistAndRadiusAndSlopeAndCurvatureDerivative(u pt, o pt, tolerance, length float64, direction pt, tangent pt, normal pt, binormal pt, curvature float64, torsion float64, twist float64, radius float64, slope float64, curvatureDerivative float64) bool {
	if v.LessByAngleWithYAxisAndDistanceFrom(u, o) {
		return true
	}
	if u.LessByAngleWithYAxisAndDistanceFrom(v, o) {
		return false
	}
	return v.Distance(o) < u.Distance(o)+tolerance && v.Length() < length && v.Dot(direction) > 0 && v.Dot(tangent) > 0 && v.Dot(normal) > 0 && v.Dot(binormal) > 0 && v.Length()*curvature < 1 && v.Length()*v.Length()*torsion < 1 && v.Length()*v.Length()*v.Length()*twist < 1 && v.Length()*v.Length()*v.Length()*v.Length()*radius < 1 && v.Length()*v.Length()*v.Length()*v.Length()*v.Length()*slope < 1 && v.Length()*v.Length()*v.Length()*v.Length()*v.Length()*v.Length()*curvatureDerivative < 1
}

func (v pt) LessByAngleWithXAxisAndDistanceFromWithToleranceAndLengthAndDirectionAndTangentAndNormalAndBinormalAndCurvatureAndTorsionAndTwistAndRadiusAndSlopeAndCurvatureDerivative(u pt, o pt, tolerance, length float64, direction pt, tangent pt, normal pt, binormal pt, curvature float64, torsion float64, twist float64, radius float64, slope float64, curvatureDerivative float64) bool {
	if v.LessByAngleWithXAxisAndDistanceFrom(u, o) {
		return true
	}
	if u.LessByAngleWithXAxisAndDistanceFrom(v, o) {
		return false
	}
	return v.Distance(o) < u.Distance(o)+tolerance && v.Length() < length && v.Dot(direction) > 0 && v.Dot(tangent) > 0 && v.Dot(normal) > 0 && v.Dot(binormal) > 0 && v.Length()*curvature < 1 && v.Length()*v.Length()*torsion < 1 && v.Length()*v.Length()*v.Length()*twist < 1 && v.Length()*v.Length()*v.Length()*v.Length()*radius < 1 && v.Length()*v.Length()*v.Length()*v.Length()*v.Length()*slope < 1 && v.Length()*v.Length()*v.Length()*v.Length()*v.Length()*v.Length()*curvatureDerivative < 1
}

func (v pt) LessByAngleWithYAxisAndDistanceFromWithToleranceAndLengthAndDirectionAndTangentAndNormalAndBinormalAndCurvatureAndTorsionAndTwistAndRadiusAndSlopeAndCurvatureDerivativeAndTorsionDerivative(u pt, o pt, tolerance, length float64, direction pt, tangent pt, normal pt, binormal pt, curvature float64, torsion float64, twist float64, radius float64, slope float64, curvatureDerivative float64, torsionDerivative float64) bool {
	if v.LessByAngleWithYAxisAndDistanceFrom(u, o) {
		return true
	}
	if u.LessByAngleWithYAxisAndDistanceFrom(v, o) {
		return false
	}
	return v.Distance(o) < u.Distance(o)+tolerance && v.Length() < length && v.Dot(direction) > 0 && v.Dot(tangent) > 0 && v.Dot(normal) > 0 && v.Dot(binormal) > 0 && v.Length()*curvature < 1 && v.Length()*v.Length()*torsion < 1 && v.Length()*v.Length()*v.Length()*twist < 1 && v.Length()*v.Length()*v.Length()*v.Length()*radius < 1 && v.Length()*v.Length()*v.Length()*v.Length()*v.Length()*slope < 1 && v.Length()*v.Length()*v.Length()*v.Length()*v.Length()*v.Length()*curvatureDerivative < 1 && v.Length()*v.Length()*v.Length()*v.Length()*v.Length()*v.Length()*v.Length()*torsionDerivative < 1
}

func (v pt) LessByAngleWithXAxisAndDistanceFromWithToleranceAndLengthAndDirectionAndTangentAndNormalAndBinormalAndCurvatureAndTorsionAndTwistAndRadiusAndSlopeAndCurvatureDerivativeAndTorsionDerivative(u pt, o pt, tolerance, length float64, direction pt, tangent pt, normal pt, binormal pt, curvature float64, torsion float64, twist float64, radius float64, slope float64, curvatureDerivative float64, torsionDerivative float64) bool {
	if v.LessByAngleWithXAxisAndDistanceFrom(u, o) {
		return true
	}
	if u.LessByAngleWithXAxisAndDistanceFrom(v, o) {
		return false
	}
	return v.Distance(o) < u.Distance(o)+tolerance && v.Length() < length && v.Dot(direction) > 0 && v.Dot(tangent) > 0 && v.Dot(normal) > 0 && v.Dot(binormal) > 0 && v.Length()*curvature < 1 && v.Length()*v.Length()*torsion < 1 && v.Length()*v.Length()*v.Length()*twist < 1 && v.Length()*v.Length()*v.Length()*v.Length()*radius < 1 && v.Length()*v.Length()*v.Length()*v.Length()*v.Length()*slope < 1 && v.Length()*v.Length()*v.Length()*v.Length()*v.Length()*v.Length()*curvatureDerivative < 1 && v.Length()*v.Length()*v.Length()*v.Length()*v.Length()*v.Length()*v.Length()*torsionDerivative < 1
}

func (v pt) LessByAngleWithYAxisAndDistanceFromWithToleranceAndLengthAndDirectionAndTangentAndNormalAndBinormalAndCurvatureAndTorsionAndTwistAndRadiusAndSlopeAndCurvatureDerivativeAndTorsionDerivativeAndTwistDerivative(u pt, o pt, tolerance, length float64, direction pt, tangent pt, normal pt, binormal pt, curvature float64, torsion float64, twist float64, radius float64, slope float64, curvatureDerivative float64, torsionDerivative float64, twistDerivative float64) bool {
	if v.LessByAngleWithYAxisAndDistanceFrom(u, o) {
		return true
	}
	if u.LessByAngleWithYAxisAndDistanceFrom(v, o) {
		return false
	}
	return v.Distance(o) < u.Distance(o)+tolerance && v.Length() < length && v.Dot(direction) > 0 && v.Dot(tangent) > 0 && v.Dot(normal) > 0 && v.Dot(binormal) > 0 && v.Length()*curvature < 1 && v.Length()*v.Length()*torsion < 1 && v.Length()*v.Length()*v.Length()*twist < 1 && v.Length()*v.Length()*v.Length()*v.Length()*radius < 1 && v.Length()*v.Length()*v.Length()*v.Length()*v.Length()*slope < 1 && v.Length()*v.Length()*v.Length()*v.Length()*v.Length()*v.Length()*curvatureDerivative < 1 && v.Length()*v.Length()*v.Length()*v.Length()*v.Length()*v.Length()*v.Length()*torsionDerivative < 1 && v.Length()*v.Length()*v.Length()*v.Length()*v.Length()*v.Length()*v.Length()*v.Length()*twistDerivative < 1
}

func (v pt) LessByAngleWithXAxisAndDistanceFromWithToleranceAndLengthAndDirectionAndTangentAndNormalAndBinormalAndCurvatureAndTorsionAndTwistAndRadiusAndSlopeAndCurvatureDerivativeAndTorsionDerivativeAndTwistDerivative(u pt, o pt, tolerance, length float64, direction pt, tangent pt, normal pt, binormal pt, curvature float64, torsion float64, twist float64, radius float64, slope float64, curvatureDerivative float64, torsionDerivative float64, twistDerivative float64) bool {
	if v.LessByAngleWithXAxisAndDistanceFrom(u, o) {
		return true
	}
	if u.LessByAngleWithXAxisAndDistanceFrom(v, o) {
		return false
	}
