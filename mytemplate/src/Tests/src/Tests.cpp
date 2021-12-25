#include "pch.h"
#include <Vector.h>
TEST(Vector, DefaultConstructor)
{
	VectorT<int> vect;
	EXPECT_EQ(vect.size(), 0);
	EXPECT_EQ(vect.capacity(), 0);
	vect.pushback(3);
	EXPECT_EQ(vect.size(), 1);
	EXPECT_EQ(vect.capacity(), 5);
}
TEST(Vector, Constructor)
{
	VectorT<int> vect(4);
	EXPECT_EQ(vect.size(), 0);
	EXPECT_EQ(vect.capacity(), 4);
}
TEST(Vector, CapacityandModifiers)
{
	VectorT<int> vect(3);
	EXPECT_TRUE(vect.empty());

	EXPECT_EQ(vect.size(), 0);
	EXPECT_EQ(vect.capacity(), 3);
	
	vect.pushback(2);
	EXPECT_EQ(vect.size(), 1);
	vect.clear();
	EXPECT_TRUE(vect.empty());
}
TEST(Vector, OperatorEqual)
{
	VectorT<int> vect1({ 1,2,3 });
	VectorT<int> vect2({ 1,2,3 });
	EXPECT_TRUE(vect1 == vect2);
	vect1.pushback(3);
	EXPECT_TRUE(vect1 != vect2);
}
TEST(Vector, Iterator)
{
	VectorT<int> vector({ 34,2,6 });
	VectorT<int>::Iterator begin = vector.begin();
	VectorT<int>::Iterator end = vector.end();

	EXPECT_TRUE(begin == vector.begin());
	++begin;
	EXPECT_EQ(*begin, 2);
	--begin;
	EXPECT_EQ(*begin, 34);
	
}
TEST(Vector, ConstIterator)
{
	VectorT<int> vector({ 3,11 });
	VectorT<int>::ConstIterator begin = vector.cbegin();
	VectorT<int>::ConstIterator end = vector.cend();

	EXPECT_TRUE(begin == vector.cbegin());
	++begin;
	EXPECT_EQ(*begin, 11);
	--begin;
	EXPECT_EQ(*begin, 3);
	--end;
	EXPECT_EQ(*end, 11);
}
int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}