import string

def count_words(text):
    words = text.split()
    return len(words)

def count_sentences(text):
    count = 0
    for char in text:
        if char in ['.', '?', '!']:
            count += 1
    return count

def main():
    filename = input("Words Counter\nEnter the filename: ")

    try:
        with open(filename, 'r') as file:
            content = file.read()

            num_chars = len(content)
            num_words = count_words(content)
            num_sentences = count_sentences(content)

            print("Number of characters:", num_chars)
            print("Number of words:", num_words)
            print("Number of sentences:", num_sentences)
    except FileNotFoundError:
        print("Error opening file")

if __name__ == '__main__':
    main()