#include "n_queens.h"

// Time:  O(N!)
// Space: O(N)
std::vector<std::vector<std::string>> Solution51::solveNQueens(int n)
{
	std::vector<std::vector<std::string>> rst;
	if (n == 0) return rst;

	std::vector<bool> visited_column(n, false), visited_ldiag(2 * n - 1, false), visited_rdiag(2 * n - 1, false);
	std::vector<std::string> current_board(n, std::string(n, '.'));

	solveNQueensBackTracking(n, rst, visited_column, visited_ldiag, visited_rdiag, current_board, 0);

	return rst;
}

void Solution51::solveNQueensBackTracking(int n, std::vector<std::vector<std::string>>& rst, std::vector<bool>& visited_columns, std::vector<bool>& visited_ldiag, std::vector<bool>& visited_rdiag, std::vector<std::string>& current_board, int current_row)
{
	if (current_row == n)
	{
		rst.push_back(current_board);
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (visited_columns[i] || visited_ldiag[n - 1 - current_row + i] || visited_rdiag[current_row + i])
			continue;

		current_board[current_row][i] = 'Q';
		visited_columns[i] = visited_ldiag[n - 1 - current_row + i] = visited_rdiag[current_row + i] = true;

		solveNQueensBackTracking(n, rst, visited_columns, visited_ldiag, visited_rdiag, current_board, current_row + 1);

		current_board[current_row][i] = '.';
		visited_columns[i] = visited_ldiag[n - 1 - current_row + i] = visited_rdiag[current_row + i] = false;
	}
}
