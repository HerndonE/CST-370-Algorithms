/*
 * Title: hw12_1.cpp
 * Abstract: A program that to collect maximum number of coins
 *on an n x m board which was covered in the class.
 * Author: Ethan Herndon
 * ID: 4669
 * Date: 12/10/2020
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//Reference:https://riptutorial.com/algorithm/example/24087/finding-shortest-path-from-source-in-a--2d-graph
//          https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm

struct Position {
  int x;
  int y;
};

void userInput(vector < int > & board, int & cols, int & rows) {

  board.reserve(rows * cols);
  int input;
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      cin >> input;
      board.push_back(input);
    }
  }

}

void print(Position & p, vector < int > & atScore, int cols, vector < Position > & cameFrom) {
  cout << "Max coins:" << atScore[p.y * cols + p.x] << endl;
  vector < Position > path;
  do {
    path.push_back(p);
    p = cameFrom[p.y * cols + p.x];
  } while (p.x >= 0);
  cout << "Path:";
  for (int i = path.size() - 1; i >= 0; i--) {
    cout << "(" << path[i].x + 1 << "," << path[i].y + 1 << ")"; //prints the the x,y position at its index + 1
    if (i > 0)
      cout << "->";
  }
  cout << endl;
}

void dijkstraOptimalPath(vector < int > & board, int & cols, int & rows) {
  vector < Position > cameFrom(rows * cols, {
    -1,
    -1
  });
  vector < int > atScore(rows * cols, -1);
  // priority queue
  auto Less = [cols, & atScore](const Position & a,
    const Position & b) -> bool {
    const int ia = a.y * cols + a.x;
    const int scoreA = atScore[ia];
    const int ib = b.y * cols + b.x;
    const int scoreB = atScore[ib];
    if (scoreA < scoreB) {
      return false;
    }
    if (scoreA > scoreB) {
      return true;
    }
    return ia < ib;
  };
  priority_queue < Position, vector < Position > , decltype(Less) > queue(Less); //Declaration type to get priority queue with
  //lambda functionality
  // initialize the source in the queue
  queue.push({
    0,
    0
  });
  atScore[0] = board[0];
  while (!queue.empty()) //The main loop
  {
    const Position entryPosition = queue.top();
    queue.pop();
    // score at the current location
    const int currentScore = atScore[entryPosition.y * cols + entryPosition.x];
    if (entryPosition.x < cols - 1) //our x position
    {
      const int x = entryPosition.x + 1;
      const int y = entryPosition.y;
      const int i = y * cols + x;
      const int b = board[i];
      if (b != 2) //we skip 2 because it blocks our path (teacher's choice)
      {
        const int nextScore = currentScore + b;
        if (atScore[i] < nextScore) { //check if we found a better path
          atScore[i] = nextScore;
          cameFrom[i] = entryPosition;
          queue.push({
            x,
            y
          });
        }
      }
    }
    if (entryPosition.y < rows - 1) //our y position
    {
      const int x = entryPosition.x;
      const int y = entryPosition.y + 1;
      const int i = y * cols + x;
      const int b = board[i];
      if (b != 2) //we skip 2 because it blocks our path (teacher's choice)
      {
        const int nextScore = currentScore + b;
        if (atScore[i] < nextScore) { //check if we found a better path
          atScore[i] = nextScore;
          cameFrom[i] = entryPosition;
          queue.push({
            x,
            y
          });
        }
      }
    }
  }

  Position p = {
    cols - 1,
    rows - 1
  };
  print(p, atScore, cols, cameFrom);

}

int main() {
  int cols, rows;
  cin >> cols >> rows;
  vector < int > board;

  userInput(board, cols, rows);
  dijkstraOptimalPath(board, cols, rows);

  return 0;
}
