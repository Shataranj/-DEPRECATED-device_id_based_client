#include <Arduino.h>
#include "network.h"
#include <PieceMove.h>
#include "ApiClient.h"

String is_connected;
String response;

const int firstPair = 32;
const int secondPair = 33;
const int thirdPair = 34;
const int fourthPair = 35;

int getRow(int value)
{
  if (value >= 100 && value <= 214)
  {
    return 1;
  }
  else if (value >= 215 && value <= 235)
  {
    return 2;
  }
  else if (value >= 235 && value <= 273)
  {
    return 3;
  }
  else if (value >= 274 && value <= 300)
  {
    return 4;
  }
  else if (value >= 301 && value <= 340)
  {
    return 5;
  }
  else if (value >= 341 && value <= 380)
  {
    return 6;
  }
  else if (value >= 381 && value <= 465)
  {
    return 7;
  }
  else if (value >= 466 && value <= 530)
  {
    return 8;
  }
  else if (value >= 3500 && value <= 5010)
  {
    return 9;
  }
  else if (value >= 2710 && value <= 2750)
  {
    return 10;
  }
  else if (value >= 1770 && value <= 1800)
  {
    return 11;
  }
  else if (value >= 1121 && value <= 1310)
  {
    return 12;
  }
  else if (value >= 901 && value <= 1120)
  {
    return 13;
  }
  else if (value >= 741 && value <= 900)
  {
    return 14;
  }
  else if (value >= 601 && value <= 740)
  {
    return 15;
  }
  else if (value >= 531 && value <= 600)
  {
    return 16;
  }
}

Position getPosition(int inputCurrent, char column1, char column2)
{
  const int row = getRow(inputCurrent);
  Position position;
  position = {row, column1};
  if (row > 9) {
    position = {(row % 8) + 1, column2};
  }
  return position;
}

void setup()
{
  Serial.begin(9600);
  Network myConnection("honor", "");
  is_connected = myConnection.ConnectToWiFi();
  ApiClient apiclient("https://chess-sever.herokuapp.com/");
  response = apiclient.createGame("create","y");
  delay(1000);
}

void loop()
{
  Serial.println(response);
  const int firstPairValue = analogRead(firstPair);
  const int secondPairValue = analogRead(secondPair);
  const int thirdPairValue = analogRead(thirdPair);
  const int fourthPairValue = analogRead(fourthPair);

  Serial.printf("first pair %d\n", firstPairValue);
  Serial.printf("second pair %d\n", secondPairValue);
  Serial.printf("third pair %d\n", thirdPairValue);
  Serial.printf("fourth pair %d\n", fourthPairValue);

  // Position position = {0, 'n'};
  // PieceMove pieceMove = PieceMove();
  // Serial.println(pieceMove.addMove(position).row);
  // if (firstPairValue >= 100)
  // {
  //   Serial.printf("row => %s\ncolumn => %s\n",getPosition(firstPairValue, 'a', 'b').row,getPosition(firstPairValue, 'a', 'b').col);
  // }
  // else if (secondPairValue >= 100)
  // {
  //   Serial.printf("row => %s\ncolumn => %s\n",getPosition(secondPairValue, 'c', 'd').row,getPosition(secondPairValue, 'c', 'd').col);
  // }
  // else if (thirdPairValue >= 100)
  // {
  //   Serial.printf("row => %s\ncolumn => %s\n",getPosition(thirdPairValue, 'e', 'f').row,getPosition(thirdPairValue, 'e', 'f').col);
  // }
  // else if (fourthPairValue >= 100)
  // {
  //   Serial.printf("row => %s\ncolumn => %s\n",getPosition(fourthPairValue, 'g', 'h').row,getPosition(fourthPairValue, 'g', 'h').col);
  // }
  delay(1000);
}