#include "Stack.h"
#include "gtests.h"

TEST(TStack, can_create_Stack)
{
	ASSERT_NO_THROW(TStack<int> st);
}

TEST(TStack, can_push)
{
	TStack<int> st;
	ASSERT_NO_THROW(st.Push(10));
}

TEST(TStack, can_pop_no_empty_Stack)
{
	TStack<int> st;
	st.Push(10);
	ASSERT_NO_THROW(st.GetElem());
}

TEST(TStack, cant_pop_empty_Stack)
{
	TStack<int> st;
	ASSERT_ANY_THROW(st.GetElem());
}

TEST(TStack, top_work_correctly_1)
{
	TStack<int> st;
	st.Push(10);
	st.Push(20);
	EXPECT_EQ(20, st.GetElem());
}

TEST(TStack, top_work_correctly_2)
{
	TStack<int> st;
	st.Push(10);
	st.GetElem();
	ASSERT_ANY_THROW(st.GetElem());
}

TEST(TStack, empty)
{
	TStack<int> st;
	ASSERT_NO_THROW(st.IsEmpty());
}

TEST(TStack, IsEmpty_work_correctly_1)
{
	TStack<int> st;
	EXPECT_EQ(1, st.IsEmpty());
}

TEST(TStack, IsEmpty_work_correctly_2)
{
	TStack<int> st;
	st.Push(10);
	st.Push(20);
	EXPECT_EQ(0, st.IsEmpty());
}

TEST(TStack, IsEmpty_work_correctly_3) {
	TStack<int> st;
	st.Push(10);
	st.GetElem();
	EXPECT_EQ(1, st.IsEmpty());
}

TEST(TStack, Get_size_work_correctly_1) {
	TStack<int> st;
	st.Push(10);
	st.Push(20);
	st.Push(5);
	st.Push(8);
	st.Push(7);
	st.GetElem();
	st.Push(90);
	EXPECT_EQ(5, st.GetCount());
}

TEST(TStack, Get_size_work_correctly_2) {
	TStack<int> st;
	EXPECT_EQ(0, st.GetCount());
}

TEST(TStack, copy_another_Stack_is_correctly) {
	TStack<int> st1;
	st1.Push(20);
	st1.Push(10);
	TStack<int> st2(st1);
	EXPECT_EQ(st2.GetElem(), st1.GetElem());
	EXPECT_EQ(st1.GetCount(), st2.GetCount());

}
