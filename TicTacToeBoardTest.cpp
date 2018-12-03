/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT*/


TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, placenegativerow)
{
	TicTacToeBoard obj;
	Piece outcome=obj.placePiece(-1,0);
	ASSERT_EQ(outcome,Invalid);
}

TEST(TicTacToeBoardTest, placenegativecol)
{
	TicTacToeBoard obj;
	Piece outcome=obj.placePiece(0,-1);
	ASSERT_EQ(outcome,Invalid);
}

TEST(TicTacToeBoardTest, placegreatercol)
{
	TicTacToeBoard obj;
	Piece outcome=obj.placePiece(0,10);
	ASSERT_EQ(outcome,Invalid);
}

TEST(TicTacToeBoardTest, placetruepiece)
{
	TicTacToeBoard obj;
	Piece outcome=obj.placePiece(1,1);
	outcome=obj.getPiece(1,1);
	ASSERT_EQ(outcome,X);
}

TEST(TicTacToeBoardTest, placetruepiece2)
{
	TicTacToeBoard obj;
	Piece outcome=obj.placePiece(2,1);
	outcome=obj.getPiece(2,1);
	ASSERT_EQ(outcome,X);
}

TEST(TicTacToeBoardTest, winnerx)
{
	TicTacToeBoard obj;
	Piece outcome=obj.placePiece(1,1);
	outcome=obj.placePiece(2,2);
	outcome=obj.placePiece(0,1);
	outcome=obj.placePiece(1,2);
	outcome=obj.placePiece(2,1);
	outcome=obj.getWinner();
	ASSERT_EQ(outcome,X);
}

TEST(TicTacToeBoardTest, winnerxdiag)
{
	TicTacToeBoard obj;
	Piece outcome=obj.placePiece(0,0);
	outcome=obj.placePiece(0,2);
	outcome=obj.placePiece(1,1);
	outcome=obj.placePiece(1,2);
	outcome=obj.placePiece(2,2);
	outcome=obj.getWinner();
	ASSERT_EQ(outcome,X);
}

TEST(TicTacToeBoardTest, catsgame)
{
	TicTacToeBoard obj;
	Piece outcome=obj.placePiece(0,0);
	outcome=obj.placePiece(0,1);
	outcome=obj.placePiece(0,2);
	outcome=obj.placePiece(2,0);
	outcome=obj.placePiece(2,1);
	outcome=obj.placePiece(2,2);
	outcome=obj.placePiece(1,0);
	outcome=obj.placePiece(1,1);
	outcome=obj.placePiece(1,2);
	outcome=obj.getWinner();
	ASSERT_EQ(outcome,Blank);
}

TEST(TicTacToeBoardTest, notcomplete)
{
	TicTacToeBoard obj;
	Piece outcome=obj.placePiece(0,0);
	outcome=obj.placePiece(0,1);
	outcome=obj.placePiece(0,2);
	outcome=obj.placePiece(1,1);
	outcome=obj.placePiece(1,2);
	outcome=obj.placePiece(2,0);
	outcome=obj.placePiece(2,1);
	outcome=obj.placePiece(2,2);
	outcome=obj.getWinner();
	ASSERT_EQ(outcome,Invalid);
}
