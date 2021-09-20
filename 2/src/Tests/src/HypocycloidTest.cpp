#include "pch.h"
#include <Hypocycloid.h>
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
	geometry::Hypocycloid H1(1, 12, 23);
	ASSERT_EQ(1, H1.getr());
	ASSERT_EQ(12, H1.getR());
	ASSERT_EQ(23, H1.getd());

	geometry::Hypocycloid H2(9, 33, 2);
	ASSERT_EQ(9, H2.getr());
	ASSERT_EQ(33, H2.getR());
	ASSERT_EQ(2, H2.getd());
		
	geometry::Hypocycloid H3(12, 3, 32);
	ASSERT_EQ(12, H3.getr());
	ASSERT_EQ(3, H3.getR());
	ASSERT_EQ(32, H3.getd());
}

TEST(Constructor, TestException)
{
	ASSERT_ANY_THROW(lab2::Hypocycloid(0));
	ASSERT_ANY_THROW(lab2::Hypocycloid(0, 5));
	ASSERT_ANY_THROW(lab2::Hypocycloid(-6, 5));
	ASSERT_ANY_THROW(lab2::Hypocycloid(7, 10));
	ASSERT_ANY_THROW(lab2::Hypocycloid(7, 0));

	try { lab2::Hypocycloid(7, -5, 9); }
	catch (std::exception& err) {
		std::cout << err.what();
		EXPECT_EQ(err.what(), std::string("Internal radius must be bigger than 0"));
	}
	catch (...) { FAIL() << "Expected other exception"; }
}

TEST(HypocycloidMethods, Setters)
{
	lab2::Hypocycloid h;
	h.setR_EX(10);
	ASSERT_EQ(10, h.getR_EX());
	h.setR_IN(9);
	ASSERT_EQ(9, h.getR_IN());
	h.setD(5);
	ASSERT_EQ(5, h.getD());

	ASSERT_ANY_THROW(h.setR_EX(-5));
	ASSERT_ANY_THROW(h.setR_IN(10));
	ASSERT_ANY_THROW(h.setR_IN(0));
	ASSERT_ANY_THROW(h.setR_IN(-12));
}

TEST(HypocycloidMethods, Parameters)
{
	lab2::Hypocycloid a;
	lab2::Hypocycloid b(5, 4, 6);
	lab2::Hypocycloid c(5, 4, 3);

	ASSERT_STREQ("Ordinary", a.type());
	ASSERT_STREQ("Elongated", b.type());
	ASSERT_STREQ("Shortened", c.type());

	ASSERT_EQ(lab2::Point(3, 1), a.limiting_radii());
	ASSERT_EQ(lab2::Point(7, 5), b.limiting_radii());
	ASSERT_EQ(lab2::Point(4, 2), c.limiting_radii());
}

TEST(HypocycloidMethods, Angle)
{
	const double err = 0.0001;
	double pi = 3.14159;
	lab2::Hypocycloid a;
	lab2::Hypocycloid b(10, 2, 3);
	lab2::Hypocycloid c(5, 4);

	ASSERT_NEAR(8, a.curvature_radius(pi), err);   
	ASSERT_NEAR(0.2857, b.curvature_radius(0), err);
	ASSERT_NEAR(5.0612, c.curvature_radius(2), err);

	ASSERT_NEAR(3, a.point_from_angle(0).x, err);
	ASSERT_NEAR(0, a.point_from_angle(0).y, err);
	ASSERT_NEAR(-5.388378, b.point_from_angle(3).x, err);
	ASSERT_NEAR(2.738678, b.point_from_angle(3).y, err);
	ASSERT_NEAR(-3, c.point_from_angle(-4 * pi).x, err);
	ASSERT_NEAR(0, c.point_from_angle(-4 * pi).y, err);

	ASSERT_NEAR(0, a.area(0), err);
	ASSERT_NEAR(29.191129, b.area(0.5 * pi), err);
	ASSERT_NEAR(-10.624769, c.area(2 * pi), err);
}


int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}