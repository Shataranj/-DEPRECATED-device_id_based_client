#include <position.h>
#include <map>

class PieceMove{

public:
  Position source;
  Position destination;

  PieceMove();

  Position addMove(Position position);
  bool isValidMove();
  PieceMove getMove();
};