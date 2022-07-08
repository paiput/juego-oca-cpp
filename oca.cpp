/*
Tipos de casilleros:
	-2: pierde turno
	-1: retrocede x casilleros
	0: casillero normal
	1: avanca x casilleros
	2: vuelve a tirar
*/	

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

#define find_item_in_array(item, arr) find(arr.begin(), arr.end(), item) != arr.end()

/**
 * @brief Obtener un array de pairs con valores randoms de entre cierto valor a partir de una matriz cuadrada
 * @param x Cantidad de columnas del array
 * @param y Cantidad de filas del array
 * @return vector<pair<int, int> > 
 */
vector<pair<int, int> > get_random_pair_array(int x, int y) {  
  int boardSize = x * y;
	
  int specialSquares = boardSize * 0.3; // cantidad de casillas especiales
	vector<pair<int, int> > randomPairArray(specialSquares);
	
	// .first es coordenada y .second coordenada x
	for (int i = 0; i < specialSquares; i++) {
		pair<int, int> randomPair;
    do {
      randomPair.first = rand() % (boardSize / 8 - 1) + 1;
      randomPair.second = rand() % (boardSize / 8 - 1) + 1;
		} while (find_item_in_array(randomPair, randomPairArray));
    randomPairArray[i] = randomPair;
	}

  // borrar despues
	cout << "random pair values:\n";
  for (int i=0; i<randomPairArray.size(); i++) {
    cout << randomPairArray[i].first << " - " << randomPairArray[i].second << "\n";
  }

	return randomPairArray;
}

struct Player {
	char name;
	int position = 0;
	int turn = 0;
};

struct Board {
	const int x = 8;
	const int y = 8;
	vector<vector<int> > board;

	void setup() {
    // declara valor inicial del tablero (todo en 0)
    vector<pair<int, int >> specialSquaresCoordinates = get_random_pair_array(x, y);
    for (int i = 0; i < y; i++) {
      vector<int> row(x, 0);
      board.push_back(row);
    }
    // agrega casilleros especiales en el tablero
    for (int i = 0; i < specialSquaresCoordinates.size(); i++) {
      int random_special_square = 1 + rand() % (3 - 1);
      int random_sign = 1 + rand() % (3 - 1);
      if (random_sign == 1) {
        random_special_square -= random_special_square * 2;
      }
      board[specialSquaresCoordinates[i].first][specialSquaresCoordinates[i].second] = random_special_square;
    }
	} 
	
	void printBoard() {
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
	}
};

struct Game {
	vector<Player> players;
	Board board;
	
	void addPlayer(){
		cout << "Jugador " << players.size() << ": ";
		players.push_back(Player());
		cin >> players[players.size() - 1].name;
		cout << endl;
	}
};

int main() {
	srand(time(NULL));
	while(true) {
		struct Game game;
		int n = 2;
		for (int i = 0; i < n; i++) {
			game.addPlayer();
		}
    
		game.board.setup();
		game.board.printBoard();
		
		break;
	}
}
