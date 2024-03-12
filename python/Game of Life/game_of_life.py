from random import randint
from os import system
class GameOfLife:
    def __init__(self):
        self.board = [[' '] * 20 for _ in range(20)]
        num_of_cells = randint(10, 50)
        counter = 0
        while counter <= num_of_cells:
            x, y = randint(0, 19), randint(0, 19)
            if self.board[x][y] == ' ':
                counter += 1
                self.board[x][y] = 'X'
    
    def __repr__(self):
        output = "-------------------------------------------------------------------------------------------------------------------------"
        for x in range(20):
            output += "\n|"
            for y in range(20):
                output += f"  {self.board[x][y]}  |"
            output += "\n-------------------------------------------------------------------------------------------------------------------------"
        return output
    
    def neighbor_fields(self, x, y):
        cell_fields = 0
        for i in range(x-1, x+2):
            for j in range(y-1, y+2):
                if 0 <= i < len(self.board) and 0 <= j < len(self.board[0]):
                    if i != x or j != y:
                        if self.board[i][j] == 'X':
                            cell_fields += 1
        return cell_fields
    
    def field_destiny(self, x, y):
        neighbors = self.neighbor_fields(x, y)
        if self.board[x][y] == 'X':
            if neighbors < 2:
                return "death"
            elif 1 < neighbors < 4:
                return "life"
            else:
                return "death"
        elif neighbors == 3:
            return "birth"
            
    def next_epoch(self):
        new_board = self.board.copy()
        for x in range(20):
            for y in range(20):
                if self.field_destiny(x, y) == "death":
                    new_board[x][y] = ' '
                elif self.field_destiny(x, y) == "life" or self.field_destiny(x, y) == "birth":
                    new_board[x][y] = 'X'
        self.board = new_board.copy()
        
    def play_game(self):
        epoch = 1
        while 'X' in [field for row in self.board for field in row]:
            try:
                user_unput = int(input("How many epochs do you want to pass: "))
                for _ in range(user_unput):
                    self.next_epoch()
                system("cls")
                print(f"Epoch: {epoch}")
                print(self)
                print("For exit use: Ctrl + X")
            except ValueError:
                system("cls")
                print("Input only integers!")
                print(f"Epoch: {epoch}")
                print(self)
                print("For exit use: Ctrl + X")
            except KeyboardInterrupt:
                system("cls")
                print(f"Epoch: {epoch}")
                print(self)
                print("Game Stopped!")
                
game = GameOfLife()

game.play_game()