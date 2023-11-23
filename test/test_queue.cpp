#include "Queue.h"
#include "gtests.h"
TEST(TQueue, can_create_queue)
{
	ASSERT_NO_THROW(TQueue<int> q);
}

TEST(TQueue, can_push)
{
	TQueue<int> q;
	ASSERT_NO_THROW(q.Push(10));
}

TEST(TQueue, can_getelem_no_empty_queue)
{
	TQueue<int> q;
	q.Push(10);
	ASSERT_NO_THROW(q.GetElem());
}

TEST(TQueue, cant_getelem_empty_queue)
{
	TQueue<int> q;
	ASSERT_ANY_THROW(q.GetElem());
}

TEST(TQueue, top_work_correctly_1)
{
	TQueue<int> q;
	q.Push(20);
	q.Push(15);
	q.Push(30);
	EXPECT_EQ(20, q.GetElem());
}


TEST(TQueue, top_work_correctly_2)
{
	TQueue<int> q;
	q.Push(20);
	q.Push(15);
	q.Push(30);
	q.GetElem();
	EXPECT_EQ(15, q.GetElem());
}

TEST(TQueue, empty)
{
	TQueue<int> q;
	ASSERT_NO_THROW(q.IsEmpty());
}

TEST(TQueue, IsEmpty_work_correctly_1)
{
	TQueue<int> q;
	EXPECT_EQ(1, q.IsEmpty());
}

TEST(TQueue, empty_work_correctly_2)
{
	TQueue<int> q;
	q.Push(15);
	EXPECT_EQ(0, q.IsEmpty());
}

TEST(TQueue, IsEmpty_work_correctly_3)
{
	TQueue<int> q;
	q.Push(20);
	q.GetElem();
	EXPECT_EQ(1, q.IsEmpty());
}

TEST(TQueue, Get_size_work_correctly_1)
{
	TQueue<int> q;
	q.Push(10);
	q.Push(20);
	q.Push(5);
	q.Push(8);
	q.Push(7);
	q.GetElem();
	q.Push(90);
	EXPECT_EQ(5, q.GetCount());
}

TEST(TQueue, Get_size_work_correctly_2)
{
	TQueue<int> q;
	EXPECT_EQ(0, q.GetCount());
}

TEST(TQueue, copy_queue_is_correctly)
{
	TQueue<int> q1;
	q1.Push(2);
	q1.Push(1);
	TQueue<int> q2(q1);
	EXPECT_EQ(q2.GetElem(), q1.GetElem());
	EXPECT_EQ(q1.GetCount(), q2.GetCount());

}
