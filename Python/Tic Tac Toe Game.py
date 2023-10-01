import os

board = [[' ' for _ in range(3)] for _ in range(3)]
current_player = 'X'
user_wins = 0

def initialize_board():
    global board
    board = [[' ' for _ in range(3)] for _ in range(3)]

def print_board():
    print()
    for i in range(3):
        for j in range(3):
            print(f' {board[i][j]} ', end='')
            if j < 2:
                print('|', end='')
        print()
        if i < 2:
            print('---+---+---')
    print()

def is_board_full():
    for i in range(3):
        for j in range(3):
            if board[i][j] == ' ':
                return False
    return True

def check_win():
    global current_player
    # Check rows
    for i in range(3):
        if board[i][0] == current_player and board[i][1] == current_player and board[i][2] == current_player:
            return True
    # Check columns
    for i in range(3):
        if board[0][i] == current_player and board[1][i] == current_player and board[2][i] == current_player:
            return True
    # Check diagonals
    if board[0][0] == current_player and board[1][1] == current_player and board[2][2] == current_player:
        return True
    if board[0][2] == current_player and board[1][1] == current_player and board[2][0] == current_player:
        return True
    return False

def update_score_file():
    with open('score.txt', 'w') as file:
        file.write(str(user_wins))

def read_score_file():
    global user_wins
    if os.path.exists('score.txt'):
        with open('score.txt', 'r') as file:
            user_wins = int(file.read())

def main():
    initialize_board()
    read_score_file()
    play_again = 'y'

    while play_again.lower() == 'y':
        global current_player
        current_player = 'X'
        moves = 0
        game_over = False

        print('Tic Tac Toe')
        print(f'User Wins: {user_wins}')
        print_board()

        while not game_over:
            print(f'Player {current_player}\'s turn')
            row = int(input('Enter the row (0-2): '))
            col = int(input('Enter the column (0-2): '))

            if 0 <= row < 3 and 0 <= col < 3 and board[row][col] == ' ':
                board[row][col] = current_player
                print_board()
                moves += 1

                if check_win():
                    print(f'Player {current_player} wins!')
                    if current_player == 'X':
                        global user_wins
                        user_wins += 1
                    game_over = True
                elif is_board_full():
                    print("It's a tie!")
                    game_over = True
                else:
                    current_player = 'O' if current_player == 'X' else 'X'
            else:
                print('Invalid move. Try again.')

        update_score_file()

        play_again = input('Do you want to play again? (y/n): ')
        if play_again.lower() != 'y':
            break
        else:
            initialize_board()
            print()

if __name__ == '__main__':
    main()