#define BOOST_TEST_DYN_LINK
#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>
#include "matrixIO.hpp"

using namespace Eigen;
using namespace matrixIO;

struct MatrixIOFixture {
  MatrixIOFixture()
  {
    // Initialize the expected matrix
    expectedMatrix = MatrixXd(3, 3);
    expectedMatrix << 0.680375, 0.59688, -0.329554,
        -0.211234, 0.823295, 0.536459,
        0.566198, -0.604897, -0.444451;
    fileName = "m3_test.csv";
    size     = 3;
  }

  MatrixXd    expectedMatrix;
  std::string fileName;
  int         size;
};

BOOST_FIXTURE_TEST_SUITE(MatrixIOTests, MatrixIOFixture, *boost::unit_test::tolerance(1e-12))

BOOST_AUTO_TEST_CASE(OpenDataTest)
{

  MatrixXd actualMatrix = openData(fileName, size);

  BOOST_TEST(actualMatrix.isApprox(expectedMatrix));
}

BOOST_AUTO_TEST_SUITE_END()