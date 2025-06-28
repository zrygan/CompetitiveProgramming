public class Main {
  public boolean exist(char[][] board, String word) {
    int rc = board.length;
    int cc = board[0].length;

    for (int row = 0; row < rc; row++) {
      for (int col = 0; col < cc; col++) {
        if (bt(board, word, row, col, 0))
          return true;
      }
    }

    return false;
  }

  private boolean bt(
      char[][] board,
      String word,
      int row,
      int col,
      int index) {

    if (index == word.length())
      return true;

    // constraints
    if (row < 0 ||
        col < 0 ||
        row >= board.length ||
        col >= board[0].length ||
        board[row][col] != word.charAt(index))
      return false;

    char t = board[row][col];
    board[row][col] = '_';

    boolean check = bt(board, word, row + 1, col, index + 1) ||
        bt(board, word, row, col + 1, index + 1) ||
        bt(board, word, row - 1, col, index + 1) ||
        bt(board, word, row, col - 1, index + 1);

    // change back to false to visit it again
    board[row][col] = t;

    return check;
  }
}
