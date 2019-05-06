#https://www.hackerrank.com/challenges/find-angle/problem
# Here I use the property that a median on the hypotenuse divides the triangle
# in two isosceles triangles, so the MBC angle will be equal to MCB.

from math import degrees, atan
#we will get the angle that forms the tangent of opposite(AB)/adjacent(BC)
print(round(degrees(atan(int(input())/int(input())))), end = "°")