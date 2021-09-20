#include "pch.h"
#include <Hypocycloid.h>
//#include <Hypocycloid.h>
const double error = 0.001; //значение ошибки в соответствии с рекомендацией Ларисы Ивановны
TEST(Constructor, SimpleConstructor)
{
	geometry::Hypocycloid Hypocycloid(3, 4, 2);
	ASSERT_EQ(3, Hypocycloid.getr());
	ASSERT_EQ(4, Hypocycloid.getR());
	ASSERT_EQ(2, Hypocycloid.getd());
}

TEST(Constructor, SeveralConstructors)
{
	geometry::Hypocycloid H1(1, 12, 2);
	ASSERT_EQ(1, H1.getr());
	ASSERT_EQ(12, H1.getR());
	ASSERT_EQ(2, H1.getd());

	geometry::Hypocycloid H2(9, 33, 2);
	ASSERT_EQ(9, H2.getr());
	ASSERT_EQ(33, H2.getR());
	ASSERT_EQ(2, H2.getd());
		
	geometry::Hypocycloid H3(1, 3, 3);
	ASSERT_EQ(1, H3.getr());
	ASSERT_EQ(3, H3.getR());
	ASSERT_EQ(3, H3.getd());
}

TEST(Constructor, Error)
{
	try { geometry::Hypocycloid H1(1, 12, 1); }
	catch (std::invalid_argument& err)
	{
		std::cout << err.what();
		EXPECT_EQ(err.what(), std::string("Incorrect pen length (less than 1)!"));
	}
	try { geometry::Hypocycloid H1(0, 12, 13); }
	catch (std::invalid_argument& err) {
		std::cout << err.what();
		EXPECT_EQ(err.what(), std::string("Incorrect generating circle radius (less than 0)!"));
	}

	EXPECT_THROW(geometry::Hypocycloid H1(1, -12, 13), std::invalid_argument);
}

TEST(Hypocycloid, Setters)
{
	geometry::Hypocycloid H1(1, 12, 4);
	H1.setr(4);
	H1.setR(11);
	H1.setd(5);
	EXPECT_EQ(4, H1.getr());
	EXPECT_EQ(11, H1.getR());
	EXPECT_EQ(5, H1.getd());
}
TEST(Hypocycloid, SettersError)
{
	geometry::Hypocycloid H1(1, 8, 4);
	EXPECT_THROW(H1.setr(8), std::invalid_argument);
 }
TEST(Hypocycloid, Type)
{
	geometry::Hypocycloid H1(2, 12, 4);
	geometry::Hypocycloid H2(3, 12, 2);
	geometry::Hypocycloid H3(2, 7, 2);

	EXPECT_STREQ("Elongated Hypocycloid", H1.Hypocycloid_type());
	EXPECT_STREQ("Shortened Hypocycloid", H2.Hypocycloid_type());
	EXPECT_STREQ("Normal Hypocycloid", H3.Hypocycloid_type());
}
TEST(Hypocycloid, Area)
{
	geometry::Hypocycloid H2(4, 8, 5);
	EXPECT_NEAR(135, H2.Hypocycloid_Area(30), error);
}
TEST(Hypocycloid, RadiusCurv)
{
	geometry::Hypocycloid H1(4, 5, 4);
	EXPECT_NEAR(0.53, H1.Radius_of_Curvature(30), error);

	geometry::Hypocycloid H2(2, 6, 3);
	EXPECT_NEAR(12.48, H2.Radius_of_Curvature(45), error);

	geometry::Hypocycloid H3(4, 7, 2);
	EXPECT_NEAR(8.597, H3.Radius_of_Curvature(30), error);
}

TEST(Hypocycloid, Point)
{
	double x, y;
	geometry::Hypocycloid H1(4, 5, 4);
	H1.getPoint(30, x, y);
	EXPECT_NEAR(1.54, x, error);
	EXPECT_NEAR(-4.74, y, error);
}
int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}