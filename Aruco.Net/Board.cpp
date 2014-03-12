#include "StdAfx.h"
#include "Board.h"

using namespace System::Runtime::InteropServices;

Aruco::Net::Board::Board(const aruco::Board &board, float likelihood):
board(new aruco::Board(board)),
markers(gcnew List<Marker ^>(board.size())),
likelihood(likelihood)
{
	std::vector<aruco::Marker>::const_iterator it;
	for (it = board.begin(); it < board.end(); it++)
	{
		markers->Add(gcnew Marker(*it));
	}
}

Aruco::Net::Board::~Board()
{
	delete board;
}

cli::array<double> ^ Aruco::Net::Board::GetGLModelViewMatrix()
{
	cli::array<double> ^result = gcnew cli::array<double>(16);
	cli::pin_ptr<double> modelView = &result[0];
	board->glGetModelViewMatrix(modelView);
	return result;
}