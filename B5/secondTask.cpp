#include <algorithm>
#include <iostream>
#include <numeric>
#include <iterator>
#include <vector>
#include "shape.hpp"

void secondTask(std::istream &in, std::ostream &out)
{
  std::vector <Shape> containerOfShapes((std::istream_iterator<Shape>(in)), std::istream_iterator<Shape>());
  if ((!in.eof()) && (in.fail() || in.bad()))
  {
    throw std::ios_base::failure("Error occurred while reading data!\n");
  }
  int sumOfVertices = std::accumulate(containerOfShapes.begin(), containerOfShapes.end(), 0,
  [](const size_t &sum, const Shape &shape)
  {
    return sum + shape.size();
  });
  int countTriangles = std::count_if(containerOfShapes.begin(), containerOfShapes.end(), isTriangle);
  int countRectangles = std::count_if(containerOfShapes.begin(), containerOfShapes.end(), isRectangle);
  int countSquares = std::count_if(containerOfShapes.begin(), containerOfShapes.end(), isSquare);
  containerOfShapes.erase(std::remove_if(containerOfShapes.begin(), containerOfShapes.end(), [](const Shape &shape)
  {
    return shape.size() == 5;
  }), end(containerOfShapes));
  std::vector <Point> points;
  std::transform(containerOfShapes.begin(), containerOfShapes.end(), std::back_inserter(points), [](const Shape &shape)
  {
    return shape.front();
  });
  std::vector <Point> vectorOfPoints;
  std::sort(containerOfShapes.begin(), containerOfShapes.end());
  out << "Vertices: " << sumOfVertices << "\n";
  out << "Triangles: " << countTriangles << "\n";
  out << "Squares: " << countSquares << "\n";
  out << "Rectangles: " << countRectangles << "\n";
  out << "Points: ";
  std::copy(points.begin(), points.end(), std::ostream_iterator<Point>(out, " "));
  out << "\nShapes:\n";
  std::copy(containerOfShapes.begin(), containerOfShapes.end(), std::ostream_iterator<Shape>(out, "\n"));
}
