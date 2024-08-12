#include "headers/SingleList.hpp"

#include <gtest/gtest.h>

TEST(IntSingeList, OperatorAssignShorten)
{
    SingleList<int> s1;
    s1.push_front(10);
    s1.push_front(20);
    s1.push_front(30);
    s1.push_front(40);
    s1.push_front(50);

    SingleList<int> s2;
    s2.push_front(1);
    s2.push_front(2);
    s2.push_front(3);
    s1 = s2;
    EXPECT_EQ(s1.size(), 3);
    std::stringstream out;
    out << s1;
    EXPECT_EQ(out.str(), "3 2 1 ");
}

TEST(IntSingeList, OperatorAssignLarger)
{
    SingleList<int> s1;
    s1.push_front(10);
    s1.push_front(20);
    s1.push_front(30);
    s1.push_front(40);
    s1.push_front(50);

    SingleList<int> s2;
    s2.push_front(1);
    s2.push_front(2);
    s2.push_front(3);

    s2 = s1;
    EXPECT_EQ(s2.size(), 5);
    std::stringstream out;
    out << s2;
    EXPECT_EQ(out.str(), "50 40 30 20 10 ");
}

TEST(IntSingeList, CopyConstructor)
{
    SingleList<int> s1;
    s1.push_front(10);
    s1.push_front(20);
    s1.push_front(30);
    s1.push_front(40);
    s1.push_front(50);

    SingleList<int> s2(s1);

    EXPECT_EQ(s2.size(), 5);
    std::stringstream out;
    out << s2;
    EXPECT_EQ(out.str(), "50 40 30 20 10 ");
}

TEST(IntSingleList, Swap)
{
    SingleList<int> s1(5, 3);
    SingleList<int> s2(3, 2);
    s1.swap(s2);

    std::stringstream out1;
    out1 << s2;
    EXPECT_EQ(out1.str(), "3 3 3 3 3 ");

    std::stringstream out2;
    out2 << s1;
    EXPECT_EQ(out2.str(), "2 2 2 ");
}

TEST(IntSingeList, ResizeShorten)
{
    SingleList<int> s;
    s.push_front(10);
    s.push_front(20);
    s.push_front(30);
    s.push_front(40);
    s.push_front(50);

    EXPECT_EQ(s.size(), 5);

    s.resize(3);

    std::stringstream out;
    out << s;
    EXPECT_EQ(out.str(), "50 40 30 ");
    EXPECT_EQ(s.size(), 3);
}

TEST(IntSingeList, ResizeLonger)
{
    SingleList<int> s;
    s.push_front(10);
    s.push_front(20);
    s.push_front(30);
    s.push_front(40);
    s.push_front(50);

    EXPECT_EQ(s.size(), 5);

    s.resize(7);

    std::stringstream out;
    out << s;
    EXPECT_EQ(out.str(), "50 40 30 20 10 0 0 ");
    EXPECT_EQ(s.size(), 7);
}

TEST(IntSingeList, Clear)
{
    SingleList<int> s;
    s.push_front(10);
    s.push_front(20);
    s.push_front(30);
    s.push_front(40);
    s.push_front(50);

    s.clear();
    EXPECT_EQ(s.empty(), true);
    EXPECT_EQ(s.size(), 0);
}

TEST(IntSingeList, PushFront)
{
    SingleList<int> s;
    s.push_front(5);
    s.push_front(7);
    std::stringstream out;
    out << s;
    EXPECT_EQ(out.str(), "7 5 ");
    EXPECT_EQ(s.size(), 2);
}

TEST(IntSingeList, PushBack)
{
    SingleList<int> s;
    s.push_back(5);
    s.push_back(7);
    std::stringstream out;
    out << s;
    EXPECT_EQ(out.str(), "5 7 ");
    EXPECT_EQ(s.size(), 2);
}

TEST(IntSingeList, PopFront)
{
    SingleList<int> s;
    s.push_front(5);
    s.push_front(7);
    s.pop_front();
    std::stringstream out;
    out << s;
    EXPECT_EQ(out.str(), "5 ");
    EXPECT_EQ(s.size(), 1);
}

TEST(IntSingeList, PopBack)
{
    SingleList<int> s;
    s.push_front(5);
    s.push_front(7);
    s.pop_back();
    std::stringstream out;
    out << s;
    EXPECT_EQ(out.str(), "7 ");
    EXPECT_EQ(s.size(), 1);
}

TEST(IntSingleList, OperatorIsEqual)
{
    SingleList<int> s1;
    s1.push_back(1);
    s1.push_back(2);
    s1.push_back(3);

    SingleList<int> s2;
    s2.push_back(1);
    s2.push_back(2);

    SingleList<int> s3;
    s3.push_back(1);
    s3.push_back(2);
    s3.push_back(3);

    EXPECT_TRUE(s1 == s3);
    EXPECT_FALSE(s1 == s2);
}

TEST(IntSingleList, OperatorIsLess)
{
    SingleList<int> s1;
    s1.push_back(1);
    s1.push_back(2);
    s1.push_back(3);

    SingleList<int> s2;
    s2.push_back(1);
    s2.push_back(2);

    SingleList<int> s3;
    s3.push_back(1);
    s3.push_back(2);
    s3.push_back(5);

    EXPECT_TRUE(s2 < s1);
    EXPECT_TRUE(s1 < s3);
}

TEST(ConstItertor, AddOperator)
{
    SingleList<int> s;
    s.push_back(1);
    s.push_back(2);
    s.push_back(3);

    SingleList<int>::const_iterator it = s.begin();
    ++it;
    EXPECT_EQ(*it, 2);
    it++;
    EXPECT_EQ(*it, 3);
}

TEST(IntSingleList, InsertBeforeMiddle)
{
    SingleList<int> s;
    s.push_front(10);
    s.push_front(20);
    s.push_front(30);
    s.push_front(40);
    s.push_front(50);

    SingleList<int>::iterator pos = s.begin();
    ++pos;
    ++pos;
    int a = 5;
    s.insert(pos, a);

    std::stringstream out;
    out << s;
    EXPECT_EQ(out.str(), "50 40 5 30 20 10 ");
    EXPECT_EQ(s.size(), 6);
}

TEST(IntSingleList, InsertEndMiddle)
{
    SingleList<int> s;
    s.push_front(10);
    s.push_front(20);
    s.push_front(30);
    s.push_front(40);
    s.push_front(50);

    SingleList<int>::iterator pos = s.end();
    int a = 5;
    s.insert(pos, a);

    std::stringstream out;
    out << s;
    EXPECT_EQ(out.str(), "50 40 30 20 10 5 ");
    EXPECT_EQ(s.size(), 6);
}

TEST(IntSingleList, InsertSizeMiddle)
{
    SingleList<int> s;
    s.push_front(10);
    s.push_front(20);
    s.push_front(30);
    s.push_front(40);
    s.push_front(50);

    SingleList<int>::iterator pos = s.begin();
    ++pos;
    ++pos;

    s.insert(pos, 3, 5);

    std::stringstream out;
    out << s;
    EXPECT_EQ(out.str(), "50 40 5 5 5 30 20 10 ");
    EXPECT_EQ(s.size(), 8);
}

TEST(IntSingleList, InsertSizeEnd)
{
    SingleList<int> s;
    s.push_front(10);
    s.push_front(20);
    s.push_front(30);
    s.push_front(40);
    s.push_front(50);

    SingleList<int>::iterator pos = s.end();
    s.insert(pos, 3, 5);

    std::stringstream out;
    out << s;
    EXPECT_EQ(out.str(), "50 40 30 20 10 5 5 5 ");
    EXPECT_EQ(s.size(), 8);
}

TEST(IntSingleList, InsertRange)
{
    SingleList<int> s;
    s.push_back(10);
    s.push_back(20);
    s.push_back(30);
    s.push_back(40);
    s.push_back(50);

    SingleList<int> s1;
    s1.push_back(1);
    s1.push_back(2);
    s1.push_back(3);
    s1.push_back(4);
    s1.push_back(5);


    SingleList<int>::iterator pos = s.begin();
    SingleList<int>::iterator f = s1.begin();
    SingleList<int>::iterator l = s1.begin();
    ++pos;
    ++l;
    ++l;
    ++l;
    ++l;
    s.insert(pos, f, l);

    std::stringstream out;
    out << s;
    EXPECT_EQ(out.str(), "10 1 2 3 4 20 30 40 50 ");
    EXPECT_EQ(s.size(), 9);
}

TEST(IntSingleList, InsertAfterDefault)
{
    SingleList<int> s;
    s.push_back(1);
    s.push_back(3);
    s.push_back(2);
    s.push_back(8);

    SingleList<int>::iterator pos = s.begin();
    ++pos;
    ++pos;

    s.insert_after(pos);
    std::stringstream out;
    out << s;
    EXPECT_EQ(out.str(), "1 3 2 0 8 ");
    EXPECT_EQ(s.size(), 5);
}

TEST(IntSingleList, InsertAfter)
{
    SingleList<int> s;
    s.push_back(1);
    s.push_back(3);
    s.push_back(2);
    s.push_back(8);

    SingleList<int>::iterator pos = s.begin();
    ++pos;
    ++pos;

    s.insert_after(pos, 11);
    std::stringstream out;
    out << s;
    EXPECT_EQ(out.str(), "1 3 2 11 8 ");
    EXPECT_EQ(s.size(), 5);
}

TEST(IntSingleList, InsertAfterBack)
{
    SingleList<int> s;
    s.push_back(1);
    s.push_back(3);
    s.push_back(2);
    s.push_back(8);

    SingleList<int>::iterator pos = s.end();

    s.insert_after(pos, 11);
    std::stringstream out;
    out << s;
    EXPECT_EQ(out.str(), "1 3 2 8 11 ");
    EXPECT_EQ(s.size(), 5);
}

TEST(IntSingleList, InsertAfterBySize)
{
    SingleList<int> s;
    s.push_back(1);
    s.push_back(3);
    s.push_back(2);
    s.push_back(8);

    SingleList<int>::iterator pos = s.begin();
    ++pos;
    ++pos;

    s.insert_after(pos, 3,11);
    std::stringstream out;
    out << s;
    EXPECT_EQ(out.str(), "1 3 2 11 11 11 8 ");
    EXPECT_EQ(s.size(), 7);
}


TEST(IntSingleList, InsertAfterBySizeBack)
{
    SingleList<int> s;
    s.push_back(1);
    s.push_back(3);
    s.push_back(2);
    s.push_back(8);

    SingleList<int>::iterator pos = s.end();

    s.insert_after(pos, 5, 11);
    std::stringstream out;
    out << s;
    EXPECT_EQ(out.str(), "1 3 2 8 11 11 11 11 11 ");
    EXPECT_EQ(s.size(), 9);
}

TEST(IntSingleList, InsertAfterRange)
{
    SingleList<int> s;
    s.push_back(10);
    s.push_back(20);
    s.push_back(30);
    s.push_back(40);
    s.push_back(50);

    SingleList<int> s1;
    s1.push_back(1);
    s1.push_back(2);
    s1.push_back(3);
    s1.push_back(4);
    s1.push_back(5);

    SingleList<int>::iterator pos = s.begin();
    SingleList<int>::iterator f = s1.begin();
    SingleList<int>::iterator l = s1.begin();
    ++pos;
    ++l;
    ++l;
    ++l;
    ++l;
    s.insert_after(pos, f, l);

    std::stringstream out;
    out << s;
    EXPECT_EQ(out.str(), "10 20 1 2 3 4 30 40 50 ");
    EXPECT_EQ(s.size(), 9);
}

TEST(IntSingeList, Erase)
{
    SingleList<int> s;
    s.push_back(10);
    s.push_back(20);
    s.push_back(30);
    s.push_back(40);
    s.push_back(50);

    SingleList<int>::iterator pos = s.begin();
    ++pos; ++pos;

    s.erase(pos);
    std::stringstream out;
    out << s;
    EXPECT_EQ(out.str(), "10 20 40 50 ");
    EXPECT_EQ(s.size(), 4);
}

TEST(IntSingeList, EraseFirst)
{
    SingleList<int> s;
    s.push_back(10);
    s.push_back(20);
    s.push_back(30);
    s.push_back(40);
    s.push_back(50);

    SingleList<int>::iterator pos = s.begin();

    s.erase(pos);
    std::stringstream out;
    out << s;
    EXPECT_EQ(out.str(), "20 30 40 50 ");
    EXPECT_EQ(s.size(), 4);
}

TEST(IntSingeList, EraseRange)
{
    SingleList<int> s;
    s.push_back(10);
    s.push_back(20);
    s.push_back(30);
    s.push_back(40);
    s.push_back(50);

    SingleList<int>::iterator f = s.begin();
    SingleList<int>::iterator l = s.begin();
    ++f; ++l; ++l; ++l; ++l;
    s.erase(f, l);
    std::stringstream out;
    out << s;
    EXPECT_EQ(out.str(), "10 50 ");
    EXPECT_EQ(s.size(), 2);
}

TEST(IntSingeList, EraseRangeFirst)
{
    SingleList<int> s;
    s.push_back(10);
    s.push_back(20);
    s.push_back(30);
    s.push_back(40);
    s.push_back(50);

    SingleList<int>::iterator l = s.begin();
    ++l; ++l; ++l; ++l;
    s.erase(s.begin(), l);
    std::stringstream out;
    out << s;
    EXPECT_EQ(out.str(), "50 ");
    EXPECT_EQ(s.size(), 1);
}

TEST(IntSingeList, EraseRangeLast)
{
    SingleList<int> s;
    s.push_back(10);
    s.push_back(20);
    s.push_back(30);
    s.push_back(40);
    s.push_back(50);

    SingleList<int>::iterator f = s.begin();
    ++f; ++f;
    s.erase(f, s.end());
    std::stringstream out;
    out << s;
    EXPECT_EQ(out.str(), "10 20 ");
    EXPECT_EQ(s.size(), 2);
}

TEST(IntSingeList, EraseAfter)
{
    SingleList<int> s;
    s.push_back(10);
    s.push_back(20);
    s.push_back(30);
    s.push_back(40);
    s.push_back(50);

    SingleList<int>::iterator pos = s.begin();
    ++pos; ++pos;

    s.erase_after(pos);
    std::stringstream out;
    out << s;
    EXPECT_EQ(out.str(), "10 20 30 50 ");
    EXPECT_EQ(s.size(), 4);
}



int
main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
