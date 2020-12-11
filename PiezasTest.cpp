/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
#include <iostream>

class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, constructorCheck)
{
    Piezas p;
    int blankValues = 1;
    for(int i = 0; i < BOARD_ROWS; i ++)
    {
        for(int j = 0; j < BOARD_COLS; j++)
        {

            if(p.pieceAt(i,j) != Blank)
            {
                blankValues = 0;
            }
        }
    }

	ASSERT_TRUE(blankValues);
}

TEST(PiezasTest, resetCheck)
{
    Piezas p;
    int blankValues = 1;

    p.dropPiece(0);
    p.dropPiece(0);
    p.dropPiece(2);
    p.reset();

    for(int i = 0; i < BOARD_ROWS; i ++)
    {
        for(int j = 0; j < BOARD_COLS; j++)
        {
            if(p.pieceAt(i,j) != Blank)
            {
                blankValues = 0;
            }
        }
    }

	ASSERT_TRUE(blankValues);
}

TEST(PiezasTest, dropPieceXTurn)
{
    Piezas p;

	ASSERT_EQ(p.dropPiece(0), X);
}

TEST(PiezasTest, dropPieceYTurn)
{
    Piezas p;
    p.dropPiece(0);
	ASSERT_EQ(p.dropPiece(0), O);
}

TEST(PiezasTest, dropPieceFullColumn)
{
    Piezas p;
    p.dropPiece(0);
    p.dropPiece(0);
    p.dropPiece(0);
    ASSERT_EQ(p.dropPiece(0), Blank);
}

TEST(PiezasTest, dropPieceInvalidBelowZero)
{
    Piezas p;

    ASSERT_EQ(p.dropPiece(-1), Invalid);
}

TEST(PiezasTest, dropPieceInvalidAboveMax)
{
    Piezas p;

    ASSERT_EQ(p.dropPiece(10), Invalid);
}


TEST(PiezasTest, pieceAtCheckX)
{
    Piezas p;
    p.dropPiece(0);
    ASSERT_EQ(p.pieceAt(0,0), X);
}

TEST(PiezasTest, pieceAtCheckO)
{
    Piezas p;
    p.dropPiece(0);
    p.dropPiece(0);
    ASSERT_EQ(p.pieceAt(1,0), O);
}

TEST(PiezasTest, pieceAtRowAboveBounds)
{
    Piezas p;
    ASSERT_EQ(p.pieceAt(5,0), Invalid);
}

TEST(PiezasTest, pieceAtRowBelowBounds)
{
    Piezas p;
    ASSERT_EQ(p.pieceAt(-1,0), Invalid);
}

TEST(PiezasTest, pieceAtColAboveBounds)
{
    Piezas p;
    ASSERT_EQ(p.pieceAt(0,9), Invalid);
}

TEST(PiezasTest, pieceAtColBelowBounds)
{
    Piezas p;
    ASSERT_EQ(p.pieceAt(0,-1), Invalid);
}

TEST(PiezasTest, gameStateGameNotOverEmpty)
{
    Piezas p;
    ASSERT_EQ(p.gameState(), Invalid);
}

TEST(PiezasTest, gameStateGameNotOver)
{
    Piezas p;
    p.dropPiece(0);
    ASSERT_EQ(p.gameState(), Invalid);
}

TEST(PiezasTest, gameStateGameWonX)
{
    Piezas p;
    p.dropPiece(0); //x
    p.dropPiece(0); //y
    p.dropPiece(1); //x
    p.dropPiece(0); //y
    p.dropPiece(2); //x
    p.dropPiece(1); //y
    p.dropPiece(3); //x
    p.dropPiece(1); //y
    p.dropPiece(2); //x
    p.dropPiece(3); //y
    p.dropPiece(2); //x
    p.dropPiece(3); //y
    ASSERT_EQ(p.gameState(), X);
}

TEST(PiezasTest, gameStateGameWonY)
{
    Piezas p;
    p.dropPiece(0); //x
    p.dropPiece(0); //y
    p.dropPiece(1); //x
    p.dropPiece(1); //y
    p.dropPiece(2); //x
    p.dropPiece(2); //y
    p.dropPiece(0); //x
    p.dropPiece(3); //y
    p.dropPiece(1); //x
    p.dropPiece(3); //y
    p.dropPiece(3); //x
    p.dropPiece(2); //y
    ASSERT_EQ(p.gameState(), O);
}


TEST(PiezasTest, gameStateGameTie)
{
    Piezas p;
    p.dropPiece(0); //x
    p.dropPiece(1); //y
    p.dropPiece(0); //x
    p.dropPiece(2); //y
    p.dropPiece(0); //x
    p.dropPiece(3); //y
    p.dropPiece(3); //x
    p.dropPiece(1); //y
    p.dropPiece(1); //x
    p.dropPiece(2); //y
    p.dropPiece(2); //x
    p.dropPiece(3); //y
    ASSERT_EQ(p.gameState(), Blank);
}
